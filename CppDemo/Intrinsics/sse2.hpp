// This file is generated automatically by a tool. If you want to change it, fork & modify the tool instead: https://github.com/Const-me/IntelIntrinsics
#pragma once
#include <emmintrin.h>
#include <immintrin.h>
#include "Extra/common.hpp"

namespace Intrinsics
{
	namespace Sse
	{
		// Add packed 8-bit integers in "a" and "b", and store the results in "dst"
		inline __m128i XM_CALLCONV add_epi8( __m128i a, __m128i b )
		{
			return _mm_add_epi8( a, b );
		}

		// Add packed 16-bit integers in "a" and "b", and store the results in "dst"
		inline __m128i XM_CALLCONV add_epi16( __m128i a, __m128i b )
		{
			return _mm_add_epi16( a, b );
		}

		// Add packed 32-bit integers in "a" and "b", and store the results in "dst"
		inline __m128i XM_CALLCONV add_epi32( __m128i a, __m128i b )
		{
			return _mm_add_epi32( a, b );
		}

		// Add packed 64-bit integers in "a" and "b", and store the results in "dst"
		inline __m128i XM_CALLCONV add_epi64( __m128i a, __m128i b )
		{
			return _mm_add_epi64( a, b );
		}

		// Add packed double-precision floating-point elements in "a" and "b"
		inline __m128d XM_CALLCONV add_pd( __m128d a, __m128d b )
		{
			return _mm_add_pd( a, b );
		}

		// Add the lower double-precision floating-point element in "a" and "b"
		inline __m128d XM_CALLCONV add_sd( __m128d a, __m128d b )
		{
			return _mm_add_sd( a, b );
		}

		// Add packed 8-bit integers in "a" and "b" using saturation, and store the results in "dst"
		inline __m128i XM_CALLCONV adds_epi8( __m128i a, __m128i b )
		{
			return _mm_adds_epi8( a, b );
		}

		// Add packed 16-bit integers in "a" and "b" using saturation, and store the results in "dst"
		inline __m128i XM_CALLCONV adds_epi16( __m128i a, __m128i b )
		{
			return _mm_adds_epi16( a, b );
		}

		// Add packed unsigned 8-bit integers in "a" and "b" using saturation
		inline __m128i XM_CALLCONV adds_epu8( __m128i a, __m128i b )
		{
			return _mm_adds_epu8( a, b );
		}

		// Add packed unsigned 16-bit integers in "a" and "b" using saturation
		inline __m128i XM_CALLCONV adds_epu16( __m128i a, __m128i b )
		{
			return _mm_adds_epu16( a, b );
		}

		// Compute the bitwise AND of packed double-precision floating-point elements in "a" and "b"
		inline __m128d XM_CALLCONV and_pd( __m128d a, __m128d b )
		{
			return _mm_and_pd( a, b );
		}

		// Compute the bitwise AND of 128 bits (representing integer data) in "a" and "b"
		inline __m128i XM_CALLCONV and_all( __m128i a, __m128i b )
		{
			return _mm_and_si128( a, b );
		}

		// Compute the bitwise NOT of packed double-precision floating-point elements in "a" and then AND with "b"
		inline __m128d XM_CALLCONV andnot_pd( __m128d a, __m128d b )
		{
			return _mm_andnot_pd( a, b );
		}

		// Compute the bitwise NOT of 128 bits (representing integer data) in "a" and then AND with "b"
		inline __m128i XM_CALLCONV andnot_all( __m128i a, __m128i b )
		{
			return _mm_andnot_si128( a, b );
		}

		// Average packed unsigned 8-bit integers in "a" and "b", and store the results in "dst"
		inline __m128i XM_CALLCONV avg_epu8( __m128i a, __m128i b )
		{
			return _mm_avg_epu8( a, b );
		}

		// Average packed unsigned 16-bit integers in "a" and "b", and store the results in "dst"
		inline __m128i XM_CALLCONV avg_epu16( __m128i a, __m128i b )
		{
			return _mm_avg_epu16( a, b );
		}

		// Shift "a" left by "imm8" bytes while shifting in zeros, and store the results in "dst"
		template<int imm8>
		inline __m128i XM_CALLCONV bslli_all( __m128i a )
		{
			return _mm_bslli_si128( a, imm8 );
		}

		// Shift "a" right by "imm8" bytes while shifting in zeros, and store the results in "dst"
		template<int imm8>
		inline __m128i XM_CALLCONV bsrli_all( __m128i a )
		{
			return _mm_bsrli_si128( a, imm8 );
		}

		// Cast vector of type __m128d to type __m128. This intrinsic is only used for compilation and does not generate any instructions, thus it has zero latency.
		inline __m128 XM_CALLCONV castpd_ps( __m128d a )
		{
			return _mm_castpd_ps( a );
		}

		// Cast vector of type __m128d to type __m128i. This intrinsic is only used for compilation and does not generate any instructions, thus it has zero latency.
		inline __m128i XM_CALLCONV castpd_all( __m128d a )
		{
			return _mm_castpd_si128( a );
		}

		// Cast vector of type __m128 to type __m128d. This intrinsic is only used for compilation and does not generate any instructions, thus it has zero latency.
		inline __m128d XM_CALLCONV castps_pd( __m128 a )
		{
			return _mm_castps_pd( a );
		}

		// Cast vector of type __m128 to type __m128i. This intrinsic is only used for compilation and does not generate any instructions, thus it has zero latency.
		inline __m128i XM_CALLCONV castps_all( __m128 a )
		{
			return _mm_castps_si128( a );
		}

		// Cast vector of type __m128i to type __m128d. This intrinsic is only used for compilation and does not generate any instructions, thus it has zero latency.
		inline __m128d XM_CALLCONV castall_pd( __m128i a )
		{
			return _mm_castsi128_pd( a );
		}

		// Cast vector of type __m128i to type __m128. This intrinsic is only used for compilation and does not generate any instructions, thus it has zero latency.
		inline __m128 XM_CALLCONV castall_ps( __m128i a )
		{
			return _mm_castsi128_ps( a );
		}

		// Compare packed 8-bit integers in "a" and "b" for equality, and store the results in "dst"
		inline __m128i XM_CALLCONV cmpeq_epi8( __m128i a, __m128i b )
		{
			return _mm_cmpeq_epi8( a, b );
		}

		// Compare packed 16-bit integers in "a" and "b" for equality, and store the results in "dst"
		inline __m128i XM_CALLCONV cmpeq_epi16( __m128i a, __m128i b )
		{
			return _mm_cmpeq_epi16( a, b );
		}

		// Compare packed 32-bit integers in "a" and "b" for equality, and store the results in "dst"
		inline __m128i XM_CALLCONV cmpeq_epi32( __m128i a, __m128i b )
		{
			return _mm_cmpeq_epi32( a, b );
		}

