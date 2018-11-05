// This file is generated automatically by a tool. If you want to change it, fork & modify the tool instead: https://github.com/Const-me/IntelIntrinsics
#pragma once
#include <immintrin.h>
#include "Extra/common.hpp"

namespace Intrinsics
{
	namespace Avx
	{
		// Multiply packed double-precision floating-point elements in "a" and "b", add the intermediate result to packed elements in "c"
		inline __m256d XM_CALLCONV fmadd_pd( __m256d a, __m256d b, __m256d c )
		{
			return _mm256_fmadd_pd( a, b, c );
		}

		// Multiply packed single-precision floating-point elements in "a" and "b", add the intermediate result to packed elements in "c"
		inline __m256 XM_CALLCONV fmadd_ps( __m256 a, __m256 b, __m256 c )
		{
			return _mm256_fmadd_ps( a, b, c );
		}

		// Multiply packed double-precision floating-point elements in "a" and "b", alternatively add and subtract packed elements in "c" to/from the intermediate result
		inline __m256d XM_CALLCONV fmaddsub_pd( __m256d a, __m256d b, __m256d c )
		{
			return _mm256_fmaddsub_pd( a, b, c );
		}

		// Multiply packed single-precision floating-point elements in "a" and "b", alternatively add and subtract packed elements in "c" to/from the intermediate result
		inline __m256 XM_CALLCONV fmaddsub_ps( __m256 a, __m256 b, __m256 c )
		{
			return _mm256_fmaddsub_ps( a, b, c );
		}

		// Multiply packed double-precision floating-point elements in "a" and "b", subtract packed elements in "c" from the intermediate result
		inline __m256d XM_CALLCONV fmsub_pd( __m256d a, __m256d b, __m256d c )
		{
			return _mm256_fmsub_pd( a, b, c );
		}

		// Multiply packed single-precision floating-point elements in "a" and "b", subtract packed elements in "c" from the intermediate result
		inline __m256 XM_CALLCONV fmsub_ps( __m256 a, __m256 b, __m256 c )
		{
			return _mm256_fmsub_ps( a, b, c );
		}

		// Multiply packed double-precision floating-point elements in "a" and "b", alternatively subtract and add packed elements in "c" from/to the intermediate result
		inline __m256d XM_CALLCONV fmsubadd_pd( __m256d a, __m256d b, __m256d c )
		{
			return _mm256_fmsubadd_pd( a, b, c );
		}

		// Multiply packed single-precision floating-point elements in "a" and "b", alternatively subtract and add packed elements in "c" from/to the intermediate result
		inline __m256 XM_CALLCONV fmsubadd_ps( __m256 a, __m256 b, __m256 c )
		{
			return _mm256_fmsubadd_ps( a, b, c );
		}

		// Multiply packed double-precision floating-point elements in "a" and "b", add the negated intermediate result to packed elements in "c"
		inline __m256d XM_CALLCONV fnmadd_pd( __m256d a, __m256d b, __m256d c )
		{
			return _mm256_fnmadd_pd( a, b, c );
		}

		// Multiply packed single-precision floating-point elements in "a" and "b", add the negated intermediate result to packed elements in "c"
		inline __m256 XM_CALLCONV fnmadd_ps( __m256 a, __m256 b, __m256 c )
		{
			return _mm256_fnmadd_ps( a, b, c );
		}

		// Multiply packed double-precision floating-point elements in "a" and "b", subtract packed elements in "c" from the negated intermediate result
		inline __m256d XM_CALLCONV fnmsub_pd( __m256d a, __m256d b, __m256d c )
		{
			return _mm256_fnmsub_pd( a, b, c );
		}

		// Multiply packed single-precision floating-point elements in "a" and "b", subtract packed elements in "c" from the negated intermediate result
		inline __m256 XM_CALLCONV fnmsub_ps( __m256 a, __m256 b, __m256 c )
		{
			return _mm256_fnmsub_ps( a, b, c );
		}
	}	// namespace Intrinsics::Avx

	namespace Sse
	{
		// Multiply packed double-precision floating-point elements in "a" and "b", add the intermediate result to packed elements in "c"
		inline __m128d XM_CALLCONV fmadd_pd( __m128d a, __m128d b, __m128d c )
		{
			return _mm_fmadd_pd( a, b, c );
		}

		// Multiply packed single-precision floating-point elements in "a" and "b", add the intermediate result to packed elements in "c"
		inline __m128 XM_CALLCONV fmadd_ps( __m128 a, __m128 b, __m128 c )
		{
			return _mm_fmadd_ps( a, b, c );
		}

		// Multiply the lower double-precision floating-point elements in "a" and "b", and add the intermediate result to the lower element in "c"
		inline __m128d XM_CALLCONV fmadd_sd( __m128d a, __m128d b, __m128d c )
		{
			return _mm_fmadd_sd( a, b, c );
		}

		// Multiply the lower single-precision floating-point elements in "a" and "b", and add the intermediate result to the lower element in "c"
		inline __m128 XM_CALLCONV fmadd_ss( __m128 a, __m128 b, __m128 c )
		{
			return _mm_fmadd_ss( a, b, c );
		}

