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