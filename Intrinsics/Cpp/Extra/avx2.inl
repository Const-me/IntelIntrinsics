using VecInteger = __m256i;
static constexpr int allValuesMask_epi8 = -1;
static constexpr int allValuesMask_epi32 = allValuesMask_ps;
static constexpr int allValuesMask_epi64 = allValuesMask_pd;

inline __m256i XM_CALLCONV cmplt_epi8( __m256i a, __m256i b )
{
	return cmpgt_epi8( b, a );
}
inline __m256i XM_CALLCONV cmplt_epi16( __m256i a, __m256i b )
{
	return cmpgt_epi16( b, a );
}
inline __m256i XM_CALLCONV cmplt_epi32( __m256i a, __m256i b )
{
	return cmpgt_epi32( b, a );
}
inline __m256i XM_CALLCONV cmplt_epi64( __m256i a, __m256i b )
{
	return cmpgt_epi64( b, a );
}