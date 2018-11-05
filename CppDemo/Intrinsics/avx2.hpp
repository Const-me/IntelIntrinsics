// This file is generated automatically by a tool. If you want to change it, fork & modify the tool instead: https://github.com/Const-me/IntelIntrinsics
#pragma once
#include <immintrin.h>
#include "Extra/common.hpp"

namespace Intrinsics
{
	namespace Avx
	{
		// Compute the absolute value of packed 8-bit integers in "a", and store the unsigned results in "dst"
		inline __m256i XM_CALLCONV abs_epi8( __m256i a )
		{
			return _mm256_abs_epi8( a );
		}

		// Compute the absolute value of packed 16-bit integers in "a", and store the unsigned results in "dst"
		inline __m256i XM_CALLCONV abs_epi16( __m256i a )
		{
			return _mm256_abs_epi16( a );
		}

		// Compute the absolute value of packed 32-bit integers in "a", and store the unsigned results in "dst"
		inline __m256i XM_CALLCONV abs_epi32( __m256i a )
		{
			return _mm256_abs_epi32( a );
		}

		// Add packed 8-bit integers in "a" and "b", and store the results in "dst"
		inline __m256i XM_CALLCONV add_epi8( __m256i a, __m256i b )
		{
			return _mm256_add_epi8( a, b );
		}

		// Add packed 16-bit integers in "a" and "b", and store the results in "dst"
		inline __m256i XM_CALLCONV add_epi16( __m256i a, __m256i b )
		{
			return _mm256_add_epi16( a, b );
		}

		// Add packed 32-bit integers in "a" and "b", and store the results in "dst"
		inline __m256i XM_CALLCONV add_epi32( __m256i a, __m256i b )
		{
			return _mm256_add_epi32( a, b );
		}

		// Add packed 64-bit integers in "a" and "b", and store the results in "dst"
		inline __m256i XM_CALLCONV add_epi64( __m256i a, __m256i b )
		{
			return _mm256_add_epi64( a, b );
		}

		// Add packed 8-bit integers in "a" and "b" using saturation, and store the results in "dst"
		inline __m256i XM_CALLCONV adds_epi8( __m256i a, __m256i b )
		{
			return _mm256_adds_epi8( a, b );
		}

		// Add packed 16-bit integers in "a" and "b" using saturation, and store the results in "dst"
		inline __m256i XM_CALLCONV adds_epi16( __m256i a, __m256i b )
		{
			return _mm256_adds_epi16( a, b );
		}

		// Add packed unsigned 8-bit integers in "a" and "b" using saturation
		inline __m256i XM_CALLCONV adds_epu8( __m256i a, __m256i b )
		{
			return _mm256_adds_epu8( a, b );
		}

		// Add packed unsigned 16-bit integers in "a" and "b" using saturation
		inline __m256i XM_CALLCONV adds_epu16( __m256i a, __m256i b )
		{
			return _mm256_adds_epu16( a, b );
		}

		// Concatenate pairs of 16-byte blocks in "a" and "b" into a 32-byte temporary result, shift the result right by "count" bytes, and store the low 16 bytes in "dst"
		template<int count>
		inline __m256i XM_CALLCONV alignr_epi8( __m256i a, __m256i b )
		{
			return _mm256_alignr_epi8( a, b, count );
		}

		// Compute the bitwise AND of 256 bits (representing integer data) in "a" and "b"
		inline __m256i XM_CALLCONV and_all( __m256i a, __m256i b )
		{
			return _mm256_and_si256( a, b );
		}

		// Compute the bitwise NOT of 256 bits (representing integer data) in "a" and then AND with "b"
		inline __m256i XM_CALLCONV andnot_all( __m256i a, __m256i b )
		{
			return _mm256_andnot_si256( a, b );
		}

		// Average packed unsigned 8-bit integers in "a" and "b", and store the results in "dst"
		inline __m256i XM_CALLCONV avg_epu8( __m256i a, __m256i b )
		{
			return _mm256_avg_epu8( a, b );
		}

		// Average packed unsigned 16-bit integers in "a" and "b", and store the results in "dst"
		inline __m256i XM_CALLCONV avg_epu16( __m256i a, __m256i b )
		{
			return _mm256_avg_epu16( a, b );
		}

		// Blend packed 16-bit integers from "a" and "b" within 128-bit lanes using control mask "imm8"
		template<int imm8>
		inline __m256i XM_CALLCONV blend_epi16( __m256i a, __m256i b )
		{
			return _mm256_blend_epi16( a, b, imm8 );
		}

		// Blend packed 32-bit integers from "a" and "b" using control mask "imm8"
		template<int imm8>
		inline __m256i XM_CALLCONV blend_epi32( __m256i a, __m256i b )
		{
			return _mm256_blend_epi32( a, b, imm8 );
		}

		// Blend packed 8-bit integers from "a" and "b" using "mask", and store the results in "dst"
		inline __m256i XM_CALLCONV blendv_epi8( __m256i a, __m256i b, __m256i mask )
		{
			return _mm256_blendv_epi8( a, b, mask );
		}

		// Broadcast the low packed 8-bit integer from "a" to all elements of "dst"
		inline __m256i XM_CALLCONV broadcast_epi8( __m128i a )
		{
			return _mm256_broadcastb_epi8( a );
		}

		// Broadcast the low packed 32-bit integer from "a" to all elements of "dst"
		inline __m256i XM_CALLCONV broadcast_epi32( __m128i a )
		{
			return _mm256_broadcastd_epi32( a );
		}

		// Broadcast the low packed 64-bit integer from "a" to all elements of "dst"
		inline __m256i XM_CALLCONV broadcast_epi64( __m128i a )
		{
			return _mm256_broadcastq_epi64( a );
		}

		// Broadcast the low double-precision floating-point element from "a" to all elements of "dst"
		inline __m256d XM_CALLCONV broadcast_pd( __m128d a )
		{
			return _mm256_broadcastsd_pd( a );
		}

		// Broadcast 128 bits of integer data from "a" to all 128-bit lanes in "dst"
		inline __m256i XM_CALLCONV broadcast_all( __m128i a )
		{
			return _mm256_broadcastsi128_si256( a );
		}

		// Broadcast the low single-precision floating-point element from "a" to all elements of "dst"
		inline __m256 XM_CALLCONV broadcast_ps( __m128 a )
		{
			return _mm256_broadcastss_ps( a );
		}

		// Broadcast the low packed 16-bit integer from "a" to all elements of "dst"
		inline __m256i XM_CALLCONV broadcast_epi16( __m128i a )
		{
			return _mm256_broadcastw_epi16( a );
		}

		// Shift 128-bit lanes in "a" left by "imm8" bytes while shifting in zeros
		template<int imm8>
		inline __m256i XM_CALLCONV bslli_epi128( __m256i a )
		{
			return _mm256_bslli_epi128( a, imm8 );
		}

		// Shift 128-bit lanes in "a" right by "imm8" bytes while shifting in zeros
		template<int imm8>
		inline __m256i XM_CALLCONV bsrli_epi128( __m256i a )
		{
			return _mm256_bsrli_epi128( a, imm8 );
		}

