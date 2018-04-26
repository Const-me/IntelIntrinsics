using System;
using System.Collections.Generic;
using System.IO;
using ParseTables;
using System.Xml.Serialization;

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
						if( !hsCats.Contains( i.cat ) )
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

		void addInstruction( string cpu, InstructionsData.Instruction data )
		{
			Instruction r = new Instruction( cpu, data );

			debugWriter?.Write( "{0} / {1}: ", cpu, data.i );

			foreach( string i in data.i.unpackInstructions() )
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