// Return mask with sign bits of the float vector. This expands to signBitsMask_ps() and signBitsMask_pd().
inline VECTOR_TYPE XM_CALLCONV SIMD_OP( signBitsMask )( )
{
	return SIMD_OP( set1 )( -0.0 );
}

// Absolute value
inline VECTOR_TYPE XM_CALLCONV abs( VECTOR_TYPE a )
{
	const VECTOR_TYPE mask = SIMD_OP( signBitsMask )( );
	return SIMD_OP( andnot )( mask, a );
}

// Flip sign bit
inline VECTOR_TYPE XM_CALLCONV negate( VECTOR_TYPE a )
{
	const VECTOR_TYPE mask = SIMD_OP( signBitsMask )( );
	return SIMD_OP( xor )( mask, a );
}

// Test for equality
inline bool XM_CALLCONV equals( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return SIMD_OP( allValuesMask ) == SIMD_OP( movemask )( SIMD_OP( cmpeq )( a, b ) );
}
// Test for inequality
inline bool XM_CALLCONV notEquals( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return SIMD_OP( allValuesMask ) != SIMD_OP( movemask )( SIMD_OP( cmpeq )( a, b ) );
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

// Equality
inline bool XM_CALLCONV operator ==( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return equals( a, b );
}
inline bool XM_CALLCONV operator !=( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return notEquals( a, b );
}
#endif	// INTRINSICS_SUPPORT_OPERATORS