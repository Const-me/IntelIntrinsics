using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace IntrinsicsDocs.Cpp
{
	class HeaderFile
	{
		readonly List<Intrinsic> intrinsics = new List<Intrinsic>( 64 );
		readonly string cpuid;
		readonly string ns;
		readonly string callConv = "__vectorcall";

		public HeaderFile( string cpuid )
		{
			cpuid = cpuid.ToLowerInvariant();
			this.cpuid = cpuid;
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

		public void add( Intrinsic i )
		{
			if( !i.shouldInclude() )
				return;
			intrinsics.Add( i );
		}

		public void write( string destPath )
		{
			using( var fs = File.CreateText( destPath ) )
			{
				fs.WriteLine( "// This file is generated automatically by a tool, please don't edit." );
				fs.WriteLine();
				fs.WriteLine(
@"namespace Intrinsics
{{
	namespace {0}
	{{", ns );
				var all = intrinsics.Where( i => !i.is64bitOnly ).OrderBy( i => i.sortKey ).ToArray();
				fs.write( all, callConv );

				var a64 = intrinsics.Where( i => i.is64bitOnly ).OrderBy( i => i.sortKey ).ToArray();
				if( a64.Length > 0 )
				{
					fs.WriteLine();
					fs.WriteLine( "#if _M_X64" );
					fs.write( a64, callConv );
					fs.WriteLine( "#endif // _M_X64" );
				}

				string xt = ExtraCode.extra( cpuid );
				if( null != xt )
					fs.Write( xt );

				fs.Write( @"	}}	// namespace Intrinsics::{0}
}}	// namespace Intrinsics", ns );
			}
		}
	}
}