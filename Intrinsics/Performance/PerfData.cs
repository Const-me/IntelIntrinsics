using System;
using System.Collections.Generic;
using System.IO;
using ParseTables;
using System.Xml.Serialization;
using System.Diagnostics;
using System.Linq;

namespace IntrinsicsDocs.Performance
{
	class PerfData
	{
		public class Instruction
		{
			public readonly string cpu, uops, latency, throughput;
			public readonly eArgumentsMask[] args;

			internal Instruction( string cpu, InstructionsData.Instruction i )
			{
				this.cpu = cpu;
				args = ArgTypes.parse( i.op );
				uops = i.uops;
				latency = i.latency;
				throughput = i.throughput;
			}

			public override string ToString()
			{
				return $"{cpu} / {args} / {uops} {latency} {throughput}";
			}
		}

		readonly Dictionary<string, List<Instruction>> m_data = new Dictionary<string, List<Instruction>>( StringComparer.OrdinalIgnoreCase );

		static readonly HashSet<string> s_hsExtraInstructions = new HashSet<string>(StringComparer.OrdinalIgnoreCase)
		{
			"crc32", "popcnt", "rdrand", "rdseed", "rdrand rdseed",
		};

		static bool shouldAddInstruction( HashSet<int> hsCats, InstructionsData.Instruction instr )
		{
			if( hsCats.Contains( instr.cat ) )
				return true;
			if( s_hsExtraInstructions.Contains( instr.i ) )
				return true;
			return false;
		}

		public PerfData( string path, string debugOutput = null )
		{
			InstructionsData data;
			var ser = new XmlSerializer( typeof( InstructionsData ) );
			using( var fs = File.OpenRead( path ) )
				data = (InstructionsData)ser.Deserialize( fs );

			// Filter categories
			HashSet<int> hsCats = new HashSet<int>();
			foreach( var c in data.categories )
			{
				string cat = c.cat;
				if( cat.Contains( "vector" ) || cat.Contains( "XMM" ) || cat.Contains( "YMM" ) || cat.Contains( "Mask register" ) )
					hsCats.Add( c.id );
			}

			if( null != debugOutput )
			{
				debugWriter = new StreamWriter( debugOutput, false );
			}

			try
			{
				foreach( var s in data.sheets )
				{
					foreach( var i in s.data )
					{
						if( !shouldAddInstruction( hsCats, i ) )
							continue;
						addInstruction( s.name, i );
					}
				}
			}
			finally
			{
				debugWriter?.Dispose();
			}
		}

		TextWriter debugWriter=null;

		static IEnumerable<string> unpackInstructionsAddVPrefix( string instructionsCoded, bool appendVPrefix )
		{
			foreach( string i in instructionsCoded.unpackInstructions() )
			{
				if( i == "etc." )
					continue;
				yield return i;
				if( !appendVPrefix )
					continue;
				if( String.IsNullOrEmpty( i ) )
					continue;
				if( i[ 0 ] == 'v' || i[ 0 ] == 'V' )
					continue;
				yield return "V" + i;
			}
		}

		void addInstruction( string cpu, InstructionsData.Instruction data )
		{
			// if( data.i == "vpsadbw" && Debugger.IsAttached ) Debugger.Break();	// Break on loading perf.data of a "vpsadbw" instruction for some architecture

			Instruction r = new Instruction( cpu, data );

			debugWriter?.Write( "{0} / {1}: ", cpu, data.i );

			eArgumentsMask[] args = ArgTypes.parse( data.op );  // This is not a waste of CPU time because ArgTypes.parse() uses a local cache
			bool appendVPrefix  = args.Any( am => 0 != ( am & ( ArgTypes.avxBits | ArgTypes.avx512Bits ) ) );

			foreach( string i in unpackInstructionsAddVPrefix( data.i, appendVPrefix ) )
			{
				debugWriter?.Write( "{0} ", i );
				List<Instruction> list;
				if( !m_data.TryGetValue( i, out list ) )
				{
					list = new List<Instruction>( 1 );
					m_data[ i ] = list;
				}
				list.Add( r );
			}
			debugWriter?.WriteLine();
		}

		/// <summary>Lookup by CPU instruction name</summary>
		public IReadOnlyCollection<Instruction> lookup( string i )
		{
			List<Instruction> res;
			if( m_data.TryGetValue( i, out res ) )
				return res;
			return null;
		}
	}
}