		// Compare packed double-precision floating-point elements in "a" and "b" for equality
		inline __m128d XM_CALLCONV cmpeq_pd( __m128d a, __m128d b )
		{
			return _mm_cmpeq_pd( a, b );
		}

		// Compare the lower double-precision floating-point elements in "a" and "b" for equality
		inline __m128d XM_CALLCONV cmpeq_sd( __m128d a, __m128d b )
		{
			return _mm_cmpeq_sd( a, b );
		}

		// Compare packed double-precision floating-point elements in "a" and "b" for greater-than-or-equal
		inline __m128d XM_CALLCONV cmpge_pd( __m128d a, __m128d b )
		{
			return _mm_cmpge_pd( a, b );
		}

		// Compare the lower double-precision floating-point elements in "a" and "b" for greater-than-or-equal
		inline __m128d XM_CALLCONV cmpge_sd( __m128d a, __m128d b )
		{
			return _mm_cmpge_sd( a, b );
		}

		// Compare packed 8-bit integers in "a" and "b" for greater-than, and store the results in "dst"
		inline __m128i XM_CALLCONV cmpgt_epi8( __m128i a, __m128i b )
		{
			return _mm_cmpgt_epi8( a, b );
		}

		// Compare packed 16-bit integers in "a" and "b" for greater-than, and store the results in "dst"
		inline __m128i XM_CALLCONV cmpgt_epi16( __m128i a, __m128i b )
		{
			return _mm_cmpgt_epi16( a, b );
		}

		// Compare packed 32-bit integers in "a" and "b" for greater-than, and store the results in "dst"
		inline __m128i XM_CALLCONV cmpgt_epi32( __m128i a, __m128i b )
		{
			return _mm_cmpgt_epi32( a, b );
		}

		// Compare packed double-precision floating-point elements in "a" and "b" for greater-than
		inline __m128d XM_CALLCONV cmpgt_pd( __m128d a, __m128d b )
		{
			return _mm_cmpgt_pd( a, b );
		}

		// Compare the lower double-precision floating-point elements in "a" and "b" for greater-than
		inline __m128d XM_CALLCONV cmpgt_sd( __m128d a, __m128d b )
		{
			return _mm_cmpgt_sd( a, b );
		}

		// Compare packed double-precision floating-point elements in "a" and "b" for less-than-or-equal
		inline __m128d XM_CALLCONV cmple_pd( __m128d a, __m128d b )
		{
			return _mm_cmple_pd( a, b );
		}

		// Compare the lower double-precision floating-point elements in "a" and "b" for less-than-or-equal
		inline __m128d XM_CALLCONV cmple_sd( __m128d a, __m128d b )
		{
			return _mm_cmple_sd( a, b );
		}

		// Compare packed 8-bit integers in "a" and "b" for less-than, and store the results in "dst"
		inline __m128i XM_CALLCONV cmplt_epi8( __m128i a, __m128i b )
		{
			return _mm_cmplt_epi8( a, b );
		}

		// Compare packed 16-bit integers in "a" and "b" for less-than, and store the results in "dst"
		inline __m128i XM_CALLCONV cmplt_epi16( __m128i a, __m128i b )
		{
			return _mm_cmplt_epi16( a, b );
		}

		// Compare packed 32-bit integers in "a" and "b" for less-than, and store the results in "dst"
		inline __m128i XM_CALLCONV cmplt_epi32( __m128i a, __m128i b )
		{
			return _mm_cmplt_epi32( a, b );
		}

		// Compare packed double-precision floating-point elements in "a" and "b" for less-than
		inline __m128d XM_CALLCONV cmplt_pd( __m128d a, __m128d b )
		{
			return _mm_cmplt_pd( a, b );
		}

		// Compare the lower double-precision floating-point elements in "a" and "b" for less-than
		inline __m128d XM_CALLCONV cmplt_sd( __m128d a, __m128d b )
		{
			return _mm_cmplt_sd( a, b );
		}

		// Compare packed double-precision floating-point elements in "a" and "b" for not-equal
		inline __m128d XM_CALLCONV cmpneq_pd( __m128d a, __m128d b )
		{
			return _mm_cmpneq_pd( a, b );
		}

		// Compare the lower double-precision floating-point elements in "a" and "b" for not-equal
		inline __m128d XM_CALLCONV cmpneq_sd( __m128d a, __m128d b )
		{
			return _mm_cmpneq_sd( a, b );
		}

		// Compare packed double-precision floating-point elements in "a" and "b" for not-greater-than-or-equal
		inline __m128d XM_CALLCONV cmpnge_pd( __m128d a, __m128d b )
		{
			return _mm_cmpnge_pd( a, b );
		}

		// Compare the lower double-precision floating-point elements in "a" and "b" for not-greater-than-or-equal
		inline __m128d XM_CALLCONV cmpnge_sd( __m128d a, __m128d b )
		{
			return _mm_cmpnge_sd( a, b );
		}

		// Compare packed double-precision floating-point elements in "a" and "b" for not-greater-than
		inline __m128d XM_CALLCONV cmpngt_pd( __m128d a, __m128d b )
		{
			return _mm_cmpngt_pd( a, b );
		}

		// Compare the lower double-precision floating-point elements in "a" and "b" for not-greater-than
		inline __m128d XM_CALLCONV cmpngt_sd( __m128d a, __m128d b )
		{
			return _mm_cmpngt_sd( a, b );
		}

		// Compare packed double-precision floating-point elements in "a" and "b" for not-less-than-or-equal
		inline __m128d XM_CALLCONV cmpnle_pd( __m128d a, __m128d b )
		{
			return _mm_cmpnle_pd( a, b );
		}

		// Compare the lower double-precision floating-point elements in "a" and "b" for not-less-than-or-equal
		inline __m128d XM_CALLCONV cmpnle_sd( __m128d a, __m128d b )
		{
			return _mm_cmpnle_sd( a, b );
		}

		// Compare packed double-precision floating-point elements in "a" and "b" for not-less-than
		inline __m128d XM_CALLCONV cmpnlt_pd( __m128d a, __m128d b )
		{
			return _mm_cmpnlt_pd( a, b );
		}

		// Compare the lower double-precision floating-point elements in "a" and "b" for not-less-than
		inline __m128d XM_CALLCONV cmpnlt_sd( __m128d a, __m128d b )
		{
			return _mm_cmpnlt_sd( a, b );
		}

		// Compare packed double-precision floating-point elements in "a" and "b" to see if neither is NaN
		inline __m128d XM_CALLCONV cmpord_pd( __m128d a, __m128d b )
		{
			return _mm_cmpord_pd( a, b );
		}

		// Compare the lower double-precision floating-point elements in "a" and "b" to see if neither is NaN
		inline __m128d XM_CALLCONV cmpord_sd( __m128d a, __m128d b )
		{
			return _mm_cmpord_sd( a, b );
		}

