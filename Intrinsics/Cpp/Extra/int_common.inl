﻿// Return vector filled with all one-s.
inline VECTOR_TYPE XM_CALLCONV SIMD_OP( allones )()
{
	return cmpeq_epi8( SIMD_OP( setzero )(), SIMD_OP( setzero )() );
}

// Set each bit of mask "dst" based on the most significant bit of the corresponding packed 32-bit element in "a".
inline int movemask_epi32( VECTOR_TYPE a )
{
	return movemask_ps( castall_ps( a ) );
}

// Set each bit of mask "dst" based on the most significant bit of the corresponding packed 64-bit element in "a".
inline int movemask_epi64( VECTOR_TYPE a )
{
	return movemask_pd( castall_pd( a ) );
}

// Test for equality, return true if all lanes are equal
inline bool XM_CALLCONV equals( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return allValuesMask_epi8 == movemask_epi8( cmpeq_epi8( a, b ) );
}

// Test for inequality, return true if at least one lane is not equal
inline bool XM_CALLCONV notEquals( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return allValuesMask_epi8 != movemask_epi8( cmpeq_epi8( a, b ) );
}

// Shuffle 32-bit integers in "a" within 128-bit lanes
template<uint8_t c1, uint8_t c2, uint8_t c3, uint8_t c4>
inline VECTOR_TYPE XM_CALLCONV shuffle_epi32( VECTOR_TYPE a )
{
	static_assert( c1 < 4 && c2 < 4 && c3 < 4 && c4 < 4, "Shuffle constants out of range" );
	constexpr int imm = _MM_SHUFFLE( (int)c4, (int)c3, (int)c2, (int)c1 );
	return shuffle_epi32<imm>( a );
}