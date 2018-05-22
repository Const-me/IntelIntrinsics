#pragma once
#include "sse2.hpp"
#include "Implementation/utils.hpp"

namespace Intrinsics
{
	namespace Sse
	{
#include "Implementation/operators_int.inl"
#include "Implementation/operators_float64.inl"

		// Shuffle double-precision floating-point elements using the control in template arguments
		template<uint8_t c1, uint8_t c2>
		inline VecFloat64 XM_CALLCONV shuffle_pd( VecFloat64 a, VecFloat64 b )
		{
			static_assert( c1 < 2 && c2 < 2, "Shuffle constants out of range" );
			constexpr int imm = (int)c1 | (int)( c2 << 1 );
			return shuffle_pd<imm>( a, b );
		}
	}
}