// This file is generated automatically by a tool. If you want to change it, fork & modify the tool instead: https://github.com/Const-me/IntelIntrinsics
#pragma once
#include <immintrin.h>
#include "Extra/common.hpp"

namespace Intrinsics
{
	namespace Avx
	{
		// Add packed double-precision floating-point elements in "a" and "b"
		inline __m256d XM_CALLCONV add_pd( __m256d a, __m256d b )
		{
			return _mm256_add_pd( a, b );
		}

		// Add packed single-precision floating-point elements in "a" and "b"
		inline __m256 XM_CALLCONV add_ps( __m256 a, __m256 b )
		{
			return _mm256_add_ps( a, b );
		}

		// Alternatively add and subtract packed double-precision floating-point elements in "a" to/from packed elements in "b"
		inline __m256d XM_CALLCONV addsub_pd( __m256d a, __m256d b )
		{
			return _mm256_addsub_pd( a, b );
		}

		// Alternatively add and subtract packed single-precision floating-point elements in "a" to/from packed elements in "b"
		inline __m256 XM_CALLCONV addsub_ps( __m256 a, __m256 b )
		{
			return _mm256_addsub_ps( a, b );
		}

		// Compute the bitwise AND of packed double-precision floating-point elements in "a" and "b"
		inline __m256d XM_CALLCONV and_pd( __m256d a, __m256d b )
		{
			return _mm256_and_pd( a, b );
		}

		// Compute the bitwise AND of packed single-precision floating-point elements in "a" and "b"
		inline __m256 XM_CALLCONV and_ps( __m256 a, __m256 b )
		{
			return _mm256_and_ps( a, b );
		}

		// Compute the bitwise NOT of packed double-precision floating-point elements in "a" and then AND with "b"
		inline __m256d XM_CALLCONV andnot_pd( __m256d a, __m256d b )
		{
			return _mm256_andnot_pd( a, b );
		}

		// Compute the bitwise NOT of packed single-precision floating-point elements in "a" and then AND with "b"
		inline __m256 XM_CALLCONV andnot_ps( __m256 a, __m256 b )
		{
			return _mm256_andnot_ps( a, b );
		}

		// Blend packed double-precision floating-point elements from "a" and "b" using control mask "imm8"
		template<int imm8>
		inline __m256d XM_CALLCONV blend_pd( __m256d a, __m256d b )
		{
			return _mm256_blend_pd( a, b, imm8 );
		}

		// Blend packed single-precision floating-point elements from "a" and "b" using control mask "imm8"
		template<int imm8>
		inline __m256 XM_CALLCONV blend_ps( __m256 a, __m256 b )
		{
			return _mm256_blend_ps( a, b, imm8 );
		}

		// Blend packed double-precision floating-point elements from "a" and "b" using "mask"
		inline __m256d XM_CALLCONV blendv_pd( __m256d a, __m256d b, __m256d mask )
		{
			return _mm256_blendv_pd( a, b, mask );
		}

		// Blend packed single-precision floating-point elements from "a" and "b" using "mask"
		inline __m256 XM_CALLCONV blendv_ps( __m256 a, __m256 b, __m256 mask )
		{
			return _mm256_blendv_ps( a, b, mask );
		}

		// Broadcast 128 bits from memory (composed of 2 packed double-precision floating-point elements) to all elements of "dst"
		inline __m256d XM_CALLCONV broadcast_pd( const __m128d *mem_addr )
		{
			return _mm256_broadcast_pd( mem_addr );
		}

		// Broadcast 128 bits from memory (composed of 4 packed single-precision floating-point elements) to all elements of "dst"
		inline __m256 XM_CALLCONV broadcast_ps( const __m128 *mem_addr )
		{
			return _mm256_broadcast_ps( mem_addr );
		}

		// Broadcast a double-precision floating-point element from memory to all elements of "dst"
		inline __m256d XM_CALLCONV broadcast_sd( const double *mem_addr )
		{
			return _mm256_broadcast_sd( mem_addr );
		}

		// Broadcast a single-precision floating-point element from memory to all elements of "dst"
		inline __m256 XM_CALLCONV broadcast_ss( const float *mem_addr )
		{
			return _mm256_broadcast_ss( mem_addr );
		}

		// Cast vector of type __m256d to type __m256.	This intrinsic is only used for compilation and does not generate any instructions, thus it has zero latency.
		inline __m256 XM_CALLCONV castpd_ps( __m256d a )
		{
			return _mm256_castpd_ps( a );
		}

		// Casts vector of type __m256d to type __m256i. This intrinsic is only used for compilation and does not generate any instructions, thus it has zero latency.
		inline __m256i XM_CALLCONV castpd_all( __m256d a )
		{
			return _mm256_castpd_si256( a );
		}

		// Casts vector of type __m128d to type __m256d; the upper 128 bits of the result are undefined
		inline __m256d XM_CALLCONV castpd128_pd256( __m128d a )
		{
			return _mm256_castpd128_pd256( a );
		}

		// Casts vector of type __m256d to type __m128d. This intrinsic is only used for compilation and does not generate any instructions, thus it has zero latency.
		inline __m128d XM_CALLCONV castpd256_pd128( __m256d a )
		{
			return _mm256_castpd256_pd128( a );
		}

		// Cast vector of type __m256 to type __m256d.	This intrinsic is only used for compilation and does not generate any instructions, thus it has zero latency.
		inline __m256d XM_CALLCONV castps_pd( __m256 a )
		{
			return _mm256_castps_pd( a );
		}

		// Casts vector of type __m256 to type __m256i. This intrinsic is only used for compilation and does not generate any instructions, thus it has zero latency.
		inline __m256i XM_CALLCONV castps_all( __m256 a )
		{
			return _mm256_castps_si256( a );
		}

		// Casts vector of type __m128 to type __m256; the upper 128 bits of the result are undefined
		inline __m256 XM_CALLCONV castps128_ps256( __m128 a )
		{
			return _mm256_castps128_ps256( a );
		}

		// Casts vector of type __m256 to type __m128. This intrinsic is only used for compilation and does not generate any instructions, thus it has zero latency.
		inline __m128 XM_CALLCONV castps256_ps128( __m256 a )
		{
			return _mm256_castps256_ps128( a );
		}

