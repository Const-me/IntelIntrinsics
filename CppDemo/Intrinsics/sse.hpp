// This file is generated automatically by a tool. If you want to change it, fork & modify the tool instead: https://github.com/Const-me/IntelIntrinsics
#pragma once
#include <xmmintrin.h>
#include <immintrin.h>
#include "Extra/common.hpp"

namespace Intrinsics
{
	namespace Sse
	{
		// Add packed single-precision floating-point elements in "a" and "b"
		inline __m128 XM_CALLCONV add_ps( __m128 a, __m128 b )
		{
			return _mm_add_ps( a, b );
		}

		// Add the lower single-precision floating-point element in "a" and "b"
		inline __m128 XM_CALLCONV add_ss( __m128 a, __m128 b )
		{
			return _mm_add_ss( a, b );
		}

		// Compute the bitwise AND of packed single-precision floating-point elements in "a" and "b"
		inline __m128 XM_CALLCONV and_ps( __m128 a, __m128 b )
		{
			return _mm_and_ps( a, b );
		}

		// Compute the bitwise NOT of packed single-precision floating-point elements in "a" and then AND with "b"
		inline __m128 XM_CALLCONV andnot_ps( __m128 a, __m128 b )
		{
			return _mm_andnot_ps( a, b );
		}

		// Compare packed single-precision floating-point elements in "a" and "b" for equality
		inline __m128 XM_CALLCONV cmpeq_ps( __m128 a, __m128 b )
		{
			return _mm_cmpeq_ps( a, b );
		}

		// Compare the lower single-precision floating-point elements in "a" and "b" for equality
		inline __m128 XM_CALLCONV cmpeq_ss( __m128 a, __m128 b )
		{
			return _mm_cmpeq_ss( a, b );
		}

		// Compare packed single-precision floating-point elements in "a" and "b" for greater-than-or-equal
		inline __m128 XM_CALLCONV cmpge_ps( __m128 a, __m128 b )
		{
			return _mm_cmpge_ps( a, b );
		}

		// Compare the lower single-precision floating-point elements in "a" and "b" for greater-than-or-equal
		inline __m128 XM_CALLCONV cmpge_ss( __m128 a, __m128 b )
		{
			return _mm_cmpge_ss( a, b );
		}

		// Compare packed single-precision floating-point elements in "a" and "b" for greater-than
		inline __m128 XM_CALLCONV cmpgt_ps( __m128 a, __m128 b )
		{
			return _mm_cmpgt_ps( a, b );
		}

		// Compare the lower single-precision floating-point elements in "a" and "b" for greater-than
		inline __m128 XM_CALLCONV cmpgt_ss( __m128 a, __m128 b )
		{
			return _mm_cmpgt_ss( a, b );
		}

		// Compare packed single-precision floating-point elements in "a" and "b" for less-than-or-equal
		inline __m128 XM_CALLCONV cmple_ps( __m128 a, __m128 b )
		{
			return _mm_cmple_ps( a, b );
		}

		// Compare the lower single-precision floating-point elements in "a" and "b" for less-than-or-equal
		inline __m128 XM_CALLCONV cmple_ss( __m128 a, __m128 b )
		{
			return _mm_cmple_ss( a, b );
		}

		// Compare packed single-precision floating-point elements in "a" and "b" for less-than
		inline __m128 XM_CALLCONV cmplt_ps( __m128 a, __m128 b )
		{
			return _mm_cmplt_ps( a, b );
		}

		// Compare the lower single-precision floating-point elements in "a" and "b" for less-than
		inline __m128 XM_CALLCONV cmplt_ss( __m128 a, __m128 b )
		{
			return _mm_cmplt_ss( a, b );
		}

		// Compare packed single-precision floating-point elements in "a" and "b" for not-equal
		inline __m128 XM_CALLCONV cmpneq_ps( __m128 a, __m128 b )
		{
			return _mm_cmpneq_ps( a, b );
		}

