// Basic arithmetic
inline VECTOR_TYPE XM_CALLCONV operator +( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return SIMD_OP( add )( a, b );
}
inline void XM_CALLCONV operator +=( VECTOR_TYPE& a, VECTOR_TYPE b )
{
	a = SIMD_OP( add )( a, b );
}

inline VECTOR_TYPE XM_CALLCONV operator -( VECTOR_TYPE a )
{
	return SIMD_OP( sub )( setzero_all(), a );
}
inline VECTOR_TYPE XM_CALLCONV operator -( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return SIMD_OP( sub )( a, b );
}
inline void XM_CALLCONV operator -=( VECTOR_TYPE& a, VECTOR_TYPE b )
{
	a = SIMD_OP( sub )( a, b );
}

// Comparison operators return per-lane result vectors.
inline VECTOR_TYPE XM_CALLCONV operator ==( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return SIMD_OP( cmpeq )( a, b );
}
inline VECTOR_TYPE XM_CALLCONV operator !=( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return SIMD_OP( cmpneq )( a, b );
}
inline VECTOR_TYPE XM_CALLCONV operator >( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return SIMD_OP( cmpgt )( a, b );
}
inline VECTOR_TYPE XM_CALLCONV operator <( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return SIMD_OP( cmplt )( a, b );
}
inline VECTOR_TYPE XM_CALLCONV operator >=( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return SIMD_OP( cmpge )( a, b );
}
inline VECTOR_TYPE XM_CALLCONV operator <=( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return SIMD_OP( cmple )( a, b );
}