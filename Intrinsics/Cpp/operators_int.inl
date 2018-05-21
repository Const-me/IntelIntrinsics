inline VecInteger XM_CALLCONV operator &( VecInteger a, VecInteger b )
{
	return and_all( a, b );
}
inline VecInteger XM_CALLCONV operator |( VecInteger a, VecInteger b )
{
	return or_all( a, b );
}
inline VecInteger XM_CALLCONV operator ^( VecInteger a, VecInteger b )
{
	return xor_all( a, b );
}

inline bool XM_CALLCONV operator ==( VecInteger a, VecInteger b )
{
	return allBytesMask == movemask_epi8( cmpeq_epi32( a, b ) );
}
inline bool XM_CALLCONV operator !=( VecInteger a, VecInteger b )
{
	return allBytesMask != movemask_epi8( cmpeq_epi32( a, b ) );
}