		// Compare the lower single-precision floating-point elements in "a" and "b" for not-equal
		inline __m128 XM_CALLCONV cmpneq_ss( __m128 a, __m128 b )
		{
			return _mm_cmpneq_ss( a, b );
		}

		// Compare packed single-precision floating-point elements in "a" and "b" for not-greater-than-or-equal
		inline __m128 XM_CALLCONV cmpnge_ps( __m128 a, __m128 b )
		{
			return _mm_cmpnge_ps( a, b );
		}

		// Compare the lower single-precision floating-point elements in "a" and "b" for not-greater-than-or-equal
		inline __m128 XM_CALLCONV cmpnge_ss( __m128 a, __m128 b )
		{
			return _mm_cmpnge_ss( a, b );
		}

		// Compare packed single-precision floating-point elements in "a" and "b" for not-greater-than
		inline __m128 XM_CALLCONV cmpngt_ps( __m128 a, __m128 b )
		{
			return _mm_cmpngt_ps( a, b );
		}

		// Compare the lower single-precision floating-point elements in "a" and "b" for not-greater-than
		inline __m128 XM_CALLCONV cmpngt_ss( __m128 a, __m128 b )
		{
			return _mm_cmpngt_ss( a, b );
		}

		// Compare packed single-precision floating-point elements in "a" and "b" for not-less-than-or-equal
		inline __m128 XM_CALLCONV cmpnle_ps( __m128 a, __m128 b )
		{
			return _mm_cmpnle_ps( a, b );
		}

		// Compare the lower single-precision floating-point elements in "a" and "b" for not-less-than-or-equal
		inline __m128 XM_CALLCONV cmpnle_ss( __m128 a, __m128 b )
		{
			return _mm_cmpnle_ss( a, b );
		}

		// Compare packed single-precision floating-point elements in "a" and "b" for not-less-than
		inline __m128 XM_CALLCONV cmpnlt_ps( __m128 a, __m128 b )
		{
			return _mm_cmpnlt_ps( a, b );
		}

		// Compare the lower single-precision floating-point elements in "a" and "b" for not-less-than
		inline __m128 XM_CALLCONV cmpnlt_ss( __m128 a, __m128 b )
		{
			return _mm_cmpnlt_ss( a, b );
		}

		// Compare packed single-precision floating-point elements in "a" and "b" to see if neither is NaN
		inline __m128 XM_CALLCONV cmpord_ps( __m128 a, __m128 b )
		{
			return _mm_cmpord_ps( a, b );
		}

		// Compare the lower single-precision floating-point elements in "a" and "b" to see if neither is NaN
		inline __m128 XM_CALLCONV cmpord_ss( __m128 a, __m128 b )
		{
			return _mm_cmpord_ss( a, b );
		}

		// Compare packed single-precision floating-point elements in "a" and "b" to see if either is NaN
		inline __m128 XM_CALLCONV cmpunord_ps( __m128 a, __m128 b )
		{
			return _mm_cmpunord_ps( a, b );
		}

		// Compare the lower single-precision floating-point elements in "a" and "b" to see if either is NaN
		inline __m128 XM_CALLCONV cmpunord_ss( __m128 a, __m128 b )
		{
			return _mm_cmpunord_ss( a, b );
		}

		// Compare the lower single-precision floating-point element in "a" and "b" for equality
		inline int XM_CALLCONV comieq_ss( __m128 a, __m128 b )
		{
			return _mm_comieq_ss( a, b );
		}

		// Compare the lower single-precision floating-point element in "a" and "b" for greater-than-or-equal
		inline int XM_CALLCONV comige_ss( __m128 a, __m128 b )
		{
			return _mm_comige_ss( a, b );
		}

		// Compare the lower single-precision floating-point element in "a" and "b" for greater-than
		inline int XM_CALLCONV comigt_ss( __m128 a, __m128 b )
		{
			return _mm_comigt_ss( a, b );
		}

		// Compare the lower single-precision floating-point element in "a" and "b" for less-than-or-equal
		inline int XM_CALLCONV comile_ss( __m128 a, __m128 b )
		{
			return _mm_comile_ss( a, b );
		}

