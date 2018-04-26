using System;
using System.Collections.Generic;

namespace IntrinsicsDocs.Performance
{
	static class UnpackUtils
	{
		public static bool isAllLetters( this string s )
		{
			foreach( char c in s )
			{
				if( !Char.IsLetter( c ) )
					return false;
			}
			return true;
		}

		public static IEnumerable<string> unwrap( this IEnumerable<IEnumerable<string>> ii )
		{
			foreach( var a in ii )
				foreach( var b in a )
					yield return b;
		}

		public static string replaceSuffix( this string s, string sOld, string sNew )
		{
			if( !s.EndsWith( sOld ) )
				return s;
			return s.Substring( 0, s.Length - sOld.Length ) + sNew;
		}

		public static string replacePrefix( this string s, string pOld, string pNew )
		{
			if( !s.StartsWith( pOld ) )
				return s;
			return pNew + s.Substring( pOld.Length );
		}

		public static string removeLeadingSpaces( this string s, string[] parts )
		{
			foreach( string p in parts )
			{
				s = s.Replace( " " + p, p );
			}
			return s;
		}
	}
}