		// Casts vector of type __m128i to type __m256i; the upper 128 bits of the result are undefined
		inline __m256i XM_CALLCONV castsi128_all( __m128i a )
		{
			return _mm256_castsi128_si256( a );
		}

		// Casts vector of type __m256i to type __m256d. This intrinsic is only used for compilation and does not generate any instructions, thus it has zero latency.
		inline __m256d XM_CALLCONV castall_pd( __m256i a )
		{
			return _mm256_castsi256_pd( a );
		}

		// Casts vector of type __m256i to type __m256. This intrinsic is only used for compilation and does not generate any instructions, thus it has zero latency.
		inline __m256 XM_CALLCONV castall_ps( __m256i a )
		{
			return _mm256_castsi256_ps( a );
		}

		// Casts vector of type __m256i to type __m128i. This intrinsic is only used for compilation and does not generate any instructions, thus it has zero latency.
		inline __m128i XM_CALLCONV castall_si128( __m256i a )
		{
			return _mm256_castsi256_si128( a );
		}

		// Round the packed double-precision floating-point elements in "a" up to an integer value
		inline __m256d XM_CALLCONV ceil_pd( __m256d a )
		{
			return _mm256_ceil_pd( a );
		}

		// Round the packed single-precision floating-point elements in "a" up to an integer value
		inline __m256 XM_CALLCONV ceil_ps( __m256 a )
		{
			return _mm256_ceil_ps( a );
		}

		// Compare packed double-precision floating-point elements in "a" and "b"
		template<int imm8>
		inline __m256d XM_CALLCONV cmp_pd( __m256d a, __m256d b )
		{
			return _mm256_cmp_pd( a, b, imm8 );
		}

		// Compare packed single-precision floating-point elements in "a" and "b"
		template<int imm8>
		inline __m256 XM_CALLCONV cmp_ps( __m256 a, __m256 b )
		{
			return _mm256_cmp_ps( a, b, imm8 );
		}

		// Convert packed 32-bit integers in "a" to packed double-precision floating-point elements
		inline __m256d XM_CALLCONV cvtepi32_pd( __m128i a )
		{
			return _mm256_cvtepi32_pd( a );
		}

		// Convert packed 32-bit integers in "a" to packed single-precision floating-point elements
		inline __m256 XM_CALLCONV cvtepi32_ps( __m256i a )
		{
			return _mm256_cvtepi32_ps( a );
		}

		// Convert packed double-precision floating-point elements in "a" to packed 32-bit integers
		inline __m128i XM_CALLCONV cvtpd_epi32( __m256d a )
		{
			return _mm256_cvtpd_epi32( a );
		}

		// Convert packed double-precision floating-point elements in "a" to packed single-precision floating-point elements
		inline __m128 XM_CALLCONV cvtpd_ps( __m256d a )
		{
			return _mm256_cvtpd_ps( a );
		}

		// Convert packed single-precision floating-point elements in "a" to packed 32-bit integers
		inline __m256i XM_CALLCONV cvtps_epi32( __m256 a )
		{
			return _mm256_cvtps_epi32( a );
		}

		// Convert packed single-precision floating-point elements in "a" to packed double-precision floating-point elements
		inline __m256d XM_CALLCONV cvtps_pd( __m128 a )
		{
			return _mm256_cvtps_pd( a );
		}

		// Convert packed double-precision floating-point elements in "a" to packed 32-bit integers with truncation
		inline __m128i XM_CALLCONV cvttpd_epi32( __m256d a )
		{
			return _mm256_cvttpd_epi32( a );
		}

		// Convert packed single-precision floating-point elements in "a" to packed 32-bit integers with truncation
		inline __m256i XM_CALLCONV cvttps_epi32( __m256 a )
		{
			return _mm256_cvttps_epi32( a );
		}

		// Divide packed double-precision floating-point elements in "a" by packed elements in "b"
		inline __m256d XM_CALLCONV div_pd( __m256d a, __m256d b )
		{
			return _mm256_div_pd( a, b );
		}

		// Divide packed single-precision floating-point elements in "a" by packed elements in "b"
		inline __m256 XM_CALLCONV div_ps( __m256 a, __m256 b )
		{
			return _mm256_div_ps( a, b );
		}

		// Conditionally multiply the packed single-precision floating-point elements in "a" and "b" using the high 4 bits in "imm8", sum the four products, and conditionally store the sum in "dst" using the low 4 bits of "imm8"
		template<int imm8>
		inline __m256 XM_CALLCONV dp_ps( __m256 a, __m256 b )
		{
			return _mm256_dp_ps( a, b, imm8 );
		}

		// Extract a 32-bit integer from "a", selected with "index", and store the result in "dst"
		template<int index>
		inline int32_t XM_CALLCONV extract_epi32( __m256i a )
		{
			return _mm256_extract_epi32( a, index );
		}

		// Extract a 64-bit integer from "a", selected with "index", and store the result in "dst"
		template<int index>
		inline int64_t XM_CALLCONV extract_epi64( __m256i a )
		{
			return (int64_t)_mm256_extract_epi64( a, index );
		}

		// Extract 128 bits (composed of 2 packed double-precision floating-point elements) from "a", selected with "imm8"
		template<int imm8>
		inline __m128d XM_CALLCONV extractf128_pd( __m256d a )
		{
			return _mm256_extractf128_pd( a, imm8 );
		}

		// Extract 128 bits (composed of 4 packed single-precision floating-point elements) from "a", selected with "imm8"
		template<int imm8>
		inline __m128 XM_CALLCONV extractf128_ps( __m256 a )
		{
			return _mm256_extractf128_ps( a, imm8 );
		}

		// Extract 128 bits (composed of integer data) from "a", selected with "imm8"
		template<int imm8>
		inline __m128i XM_CALLCONV extractf128_all( __m256i a )
		{
			return _mm256_extractf128_si256( a, imm8 );
		}

		// Round the packed double-precision floating-point elements in "a" down to an integer value
		inline __m256d XM_CALLCONV floor_pd( __m256d a )
		{
			return _mm256_floor_pd( a );
		}

		// Round the packed single-precision floating-point elements in "a" down to an integer value
		inline __m256 XM_CALLCONV floor_ps( __m256 a )
		{
			return _mm256_floor_ps( a );
		}

