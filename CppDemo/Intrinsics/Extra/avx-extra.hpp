// This file is generated automatically by a tool. If you want to change it, fork & modify the tool instead: https://github.com/Const-me/IntelIntrinsics
#pragma once

namespace Intrinsics
{
	namespace Avx
	{
		using VecFloat32 = __m256;
		// movemask_ps will return this value when every lane has the most significant bit set.
		static constexpr int allValuesMask_ps = 0xFF;

		using VecFloat64 = __m256d;
		// movemask_pd will return this value when every lane has the most significant bit set.
		static constexpr int allValuesMask_pd = 0xF;

		// Shuffle single-precision (32-bit) floating-point elements in "a" within 128-bit lanes using the control in template arguments
		template<uint8_t c1, uint8_t c2, uint8_t c3, uint8_t c4>
		inline __m256 XM_CALLCONV shuffle_ps( __m256 a, __m256 b )
		{
			static_assert( c1 < 4 && c2 < 4 && c3 < 4 && c4 < 4, "Shuffle constants out of range" );
			constexpr int imm = _MM_SHUFFLE( (int)c4, (int)c3, (int)c2, (int)c1 );
			return shuffle_ps<imm>( a, b );
		}

		// Shuffle double-precision (64-bit) floating-point elements within 128-bit lanes using the control in "imm8", and store the results in "dst". 
		template<uint8_t c1, uint8_t c2, uint8_t c3, uint8_t c4>
		inline __m256d XM_CALLCONV shuffle_pd( __m256d a, __m256d b )
		{
			static_assert( c1 < 4 && c2 < 4 && c3 < 4 && c4 < 4, "Shuffle constants out of range" );
			constexpr int imm = _MM_SHUFFLE( (int)c4, (int)c3, (int)c2, (int)c1 );
			return shuffle_pd<imm>( a, b );
		}
		// AVX doesn't have cmpeq / cmpgt / etc. for floating point lanes, the only way to compare stuff is _mm256_cmp_ps / _mm256_cmp_pd.
		// This is inconvenient, implement missing intrinsics here.
		// https://stackoverflow.com/q/16988199/126995

		// operator ==
		inline __m256 XM_CALLCONV cmpeq_ps( __m256 a, __m256 b )
		{
			return cmp_ps<_CMP_EQ_OQ>( a, b );
		}

		// operator !=
		inline __m256 XM_CALLCONV cmpneq_ps( __m256 a, __m256 b )
		{
			return cmp_ps<_CMP_NEQ_OQ>( a, b );
		}

		// operator >
		inline __m256 XM_CALLCONV cmpgt_ps( __m256 a, __m256 b )
		{
			return cmp_ps<_CMP_GT_OQ>( a, b );
		}

		// operator <
		inline __m256 XM_CALLCONV cmplt_ps( __m256 a, __m256 b )
		{
			return cmp_ps<_CMP_LT_OQ>( a, b );
		}

		// operator >=
		inline __m256 XM_CALLCONV cmpge_ps( __m256 a, __m256 b )
		{
			return cmp_ps<_CMP_GE_OQ>( a, b );
		}

		// operator <
		inline __m256 XM_CALLCONV cmple_ps( __m256 a, __m256 b )
		{
			return cmp_ps<_CMP_LE_OQ>( a, b );
		}

		// ==== Basic floating-point arithmetic ====

		// Return vector with just the sign bits set
		inline __m256 XM_CALLCONV signBitsMask_ps()
		{
			return set1_ps( -0.0 );
		}

		// Produce vector filled with all ones. The value is NaN, you should only use this for bitwise operations.
		inline __m256 XM_CALLCONV allones_ps()
		{
			return cmpeq_ps( setzero_ps(), setzero_ps() );
		}

		// Absolute value
		inline __m256 XM_CALLCONV abs( __m256 a )
		{
			const __m256 mask = signBitsMask_ps();
			return andnot_ps( mask, a );
		}

		// Flip sign bit
		inline __m256 XM_CALLCONV negate( __m256 a )
		{
			const __m256 mask = signBitsMask_ps();
			return xor_ps( mask, a );
		}

#if INTRINSICS_SUPPORT_OPERATORS
		inline __m256 XM_CALLCONV operator +( __m256 a, __m256 b )
		{
			return add_ps( a, b );
		}
		inline __m256 XM_CALLCONV operator -( __m256 a, __m256 b )
		{
			return sub_ps( a, b );
		}
		inline __m256 XM_CALLCONV operator *( __m256 a, __m256 b )
		{
			return mul_ps( a, b );
		}
		inline __m256 XM_CALLCONV operator /( __m256 a, __m256 b )
		{
			return div_ps( a, b );
		}

