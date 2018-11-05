// This file is generated automatically by a tool. If you want to change it, fork & modify the tool instead: https://github.com/Const-me/IntelIntrinsics
#pragma once
#include <tmmintrin.h>
#include "Extra/common.hpp"

namespace Intrinsics
{
	namespace Sse
	{
		// Compute the absolute value of packed 8-bit integers in "a", and store the unsigned results in "dst"
		inline __m128i XM_CALLCONV abs_epi8( __m128i a )
		{
			return _mm_abs_epi8( a );
		}

		// Compute the absolute value of packed 16-bit integers in "a", and store the unsigned results in "dst"
		inline __m128i XM_CALLCONV abs_epi16( __m128i a )
		{
			return _mm_abs_epi16( a );
		}

		// Compute the absolute value of packed 32-bit integers in "a", and store the unsigned results in "dst"
		inline __m128i XM_CALLCONV abs_epi32( __m128i a )
		{
			return _mm_abs_epi32( a );
		}

		// Concatenate 16-byte blocks in "a" and "b" into a 32-byte temporary result, shift the result right by "count" bytes, and store the low 16 bytes in "dst"
		template<int count>
		inline __m128i XM_CALLCONV alignr_epi8( __m128i a, __m128i b )
		{
			return _mm_alignr_epi8( a, b, count );
		}

		// Horizontally add adjacent pairs of 16-bit integers in "a" and "b", and pack the signed 16-bit results in "dst"
		inline __m128i XM_CALLCONV hadd_epi16( __m128i a, __m128i b )
		{
			return _mm_hadd_epi16( a, b );
		}

		// Horizontally add adjacent pairs of 32-bit integers in "a" and "b", and pack the signed 32-bit results in "dst"
		inline __m128i XM_CALLCONV hadd_epi32( __m128i a, __m128i b )
		{
			return _mm_hadd_epi32( a, b );
		}

		// Horizontally add adjacent pairs of 16-bit integers in "a" and "b" using saturation, and pack the signed 16-bit results in "dst"
		inline __m128i XM_CALLCONV hadds_epi16( __m128i a, __m128i b )
		{
			return _mm_hadds_epi16( a, b );
		}

		// Horizontally subtract adjacent pairs of 16-bit integers in "a" and "b", and pack the signed 16-bit results in "dst"
		inline __m128i XM_CALLCONV hsub_epi16( __m128i a, __m128i b )
		{
			return _mm_hsub_epi16( a, b );
		}

		// Horizontally subtract adjacent pairs of 32-bit integers in "a" and "b", and pack the signed 32-bit results in "dst"
		inline __m128i XM_CALLCONV hsub_epi32( __m128i a, __m128i b )
		{
			return _mm_hsub_epi32( a, b );
		}

		// Horizontally subtract adjacent pairs of 16-bit integers in "a" and "b" using saturation, and pack the signed 16-bit results in "dst"
		inline __m128i XM_CALLCONV hsubs_epi16( __m128i a, __m128i b )
		{
			return _mm_hsubs_epi16( a, b );
		}

		// Vertically multiply each unsigned 8-bit integer from "a" with the corresponding signed 8-bit integer from "b", producing intermediate signed 16-bit integers
		inline __m128i XM_CALLCONV maddubs_epi16( __m128i a, __m128i b )
		{
			return _mm_maddubs_epi16( a, b );
		}

		// Multiply packed 16-bit integers in "a" and "b", producing intermediate signed 32-bit integers
		inline __m128i XM_CALLCONV mulhrs_epi16( __m128i a, __m128i b )
		{
			return _mm_mulhrs_epi16( a, b );
		}

		// Shuffle packed 8-bit integers in "a" according to shuffle control mask in the corresponding 8-bit element of "b"
		inline __m128i XM_CALLCONV shuffle_epi8( __m128i a, __m128i b )
		{
			return _mm_shuffle_epi8( a, b );
		}

		// Negate packed 8-bit integers in "a" when the corresponding signed 8-bit integer in "b" is negative
		inline __m128i XM_CALLCONV sign_epi8( __m128i a, __m128i b )
		{
			return _mm_sign_epi8( a, b );
		}

		// Negate packed 16-bit integers in "a" when the corresponding signed 16-bit integer in "b" is negative
		inline __m128i XM_CALLCONV sign_epi16( __m128i a, __m128i b )
		{
			return _mm_sign_epi16( a, b );
		}

		// Negate packed 32-bit integers in "a" when the corresponding signed 32-bit integer in "b" is negative
		inline __m128i XM_CALLCONV sign_epi32( __m128i a, __m128i b )
		{
			return _mm_sign_epi32( a, b );
		}
	}	// namespace Intrinsics::Sse
}	// namespace Intrinsics