		// Horizontally add adjacent pairs of double-precision floating-point elements in "a" and "b", and pack the results in "dst"
		inline __m256d XM_CALLCONV hadd_pd( __m256d a, __m256d b )
		{
			return _mm256_hadd_pd( a, b );
		}

		// Horizontally add adjacent pairs of single-precision floating-point elements in "a" and "b", and pack the results in "dst"
		inline __m256 XM_CALLCONV hadd_ps( __m256 a, __m256 b )
		{
			return _mm256_hadd_ps( a, b );
		}

		// Horizontally subtract adjacent pairs of double-precision floating-point elements in "a" and "b", and pack the results in "dst"
		inline __m256d XM_CALLCONV hsub_pd( __m256d a, __m256d b )
		{
			return _mm256_hsub_pd( a, b );
		}

		// Horizontally add adjacent pairs of single-precision floating-point elements in "a" and "b", and pack the results in "dst"
		inline __m256 XM_CALLCONV hsub_ps( __m256 a, __m256 b )
		{
			return _mm256_hsub_ps( a, b );
		}

		// Copy "a" to "dst", and insert the 8-bit integer "i" into "dst" at the location specified by "index"
		template<int index>
		inline __m256i XM_CALLCONV insert_epi8( __m256i a, int8_t i )
		{
			return _mm256_insert_epi8( a, i, index );
		}

		// Copy "a" to "dst", and insert the 16-bit integer "i" into "dst" at the location specified by "index"
		template<int index>
		inline __m256i XM_CALLCONV insert_epi16( __m256i a, int16_t i )
		{
			return _mm256_insert_epi16( a, i, index );
		}

		// Copy "a" to "dst", and insert the 32-bit integer "i" into "dst" at the location specified by "index"
		template<int index>
		inline __m256i XM_CALLCONV insert_epi32( __m256i a, int32_t i )
		{
			return _mm256_insert_epi32( a, i, index );
		}

		// Copy "a" to "dst", and insert the 64-bit integer "i" into "dst" at the location specified by "index"
		template<int index>
		inline __m256i XM_CALLCONV insert_epi64( __m256i a, int64_t i )
		{
			return _mm256_insert_epi64( a, (real_int64_t)i, index );
		}

		// Copy "a" to "dst", then insert 128 bits (composed of 2 packed double-precision floating-point elements) from "b" into "dst" at the location specified by "imm8"
		template<int imm8>
		inline __m256d XM_CALLCONV insertf128_pd( __m256d a, __m128d b )
		{
			return _mm256_insertf128_pd( a, b, imm8 );
		}

		// Copy "a" to "dst", then insert 128 bits (composed of 4 packed single-precision floating-point elements) from "b" into "dst" at the location specified by "imm8"
		template<int imm8>
		inline __m256 XM_CALLCONV insertf128_ps( __m256 a, __m128 b )
		{
			return _mm256_insertf128_ps( a, b, imm8 );
		}

		// Copy "a" to "dst", then insert 128 bits from "b" into "dst" at the location specified by "imm8"
		template<int imm8>
		inline __m256i XM_CALLCONV insertf128_all( __m256i a, __m128i b )
		{
			return _mm256_insertf128_si256( a, b, imm8 );
		}

		// Load 256-bits of integer data from unaligned memory into "dst". This intrinsic may perform better than "_mm256_loadu_si256" when the data crosses a cache line boundary.
		inline __m256i XM_CALLCONV lddqu_all( const __m256i *mem_addr )
		{
			return _mm256_lddqu_si256( mem_addr );
		}

		// Load 256-bits (composed of 4 packed double-precision floating-point elements) from memory into "dst"
		inline __m256d XM_CALLCONV load_pd( const double *mem_addr )
		{
			return _mm256_load_pd( mem_addr );
		}

		// Load 256-bits (composed of 8 packed single-precision floating-point elements) from memory into "dst"
		inline __m256 XM_CALLCONV load_ps( const float *mem_addr )
		{
			return _mm256_load_ps( mem_addr );
		}

		// Load 256-bits of integer data from memory into "dst".	"mem_addr" must be aligned on a 32-byte boundary or a general-protection exception may be generated.
		inline __m256i XM_CALLCONV load_all( const __m256i *mem_addr )
		{
			return _mm256_load_si256( mem_addr );
		}

		// Load 256-bits (composed of 4 packed double-precision floating-point elements) from memory into "dst"
		inline __m256d XM_CALLCONV loadu_pd( const double *mem_addr )
		{
			return _mm256_loadu_pd( mem_addr );
		}

		// Load 256-bits (composed of 8 packed single-precision floating-point elements) from memory into "dst"
		inline __m256 XM_CALLCONV loadu_ps( const float *mem_addr )
		{
			return _mm256_loadu_ps( mem_addr );
		}

		// Load 256-bits of integer data from memory into "dst".	"mem_addr" does not need to be aligned on any particular boundary.
		inline __m256i XM_CALLCONV loadu_all( const __m256i *mem_addr )
		{
			return _mm256_loadu_si256( mem_addr );
		}

		// Load packed double-precision floating-point elements from memory into "dst" using "mask" (elements are zeroed out when the high bit of the corresponding element is not set)
		inline __m256d XM_CALLCONV maskload_pd( const double *mem_addr, __m256i mask )
		{
			return _mm256_maskload_pd( mem_addr, mask );
		}

		// Load packed single-precision floating-point elements from memory into "dst" using "mask" (elements are zeroed out when the high bit of the corresponding element is not set)
		inline __m256 XM_CALLCONV maskload_ps( const float *mem_addr, __m256i mask )
		{
			return _mm256_maskload_ps( mem_addr, mask );
		}

		// Store packed double-precision floating-point elements from "a" into memory using "mask"
		inline void XM_CALLCONV maskstore_pd( double *mem_addr, __m256i mask, __m256d a )
		{
			_mm256_maskstore_pd( mem_addr, mask, a );
		}

		// Store packed single-precision floating-point elements from "a" into memory using "mask"
		inline void XM_CALLCONV maskstore_ps( float *mem_addr, __m256i mask, __m256 a )
		{
			_mm256_maskstore_ps( mem_addr, mask, a );
		}

		// Compare packed double-precision floating-point elements in "a" and "b", and store packed maximum values in "dst"
		inline __m256d XM_CALLCONV max_pd( __m256d a, __m256d b )
		{
			return _mm256_max_pd( a, b );
		}

