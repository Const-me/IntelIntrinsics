#include "stdafx.h"
#include "quaternionMul.h"
#include "Intrinsics/sse_operators.hpp"

#include <d3d11.h>
#include <SimpleMath.h>

using namespace Intrinsics::Sse;

template<uint8_t c1, uint8_t c2, uint8_t c3, uint8_t c4>
VecFloat32 permute_ps( VecFloat32 v )
{
	return shuffle_ps<c1, c2, c3, c4>( v, v );
}

VecFloat32 quaternionMultiply( VecFloat32 Q1, VecFloat32 Q2 )
{
	using DirectX::XMVECTOR;
	// https://github.com/Microsoft/DirectXMath/blob/master/Inc/DirectXMathMisc.inl, XMQuaternionMultiply

	const VecFloat32 ControlWZYX = set_ps( 1, -1, 1, -1 );
	const VecFloat32 ControlZWXY = set_ps( 1, 1, -1, -1 );
	const VecFloat32 ControlYXWZ = set_ps( -1, 1, 1, -1 );
	// Copy to SSE registers and use as few as possible for x86
	XMVECTOR Q2X = Q2;
	XMVECTOR Q2Y = Q2;
	XMVECTOR Q2Z = Q2;
	XMVECTOR vResult = Q2;
	// Splat with one instruction
	vResult = permute_ps<3, 3, 3, 3>( vResult );
	Q2X = permute_ps<0, 0, 0, 0>( Q2X );
	Q2Y = permute_ps<1, 1, 1, 1>( Q2Y );
	Q2Z = permute_ps<2, 2, 2, 2>( Q2Z );
	// Retire Q1 and perform Q1*Q2W
	vResult = mul_ps( vResult, Q1 );
	XMVECTOR Q1Shuffle = Q1;
	// Shuffle the copies of Q1
	Q1Shuffle = permute_ps<0, 1, 2, 3>( Q1Shuffle );
	// Mul by Q1WZYX
	Q2X = mul_ps( Q2X, Q1Shuffle );
	Q1Shuffle = permute_ps<2, 3, 0, 1>( Q1Shuffle );
	// Flip the signs on y and z
	Q2X = mul_ps( Q2X, ControlWZYX );
	// Mul by Q1ZWXY
	Q2Y = mul_ps( Q2Y, Q1Shuffle );
	Q1Shuffle = permute_ps<0, 1, 2, 3>( Q1Shuffle );
	// Flip the signs on z and w
	Q2Y = mul_ps( Q2Y, ControlZWXY );
	// Mul by Q1YXWZ
	Q2Z = mul_ps( Q2Z, Q1Shuffle );
	vResult = add_ps( vResult, Q2X );
	// Flip the signs on x and w
	Q2Z = mul_ps( Q2Z, ControlYXWZ );
	Q2Y = add_ps( Q2Y, Q2Z );
	vResult = add_ps( vResult, Q2Y );
	return vResult;
}

void testQuaternionMultuply()
{
	using namespace DirectX::SimpleMath;
	Quaternion q1{ 0,1,0,0 };
	// Quaternion q2 = 
}