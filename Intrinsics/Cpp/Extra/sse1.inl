using VecFloat32 = __m128;
static constexpr int allValuesMask_ps = 0xF;

// Shuffle single-precision (32-bit) floating-point elements in "a" using the control in template arguments
template<uint8_t c1, uint8_t c2, uint8_t c3, uint8_t c4>
inline __m128 XM_CALLCONV shuffle_ps( __m128 a, __m128 b )
{
	static_assert( c1 < 4 && c2 < 4 && c3 < 4 && c4 < 4, "Shuffle constants out of range" );
	constexpr int imm = _MM_SHUFFLE( (int)c4, (int)c3, (int)c2, (int)c1 );
	return shuffle_ps<imm>( a, b );
}