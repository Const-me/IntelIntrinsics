// This file is generated automatically by a tool. If you want to change it, fork & modify the tool instead: https://github.com/Const-me/IntelIntrinsics
#pragma once
#include "../sse.hpp"

namespace Intrinsics
{
	namespace Sse
	{
		using VecFloat64 = __m128d;
		// movemask_pd will return this value when every lane has the most significant bit set.
		static constexpr int allValuesMask_pd = 0x3;

		using VecInteger = __m128i;
		// movemask_epi8 will return this value when every lane has the most significant bit set.
		static constexpr int allValuesMask_epi8 = 0xFFFF;
		// movemask_epi32 will return this value when every lane has the most significant bit set.
		static constexpr int allValuesMask_epi32 = allValuesMask_ps;
		// movemask_epi64 will return this value when every lane has the most significant bit set.
		static constexpr int allValuesMask_epi64 = allValuesMask_pd;

		// Shuffle double-precision (64-bit) floating-point elements using the control in "imm8", and store the results in "dst". 
		template<uint8_t c1, uint8_t c2>
		inline __m128d XM_CALLCONV shuffle_pd( __m128d a, __m128d b )
		{
			static_assert( c1 < 2 && c2 < 2, "Shuffle constants out of range" );
			constexpr int imm = _MM_SHUFFLE2( (int)c2, (int)c1 );
			return shuffle_pd<imm>( a, b );
		}

		// ==== Basic floating-point arithmetic ====

		// Return vector with just the sign bits set
		inline __m128d XM_CALLCONV signBitsMask_pd()
		{
			return set1_pd( -0.0 );
		}

		// Produce vector filled with all ones. The value is NaN, you should only use this for bitwise operations.
		inline __m128d XM_CALLCONV allones_pd()
		{
			return cmpeq_pd( setzero_pd(), setzero_pd() );
		}

		// Absolute value
		inline __m128d XM_CALLCONV abs( __m128d a )
		{
			const __m128d mask = signBitsMask_pd();
			return andnot_pd( mask, a );
		}

		// Flip sign bit
		inline __m128d XM_CALLCONV negate( __m128d a )
		{
			const __m128d mask = signBitsMask_pd();
			return xor_pd( mask, a );
		}

#if INTRINSICS_SUPPORT_OPERATORS
		inline __m128d XM_CALLCONV operator +( __m128d a, __m128d b )
		{
			return add_pd( a, b );
		}
		inline __m128d XM_CALLCONV operator -( __m128d a, __m128d b )
		{
			return sub_pd( a, b );
		}
		inline __m128d XM_CALLCONV operator *( __m128d a, __m128d b )
		{
			return mul_pd( a, b );
		}
		inline __m128d XM_CALLCONV operator /( __m128d a, __m128d b )
		{
			return div_pd( a, b );
		}

		inline void XM_CALLCONV operator +=( __m128d &a, __m128d b )
		{
			a = a + b;
		}
		inline void XM_CALLCONV operator -=( __m128d &a, __m128d b )
		{
			a = a - b;
		}
		inline void XM_CALLCONV operator *=( __m128d &a, __m128d b )
		{
			a = a * b;
		}
		inline void XM_CALLCONV operator /=( __m128d &a, __m128d b )
		{
			a = a / b;
		}

		// Unary '-'
		inline __m128d XM_CALLCONV operator -( __m128d a )
		{
			return negate( a );
		}
#endif	// INTRINSICS_SUPPORT_OPERATORS
		// Test for equality, return true if all lanes are equal
		inline bool XM_CALLCONV equals( __m128d a, __m128d b )
		{
			return allValuesMask_pd == movemask_pd( cmpeq_pd( a, b ) );
		}
		// Test for inequality, return true if at least one lane is not equal
		inline bool XM_CALLCONV notEquals( __m128d a, __m128d b )
		{
			return allValuesMask_pd != movemask_pd( cmpeq_pd( a, b ) );
		}

#if INTRINSICS_SUPPORT_OPERATORS

		// Comparison operators return per-lane result vectors.

