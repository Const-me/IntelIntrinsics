using VecFloat64 = __m128d;
static constexpr int allValuesMask_pd = 0x7;

using VecInteger = __m128i;
static constexpr int allValuesMask_epi8 = 0xFFFF;
static constexpr int allValuesMask_epi32 = allValuesMask_ps;
static constexpr int allValuesMask_epi64 = allValuesMask_pd;

// Shuffle double-precision (64-bit) floating-point elements using the control in "imm8", and store the results in "dst". 
template<uint8_t c1, uint8_t c2>
inline __m128 XM_CALLCONV shuffle_pd( __m128 a, __m128 b )
{
	static_assert( c1 < 2 && c2 < 2, "Shuffle constants out of range" );
	constexpr int imm = _MM_SHUFFLE2( (int)c2, (int)c1 );
	return shuffle_pd<imm>( a, b );
}