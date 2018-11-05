// This file is generated automatically by a tool. If you want to change it, fork & modify the tool instead: https://github.com/Const-me/IntelIntrinsics
#pragma once
#include <wmmintrin.h>
#include "Extra/common.hpp"

namespace Intrinsics
{
	namespace Sse
	{
		// Perform one round of an AES decryption flow on data (state) in "a" using the round key in "RoundKey"
		inline __m128i XM_CALLCONV aesdec( __m128i a, __m128i RoundKey )
		{
			return _mm_aesdec_si128( a, RoundKey );
		}

		// Perform the last round of an AES decryption flow on data (state) in "a" using the round key in "RoundKey"
		inline __m128i XM_CALLCONV aesdeclast( __m128i a, __m128i RoundKey )
		{
			return _mm_aesdeclast_si128( a, RoundKey );
		}

		// Perform one round of an AES encryption flow on data (state) in "a" using the round key in "RoundKey"
		inline __m128i XM_CALLCONV aesenc( __m128i a, __m128i RoundKey )
		{
			return _mm_aesenc_si128( a, RoundKey );
		}

		// Perform the last round of an AES encryption flow on data (state) in "a" using the round key in "RoundKey"
		inline __m128i XM_CALLCONV aesenclast( __m128i a, __m128i RoundKey )
		{
			return _mm_aesenclast_si128( a, RoundKey );
		}

		// Perform the InvMixColumns transformation on "a" and store the result in "dst"
		inline __m128i XM_CALLCONV aesimc( __m128i a )
		{
			return _mm_aesimc_si128( a );
		}

		// Assist in expanding the AES cipher key by computing steps towards generating a round key for encryption cipher using data from "a" and an 8-bit round constant specified in "imm8"
		template<int imm8>
		inline __m128i XM_CALLCONV aeskeygenassist( __m128i a )
		{
			return _mm_aeskeygenassist_si128( a, imm8 );
		}
	}	// namespace Intrinsics::Sse
}	// namespace Intrinsics