#define VECTOR_TYPE VecInteger
#define TYPE_SUFFIX all
#include "operators_bitwise.inl"
#undef VECTOR_TYPE
#undef TYPE_SUFFIX

// Test for equality
inline bool XM_CALLCONV equals( VecInteger a, VecInteger b )
{
	return allValuesMask_epi8 == movemask_epi8( cmpeq_epi32( a, b ) );
}
// Test for inequality
inline bool XM_CALLCONV notEquals( VecInteger a, VecInteger b )
{
	return allValuesMask_epi8 != movemask_epi8( cmpeq_epi32( a, b ) );
}

#if INTRINSICS_SUPPORT_OPERATORS
// Equality operators
inline bool XM_CALLCONV operator ==( VecInteger a, VecInteger b )
{
	return equals( a, b );
}
inline bool XM_CALLCONV operator !=( VecInteger a, VecInteger b )
{
	return notEquals( a, b );
}
#endif // INTRINSICS_SUPPORT_OPERATORS