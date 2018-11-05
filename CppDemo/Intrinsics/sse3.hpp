// This file is generated automatically by a tool. If you want to change it, fork & modify the tool instead: https://github.com/Const-me/IntelIntrinsics
#pragma once
#include <pmmintrin.h>
#include "Extra/common.hpp"

namespace Intrinsics
{
	namespace Sse
	{
		// Alternatively add and subtract packed double-precision floating-point elements in "a" to/from packed elements in "b"
		inline __m128d XM_CALLCONV addsub_pd( __m128d a, __m128d b )
		{
			return _mm_addsub_pd( a, b );
		}

		// Alternatively add and subtract packed single-precision floating-point elements in "a" to/from packed elements in "b"
		inline __m128 XM_CALLCONV addsub_ps( __m128 a, __m128 b )
		{
			return _mm_addsub_ps( a, b );
		}

		// Horizontally add adjacent pairs of double-precision floating-point elements in "a" and "b", and pack the results in "dst"
		inline __m128d XM_CALLCONV hadd_pd( __m128d a, __m128d b )
		{
			return _mm_hadd_pd( a, b );
		}

		// Horizontally add adjacent pairs of single-precision floating-point elements in "a" and "b", and pack the results in "dst"
		inline __m128 XM_CALLCONV hadd_ps( __m128 a, __m128 b )
		{
			return _mm_hadd_ps( a, b );
		}

		// Horizontally subtract adjacent pairs of double-precision floating-point elements in "a" and "b", and pack the results in "dst"
		inline __m128d XM_CALLCONV hsub_pd( __m128d a, __m128d b )
		{
			return _mm_hsub_pd( a, b );
		}

		// Horizontally add adjacent pairs of single-precision floating-point elements in "a" and "b", and pack the results in "dst"
		inline __m128 XM_CALLCONV hsub_ps( __m128 a, __m128 b )
		{
			return _mm_hsub_ps( a, b );
		}

		// Load 128-bits of integer data from unaligned memory into "dst". This intrinsic may perform better than "_mm_loadu_si128" when the data crosses a cache line boundary.
		inline __m128i XM_CALLCONV lddqu_all( const __m128i *mem_addr )
		{
			return _mm_lddqu_si128( mem_addr );
		}

		// Load a double-precision floating-point element from memory into both elements of "dst"
		inline __m128d XM_CALLCONV loaddup_pd( const double *mem_addr )
		{
			return _mm_loaddup_pd( mem_addr );
		}

		// Duplicate the low double-precision floating-point element from "a"
		inline __m128d XM_CALLCONV movedup_pd( __m128d a )
		{
			return _mm_movedup_pd( a );
		}

		// Duplicate odd-indexed single-precision floating-point elements from "a"
		inline __m128 XM_CALLCONV movehdup_ps( __m128 a )
		{
			return _mm_movehdup_ps( a );
		}

		// Duplicate even-indexed single-precision floating-point elements from "a"
		inline __m128 XM_CALLCONV moveldup_ps( __m128 a )
		{
			return _mm_moveldup_ps( a );
		}
	}	// namespace Intrinsics::Sse
}	// namespace Intrinsics