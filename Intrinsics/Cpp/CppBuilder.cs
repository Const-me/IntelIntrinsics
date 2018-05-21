using System;
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
				case "fp16c":
				// case "kncni":
				case "pclmulqdq":
				case "sha":
					return true;
			}
			return false;
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
				string key = i.CPUID.First();
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
				string path = Path.Combine( destFolder, $"{fileName}.hpp" );
				kvp.Value.write( path );
			}
		}
	}
}