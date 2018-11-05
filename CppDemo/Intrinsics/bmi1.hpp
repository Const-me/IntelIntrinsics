// This file is generated automatically by a tool. If you want to change it, fork & modify the tool instead: https://github.com/Const-me/IntelIntrinsics
#pragma once
#include <immintrin.h>
#include "Extra/common.hpp"

namespace Intrinsics
{
	namespace Misc
	{
		// Compute the bitwise NOT of 32-bit integer "a" and then AND with b
		inline uint32_t _andn_u32( uint32_t a, uint32_t b )
		{
			return _andn_u32( a, b );
		}

		// Compute the bitwise NOT of 64-bit integer "a" and then AND with b
		inline uint64_t _andn_u64( uint64_t a, uint64_t b )
		{
			return (uint64_t)_andn_u64( (real_uint64_t)a, (real_uint64_t)b );
		}

		// Extract contiguous bits from unsigned 32-bit integer "a", and store the result in "dst"
		inline uint32_t _bextr_u32( uint32_t a, uint32_t start, uint32_t len )
		{
			return _bextr_u32( a, start, len );
		}

		// Extract contiguous bits from unsigned 64-bit integer "a", and store the result in "dst"
		inline uint64_t _bextr_u64( uint64_t a, uint32_t start, uint32_t len )
		{
			return (uint64_t)_bextr_u64( (real_uint64_t)a, start, len );
		}

		// Extract contiguous bits from unsigned 32-bit integer "a", and store the result in "dst"
		inline uint32_t _bextr2_u32( uint32_t a, uint32_t control )
		{
			return _bextr2_u32( a, control );
		}

		// Extract contiguous bits from unsigned 64-bit integer "a", and store the result in "dst"
		inline uint64_t _bextr2_u64( uint64_t a, uint64_t control )
		{
			return (uint64_t)_bextr2_u64( (real_uint64_t)a, (real_uint64_t)control );
		}

		// Extract the lowest set bit from unsigned 32-bit integer "a" and set the corresponding bit in "dst"
		inline uint32_t _blsi_u32( uint32_t a )
		{
			return _blsi_u32( a );
		}

		// Extract the lowest set bit from unsigned 64-bit integer "a" and set the corresponding bit in "dst"
		inline uint64_t _blsi_u64( uint64_t a )
		{
			return (uint64_t)_blsi_u64( (real_uint64_t)a );
		}

		// Set all the lower bits of "dst" up to and including the lowest set bit in unsigned 32-bit integer "a"
		inline uint32_t _blsmsk_u32( uint32_t a )
		{
			return _blsmsk_u32( a );
		}

		// Set all the lower bits of "dst" up to and including the lowest set bit in unsigned 64-bit integer "a"
		inline uint64_t _blsmsk_u64( uint64_t a )
		{
			return (uint64_t)_blsmsk_u64( (real_uint64_t)a );
		}

		// Copy all bits from unsigned 32-bit integer "a" to "dst", and reset (set to 0) the bit in "dst" that corresponds to the lowest set bit in "a"
		inline uint32_t _blsr_u32( uint32_t a )
		{
			return _blsr_u32( a );
		}

		// Copy all bits from unsigned 64-bit integer "a" to "dst", and reset (set to 0) the bit in "dst" that corresponds to the lowest set bit in "a"
		inline uint64_t _blsr_u64( uint64_t a )
		{
			return (uint64_t)_blsr_u64( (real_uint64_t)a );
		}

		// Count the number of trailing zero bits in unsigned 32-bit integer "a"
		inline uint32_t _tzcnt_u32( uint32_t a )
		{
			return _tzcnt_u32( a );
		}

		// Count the number of trailing zero bits in unsigned 64-bit integer "a"
		inline uint64_t _tzcnt_u64( uint64_t a )
		{
			return (uint64_t)_tzcnt_u64( (real_uint64_t)a );
		}
	}	// namespace Intrinsics::Misc
}	// namespace Intrinsics