		// Compare packed double-precision floating-point elements in "a" and "b" to see if either is NaN
		inline __m128d XM_CALLCONV cmpunord_pd( __m128d a, __m128d b )
		{
			return _mm_cmpunord_pd( a, b );
		}

		// Compare the lower double-precision floating-point elements in "a" and "b" to see if either is NaN
		inline __m128d XM_CALLCONV cmpunord_sd( __m128d a, __m128d b )
		{
			return _mm_cmpunord_sd( a, b );
		}

		// Compare the lower double-precision floating-point element in "a" and "b" for equality
		inline int XM_CALLCONV comieq_sd( __m128d a, __m128d b )
		{
			return _mm_comieq_sd( a, b );
		}

		// Compare the lower double-precision floating-point element in "a" and "b" for greater-than-or-equal
		inline int XM_CALLCONV comige_sd( __m128d a, __m128d b )
		{
			return _mm_comige_sd( a, b );
		}

		// Compare the lower double-precision floating-point element in "a" and "b" for greater-than
		inline int XM_CALLCONV comigt_sd( __m128d a, __m128d b )
		{
			return _mm_comigt_sd( a, b );
		}

		// Compare the lower double-precision floating-point element in "a" and "b" for less-than-or-equal
		inline int XM_CALLCONV comile_sd( __m128d a, __m128d b )
		{
			return _mm_comile_sd( a, b );
		}

		// Compare the lower double-precision floating-point element in "a" and "b" for less-than
		inline int XM_CALLCONV comilt_sd( __m128d a, __m128d b )
		{
			return _mm_comilt_sd( a, b );
		}

		// Compare the lower double-precision floating-point element in "a" and "b" for not-equal
		inline int XM_CALLCONV comineq_sd( __m128d a, __m128d b )
		{
			return _mm_comineq_sd( a, b );
		}

		// Convert packed 32-bit integers in "a" to packed double-precision floating-point elements
		inline __m128d XM_CALLCONV cvtepi32_pd( __m128i a )
		{
			return _mm_cvtepi32_pd( a );
		}

		// Convert packed 32-bit integers in "a" to packed single-precision floating-point elements
		inline __m128 XM_CALLCONV cvtepi32_ps( __m128i a )
		{
			return _mm_cvtepi32_ps( a );
		}

		// Convert packed double-precision floating-point elements in "a" to packed 32-bit integers
		inline __m128i XM_CALLCONV cvtpd_epi32( __m128d a )
		{
			return _mm_cvtpd_epi32( a );
		}

		// Convert packed double-precision floating-point elements in "a" to packed single-precision floating-point elements
		inline __m128 XM_CALLCONV cvtpd_ps( __m128d a )
		{
			return _mm_cvtpd_ps( a );
		}

		// Convert packed single-precision floating-point elements in "a" to packed 32-bit integers
		inline __m128i XM_CALLCONV cvtps_epi32( __m128 a )
		{
			return _mm_cvtps_epi32( a );
		}

		// Convert packed single-precision floating-point elements in "a" to packed double-precision floating-point elements
		inline __m128d XM_CALLCONV cvtps_pd( __m128 a )
		{
			return _mm_cvtps_pd( a );
		}

		// Copy the lower double-precision floating-point element of "a" to "dst"
		inline double XM_CALLCONV cvtsd_f64( __m128d a )
		{
			return _mm_cvtsd_f64( a );
		}

		// Convert the lower double-precision floating-point element in "a" to a 32-bit integer
		inline int XM_CALLCONV cvtsd_si32( __m128d a )
		{
			return _mm_cvtsd_si32( a );
		}

		// Convert the lower double-precision floating-point element in "b" to a single-precision floating-point element
		inline __m128 XM_CALLCONV cvtsd_ss( __m128 a, __m128d b )
		{
			return _mm_cvtsd_ss( a, b );
		}

		// Copy the lower 32-bit integer in "a" to "dst".
		inline int XM_CALLCONV cvtsi128_si32( __m128i a )
		{
			return _mm_cvtsi128_si32( a );
		}

		// Convert the 32-bit integer "b" to a double-precision floating-point element
		inline __m128d XM_CALLCONV cvtsi32_sd( __m128d a, int b )
		{
			return _mm_cvtsi32_sd( a, b );
		}

		// Copy 32-bit integer "a" to the lower elements of "dst", and zero the upper elements of "dst"
		inline __m128i XM_CALLCONV cvtsi32_all( int a )
		{
			return _mm_cvtsi32_si128( a );
		}

		// Convert the lower single-precision floating-point element in "b" to a double-precision floating-point element
		inline __m128d XM_CALLCONV cvtss_sd( __m128d a, __m128 b )
		{
			return _mm_cvtss_sd( a, b );
		}

		// Convert packed double-precision floating-point elements in "a" to packed 32-bit integers with truncation
		inline __m128i XM_CALLCONV cvttpd_epi32( __m128d a )
		{
			return _mm_cvttpd_epi32( a );
		}

		// Convert packed single-precision floating-point elements in "a" to packed 32-bit integers with truncation
		inline __m128i XM_CALLCONV cvttps_epi32( __m128 a )
		{
			return _mm_cvttps_epi32( a );
		}

		// Convert the lower double-precision floating-point element in "a" to a 32-bit integer with truncation
		inline int XM_CALLCONV cvttsd_si32( __m128d a )
		{
			return _mm_cvttsd_si32( a );
		}

		// Divide packed double-precision floating-point elements in "a" by packed elements in "b"
		inline __m128d XM_CALLCONV div_pd( __m128d a, __m128d b )
		{
			return _mm_div_pd( a, b );
		}

		// Divide the lower double-precision floating-point element in "a" by the lower double-precision floating-point element in "b"
		inline __m128d XM_CALLCONV div_sd( __m128d a, __m128d b )
		{
			return _mm_div_sd( a, b );
		}

		// Extract a 16-bit integer from "a", selected with "imm8", and store the result in the lower element of "dst"
		template<int imm8>
		inline int XM_CALLCONV extract_epi16( __m128i a )
		{
			return _mm_extract_epi16( a, imm8 );
		}

		// Copy "a" to "dst", and insert the 16-bit integer "i" into "dst" at the location specified by "imm8"
		template<int imm8>
		inline __m128i XM_CALLCONV insert_epi16( __m128i a, int i )
		{
			return _mm_insert_epi16( a, i, imm8 );
		}

		// Perform a serializing operation on all load-from-memory instructions that were issued prior to this instruction
		inline void XM_CALLCONV lfence()
		{
			_mm_lfence();
		}

		// Load 128-bits (composed of 2 packed double-precision floating-point elements) from memory into "dst"
		inline __m128d XM_CALLCONV load_pd( const double *mem_addr )
		{
			return _mm_load_pd( mem_addr );
		}

