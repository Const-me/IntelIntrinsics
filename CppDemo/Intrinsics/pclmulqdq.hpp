// This file is generated automatically by a tool. If you want to change it, fork & modify the tool instead: https://github.com/Const-me/IntelIntrinsics
#pragma once
#include <wmmintrin.h>
#include "Extra/common.hpp"

namespace Intrinsics
{
	namespace Sse
	{
		// Perform a carry-less multiplication of two 64-bit integers, selected from "a" and "b" according to "imm8"
		template<int imm8>
		inline __m128i XM_CALLCONV clmulepi64_all( __m128i a, __m128i b )
		{
			return _mm_clmulepi64_si128( a, b, imm8 );
		}
	}	// namespace Intrinsics::Sse
}	// namespace Intrinsics