		inline __m128d XM_CALLCONV operator ==( __m128d a, __m128d b )
		{
			return cmpeq_pd( a, b );
		}
		inline __m128d XM_CALLCONV operator !=( __m128d a, __m128d b )
		{
			return cmpneq_pd( a, b );
		}
		inline __m128d XM_CALLCONV operator >( __m128d a, __m128d b )
		{
			return cmpgt_pd( a, b );
		}
		inline __m128d XM_CALLCONV operator <( __m128d a, __m128d b )
		{
			return cmplt_pd( a, b );
		}
		inline __m128d XM_CALLCONV operator >=( __m128d a, __m128d b )
		{
			return cmpge_pd( a, b );
		}
		inline __m128d XM_CALLCONV operator <=( __m128d a, __m128d b )
		{
			return cmple_pd( a, b );
		}

#endif	// INTRINSICS_SUPPORT_OPERATORS

		// ==== Bitwise operations ====
#if INTRINSICS_SUPPORT_OPERATORS
		// Bitwise operator processing the complete vectors
		inline __m128d XM_CALLCONV operator &( __m128d a, __m128d b )
		{
			return and_pd( a, b );
		}
		inline __m128d XM_CALLCONV operator |( __m128d a, __m128d b )
		{
			return or_pd( a, b );
		}
		inline __m128d XM_CALLCONV operator ^( __m128d a, __m128d b )
		{
			return xor_pd( a, b );
		}

		inline void XM_CALLCONV operator &=( __m128d &a, __m128d b )
		{
			a = a & b;
		}
		inline void XM_CALLCONV operator |=( __m128d &a, __m128d b )
		{
			a = a | b;
		}
		inline void XM_CALLCONV operator ^=( __m128d &a, __m128d b )
		{
			a = a ^ b;
		}

		inline __m128d XM_CALLCONV operator~( __m128d a )
		{
			return xor_pd( a, allones_pd() );
		}
#endif // INTRINSICS_SUPPORT_OPERATORS

		// Return vector filled with all one-s.
		inline __m128i XM_CALLCONV allones_all()
		{
			return cmpeq_epi8( setzero_all(), setzero_all() );
		}

		// Set each bit of mask "dst" based on the most significant bit of the corresponding packed 32-bit element in "a".
		inline int movemask_epi32( __m128i a )
		{
			return movemask_ps( castall_ps( a ) );
		}

		// Set each bit of mask "dst" based on the most significant bit of the corresponding packed 64-bit element in "a".
		inline int movemask_epi64( __m128i a )
		{
			return movemask_pd( castall_pd( a ) );
		}

		// Test for equality, return true if all lanes are equal
		inline bool XM_CALLCONV equals( __m128i a, __m128i b )
		{
			return allValuesMask_epi8 == movemask_epi8( cmpeq_epi8( a, b ) );
		}

		// Test for inequality, return true if at least one lane is not equal
		inline bool XM_CALLCONV notEquals( __m128i a, __m128i b )
		{
			return allValuesMask_epi8 != movemask_epi8( cmpeq_epi8( a, b ) );
		}

		// Shuffle 32-bit integers in "a" within 128-bit lanes
		template<uint8_t c1, uint8_t c2, uint8_t c3, uint8_t c4>
		inline __m128i XM_CALLCONV shuffle_epi32( __m128i a )
		{
			static_assert( c1 < 4 && c2 < 4 && c3 < 4 && c4 < 4, "Shuffle constants out of range" );
			constexpr int imm = _MM_SHUFFLE( (int)c4, (int)c3, (int)c2, (int)c1 );
			return shuffle_epi32<imm>( a );
		}

		// ==== Bitwise operations ====
#if INTRINSICS_SUPPORT_OPERATORS
		// Bitwise operator processing the complete vectors
		inline __m128i XM_CALLCONV operator &( __m128i a, __m128i b )
		{
			return and_all( a, b );
		}
		inline __m128i XM_CALLCONV operator |( __m128i a, __m128i b )
		{
			return or_all( a, b );
		}
		inline __m128i XM_CALLCONV operator ^( __m128i a, __m128i b )
		{
			return xor_all( a, b );
		}