		// Compare the lower single-precision floating-point element in "a" and "b" for less-than
		inline int XM_CALLCONV comilt_ss( __m128 a, __m128 b )
		{
			return _mm_comilt_ss( a, b );
		}

		// Compare the lower single-precision floating-point element in "a" and "b" for not-equal
		inline int XM_CALLCONV comineq_ss( __m128 a, __m128 b )
		{
			return _mm_comineq_ss( a, b );
		}

		// Convert the 32-bit integer "b" to a single-precision floating-point element
		inline __m128 XM_CALLCONV cvt_si2ss( __m128 a, int b )
		{
			return _mm_cvt_si2ss( a, b );
		}

		// Convert the lower single-precision floating-point element in "a" to a 32-bit integer
		inline int XM_CALLCONV cvt_ss2si( __m128 a )
		{
			return _mm_cvt_ss2si( a );
		}

		// Convert the 32-bit integer "b" to a single-precision floating-point element
		inline __m128 XM_CALLCONV cvtsi32_ss( __m128 a, int b )
		{
			return _mm_cvtsi32_ss( a, b );
		}

		// Copy the lower single-precision floating-point element of "a" to "dst"
		inline float XM_CALLCONV cvtss_f32( __m128 a )
		{
			return _mm_cvtss_f32( a );
		}

		// Convert the lower single-precision floating-point element in "a" to a 32-bit integer
		inline int XM_CALLCONV cvtss_si32( __m128 a )
		{
			return _mm_cvtss_si32( a );
		}

		// Convert the lower single-precision floating-point element in "a" to a 32-bit integer with truncation
		inline int XM_CALLCONV cvtt_ss2si( __m128 a )
		{
			return _mm_cvtt_ss2si( a );
		}

		// Convert the lower single-precision floating-point element in "a" to a 32-bit integer with truncation
		inline int XM_CALLCONV cvttss_si32( __m128 a )
		{
			return _mm_cvttss_si32( a );
		}

		// Divide packed single-precision floating-point elements in "a" by packed elements in "b"
		inline __m128 XM_CALLCONV div_ps( __m128 a, __m128 b )
		{
			return _mm_div_ps( a, b );
		}

		// Divide the lower single-precision floating-point element in "a" by the lower single-precision floating-point element in "b"
		inline __m128 XM_CALLCONV div_ss( __m128 a, __m128 b )
		{
			return _mm_div_ss( a, b );
		}

		// Get the unsigned 32-bit value of the MXCSR control and status register
		inline uint32_t XM_CALLCONV getcsr()
		{
			return _mm_getcsr();
		}

		// Load 128-bits (composed of 4 packed single-precision floating-point elements) from memory into "dst"
		inline __m128 XM_CALLCONV load_ps( const float *mem_addr )
		{
			return _mm_load_ps( mem_addr );
		}

		// Load a single-precision floating-point element from memory into all elements of "dst"
		inline __m128 XM_CALLCONV load_ps1( const float *mem_addr )
		{
			return _mm_load_ps1( mem_addr );
		}

		// Load a single-precision floating-point element from memory into the lower of "dst", and zero the upper 3 elements
		inline __m128 XM_CALLCONV load_ss( const float *mem_addr )
		{
			return _mm_load_ss( mem_addr );
		}

		// Load a single-precision floating-point element from memory into all elements of "dst"
		inline __m128 XM_CALLCONV load1_ps( const float *mem_addr )
		{
			return _mm_load1_ps( mem_addr );
		}

		// Load 2 single-precision floating-point elements from memory into the upper 2 elements of "dst", and copy the lower 2 elements from "a" to "dst"
		inline __m128 XM_CALLCONV loadh_pi( __m128 a, const __m64 *mem_addr )
		{
			return _mm_loadh_pi( a, mem_addr );
		}

		// Load 2 single-precision floating-point elements from memory into the lower 2 elements of "dst", and copy the upper 2 elements from "a" to "dst"
		inline __m128 XM_CALLCONV loadl_pi( __m128 a, const __m64 *mem_addr )
		{
			return _mm_loadl_pi( a, mem_addr );
		}

