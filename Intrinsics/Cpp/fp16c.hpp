#pragma once

namespace Intrinsics
{
	namespace Sse
	{
		// Convert packed single-precision floating-point elements in "a" to packed half-precision (16-bit) floating-point elements
		template<int rounding>
		inline __m128i __vectorcall cvtps_ph( __m128 a )
		{
			return _mm_cvtps_ph( a, rounding );
		}

		// Convert packed half-precision (16-bit) floating-point elements in ""a"" to packed single-precision floating-point elements
		inline __m128 __vectorcall cvtph_ps( __m128i a )
		{
			return _mm_cvtph_ps( a );
		}
	}

	namespace Avx
	{
		// Convert packed single-precision floating-point elements in "a" to packed half-precision (16-bit) floating-point elements
		template<int rounding>
		inline __m128i __vectorcall cvtps_ph( __m256 a )
		{
			return _mm256_cvtps_ph( a, rounding );
		}

		// Convert packed half-precision (16-bit) floating-point elements in ""a"" to packed single-precision floating-point elements
		inline __m256 __vectorcall cvtph_ps( __m128i a )
		{
			return _mm256_cvtph_ps( a );
		}
	}
}