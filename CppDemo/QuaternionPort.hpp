#pragma once
// A direct port of small piece of DirectXMath, that's used by quaternionMul.cpp test.

namespace DirectX
{
	using FXMVECTOR = __m128;
	using XMVECTOR = __m128;

	static const __m128 g_XMInfinity = _mm_castsi128_ps( _mm_set1_epi32( 0x7F800000 ) );
	static const __m128 g_XMQNaN = _mm_castsi128_ps( _mm_set1_epi32( 0x7FC00000 ) );
#define XM_PERMUTE_PS( v, c ) _mm_permute_ps( v, c )

	inline __m128 XM_CALLCONV XMVector4Normalize( FXMVECTOR V )
	{
		// SSE 4.1 version

		XMVECTOR vLengthSq = _mm_dp_ps( V, V, 0xff );
		// Prepare for the division
		XMVECTOR vResult = _mm_sqrt_ps( vLengthSq );
		// Create zero with a single instruction
		XMVECTOR vZeroMask = _mm_setzero_ps();
		// Test for a divide by zero (Must be FP to detect -0.0)
		vZeroMask = _mm_cmpneq_ps( vZeroMask, vResult );
		// Failsafe on zero (Or epsilon) length planes
		// If the length is infinity, set the elements to zero
		vLengthSq = _mm_cmpneq_ps( vLengthSq, g_XMInfinity );
		// Divide to perform the normalization
		vResult = _mm_div_ps( V, vResult );
		// Any that are infinity, set to zero
		vResult = _mm_and_ps( vResult, vZeroMask );
		// Select qnan or result based on infinite length
		XMVECTOR vTemp1 = _mm_andnot_ps( vLengthSq, g_XMQNaN );
		XMVECTOR vTemp2 = _mm_and_ps( vResult, vLengthSq );
		vResult = _mm_or_ps( vTemp1, vTemp2 );
		return vResult;
	}

	inline __m128 XM_CALLCONV XMQuaternionMultiply( __m128 Q1, __m128 Q2 )
	{
		// Returns the product Q2*Q1 (which is the concatenation of a rotation Q1 followed by the rotation Q2)

		// [ (Q2.w * Q1.x) + (Q2.x * Q1.w) + (Q2.y * Q1.z) - (Q2.z * Q1.y),
		//   (Q2.w * Q1.y) - (Q2.x * Q1.z) + (Q2.y * Q1.w) + (Q2.z * Q1.x),
		//   (Q2.w * Q1.z) + (Q2.x * Q1.y) - (Q2.y * Q1.x) + (Q2.z * Q1.w),
		//   (Q2.w * Q1.w) - (Q2.x * Q1.x) - (Q2.y * Q1.y) - (Q2.z * Q1.z) ]

		static const __m128 ControlWZYX = _mm_setr_ps( 1.0f, -1.0f, 1.0f, -1.0f );
		static const __m128 ControlZWXY = _mm_setr_ps( 1.0f, 1.0f, -1.0f, -1.0f );
		static const __m128 ControlYXWZ = _mm_setr_ps( -1.0f, 1.0f, 1.0f, -1.0f );
		// Copy to SSE registers and use as few as possible for x86
		__m128 Q2X = Q2;
		__m128 Q2Y = Q2;
		__m128 Q2Z = Q2;
		__m128 vResult = Q2;
		// Splat with one instruction
		vResult = XM_PERMUTE_PS( vResult, _MM_SHUFFLE( 3, 3, 3, 3 ) );
		Q2X = XM_PERMUTE_PS( Q2X, _MM_SHUFFLE( 0, 0, 0, 0 ) );
		Q2Y = XM_PERMUTE_PS( Q2Y, _MM_SHUFFLE( 1, 1, 1, 1 ) );
		Q2Z = XM_PERMUTE_PS( Q2Z, _MM_SHUFFLE( 2, 2, 2, 2 ) );
		// Retire Q1 and perform Q1*Q2W
		vResult = _mm_mul_ps( vResult, Q1 );
		__m128 Q1Shuffle = Q1;
		// Shuffle the copies of Q1
		Q1Shuffle = XM_PERMUTE_PS( Q1Shuffle, _MM_SHUFFLE( 0, 1, 2, 3 ) );
		// Mul by Q1WZYX
		Q2X = _mm_mul_ps( Q2X, Q1Shuffle );
		Q1Shuffle = XM_PERMUTE_PS( Q1Shuffle, _MM_SHUFFLE( 2, 3, 0, 1 ) );
		// Flip the signs on y and z
		Q2X = _mm_mul_ps( Q2X, ControlWZYX );
		// Mul by Q1ZWXY
		Q2Y = _mm_mul_ps( Q2Y, Q1Shuffle );
		Q1Shuffle = XM_PERMUTE_PS( Q1Shuffle, _MM_SHUFFLE( 0, 1, 2, 3 ) );
		// Flip the signs on z and w
		Q2Y = _mm_mul_ps( Q2Y, ControlZWXY );
		// Mul by Q1YXWZ
		Q2Z = _mm_mul_ps( Q2Z, Q1Shuffle );
		vResult = _mm_add_ps( vResult, Q2X );
		// Flip the signs on x and w
		Q2Z = _mm_mul_ps( Q2Z, ControlYXWZ );
		Q2Y = _mm_add_ps( Q2Y, Q2Z );
		vResult = _mm_add_ps( vResult, Q2Y );
		return vResult;
	}

	namespace SimpleMath
	{
		struct Quaternion
		{
			__m128 val;

		public:
			Quaternion( float a, float b, float c, float d ) :
				val( _mm_setr_ps( a, b, c, d ) ) { }

			operator __m128( ) const { return val; }

			void Normalize()
			{
				val = XMVector4Normalize( val );
			}
		};
	}
}