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

			return true;
		}

		public void add( Intrinsic i )
		{
			if( !shouldInclude( i ) )
				return;
			intrinsics.Add( i );
		}

		public void write( string destPath )
		{
			using( var fs = File.CreateText( destPath ) )
			{
				fs.WriteLine( "// This file is generated automatically by a tool, please don't edit" );
				fs.WriteLine();
				fs.WriteLine( "namespace Intrinsics {{ namespace {0}", ns );
				fs.WriteLine( "{" );

				foreach( var i in intrinsics.OrderBy( i => i.sortKey ) )
					fs.write( i, callConv );

				fs.WriteLine( "}} }}	// namespace Intrinsics::{0}", ns );
			}
		}
	}
}