		// Compare packed 8-bit integers in "a" and "b" for equality, and store the results in "dst"
		inline __m256i XM_CALLCONV cmpeq_epi8( __m256i a, __m256i b )
		{
			return _mm256_cmpeq_epi8( a, b );
		}

		// Compare packed 16-bit integers in "a" and "b" for equality, and store the results in "dst"
		inline __m256i XM_CALLCONV cmpeq_epi16( __m256i a, __m256i b )
		{
			return _mm256_cmpeq_epi16( a, b );
		}

		// Compare packed 32-bit integers in "a" and "b" for equality, and store the results in "dst"
		inline __m256i XM_CALLCONV cmpeq_epi32( __m256i a, __m256i b )
		{
			return _mm256_cmpeq_epi32( a, b );
		}

		// Compare packed 64-bit integers in "a" and "b" for equality, and store the results in "dst"
		inline __m256i XM_CALLCONV cmpeq_epi64( __m256i a, __m256i b )
		{
			return _mm256_cmpeq_epi64( a, b );
		}

		// Compare packed 8-bit integers in "a" and "b" for greater-than, and store the results in "dst"
		inline __m256i XM_CALLCONV cmpgt_epi8( __m256i a, __m256i b )
		{
			return _mm256_cmpgt_epi8( a, b );
		}

		// Compare packed 16-bit integers in "a" and "b" for greater-than, and store the results in "dst"
		inline __m256i XM_CALLCONV cmpgt_epi16( __m256i a, __m256i b )
		{
			return _mm256_cmpgt_epi16( a, b );
		}

		// Compare packed 32-bit integers in "a" and "b" for greater-than, and store the results in "dst"
		inline __m256i XM_CALLCONV cmpgt_epi32( __m256i a, __m256i b )
		{
			return _mm256_cmpgt_epi32( a, b );
		}

		// Compare packed 64-bit integers in "a" and "b" for greater-than, and store the results in "dst"
		inline __m256i XM_CALLCONV cmpgt_epi64( __m256i a, __m256i b )
		{
			return _mm256_cmpgt_epi64( a, b );
		}

		// Sign extend packed 16-bit integers in "a" to packed 32-bit integers
		inline __m256i XM_CALLCONV cvtepi16_epi32( __m128i a )
		{
			return _mm256_cvtepi16_epi32( a );
		}

		// Sign extend packed 16-bit integers in "a" to packed 64-bit integers
		inline __m256i XM_CALLCONV cvtepi16_epi64( __m128i a )
		{
			return _mm256_cvtepi16_epi64( a );
		}

		// Sign extend packed 32-bit integers in "a" to packed 64-bit integers
		inline __m256i XM_CALLCONV cvtepi32_epi64( __m128i a )
		{
			return _mm256_cvtepi32_epi64( a );
		}

		// Sign extend packed 8-bit integers in "a" to packed 16-bit integers
		inline __m256i XM_CALLCONV cvtepi8_epi16( __m128i a )
		{
			return _mm256_cvtepi8_epi16( a );
		}

		// Sign extend packed 8-bit integers in "a" to packed 32-bit integers
		inline __m256i XM_CALLCONV cvtepi8_epi32( __m128i a )
		{
			return _mm256_cvtepi8_epi32( a );
		}

		// Sign extend packed 8-bit integers in the low 8 bytes of "a" to packed 64-bit integers
		inline __m256i XM_CALLCONV cvtepi8_epi64( __m128i a )
		{
			return _mm256_cvtepi8_epi64( a );
		}

		// Zero extend packed unsigned 16-bit integers in "a" to packed 32-bit integers
		inline __m256i XM_CALLCONV cvtepu16_epi32( __m128i a )
		{
			return _mm256_cvtepu16_epi32( a );
		}

		// Zero extend packed unsigned 16-bit integers in "a" to packed 64-bit integers
		inline __m256i XM_CALLCONV cvtepu16_epi64( __m128i a )
		{
			return _mm256_cvtepu16_epi64( a );
		}

		// Zero extend packed unsigned 32-bit integers in "a" to packed 64-bit integers
		inline __m256i XM_CALLCONV cvtepu32_epi64( __m128i a )
		{
			return _mm256_cvtepu32_epi64( a );
		}

		// Zero extend packed unsigned 8-bit integers in "a" to packed 16-bit integers
		inline __m256i XM_CALLCONV cvtepu8_epi16( __m128i a )
		{
			return _mm256_cvtepu8_epi16( a );
		}

		// Zero extend packed unsigned 8-bit integers in "a" to packed 32-bit integers
		inline __m256i XM_CALLCONV cvtepu8_epi32( __m128i a )
		{
			return _mm256_cvtepu8_epi32( a );
		}

		// Zero extend packed unsigned 8-bit integers in the low 8 byte sof "a" to packed 64-bit integers
		inline __m256i XM_CALLCONV cvtepu8_epi64( __m128i a )
		{
			return _mm256_cvtepu8_epi64( a );
		}

		// Extract an 8-bit integer from "a", selected with "index", and store the result in "dst"
		template<int index>
		inline int XM_CALLCONV extract_epi8( __m256i a )
		{
			return _mm256_extract_epi8( a, index );
		}

		// Extract a 16-bit integer from "a", selected with "index", and store the result in "dst"
		template<int index>
		inline int XM_CALLCONV extract_epi16( __m256i a )
		{
			return _mm256_extract_epi16( a, index );
		}

		// Extract 128 bits (composed of integer data) from "a", selected with "imm8"
		template<int imm8>
		inline __m128i XM_CALLCONV extracti128_all( __m256i a )
		{
			return _mm256_extracti128_si256( a, imm8 );
		}

		// Horizontally add adjacent pairs of 16-bit integers in "a" and "b", and pack the signed 16-bit results in "dst"
		inline __m256i XM_CALLCONV hadd_epi16( __m256i a, __m256i b )
		{
			return _mm256_hadd_epi16( a, b );
		}

		// Horizontally add adjacent pairs of 32-bit integers in "a" and "b", and pack the signed 32-bit results in "dst"
		inline __m256i XM_CALLCONV hadd_epi32( __m256i a, __m256i b )
		{
			return _mm256_hadd_epi32( a, b );
		}

		// Horizontally add adjacent pairs of 16-bit integers in "a" and "b" using saturation, and pack the signed 16-bit results in "dst"
		inline __m256i XM_CALLCONV hadds_epi16( __m256i a, __m256i b )
		{
			return _mm256_hadds_epi16( a, b );
		}

		// Horizontally subtract adjacent pairs of 16-bit integers in "a" and "b", and pack the signed 16-bit results in "dst"
		inline __m256i XM_CALLCONV hsub_epi16( __m256i a, __m256i b )
		{
			return _mm256_hsub_epi16( a, b );
		}

