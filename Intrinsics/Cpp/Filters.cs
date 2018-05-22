using System;
using System.Collections.Generic;
using System.Linq;

namespace IntrinsicsDocs.Cpp
{
	static class Filters
	{
		static readonly string[] skipPrefixes = new string[]
		{
			"_mm_cbrt_",
			"_mm_cdfnorm",
			"_mm_cexp",
			"_mm_clog",
			"_mm_csqrt",
			"_mm_erf",
			"_mm_exp",
			"_mm_invcbrt",
			"_mm_invsqrt",
			"_mm_log",
			"_mm_pow",
			"_mm_svml_",
			"_mm_trunc",
			"_mm256_cbrt",
			"_mm256_cdfnorm",
			"_mm256_cexp",
			"_mm256_clog",
			"_mm256_csqrt",
			"_mm256_erf",
			"_mm256_exp",
			"_mm256_invcbrt",
			"_mm256_invsqrt",
			"_mm256_log",
			"_mm256_pow",
			"_mm256_svml",
			"_mm256_trunc",
			// "_mm_broadcast",
			// "_mm256_broadcast",
		};

		static readonly HashSet<string> skipIntrinsics = new HashSet<string>
		{
			"_mm_load_pd1",
			"_mm_set_pd1",
			"_mm_store_pd1",
			"_mm_sfence",
			"_mm_malloc",
			"_mm_free",
			"_mm_clflush",
			"_mm_prefetch",

			// Extra fp16c code
			"_mm_cvtph_ps",
			"_mm256_cvtph_ps",

			"_mm_tzcnt_32",
			"_mm_tzcnt_64",

			"_mm_broadcastsi128_si256",

			// VS doesn't have these
			"_mm_loadu_si16",
			"_mm_loadu_si64",
			"_mm_storeu_si16",
			"_mm_storeu_si64",
		};

		static readonly HashSet<string> _64BitIntrinsics = new HashSet<string>
		{
			"_mm_stream_si64",
			"_mm_cvtsd_si64",
			"_mm_cvttsd_si64",
			"_mm_cvtsi64_sd",
			"_mm_cvtsi64_si128",
			"_mm_cvtsi128_si64",
			"_mm_cvtss_si64",
			"_mm_cvttss_si64",
			"_mm_cvtsi64_ss",
			"_mm_crc32_u64",
		};

		static bool isAllCaps( string name )
		{
			foreach( char c in name )
			{
				if( char.IsUpper( c ) )
					continue;
				if( char.IsDigit( c ) )
					continue;
				if( '_' == c )
					continue;
				return false;
			}
			return true;
		}

		public static bool shouldInclude( this Intrinsic i )
		{
			if( i.category == "Trigonometry" )
				return false;
			if( i.category == "Arithmetic" && i.instruction == null )
				return false;
			if( i.rettype == "__m64" || true == i.parameter?.Any( p => p.type == "__m64" ) )
				return false;

			string n = i.name;
			if( isAllCaps( n ) )
				return false;

			if( n.Contains( "_setr_" ) )
				return false;   // Skip _setr_, only include _set_
			if( n.startsWith( skipPrefixes ) )
				return false;

			if( skipIntrinsics.Contains( n ) )
				return false;

			if( n.EndsWith( "_si64x" ) || n.Contains( "_cvtsi64x_" ) )
				i.is64bitOnly = true;
			else if( _64BitIntrinsics.Contains( n ) )
				i.is64bitOnly = true;

			return true;
		}

		static IEnumerable<string> api( this Intrinsic i )
		{
			yield return i.rettype;
			if( null == i.parameter )
				yield break;
			foreach( var p in i.parameter )
				yield return p.type;
		}

		public static Func<IEnumerable<string>, bool> isSmallerFunc( int iThisBits )
		{
			string strThisBits = iThisBits.ToString();
			string strSmallerBits = ( iThisBits / 2 ).ToString();
			return ( IEnumerable<string> types ) =>
			{
				bool anySmaller = false;
				foreach( string s in types )
				{
					if( s.Contains( strThisBits ) )
						return false;
					else if( s.Contains( strSmallerBits ) )
						anySmaller = true;
				}
				return anySmaller;
			};
		}

		public static bool isSmall( this Intrinsic i, Func<IEnumerable<string>, bool> fn )
		{
			return fn( i.api() );
		}
	}
}