		// Load a double-precision floating-point element from memory into the lower of "dst", and zero the upper element
		inline __m128d XM_CALLCONV load_sd( const double *mem_addr )
		{
			return _mm_load_sd( mem_addr );
		}

		// Load 128-bits of integer data from memory into "dst". "mem_addr" must be aligned on a 16-byte boundary or a general-protection exception may be generated.
		inline __m128i XM_CALLCONV load_all( const __m128i *mem_addr )
		{
			return _mm_load_si128( mem_addr );
		}

		// Load a double-precision floating-point element from memory into both elements of "dst"
		inline __m128d XM_CALLCONV load1_pd( const double *mem_addr )
		{
			return _mm_load1_pd( mem_addr );
		}

		// Load a double-precision floating-point element from memory into the upper element of "dst", and copy the lower element from "a" to "dst"
		inline __m128d XM_CALLCONV loadh_pd( __m128d a, const double *mem_addr )
		{
			return _mm_loadh_pd( a, mem_addr );
		}

		// Load 64-bit integer from memory into the first element of "dst".
		inline __m128i XM_CALLCONV loadl_epi64( const __m128i *mem_addr )
		{
			return _mm_loadl_epi64( mem_addr );
		}

		// Load a double-precision floating-point element from memory into the lower element of "dst", and copy the upper element from "a" to "dst"
		inline __m128d XM_CALLCONV loadl_pd( __m128d a, const double *mem_addr )
		{
			return _mm_loadl_pd( a, mem_addr );
		}

		// Load 2 double-precision floating-point elements from memory into "dst" in reverse order
		inline __m128d XM_CALLCONV loadr_pd( const double *mem_addr )
		{
			return _mm_loadr_pd( mem_addr );
		}

		// Load 128-bits (composed of 2 packed double-precision floating-point elements) from memory into "dst"
		inline __m128d XM_CALLCONV loadu_pd( const double *mem_addr )
		{
			return _mm_loadu_pd( mem_addr );
		}

		// Load 128-bits of integer data from memory into "dst".	"mem_addr" does not need to be aligned on any particular boundary.
		inline __m128i XM_CALLCONV loadu_all( const __m128i *mem_addr )
		{
			return _mm_loadu_si128( mem_addr );
		}

		// Multiply packed signed 16-bit integers in "a" and "b", producing intermediate signed 32-bit integers
		inline __m128i XM_CALLCONV madd_epi16( __m128i a, __m128i b )
		{
			return _mm_madd_epi16( a, b );
		}

		// Conditionally store 8-bit integer elements from "a" into memory using "mask" (elements are not stored when the highest bit is not set in the corresponding element) and a non-temporal memory hint
		inline void XM_CALLCONV maskmoveu_all( __m128i a, __m128i mask, char *mem_addr )
		{
			_mm_maskmoveu_si128( a, mask, mem_addr );
		}

		// Compare packed 16-bit integers in "a" and "b", and store packed maximum values in "dst"
		inline __m128i XM_CALLCONV max_epi16( __m128i a, __m128i b )
		{
			return _mm_max_epi16( a, b );
		}

		// Compare packed unsigned 8-bit integers in "a" and "b", and store packed maximum values in "dst"
		inline __m128i XM_CALLCONV max_epu8( __m128i a, __m128i b )
		{
			return _mm_max_epu8( a, b );
		}

		// Compare packed double-precision floating-point elements in "a" and "b", and store packed maximum values in "dst"
		inline __m128d XM_CALLCONV max_pd( __m128d a, __m128d b )
		{
			return _mm_max_pd( a, b );
		}

		// Compare the lower double-precision floating-point elements in "a" and "b", store the maximum value in the lower element of "dst", and copy the upper element from "a" to the upper element of "dst"
		inline __m128d XM_CALLCONV max_sd( __m128d a, __m128d b )
		{
			return _mm_max_sd( a, b );
		}

		// Perform a serializing operation on all load-from-memory and store-to-memory instructions that were issued prior to this instruction
		inline void XM_CALLCONV mfence()
		{
			_mm_mfence();
		}

		// Compare packed 16-bit integers in "a" and "b", and store packed minimum values in "dst"
		inline __m128i XM_CALLCONV min_epi16( __m128i a, __m128i b )
		{
			return _mm_min_epi16( a, b );
		}

		// Compare packed unsigned 8-bit integers in "a" and "b", and store packed minimum values in "dst"
		inline __m128i XM_CALLCONV min_epu8( __m128i a, __m128i b )
		{
			return _mm_min_epu8( a, b );
		}

		// Compare packed double-precision floating-point elements in "a" and "b", and store packed minimum values in "dst"
		inline __m128d XM_CALLCONV min_pd( __m128d a, __m128d b )
		{
			return _mm_min_pd( a, b );
		}

		// Compare the lower double-precision floating-point elements in "a" and "b", store the minimum value in the lower element of "dst", and copy the upper element from "a" to the upper element of "dst"
		inline __m128d XM_CALLCONV min_sd( __m128d a, __m128d b )
		{
			return _mm_min_sd( a, b );
		}

		// Copy the lower 64-bit integer in "a" to the lower element of "dst", and zero the upper element
		inline __m128i XM_CALLCONV move_epi64( __m128i a )
		{
			return _mm_move_epi64( a );
		}

		// Move the lower double-precision floating-point element from "b" to the lower element of "dst", and copy the upper element from "a" to the upper element of "dst"
		inline __m128d XM_CALLCONV move_sd( __m128d a, __m128d b )
		{
			return _mm_move_sd( a, b );
		}

		// Create mask from the most significant bit of each 8-bit element in "a"
		inline int XM_CALLCONV movemask_epi8( __m128i a )
		{
			return _mm_movemask_epi8( a );
		}

		// Set each bit of mask "dst" based on the most significant bit of the corresponding packed double-precision floating-point element in "a"
		inline int XM_CALLCONV movemask_pd( __m128d a )
		{
			return _mm_movemask_pd( a );
		}

		// Multiply the low unsigned 32-bit integers from each packed 64-bit element in "a" and "b", and store the unsigned 64-bit results in "dst"
		inline __m128i XM_CALLCONV mul_epu32( __m128i a, __m128i b )
		{
			return _mm_mul_epu32( a, b );
		}

		// Multiply packed double-precision floating-point elements in "a" and "b"
		inline __m128d XM_CALLCONV mul_pd( __m128d a, __m128d b )
		{
			return _mm_mul_pd( a, b );
		}

		// Multiply the lower double-precision floating-point element in "a" and "b"
		inline __m128d XM_CALLCONV mul_sd( __m128d a, __m128d b )
		{
			return _mm_mul_sd( a, b );
		}