		// Compare packed single-precision floating-point elements in "a" and "b", and store packed maximum values in "dst"
		inline __m256 XM_CALLCONV max_ps( __m256 a, __m256 b )
		{
			return _mm256_max_ps( a, b );
		}

		// Compare packed double-precision floating-point elements in "a" and "b", and store packed minimum values in "dst"
		inline __m256d XM_CALLCONV min_pd( __m256d a, __m256d b )
		{
			return _mm256_min_pd( a, b );
		}

		// Compare packed single-precision floating-point elements in "a" and "b", and store packed minimum values in "dst"
		inline __m256 XM_CALLCONV min_ps( __m256 a, __m256 b )
		{
			return _mm256_min_ps( a, b );
		}

		// Duplicate even-indexed double-precision floating-point elements from "a"
		inline __m256d XM_CALLCONV movedup_pd( __m256d a )
		{
			return _mm256_movedup_pd( a );
		}

		// Duplicate odd-indexed single-precision floating-point elements from "a"
		inline __m256 XM_CALLCONV movehdup_ps( __m256 a )
		{
			return _mm256_movehdup_ps( a );
		}

		// Duplicate even-indexed single-precision floating-point elements from "a"
		inline __m256 XM_CALLCONV moveldup_ps( __m256 a )
		{
			return _mm256_moveldup_ps( a );
		}

		// Set each bit of mask "dst" based on the most significant bit of the corresponding packed double-precision floating-point element in "a"
		inline int XM_CALLCONV movemask_pd( __m256d a )
		{
			return _mm256_movemask_pd( a );
		}

		// Set each bit of mask "dst" based on the most significant bit of the corresponding packed single-precision floating-point element in "a"
		inline int XM_CALLCONV movemask_ps( __m256 a )
		{
			return _mm256_movemask_ps( a );
		}

		// Multiply packed double-precision floating-point elements in "a" and "b"
		inline __m256d XM_CALLCONV mul_pd( __m256d a, __m256d b )
		{
			return _mm256_mul_pd( a, b );
		}

		// Multiply packed single-precision floating-point elements in "a" and "b"
		inline __m256 XM_CALLCONV mul_ps( __m256 a, __m256 b )
		{
			return _mm256_mul_ps( a, b );
		}

		// Compute the bitwise OR of packed double-precision floating-point elements in "a" and "b"
		inline __m256d XM_CALLCONV or_pd( __m256d a, __m256d b )
		{
			return _mm256_or_pd( a, b );
		}

		// Compute the bitwise OR of packed single-precision floating-point elements in "a" and "b"
		inline __m256 XM_CALLCONV or_ps( __m256 a, __m256 b )
		{
			return _mm256_or_ps( a, b );
		}

		// Shuffle double-precision floating-point elements in "a" within 128-bit lanes using the control in "imm8"
		template<int imm8>
		inline __m256d XM_CALLCONV permute_pd( __m256d a )
		{
			return _mm256_permute_pd( a, imm8 );
		}

		// Shuffle single-precision floating-point elements in "a" within 128-bit lanes using the control in "imm8"
		template<int imm8>
		inline __m256 XM_CALLCONV permute_ps( __m256 a )
		{
			return _mm256_permute_ps( a, imm8 );
		}

		// Shuffle 128-bits (composed of 2 packed double-precision floating-point elements) selected by "imm8" from "a" and "b"
		template<int imm8>
		inline __m256d XM_CALLCONV permute2f128_pd( __m256d a, __m256d b )
		{
			return _mm256_permute2f128_pd( a, b, imm8 );
		}

		// Shuffle 128-bits (composed of 4 packed single-precision floating-point elements) selected by "imm8" from "a" and "b"
		template<int imm8>
		inline __m256 XM_CALLCONV permute2f128_ps( __m256 a, __m256 b )
		{
			return _mm256_permute2f128_ps( a, b, imm8 );
		}

		// Shuffle 128-bits (composed of integer data) selected by "imm8" from "a" and "b"
		template<int imm8>
		inline __m256i XM_CALLCONV permute2f128_all( __m256i a, __m256i b )
		{
			return _mm256_permute2f128_si256( a, b, imm8 );
		}

		// Shuffle double-precision floating-point elements in "a" within 128-bit lanes using the control in "b"
		inline __m256d XM_CALLCONV permutevar_pd( __m256d a, __m256i b )
		{
			return _mm256_permutevar_pd( a, b );
		}

		// Shuffle single-precision floating-point elements in "a" within 128-bit lanes using the control in "b"
		inline __m256 XM_CALLCONV permutevar_ps( __m256 a, __m256i b )
		{
			return _mm256_permutevar_ps( a, b );
		}

		// Compute the approximate reciprocal of packed single-precision floating-point elements in "a"
		inline __m256 XM_CALLCONV rcp_ps( __m256 a )
		{
			return _mm256_rcp_ps( a );
		}

		// Round the packed double-precision floating-point elements in "a" using the "rounding" parameter
		template<int rounding>
		inline __m256d XM_CALLCONV round_pd( __m256d a )
		{
			return _mm256_round_pd( a, rounding );
		}

		// Round the packed single-precision floating-point elements in "a" using the "rounding" parameter
		template<int rounding>
		inline __m256 XM_CALLCONV round_ps( __m256 a )
		{
			return _mm256_round_ps( a, rounding );
		}

		// Compute the approximate reciprocal square root of packed single-precision floating-point elements in "a"
		inline __m256 XM_CALLCONV rsqrt_ps( __m256 a )
		{
			return _mm256_rsqrt_ps( a );
		}

