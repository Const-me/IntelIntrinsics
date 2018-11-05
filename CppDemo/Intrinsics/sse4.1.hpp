// This file is generated automatically by a tool. If you want to change it, fork & modify the tool instead: https://github.com/Const-me/IntelIntrinsics
#pragma once
#include <smmintrin.h>
#include "Extra/common.hpp"

namespace Intrinsics
{
	namespace Sse
	{
		// Blend packed 16-bit integers from "a" and "b" using control mask "imm8"
		template<int imm8>
		inline __m128i XM_CALLCONV blend_epi16( __m128i a, __m128i b )
		{
			return _mm_blend_epi16( a, b, imm8 );
		}

		// Blend packed double-precision floating-point elements from "a" and "b" using control mask "imm8"
		template<int imm8>
		inline __m128d XM_CALLCONV blend_pd( __m128d a, __m128d b )
		{
			return _mm_blend_pd( a, b, imm8 );
		}

		// Blend packed single-precision floating-point elements from "a" and "b" using control mask "imm8"
		template<int imm8>
		inline __m128 XM_CALLCONV blend_ps( __m128 a, __m128 b )
		{
			return _mm_blend_ps( a, b, imm8 );
		}

		// Blend packed 8-bit integers from "a" and "b" using "mask", and store the results in "dst"
		inline __m128i XM_CALLCONV blendv_epi8( __m128i a, __m128i b, __m128i mask )
		{
			return _mm_blendv_epi8( a, b, mask );
		}

		// Blend packed double-precision floating-point elements from "a" and "b" using "mask"
		inline __m128d XM_CALLCONV blendv_pd( __m128d a, __m128d b, __m128d mask )
		{
			return _mm_blendv_pd( a, b, mask );
		}

		// Blend packed single-precision floating-point elements from "a" and "b" using "mask"
		inline __m128 XM_CALLCONV blendv_ps( __m128 a, __m128 b, __m128 mask )
		{
			return _mm_blendv_ps( a, b, mask );
		}

		// Round the packed double-precision floating-point elements in "a" up to an integer value
		inline __m128d XM_CALLCONV ceil_pd( __m128d a )
		{
			return _mm_ceil_pd( a );
		}

		// Round the packed single-precision floating-point elements in "a" up to an integer value
		inline __m128 XM_CALLCONV ceil_ps( __m128 a )
		{
			return _mm_ceil_ps( a );
		}

		// Round the lower double-precision floating-point element in "b" up to an integer value
		inline __m128d XM_CALLCONV ceil_sd( __m128d a, __m128d b )
		{
			return _mm_ceil_sd( a, b );
		}

		// Round the lower single-precision floating-point element in "b" up to an integer value
		inline __m128 XM_CALLCONV ceil_ss( __m128 a, __m128 b )
		{
			return _mm_ceil_ss( a, b );
		}

		// Compare packed 64-bit integers in "a" and "b" for equality, and store the results in "dst"
		inline __m128i XM_CALLCONV cmpeq_epi64( __m128i a, __m128i b )
		{
			return _mm_cmpeq_epi64( a, b );
		}

		// Sign extend packed 16-bit integers in "a" to packed 32-bit integers
		inline __m128i XM_CALLCONV cvtepi16_epi32( __m128i a )
		{
			return _mm_cvtepi16_epi32( a );
		}

		// Sign extend packed 16-bit integers in "a" to packed 64-bit integers
		inline __m128i XM_CALLCONV cvtepi16_epi64( __m128i a )
		{
			return _mm_cvtepi16_epi64( a );
		}

		// Sign extend packed 32-bit integers in "a" to packed 64-bit integers
		inline __m128i XM_CALLCONV cvtepi32_epi64( __m128i a )
		{
			return _mm_cvtepi32_epi64( a );
		}

		// Sign extend packed 8-bit integers in "a" to packed 16-bit integers
		inline __m128i XM_CALLCONV cvtepi8_epi16( __m128i a )
		{
			return _mm_cvtepi8_epi16( a );
		}