		inline void XM_CALLCONV operator +=( __m256 &a, __m256 b )
		{
			a = a + b;
		}
		inline void XM_CALLCONV operator -=( __m256 &a, __m256 b )
		{
			a = a - b;
		}
		inline void XM_CALLCONV operator *=( __m256 &a, __m256 b )
		{
			a = a * b;
		}
		inline void XM_CALLCONV operator /=( __m256 &a, __m256 b )
		{
			a = a / b;
		}

		// Unary '-'
		inline __m256 XM_CALLCONV operator -( __m256 a )
		{
			return negate( a );
		}
#endif	// INTRINSICS_SUPPORT_OPERATORS
		// Test for equality, return true if all lanes are equal
		inline bool XM_CALLCONV equals( __m256 a, __m256 b )
		{
			return allValuesMask_ps == movemask_ps( cmpeq_ps( a, b ) );
		}
		// Test for inequality, return true if at least one lane is not equal
		inline bool XM_CALLCONV notEquals( __m256 a, __m256 b )
		{
			return allValuesMask_ps != movemask_ps( cmpeq_ps( a, b ) );
		}

#if INTRINSICS_SUPPORT_OPERATORS

		// Comparison operators return per-lane result vectors.

		inline __m256 XM_CALLCONV operator ==( __m256 a, __m256 b )
		{
			return cmpeq_ps( a, b );
		}
		inline __m256 XM_CALLCONV operator !=( __m256 a, __m256 b )
		{
			return cmpneq_ps( a, b );
		}
		inline __m256 XM_CALLCONV operator >( __m256 a, __m256 b )
		{
			return cmpgt_ps( a, b );
		}
		inline __m256 XM_CALLCONV operator <( __m256 a, __m256 b )
		{
			return cmplt_ps( a, b );
		}
		inline __m256 XM_CALLCONV operator >=( __m256 a, __m256 b )
		{
			return cmpge_ps( a, b );
		}
		inline __m256 XM_CALLCONV operator <=( __m256 a, __m256 b )
		{
			return cmple_ps( a, b );
		}

#endif	// INTRINSICS_SUPPORT_OPERATORS

		// ==== Bitwise operations ====
#if INTRINSICS_SUPPORT_OPERATORS
		// Bitwise operator processing the complete vectors
		inline __m256 XM_CALLCONV operator &( __m256 a, __m256 b )
		{
			return and_ps( a, b );
		}
		inline __m256 XM_CALLCONV operator |( __m256 a, __m256 b )
		{
			return or_ps( a, b );
		}
		inline __m256 XM_CALLCONV operator ^( __m256 a, __m256 b )
		{
			return xor_ps( a, b );
		}

		inline void XM_CALLCONV operator &=( __m256 &a, __m256 b )
		{
			a = a & b;
		}
		inline void XM_CALLCONV operator |=( __m256 &a, __m256 b )
		{
			a = a | b;
		}
		inline void XM_CALLCONV operator ^=( __m256 &a, __m256 b )
		{
			a = a ^ b;
		}

		inline __m256 XM_CALLCONV operator~( __m256 a )
		{
			return xor_ps( a, allones_ps() );
		}
#endif // INTRINSICS_SUPPORT_OPERATORS
		// AVX doesn't have cmpeq / cmpgt / etc. for floating point lanes, the only way to compare stuff is _mm256_cmp_ps / _mm256_cmp_pd.
		// This is inconvenient, implement missing intrinsics here.
		// https://stackoverflow.com/q/16988199/126995

		// operator ==
		inline __m256d XM_CALLCONV cmpeq_pd( __m256d a, __m256d b )
		{
			return cmp_pd<_CMP_EQ_OQ>( a, b );
		}

		// operator !=
		inline __m256d XM_CALLCONV cmpneq_pd( __m256d a, __m256d b )
		{
			return cmp_pd<_CMP_NEQ_OQ>( a, b );
		}

		// operator >
		inline __m256d XM_CALLCONV cmpgt_pd( __m256d a, __m256d b )
		{
			return cmp_pd<_CMP_GT_OQ>( a, b );
		}

		// operator <
		inline __m256d XM_CALLCONV cmplt_pd( __m256d a, __m256d b )
		{
			return cmp_pd<_CMP_LT_OQ>( a, b );
		}

		// operator >=
		inline __m256d XM_CALLCONV cmpge_pd( __m256d a, __m256d b )
		{
			return cmp_pd<_CMP_GE_OQ>( a, b );
		}

		// operator <
		inline __m256d XM_CALLCONV cmple_pd( __m256d a, __m256d b )
		{
			return cmp_pd<_CMP_LE_OQ>( a, b );
		}