		// Load 4 single-precision floating-point elements from memory into "dst" in reverse order
		inline __m128 XM_CALLCONV loadr_ps( const float *mem_addr )
		{
			return _mm_loadr_ps( mem_addr );
		}

		// Load 128-bits (composed of 4 packed single-precision floating-point elements) from memory into "dst"
		inline __m128 XM_CALLCONV loadu_ps( const float *mem_addr )
		{
			return _mm_loadu_ps( mem_addr );
		}

		// Compare packed single-precision floating-point elements in "a" and "b", and store packed maximum values in "dst"
		inline __m128 XM_CALLCONV max_ps( __m128 a, __m128 b )
		{
			return _mm_max_ps( a, b );
		}

		// Compare the lower single-precision floating-point elements in "a" and "b", store the maximum value in the lower element of "dst", and copy the upper element from "a" to the upper element of "dst"
		inline __m128 XM_CALLCONV max_ss( __m128 a, __m128 b )
		{
			return _mm_max_ss( a, b );
		}

		// Compare packed single-precision floating-point elements in "a" and "b", and store packed minimum values in "dst"
		inline __m128 XM_CALLCONV min_ps( __m128 a, __m128 b )
		{
			return _mm_min_ps( a, b );
		}

		// Compare the lower single-precision floating-point elements in "a" and "b", store the minimum value in the lower element of "dst", and copy the upper element from "a" to the upper element of "dst"
		inline __m128 XM_CALLCONV min_ss( __m128 a, __m128 b )
		{
			return _mm_min_ss( a, b );
		}

		// Move the lower single-precision floating-point element from "b" to the lower element of "dst", and copy the upper 3 elements from "a" to the upper elements of "dst"
		inline __m128 XM_CALLCONV move_ss( __m128 a, __m128 b )
		{
			return _mm_move_ss( a, b );
		}

		// Move the upper 2 single-precision floating-point elements from "b" to the lower 2 elements of "dst", and copy the upper 2 elements from "a" to the upper 2 elements of "dst"
		inline __m128 XM_CALLCONV movehl_ps( __m128 a, __m128 b )
		{
			return _mm_movehl_ps( a, b );
		}

		// Move the lower 2 single-precision floating-point elements from "b" to the upper 2 elements of "dst", and copy the lower 2 elements from "a" to the lower 2 elements of "dst"
		inline __m128 XM_CALLCONV movelh_ps( __m128 a, __m128 b )
		{
			return _mm_movelh_ps( a, b );
		}

		// Set each bit of mask "dst" based on the most significant bit of the corresponding packed single-precision floating-point element in "a"
		inline int XM_CALLCONV movemask_ps( __m128 a )
		{
			return _mm_movemask_ps( a );
		}

		// Multiply packed single-precision floating-point elements in "a" and "b"
		inline __m128 XM_CALLCONV mul_ps( __m128 a, __m128 b )
		{
			return _mm_mul_ps( a, b );
		}

		// Multiply the lower single-precision floating-point element in "a" and "b"
		inline __m128 XM_CALLCONV mul_ss( __m128 a, __m128 b )
		{
			return _mm_mul_ss( a, b );
		}

		// Compute the bitwise OR of packed single-precision floating-point elements in "a" and "b"
		inline __m128 XM_CALLCONV or_ps( __m128 a, __m128 b )
		{
			return _mm_or_ps( a, b );
		}

		// Compute the approximate reciprocal of packed single-precision floating-point elements in "a"
		inline __m128 XM_CALLCONV rcp_ps( __m128 a )
		{
			return _mm_rcp_ps( a );
		}

		// Compute the approximate reciprocal of the lower single-precision floating-point element in "a"
		inline __m128 XM_CALLCONV rcp_ss( __m128 a )
		{
			return _mm_rcp_ss( a );
		}

