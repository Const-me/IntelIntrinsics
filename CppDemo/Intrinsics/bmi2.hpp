// This file is generated automatically by a tool. If you want to change it, fork & modify the tool instead: https://github.com/Const-me/IntelIntrinsics
#pragma once
#include <immintrin.h>
#include "Extra/common.hpp"

namespace Intrinsics
{
	namespace Misc
	{
		// Copy all bits from unsigned 32-bit integer "a" to "dst", and reset (set to 0) the high bits in "dst" starting at "index"
		inline uint32_t _bzhi_u32( uint32_t a, uint32_t index )
		{
			return _bzhi_u32( a, index );
		}

		// Copy all bits from unsigned 64-bit integer "a" to "dst", and reset (set to 0) the high bits in "dst" starting at "index"
		inline uint64_t _bzhi_u64( uint64_t a, uint32_t index )
		{
			return (uint64_t)_bzhi_u64( (real_uint64_t)a, index );
		}

		// Multiply unsigned 32-bit integers "a" and "b", store the low 32-bits of the result in "dst", and store the high 32-bits in "hi"
		inline uint32_t _mulx_u32( uint32_t a, uint32_t b, uint32_t *hi )
		{
			return _mulx_u32( a, b, hi );
		}

		// Multiply unsigned 64-bit integers "a" and "b", store the low 64-bits of the result in "dst", and store the high 64-bits in "hi"
		inline uint64_t _mulx_u64( uint64_t a, uint64_t b, uint64_t *hi )
		{
			return (uint64_t)_mulx_u64( (real_uint64_t)a, (real_uint64_t)b, (real_uint64_t *)hi );
		}

		// Deposit contiguous low bits from unsigned 32-bit integer "a" to "dst" at the corresponding bit locations specified by "mask"
		inline uint32_t _pdep_u32( uint32_t a, uint32_t mask )
		{
			return _pdep_u32( a, mask );
		}

		// Deposit contiguous low bits from unsigned 64-bit integer "a" to "dst" at the corresponding bit locations specified by "mask"
		inline uint64_t _pdep_u64( uint64_t a, uint64_t mask )
		{
			return (uint64_t)_pdep_u64( (real_uint64_t)a, (real_uint64_t)mask );
		}

		// Extract bits from unsigned 32-bit integer "a" at the corresponding bit locations specified by "mask" to contiguous low bits in "dst"
		inline uint32_t _pext_u32( uint32_t a, uint32_t mask )
		{
			return _pext_u32( a, mask );
		}

		// Extract bits from unsigned 64-bit integer "a" at the corresponding bit locations specified by "mask" to contiguous low bits in "dst"
		inline uint64_t _pext_u64( uint64_t a, uint64_t mask )
		{
			return (uint64_t)_pext_u64( (real_uint64_t)a, (real_uint64_t)mask );
		}
	}	// namespace Intrinsics::Misc
}	// namespace Intrinsics