		// Set packed 8-bit integers in "dst" with the supplied values
		inline __m256i XM_CALLCONV set_epi8( char e0, char e1, char e2, char e3, char e4, char e5, char e6, char e7, char e8, char e9, char e10, char e11, char e12, char e13, char e14, char e15, char e16, char e17, char e18, char e19, char e20, char e21, char e22, char e23, char e24, char e25, char e26, char e27, char e28, char e29, char e30, char e31 )
		{
			return _mm256_set_epi8( e31, e30, e29, e28, e27, e26, e25, e24, e23, e22, e21, e20, e19, e18, e17, e16, e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0 );
		}
		// Set packed 8-bit integers in "dst" with the supplied values
		inline __m256i XM_CALLCONV set_epu8( uint8_t e0, uint8_t e1, uint8_t e2, uint8_t e3, uint8_t e4, uint8_t e5, uint8_t e6, uint8_t e7, uint8_t e8, uint8_t e9, uint8_t e10, uint8_t e11, uint8_t e12, uint8_t e13, uint8_t e14, uint8_t e15, uint8_t e16, uint8_t e17, uint8_t e18, uint8_t e19, uint8_t e20, uint8_t e21, uint8_t e22, uint8_t e23, uint8_t e24, uint8_t e25, uint8_t e26, uint8_t e27, uint8_t e28, uint8_t e29, uint8_t e30, uint8_t e31 )
		{
			return _mm256_set_epi8( (char)e31, (char)e30, (char)e29, (char)e28, (char)e27, (char)e26, (char)e25, (char)e24, (char)e23, (char)e22, (char)e21, (char)e20, (char)e19, (char)e18, (char)e17, (char)e16, (char)e15, (char)e14, (char)e13, (char)e12, (char)e11, (char)e10, (char)e9, (char)e8, (char)e7, (char)e6, (char)e5, (char)e4, (char)e3, (char)e2, (char)e1, (char)e0 );
		}

		// Set packed 16-bit integers in "dst" with the supplied values.
		inline __m256i XM_CALLCONV set_epi16( short e0, short e1, short e2, short e3, short e4, short e5, short e6, short e7, short e8, short e9, short e10, short e11, short e12, short e13, short e14, short e15 )
		{
			return _mm256_set_epi16( e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0 );
		}
		// Set packed 16-bit integers in "dst" with the supplied values.
		inline __m256i XM_CALLCONV set_epu16( uint16_t e0, uint16_t e1, uint16_t e2, uint16_t e3, uint16_t e4, uint16_t e5, uint16_t e6, uint16_t e7, uint16_t e8, uint16_t e9, uint16_t e10, uint16_t e11, uint16_t e12, uint16_t e13, uint16_t e14, uint16_t e15 )
		{
			return _mm256_set_epi16( (short)e15, (short)e14, (short)e13, (short)e12, (short)e11, (short)e10, (short)e9, (short)e8, (short)e7, (short)e6, (short)e5, (short)e4, (short)e3, (short)e2, (short)e1, (short)e0 );
		}

		// Set packed 32-bit integers in "dst" with the supplied values.
		inline __m256i XM_CALLCONV set_epi32( int e0, int e1, int e2, int e3, int e4, int e5, int e6, int e7 )
		{
			return _mm256_set_epi32( e7, e6, e5, e4, e3, e2, e1, e0 );
		}
		// Set packed 32-bit integers in "dst" with the supplied values.
		inline __m256i XM_CALLCONV set_epu32( uint32_t e0, uint32_t e1, uint32_t e2, uint32_t e3, uint32_t e4, uint32_t e5, uint32_t e6, uint32_t e7 )
		{
			return _mm256_set_epi32( (int)e7, (int)e6, (int)e5, (int)e4, (int)e3, (int)e2, (int)e1, (int)e0 );
		}

		// Set packed 64-bit integers in "dst" with the supplied values.
		inline __m256i XM_CALLCONV set_epi64x( int64_t e0, int64_t e1, int64_t e2, int64_t e3 )
		{
			return _mm256_set_epi64x( (real_int64_t)e3, (real_int64_t)e2, (real_int64_t)e1, (real_int64_t)e0 );
		}
		// Set packed 64-bit integers in "dst" with the supplied values.
		inline __m256i XM_CALLCONV set_epu64x( uint64_t e0, uint64_t e1, uint64_t e2, uint64_t e3 )
		{
			return _mm256_set_epi64x( (real_int64_t)e3, (real_int64_t)e2, (real_int64_t)e1, (real_int64_t)e0 );
		}

		// Set packed double-precision floating-point elements in "dst" with the supplied values
		inline __m256d XM_CALLCONV set_pd( double e0, double e1, double e2, double e3 )
		{
			return _mm256_set_pd( e3, e2, e1, e0 );
		}

		// Set packed single-precision floating-point elements in "dst" with the supplied values
		inline __m256 XM_CALLCONV set_ps( float e0, float e1, float e2, float e3, float e4, float e5, float e6, float e7 )
		{
			return _mm256_set_ps( e7, e6, e5, e4, e3, e2, e1, e0 );
		}

		// Broadcast 8-bit integer "a" to all elements of "dst". This intrinsic may generate the "vpbroadcastb".
		inline __m256i XM_CALLCONV set1_epi8( char a )
		{
			return _mm256_set1_epi8( a );
		}
		// Broadcast 8-bit integer "a" to all elements of "dst". This intrinsic may generate the "vpbroadcastb".
		inline __m256i XM_CALLCONV set1_epu8( uint8_t a )
		{
			return _mm256_set1_epi8( (char)a );
		}

		// Broadcast 16-bit integer "a" to all all elements of "dst". This intrinsic may generate the "vpbroadcastw".
		inline __m256i XM_CALLCONV set1_epi16( short a )
		{
			return _mm256_set1_epi16( a );
		}
		// Broadcast 16-bit integer "a" to all all elements of "dst". This intrinsic may generate the "vpbroadcastw".
		inline __m256i XM_CALLCONV set1_epu16( uint16_t a )
		{
			return _mm256_set1_epi16( (short)a );
		}

		// Broadcast 32-bit integer "a" to all elements of "dst". This intrinsic may generate the "vpbroadcastd".
		inline __m256i XM_CALLCONV set1_epi32( int a )
		{
			return _mm256_set1_epi32( a );
		}
		// Broadcast 32-bit integer "a" to all elements of "dst". This intrinsic may generate the "vpbroadcastd".
		inline __m256i XM_CALLCONV set1_epu32( uint32_t a )
		{
			return _mm256_set1_epi32( (int)a );
		}

		// Broadcast 64-bit integer "a" to all elements of "dst". This intrinsic may generate the "vpbroadcastq".
		inline __m256i XM_CALLCONV set1_epi64x( int64_t a )
		{
			return _mm256_set1_epi64x( (real_int64_t)a );
		}
		// Broadcast 64-bit integer "a" to all elements of "dst". This intrinsic may generate the "vpbroadcastq".
		inline __m256i XM_CALLCONV set1_epu64x( uint64_t a )
		{
			return _mm256_set1_epi64x( (real_int64_t)a );
		}

