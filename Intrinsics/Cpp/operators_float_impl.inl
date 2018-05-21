#define CONCAT( A, B ) A ## B
#define CONCAT2( A, B ) CONCAT( A, B )

// Return mask with sign bits of the float vector. This expands to signBitsMask_ps() and signBitsMask_pd().
inline VECTOR_TYPE XM_CALLCONV CONCAT2( signBitsMask_, TYPE_SUFFIX )( )
{
	return CONCAT2( set1_, TYPE_SUFFIX )( -0.0 );
}

inline VECTOR_TYPE XM_CALLCONV operator +( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return CONCAT2( add_, TYPE_SUFFIX )( a, b );
}
inline VECTOR_TYPE XM_CALLCONV operator -( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return CONCAT2( sub_, TYPE_SUFFIX )( a, b );
}
inline VECTOR_TYPE XM_CALLCONV operator *( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return CONCAT2( mul_, TYPE_SUFFIX )( a, b );
}
inline VECTOR_TYPE XM_CALLCONV operator /( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return CONCAT2( div_, TYPE_SUFFIX )( a, b );
}

inline void operator +=( VECTOR_TYPE &a, VECTOR_TYPE b )
{
	a = a + b;
}
inline void operator -=( VECTOR_TYPE &a, VECTOR_TYPE b )
{
	a = a - b;
}
inline void operator *=( VECTOR_TYPE &a, VECTOR_TYPE b )
{
	a = a * b;
}
inline void operator /=( VECTOR_TYPE &a, VECTOR_TYPE b )
{
	a = a / b;
}

inline VECTOR_TYPE XM_CALLCONV operator &( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return CONCAT2( and_, TYPE_SUFFIX )( a, b );
}
inline VECTOR_TYPE XM_CALLCONV operator |( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return CONCAT2( or_, TYPE_SUFFIX )( a, b );
}
inline VECTOR_TYPE XM_CALLCONV operator ^( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return CONCAT2( xor_, TYPE_SUFFIX )( a, b );
}

// Unary '-'
inline VECTOR_TYPE XM_CALLCONV operator -( VECTOR_TYPE a )
{
	const VECTOR_TYPE mask = CONCAT2( signBitsMask_, TYPE_SUFFIX )( );
	return a ^ mask;
}

// Absolute value
inline VECTOR_TYPE XM_CALLCONV abs( VECTOR_TYPE a )
{
	const VECTOR_TYPE mask = CONCAT2( signBitsMask_, TYPE_SUFFIX )( );
	return CONCAT2( andnot_, TYPE_SUFFIX )( mask, a );
}



#undef CONCAT2
#undef CONCAT