		// Horizontally subtract adjacent pairs of 32-bit integers in "a" and "b", and pack the signed 32-bit results in "dst"
		inline __m256i XM_CALLCONV hsub_epi32( __m256i a, __m256i b )
		{
			return _mm256_hsub_epi32( a, b );
		}

		// Horizontally subtract adjacent pairs of 16-bit integers in "a" and "b" using saturation, and pack the signed 16-bit results in "dst"
		inline __m256i XM_CALLCONV hsubs_epi16( __m256i a, __m256i b )
		{
			return _mm256_hsubs_epi16( a, b );
		}

		// Gather 32-bit integers from memory using 32-bit indices. 32-bit elements are loaded from addresses starting at "base_addr" and offset by each 32-bit element in "vindex" (each index is scaled by the factor in "scale"). Gathered elements are merged into "dst". "scale" should be 1, 2, 4 or 8.
		template<int scale>
		inline __m256i XM_CALLCONV i32gather_epi32( const int *base_addr, __m256i vindex )
		{
			return _mm256_i32gather_epi32( base_addr, vindex, scale );
		}

		// Gather 64-bit integers from memory using 32-bit indices. 64-bit elements are loaded from addresses starting at "base_addr" and offset by each 32-bit element in "vindex" (each index is scaled by the factor in "scale"). Gathered elements are merged into "dst". "scale" should be 1, 2, 4 or 8.
		template<int scale>
		inline __m256i XM_CALLCONV i32gather_epi64( const int64_t *base_addr, __m128i vindex )
		{
			return _mm256_i32gather_epi64( (const real_int64_t *)base_addr, vindex, scale );
		}

		// Gather double-precision floating-point elements from memory using 32-bit indices
		template<int scale>
		inline __m256d XM_CALLCONV i32gather_pd( const double *base_addr, __m128i vindex )
		{
			return _mm256_i32gather_pd( base_addr, vindex, scale );
		}

		// Gather single-precision floating-point elements from memory using 32-bit indices
		template<int scale>
		inline __m256 XM_CALLCONV i32gather_ps( const float *base_addr, __m256i vindex )
		{
			return _mm256_i32gather_ps( base_addr, vindex, scale );
		}

		// Gather 32-bit integers from memory using 64-bit indices. 32-bit elements are loaded from addresses starting at "base_addr" and offset by each 64-bit element in "vindex" (each index is scaled by the factor in "scale"). Gathered elements are merged into "dst". "scale" should be 1, 2, 4 or 8.
		template<int scale>
		inline __m128i XM_CALLCONV i64gather_epi32( const int *base_addr, __m256i vindex )
		{
			return _mm256_i64gather_epi32( base_addr, vindex, scale );
		}

		// Gather 64-bit integers from memory using 64-bit indices. 64-bit elements are loaded from addresses starting at "base_addr" and offset by each 64-bit element in "vindex" (each index is scaled by the factor in "scale"). Gathered elements are merged into "dst". "scale" should be 1, 2, 4 or 8.
		template<int scale>
		inline __m256i XM_CALLCONV i64gather_epi64( const int64_t *base_addr, __m256i vindex )
		{
			return _mm256_i64gather_epi64( (const real_int64_t *)base_addr, vindex, scale );
		}

		// Gather double-precision floating-point elements from memory using 64-bit indices
		template<int scale>
		inline __m256d XM_CALLCONV i64gather_pd( const double *base_addr, __m256i vindex )
		{
			return _mm256_i64gather_pd( base_addr, vindex, scale );
		}

		// Gather single-precision floating-point elements from memory using 64-bit indices
		template<int scale>
		inline __m128 XM_CALLCONV i64gather_ps( const float *base_addr, __m256i vindex )
		{
			return _mm256_i64gather_ps( base_addr, vindex, scale );
		}

		// Copy "a" to "dst", then insert 128 bits (composed of integer data) from "b" into "dst" at the location specified by "imm8"
		template<int imm8>
		inline __m256i XM_CALLCONV inserti128_all( __m256i a, __m128i b )
		{
			return _mm256_inserti128_si256( a, b, imm8 );
		}

		// Multiply packed signed 16-bit integers in "a" and "b", producing intermediate signed 32-bit integers
		inline __m256i XM_CALLCONV madd_epi16( __m256i a, __m256i b )
		{
			return _mm256_madd_epi16( a, b );
		}

		// Vertically multiply each unsigned 8-bit integer from "a" with the corresponding signed 8-bit integer from "b", producing intermediate signed 16-bit integers
		inline __m256i XM_CALLCONV maddubs_epi16( __m256i a, __m256i b )
		{
			return _mm256_maddubs_epi16( a, b );
		}

		// Gather 32-bit integers from memory using 32-bit indices. 32-bit elements are loaded from addresses starting at "base_addr" and offset by each 32-bit element in "vindex" (each index is scaled by the factor in "scale"). Gathered elements are merged into "dst" using "mask" (elements are copied from "src" when the highest bit is not set in the corresponding element). "scale" should be 1, 2, 4 or 8.
		template<int scale>
		inline __m256i XM_CALLCONV mask_i32gather_epi32( __m256i src, const int *base_addr, __m256i vindex, __m256i mask )
		{
			return _mm256_mask_i32gather_epi32( src, base_addr, vindex, mask, scale );
		}

		// Gather 64-bit integers from memory using 32-bit indices. 64-bit elements are loaded from addresses starting at "base_addr" and offset by each 32-bit element in "vindex" (each index is scaled by the factor in "scale"). Gathered elements are merged into "dst" using "mask" (elements are copied from "src" when the highest bit is not set in the corresponding element). "scale" should be 1, 2, 4 or 8.
		template<int scale>
		inline __m256i XM_CALLCONV mask_i32gather_epi64( __m256i src, const int64_t *base_addr, __m128i vindex, __m256i mask )
		{
			return _mm256_mask_i32gather_epi64( src, (const real_int64_t *)base_addr, vindex, mask, scale );
		}

		// Gather double-precision floating-point elements from memory using 32-bit indices
		template<int scale>
		inline __m256d XM_CALLCONV mask_i32gather_pd( __m256d src, const double *base_addr, __m128i vindex, __m256d mask )
		{
			return _mm256_mask_i32gather_pd( src, base_addr, vindex, mask, scale );
		}

		// Gather single-precision floating-point elements from memory using 32-bit indices
		template<int scale>
		inline __m256 XM_CALLCONV mask_i32gather_ps( __m256 src, const float *base_addr, __m256i vindex, __m256 mask )
		{
			return _mm256_mask_i32gather_ps( src, base_addr, vindex, mask, scale );
		}

		// Gather 32-bit integers from memory using 64-bit indices. 32-bit elements are loaded from addresses starting at "base_addr" and offset by each 64-bit element in "vindex" (each index is scaled by the factor in "scale"). Gathered elements are merged into "dst" using "mask" (elements are copied from "src" when the highest bit is not set in the corresponding element). "scale" should be 1, 2, 4 or 8.
		template<int scale>
		inline __m128i XM_CALLCONV mask_i64gather_epi32( __m128i src, const int *base_addr, __m256i vindex, __m128i mask )
		{
			return _mm256_mask_i64gather_epi32( src, base_addr, vindex, mask, scale );
		}

