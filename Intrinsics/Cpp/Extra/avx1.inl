using VecFloat32 = __m256;
// movemask_ps will return this value when every lane has the most significant bit set.
static constexpr int allValuesMask_ps = 0xFF;

using VecFloat64 = __m256d;
// movemask_pd will return this value when every lane has the most significant bit set.
static constexpr int allValuesMask_pd = 0xF;

// Shuffle single-precision (32-bit) floating-point elements in "a" within 128-bit lanes using the control in template arguments
template<uint8_t c1, uint8_t c2, uint8_t c3, uint8_t c4>
inline __m256 XM_CALLCONV shuffle_ps( __m256 a, __m256 b )
{
	static_assert( c1 < 4 && c2 < 4 && c3 < 4 && c4 < 4, "Shuffle constants out of range" );
	constexpr int imm = _MM_SHUFFLE( (int)c4, (int)c3, (int)c2, (int)c1 );
	return shuffle_ps<imm>( a, b );
}

// Shuffle double-precision (64-bit) floating-point elements within 128-bit lanes using the control in "imm8", and store the results in "dst". 
template<uint8_t c1, uint8_t c2, uint8_t c3, uint8_t c4>
inline __m256 XM_CALLCONV shuffle_pd( __m256 a, __m256 b )
{
	static_assert( c1 < 4 && c2 < 4 && c3 < 4 && c4 < 4, "Shuffle constants out of range" );
	constexpr int imm = _MM_SHUFFLE( (int)c4, (int)c3, (int)c2, (int)c1 );
	return shuffle_pd<imm>( a, b );
}