		// Multiply packed double-precision floating-point elements in "a" and "b", alternatively add and subtract packed elements in "c" to/from the intermediate result
		inline __m128d XM_CALLCONV fmaddsub_pd( __m128d a, __m128d b, __m128d c )
		{
			return _mm_fmaddsub_pd( a, b, c );
		}

		// Multiply packed single-precision floating-point elements in "a" and "b", alternatively add and subtract packed elements in "c" to/from the intermediate result
		inline __m128 XM_CALLCONV fmaddsub_ps( __m128 a, __m128 b, __m128 c )
		{
			return _mm_fmaddsub_ps( a, b, c );
		}

		// Multiply packed double-precision floating-point elements in "a" and "b", subtract packed elements in "c" from the intermediate result
		inline __m128d XM_CALLCONV fmsub_pd( __m128d a, __m128d b, __m128d c )
		{
			return _mm_fmsub_pd( a, b, c );
		}

		// Multiply packed single-precision floating-point elements in "a" and "b", subtract packed elements in "c" from the intermediate result
		inline __m128 XM_CALLCONV fmsub_ps( __m128 a, __m128 b, __m128 c )
		{
			return _mm_fmsub_ps( a, b, c );
		}

		// Multiply the lower double-precision floating-point elements in "a" and "b", and subtract the lower element in "c" from the intermediate result
		inline __m128d XM_CALLCONV fmsub_sd( __m128d a, __m128d b, __m128d c )
		{
			return _mm_fmsub_sd( a, b, c );
		}

		// Multiply the lower single-precision floating-point elements in "a" and "b", and subtract the lower element in "c" from the intermediate result
		inline __m128 XM_CALLCONV fmsub_ss( __m128 a, __m128 b, __m128 c )
		{
			return _mm_fmsub_ss( a, b, c );
		}

		// Multiply packed double-precision floating-point elements in "a" and "b", alternatively subtract and add packed elements in "c" from/to the intermediate result
		inline __m128d XM_CALLCONV fmsubadd_pd( __m128d a, __m128d b, __m128d c )
		{
			return _mm_fmsubadd_pd( a, b, c );
		}

		// Multiply packed single-precision floating-point elements in "a" and "b", alternatively subtract and add packed elements in "c" from/to the intermediate result
		inline __m128 XM_CALLCONV fmsubadd_ps( __m128 a, __m128 b, __m128 c )
		{
			return _mm_fmsubadd_ps( a, b, c );
		}

		// Multiply packed double-precision floating-point elements in "a" and "b", add the negated intermediate result to packed elements in "c"
		inline __m128d XM_CALLCONV fnmadd_pd( __m128d a, __m128d b, __m128d c )
		{
			return _mm_fnmadd_pd( a, b, c );
		}

		// Multiply packed single-precision floating-point elements in "a" and "b", add the negated intermediate result to packed elements in "c"
		inline __m128 XM_CALLCONV fnmadd_ps( __m128 a, __m128 b, __m128 c )
		{
			return _mm_fnmadd_ps( a, b, c );
		}

		// Multiply the lower double-precision floating-point elements in "a" and "b", and add the negated intermediate result to the lower element in "c"
		inline __m128d XM_CALLCONV fnmadd_sd( __m128d a, __m128d b, __m128d c )
		{
			return _mm_fnmadd_sd( a, b, c );
		}

		// Multiply the lower single-precision floating-point elements in "a" and "b", and add the negated intermediate result to the lower element in "c"
		inline __m128 XM_CALLCONV fnmadd_ss( __m128 a, __m128 b, __m128 c )
		{
			return _mm_fnmadd_ss( a, b, c );
		}

		// Multiply packed double-precision floating-point elements in "a" and "b", subtract packed elements in "c" from the negated intermediate result
		inline __m128d XM_CALLCONV fnmsub_pd( __m128d a, __m128d b, __m128d c )
		{
			return _mm_fnmsub_pd( a, b, c );
		}

		// Multiply packed single-precision floating-point elements in "a" and "b", subtract packed elements in "c" from the negated intermediate result
		inline __m128 XM_CALLCONV fnmsub_ps( __m128 a, __m128 b, __m128 c )
		{
			return _mm_fnmsub_ps( a, b, c );
		}

		// Multiply the lower double-precision floating-point elements in "a" and "b", and subtract the lower element in "c" from the negated intermediate result
		inline __m128d XM_CALLCONV fnmsub_sd( __m128d a, __m128d b, __m128d c )
		{
			return _mm_fnmsub_sd( a, b, c );
		}

		// Multiply the lower single-precision floating-point elements in "a" and "b", and subtract the lower element in "c" from the negated intermediate result
		inline __m128 XM_CALLCONV fnmsub_ss( __m128 a, __m128 b, __m128 c )
		{
			return _mm_fnmsub_ss( a, b, c );
		}
	}	// namespace Intrinsics::Sse
}	// namespace Intrinsics