		// Gather 64-bit integers from memory using 64-bit indices. 64-bit elements are loaded from addresses starting at "base_addr" and offset by each 64-bit element in "vindex" (each index is scaled by the factor in "scale"). Gathered elements are merged into "dst" using "mask" (elements are copied from "src" when the highest bit is not set in the corresponding element). "scale" should be 1, 2, 4 or 8.
		template<int scale>
		inline __m256i XM_CALLCONV mask_i64gather_epi64( __m256i src, const int64_t *base_addr, __m256i vindex, __m256i mask )
		{
			return _mm256_mask_i64gather_epi64( src, (const real_int64_t *)base_addr, vindex, mask, scale );
		}

		// Gather double-precision floating-point elements from memory using 64-bit indices
		template<int scale>
		inline __m256d XM_CALLCONV mask_i64gather_pd( __m256d src, const double *base_addr, __m256i vindex, __m256d mask )
		{
			return _mm256_mask_i64gather_pd( src, base_addr, vindex, mask, scale );
		}

		// Gather single-precision floating-point elements from memory using 64-bit indices
		template<int scale>
		inline __m128 XM_CALLCONV mask_i64gather_ps( __m128 src, const float *base_addr, __m256i vindex, __m128 mask )
		{
			return _mm256_mask_i64gather_ps( src, base_addr, vindex, mask, scale );
		}

		// Load packed 32-bit integers from memory into "dst" using "mask" (elements are zeroed out when the highest bit is not set in the corresponding element)
		inline __m256i XM_CALLCONV maskload_epi32( const int *mem_addr, __m256i mask )
		{
			return _mm256_maskload_epi32( mem_addr, mask );
		}

		// Load packed 64-bit integers from memory into "dst" using "mask" (elements are zeroed out when the highest bit is not set in the corresponding element)
		inline __m256i XM_CALLCONV maskload_epi64( const int64_t *mem_addr, __m256i mask )
		{
			return _mm256_maskload_epi64( (const real_int64_t *)mem_addr, mask );
		}

		// Store packed 32-bit integers from "a" into memory using "mask" (elements are not stored when the highest bit is not set in the corresponding element)
		inline void XM_CALLCONV maskstore_epi32( int *mem_addr, __m256i mask, __m256i a )
		{
			_mm256_maskstore_epi32( mem_addr, mask, a );
		}

		// Store packed 64-bit integers from "a" into memory using "mask" (elements are not stored when the highest bit is not set in the corresponding element)
		inline void XM_CALLCONV maskstore_epi64( int64_t *mem_addr, __m256i mask, __m256i a )
		{
			_mm256_maskstore_epi64( (real_int64_t *)mem_addr, mask, a );
		}

		// Compare packed 8-bit integers in "a" and "b", and store packed maximum values in "dst"
		inline __m256i XM_CALLCONV max_epi8( __m256i a, __m256i b )
		{
			return _mm256_max_epi8( a, b );
		}

		// Compare packed 16-bit integers in "a" and "b", and store packed maximum values in "dst"
		inline __m256i XM_CALLCONV max_epi16( __m256i a, __m256i b )
		{
			return _mm256_max_epi16( a, b );
		}

		// Compare packed 32-bit integers in "a" and "b", and store packed maximum values in "dst"
		inline __m256i XM_CALLCONV max_epi32( __m256i a, __m256i b )
		{
			return _mm256_max_epi32( a, b );
		}

		// Compare packed unsigned 8-bit integers in "a" and "b", and store packed maximum values in "dst"
		inline __m256i XM_CALLCONV max_epu8( __m256i a, __m256i b )
		{
			return _mm256_max_epu8( a, b );
		}

		// Compare packed unsigned 16-bit integers in "a" and "b", and store packed maximum values in "dst"
		inline __m256i XM_CALLCONV max_epu16( __m256i a, __m256i b )
		{
			return _mm256_max_epu16( a, b );
		}

		// Compare packed unsigned 32-bit integers in "a" and "b", and store packed maximum values in "dst"
		inline __m256i XM_CALLCONV max_epu32( __m256i a, __m256i b )
		{
			return _mm256_max_epu32( a, b );
		}

		// Compare packed 8-bit integers in "a" and "b", and store packed minimum values in "dst"
		inline __m256i XM_CALLCONV min_epi8( __m256i a, __m256i b )
		{
			return _mm256_min_epi8( a, b );
		}

		// Compare packed 16-bit integers in "a" and "b", and store packed minimum values in "dst"
		inline __m256i XM_CALLCONV min_epi16( __m256i a, __m256i b )
		{
			return _mm256_min_epi16( a, b );
		}

		// Compare packed 32-bit integers in "a" and "b", and store packed minimum values in "dst"
		inline __m256i XM_CALLCONV min_epi32( __m256i a, __m256i b )
		{
			return _mm256_min_epi32( a, b );
		}

		// Compare packed unsigned 8-bit integers in "a" and "b", and store packed minimum values in "dst"
		inline __m256i XM_CALLCONV min_epu8( __m256i a, __m256i b )
		{
			return _mm256_min_epu8( a, b );
		}

		// Compare packed unsigned 16-bit integers in "a" and "b", and store packed minimum values in "dst"
		inline __m256i XM_CALLCONV min_epu16( __m256i a, __m256i b )
		{
			return _mm256_min_epu16( a, b );
		}

		// Compare packed unsigned 32-bit integers in "a" and "b", and store packed minimum values in "dst"
		inline __m256i XM_CALLCONV min_epu32( __m256i a, __m256i b )
		{
			return _mm256_min_epu32( a, b );
		}

		// Create mask from the most significant bit of each 8-bit element in "a"
		inline int XM_CALLCONV movemask_epi8( __m256i a )
		{
			return _mm256_movemask_epi8( a );
		}

		// Compute the sum of absolute differences (SADs) of quadruplets of unsigned 8-bit integers in "a" compared to those in "b", and store the 16-bit results in "dst"
		template<int imm8>
		inline __m256i XM_CALLCONV mpsadbw_epu8( __m256i a, __m256i b )
		{
			return _mm256_mpsadbw_epu8( a, b, imm8 );
		}

		// Multiply the low 32-bit integers from each packed 64-bit element in "a" and "b", and store the signed 64-bit results in "dst"
		inline __m256i XM_CALLCONV mul_epi32( __m256i a, __m256i b )
		{
			return _mm256_mul_epi32( a, b );
		}

		// Multiply the low unsigned 32-bit integers from each packed 64-bit element in "a" and "b", and store the unsigned 64-bit results in "dst"
		inline __m256i XM_CALLCONV mul_epu32( __m256i a, __m256i b )
		{
			return _mm256_mul_epu32( a, b );
		}

		// Multiply the packed 16-bit integers in "a" and "b", producing intermediate 32-bit integers, and store the high 16 bits of the intermediate integers in "dst"
		inline __m256i XM_CALLCONV mulhi_epi16( __m256i a, __m256i b )
		{
			return _mm256_mulhi_epi16( a, b );
		}

