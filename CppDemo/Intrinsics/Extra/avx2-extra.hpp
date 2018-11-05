// This file is generated automatically by a tool. If you want to change it, fork & modify the tool instead: https://github.com/Const-me/IntelIntrinsics
#pragma once
#include "../avx.hpp"

namespace Intrinsics
{
	namespace Avx
	{
		using VecInteger = __m256i;

		// movemask_epi8 will return this value when every lane has the most significant bit set.
		static constexpr int allValuesMask_epi8 = -1;
		// movemask_epi32 will return this value when every lane has the most significant bit set.
		static constexpr int allValuesMask_epi32 = allValuesMask_ps;
		// movemask_epi64 will return this value when every lane has the most significant bit set.
		static constexpr int allValuesMask_epi64 = allValuesMask_pd;

		// operator <
		inline __m256i XM_CALLCONV cmplt_epi8( __m256i a, __m256i b )
		{
			return cmpgt_epi8( b, a );
		}
		// operator <
		inline __m256i XM_CALLCONV cmplt_epi16( __m256i a, __m256i b )
		{
			return cmpgt_epi16( b, a );
		}
		// operator <
		inline __m256i XM_CALLCONV cmplt_epi32( __m256i a, __m256i b )
		{
			return cmpgt_epi32( b, a );
		}
		// operator <
		inline __m256i XM_CALLCONV cmplt_epi64( __m256i a, __m256i b )
		{
			return cmpgt_epi64( b, a );
		}
		// Return vector filled with all one-s.
		inline __m256i XM_CALLCONV allones_all()
		{
			return cmpeq_epi8( setzero_all(), setzero_all() );
		}

		// Set each bit of mask "dst" based on the most significant bit of the corresponding packed 32-bit element in "a".
		inline int movemask_epi32( __m256i a )
		{
			return movemask_ps( castall_ps( a ) );
		}

		// Set each bit of mask "dst" based on the most significant bit of the corresponding packed 64-bit element in "a".
		inline int movemask_epi64( __m256i a )
		{
			return movemask_pd( castall_pd( a ) );
		}

		// Test for equality, return true if all lanes are equal
		inline bool XM_CALLCONV equals( __m256i a, __m256i b )
		{
			return allValuesMask_epi8 == movemask_epi8( cmpeq_epi8( a, b ) );
		}

		// Test for inequality, return true if at least one lane is not equal
		inline bool XM_CALLCONV notEquals( __m256i a, __m256i b )
		{
			return allValuesMask_epi8 != movemask_epi8( cmpeq_epi8( a, b ) );
		}

		// Shuffle 32-bit integers in "a" within 128-bit lanes
		template<uint8_t c1, uint8_t c2, uint8_t c3, uint8_t c4>
		inline __m256i XM_CALLCONV shuffle_epi32( __m256i a )
		{
			static_assert( c1 < 4 && c2 < 4 && c3 < 4 && c4 < 4, "Shuffle constants out of range" );
			constexpr int imm = _MM_SHUFFLE( (int)c4, (int)c3, (int)c2, (int)c1 );
			return shuffle_epi32<imm>( a );
		}

		// ==== Bitwise operations ====
#if INTRINSICS_SUPPORT_OPERATORS
		// Bitwise operator processing the complete vectors
		inline __m256i XM_CALLCONV operator &( __m256i a, __m256i b )
		{
			return and_all( a, b );
		}
		inline __m256i XM_CALLCONV operator |( __m256i a, __m256i b )
		{
			return or_all( a, b );
		}
		inline __m256i XM_CALLCONV operator ^( __m256i a, __m256i b )
		{
			return xor_all( a, b );
		}

		inline void XM_CALLCONV operator &=( __m256i &a, __m256i b )
		{
			a = a & b;
		}
		inline void XM_CALLCONV operator |=( __m256i &a, __m256i b )
		{
			a = a | b;
		}
		inline void XM_CALLCONV operator ^=( __m256i &a, __m256i b )
		{
			a = a ^ b;
		}

		inline __m256i XM_CALLCONV operator~( __m256i a )
		{
			return xor_all( a, allones_all() );
		}
#endif // INTRINSICS_SUPPORT_OPERATORS

		// ==== Couple missing integer comparison intrinsics ====

		// operator >=
		inline __m256i XM_CALLCONV cmpge_epi8( __m256i a, __m256i b )
		{
			const __m256i lt = cmplt_epi8( a, b );
			return xor_all( lt, allones_all() );
		}

		// operator <=
		inline __m256i XM_CALLCONV cmple_epi8( __m256i a, __m256i b )
		{
			const __m256i gt = cmpgt_epi8( a, b );
			return xor_all( gt, allones_all() );
		}