		// Compute the approximate reciprocal square root of packed single-precision floating-point elements in "a"
		inline __m128 XM_CALLCONV rsqrt_ps( __m128 a )
		{
			return _mm_rsqrt_ps( a );
		}

		// Compute the approximate reciprocal square root of the lower single-precision floating-point element in "a"
		inline __m128 XM_CALLCONV rsqrt_ss( __m128 a )
		{
			return _mm_rsqrt_ss( a );
		}

		// Set packed single-precision floating-point elements in "dst" with the supplied values
		inline __m128 XM_CALLCONV set_ps( float e0, float e1, float e2, float e3 )
		{
			return _mm_set_ps( e3, e2, e1, e0 );
		}

		// Broadcast single-precision floating-point value "a" to all elements of "dst"
		inline __m128 XM_CALLCONV set_ps1( float a )
		{
			return _mm_set_ps1( a );
		}

		// Copy single-precision floating-point element "a" to the lower element of "dst", and zero the upper 3 elements
		inline __m128 XM_CALLCONV set_ss( float a )
		{
			return _mm_set_ss( a );
		}

		// Broadcast single-precision floating-point value "a" to all elements of "dst"
		inline __m128 XM_CALLCONV set1_ps( float a )
		{
			return _mm_set1_ps( a );
		}

		// Set the MXCSR control and status register with the value in unsigned 32-bit integer "a"
		inline void XM_CALLCONV setcsr( uint32_t a )
		{
			_mm_setcsr( a );
		}

		// Return vector of type __m128 with all elements set to zero.
		inline __m128 XM_CALLCONV setzero_ps()
		{
			return _mm_setzero_ps();
		}

		// Shuffle single-precision floating-point elements in "a" using the control in "imm8"
		template<uint32_t imm8>
		inline __m128 XM_CALLCONV shuffle_ps( __m128 a, __m128 b )
		{
			return _mm_shuffle_ps( a, b, imm8 );
		}

		// Compute the square root of packed single-precision floating-point elements in "a"
		inline __m128 XM_CALLCONV sqrt_ps( __m128 a )
		{
			return _mm_sqrt_ps( a );
		}

		// Compute the square root of the lower single-precision floating-point element in "a"
		inline __m128 XM_CALLCONV sqrt_ss( __m128 a )
		{
			return _mm_sqrt_ss( a );
		}

		// Store 128-bits (composed of 4 packed single-precision floating-point elements) from "a" into memory
		inline void XM_CALLCONV store_ps( float *mem_addr, __m128 a )
		{
			_mm_store_ps( mem_addr, a );
		}

		// Store the lower single-precision floating-point element from "a" into 4 contiguous elements in memory
		inline void XM_CALLCONV store_ps1( float *mem_addr, __m128 a )
		{
			_mm_store_ps1( mem_addr, a );
		}

		// Store the lower single-precision floating-point element from "a" into memory
		inline void XM_CALLCONV store_ss( float *mem_addr, __m128 a )
		{
			_mm_store_ss( mem_addr, a );
		}

		// Store the lower single-precision floating-point element from "a" into 4 contiguous elements in memory
		inline void XM_CALLCONV store1_ps( float *mem_addr, __m128 a )
		{
			_mm_store1_ps( mem_addr, a );
		}

		// Store the upper 2 single-precision floating-point elements from "a" into memory
		inline void XM_CALLCONV storeh_pi( __m64 *mem_addr, __m128 a )
		{
			_mm_storeh_pi( mem_addr, a );
		}

		// Store the lower 2 single-precision floating-point elements from "a" into memory
		inline void XM_CALLCONV storel_pi( __m64 *mem_addr, __m128 a )
		{
			_mm_storel_pi( mem_addr, a );
		}

		// Store 4 single-precision floating-point elements from "a" into memory in reverse order
		inline void XM_CALLCONV storer_ps( float *mem_addr, __m128 a )
		{
			_mm_storer_ps( mem_addr, a );
		}

		// Store 128-bits (composed of 4 packed single-precision floating-point elements) from "a" into memory
		inline void XM_CALLCONV storeu_ps( float *mem_addr, __m128 a )
		{
			_mm_storeu_ps( mem_addr, a );
		}

