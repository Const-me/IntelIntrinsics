using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;

namespace IntrinsicsDocs.Cpp
{
	class HeaderFile
	{
		readonly List<Intrinsic> intrinsics = new List<Intrinsic>( 64 );
		readonly string cpuid;
		readonly string ns;
		readonly string callConv = "XM_CALLCONV";
		readonly HashSet<string> headers = new HashSet<string>( StringComparer.OrdinalIgnoreCase );

		readonly Func<IEnumerable<string>, bool> fnSmaller = null;
		readonly HeaderFile smallRegInstructions = null;

		public HeaderFile( string cpuid )
		{
			cpuid = cpuid.ToLowerInvariant();
			this.cpuid = cpuid;
			if( cpuid.Contains( "avx" ) || cpuid.Contains( "fma" ) )
			{
				ns = "Avx";
				fnSmaller = Filters.isSmallerFunc( 256 );
				smallRegInstructions = new HeaderFile( "sse-??" );
			}
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
			// if( i.name == "_mm_broadcastb_epi8" && Debugger.IsAttached ) Debugger.Break();

			if( !i.shouldInclude() )
				return;

			if( i.header.notEmpty() )
				headers.Add( i.header );

			if( null != smallRegInstructions && i.isSmall( fnSmaller ) )
				smallRegInstructions.add( i );
			else
				intrinsics.Add( i );
		}

		void writeImpl( StreamWriter fs )
		{
			fs.WriteLine(
@"	namespace {0}
	{{", ns );
			var all = intrinsics.Where( i => !i.is64bitOnly && !i.isUnsupportedInGcc() ).OrderBy( i => i.sortKey ).ToArray();
			fs.write( all, callConv );

			var a64 = intrinsics.Where( i => i.is64bitOnly ).OrderBy( i => i.sortKey ).ToArray();
			if( a64.notEmpty() )
			{
				fs.WriteLine();
				fs.WriteLine( "#if _M_X64" );
				fs.write( a64, callConv );
				fs.WriteLine( "#endif // _M_X64" );
			}

			var gccMissing = intrinsics.Where( i => i.isUnsupportedInGcc() ).OrderBy( i => i.sortKey ).ToArray();
			if( gccMissing.notEmpty() )
			{
				fs.WriteLine();
				fs.WriteLine( "#ifndef __GNUC__" );
				fs.write( gccMissing, callConv );
				fs.WriteLine( "#endif // !__GNUC__" );
			}

			fs.WriteLine( @"	}}	// namespace Intrinsics::{0}", ns );

		}

		public void write( string destPath )
		{
			using( var fs = File.CreateText( destPath ) )
			{
				fs.WriteLine(
@"// This file is generated automatically by a tool, please don't edit.
#pragma once" );

				foreach( var h in headers )
					fs.WriteLine( "#include <{0}>", h );

				fs.WriteLine(
@"#include ""Extra/common.hpp""

namespace Intrinsics
{" );
				writeImpl( fs );

				if( null != smallRegInstructions && smallRegInstructions.intrinsics.Count > 0 )
				{
					fs.WriteLine();
					smallRegInstructions.writeImpl( fs );
				}
				fs.Write( "}	// namespace Intrinsics" );

				if( ExtraCodeGen.hasExtraHeader( cpuid ) )
				{
					fs.WriteLine();
					fs.Write( @"#include ""Extra/{0}-extra.hpp""", cpuid );
				}
			}
		}
	}
}