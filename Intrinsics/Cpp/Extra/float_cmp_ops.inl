// Test for equality, return true if all lanes are equal
inline bool XM_CALLCONV equals( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return SIMD_OP( allValuesMask ) == SIMD_OP( movemask )( SIMD_OP( cmpeq )( a, b ) );
}
// Test for inequality, return true if at least one lane is not equal
inline bool XM_CALLCONV notEquals( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return SIMD_OP( allValuesMask ) != SIMD_OP( movemask )( SIMD_OP( cmpeq )( a, b ) );
}

#if INTRINSICS_SUPPORT_OPERATORS

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

#endif	// INTRINSICS_SUPPORT_OPERATORS