		// Sign extend packed 8-bit integers in "a" to packed 32-bit integers
		inline __m128i XM_CALLCONV cvtepi8_epi32( __m128i a )
		{
			return _mm_cvtepi8_epi32( a );
		}

		// Sign extend packed 8-bit integers in the low 8 bytes of "a" to packed 64-bit integers
		inline __m128i XM_CALLCONV cvtepi8_epi64( __m128i a )
		{
			return _mm_cvtepi8_epi64( a );
		}

		// Zero extend packed unsigned 16-bit integers in "a" to packed 32-bit integers
		inline __m128i XM_CALLCONV cvtepu16_epi32( __m128i a )
		{
			return _mm_cvtepu16_epi32( a );
		}

		// Zero extend packed unsigned 16-bit integers in "a" to packed 64-bit integers
		inline __m128i XM_CALLCONV cvtepu16_epi64( __m128i a )
		{
			return _mm_cvtepu16_epi64( a );
		}

		// Zero extend packed unsigned 32-bit integers in "a" to packed 64-bit integers
		inline __m128i XM_CALLCONV cvtepu32_epi64( __m128i a )
		{
			return _mm_cvtepu32_epi64( a );
		}

		// Zero extend packed unsigned 8-bit integers in "a" to packed 16-bit integers
		inline __m128i XM_CALLCONV cvtepu8_epi16( __m128i a )
		{
			return _mm_cvtepu8_epi16( a );
		}

		// Zero extend packed unsigned 8-bit integers in "a" to packed 32-bit integers
		inline __m128i XM_CALLCONV cvtepu8_epi32( __m128i a )
		{
			return _mm_cvtepu8_epi32( a );
		}

		// Zero extend packed unsigned 8-bit integers in the low 8 byte sof "a" to packed 64-bit integers
		inline __m128i XM_CALLCONV cvtepu8_epi64( __m128i a )
		{
			return _mm_cvtepu8_epi64( a );
		}

		// Conditionally multiply the packed double-precision floating-point elements in "a" and "b" using the high 4 bits in "imm8", sum the four products, and conditionally store the sum in "dst" using the low 4 bits of "imm8"
		template<int imm8>
		inline __m128d XM_CALLCONV dp_pd( __m128d a, __m128d b )
		{
			return _mm_dp_pd( a, b, imm8 );
		}

		// Conditionally multiply the packed single-precision floating-point elements in "a" and "b" using the high 4 bits in "imm8", sum the four products, and conditionally store the sum in "dst" using the low 4 bits of "imm8"
		template<int imm8>
		inline __m128 XM_CALLCONV dp_ps( __m128 a, __m128 b )
		{
			return _mm_dp_ps( a, b, imm8 );
		}

		// Extract an 8-bit integer from "a", selected with "imm8", and store the result in the lower element of "dst"
		template<int imm8>
		inline int XM_CALLCONV extract_epi8( __m128i a )
		{
			return _mm_extract_epi8( a, imm8 );
		}

		// Extract a 32-bit integer from "a", selected with "imm8", and store the result in "dst"
		template<int imm8>
		inline int XM_CALLCONV extract_epi32( __m128i a )
		{
			return _mm_extract_epi32( a, imm8 );
		}

		// Extract a 64-bit integer from "a", selected with "imm8", and store the result in "dst"
		template<int imm8>
		inline int64_t XM_CALLCONV extract_epi64( __m128i a )
		{
			return (int64_t)_mm_extract_epi64( a, imm8 );
		}

		// Extract a single-precision floating-point element from "a", selected with "imm8"
		template<int imm8>
		inline int XM_CALLCONV extract_ps( __m128 a )
		{
			return _mm_extract_ps( a, imm8 );
		}

		// Round the packed double-precision floating-point elements in "a" down to an integer value
		inline __m128d XM_CALLCONV floor_pd( __m128d a )
		{
			return _mm_floor_pd( a );
		}

		// Round the packed single-precision floating-point elements in "a" down to an integer value
		inline __m128 XM_CALLCONV floor_ps( __m128 a )
		{
			return _mm_floor_ps( a );
		}