		// Multiply the packed 16-bit integers in "a" and "b", producing intermediate 32-bit integers, and store the high 16 bits of the intermediate integers in "dst"
		inline __m128i XM_CALLCONV mulhi_epi16( __m128i a, __m128i b )
		{
			return _mm_mulhi_epi16( a, b );
		}

		// Multiply the packed unsigned 16-bit integers in "a" and "b", producing intermediate 32-bit integers, and store the high 16 bits of the intermediate integers in "dst"
		inline __m128i XM_CALLCONV mulhi_epu16( __m128i a, __m128i b )
		{
			return _mm_mulhi_epu16( a, b );
		}

		// Multiply the packed 16-bit integers in "a" and "b", producing intermediate 32-bit integers, and store the low 16 bits of the intermediate integers in "dst"
		inline __m128i XM_CALLCONV mullo_epi16( __m128i a, __m128i b )
		{
			return _mm_mullo_epi16( a, b );
		}

		// Compute the bitwise OR of packed double-precision floating-point elements in "a" and "b"
		inline __m128d XM_CALLCONV or_pd( __m128d a, __m128d b )
		{
			return _mm_or_pd( a, b );
		}

		// Compute the bitwise OR of 128 bits (representing integer data) in "a" and "b"
		inline __m128i XM_CALLCONV or_all( __m128i a, __m128i b )
		{
			return _mm_or_si128( a, b );
		}

		// Convert packed 16-bit integers from "a" and "b" to packed 8-bit integers using signed saturation
		inline __m128i XM_CALLCONV packs_epi16( __m128i a, __m128i b )
		{
			return _mm_packs_epi16( a, b );
		}

		// Convert packed 32-bit integers from "a" and "b" to packed 16-bit integers using signed saturation
		inline __m128i XM_CALLCONV packs_epi32( __m128i a, __m128i b )
		{
			return _mm_packs_epi32( a, b );
		}

		// Convert packed 16-bit integers from "a" and "b" to packed 8-bit integers using unsigned saturation
		inline __m128i XM_CALLCONV packus_epi16( __m128i a, __m128i b )
		{
			return _mm_packus_epi16( a, b );
		}

		// Provide a hint to the processor that the code sequence is a spin-wait loop
		inline void XM_CALLCONV pause()
		{
			_mm_pause();
		}

		// Compute the absolute differences of packed unsigned 8-bit integers in "a" and "b", then horizontally sum each consecutive 8 differences to produce two unsigned 16-bit integers, and pack these unsigned 16-bit integers in the low 16 bits of 64-bit elements in "dst"
		inline __m128i XM_CALLCONV sad_epu8( __m128i a, __m128i b )
		{
			return _mm_sad_epu8( a, b );
		}

		// Set packed 8-bit integers in "dst" with the supplied values
		inline __m128i XM_CALLCONV set_epi8( char e0, char e1, char e2, char e3, char e4, char e5, char e6, char e7, char e8, char e9, char e10, char e11, char e12, char e13, char e14, char e15 )
		{
			return _mm_set_epi8( e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0 );
		}
		// Set packed 8-bit integers in "dst" with the supplied values
		inline __m128i XM_CALLCONV set_epu8( uint8_t e0, uint8_t e1, uint8_t e2, uint8_t e3, uint8_t e4, uint8_t e5, uint8_t e6, uint8_t e7, uint8_t e8, uint8_t e9, uint8_t e10, uint8_t e11, uint8_t e12, uint8_t e13, uint8_t e14, uint8_t e15 )
		{
			return _mm_set_epi8( (char)e15, (char)e14, (char)e13, (char)e12, (char)e11, (char)e10, (char)e9, (char)e8, (char)e7, (char)e6, (char)e5, (char)e4, (char)e3, (char)e2, (char)e1, (char)e0 );
		}

		// Set packed 16-bit integers in "dst" with the supplied values.
		inline __m128i XM_CALLCONV set_epi16( short e0, short e1, short e2, short e3, short e4, short e5, short e6, short e7 )
		{
			return _mm_set_epi16( e7, e6, e5, e4, e3, e2, e1, e0 );
		}
		// Set packed 16-bit integers in "dst" with the supplied values.
		inline __m128i XM_CALLCONV set_epu16( uint16_t e0, uint16_t e1, uint16_t e2, uint16_t e3, uint16_t e4, uint16_t e5, uint16_t e6, uint16_t e7 )
		{
			return _mm_set_epi16( (short)e7, (short)e6, (short)e5, (short)e4, (short)e3, (short)e2, (short)e1, (short)e0 );
		}

		// Set packed 32-bit integers in "dst" with the supplied values.
		inline __m128i XM_CALLCONV set_epi32( int e0, int e1, int e2, int e3 )
		{
			return _mm_set_epi32( e3, e2, e1, e0 );
		}
		// Set packed 32-bit integers in "dst" with the supplied values.
		inline __m128i XM_CALLCONV set_epu32( uint32_t e0, uint32_t e1, uint32_t e2, uint32_t e3 )
		{
			return _mm_set_epi32( (int)e3, (int)e2, (int)e1, (int)e0 );
		}

		// Set packed 64-bit integers in "dst" with the supplied values.
		inline __m128i XM_CALLCONV set_epi64x( int64_t e0, int64_t e1 )
		{
			return _mm_set_epi64x( (real_int64_t)e1, (real_int64_t)e0 );
		}
		// Set packed 64-bit integers in "dst" with the supplied values.
		inline __m128i XM_CALLCONV set_epu64x( uint64_t e0, uint64_t e1 )
		{
			return _mm_set_epi64x( (real_int64_t)e1, (real_int64_t)e0 );
		}

		// Set packed double-precision floating-point elements in "dst" with the supplied values
		inline __m128d XM_CALLCONV set_pd( double e0, double e1 )
		{
			return _mm_set_pd( e1, e0 );
		}

		// Copy double-precision floating-point element "a" to the lower element of "dst", and zero the upper element
		inline __m128d XM_CALLCONV set_sd( double a )
		{
			return _mm_set_sd( a );
		}

		// Broadcast 8-bit integer "a" to all elements of "dst". This intrinsic may generate "vpbroadcastb".
		inline __m128i XM_CALLCONV set1_epi8( char a )
		{
			return _mm_set1_epi8( a );
		}
		// Broadcast 8-bit integer "a" to all elements of "dst". This intrinsic may generate "vpbroadcastb".
		inline __m128i XM_CALLCONV set1_epu8( uint8_t a )
		{
			return _mm_set1_epi8( (char)a );
		}

		// Broadcast 16-bit integer "a" to all all elements of "dst". This intrinsic may generate "vpbroadcastw".
		inline __m128i XM_CALLCONV set1_epi16( short a )
		{
			return _mm_set1_epi16( a );
		}
		// Broadcast 16-bit integer "a" to all all elements of "dst". This intrinsic may generate "vpbroadcastw".
		inline __m128i XM_CALLCONV set1_epu16( uint16_t a )
		{
			return _mm_set1_epi16( (short)a );
		}