		// operator !=
		inline __m256i XM_CALLCONV cmpneq_epi8( __m256i a, __m256i b )
		{
			const __m256i ee = cmpeq_epi8( a, b );
			return xor_all( ee, allones_all() );
		}

		// operator >=
		inline __m256i XM_CALLCONV cmpge_epi16( __m256i a, __m256i b )
		{
			const __m256i lt = cmplt_epi16( a, b );
			return xor_all( lt, allones_all() );
		}

		// operator <=
		inline __m256i XM_CALLCONV cmple_epi16( __m256i a, __m256i b )
		{
			const __m256i gt = cmpgt_epi16( a, b );
			return xor_all( gt, allones_all() );
		}

		// operator !=
		inline __m256i XM_CALLCONV cmpneq_epi16( __m256i a, __m256i b )
		{
			const __m256i ee = cmpeq_epi16( a, b );
			return xor_all( ee, allones_all() );
		}

		// operator >=
		inline __m256i XM_CALLCONV cmpge_epi32( __m256i a, __m256i b )
		{
			const __m256i lt = cmplt_epi32( a, b );
			return xor_all( lt, allones_all() );
		}

		// operator <=
		inline __m256i XM_CALLCONV cmple_epi32( __m256i a, __m256i b )
		{
			const __m256i gt = cmpgt_epi32( a, b );
			return xor_all( gt, allones_all() );
		}

		// operator !=
		inline __m256i XM_CALLCONV cmpneq_epi32( __m256i a, __m256i b )
		{
			const __m256i ee = cmpeq_epi32( a, b );
			return xor_all( ee, allones_all() );
		}

		// operator >=
		inline __m256i XM_CALLCONV cmpge_epi64( __m256i a, __m256i b )
		{
			const __m256i lt = cmplt_epi64( a, b );
			return xor_all( lt, allones_all() );
		}

		// operator <=
		inline __m256i XM_CALLCONV cmple_epi64( __m256i a, __m256i b )
		{
			const __m256i gt = cmpgt_epi64( a, b );
			return xor_all( gt, allones_all() );
		}

		// operator !=
		inline __m256i XM_CALLCONV cmpneq_epi64( __m256i a, __m256i b )
		{
			const __m256i ee = cmpeq_epi64( a, b );
			return xor_all( ee, allones_all() );
		}

#if INTRINSICS_SUPPORT_OPERATORS
		namespace Int8
		{
			// Basic arithmetic
			inline __m256i XM_CALLCONV operator +( __m256i a, __m256i b )
			{
				return add_epi8( a, b );
			}
			inline void XM_CALLCONV operator +=( __m256i& a, __m256i b )
			{
				a = add_epi8( a, b );
			}

			inline __m256i XM_CALLCONV operator -( __m256i a )
			{
				return sub_epi8( setzero_all(), a );
			}
			inline __m256i XM_CALLCONV operator -( __m256i a, __m256i b )
			{
				return sub_epi8( a, b );
			}
			inline void XM_CALLCONV operator -=( __m256i& a, __m256i b )
			{
				a = sub_epi8( a, b );
			}

			// Comparison operators return per-lane result vectors.
			inline __m256i XM_CALLCONV operator ==( __m256i a, __m256i b )
			{
				return cmpeq_epi8( a, b );
			}
			inline __m256i XM_CALLCONV operator !=( __m256i a, __m256i b )
			{
				return cmpneq_epi8( a, b );
			}
			inline __m256i XM_CALLCONV operator >( __m256i a, __m256i b )
			{
				return cmpgt_epi8( a, b );
			}
			inline __m256i XM_CALLCONV operator <( __m256i a, __m256i b )
			{
				return cmplt_epi8( a, b );
			}
			inline __m256i XM_CALLCONV operator >=( __m256i a, __m256i b )
			{
				return cmpge_epi8( a, b );
			}
			inline __m256i XM_CALLCONV operator <=( __m256i a, __m256i b )
			{
				return cmple_epi8( a, b );
			}
		}	// namespace Intrinsics::Avx::Int8
		namespace Int16
		{
			// Basic arithmetic
			inline __m256i XM_CALLCONV operator +( __m256i a, __m256i b )
			{
				return add_epi16( a, b );
			}
			inline void XM_CALLCONV operator +=( __m256i& a, __m256i b )
			{
				a = add_epi16( a, b );
			}

