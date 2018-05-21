using System.Collections.Generic;

namespace IntrinsicsDocs.Cpp
{
	class ExtraCode
	{
		static readonly Dictionary<string, string> s_extraCode = new Dictionary<string, string>()
		{
			{  "avx",
@"
		// Broadcast a single-precision (32-bit) floating-point element from memory to all elements of ""dst"".
		inline void broadcast_ss( __m128 &dst, float const *mem_addr )
		{
			dst = _mm_broadcast_ss( mem_addr );
		}

		// Broadcast a single-precision (32-bit) floating-point element from memory to all elements of ""dst"".
		inline void broadcast_ss( __m256 &dst, float const *mem_addr )
		{
			dst = _mm256_broadcast_ss( mem_addr );
		}
" }
,
			{  "avx2",
@"
		// Broadcast the low packed 8-bit integer from ""a"" to all elements of ""dst""
		inline void __vectorcall broadcast_epi8( __m128i &dst, __m128i a )
		{
			dst = _mm_broadcastb_epi8( a );
		}
		// Broadcast the low packed 8-bit integer from ""a"" to all elements of ""dst""
		inline void __vectorcall broadcast_epi8( __m256i &dst, __m128i a )
		{
			dst = _mm256_broadcastb_epi8( a );
		}

		// Broadcast the low packed 16-bit integer from ""a"" to all elements of ""dst"".
		inline void __vectorcall broadcast_epi16( __m128i &dst, __m128i a )
		{
			dst = _mm_broadcastw_epi16( a );
		}
		// Broadcast the low packed 16-bit integer from ""a"" to all elements of ""dst"".
		inline void __vectorcall broadcast_epi16( __m256i &dst, __m128i a )
		{
			dst = _mm256_broadcastw_epi16( a );
		}

		// Broadcast the low packed 32-bit integer from ""a"" to all elements of ""dst"".
		inline void __vectorcall broadcast_epi32( __m128i &dst, __m128i a )
		{
			dst = _mm_broadcastd_epi32( a );
		}
		// Broadcast the low packed 32-bit integer from ""a"" to all elements of ""dst"".
		inline void __vectorcall broadcast_epi32( __m256i &dst, __m128i a )
		{
			dst = _mm256_broadcastd_epi32( a );
		}

		// Broadcast the low packed 64-bit integer from ""a"" to all elements of ""dst"".
		inline void __vectorcall broadcast_epi64( __m128i &dst, __m128i a )
		{
			dst = _mm_broadcastq_epi64( a );
		}
		// Broadcast the low packed 64-bit integer from ""a"" to all elements of ""dst"".
		inline void __vectorcall broadcast_epi64( __m256i &dst, __m128i a )
		{
			dst = _mm256_broadcastq_epi64( a );
		}

		// Broadcast 128 bits of integer data from ""a"" to all 128-bit lanes in ""dst"". 
		inline void __vectorcall broadcast_si128( __m256i &dst, __m128i a )
		{
			dst = _mm256_broadcastsi128_si256( a );
		}
"
			}
			,
			{  "fp16c",
@"
		// Convert packed half-precision (16-bit) floating-point elements in ""a"" to packed single-precision floating-point elements
		inline void __vectorcall cvtph_ps( __m128 &dst, __m128i a )
		{
			dst = _mm_cvtph_ps( a );
		}

		// Convert packed half-precision (16-bit) floating-point elements in ""a"" to packed single-precision floating-point elements
		inline void __vectorcall cvtph_ps( __m256 &dst, __m128i a )
		{
			dst = _mm256_cvtph_ps( a );
		}
" }
		};

		public static string extra( string f )
		{
			f = f.ToLowerInvariant();
			string r;
			if( s_extraCode.TryGetValue( f, out r ) )
				return r;
			return null;
		}
	}
}