		// ==== Basic floating-point arithmetic ====

		// Return vector with just the sign bits set
		inline __m256d XM_CALLCONV signBitsMask_pd()
		{
			return set1_pd( -0.0 );
		}

		// Produce vector filled with all ones. The value is NaN, you should only use this for bitwise operations.
		inline __m256d XM_CALLCONV allones_pd()
		{
			return cmpeq_pd( setzero_pd(), setzero_pd() );
		}

		// Absolute value
		inline __m256d XM_CALLCONV abs( __m256d a )
		{
			const __m256d mask = signBitsMask_pd();
			return andnot_pd( mask, a );
		}

		// Flip sign bit
		inline __m256d XM_CALLCONV negate( __m256d a )
		{
			const __m256d mask = signBitsMask_pd();
			return xor_pd( mask, a );
		}

#if INTRINSICS_SUPPORT_OPERATORS
		inline __m256d XM_CALLCONV operator +( __m256d a, __m256d b )
		{
			return add_pd( a, b );
		}
		inline __m256d XM_CALLCONV operator -( __m256d a, __m256d b )
		{
			return sub_pd( a, b );
		}
		inline __m256d XM_CALLCONV operator *( __m256d a, __m256d b )
		{
			return mul_pd( a, b );
		}
		inline __m256d XM_CALLCONV operator /( __m256d a, __m256d b )
		{
			return div_pd( a, b );
		}

		inline void XM_CALLCONV operator +=( __m256d &a, __m256d b )
		{
			a = a + b;
		}
		inline void XM_CALLCONV operator -=( __m256d &a, __m256d b )
		{
			a = a - b;
		}
		inline void XM_CALLCONV operator *=( __m256d &a, __m256d b )
		{
			a = a * b;
		}
		inline void XM_CALLCONV operator /=( __m256d &a, __m256d b )
		{
			a = a / b;
		}

		// Unary '-'
		inline __m256d XM_CALLCONV operator -( __m256d a )
		{
			return negate( a );
		}
#endif	// INTRINSICS_SUPPORT_OPERATORS
		// Test for equality, return true if all lanes are equal
		inline bool XM_CALLCONV equals( __m256d a, __m256d b )
		{
			return allValuesMask_pd == movemask_pd( cmpeq_pd( a, b ) );
		}
		// Test for inequality, return true if at least one lane is not equal
		inline bool XM_CALLCONV notEquals( __m256d a, __m256d b )
		{
			return allValuesMask_pd != movemask_pd( cmpeq_pd( a, b ) );
		}

#if INTRINSICS_SUPPORT_OPERATORS

		// Comparison operators return per-lane result vectors.

		inline __m256d XM_CALLCONV operator ==( __m256d a, __m256d b )
		{
			return cmpeq_pd( a, b );
		}
		inline __m256d XM_CALLCONV operator !=( __m256d a, __m256d b )
		{
			return cmpneq_pd( a, b );
		}
		inline __m256d XM_CALLCONV operator >( __m256d a, __m256d b )
		{
			return cmpgt_pd( a, b );
		}
		inline __m256d XM_CALLCONV operator <( __m256d a, __m256d b )
		{
			return cmplt_pd( a, b );
		}
		inline __m256d XM_CALLCONV operator >=( __m256d a, __m256d b )
		{
			return cmpge_pd( a, b );
		}
		inline __m256d XM_CALLCONV operator <=( __m256d a, __m256d b )
		{
			return cmple_pd( a, b );
		}

#endif	// INTRINSICS_SUPPORT_OPERATORS

		// ==== Bitwise operations ====
#if INTRINSICS_SUPPORT_OPERATORS
		// Bitwise operator processing the complete vectors
		inline __m256d XM_CALLCONV operator &( __m256d a, __m256d b )
		{
			return and_pd( a, b );
		}
		inline __m256d XM_CALLCONV operator |( __m256d a, __m256d b )
		{
			return or_pd( a, b );
		}
		inline __m256d XM_CALLCONV operator ^( __m256d a, __m256d b )
		{
			return xor_pd( a, b );
		}

		inline void XM_CALLCONV operator &=( __m256d &a, __m256d b )
		{
			a = a & b;
		}
		inline void XM_CALLCONV operator |=( __m256d &a, __m256d b )
		{
			a = a | b;
		}
		inline void XM_CALLCONV operator ^=( __m256d &a, __m256d b )
		{
			a = a ^ b;
		}

		inline __m256d XM_CALLCONV operator~( __m256d a )
		{
			return xor_pd( a, allones_pd() );
		}
#endif // INTRINSICS_SUPPORT_OPERATORS
	}	// namespace Intrinsics::Avx
}	// namespace Intrinsics