		inline void XM_CALLCONV operator &=( __m128i &a, __m128i b )
		{
			a = a & b;
		}
		inline void XM_CALLCONV operator |=( __m128i &a, __m128i b )
		{
			a = a | b;
		}
		inline void XM_CALLCONV operator ^=( __m128i &a, __m128i b )
		{
			a = a ^ b;
		}

		inline __m128i XM_CALLCONV operator~( __m128i a )
		{
			return xor_all( a, allones_all() );
		}
#endif // INTRINSICS_SUPPORT_OPERATORS

		// ==== Couple missing integer comparison intrinsics ====

		// operator >=
		inline __m128i XM_CALLCONV cmpge_epi8( __m128i a, __m128i b )
		{
			const __m128i lt = cmplt_epi8( a, b );
			return xor_all( lt, allones_all() );
		}

		// operator <=
		inline __m128i XM_CALLCONV cmple_epi8( __m128i a, __m128i b )
		{
			const __m128i gt = cmpgt_epi8( a, b );
			return xor_all( gt, allones_all() );
		}

		// operator !=
		inline __m128i XM_CALLCONV cmpneq_epi8( __m128i a, __m128i b )
		{
			const __m128i ee = cmpeq_epi8( a, b );
			return xor_all( ee, allones_all() );
		}

		// operator >=
		inline __m128i XM_CALLCONV cmpge_epi16( __m128i a, __m128i b )
		{
			const __m128i lt = cmplt_epi16( a, b );
			return xor_all( lt, allones_all() );
		}

		// operator <=
		inline __m128i XM_CALLCONV cmple_epi16( __m128i a, __m128i b )
		{
			const __m128i gt = cmpgt_epi16( a, b );
			return xor_all( gt, allones_all() );
		}

		// operator !=
		inline __m128i XM_CALLCONV cmpneq_epi16( __m128i a, __m128i b )
		{
			const __m128i ee = cmpeq_epi16( a, b );
			return xor_all( ee, allones_all() );
		}

		// operator >=
		inline __m128i XM_CALLCONV cmpge_epi32( __m128i a, __m128i b )
		{
			const __m128i lt = cmplt_epi32( a, b );
			return xor_all( lt, allones_all() );
		}

		// operator <=
		inline __m128i XM_CALLCONV cmple_epi32( __m128i a, __m128i b )
		{
			const __m128i gt = cmpgt_epi32( a, b );
			return xor_all( gt, allones_all() );
		}

		// operator !=
		inline __m128i XM_CALLCONV cmpneq_epi32( __m128i a, __m128i b )
		{
			const __m128i ee = cmpeq_epi32( a, b );
			return xor_all( ee, allones_all() );
		}

#if INTRINSICS_SUPPORT_OPERATORS
		namespace Int8
		{
			// Basic arithmetic
			inline __m128i XM_CALLCONV operator +( __m128i a, __m128i b )
			{
				return add_epi8( a, b );
			}
			inline void XM_CALLCONV operator +=( __m128i& a, __m128i b )
			{
				a = add_epi8( a, b );
			}

			inline __m128i XM_CALLCONV operator -( __m128i a )
			{
				return sub_epi8( setzero_all(), a );
			}
			inline __m128i XM_CALLCONV operator -( __m128i a, __m128i b )
			{
				return sub_epi8( a, b );
			}
			inline void XM_CALLCONV operator -=( __m128i& a, __m128i b )
			{
				a = sub_epi8( a, b );
			}

