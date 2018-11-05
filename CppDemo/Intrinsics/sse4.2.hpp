// This file is generated automatically by a tool. If you want to change it, fork & modify the tool instead: https://github.com/Const-me/IntelIntrinsics
#pragma once
#include <nmmintrin.h>
#include "Extra/common.hpp"

namespace Intrinsics
{
	namespace Sse
	{
		// Compare packed strings in "a" and "b" with lengths "la" and "lb" using the control in "imm8"
		template<int imm8>
		inline int XM_CALLCONV cmpestra( __m128i a, int la, __m128i b, int lb )
		{
			return _mm_cmpestra( a, la, b, lb, imm8 );
		}

		// Compare packed strings in "a" and "b" with lengths "la" and "lb" using the control in "imm8"
		template<int imm8>
		inline int XM_CALLCONV cmpestrc( __m128i a, int la, __m128i b, int lb )
		{
			return _mm_cmpestrc( a, la, b, lb, imm8 );
		}

		// Compare packed strings in "a" and "b" with lengths "la" and "lb" using the control in "imm8", and store the generated index in "dst"
		template<int imm8>
		inline int XM_CALLCONV cmpestri( __m128i a, int la, __m128i b, int lb )
		{
			return _mm_cmpestri( a, la, b, lb, imm8 );
		}

		// Compare packed strings in "a" and "b" with lengths "la" and "lb" using the control in "imm8", and store the generated mask in "dst"
		template<int imm8>
		inline __m128i XM_CALLCONV cmpestrm( __m128i a, int la, __m128i b, int lb )
		{
			return _mm_cmpestrm( a, la, b, lb, imm8 );
		}

		// Compare packed strings in "a" and "b" with lengths "la" and "lb" using the control in "imm8"
		template<int imm8>
		inline int XM_CALLCONV cmpestro( __m128i a, int la, __m128i b, int lb )
		{
			return _mm_cmpestro( a, la, b, lb, imm8 );
		}

		// Compare packed strings in "a" and "b" with lengths "la" and "lb" using the control in "imm8"
		template<int imm8>
		inline int XM_CALLCONV cmpestrs( __m128i a, int la, __m128i b, int lb )
		{
			return _mm_cmpestrs( a, la, b, lb, imm8 );
		}

		// Compare packed strings in "a" and "b" with lengths "la" and "lb" using the control in "imm8"
		template<int imm8>
		inline int XM_CALLCONV cmpestrz( __m128i a, int la, __m128i b, int lb )
		{
			return _mm_cmpestrz( a, la, b, lb, imm8 );
		}

		// Compare packed 64-bit integers in "a" and "b" for greater-than, and store the results in "dst"
		inline __m128i XM_CALLCONV cmpgt_epi64( __m128i a, __m128i b )
		{
			return _mm_cmpgt_epi64( a, b );
		}

		// Compare packed strings with implicit lengths in "a" and "b" using the control in "imm8"
		template<int imm8>
		inline int XM_CALLCONV cmpistra( __m128i a, __m128i b )
		{
			return _mm_cmpistra( a, b, imm8 );
		}

		// Compare packed strings with implicit lengths in "a" and "b" using the control in "imm8"
		template<int imm8>
		inline int XM_CALLCONV cmpistrc( __m128i a, __m128i b )
		{
			return _mm_cmpistrc( a, b, imm8 );
		}

		// Compare packed strings with implicit lengths in "a" and "b" using the control in "imm8", and store the generated index in "dst"
		template<int imm8>
		inline int XM_CALLCONV cmpistri( __m128i a, __m128i b )
		{
			return _mm_cmpistri( a, b, imm8 );
		}

		// Compare packed strings with implicit lengths in "a" and "b" using the control in "imm8", and store the generated mask in "dst"
		template<int imm8>
		inline __m128i XM_CALLCONV cmpistrm( __m128i a, __m128i b )
		{
			return _mm_cmpistrm( a, b, imm8 );
		}

		// Compare packed strings with implicit lengths in "a" and "b" using the control in "imm8"
		template<int imm8>
		inline int XM_CALLCONV cmpistro( __m128i a, __m128i b )
		{
			return _mm_cmpistro( a, b, imm8 );
		}

		// Compare packed strings with implicit lengths in "a" and "b" using the control in "imm8"
		template<int imm8>
		inline int XM_CALLCONV cmpistrs( __m128i a, __m128i b )
		{
			return _mm_cmpistrs( a, b, imm8 );
		}

		// Compare packed strings with implicit lengths in "a" and "b" using the control in "imm8"
		template<int imm8>
		inline int XM_CALLCONV cmpistrz( __m128i a, __m128i b )
		{
			return _mm_cmpistrz( a, b, imm8 );
		}

		// Starting with the initial value in "crc", accumulates a CRC32 value for unsigned 8-bit integer "v", and stores the result in "dst"
		inline uint32_t XM_CALLCONV crc32_u8( uint32_t crc, uint8_t v )
		{
			return _mm_crc32_u8( crc, v );
		}

		// Starting with the initial value in "crc", accumulates a CRC32 value for unsigned 16-bit integer "v", and stores the result in "dst"
		inline uint32_t XM_CALLCONV crc32_u16( uint32_t crc, uint16_t v )
		{
			return _mm_crc32_u16( crc, v );
		}

		// Starting with the initial value in "crc", accumulates a CRC32 value for unsigned 32-bit integer "v", and stores the result in "dst"
		inline uint32_t XM_CALLCONV crc32_u32( uint32_t crc, uint32_t v )
		{
			return _mm_crc32_u32( crc, v );
		}

#if _M_X64
		// Starting with the initial value in "crc", accumulates a CRC32 value for unsigned 64-bit integer "v", and stores the result in "dst"
		inline uint64_t XM_CALLCONV crc32_u64( uint64_t crc, uint64_t v )
		{
			return (uint64_t)_mm_crc32_u64( (real_uint64_t)crc, (real_uint64_t)v );
		}
#endif // _M_X64
	}	// namespace Intrinsics::Sse
}	// namespace Intrinsics
#include "Extra/sse4.2-extra.hpp"