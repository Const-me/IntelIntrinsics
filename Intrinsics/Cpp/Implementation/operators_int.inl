#define VECTOR_TYPE VecInteger
#define TYPE_SUFFIX all
#include "operators_bitwise.inl"
#undef VECTOR_TYPE
#undef TYPE_SUFFIX

// Equality operator
inline bool XM_CALLCONV operator ==( VecInteger a, VecInteger b )
{
	return allValuesMask_epi8 == movemask_epi8( cmpeq_epi32( a, b ) );
}
inline bool XM_CALLCONV operator !=( VecInteger a, VecInteger b )
{
	return !( a == b );
}