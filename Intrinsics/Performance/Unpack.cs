using System;
using System.Collections.Generic;
using System.Linq;

namespace IntrinsicsDocs.Performance
{
	static class Unpack
	{
		static readonly char[] allSpecial = new char[ 7 ] { ',', ' ', '\r', '\n', '(', ')', '/' };

		static readonly string[] arrPrefixes = new string[] { "AND/ANDN/OR/XOR", "PMIN/PMAX" };
		static IEnumerable<string> tryUnpackPrefix( this string op )
		{
			string prefix = arrPrefixes.FirstOrDefault( s => op.StartsWith( s ) );
			if( null == prefix )
				return null;
			string suffix = op.Substring( prefix.Length );
			return prefix.Split( '/' ).Select( p => p + suffix );
		}

		static readonly string[] arrSuffixes = new string[]
		{
			"B/W/D/Q/SB/SW/USB/USW", "BW/BD/BQ/WD/WQ/DQ", "SB/SW/SD/UB/UW/UD", "BW/BD/BQ/DW/DQ", "SS/SD/PS/PD",
			"B/W/D/Q", "W/D/Q", "B/W/D", "W/SW/D", "B/W/D", "BW/WD/DQ",
			"S/D", "PS/PD", "SS/SD", "D/Q", "W/D", "B/W", "WB/DW", "SS/PS", "SD/PD", "SW/UB", "A/U", "BW/WD", "UB/SW", "UB/SD", "UB/SQ",
		};
		static IEnumerable<string> tryUnpackSuffix( this string op )
		{
			string suffix = arrSuffixes.FirstOrDefault( s => op.EndsWith( s ) );
			if( null == suffix )
				return null;
			string prefix = op.Substring( 0, op.Length - suffix.Length );
			return suffix.Split( '/' ).Select( s => prefix + s );
		}

		static readonly string[] arrMid = new string[] { "ADD/SUB", "MIN/MAX", "AND/ANDN/OR/XOR", "AND/OR/XOR", "ANDN/OR/XOR", "LL/RL", "LL/RA", "RL/RA", "RA/RL", "EQ/GT", "H/L", "L/H", "SX/ZX", "U/S", "L/R" };
		static IEnumerable<string> tryUnpackMid( this string op )
		{
			string vals = null;
			int startInd = -1;
			for( int i = 0; i < arrMid.Length; i++ )
			{
				vals = arrMid[ i ];
				startInd = op.IndexOf( vals );
				if( startInd >= 0 )
					break;
			}
			if( startInd < 0 )
				return null;

			string prefix = op.Substring( 0, startInd );
			string suffix = op.Substring( startInd + vals.Length );
			return vals.Split( '/' ).Select( s => prefix + s + suffix );
		}

		static IEnumerable<string> unpackOptions( string op, int iOpen, int iClose )
		{
			string prefix = op.Substring( 0, iOpen );
			string suffix = op.Substring( iClose + 1 );
			string inside = op.Substring( iOpen + 1, iClose - iOpen - 1 );

			yield return prefix + suffix;
			for( int i = inside.IndexOf( ',' ); i > 0; i = inside.IndexOf( ',' ) )
			{
				yield return prefix + inside.Substring( 0, i ) + suffix;
				inside = inside.Substring( i + 1 );
			}
			yield return prefix + inside + suffix;
		}

		static IEnumerable<string> tryUnpackOptions( this string op )
		{
			int i1 = op.IndexOf( '(' );
			if( i1 < 0 )
				return null;
			int i2 = op.IndexOf(')', i1+1);
			if( i2 < 0 )
				return null;
			return unpackOptions( op, i1, i2 );
		}

		static IEnumerable<string> unwrap( params IEnumerable<string>[] ii )
		{
			return ii.unwrap();
		}

		static IEnumerable<string> unpackImpl( this string op )
		{
			int i = op.IndexOfAny( allSpecial );
			if( i < 0 )
			{
				return new string[ 1 ] { op };
			}

			i = op.IndexOf( ", " );
			if( i > 0 )
				return unwrap( op.Substring( 0, i ).unpackImpl(), op.Substring( i + 2 ).unpackImpl() );

			if( op.StartsWith( "(V)" ) )
			{
				var res = unpackImpl( op.Substring( 3 ) );
				return unwrap( res, res.Select( s => "V" + s ) );
			}
			if( op.StartsWith( "(U)" ) )
			{
				var res = unpackImpl( op.Substring( 3 ) );
				return unwrap( res, res.Select( s => "U" + s ) );
			}

			// Process alternatives
			var r = op.tryUnpackPrefix() ?? op.tryUnpackMid() ?? op.tryUnpackOptions() ?? op.tryUnpackSuffix();
			if( null != r )
				return r.Select( oo => oo.unpackImpl() ).unwrap();

			s_errors.Add( op );
			return new string[ 0 ];
		}

		static IEnumerable<string> split( this string op )
		{
			foreach( string a in op.Split( "\r\n".ToCharArray(), StringSplitOptions.RemoveEmptyEntries ) )
				foreach( string b in a.Split( new string[ 1 ] { ", " }, StringSplitOptions.RemoveEmptyEntries ) )
					foreach( string c in b.Split( " ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries ) )
						yield return c;
		}

		static string finalFix( string s )
		{
			if( s.StartsWith( "CMPcc", StringComparison.OrdinalIgnoreCase ) )
				return s.Substring( 0, 3 ) + s.Substring( 5 );
			return s;
		}

		public static IEnumerable<string> unpackInstructions( this string op )
		{
			// Initial fixes
			if( op.ToLowerInvariant().Contains( "all fma instr." ) )
				op = "VF(N)ADD/SUB132SS/SD/PS/PD\nVF(N)ADDSUB132SS/SD/PS/PD";
			if( op == "MOVD / MOVQ" )
				op = "MOVD\nMOVQ";

			op = op.Trim();
			op = op.replacePrefix( "VPBROADCAST\n", "VPBROADCAST" );
			op = op.replacePrefix( "PUNPCKH/L\n", "PUNPCKH/L" );

			op = op.removeLeadingSpaces( arrSuffixes );
			// Replace suffixes before the split, because some of them contain spaces and we don't want to split on these
			op = op.Replace( "PS/ PD", "PS/PD" );
			op = op.Replace( "SS/D PS/D", "SS/SD/PS/PD" );
			op = op.Replace( "SS/SD/PS/ PD", "SS/SD/PS/PD" );
			op = op.Replace( "SS/D/PS/D", "SS/SD/PS/PD" );
			op = op.Replace( " H/L PS/D", "H/LPS/PD" );
			op = op.Replace( " BW BD BQ DW DQ", "BW/BD/BQ/DW/DQ" );
			op = op.Replace( "\nSB/SW/SD\nUB/UW/UD", "SB/SW/SD/UB/UW/UD" );
			op = op.Replace( " SB/SW/ SD UB/UW/UD", "SB/SW/SD/UB/UW/UD" );

			// Split into components
			foreach( string s in op.split() )
			{
				foreach( var r in s.unpackImpl() )
					yield return finalFix( r );
			}
		}

		// Debug code
		static readonly HashSet<string> s_errors = new HashSet<string>( StringComparer.OrdinalIgnoreCase );

		public static IEnumerable<string> errors()
		{
			return s_errors.OrderBy( s => s, StringComparer.OrdinalIgnoreCase );
		}
	}
}