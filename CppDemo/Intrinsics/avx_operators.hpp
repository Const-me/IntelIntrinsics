#pragma once
#include "avx.hpp"
#include "Implementation/utils.hpp"

namespace Intrinsics
{
	namespace Avx
	{
#include "Implementation/operators_float32.inl"
#include "Implementation/operators_float64.inl"

		// Shuffle double-precision (64-bit) floating-point elements within 128-bit lanes using the control in template arguments
		template<uint8_t c1, uint8_t c2, uint8_t c3, uint8_t c4>
		inline VecFloat64 XM_CALLCONV shuffle_pd( VecFloat64 a, VecFloat64 b )
		{
			static_assert( c1 < 2 && c2 < 2 && c3 < 2 && c4 < 2, "Shuffle constants out of range" );
			constexpr int imm = (int)c1 | (int)( c2 << 1 ) | (int)( c3 << 2 ) | (int)( c4 << 3 );
			return shuffle_pd<imm>( a, b );
		}
	}
}