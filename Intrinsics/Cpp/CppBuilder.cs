﻿using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace IntrinsicsDocs.Cpp
{
	static class CppBuilder
	{
		static bool shouldInclude( string cpuId )
		{
			if( cpuId.Contains( "512" ) )
				return false;

			cpuId = cpuId.ToLowerInvariant();
			if( cpuId.Contains( "sse" ) )
				return true;
			if( cpuId.Contains( "avx" ) )
				return true;
			if( cpuId.Contains( "bmi" ) )
				return true;

			switch( cpuId )
			{
				case "aes":
				case "fma":
				// case "fp16c":
				// case "kncni":
				case "pclmulqdq":
				case "sha":
					return true;
			}
			return false;
		}

		static string hpp( this string destFolder, string fileName )
		{
			return Path.Combine( destFolder, $"{fileName}.hpp" );
		}

		public static void produce( string destFolder, DataSet dataSet )
		{
			if( !Directory.Exists( destFolder ) )
				Directory.CreateDirectory( destFolder );

			/* var noIds = dataSet.intrinsic.Where( i => i.CPUID.isEmpty() ).ToArray();
			var manyIDs = dataSet.intrinsic.Where( i => null != i.CPUID && i.CPUID.Length > 1 ).ToArray();
			manyIDs = manyIDs.Where( i => !i.CPUID.Any( c => c.Contains( "AVX512" ) ) ).ToArray(); */

			var all = dataSet.intrinsic.Where( i => null != i.CPUID && 1 == i.CPUID.Length ).ToArray();

			Dictionary<string, HeaderFile> dict = new Dictionary<string, HeaderFile>( StringComparer.OrdinalIgnoreCase );
			foreach( var i in all )
			{
				HeaderFile header;
				string key = i.CPUID.First().ToLowerInvariant();
				if( !shouldInclude( key ) )
					continue;

				if( !dict.TryGetValue( key, out header ) )
				{
					header = new HeaderFile( key );
					dict[ key ] = header;
				}
				header.add( i );
			}

			foreach( var kvp in dict )
			{
				string fileName = kvp.Key.ToLowerInvariant();
				kvp.Value.write( destFolder.hpp( fileName ) );
			}

			/* if( makeIntrinsicsHpp )
			{
				using( var fs = File.CreateText( destFolder.hpp( "intrinsics" ) ) )
				{
					fs.WriteLine(
@"#pragma once
// Includes all of them, up to AVX2

# include <intrin.h>
# include <emmintrin.h>
# include <immintrin.h>
" );
					List<string> keys = dict.Keys.ToList();
					keys.Add( "fp16c" );
					keys.Sort();
					foreach( string fn in keys )
					{
						fs.WriteLine( @"#include ""{0}.hpp""", fn );
					}
				}
			} */

			// ExtraCode.copyExtraFiles( destFolder );
			ExtraCodeGen.generateExtras( destFolder );
		}
	}
}