		// Broadcast double-precision floating-point value "a" to all elements of "dst"
		inline __m256d XM_CALLCONV set1_pd( double a )
		{
			return _mm256_set1_pd( a );
		}

		// Broadcast single-precision floating-point value "a" to all elements of "dst"
		inline __m256 XM_CALLCONV set1_ps( float a )
		{
			return _mm256_set1_ps( a );
		}

		// Return vector of type __m256d with all elements set to zero.
		inline __m256d XM_CALLCONV setzero_pd()
		{
			return _mm256_setzero_pd();
		}

		// Return vector of type __m256 with all elements set to zero.
		inline __m256 XM_CALLCONV setzero_ps()
		{
			return _mm256_setzero_ps();
		}

		// Return vector of type __m256i with all elements set to zero.
		inline __m256i XM_CALLCONV setzero_all()
		{
			return _mm256_setzero_si256();
		}

		// Shuffle double-precision floating-point elements within 128-bit lanes using the control in "imm8"
		template<int imm8>
		inline __m256d XM_CALLCONV shuffle_pd( __m256d a, __m256d b )
		{
			return _mm256_shuffle_pd( a, b, imm8 );
		}

		// Shuffle single-precision floating-point elements in "a" within 128-bit lanes using the control in "imm8"
		template<int imm8>
		inline __m256 XM_CALLCONV shuffle_ps( __m256 a, __m256 b )
		{
			return _mm256_shuffle_ps( a, b, imm8 );
		}

		// Compute the square root of packed double-precision floating-point elements in "a"
		inline __m256d XM_CALLCONV sqrt_pd( __m256d a )
		{
			return _mm256_sqrt_pd( a );
		}

		// Compute the square root of packed single-precision floating-point elements in "a"
		inline __m256 XM_CALLCONV sqrt_ps( __m256 a )
		{
			return _mm256_sqrt_ps( a );
		}

		// Store 256-bits (composed of 4 packed double-precision floating-point elements) from "a" into memory
		inline void XM_CALLCONV store_pd( double *mem_addr, __m256d a )
		{
			_mm256_store_pd( mem_addr, a );
		}

		// Store 256-bits (composed of 8 packed single-precision floating-point elements) from "a" into memory
		inline void XM_CALLCONV store_ps( float *mem_addr, __m256 a )
		{
			_mm256_store_ps( mem_addr, a );
		}

		// Store 256-bits of integer data from "a" into memory.	"mem_addr" must be aligned on a 32-byte boundary or a general-protection exception may be generated.
		inline void XM_CALLCONV store_all( __m256i *mem_addr, __m256i a )
		{
			_mm256_store_si256( mem_addr, a );
		}

		// Store 256-bits (composed of 4 packed double-precision floating-point elements) from "a" into memory
		inline void XM_CALLCONV storeu_pd( double *mem_addr, __m256d a )
		{
			_mm256_storeu_pd( mem_addr, a );
		}

		// Store 256-bits (composed of 8 packed single-precision floating-point elements) from "a" into memory
		inline void XM_CALLCONV storeu_ps( float *mem_addr, __m256 a )
		{
			_mm256_storeu_ps( mem_addr, a );
		}

		// Store 256-bits of integer data from "a" into memory.	"mem_addr" does not need to be aligned on any particular boundary.
		inline void XM_CALLCONV storeu_all( __m256i *mem_addr, __m256i a )
		{
			_mm256_storeu_si256( mem_addr, a );
		}

		// Store 256-bits (composed of 4 packed double-precision floating-point elements) from "a" into memory using a non-temporal memory hint
		inline void XM_CALLCONV stream_pd( double *mem_addr, __m256d a )
		{
			_mm256_stream_pd( mem_addr, a );
		}

		// Store 256-bits (composed of 8 packed single-precision floating-point elements) from "a" into memory using a non-temporal memory hint
		inline void XM_CALLCONV stream_ps( float *mem_addr, __m256 a )
		{
			_mm256_stream_ps( mem_addr, a );
		}

		// Store 256-bits of integer data from "a" into memory using a non-temporal memory hint
		inline void XM_CALLCONV stream_all( __m256i *mem_addr, __m256i a )
		{
			_mm256_stream_si256( mem_addr, a );
		}

		// Subtract packed double-precision floating-point elements in "b" from packed double-precision floating-point elements in "a"
		inline __m256d XM_CALLCONV sub_pd( __m256d a, __m256d b )
		{
			return _mm256_sub_pd( a, b );
		}

		// Subtract packed single-precision floating-point elements in "b" from packed single-precision floating-point elements in "a"
		inline __m256 XM_CALLCONV sub_ps( __m256 a, __m256 b )
		{
			return _mm256_sub_ps( a, b );
		}

		// Compute the bitwise AND of 256 bits (representing double-precision floating-point elements) in "a" and "b", producing an intermediate 256-bit value, and set "ZF" to 1 if the sign bit of each 64-bit element in the intermediate value is zero, otherwise set "ZF" to 0
		inline int XM_CALLCONV testc_pd( __m256d a, __m256d b )
		{
			return _mm256_testc_pd( a, b );
		}

		// Compute the bitwise AND of 256 bits (representing single-precision floating-point elements) in "a" and "b", producing an intermediate 256-bit value, and set "ZF" to 1 if the sign bit of each 32-bit element in the intermediate value is zero, otherwise set "ZF" to 0
		inline int XM_CALLCONV testc_ps( __m256 a, __m256 b )
		{
			return _mm256_testc_ps( a, b );
		}

		// Compute the bitwise AND of 256 bits (representing integer data) in "a" and "b", and set "ZF" to 1 if the result is zero, otherwise set "ZF" to 0
		inline int XM_CALLCONV testc_all( __m256i a, __m256i b )
		{
			return _mm256_testc_si256( a, b );
		}

		// Compute the bitwise AND of 256 bits (representing double-precision floating-point elements) in "a" and "b", producing an intermediate 256-bit value, and set "ZF" to 1 if the sign bit of each 64-bit element in the intermediate value is zero, otherwise set "ZF" to 0
		inline int XM_CALLCONV testnzc_pd( __m256d a, __m256d b )
		{
			return _mm256_testnzc_pd( a, b );
		}

