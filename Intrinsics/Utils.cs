using System;
using System.Collections.Generic;
using System.IO;
using System.Xml.Linq;

namespace IntrinsicsDocs
{
	public static class Utils
	{
		public static string getAttrib( this XElement e, string name )
		{
			return e.Attribute( name )?.Value;
		}

		public static void trim( ref string s )
		{
			if( String.IsNullOrEmpty( s ) )
				return;
			s = s.Trim( '\r', '\n' );
		}

		public static HashSet<string> hashSet()
		{
			return new HashSet<string>( StringComparer.InvariantCultureIgnoreCase );
		}

		public static Dictionary<string, tValue> dictionary<tValue>()
		{
			return new Dictionary<string, tValue>( StringComparer.InvariantCultureIgnoreCase );
		}

		public static tValue lookup<tKey, tValue>( this Dictionary<tKey, tValue> dict, tKey k )
		{
			tValue val;
			if( dict.TryGetValue( k, out val ) )
				return val;
			return default( tValue );
		}

		public static bool isEmpty( this string s )
		{
			return String.IsNullOrEmpty( s );
		}
		public static bool notEmpty( this string s )
		{
			return !String.IsNullOrEmpty( s );
		}

		public static bool isEmpty<t>( this t[] a )
		{
			return null == a || a.Length <= 0;
		}

		public static bool notEmpty<t>( this t[] a )
		{
			return !a.isEmpty();
		}

		public static string htmlFile( string id )
		{
			string res = id;
			res = res.Replace( ' ', '-' );
			res = res.Replace( '/', '-' );
			res = res.Replace( '\\', '-' );
			return res + ".html";
		}

		public static void writeLines( this TextWriter w, params string[] lines )
		{
			foreach( string l in lines )
				w.WriteLine( l );
		}

		public static string inTemp( string name )
		{
			return Path.Combine( Path.GetTempPath(), name );
		}

		public static int longestCommonPrefix( this IEnumerable<string> strings )
		{
			int res = -1;
			string last = null;
			foreach( string s in strings )
			{
				if( s.isEmpty() )
					continue;

				if( null == last )
				{
					last = s;
					res = s.Length;
					continue;
				}


				if( s.Length < res )
					res = s.Length;

				for( int i = 0; i < res; i++ )
				{
					if( last[ i ] != s[ i ] )
					{
						res = i;
						break;
					}
				}

				if( res <= 0 )
					return 0;
			}
			return res;
		}

		public static string stripPrefix( this string s, params string[] pfix )
		{
			foreach( string p in pfix )
			{
				if( s.StartsWith( p ) )
					return s.Substring( p.Length );
			}
			return s;
		}

		public static bool startsWith( this string s, params string[] pfix )
		{
			foreach( string p in pfix )
				if( s.StartsWith( p ) )
					return true;
			return false;
		}

		public static string stripSuffix( this string s, string sfOld )
		{
			if( !s.EndsWith( sfOld ) )
				return s;
			return s.Substring( 0, s.Length - sfOld.Length );
		}

		public static string replaceSuffix( this string s, string sfOld, string sfNew )
		{
			if( !s.EndsWith( sfOld ) )
				return s;
			return s.Substring( 0, s.Length - sfOld.Length ) + sfNew; ;
		}
	}
}