		// Round the lower double-precision floating-point element in "b" down to an integer value
		inline __m128d XM_CALLCONV floor_sd( __m128d a, __m128d b )
		{
			return _mm_floor_sd( a, b );
		}

		// Round the lower single-precision floating-point element in "b" down to an integer value
		inline __m128 XM_CALLCONV floor_ss( __m128 a, __m128 b )
		{
			return _mm_floor_ss( a, b );
		}

		// Copy "a" to "dst", and insert the lower 8-bit integer from "i" into "dst" at the location specified by "imm8"
		template<int imm8>
		inline __m128i XM_CALLCONV insert_epi8( __m128i a, int i )
		{
			return _mm_insert_epi8( a, i, imm8 );
		}

		// Copy "a" to "dst", and insert the 32-bit integer "i" into "dst" at the location specified by "imm8"
		template<int imm8>
		inline __m128i XM_CALLCONV insert_epi32( __m128i a, int i )
		{
			return _mm_insert_epi32( a, i, imm8 );
		}

		// Copy "a" to "dst", and insert the 64-bit integer "i" into "dst" at the location specified by "imm8"
		template<int imm8>
		inline __m128i XM_CALLCONV insert_epi64( __m128i a, int64_t i )
		{
			return _mm_insert_epi64( a, (real_int64_t)i, imm8 );
		}

		// Copy "a" to "tmp", then insert a single-precision floating-point element from "b" into "tmp" using the control in "imm8"
		template<int imm8>
		inline __m128 XM_CALLCONV insert_ps( __m128 a, __m128 b )
		{
			return _mm_insert_ps( a, b, imm8 );
		}

		// Compare packed 8-bit integers in "a" and "b", and store packed maximum values in "dst"
		inline __m128i XM_CALLCONV max_epi8( __m128i a, __m128i b )
		{
			return _mm_max_epi8( a, b );
		}

		// Compare packed 32-bit integers in "a" and "b", and store packed maximum values in "dst"
		inline __m128i XM_CALLCONV max_epi32( __m128i a, __m128i b )
		{
			return _mm_max_epi32( a, b );
		}

		// Compare packed unsigned 16-bit integers in "a" and "b", and store packed maximum values in "dst"
		inline __m128i XM_CALLCONV max_epu16( __m128i a, __m128i b )
		{
			return _mm_max_epu16( a, b );
		}

		// Compare packed unsigned 32-bit integers in "a" and "b", and store packed maximum values in "dst"
		inline __m128i XM_CALLCONV max_epu32( __m128i a, __m128i b )
		{
			return _mm_max_epu32( a, b );
		}

		// Compare packed 8-bit integers in "a" and "b", and store packed minimum values in "dst"
		inline __m128i XM_CALLCONV min_epi8( __m128i a, __m128i b )
		{
			return _mm_min_epi8( a, b );
		}

		// Compare packed 32-bit integers in "a" and "b", and store packed minimum values in "dst"
		inline __m128i XM_CALLCONV min_epi32( __m128i a, __m128i b )
		{
			return _mm_min_epi32( a, b );
		}

		// Compare packed unsigned 16-bit integers in "a" and "b", and store packed minimum values in "dst"
		inline __m128i XM_CALLCONV min_epu16( __m128i a, __m128i b )
		{
			return _mm_min_epu16( a, b );
		}

		// Compare packed unsigned 32-bit integers in "a" and "b", and store packed minimum values in "dst"
		inline __m128i XM_CALLCONV min_epu32( __m128i a, __m128i b )
		{
			return _mm_min_epu32( a, b );
		}

		// Horizontally compute the minimum amongst the packed unsigned 16-bit integers in "a", store the minimum and index in "dst", and zero the remaining bits in "dst"
		inline __m128i XM_CALLCONV minpos_epu16( __m128i a )
		{
			return _mm_minpos_epu16( a );
		}