		// Multiply the packed unsigned 16-bit integers in "a" and "b", producing intermediate 32-bit integers, and store the high 16 bits of the intermediate integers in "dst"
		inline __m256i XM_CALLCONV mulhi_epu16( __m256i a, __m256i b )
		{
			return _mm256_mulhi_epu16( a, b );
		}

		// Multiply packed 16-bit integers in "a" and "b", producing intermediate signed 32-bit integers
		inline __m256i XM_CALLCONV mulhrs_epi16( __m256i a, __m256i b )
		{
			return _mm256_mulhrs_epi16( a, b );
		}

		// Multiply the packed 16-bit integers in "a" and "b", producing intermediate 32-bit integers, and store the low 16 bits of the intermediate integers in "dst"
		inline __m256i XM_CALLCONV mullo_epi16( __m256i a, __m256i b )
		{
			return _mm256_mullo_epi16( a, b );
		}

		// Multiply the packed 32-bit integers in "a" and "b", producing intermediate 64-bit integers, and store the low 32 bits of the intermediate integers in "dst"
		inline __m256i XM_CALLCONV mullo_epi32( __m256i a, __m256i b )
		{
			return _mm256_mullo_epi32( a, b );
		}

		// Compute the bitwise OR of 256 bits (representing integer data) in "a" and "b"
		inline __m256i XM_CALLCONV or_all( __m256i a, __m256i b )
		{
			return _mm256_or_si256( a, b );
		}

		// Convert packed 16-bit integers from "a" and "b" to packed 8-bit integers using signed saturation
		inline __m256i XM_CALLCONV packs_epi16( __m256i a, __m256i b )
		{
			return _mm256_packs_epi16( a, b );
		}

		// Convert packed 32-bit integers from "a" and "b" to packed 16-bit integers using signed saturation
		inline __m256i XM_CALLCONV packs_epi32( __m256i a, __m256i b )
		{
			return _mm256_packs_epi32( a, b );
		}

		// Convert packed 16-bit integers from "a" and "b" to packed 8-bit integers using unsigned saturation
		inline __m256i XM_CALLCONV packus_epi16( __m256i a, __m256i b )
		{
			return _mm256_packus_epi16( a, b );
		}

		// Convert packed 32-bit integers from "a" and "b" to packed 16-bit integers using unsigned saturation
		inline __m256i XM_CALLCONV packus_epi32( __m256i a, __m256i b )
		{
			return _mm256_packus_epi32( a, b );
		}

		// Shuffle 128-bits (composed of integer data) selected by "imm8" from "a" and "b"
		template<int imm8>
		inline __m256i XM_CALLCONV permute2x128_all( __m256i a, __m256i b )
		{
			return _mm256_permute2x128_si256( a, b, imm8 );
		}

		// Shuffle 64-bit integers in "a" across lanes using the control in "imm8"
		template<int imm8>
		inline __m256i XM_CALLCONV permute4x64_epi64( __m256i a )
		{
			return _mm256_permute4x64_epi64( a, imm8 );
		}

		// Shuffle double-precision floating-point elements in "a" across lanes using the control in "imm8"
		template<int imm8>
		inline __m256d XM_CALLCONV permute4x64_pd( __m256d a )
		{
			return _mm256_permute4x64_pd( a, imm8 );
		}

		// Shuffle 32-bit integers in "a" across lanes using the corresponding index in "idx"
		inline __m256i XM_CALLCONV permutevar8x32_epi32( __m256i a, __m256i idx )
		{
			return _mm256_permutevar8x32_epi32( a, idx );
		}

		// Shuffle single-precision floating-point elements in "a" across lanes using the corresponding index in "idx"
		inline __m256 XM_CALLCONV permutevar8x32_ps( __m256 a, __m256i idx )
		{
			return _mm256_permutevar8x32_ps( a, idx );
		}

		// Compute the absolute differences of packed unsigned 8-bit integers in "a" and "b", then horizontally sum each consecutive 8 differences to produce four unsigned 16-bit integers, and pack these unsigned 16-bit integers in the low 16 bits of 64-bit elements in "dst"
		inline __m256i XM_CALLCONV sad_epu8( __m256i a, __m256i b )
		{
			return _mm256_sad_epu8( a, b );
		}

		// Shuffle 8-bit integers in "a" within 128-bit lanes according to shuffle control mask in the corresponding 8-bit element of "b"
		inline __m256i XM_CALLCONV shuffle_epi8( __m256i a, __m256i b )
		{
			return _mm256_shuffle_epi8( a, b );
		}

		// Shuffle 32-bit integers in "a" within 128-bit lanes using the control in "imm8"
		template<int imm8>
		inline __m256i XM_CALLCONV shuffle_epi32( __m256i a )
		{
			return _mm256_shuffle_epi32( a, imm8 );
		}

		// Shuffle 16-bit integers in the high 64 bits of 128-bit lanes of "a" using the control in "imm8"
		template<int imm8>
		inline __m256i XM_CALLCONV shufflehi_epi16( __m256i a )
		{
			return _mm256_shufflehi_epi16( a, imm8 );
		}

		// Shuffle 16-bit integers in the low 64 bits of 128-bit lanes of "a" using the control in "imm8"
		template<int imm8>
		inline __m256i XM_CALLCONV shufflelo_epi16( __m256i a )
		{
			return _mm256_shufflelo_epi16( a, imm8 );
		}

		// Negate packed 8-bit integers in "a" when the corresponding signed 8-bit integer in "b" is negative
		inline __m256i XM_CALLCONV sign_epi8( __m256i a, __m256i b )
		{
			return _mm256_sign_epi8( a, b );
		}

		// Negate packed 16-bit integers in "a" when the corresponding signed 16-bit integer in "b" is negative
		inline __m256i XM_CALLCONV sign_epi16( __m256i a, __m256i b )
		{
			return _mm256_sign_epi16( a, b );
		}

		// Negate packed 32-bit integers in "a" when the corresponding signed 32-bit integer in "b" is negative
		inline __m256i XM_CALLCONV sign_epi32( __m256i a, __m256i b )
		{
			return _mm256_sign_epi32( a, b );
		}

		// Shift packed 16-bit integers in "a" left by "count" while shifting in zeros
		inline __m256i XM_CALLCONV sll_epi16( __m256i a, __m128i count )
		{
			return _mm256_sll_epi16( a, count );
		}

		// Shift packed 32-bit integers in "a" left by "count" while shifting in zeros
		inline __m256i XM_CALLCONV sll_epi32( __m256i a, __m128i count )
		{
			return _mm256_sll_epi32( a, count );
		}

		// Shift packed 64-bit integers in "a" left by "count" while shifting in zeros
		inline __m256i XM_CALLCONV sll_epi64( __m256i a, __m128i count )
		{
			return _mm256_sll_epi64( a, count );
		}

