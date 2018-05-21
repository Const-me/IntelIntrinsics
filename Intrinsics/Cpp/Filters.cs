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
			"_mm_broadcast_ss",
			"_mm256_broadcast_ss",
		};

		static readonly HashSet<string> _64BitIntrinsics = new HashSet<string>
		{
			"_mm_stream_si64",
			"_mm_cvtsd_si64",
			"_mm_cvttsd_si64",
			"_mm_cvtsi64_sd",
			"_mm_cvtsi64_si128",
			"_mm_cvtsi128_si64",
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

			if( n.Contains( "_set_" ) )
				return false;   // Skip _set_, only include _setr_
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
	}
}