		// Store 128-bits (composed of 4 packed single-precision floating-point elements) from "a" into memory using a non-temporal memory hint
		inline void XM_CALLCONV stream_ps( float *mem_addr, __m128 a )
		{
			_mm_stream_ps( mem_addr, a );
		}

		// Subtract packed single-precision floating-point elements in "b" from packed single-precision floating-point elements in "a"
		inline __m128 XM_CALLCONV sub_ps( __m128 a, __m128 b )
		{
			return _mm_sub_ps( a, b );
		}

		// Subtract the lower single-precision floating-point element in "b" from the lower single-precision floating-point element in "a"
		inline __m128 XM_CALLCONV sub_ss( __m128 a, __m128 b )
		{
			return _mm_sub_ss( a, b );
		}

		// Compare the lower single-precision floating-point element in "a" and "b" for equality
		inline int XM_CALLCONV ucomieq_ss( __m128 a, __m128 b )
		{
			return _mm_ucomieq_ss( a, b );
		}

		// Compare the lower single-precision floating-point element in "a" and "b" for greater-than-or-equal
		inline int XM_CALLCONV ucomige_ss( __m128 a, __m128 b )
		{
			return _mm_ucomige_ss( a, b );
		}

		// Compare the lower single-precision floating-point element in "a" and "b" for greater-than
		inline int XM_CALLCONV ucomigt_ss( __m128 a, __m128 b )
		{
			return _mm_ucomigt_ss( a, b );
		}

		// Compare the lower single-precision floating-point element in "a" and "b" for less-than-or-equal
		inline int XM_CALLCONV ucomile_ss( __m128 a, __m128 b )
		{
			return _mm_ucomile_ss( a, b );
		}

		// Compare the lower single-precision floating-point element in "a" and "b" for less-than
		inline int XM_CALLCONV ucomilt_ss( __m128 a, __m128 b )
		{
			return _mm_ucomilt_ss( a, b );
		}

		// Compare the lower single-precision floating-point element in "a" and "b" for not-equal
		inline int XM_CALLCONV ucomineq_ss( __m128 a, __m128 b )
		{
			return _mm_ucomineq_ss( a, b );
		}

		// Return vector of type __m128 with undefined elements.
		inline __m128 XM_CALLCONV undefined_ps()
		{
			return _mm_undefined_ps();
		}

		// Unpack and interleave single-precision floating-point elements from the high half "a" and "b"
		inline __m128 XM_CALLCONV unpackhi_ps( __m128 a, __m128 b )
		{
			return _mm_unpackhi_ps( a, b );
		}

		// Unpack and interleave single-precision floating-point elements from the low half of "a" and "b"
		inline __m128 XM_CALLCONV unpacklo_ps( __m128 a, __m128 b )
		{
			return _mm_unpacklo_ps( a, b );
		}

		// Compute the bitwise XOR of packed single-precision floating-point elements in "a" and "b"
		inline __m128 XM_CALLCONV xor_ps( __m128 a, __m128 b )
		{
			return _mm_xor_ps( a, b );
		}

#if _M_X64
		// Convert the 64-bit integer "b" to a single-precision floating-point element
		inline __m128 XM_CALLCONV cvtsi64_ss( __m128 a, int64_t b )
		{
			return _mm_cvtsi64_ss( a, (real_int64_t)b );
		}

		// Convert the lower single-precision floating-point element in "a" to a 64-bit integer
		inline int64_t XM_CALLCONV cvtss_si64( __m128 a )
		{
			return (int64_t)_mm_cvtss_si64( a );
		}

		// Convert the lower single-precision floating-point element in "a" to a 64-bit integer with truncation
		inline int64_t XM_CALLCONV cvttss_si64( __m128 a )
		{
			return (int64_t)_mm_cvttss_si64( a );
		}
#endif // _M_X64
	}	// namespace Intrinsics::Sse
}	// namespace Intrinsics
#include "Extra/sse-extra.hpp"