		// Compute the bitwise AND of 256 bits (representing single-precision floating-point elements) in "a" and "b", producing an intermediate 256-bit value, and set "ZF" to 1 if the sign bit of each 32-bit element in the intermediate value is zero, otherwise set "ZF" to 0
		inline int XM_CALLCONV testnzc_ps( __m256 a, __m256 b )
		{
			return _mm256_testnzc_ps( a, b );
		}

		// Compute the bitwise AND of 256 bits (representing integer data) in "a" and "b", and set "ZF" to 1 if the result is zero, otherwise set "ZF" to 0
		inline int XM_CALLCONV testnzc_all( __m256i a, __m256i b )
		{
			return _mm256_testnzc_si256( a, b );
		}

		// Compute the bitwise AND of 256 bits (representing double-precision floating-point elements) in "a" and "b", producing an intermediate 256-bit value, and set "ZF" to 1 if the sign bit of each 64-bit element in the intermediate value is zero, otherwise set "ZF" to 0
		inline int XM_CALLCONV testz_pd( __m256d a, __m256d b )
		{
			return _mm256_testz_pd( a, b );
		}

		// Compute the bitwise AND of 256 bits (representing single-precision floating-point elements) in "a" and "b", producing an intermediate 256-bit value, and set "ZF" to 1 if the sign bit of each 32-bit element in the intermediate value is zero, otherwise set "ZF" to 0
		inline int XM_CALLCONV testz_ps( __m256 a, __m256 b )
		{
			return _mm256_testz_ps( a, b );
		}

		// Compute the bitwise AND of 256 bits (representing integer data) in "a" and "b", and set "ZF" to 1 if the result is zero, otherwise set "ZF" to 0
		inline int XM_CALLCONV testz_all( __m256i a, __m256i b )
		{
			return _mm256_testz_si256( a, b );
		}

		// Return vector of type __m256d with undefined elements.
		inline __m256d XM_CALLCONV undefined_pd()
		{
			return _mm256_undefined_pd();
		}

		// Return vector of type __m256 with undefined elements.
		inline __m256 XM_CALLCONV undefined_ps()
		{
			return _mm256_undefined_ps();
		}

		// Return vector of type __m256i with undefined elements.
		inline __m256i XM_CALLCONV undefined_all()
		{
			return _mm256_undefined_si256();
		}

		// Unpack and interleave double-precision floating-point elements from the high half of each 128-bit lane in "a" and "b"
		inline __m256d XM_CALLCONV unpackhi_pd( __m256d a, __m256d b )
		{
			return _mm256_unpackhi_pd( a, b );
		}

		// Unpack and interleave single-precision floating-point elements from the high half of each 128-bit lane in "a" and "b"
		inline __m256 XM_CALLCONV unpackhi_ps( __m256 a, __m256 b )
		{
			return _mm256_unpackhi_ps( a, b );
		}

		// Unpack and interleave double-precision floating-point elements from the low half of each 128-bit lane in "a" and "b"
		inline __m256d XM_CALLCONV unpacklo_pd( __m256d a, __m256d b )
		{
			return _mm256_unpacklo_pd( a, b );
		}

		// Unpack and interleave single-precision floating-point elements from the low half of each 128-bit lane in "a" and "b"
		inline __m256 XM_CALLCONV unpacklo_ps( __m256 a, __m256 b )
		{
			return _mm256_unpacklo_ps( a, b );
		}

		// Compute the bitwise XOR of packed double-precision floating-point elements in "a" and "b"
		inline __m256d XM_CALLCONV xor_pd( __m256d a, __m256d b )
		{
			return _mm256_xor_pd( a, b );
		}

		// Compute the bitwise XOR of packed single-precision floating-point elements in "a" and "b"
		inline __m256 XM_CALLCONV xor_ps( __m256 a, __m256 b )
		{
			return _mm256_xor_ps( a, b );
		}

		// Zero the contents of all XMM or YMM registers.
		inline void XM_CALLCONV zeroall()
		{
			_mm256_zeroall();
		}

		// Zero the upper 128 bits of all YMM registers; the lower 128-bits of the registers are unmodified
		inline void XM_CALLCONV zeroupper()
		{
			_mm256_zeroupper();
		}

#ifndef __GNUC__
		// Load two 128-bit values (composed of 4 packed single-precision floating-point elements) from memory, and combine them into a 256-bit value in "dst"
		inline __m256 XM_CALLCONV loadu2_m128( const float *hiaddr, const float *loaddr )
		{
			return _mm256_loadu2_m128( hiaddr, loaddr );
		}

		// Load two 128-bit values (composed of 2 packed double-precision floating-point elements) from memory, and combine them into a 256-bit value in "dst"
		inline __m256d XM_CALLCONV loadu2_m128d( const double *hiaddr, const double *loaddr )
		{
			return _mm256_loadu2_m128d( hiaddr, loaddr );
		}

		// Load two 128-bit values (composed of integer data) from memory, and combine them into a 256-bit value in "dst"
		inline __m256i XM_CALLCONV loadu2_m128i( const __m128i *hiaddr, const __m128i *loaddr )
		{
			return _mm256_loadu2_m128i( hiaddr, loaddr );
		}

		// Set packed __m256 vector "dst" with the supplied values.
		inline __m256 XM_CALLCONV set_m128( __m128 lo, __m128 hi )
		{
			return _mm256_set_m128( hi, lo );
		}

		// Set packed __m256d vector "dst" with the supplied values.
		inline __m256d XM_CALLCONV set_m128d( __m128d lo, __m128d hi )
		{
			return _mm256_set_m128d( hi, lo );
		}

		// Set packed __m256i vector "dst" with the supplied values.
		inline __m256i XM_CALLCONV set_m128i( __m128i lo, __m128i hi )
		{
			return _mm256_set_m128i( hi, lo );
		}

		// Store the high and low 128-bit halves (each composed of 4 packed single-precision floating-point elements) from "a" into memory two different 128-bit locations
		inline void XM_CALLCONV storeu2_m128( float *hiaddr, float *loaddr, __m256 a )
		{
			_mm256_storeu2_m128( hiaddr, loaddr, a );
		}

		// Store the high and low 128-bit halves (each composed of 2 packed double-precision floating-point elements) from "a" into memory two different 128-bit locations
		inline void XM_CALLCONV storeu2_m128d( double *hiaddr, double *loaddr, __m256d a )
		{
			_mm256_storeu2_m128d( hiaddr, loaddr, a );
		}

