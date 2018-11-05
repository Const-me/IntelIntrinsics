using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;

namespace IntrinsicsDocs.Cpp
{
	public enum eExtra : byte
	{
		sse1,
		sse2,
		bitwise,
		float_avx_cmp,
		float_cmp_ops,
		float_math,
		int_common,
		int_math,
		int_math_ops,
		avx1,
		avx2,
	}

	static class ExtraCodeParser
	{
		const string prefix = "IntrinsicsDocs.Cpp.Extra.";

		static IEnumerable<Tuple<eExtra, string>> listExtraSources()
		{
			var ass = Assembly.GetExecutingAssembly();
			foreach( string fullName in ass.GetManifestResourceNames() )
			{
				if( !fullName.StartsWith( prefix ) )
					continue;
				string name = Path.ChangeExtension( fullName, null );
				name = name.stripPrefix( prefix );
				eExtra e;
				if( !Enum.TryParse( name, out e ) )
					continue;

				yield return Tuple.Create( e, fullName );
			}
		}

		[Flags]
		enum LineFlags : byte
		{
			None = 0,
			HasVec = 1,
			HasOp = 2,
			NeedsTabs = 4,
		}

		struct SourceLine
		{
			public readonly LineFlags flags;
			public readonly string src;

			public SourceLine( string s )
			{
				src = s;
				LineFlags lf = LineFlags.None;
				if( s.Contains( "VECTOR_TYPE" ) )
					lf |= LineFlags.HasVec;
				if( s.Contains( "SIMD_OP" ) )
					lf |= LineFlags.HasOp;
				if( !string.IsNullOrWhiteSpace( s ) && s[ 0 ] != '#' )
					lf |= LineFlags.NeedsTabs;
				flags = lf;
			}
		}

		static IEnumerable<SourceLine> readSource( string resource )
		{
			var ass = Assembly.GetExecutingAssembly();
			var stm = ass.GetManifestResourceStream( resource );
			using( var sr = new StreamReader( stm, Encoding.UTF8, false, 1024, true ) )
			{
				while( true )
				{
					string line = sr.ReadLine();
					if( line == null )
						yield break;
					yield return new SourceLine( line );
				}
			}
		}

		static readonly Dictionary<eExtra, SourceLine[]> s_sources = new Dictionary<eExtra, SourceLine[]>();

		static ExtraCodeParser()
		{
			foreach( var tp in listExtraSources() )
				s_sources[ tp.Item1 ] = readSource( tp.Item2 ).ToArray();
		}

		static string expandOp( string line, string TYPE_SUFFIX )
		{
			while( true )
			{
				int iOp = line.IndexOf( "SIMD_OP" );
				if( iOp < 0 )
					return line;
				int iArg = line.IndexOf( '(', iOp );
				iArg++;
				int iEnd = line.IndexOf( ')', iArg );
				string content = line.Substring( iArg, iEnd - iArg ).Trim();
				line = line.Substring( 0, iOp ) + content + "_" + TYPE_SUFFIX + line.Substring( iEnd + 1 );
			}
		}

		public static void write( TextWriter tw, eExtra what, int nTabs, string VECTOR_TYPE, string TYPE_SUFFIX )
		{
			string tabs = new string( '\t', nTabs );
			foreach( var line in s_sources[ what ] )
			{
				string dest = line.src;
				if( line.flags.HasFlag( LineFlags.HasVec ) )
					dest = dest.Replace( "VECTOR_TYPE", VECTOR_TYPE );
				if( line.flags.HasFlag( LineFlags.HasOp ) )
					dest = expandOp( dest, TYPE_SUFFIX );
				if( line.flags.HasFlag( LineFlags.NeedsTabs ) )
					dest = tabs + dest;
				tw.WriteLine( dest );
			}
		}

		public static void copyStatic( string src, string dest )
		{
			var ass = Assembly.GetExecutingAssembly();
			string resource = prefix + src;
			var ss = ass.GetManifestResourceStream( resource );
			using( var ds = File.Create( Path.Combine( dest, src ) ) )
				ss.CopyTo( ds );
		}
	}
}