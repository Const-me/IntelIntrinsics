// This file is generated automatically by a tool. If you want to change it, fork & modify the tool instead: https://github.com/Const-me/IntelIntrinsics
#pragma once
#include "../sse2.hpp"
#include "../sse4.1.hpp"

namespace Intrinsics
{
	namespace Sse
	{
		// operator <
		inline __m128i XM_CALLCONV cmplt_epi64( __m128i a, __m128i b )
		{
			return cmpgt_epi64( b, a );
		}

		// operator >=
		inline __m128i XM_CALLCONV cmpge_epi64( __m128i a, __m128i b )
		{
			const __m128i lt = cmplt_epi64( a, b );
			return xor_all( lt, allones_all() );
		}

		// operator <=
		inline __m128i XM_CALLCONV cmple_epi64( __m128i a, __m128i b )
		{
			const __m128i gt = cmpgt_epi64( a, b );
			return xor_all( gt, allones_all() );
		}

		// operator !=
		inline __m128i XM_CALLCONV cmpneq_epi64( __m128i a, __m128i b )
		{
			const __m128i ee = cmpeq_epi64( a, b );
			return xor_all( ee, allones_all() );
		}

#if INTRINSICS_SUPPORT_OPERATORS
		namespace Int64
		{
			// Basic arithmetic
			inline __m128i XM_CALLCONV operator +( __m128i a, __m128i b )
			{
				return add_epi64( a, b );
			}
			inline void XM_CALLCONV operator +=( __m128i& a, __m128i b )
			{
				a = add_epi64( a, b );
			}

			inline __m128i XM_CALLCONV operator -( __m128i a )
			{
				return sub_epi64( setzero_all(), a );
			}
			inline __m128i XM_CALLCONV operator -( __m128i a, __m128i b )
			{
				return sub_epi64( a, b );
			}
			inline void XM_CALLCONV operator -=( __m128i& a, __m128i b )
			{
				a = sub_epi64( a, b );
			}

			// Comparison operators return per-lane result vectors.
			inline __m128i XM_CALLCONV operator ==( __m128i a, __m128i b )
			{
				return cmpeq_epi64( a, b );
			}
			inline __m128i XM_CALLCONV operator !=( __m128i a, __m128i b )
			{
				return cmpneq_epi64( a, b );
			}
			inline __m128i XM_CALLCONV operator >( __m128i a, __m128i b )
			{
				return cmpgt_epi64( a, b );
			}
			inline __m128i XM_CALLCONV operator <( __m128i a, __m128i b )
			{
				return cmplt_epi64( a, b );
			}
			inline __m128i XM_CALLCONV operator >=( __m128i a, __m128i b )
			{
				return cmpge_epi64( a, b );
			}
			inline __m128i XM_CALLCONV operator <=( __m128i a, __m128i b )
			{
				return cmple_epi64( a, b );
			}
		}	// namespace Intrinsics::Sse::Int64
#endif // INTRINSICS_SUPPORT_OPERATORS
	}	// namespace Intrinsics::Sse
}	// namespace Intrinsics