		// Broadcast 32-bit integer "a" to all elements of "dst". This intrinsic may generate "vpbroadcastd".
		inline __m128i XM_CALLCONV set1_epi32( int a )
		{
			return _mm_set1_epi32( a );
		}
		// Broadcast 32-bit integer "a" to all elements of "dst". This intrinsic may generate "vpbroadcastd".
		inline __m128i XM_CALLCONV set1_epu32( uint32_t a )
		{
			return _mm_set1_epi32( (int)a );
		}

		// Broadcast 64-bit integer "a" to all elements of "dst". This intrinsic may generate the "vpbroadcastq".
		inline __m128i XM_CALLCONV set1_epi64x( int64_t a )
		{
			return _mm_set1_epi64x( (real_int64_t)a );
		}
		// Broadcast 64-bit integer "a" to all elements of "dst". This intrinsic may generate the "vpbroadcastq".
		inline __m128i XM_CALLCONV set1_epu64x( uint64_t a )
		{
			return _mm_set1_epi64x( (real_int64_t)a );
		}

		// Broadcast double-precision floating-point value "a" to all elements of "dst"
		inline __m128d XM_CALLCONV set1_pd( double a )
		{
			return _mm_set1_pd( a );
		}

		// Return vector of type __m128d with all elements set to zero.
		inline __m128d XM_CALLCONV setzero_pd()
		{
			return _mm_setzero_pd();
		}

		// Return vector of type __m128i with all elements set to zero.
		inline __m128i XM_CALLCONV setzero_all()
		{
			return _mm_setzero_si128();
		}

		// Shuffle 32-bit integers in "a" using the control in "imm8", and store the results in "dst"
		template<int imm8>
		inline __m128i XM_CALLCONV shuffle_epi32( __m128i a )
		{
			return _mm_shuffle_epi32( a, imm8 );
		}

		// Shuffle double-precision floating-point elements using the control in "imm8"
		template<int imm8>
		inline __m128d XM_CALLCONV shuffle_pd( __m128d a, __m128d b )
		{
			return _mm_shuffle_pd( a, b, imm8 );
		}

		// Shuffle 16-bit integers in the high 64 bits of "a" using the control in "imm8"
		template<int imm8>
		inline __m128i XM_CALLCONV shufflehi_epi16( __m128i a )
		{
			return _mm_shufflehi_epi16( a, imm8 );
		}

		// Shuffle 16-bit integers in the low 64 bits of "a" using the control in "imm8"
		template<int imm8>
		inline __m128i XM_CALLCONV shufflelo_epi16( __m128i a )
		{
			return _mm_shufflelo_epi16( a, imm8 );
		}

		// Shift packed 16-bit integers in "a" left by "count" while shifting in zeros
		inline __m128i XM_CALLCONV sll_epi16( __m128i a, __m128i count )
		{
			return _mm_sll_epi16( a, count );
		}

		// Shift packed 32-bit integers in "a" left by "count" while shifting in zeros
		inline __m128i XM_CALLCONV sll_epi32( __m128i a, __m128i count )
		{
			return _mm_sll_epi32( a, count );
		}

		// Shift packed 64-bit integers in "a" left by "count" while shifting in zeros
		inline __m128i XM_CALLCONV sll_epi64( __m128i a, __m128i count )
		{
			return _mm_sll_epi64( a, count );
		}

		// Shift packed 16-bit integers in "a" left by "imm8" while shifting in zeros
		template<int imm8>
		inline __m128i XM_CALLCONV slli_epi16( __m128i a )
		{
			return _mm_slli_epi16( a, imm8 );
		}

		// Shift packed 32-bit integers in "a" left by "imm8" while shifting in zeros
		template<int imm8>
		inline __m128i XM_CALLCONV slli_epi32( __m128i a )
		{
			return _mm_slli_epi32( a, imm8 );
		}

		// Shift packed 64-bit integers in "a" left by "imm8" while shifting in zeros
		template<int imm8>
		inline __m128i XM_CALLCONV slli_epi64( __m128i a )
		{
			return _mm_slli_epi64( a, imm8 );
		}

		// Shift "a" left by "imm8" bytes while shifting in zeros, and store the results in "dst"
		template<int imm8>
		inline __m128i XM_CALLCONV slli_all( __m128i a )
		{
			return _mm_slli_si128( a, imm8 );
		}

		// Compute the square root of packed double-precision floating-point elements in "a"
		inline __m128d XM_CALLCONV sqrt_pd( __m128d a )
		{
			return _mm_sqrt_pd( a );
		}

		// Compute the square root of the lower double-precision floating-point element in "b"
		inline __m128d XM_CALLCONV sqrt_sd( __m128d a, __m128d b )
		{
			return _mm_sqrt_sd( a, b );
		}

		// Shift packed 16-bit integers in "a" right by "count" while shifting in sign bits
		inline __m128i XM_CALLCONV sra_epi16( __m128i a, __m128i count )
		{
			return _mm_sra_epi16( a, count );
		}

		// Shift packed 32-bit integers in "a" right by "count" while shifting in sign bits
		inline __m128i XM_CALLCONV sra_epi32( __m128i a, __m128i count )
		{
			return _mm_sra_epi32( a, count );
		}

		// Shift packed 16-bit integers in "a" right by "imm8" while shifting in sign bits
		template<int imm8>
		inline __m128i XM_CALLCONV srai_epi16( __m128i a )
		{
			return _mm_srai_epi16( a, imm8 );
		}

		// Shift packed 32-bit integers in "a" right by "imm8" while shifting in sign bits
		template<int imm8>
		inline __m128i XM_CALLCONV srai_epi32( __m128i a )
		{
			return _mm_srai_epi32( a, imm8 );
		}

		// Shift packed 16-bit integers in "a" right by "count" while shifting in zeros
		inline __m128i XM_CALLCONV srl_epi16( __m128i a, __m128i count )
		{
			return _mm_srl_epi16( a, count );
		}

		// Shift packed 32-bit integers in "a" right by "count" while shifting in zeros
		inline __m128i XM_CALLCONV srl_epi32( __m128i a, __m128i count )
		{
			return _mm_srl_epi32( a, count );
		}

		// Shift packed 64-bit integers in "a" right by "count" while shifting in zeros
		inline __m128i XM_CALLCONV srl_epi64( __m128i a, __m128i count )
		{
			return _mm_srl_epi64( a, count );
		}

		// Shift packed 16-bit integers in "a" right by "imm8" while shifting in zeros
		template<int imm8>
		inline __m128i XM_CALLCONV srli_epi16( __m128i a )
		{
			return _mm_srli_epi16( a, imm8 );
		}