		// Store the high and low 128-bit halves (each composed of integer data) from "a" into memory two different 128-bit locations
		inline void XM_CALLCONV storeu2_m128i( __m128i *hiaddr, __m128i *loaddr, __m256i a )
		{
			_mm256_storeu2_m128i( hiaddr, loaddr, a );
		}
#endif // !__GNUC__
	}	// namespace Intrinsics::Avx

	namespace Sse
	{
		// Broadcast a single-precision floating-point element from memory to all elements of "dst"
		inline __m128 XM_CALLCONV broadcast_ss( const float *mem_addr )
		{
			return _mm_broadcast_ss( mem_addr );
		}

		// Compare packed double-precision floating-point elements in "a" and "b"
		template<int imm8>
		inline __m128d XM_CALLCONV cmp_pd( __m128d a, __m128d b )
		{
			return _mm_cmp_pd( a, b, imm8 );
		}

		// Compare packed single-precision floating-point elements in "a" and "b"
		template<int imm8>
		inline __m128 XM_CALLCONV cmp_ps( __m128 a, __m128 b )
		{
			return _mm_cmp_ps( a, b, imm8 );
		}

		// Compare the lower double-precision floating-point element in "a" and "b"
		template<int imm8>
		inline __m128d XM_CALLCONV cmp_sd( __m128d a, __m128d b )
		{
			return _mm_cmp_sd( a, b, imm8 );
		}

		// Compare the lower single-precision floating-point element in "a" and "b"
		template<int imm8>
		inline __m128 XM_CALLCONV cmp_ss( __m128 a, __m128 b )
		{
			return _mm_cmp_ss( a, b, imm8 );
		}

		// Load packed double-precision floating-point elements from memory into "dst" using "mask" (elements are zeroed out when the high bit of the corresponding element is not set)
		inline __m128d XM_CALLCONV maskload_pd( const double *mem_addr, __m128i mask )
		{
			return _mm_maskload_pd( mem_addr, mask );
		}

		// Load packed single-precision floating-point elements from memory into "dst" using "mask" (elements are zeroed out when the high bit of the corresponding element is not set)
		inline __m128 XM_CALLCONV maskload_ps( const float *mem_addr, __m128i mask )
		{
			return _mm_maskload_ps( mem_addr, mask );
		}

		// Store packed double-precision floating-point elements from "a" into memory using "mask"
		inline void XM_CALLCONV maskstore_pd( double *mem_addr, __m128i mask, __m128d a )
		{
			_mm_maskstore_pd( mem_addr, mask, a );
		}

		// Store packed single-precision floating-point elements from "a" into memory using "mask"
		inline void XM_CALLCONV maskstore_ps( float *mem_addr, __m128i mask, __m128 a )
		{
			_mm_maskstore_ps( mem_addr, mask, a );
		}

		// Shuffle double-precision floating-point elements in "a" using the control in "imm8"
		template<int imm8>
		inline __m128d XM_CALLCONV permute_pd( __m128d a )
		{
			return _mm_permute_pd( a, imm8 );
		}

		// Shuffle single-precision floating-point elements in "a" using the control in "imm8"
		template<int imm8>
		inline __m128 XM_CALLCONV permute_ps( __m128 a )
		{
			return _mm_permute_ps( a, imm8 );
		}

		// Shuffle double-precision floating-point elements in "a" using the control in "b"
		inline __m128d XM_CALLCONV permutevar_pd( __m128d a, __m128i b )
		{
			return _mm_permutevar_pd( a, b );
		}

		// Shuffle single-precision floating-point elements in "a" using the control in "b"
		inline __m128 XM_CALLCONV permutevar_ps( __m128 a, __m128i b )
		{
			return _mm_permutevar_ps( a, b );
		}

		// Compute the bitwise AND of 128 bits (representing double-precision floating-point elements) in "a" and "b", producing an intermediate 128-bit value, and set "ZF" to 1 if the sign bit of each 64-bit element in the intermediate value is zero, otherwise set "ZF" to 0
		inline int XM_CALLCONV testc_pd( __m128d a, __m128d b )
		{
			return _mm_testc_pd( a, b );
		}

		// Compute the bitwise AND of 128 bits (representing single-precision floating-point elements) in "a" and "b", producing an intermediate 128-bit value, and set "ZF" to 1 if the sign bit of each 32-bit element in the intermediate value is zero, otherwise set "ZF" to 0
		inline int XM_CALLCONV testc_ps( __m128 a, __m128 b )
		{
			return _mm_testc_ps( a, b );
		}

		// Compute the bitwise AND of 128 bits (representing double-precision floating-point elements) in "a" and "b", producing an intermediate 128-bit value, and set "ZF" to 1 if the sign bit of each 64-bit element in the intermediate value is zero, otherwise set "ZF" to 0
		inline int XM_CALLCONV testnzc_pd( __m128d a, __m128d b )
		{
			return _mm_testnzc_pd( a, b );
		}

		// Compute the bitwise AND of 128 bits (representing single-precision floating-point elements) in "a" and "b", producing an intermediate 128-bit value, and set "ZF" to 1 if the sign bit of each 32-bit element in the intermediate value is zero, otherwise set "ZF" to 0
		inline int XM_CALLCONV testnzc_ps( __m128 a, __m128 b )
		{
			return _mm_testnzc_ps( a, b );
		}

		// Compute the bitwise AND of 128 bits (representing double-precision floating-point elements) in "a" and "b", producing an intermediate 128-bit value, and set "ZF" to 1 if the sign bit of each 64-bit element in the intermediate value is zero, otherwise set "ZF" to 0
		inline int XM_CALLCONV testz_pd( __m128d a, __m128d b )
		{
			return _mm_testz_pd( a, b );
		}

		// Compute the bitwise AND of 128 bits (representing single-precision floating-point elements) in "a" and "b", producing an intermediate 128-bit value, and set "ZF" to 1 if the sign bit of each 32-bit element in the intermediate value is zero, otherwise set "ZF" to 0
		inline int XM_CALLCONV testz_ps( __m128 a, __m128 b )
		{
			return _mm_testz_ps( a, b );
		}
	}	// namespace Intrinsics::Sse
}	// namespace Intrinsics
#include "Extra/avx-extra.hpp"