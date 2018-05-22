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

// Return mask with sign bits of the float vector. This expands to signBitsMask_ps() and signBitsMask_pd().
inline VECTOR_TYPE XM_CALLCONV SIMD_OP( signBitsMask )( )
{
	return SIMD_OP( set1 )( -0.0 );
}

// Unary '-'
inline VECTOR_TYPE XM_CALLCONV operator -( VECTOR_TYPE a )
{
	const VECTOR_TYPE mask = SIMD_OP( signBitsMask )( );
	return a ^ mask;
}

// Absolute value
inline VECTOR_TYPE XM_CALLCONV abs( VECTOR_TYPE a )
{
	const VECTOR_TYPE mask = SIMD_OP( signBitsMask )( );
	return SIMD_OP( andnot )( mask, a );
}

// Equality
inline bool XM_CALLCONV operator ==( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return SIMD_OP( allValuesMask ) == SIMD_OP( movemask )( SIMD_OP( cmpeq )( a, b ) );
}
inline bool XM_CALLCONV operator !=( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return !( a == b );
}