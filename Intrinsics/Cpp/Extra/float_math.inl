
// ==== Basic floating-point arithmetic ====

// Return vector with just the sign bits set
inline VECTOR_TYPE XM_CALLCONV SIMD_OP( signBitsMask )()
{
	return SIMD_OP( set1 )( -0.0 );
}

// Produce vector filled with all ones. The value is NaN, you should only use this for bitwise operations.
inline VECTOR_TYPE XM_CALLCONV SIMD_OP( allones )()
{
	return SIMD_OP( cmpeq )( SIMD_OP( setzero )(), SIMD_OP( setzero )() );
}

// Absolute value
inline VECTOR_TYPE XM_CALLCONV abs( VECTOR_TYPE a )
{
	const VECTOR_TYPE mask = SIMD_OP( signBitsMask )();
	return SIMD_OP( andnot )( mask, a );
}

// Flip sign bit
inline VECTOR_TYPE XM_CALLCONV negate( VECTOR_TYPE a )
{
	const VECTOR_TYPE mask = SIMD_OP( signBitsMask )();
	return SIMD_OP( xor )( mask, a );
}

#if INTRINSICS_SUPPORT_OPERATORS
inline VECTOR_TYPE XM_CALLCONV operator +( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return SIMD_OP( add )( a, b );
}
inline VECTOR_TYPE XM_CALLCONV operator -( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return SIMD_OP( sub )( a, b );
}
inline VECTOR_TYPE XM_CALLCONV operator *( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return SIMD_OP( mul )( a, b );
}
inline VECTOR_TYPE XM_CALLCONV operator /( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return SIMD_OP( div )( a, b );
}

inline void XM_CALLCONV operator +=( VECTOR_TYPE &a, VECTOR_TYPE b )
{
	a = a + b;
}
inline void XM_CALLCONV operator -=( VECTOR_TYPE &a, VECTOR_TYPE b )
{
	a = a - b;
}
inline void XM_CALLCONV operator *=( VECTOR_TYPE &a, VECTOR_TYPE b )
{
	a = a * b;
}
inline void XM_CALLCONV operator /=( VECTOR_TYPE &a, VECTOR_TYPE b )
{
	a = a / b;
}

// Unary '-'
inline VECTOR_TYPE XM_CALLCONV operator -( VECTOR_TYPE a )
{
	return negate( a );
}
#endif	// INTRINSICS_SUPPORT_OPERATORS