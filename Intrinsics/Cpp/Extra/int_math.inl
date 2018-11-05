
// operator >=
inline VECTOR_TYPE XM_CALLCONV SIMD_OP( cmpge )( VECTOR_TYPE a, VECTOR_TYPE b )
{
	const VECTOR_TYPE lt = SIMD_OP( cmplt )( a, b );
	return xor_all( lt, allones_all() );
}

// operator <=
inline VECTOR_TYPE XM_CALLCONV SIMD_OP( cmple )( VECTOR_TYPE a, VECTOR_TYPE b )
{
	const VECTOR_TYPE gt = SIMD_OP( cmpgt )( a, b );
	return xor_all( gt, allones_all() );
}

// operator !=
inline VECTOR_TYPE XM_CALLCONV SIMD_OP( cmpneq )( VECTOR_TYPE a, VECTOR_TYPE b )
{
	const VECTOR_TYPE ee = SIMD_OP( cmpeq )( a, b );
	return xor_all( ee, allones_all() );
}