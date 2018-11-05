// This file is generated automatically by a tool. If you want to change it, fork & modify the tool instead: https://github.com/Const-me/IntelIntrinsics
#pragma once
#include <immintrin.h>
#include "Extra/common.hpp"

namespace Intrinsics
{
	namespace Sse
	{
		// Perform an intermediate calculation for the next four SHA1 message values (unsigned 32-bit integers) using previous message values from "a" and "b"
		inline __m128i XM_CALLCONV sha1msg1_epu32( __m128i a, __m128i b )
		{
			return _mm_sha1msg1_epu32( a, b );
		}

		// Perform the final calculation for the next four SHA1 message values (unsigned 32-bit integers) using the intermediate result in "a" and the previous message values in "b"
		inline __m128i XM_CALLCONV sha1msg2_epu32( __m128i a, __m128i b )
		{
			return _mm_sha1msg2_epu32( a, b );
		}

		// Calculate SHA1 state variable E after four rounds of operation from the current SHA1 state variable "a", add that value to the scheduled values (unsigned 32-bit integers) in "b"
		inline __m128i XM_CALLCONV sha1nexte_epu32( __m128i a, __m128i b )
		{
			return _mm_sha1nexte_epu32( a, b );
		}

		// Perform four rounds of SHA1 operation using an initial SHA1 state (A,B,C,D) from "a" and some pre-computed sum of the next 4 round message values (unsigned 32-bit integers), and state variable E from "b", and store the updated SHA1 state (A,B,C,D) in "dst"
		template<int func>
		inline __m128i XM_CALLCONV sha1rnds4_epu32( __m128i a, __m128i b )
		{
			return _mm_sha1rnds4_epu32( a, b, func );
		}

		// Perform an intermediate calculation for the next four SHA256 message values (unsigned 32-bit integers) using previous message values from "a" and "b"
		inline __m128i XM_CALLCONV sha256msg1_epu32( __m128i a, __m128i b )
		{
			return _mm_sha256msg1_epu32( a, b );
		}

		// Perform the final calculation for the next four SHA256 message values (unsigned 32-bit integers) using previous message values from "a" and "b"
		inline __m128i XM_CALLCONV sha256msg2_epu32( __m128i a, __m128i b )
		{
			return _mm_sha256msg2_epu32( a, b );
		}

		// Perform 2 rounds of SHA256 operation using an initial SHA256 state (C,D,G,H) from "a", an initial SHA256 state (A,B,E,F) from "b", and a pre-computed sum of the next 2 round message values (unsigned 32-bit integers) and the corresponding round constants from "k", and store the updated SHA256 state (A,B,E,F) in "dst"
		inline __m128i XM_CALLCONV sha256rnds2_epu32( __m128i a, __m128i b, __m128i k )
		{
			return _mm_sha256rnds2_epu32( a, b, k );
		}
	}	// namespace Intrinsics::Sse
}	// namespace Intrinsics