			inline __m256i XM_CALLCONV operator -( __m256i a )
			{
				return sub_epi16( setzero_all(), a );
			}
			inline __m256i XM_CALLCONV operator -( __m256i a, __m256i b )
			{
				return sub_epi16( a, b );
			}
			inline void XM_CALLCONV operator -=( __m256i& a, __m256i b )
			{
				a = sub_epi16( a, b );
			}

			// Comparison operators return per-lane result vectors.
			inline __m256i XM_CALLCONV operator ==( __m256i a, __m256i b )
			{
				return cmpeq_epi16( a, b );
			}
			inline __m256i XM_CALLCONV operator !=( __m256i a, __m256i b )
			{
				return cmpneq_epi16( a, b );
			}
			inline __m256i XM_CALLCONV operator >( __m256i a, __m256i b )
			{
				return cmpgt_epi16( a, b );
			}
			inline __m256i XM_CALLCONV operator <( __m256i a, __m256i b )
			{
				return cmplt_epi16( a, b );
			}
			inline __m256i XM_CALLCONV operator >=( __m256i a, __m256i b )
			{
				return cmpge_epi16( a, b );
			}
			inline __m256i XM_CALLCONV operator <=( __m256i a, __m256i b )
			{
				return cmple_epi16( a, b );
			}
		}	// namespace Intrinsics::Avx::Int16
		namespace Int32
		{
			// Basic arithmetic
			inline __m256i XM_CALLCONV operator +( __m256i a, __m256i b )
			{
				return add_epi32( a, b );
			}
			inline void XM_CALLCONV operator +=( __m256i& a, __m256i b )
			{
				a = add_epi32( a, b );
			}

			inline __m256i XM_CALLCONV operator -( __m256i a )
			{
				return sub_epi32( setzero_all(), a );
			}
			inline __m256i XM_CALLCONV operator -( __m256i a, __m256i b )
			{
				return sub_epi32( a, b );
			}
			inline void XM_CALLCONV operator -=( __m256i& a, __m256i b )
			{
				a = sub_epi32( a, b );
			}

			// Comparison operators return per-lane result vectors.
			inline __m256i XM_CALLCONV operator ==( __m256i a, __m256i b )
			{
				return cmpeq_epi32( a, b );
			}
			inline __m256i XM_CALLCONV operator !=( __m256i a, __m256i b )
			{
				return cmpneq_epi32( a, b );
			}
			inline __m256i XM_CALLCONV operator >( __m256i a, __m256i b )
			{
				return cmpgt_epi32( a, b );
			}
			inline __m256i XM_CALLCONV operator <( __m256i a, __m256i b )
			{
				return cmplt_epi32( a, b );
			}
			inline __m256i XM_CALLCONV operator >=( __m256i a, __m256i b )
			{
				return cmpge_epi32( a, b );
			}
			inline __m256i XM_CALLCONV operator <=( __m256i a, __m256i b )
			{
				return cmple_epi32( a, b );
			}
		}	// namespace Intrinsics::Avx::Int32
		namespace Int64
		{
			// Basic arithmetic
			inline __m256i XM_CALLCONV operator +( __m256i a, __m256i b )
			{
				return add_epi64( a, b );
			}
			inline void XM_CALLCONV operator +=( __m256i& a, __m256i b )
			{
				a = add_epi64( a, b );
			}

			inline __m256i XM_CALLCONV operator -( __m256i a )
			{
				return sub_epi64( setzero_all(), a );
			}
			inline __m256i XM_CALLCONV operator -( __m256i a, __m256i b )
			{
				return sub_epi64( a, b );
			}
			inline void XM_CALLCONV operator -=( __m256i& a, __m256i b )
			{
				a = sub_epi64( a, b );
			}

			// Comparison operators return per-lane result vectors.
			inline __m256i XM_CALLCONV operator ==( __m256i a, __m256i b )
			{
				return cmpeq_epi64( a, b );
			}
			inline __m256i XM_CALLCONV operator !=( __m256i a, __m256i b )
			{
				return cmpneq_epi64( a, b );
			}
			inline __m256i XM_CALLCONV operator >( __m256i a, __m256i b )
			{
				return cmpgt_epi64( a, b );
			}
			inline __m256i XM_CALLCONV operator <( __m256i a, __m256i b )
			{
				return cmplt_epi64( a, b );
			}
			inline __m256i XM_CALLCONV operator >=( __m256i a, __m256i b )
			{
				return cmpge_epi64( a, b );
			}
			inline __m256i XM_CALLCONV operator <=( __m256i a, __m256i b )
			{
				return cmple_epi64( a, b );
			}
		}	// namespace Intrinsics::Avx::Int64
#endif // INTRINSICS_SUPPORT_OPERATORS
	}	// namespace Intrinsics::Avx
}	// namespace Intrinsics