#if INTRINSICS_SUPPORT_OPERATORS

// Bitwise operator processing the complete vectors
inline VECTOR_TYPE XM_CALLCONV operator &( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return SIMD_OP( and )( a, b );
}
inline VECTOR_TYPE XM_CALLCONV operator |( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return SIMD_OP( or )( a, b );
}
inline VECTOR_TYPE XM_CALLCONV operator ^( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return SIMD_OP( xor )( a, b );
}

inline void operator &=( VECTOR_TYPE &a, VECTOR_TYPE b )
{
	a = a & b;
}
inline void operator |=( VECTOR_TYPE &a, VECTOR_TYPE b )
{
	a = a | b;
}
inline void operator ^=( VECTOR_TYPE &a, VECTOR_TYPE b )
{
	a = a ^ b;
}

#endif // INTRINSICS_SUPPORT_OPERATORS