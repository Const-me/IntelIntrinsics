// AVX doesn't have cmpeq / cmpgt / etc. for floating point lanes, the only way to compare stuff is _mm256_cmp_ps / _mm256_cmp_pd.
// This is inconvenient, implement missing intrinsics here.
// https://stackoverflow.com/q/16988199/126995

// operator ==
inline VECTOR_TYPE XM_CALLCONV SIMD_OP( cmpeq )( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return SIMD_OP( cmp )<_CMP_EQ_OQ>( a, b );
}

// operator !=
inline VECTOR_TYPE XM_CALLCONV SIMD_OP( cmpneq )( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return SIMD_OP( cmp )<_CMP_NEQ_OQ>( a, b );
}

// operator >
inline VECTOR_TYPE XM_CALLCONV SIMD_OP( cmpgt )( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return SIMD_OP( cmp )<_CMP_GT_OQ>( a, b );
}

// operator <
inline VECTOR_TYPE XM_CALLCONV SIMD_OP( cmplt )( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return SIMD_OP( cmp )<_CMP_LT_OQ>( a, b );
}

// operator >=
inline VECTOR_TYPE XM_CALLCONV SIMD_OP( cmpge )( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return SIMD_OP( cmp )<_CMP_GE_OQ>( a, b );
}

// operator <
inline VECTOR_TYPE XM_CALLCONV SIMD_OP( cmple )( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return SIMD_OP( cmp )<_CMP_LE_OQ>( a, b );
}