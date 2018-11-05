// operator <
inline __m128i XM_CALLCONV cmplt_epi64( __m128i a, __m128i b )
{
	return cmpgt_epi64( b, a );
}