		// Shift packed 32-bit integers in "a" right by "imm8" while shifting in zeros
		template<int imm8>
		inline __m128i XM_CALLCONV srli_epi32( __m128i a )
		{
			return _mm_srli_epi32( a, imm8 );
		}

		// Shift packed 64-bit integers in "a" right by "imm8" while shifting in zeros
		template<int imm8>
		inline __m128i XM_CALLCONV srli_epi64( __m128i a )
		{
			return _mm_srli_epi64( a, imm8 );
		}

		// Shift "a" right by "imm8" bytes while shifting in zeros, and store the results in "dst"
		template<int imm8>
		inline __m128i XM_CALLCONV srli_all( __m128i a )
		{
			return _mm_srli_si128( a, imm8 );
		}

		// Store 128-bits (composed of 2 packed double-precision floating-point elements) from "a" into memory
		inline void XM_CALLCONV store_pd( double *mem_addr, __m128d a )
		{
			_mm_store_pd( mem_addr, a );
		}

		// Store the lower double-precision floating-point element from "a" into memory
		inline void XM_CALLCONV store_sd( double *mem_addr, __m128d a )
		{
			_mm_store_sd( mem_addr, a );
		}

		// Store 128-bits of integer data from "a" into memory. "mem_addr" must be aligned on a 16-byte boundary or a general-protection exception may be generated.
		inline void XM_CALLCONV store_all( __m128i *mem_addr, __m128i a )
		{
			_mm_store_si128( mem_addr, a );
		}

		// Store the lower double-precision floating-point element from "a" into 2 contiguous elements in memory
		inline void XM_CALLCONV store1_pd( double *mem_addr, __m128d a )
		{
			_mm_store1_pd( mem_addr, a );
		}

		// Store the upper double-precision floating-point element from "a" into memory
		inline void XM_CALLCONV storeh_pd( double *mem_addr, __m128d a )
		{
			_mm_storeh_pd( mem_addr, a );
		}

		// Store 64-bit integer from the first element of "a" into memory.
		inline void XM_CALLCONV storel_epi64( __m128i *mem_addr, __m128i a )
		{
			_mm_storel_epi64( mem_addr, a );
		}

		// Store the lower double-precision floating-point element from "a" into memory
		inline void XM_CALLCONV storel_pd( double *mem_addr, __m128d a )
		{
			_mm_storel_pd( mem_addr, a );
		}

		// Store 2 double-precision floating-point elements from "a" into memory in reverse order
		inline void XM_CALLCONV storer_pd( double *mem_addr, __m128d a )
		{
			_mm_storer_pd( mem_addr, a );
		}

		// Store 128-bits (composed of 2 packed double-precision floating-point elements) from "a" into memory
		inline void XM_CALLCONV storeu_pd( double *mem_addr, __m128d a )
		{
			_mm_storeu_pd( mem_addr, a );
		}

		// Store 128-bits of integer data from "a" into memory.	"mem_addr" does not need to be aligned on any particular boundary.
		inline void XM_CALLCONV storeu_all( __m128i *mem_addr, __m128i a )
		{
			_mm_storeu_si128( mem_addr, a );
		}

		// Store 128-bits (composed of 2 packed double-precision floating-point elements) from "a" into memory using a non-temporal memory hint
		inline void XM_CALLCONV stream_pd( double *mem_addr, __m128d a )
		{
			_mm_stream_pd( mem_addr, a );
		}

		// Store 32-bit integer "a" into memory using a non-temporal hint to minimize cache pollution
		inline void XM_CALLCONV stream_si32( int *mem_addr, int a )
		{
			_mm_stream_si32( mem_addr, a );
		}

		// Store 128-bits of integer data from "a" into memory using a non-temporal memory hint
		inline void XM_CALLCONV stream_all( __m128i *mem_addr, __m128i a )
		{
			_mm_stream_si128( mem_addr, a );
		}

		// Subtract packed 8-bit integers in "b" from packed 8-bit integers in "a"
		inline __m128i XM_CALLCONV sub_epi8( __m128i a, __m128i b )
		{
			return _mm_sub_epi8( a, b );
		}

		// Subtract packed 16-bit integers in "b" from packed 16-bit integers in "a"
		inline __m128i XM_CALLCONV sub_epi16( __m128i a, __m128i b )
		{
			return _mm_sub_epi16( a, b );
		}

		// Subtract packed 32-bit integers in "b" from packed 32-bit integers in "a"
		inline __m128i XM_CALLCONV sub_epi32( __m128i a, __m128i b )
		{
			return _mm_sub_epi32( a, b );
		}

		// Subtract packed 64-bit integers in "b" from packed 64-bit integers in "a"
		inline __m128i XM_CALLCONV sub_epi64( __m128i a, __m128i b )
		{
			return _mm_sub_epi64( a, b );
		}

		// Subtract packed double-precision floating-point elements in "b" from packed double-precision floating-point elements in "a"
		inline __m128d XM_CALLCONV sub_pd( __m128d a, __m128d b )
		{
			return _mm_sub_pd( a, b );
		}

		// Subtract the lower double-precision floating-point element in "b" from the lower double-precision floating-point element in "a"
		inline __m128d XM_CALLCONV sub_sd( __m128d a, __m128d b )
		{
			return _mm_sub_sd( a, b );
		}

		// Subtract packed 8-bit integers in "b" from packed 8-bit integers in "a" using saturation
		inline __m128i XM_CALLCONV subs_epi8( __m128i a, __m128i b )
		{
			return _mm_subs_epi8( a, b );
		}

		// Subtract packed 16-bit integers in "b" from packed 16-bit integers in "a" using saturation
		inline __m128i XM_CALLCONV subs_epi16( __m128i a, __m128i b )
		{
			return _mm_subs_epi16( a, b );
		}

		// Subtract packed unsigned 8-bit integers in "b" from packed unsigned 8-bit integers in "a" using saturation
		inline __m128i XM_CALLCONV subs_epu8( __m128i a, __m128i b )
		{
			return _mm_subs_epu8( a, b );
		}

		// Subtract packed unsigned 16-bit integers in "b" from packed unsigned 16-bit integers in "a" using saturation
		inline __m128i XM_CALLCONV subs_epu16( __m128i a, __m128i b )
		{
			return _mm_subs_epu16( a, b );
		}

		// Compare the lower double-precision floating-point element in "a" and "b" for equality
		inline int XM_CALLCONV ucomieq_sd( __m128d a, __m128d b )
		{
			return _mm_ucomieq_sd( a, b );
		}

		// Compare the lower double-precision floating-point element in "a" and "b" for greater-than-or-equal
		inline int XM_CALLCONV ucomige_sd( __m128d a, __m128d b )
		{
			return _mm_ucomige_sd( a, b );
		}

		// Compare the lower double-precision floating-point element in "a" and "b" for greater-than
		inline int XM_CALLCONV ucomigt_sd( __m128d a, __m128d b )
		{
			return _mm_ucomigt_sd( a, b );
		}

