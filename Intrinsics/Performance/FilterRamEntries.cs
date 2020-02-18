using ParseTables;
using System;
using System.Collections.Generic;
using System.Linq;
using static ParseTables.InstructionsData;

namespace IntrinsicsDocs.Performance
{
	/// <summary>For many instructions like vextractf128, tables contain multiple entries, for register and RAM arguments.
	/// We only want register versions. It's obvious the memory is extremely slow compared to CPU, even unpredictably so if it's not cached or worse, if the cache line is modiofyed by another CPU core.</summary>
	static class FilterRamEntries
	{
		static bool startwWith( string str, string prefix )
		{
			return str.StartsWith( prefix, StringComparison.InvariantCultureIgnoreCase );
		}

		static readonly string[] exclude = new string[] { "MOV", "VMOV", "VPMOV" };
		static readonly string[] include = new string[] { "MOVMSK", "MOVDDUP" };

		static bool shouldProcessInstruction( string i )
		{
			bool excluded = false;
			foreach( string p in exclude )
				if( i.startsWith( p ) )
				{
					excluded = true;
					break;
				}

			if( excluded )
			{
				foreach( string p in include )
					if( i.startsWith( p ) )
					{
						excluded = false;
						break;
					}
			}
			return !excluded;
		}

		static bool isRegisterOnlyOp( string op )
		{
			if( null == op )
				return true;
			return !op.Contains( "m" );
		}

		static double latencyNumber( Instruction i )
		{
			string a = i.latency;
			if( null == a )
				return 0;
			if( a.Contains( "-" ) )
			{
				string[] fields = a.Split( '-' );
				return fields.Select( double.Parse ).Average();
			}
			if( a.Contains( "+" ) )
			{
				int idx = a.IndexOf( '+' );
				a = a.Substring( 0, idx );
			}
			if( a.StartsWith( "~" ) )
				a = a.Substring( 1 );
			if( double.TryParse( a, out double dbl ) )
				return dbl;
			return double.PositiveInfinity;
		}

		static Instruction pickSlowest( IEnumerable<Instruction> list )
		{
			return list.OrderByDescending( latencyNumber ).First();
		}

		static Instruction applyFilter( List<Instruction> list )
		{
			if( list.Count == 1 )
				return list[ 0 ];
			List<Instruction> regOnly = list.Where( i => isRegisterOnlyOp( i.op ) ).ToList();
			if( regOnly.Count == 1 )
				return regOnly[ 0 ];
			if( regOnly.Count == 0 )
				return pickSlowest( list );
			return pickSlowest( regOnly );
		}

		static Instruction[] processSheet( Instruction[] source )
		{
			Dictionary<string, List<Instruction>> grouped = new Dictionary<string, List<Instruction>>( StringComparer.InvariantCultureIgnoreCase );

			foreach( var i in source )
			{
				if( !shouldProcessInstruction( i.i ) )
					continue;

				List<Instruction> list;
				if( !grouped.TryGetValue( i.i, out list ) )
				{
					list = new List<Instruction>();
					grouped.Add( i.i, list );
				}
				list.Add( i );
			}

			Dictionary<string, Instruction> filtered = new Dictionary<string, Instruction>( StringComparer.InvariantCultureIgnoreCase );
			foreach( var kvp in grouped )
				filtered.Add( kvp.Key, applyFilter( kvp.Value ) );

			List<Instruction> result = new List<Instruction>();

			foreach( var i in source )
			{
				Instruction ins;
				if( !filtered.TryGetValue( i.i, out ins ) )
				{
					result.Add( i );
					continue;
				}
				if( null == ins )
					continue;
				result.Add( ins );
				filtered[ i.i ] = null;
			}
			return result.ToArray();
		}

		public static void process( InstructionsData data )
		{
			foreach( var s in data.sheets )
				s.data = processSheet( s.data );
		}
	}
}