// This file is generated automatically by a tool. If you want to change it, fork & modify the tool instead: https://github.com/Const-me/IntelIntrinsics
#pragma once

namespace Intrinsics
{
	namespace Sse
	{
		using VecFloat32 = __m128;
		// movemask_ps will return this value when every lane has the most significant bit set.
		static constexpr int allValuesMask_ps = 0xF;

		// Shuffle single-precision (32-bit) floating-point elements in "a" using the control in template arguments
		template<uint8_t c1, uint8_t c2, uint8_t c3, uint8_t c4>
		inline __m128 XM_CALLCONV shuffle_ps( __m128 a, __m128 b )
		{
			static_assert( c1 < 4 && c2 < 4 && c3 < 4 && c4 < 4, "Shuffle constants out of range" );
			constexpr int imm = _MM_SHUFFLE( (int)c4, (int)c3, (int)c2, (int)c1 );
			return shuffle_ps<imm>( a, b );
		}

		// ==== Basic floating-point arithmetic ====

		// Return vector with just the sign bits set
		inline __m128 XM_CALLCONV signBitsMask_ps()
		{
			return set1_ps( -0.0 );
		}

		// Produce vector filled with all ones. The value is NaN, you should only use this for bitwise operations.
		inline __m128 XM_CALLCONV allones_ps()
		{
			return cmpeq_ps( setzero_ps(), setzero_ps() );
		}

		// Absolute value
		inline __m128 XM_CALLCONV abs( __m128 a )
		{
			const __m128 mask = signBitsMask_ps();
			return andnot_ps( mask, a );
		}

		// Flip sign bit
		inline __m128 XM_CALLCONV negate( __m128 a )
		{
			const __m128 mask = signBitsMask_ps();
			return xor_ps( mask, a );
		}

#if INTRINSICS_SUPPORT_OPERATORS
		inline __m128 XM_CALLCONV operator +( __m128 a, __m128 b )
		{
			return add_ps( a, b );
		}
		inline __m128 XM_CALLCONV operator -( __m128 a, __m128 b )
		{
			return sub_ps( a, b );
		}
		inline __m128 XM_CALLCONV operator *( __m128 a, __m128 b )
		{
			return mul_ps( a, b );
		}
		inline __m128 XM_CALLCONV operator /( __m128 a, __m128 b )
		{
			return div_ps( a, b );
		}

		inline void XM_CALLCONV operator +=( __m128 &a, __m128 b )
		{
			a = a + b;
		}
		inline void XM_CALLCONV operator -=( __m128 &a, __m128 b )
		{
			a = a - b;
		}
		inline void XM_CALLCONV operator *=( __m128 &a, __m128 b )
		{
			a = a * b;
		}
		inline void XM_CALLCONV operator /=( __m128 &a, __m128 b )
		{
			a = a / b;
		}

		// Unary '-'
		inline __m128 XM_CALLCONV operator -( __m128 a )
		{
			return negate( a );
		}
#endif	// INTRINSICS_SUPPORT_OPERATORS
		// Test for equality, return true if all lanes are equal
		inline bool XM_CALLCONV equals( __m128 a, __m128 b )
		{
			return allValuesMask_ps == movemask_ps( cmpeq_ps( a, b ) );
		}
		// Test for inequality, return true if at least one lane is not equal
		inline bool XM_CALLCONV notEquals( __m128 a, __m128 b )
		{
			return allValuesMask_ps != movemask_ps( cmpeq_ps( a, b ) );
		}

#if INTRINSICS_SUPPORT_OPERATORS

		// Comparison operators return per-lane result vectors.

		inline __m128 XM_CALLCONV operator ==( __m128 a, __m128 b )
		{
			return cmpeq_ps( a, b );
		}
		inline __m128 XM_CALLCONV operator !=( __m128 a, __m128 b )
		{
			return cmpneq_ps( a, b );
		}
		inline __m128 XM_CALLCONV operator >( __m128 a, __m128 b )
		{
			return cmpgt_ps( a, b );
		}
		inline __m128 XM_CALLCONV operator <( __m128 a, __m128 b )
		{
			return cmplt_ps( a, b );
		}
		inline __m128 XM_CALLCONV operator >=( __m128 a, __m128 b )
		{
			return cmpge_ps( a, b );
		}
		inline __m128 XM_CALLCONV operator <=( __m128 a, __m128 b )
		{
			return cmple_ps( a, b );
		}

#endif	// INTRINSICS_SUPPORT_OPERATORS

		// ==== Bitwise operations ====
#if INTRINSICS_SUPPORT_OPERATORS
		// Bitwise operator processing the complete vectors
		inline __m128 XM_CALLCONV operator &( __m128 a, __m128 b )
		{
			return and_ps( a, b );
		}
		inline __m128 XM_CALLCONV operator |( __m128 a, __m128 b )
		{
			return or_ps( a, b );
		}
		inline __m128 XM_CALLCONV operator ^( __m128 a, __m128 b )
		{
			return xor_ps( a, b );
		}

		inline void XM_CALLCONV operator &=( __m128 &a, __m128 b )
		{
			a = a & b;
		}
		inline void XM_CALLCONV operator |=( __m128 &a, __m128 b )
		{
			a = a | b;
		}
		inline void XM_CALLCONV operator ^=( __m128 &a, __m128 b )
		{
			a = a ^ b;
		}

		inline __m128 XM_CALLCONV operator~( __m128 a )
		{
			return xor_ps( a, allones_ps() );
		}
#endif // INTRINSICS_SUPPORT_OPERATORS
	}	// namespace Intrinsics::Sse
}	// namespace Intrinsics