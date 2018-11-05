using VecInteger = __m256i;

// movemask_epi8 will return this value when every lane has the most significant bit set.
static constexpr int allValuesMask_epi8 = -1;
// movemask_epi32 will return this value when every lane has the most significant bit set.
static constexpr int allValuesMask_epi32 = allValuesMask_ps;
// movemask_epi64 will return this value when every lane has the most significant bit set.
static constexpr int allValuesMask_epi64 = allValuesMask_pd;

// operator <
inline __m256i XM_CALLCONV cmplt_epi8( __m256i a, __m256i b )
{
	return cmpgt_epi8( b, a );
}
// operator <
inline __m256i XM_CALLCONV cmplt_epi16( __m256i a, __m256i b )
{
	return cmpgt_epi16( b, a );
}
// operator <
inline __m256i XM_CALLCONV cmplt_epi32( __m256i a, __m256i b )
{
	return cmpgt_epi32( b, a );
}
// operator <
inline __m256i XM_CALLCONV cmplt_epi64( __m256i a, __m256i b )
{
	return cmpgt_epi64( b, a );
}