		// Compare the lower double-precision floating-point element in "a" and "b" for less-than-or-equal
		inline int XM_CALLCONV ucomile_sd( __m128d a, __m128d b )
		{
			return _mm_ucomile_sd( a, b );
		}

		// Compare the lower double-precision floating-point element in "a" and "b" for less-than
		inline int XM_CALLCONV ucomilt_sd( __m128d a, __m128d b )
		{
			return _mm_ucomilt_sd( a, b );
		}

		// Compare the lower double-precision floating-point element in "a" and "b" for not-equal
		inline int XM_CALLCONV ucomineq_sd( __m128d a, __m128d b )
		{
			return _mm_ucomineq_sd( a, b );
		}

		// Return vector of type __m128d with undefined elements.
		inline __m128d XM_CALLCONV undefined_pd()
		{
			return _mm_undefined_pd();
		}

		// Return vector of type __m128i with undefined elements.
		inline __m128i XM_CALLCONV undefined_all()
		{
			return _mm_undefined_si128();
		}

		// Unpack and interleave 8-bit integers from the high half of "a" and "b"
		inline __m128i XM_CALLCONV unpackhi_epi8( __m128i a, __m128i b )
		{
			return _mm_unpackhi_epi8( a, b );
		}

		// Unpack and interleave 16-bit integers from the high half of "a" and "b"
		inline __m128i XM_CALLCONV unpackhi_epi16( __m128i a, __m128i b )
		{
			return _mm_unpackhi_epi16( a, b );
		}

		// Unpack and interleave 32-bit integers from the high half of "a" and "b"
		inline __m128i XM_CALLCONV unpackhi_epi32( __m128i a, __m128i b )
		{
			return _mm_unpackhi_epi32( a, b );
		}

		// Unpack and interleave 64-bit integers from the high half of "a" and "b"
		inline __m128i XM_CALLCONV unpackhi_epi64( __m128i a, __m128i b )
		{
			return _mm_unpackhi_epi64( a, b );
		}

		// Unpack and interleave double-precision floating-point elements from the high half of "a" and "b"
		inline __m128d XM_CALLCONV unpackhi_pd( __m128d a, __m128d b )
		{
			return _mm_unpackhi_pd( a, b );
		}

		// Unpack and interleave 8-bit integers from the low half of "a" and "b"
		inline __m128i XM_CALLCONV unpacklo_epi8( __m128i a, __m128i b )
		{
			return _mm_unpacklo_epi8( a, b );
		}

		// Unpack and interleave 16-bit integers from the low half of "a" and "b"
		inline __m128i XM_CALLCONV unpacklo_epi16( __m128i a, __m128i b )
		{
			return _mm_unpacklo_epi16( a, b );
		}

		// Unpack and interleave 32-bit integers from the low half of "a" and "b"
		inline __m128i XM_CALLCONV unpacklo_epi32( __m128i a, __m128i b )
		{
			return _mm_unpacklo_epi32( a, b );
		}

		// Unpack and interleave 64-bit integers from the low half of "a" and "b"
		inline __m128i XM_CALLCONV unpacklo_epi64( __m128i a, __m128i b )
		{
			return _mm_unpacklo_epi64( a, b );
		}

		// Unpack and interleave double-precision floating-point elements from the low half of "a" and "b"
		inline __m128d XM_CALLCONV unpacklo_pd( __m128d a, __m128d b )
		{
			return _mm_unpacklo_pd( a, b );
		}

		// Compute the bitwise XOR of packed double-precision floating-point elements in "a" and "b"
		inline __m128d XM_CALLCONV xor_pd( __m128d a, __m128d b )
		{
			return _mm_xor_pd( a, b );
		}

		// Compute the bitwise XOR of 128 bits (representing integer data) in "a" and "b"
		inline __m128i XM_CALLCONV xor_all( __m128i a, __m128i b )
		{
			return _mm_xor_si128( a, b );
		}

#if _M_X64
		// Convert the lower double-precision floating-point element in "a" to a 64-bit integer
		inline int64_t XM_CALLCONV cvtsd_si64( __m128d a )
		{
			return (int64_t)_mm_cvtsd_si64( a );
		}

		// Convert the lower double-precision floating-point element in "a" to a 64-bit integer
		inline int64_t XM_CALLCONV cvtsd_si64x( __m128d a )
		{
			return (int64_t)_mm_cvtsd_si64x( a );
		}

		// Copy the lower 64-bit integer in "a" to "dst".
		inline int64_t XM_CALLCONV cvtsi128_si64( __m128i a )
		{
			return (int64_t)_mm_cvtsi128_si64( a );
		}

		// Copy the lower 64-bit integer in "a" to "dst".
		inline int64_t XM_CALLCONV cvtsi128_si64x( __m128i a )
		{
			return (int64_t)_mm_cvtsi128_si64x( a );
		}

		// Convert the 64-bit integer "b" to a double-precision floating-point element
		inline __m128d XM_CALLCONV cvtsi64_sd( __m128d a, int64_t b )
		{
			return _mm_cvtsi64_sd( a, (real_int64_t)b );
		}

		// Copy 64-bit integer "a" to the lower element of "dst", and zero the upper element
		inline __m128i XM_CALLCONV cvtsi64_all( int64_t a )
		{
			return _mm_cvtsi64_si128( (real_int64_t)a );
		}

		// Convert the 64-bit integer "b" to a double-precision floating-point element
		inline __m128d XM_CALLCONV cvtsi64x_sd( __m128d a, int64_t b )
		{
			return _mm_cvtsi64x_sd( a, (real_int64_t)b );
		}

		// Copy 64-bit integer "a" to the lower element of "dst", and zero the upper element
		inline __m128i XM_CALLCONV cvtsi64x_all( int64_t a )
		{
			return _mm_cvtsi64x_si128( (real_int64_t)a );
		}

		// Convert the lower double-precision floating-point element in "a" to a 64-bit integer with truncation
		inline int64_t XM_CALLCONV cvttsd_si64( __m128d a )
		{
			return (int64_t)_mm_cvttsd_si64( a );
		}

		// Convert the lower double-precision floating-point element in "a" to a 64-bit integer with truncation
		inline int64_t XM_CALLCONV cvttsd_si64x( __m128d a )
		{
			return (int64_t)_mm_cvttsd_si64x( a );
		}

		// Store 64-bit integer "a" into memory using a non-temporal hint to minimize cache pollution
		inline void XM_CALLCONV stream_si64( int64_t *mem_addr, int64_t a )
		{
			_mm_stream_si64( (real_int64_t *)mem_addr, (real_int64_t)a );
		}
#endif // _M_X64
	}	// namespace Intrinsics::Sse
}	// namespace Intrinsics
#include "Extra/sse2-extra.hpp"