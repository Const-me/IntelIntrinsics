// Return vector filled with all one-s.
inline VECTOR_TYPE XM_CALLCONV allones_all()
{
	const VECTOR_TYPE zero = setzero_all();
	return cmpeq_epi8( zero, zero );
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
inline bool XM_CALLCONV cmpeq_all( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return allValuesMask_epi8 == movemask_epi8( cmpeq_epi8( a, b ) );
}

// Test for inequality, return true if at least one lane is not equal
inline bool XM_CALLCONV cmpneq_all( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return allValuesMask_epi8 != movemask_epi8( cmpeq_epi8( a, b ) );
}

// true if a < b, for unsigned integers occupying the whole registers
inline bool XM_CALLCONV cmplt_all( VECTOR_TYPE a, VECTOR_TYPE b )
{
	// Flip the sign bits in both arguments. Transforms 0 into -128 = minimum for signed bytes, 0xFF into +127 = maximum for signed bytes.
	const VECTOR_TYPE signBits = set1_epu8( 0x80 );
	a = xor_all( a, signBits );
	b = xor_all( b, signBits );

	// Use signed comparisons on the bytes. Casting the results to uint32_t because AVX will return 32 bits in these scalars, int may be negative.
	const uint32_t less = (uint32_t)movemask_epi8( cmpgt_epi8( b, a ) );
	const uint32_t greater = (uint32_t)movemask_epi8( cmpgt_epi8( a, b ) );

	// It's counter-intuitive, but this scalar comparison does the right thing.
	// Essentially, integer comparison searches for the most significant bit that differs.
	return less > greater;
}

// true if a > b, for unsigned integers occupying the whole registers
inline bool XM_CALLCONV cmpgt_all( VECTOR_TYPE a, VECTOR_TYPE b )
{
	return cmplt_all( b, a );
}

// Shuffle 32-bit integers in "a" within 128-bit lanes
template<uint8_t c1, uint8_t c2, uint8_t c3, uint8_t c4>
inline VECTOR_TYPE XM_CALLCONV shuffle_epi32( VECTOR_TYPE a )
{
	static_assert( c1 < 4 && c2 < 4 && c3 < 4 && c4 < 4, "Shuffle constants out of range" );
	constexpr int imm = _MM_SHUFFLE( (int)c4, (int)c3, (int)c2, (int)c1 );
	return shuffle_epi32<imm>( a );
}