		// Shift packed 16-bit integers in "a" left by "imm8" while shifting in zeros
		template<int imm8>
		inline __m256i XM_CALLCONV slli_epi16( __m256i a )
		{
			return _mm256_slli_epi16( a, imm8 );
		}

		// Shift packed 32-bit integers in "a" left by "imm8" while shifting in zeros
		template<int imm8>
		inline __m256i XM_CALLCONV slli_epi32( __m256i a )
		{
			return _mm256_slli_epi32( a, imm8 );
		}

		// Shift packed 64-bit integers in "a" left by "imm8" while shifting in zeros
		template<int imm8>
		inline __m256i XM_CALLCONV slli_epi64( __m256i a )
		{
			return _mm256_slli_epi64( a, imm8 );
		}

		// Shift 128-bit lanes in "a" left by "imm8" bytes while shifting in zeros
		template<int imm8>
		inline __m256i XM_CALLCONV slli_all( __m256i a )
		{
			return _mm256_slli_si256( a, imm8 );
		}

		// Shift packed 32-bit integers in "a" left by the amount specified by the corresponding element in "count" while shifting in zeros
		inline __m256i XM_CALLCONV sllv_epi32( __m256i a, __m256i count )
		{
			return _mm256_sllv_epi32( a, count );
		}

		// Shift packed 64-bit integers in "a" left by the amount specified by the corresponding element in "count" while shifting in zeros
		inline __m256i XM_CALLCONV sllv_epi64( __m256i a, __m256i count )
		{
			return _mm256_sllv_epi64( a, count );
		}

		// Shift packed 16-bit integers in "a" right by "count" while shifting in sign bits
		inline __m256i XM_CALLCONV sra_epi16( __m256i a, __m128i count )
		{
			return _mm256_sra_epi16( a, count );
		}

		// Shift packed 32-bit integers in "a" right by "count" while shifting in sign bits
		inline __m256i XM_CALLCONV sra_epi32( __m256i a, __m128i count )
		{
			return _mm256_sra_epi32( a, count );
		}

		// Shift packed 16-bit integers in "a" right by "imm8" while shifting in sign bits
		template<int imm8>
		inline __m256i XM_CALLCONV srai_epi16( __m256i a )
		{
			return _mm256_srai_epi16( a, imm8 );
		}

		// Shift packed 32-bit integers in "a" right by "imm8" while shifting in sign bits
		template<int imm8>
		inline __m256i XM_CALLCONV srai_epi32( __m256i a )
		{
			return _mm256_srai_epi32( a, imm8 );
		}

		// Shift packed 32-bit integers in "a" right by the amount specified by the corresponding element in "count" while shifting in sign bits
		inline __m256i XM_CALLCONV srav_epi32( __m256i a, __m256i count )
		{
			return _mm256_srav_epi32( a, count );
		}

		// Shift packed 16-bit integers in "a" right by "count" while shifting in zeros
		inline __m256i XM_CALLCONV srl_epi16( __m256i a, __m128i count )
		{
			return _mm256_srl_epi16( a, count );
		}

		// Shift packed 32-bit integers in "a" right by "count" while shifting in zeros
		inline __m256i XM_CALLCONV srl_epi32( __m256i a, __m128i count )
		{
			return _mm256_srl_epi32( a, count );
		}

		// Shift packed 64-bit integers in "a" right by "count" while shifting in zeros
		inline __m256i XM_CALLCONV srl_epi64( __m256i a, __m128i count )
		{
			return _mm256_srl_epi64( a, count );
		}

		// Shift packed 16-bit integers in "a" right by "imm8" while shifting in zeros
		template<int imm8>
		inline __m256i XM_CALLCONV srli_epi16( __m256i a )
		{
			return _mm256_srli_epi16( a, imm8 );
		}

		// Shift packed 32-bit integers in "a" right by "imm8" while shifting in zeros
		template<int imm8>
		inline __m256i XM_CALLCONV srli_epi32( __m256i a )
		{
			return _mm256_srli_epi32( a, imm8 );
		}

		// Shift packed 64-bit integers in "a" right by "imm8" while shifting in zeros
		template<int imm8>
		inline __m256i XM_CALLCONV srli_epi64( __m256i a )
		{
			return _mm256_srli_epi64( a, imm8 );
		}

		// Shift 128-bit lanes in "a" right by "imm8" bytes while shifting in zeros
		template<int imm8>
		inline __m256i XM_CALLCONV srli_all( __m256i a )
		{
			return _mm256_srli_si256( a, imm8 );
		}

		// Shift packed 32-bit integers in "a" right by the amount specified by the corresponding element in "count" while shifting in zeros
		inline __m256i XM_CALLCONV srlv_epi32( __m256i a, __m256i count )
		{
			return _mm256_srlv_epi32( a, count );
		}

		// Shift packed 64-bit integers in "a" right by the amount specified by the corresponding element in "count" while shifting in zeros
		inline __m256i XM_CALLCONV srlv_epi64( __m256i a, __m256i count )
		{
			return _mm256_srlv_epi64( a, count );
		}

		// Load 256-bits of integer data from memory into "dst" using a non-temporal memory hint
		inline __m256i XM_CALLCONV stream_load_all( const __m256i *mem_addr )
		{
			return _mm256_stream_load_si256( mem_addr );
		}

		// Subtract packed 8-bit integers in "b" from packed 8-bit integers in "a"
		inline __m256i XM_CALLCONV sub_epi8( __m256i a, __m256i b )
		{
			return _mm256_sub_epi8( a, b );
		}

		// Subtract packed 16-bit integers in "b" from packed 16-bit integers in "a"
		inline __m256i XM_CALLCONV sub_epi16( __m256i a, __m256i b )
		{
			return _mm256_sub_epi16( a, b );
		}

		// Subtract packed 32-bit integers in "b" from packed 32-bit integers in "a"
		inline __m256i XM_CALLCONV sub_epi32( __m256i a, __m256i b )
		{
			return _mm256_sub_epi32( a, b );
		}

		// Subtract packed 64-bit integers in "b" from packed 64-bit integers in "a"
		inline __m256i XM_CALLCONV sub_epi64( __m256i a, __m256i b )
		{
			return _mm256_sub_epi64( a, b );
		}

		// Subtract packed 8-bit integers in "b" from packed 8-bit integers in "a" using saturation
		inline __m256i XM_CALLCONV subs_epi8( __m256i a, __m256i b )
		{
			return _mm256_subs_epi8( a, b );
		}

		// Subtract packed 16-bit integers in "b" from packed 16-bit integers in "a" using saturation
		inline __m256i XM_CALLCONV subs_epi16( __m256i a, __m256i b )
		{
			return _mm256_subs_epi16( a, b );
		}

		// Subtract packed unsigned 8-bit integers in "b" from packed unsigned 8-bit integers in "a" using saturation
		inline __m256i XM_CALLCONV subs_epu8( __m256i a, __m256i b )
		{
			return _mm256_subs_epu8( a, b );
		}

		// Subtract packed unsigned 16-bit integers in "b" from packed unsigned 16-bit integers in "a" using saturation
		inline __m256i XM_CALLCONV subs_epu16( __m256i a, __m256i b )
		{
			return _mm256_subs_epu16( a, b );
		}