			// Comparison operators return per-lane result vectors.
			inline __m128i XM_CALLCONV operator ==( __m128i a, __m128i b )
			{
				return cmpeq_epi8( a, b );
			}
			inline __m128i XM_CALLCONV operator !=( __m128i a, __m128i b )
			{
				return cmpneq_epi8( a, b );
			}
			inline __m128i XM_CALLCONV operator >( __m128i a, __m128i b )
			{
				return cmpgt_epi8( a, b );
			}
			inline __m128i XM_CALLCONV operator <( __m128i a, __m128i b )
			{
				return cmplt_epi8( a, b );
			}
			inline __m128i XM_CALLCONV operator >=( __m128i a, __m128i b )
			{
				return cmpge_epi8( a, b );
			}
			inline __m128i XM_CALLCONV operator <=( __m128i a, __m128i b )
			{
				return cmple_epi8( a, b );
			}
		}	// namespace Intrinsics::Sse::Int8
		namespace Int16
		{
			// Basic arithmetic
			inline __m128i XM_CALLCONV operator +( __m128i a, __m128i b )
			{
				return add_epi16( a, b );
			}
			inline void XM_CALLCONV operator +=( __m128i& a, __m128i b )
			{
				a = add_epi16( a, b );
			}

			inline __m128i XM_CALLCONV operator -( __m128i a )
			{
				return sub_epi16( setzero_all(), a );
			}
			inline __m128i XM_CALLCONV operator -( __m128i a, __m128i b )
			{
				return sub_epi16( a, b );
			}
			inline void XM_CALLCONV operator -=( __m128i& a, __m128i b )
			{
				a = sub_epi16( a, b );
			}

			// Comparison operators return per-lane result vectors.
			inline __m128i XM_CALLCONV operator ==( __m128i a, __m128i b )
			{
				return cmpeq_epi16( a, b );
			}
			inline __m128i XM_CALLCONV operator !=( __m128i a, __m128i b )
			{
				return cmpneq_epi16( a, b );
			}
			inline __m128i XM_CALLCONV operator >( __m128i a, __m128i b )
			{
				return cmpgt_epi16( a, b );
			}
			inline __m128i XM_CALLCONV operator <( __m128i a, __m128i b )
			{
				return cmplt_epi16( a, b );
			}
			inline __m128i XM_CALLCONV operator >=( __m128i a, __m128i b )
			{
				return cmpge_epi16( a, b );
			}
			inline __m128i XM_CALLCONV operator <=( __m128i a, __m128i b )
			{
				return cmple_epi16( a, b );
			}
		}	// namespace Intrinsics::Sse::Int16
		namespace Int32
		{
			// Basic arithmetic
			inline __m128i XM_CALLCONV operator +( __m128i a, __m128i b )
			{
				return add_epi32( a, b );
			}
			inline void XM_CALLCONV operator +=( __m128i& a, __m128i b )
			{
				a = add_epi32( a, b );
			}

			inline __m128i XM_CALLCONV operator -( __m128i a )
			{
				return sub_epi32( setzero_all(), a );
			}
			inline __m128i XM_CALLCONV operator -( __m128i a, __m128i b )
			{
				return sub_epi32( a, b );
			}
			inline void XM_CALLCONV operator -=( __m128i& a, __m128i b )
			{
				a = sub_epi32( a, b );
			}

			// Comparison operators return per-lane result vectors.
			inline __m128i XM_CALLCONV operator ==( __m128i a, __m128i b )
			{
				return cmpeq_epi32( a, b );
			}
			inline __m128i XM_CALLCONV operator !=( __m128i a, __m128i b )
			{
				return cmpneq_epi32( a, b );
			}
			inline __m128i XM_CALLCONV operator >( __m128i a, __m128i b )
			{
				return cmpgt_epi32( a, b );
			}
			inline __m128i XM_CALLCONV operator <( __m128i a, __m128i b )
			{
				return cmplt_epi32( a, b );
			}
			inline __m128i XM_CALLCONV operator >=( __m128i a, __m128i b )
			{
				return cmpge_epi32( a, b );
			}
			inline __m128i XM_CALLCONV operator <=( __m128i a, __m128i b )
			{
				return cmple_epi32( a, b );
			}
		}	// namespace Intrinsics::Sse::Int32
#endif // INTRINSICS_SUPPORT_OPERATORS
	}	// namespace Intrinsics::Sse
}	// namespace Intrinsics