		// Compute the sum of absolute differences (SADs) of quadruplets of unsigned 8-bit integers in "a" compared to those in "b", and store the 16-bit results in "dst"
		template<int imm8>
		inline __m128i XM_CALLCONV mpsadbw_epu8( __m128i a, __m128i b )
		{
			return _mm_mpsadbw_epu8( a, b, imm8 );
		}

		// Multiply the low 32-bit integers from each packed 64-bit element in "a" and "b", and store the signed 64-bit results in "dst"
		inline __m128i XM_CALLCONV mul_epi32( __m128i a, __m128i b )
		{
			return _mm_mul_epi32( a, b );
		}

		// Multiply the packed 32-bit integers in "a" and "b", producing intermediate 64-bit integers, and store the low 32 bits of the intermediate integers in "dst"
		inline __m128i XM_CALLCONV mullo_epi32( __m128i a, __m128i b )
		{
			return _mm_mullo_epi32( a, b );
		}

		// Convert packed 32-bit integers from "a" and "b" to packed 16-bit integers using unsigned saturation
		inline __m128i XM_CALLCONV packus_epi32( __m128i a, __m128i b )
		{
			return _mm_packus_epi32( a, b );
		}

		// Round the packed double-precision floating-point elements in "a" using the "rounding" parameter
		template<int rounding>
		inline __m128d XM_CALLCONV round_pd( __m128d a )
		{
			return _mm_round_pd( a, rounding );
		}

		// Round the packed single-precision floating-point elements in "a" using the "rounding" parameter
		template<int rounding>
		inline __m128 XM_CALLCONV round_ps( __m128 a )
		{
			return _mm_round_ps( a, rounding );
		}

		// Round the lower double-precision floating-point element in "b" using the "rounding" parameter
		template<int rounding>
		inline __m128d XM_CALLCONV round_sd( __m128d a, __m128d b )
		{
			return _mm_round_sd( a, b, rounding );
		}

		// Round the lower single-precision floating-point element in "b" using the "rounding" parameter
		template<int rounding>
		inline __m128 XM_CALLCONV round_ss( __m128 a, __m128 b )
		{
			return _mm_round_ss( a, b, rounding );
		}

		// Load 128-bits of integer data from memory into "dst" using a non-temporal memory hint
		inline __m128i XM_CALLCONV stream_load_all( __m128i *mem_addr )
		{
			return _mm_stream_load_si128( mem_addr );
		}

		// Compute the bitwise NOT of "a" and then AND with a 128-bit vector containing all 1's
		inline int XM_CALLCONV test_all_ones( __m128i a )
		{
			return _mm_test_all_ones( a );
		}

		// Compute the bitwise AND of 128 bits (representing integer data) in "a" and "mask"
		inline int XM_CALLCONV test_all_zeros( __m128i a, __m128i mask )
		{
			return _mm_test_all_zeros( a, mask );
		}

		// Compute the bitwise AND of 128 bits (representing integer data) in "a" and "mask", and set "ZF" to 1 if the result is zero, otherwise set "ZF" to 0
		inline int XM_CALLCONV test_mix_ones_zeros( __m128i a, __m128i mask )
		{
			return _mm_test_mix_ones_zeros( a, mask );
		}

		// Compute the bitwise AND of 128 bits (representing integer data) in "a" and "b", and set "ZF" to 1 if the result is zero, otherwise set "ZF" to 0
		inline int XM_CALLCONV testc_all( __m128i a, __m128i b )
		{
			return _mm_testc_si128( a, b );
		}

		// Compute the bitwise AND of 128 bits (representing integer data) in "a" and "b", and set "ZF" to 1 if the result is zero, otherwise set "ZF" to 0
		inline int XM_CALLCONV testnzc_all( __m128i a, __m128i b )
		{
			return _mm_testnzc_si128( a, b );
		}

		// Compute the bitwise AND of 128 bits (representing integer data) in "a" and "b", and set "ZF" to 1 if the result is zero, otherwise set "ZF" to 0
		inline int XM_CALLCONV testz_all( __m128i a, __m128i b )
		{
			return _mm_testz_si128( a, b );
		}
	}	// namespace Intrinsics::Sse
}	// namespace Intrinsics