		// Unpack and interleave 8-bit integers from the high half of each 128-bit lane in "a" and "b"
		inline __m256i XM_CALLCONV unpackhi_epi8( __m256i a, __m256i b )
		{
			return _mm256_unpackhi_epi8( a, b );
		}

		// Unpack and interleave 16-bit integers from the high half of each 128-bit lane in "a" and "b"
		inline __m256i XM_CALLCONV unpackhi_epi16( __m256i a, __m256i b )
		{
			return _mm256_unpackhi_epi16( a, b );
		}

		// Unpack and interleave 32-bit integers from the high half of each 128-bit lane in "a" and "b"
		inline __m256i XM_CALLCONV unpackhi_epi32( __m256i a, __m256i b )
		{
			return _mm256_unpackhi_epi32( a, b );
		}

		// Unpack and interleave 64-bit integers from the high half of each 128-bit lane in "a" and "b"
		inline __m256i XM_CALLCONV unpackhi_epi64( __m256i a, __m256i b )
		{
			return _mm256_unpackhi_epi64( a, b );
		}

		// Unpack and interleave 8-bit integers from the low half of each 128-bit lane in "a" and "b"
		inline __m256i XM_CALLCONV unpacklo_epi8( __m256i a, __m256i b )
		{
			return _mm256_unpacklo_epi8( a, b );
		}

		// Unpack and interleave 16-bit integers from the low half of each 128-bit lane in "a" and "b"
		inline __m256i XM_CALLCONV unpacklo_epi16( __m256i a, __m256i b )
		{
			return _mm256_unpacklo_epi16( a, b );
		}

		// Unpack and interleave 32-bit integers from the low half of each 128-bit lane in "a" and "b"
		inline __m256i XM_CALLCONV unpacklo_epi32( __m256i a, __m256i b )
		{
			return _mm256_unpacklo_epi32( a, b );
		}

		// Unpack and interleave 64-bit integers from the low half of each 128-bit lane in "a" and "b"
		inline __m256i XM_CALLCONV unpacklo_epi64( __m256i a, __m256i b )
		{
			return _mm256_unpacklo_epi64( a, b );
		}

		// Compute the bitwise XOR of 256 bits (representing integer data) in "a" and "b"
		inline __m256i XM_CALLCONV xor_all( __m256i a, __m256i b )
		{
			return _mm256_xor_si256( a, b );
		}
	}	// namespace Intrinsics::Avx

	namespace Sse
	{
		// Blend packed 32-bit integers from "a" and "b" using control mask "imm8"
		template<int imm8>
		inline __m128i XM_CALLCONV blend_epi32( __m128i a, __m128i b )
		{
			return _mm_blend_epi32( a, b, imm8 );
		}

		// Broadcast the low packed 8-bit integer from "a" to all elements of "dst"
		inline __m128i XM_CALLCONV broadcast_epi8( __m128i a )
		{
			return _mm_broadcastb_epi8( a );
		}

		// Broadcast the low packed 32-bit integer from "a" to all elements of "dst"
		inline __m128i XM_CALLCONV broadcast_epi32( __m128i a )
		{
			return _mm_broadcastd_epi32( a );
		}

		// Broadcast the low packed 64-bit integer from "a" to all elements of "dst"
		inline __m128i XM_CALLCONV broadcast_epi64( __m128i a )
		{
			return _mm_broadcastq_epi64( a );
		}

		// Broadcast the low single-precision floating-point element from "a" to all elements of "dst"
		inline __m128 XM_CALLCONV broadcast_ps( __m128 a )
		{
			return _mm_broadcastss_ps( a );
		}

		// Broadcast the low packed 16-bit integer from "a" to all elements of "dst"
		inline __m128i XM_CALLCONV broadcast_epi16( __m128i a )
		{
			return _mm_broadcastw_epi16( a );
		}

		// Gather 32-bit integers from memory using 32-bit indices. 32-bit elements are loaded from addresses starting at "base_addr" and offset by each 32-bit element in "vindex" (each index is scaled by the factor in "scale"). Gathered elements are merged into "dst". "scale" should be 1, 2, 4 or 8.
		template<int scale>
		inline __m128i XM_CALLCONV i32gather_epi32( const int *base_addr, __m128i vindex )
		{
			return _mm_i32gather_epi32( base_addr, vindex, scale );
		}

		// Gather 64-bit integers from memory using 32-bit indices. 64-bit elements are loaded from addresses starting at "base_addr" and offset by each 32-bit element in "vindex" (each index is scaled by the factor in "scale"). Gathered elements are merged into "dst". "scale" should be 1, 2, 4 or 8.
		template<int scale>
		inline __m128i XM_CALLCONV i32gather_epi64( const int64_t *base_addr, __m128i vindex )
		{
			return _mm_i32gather_epi64( (const real_int64_t *)base_addr, vindex, scale );
		}

		// Gather double-precision floating-point elements from memory using 32-bit indices
		template<int scale>
		inline __m128d XM_CALLCONV i32gather_pd( const double *base_addr, __m128i vindex )
		{
			return _mm_i32gather_pd( base_addr, vindex, scale );
		}

		// Gather single-precision floating-point elements from memory using 32-bit indices
		template<int scale>
		inline __m128 XM_CALLCONV i32gather_ps( const float *base_addr, __m128i vindex )
		{
			return _mm_i32gather_ps( base_addr, vindex, scale );
		}

		// Gather 32-bit integers from memory using 64-bit indices. 32-bit elements are loaded from addresses starting at "base_addr" and offset by each 64-bit element in "vindex" (each index is scaled by the factor in "scale"). Gathered elements are merged into "dst". "scale" should be 1, 2, 4 or 8.
		template<int scale>
		inline __m128i XM_CALLCONV i64gather_epi32( const int *base_addr, __m128i vindex )
		{
			return _mm_i64gather_epi32( base_addr, vindex, scale );
		}

		// Gather 64-bit integers from memory using 64-bit indices. 64-bit elements are loaded from addresses starting at "base_addr" and offset by each 64-bit element in "vindex" (each index is scaled by the factor in "scale"). Gathered elements are merged into "dst". "scale" should be 1, 2, 4 or 8.
		template<int scale>
		inline __m128i XM_CALLCONV i64gather_epi64( const int64_t *base_addr, __m128i vindex )
		{
			return _mm_i64gather_epi64( (const real_int64_t *)base_addr, vindex, scale );
		}

		// Gather double-precision floating-point elements from memory using 64-bit indices
		template<int scale>
		inline __m128d XM_CALLCONV i64gather_pd( const double *base_addr, __m128i vindex )
		{
			return _mm_i64gather_pd( base_addr, vindex, scale );
		}

		// Gather single-precision floating-point elements from memory using 64-bit indices
		template<int scale>
		inline __m128 XM_CALLCONV i64gather_ps( const float *base_addr, __m128i vindex )
		{
			return _mm_i64gather_ps( base_addr, vindex, scale );
		}

