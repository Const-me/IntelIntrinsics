using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace IntrinsicsDocs.Cpp
{
	class HeaderFile
	{
		readonly List<Intrinsic> intrinsics = new List<Intrinsic>( 64 );
		readonly string ns;
		readonly string callConv = "__vectorcall";

		public HeaderFile( string cpuid )
		{
			cpuid = cpuid.ToLowerInvariant();
			if( cpuid.Contains( "avx" ) )
				ns = "Avx";
			else if( cpuid.StartsWith( "bmi" ) )
			{
				ns = "Misc";
				callConv = "";
			}
			else
				ns = "Sse";
		}

		static bool shouldInclude( Intrinsic i )
		{
			if( i.category == "Trigonometry" )
				return false;

			if( i.rettype == "__m64" || true == i.parameter?.Any( p => p.type == "__m64" ) )
				return false;

			string n = i.name;

			switch( n )
			{
				case "_mm_load_pd1":
				case "_mm_set_pd1":
				case "_mm_store_pd1":
					return false;
			}

			if( n.EndsWith( "_si64x" ) || n.Contains( "_cvtsi64x_" ) )
				i.is64bitOnly = true;
			else switch( n )
				{
					case "_mm_stream_si64":
					case "_mm_cvtsd_si64":
					case "_mm_cvttsd_si64":
					case "_mm_cvtsi64_sd":
					case "_mm_cvtsi64_si128":
					case "_mm_cvtsi128_si64":
						i.is64bitOnly = true;
						break;
				}

			return true;
		}

		public void add( Intrinsic i )
		{
			if( !shouldInclude( i ) )
				return;
			intrinsics.Add( i );
		}

		void write( IEnumerable<Intrinsic> ii )
		{
		}

		public void write( string destPath )
		{
			using( var fs = File.CreateText( destPath ) )
			{
				fs.WriteLine( "// This file is generated automatically by a tool, please don't edit" );
				fs.WriteLine();
				fs.WriteLine( "namespace Intrinsics {{ namespace {0}", ns );
				fs.WriteLine( "{" );

				var all = intrinsics.Where( i => !i.is64bitOnly ).OrderBy( i => i.sortKey ).ToArray();
				fs.write( all, callConv );

				var a64 = intrinsics.Where( i => i.is64bitOnly ).OrderBy( i => i.sortKey ).ToArray();
				if( a64.Length > 0 )
				{
					fs.WriteLine( "#if _M_X64" );
					fs.write( a64, callConv );
					fs.WriteLine( "#endif // _M_X64" );
				}

				fs.WriteLine( "}} }}	// namespace Intrinsics::{0}", ns );
			}
		}
	}
}