		// Gather 32-bit integers from memory using 32-bit indices. 32-bit elements are loaded from addresses starting at "base_addr" and offset by each 32-bit element in "vindex" (each index is scaled by the factor in "scale"). Gathered elements are merged into "dst" using "mask" (elements are copied from "src" when the highest bit is not set in the corresponding element). "scale" should be 1, 2, 4 or 8.
		template<int scale>
		inline __m128i XM_CALLCONV mask_i32gather_epi32( __m128i src, const int *base_addr, __m128i vindex, __m128i mask )
		{
			return _mm_mask_i32gather_epi32( src, base_addr, vindex, mask, scale );
		}

		// Gather 64-bit integers from memory using 32-bit indices. 64-bit elements are loaded from addresses starting at "base_addr" and offset by each 32-bit element in "vindex" (each index is scaled by the factor in "scale"). Gathered elements are merged into "dst" using "mask" (elements are copied from "src" when the highest bit is not set in the corresponding element). "scale" should be 1, 2, 4 or 8.
		template<int scale>
		inline __m128i XM_CALLCONV mask_i32gather_epi64( __m128i src, const int64_t *base_addr, __m128i vindex, __m128i mask )
		{
			return _mm_mask_i32gather_epi64( src, (const real_int64_t *)base_addr, vindex, mask, scale );
		}

		// Gather double-precision floating-point elements from memory using 32-bit indices
		template<int scale>
		inline __m128d XM_CALLCONV mask_i32gather_pd( __m128d src, const double *base_addr, __m128i vindex, __m128d mask )
		{
			return _mm_mask_i32gather_pd( src, base_addr, vindex, mask, scale );
		}

		// Gather single-precision floating-point elements from memory using 32-bit indices
		template<int scale>
		inline __m128 XM_CALLCONV mask_i32gather_ps( __m128 src, const float *base_addr, __m128i vindex, __m128 mask )
		{
			return _mm_mask_i32gather_ps( src, base_addr, vindex, mask, scale );
		}

		// Gather 32-bit integers from memory using 64-bit indices. 32-bit elements are loaded from addresses starting at "base_addr" and offset by each 64-bit element in "vindex" (each index is scaled by the factor in "scale"). Gathered elements are merged into "dst" using "mask" (elements are copied from "src" when the highest bit is not set in the corresponding element). "scale" should be 1, 2, 4 or 8.
		template<int scale>
		inline __m128i XM_CALLCONV mask_i64gather_epi32( __m128i src, const int *base_addr, __m128i vindex, __m128i mask )
		{
			return _mm_mask_i64gather_epi32( src, base_addr, vindex, mask, scale );
		}

		// Gather 64-bit integers from memory using 64-bit indices. 64-bit elements are loaded from addresses starting at "base_addr" and offset by each 64-bit element in "vindex" (each index is scaled by the factor in "scale"). Gathered elements are merged into "dst" using "mask" (elements are copied from "src" when the highest bit is not set in the corresponding element). "scale" should be 1, 2, 4 or 8.
		template<int scale>
		inline __m128i XM_CALLCONV mask_i64gather_epi64( __m128i src, const int64_t *base_addr, __m128i vindex, __m128i mask )
		{
			return _mm_mask_i64gather_epi64( src, (const real_int64_t *)base_addr, vindex, mask, scale );
		}

		// Gather double-precision floating-point elements from memory using 64-bit indices
		template<int scale>
		inline __m128d XM_CALLCONV mask_i64gather_pd( __m128d src, const double *base_addr, __m128i vindex, __m128d mask )
		{
			return _mm_mask_i64gather_pd( src, base_addr, vindex, mask, scale );
		}

		// Gather single-precision floating-point elements from memory using 64-bit indices
		template<int scale>
		inline __m128 XM_CALLCONV mask_i64gather_ps( __m128 src, const float *base_addr, __m128i vindex, __m128 mask )
		{
			return _mm_mask_i64gather_ps( src, base_addr, vindex, mask, scale );
		}

		// Load packed 32-bit integers from memory into "dst" using "mask" (elements are zeroed out when the highest bit is not set in the corresponding element)
		inline __m128i XM_CALLCONV maskload_epi32( const int *mem_addr, __m128i mask )
		{
			return _mm_maskload_epi32( mem_addr, mask );
		}

		// Load packed 64-bit integers from memory into "dst" using "mask" (elements are zeroed out when the highest bit is not set in the corresponding element)
		inline __m128i XM_CALLCONV maskload_epi64( const int64_t *mem_addr, __m128i mask )
		{
			return _mm_maskload_epi64( (const real_int64_t *)mem_addr, mask );
		}

		// Store packed 32-bit integers from "a" into memory using "mask" (elements are not stored when the highest bit is not set in the corresponding element)
		inline void XM_CALLCONV maskstore_epi32( int *mem_addr, __m128i mask, __m128i a )
		{
			_mm_maskstore_epi32( mem_addr, mask, a );
		}

		// Store packed 64-bit integers from "a" into memory using "mask" (elements are not stored when the highest bit is not set in the corresponding element)
		inline void XM_CALLCONV maskstore_epi64( int64_t *mem_addr, __m128i mask, __m128i a )
		{
			_mm_maskstore_epi64( (real_int64_t *)mem_addr, mask, a );
		}

		// Shift packed 32-bit integers in "a" left by the amount specified by the corresponding element in "count" while shifting in zeros
		inline __m128i XM_CALLCONV sllv_epi32( __m128i a, __m128i count )
		{
			return _mm_sllv_epi32( a, count );
		}

		// Shift packed 64-bit integers in "a" left by the amount specified by the corresponding element in "count" while shifting in zeros
		inline __m128i XM_CALLCONV sllv_epi64( __m128i a, __m128i count )
		{
			return _mm_sllv_epi64( a, count );
		}

		// Shift packed 32-bit integers in "a" right by the amount specified by the corresponding element in "count" while shifting in sign bits
		inline __m128i XM_CALLCONV srav_epi32( __m128i a, __m128i count )
		{
			return _mm_srav_epi32( a, count );
		}

		// Shift packed 32-bit integers in "a" right by the amount specified by the corresponding element in "count" while shifting in zeros
		inline __m128i XM_CALLCONV srlv_epi32( __m128i a, __m128i count )
		{
			return _mm_srlv_epi32( a, count );
		}

		// Shift packed 64-bit integers in "a" right by the amount specified by the corresponding element in "count" while shifting in zeros
		inline __m128i XM_CALLCONV srlv_epi64( __m128i a, __m128i count )
		{
			return _mm_srlv_epi64( a, count );
		}

#ifndef __GNUC__
		// Broadcast the low double-precision floating-point element from "a" to all elements of "dst"
		inline __m128d XM_CALLCONV broadcast_pd( __m128d a )
		{
			return _mm_broadcastsd_pd( a );
		}
#endif // !__GNUC__
	}	// namespace Intrinsics::Sse
}	// namespace Intrinsics
#include "Extra/avx2-extra.hpp"