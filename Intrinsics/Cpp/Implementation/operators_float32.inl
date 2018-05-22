#define VECTOR_TYPE VecFloat32
#define TYPE_SUFFIX ps
#include "operators_bitwise.inl"
#include "operators_float_impl.inl"
#undef VECTOR_TYPE
#undef TYPE_SUFFIX

// Shuffle single-precision (32-bit) floating-point elements in "a" within 128-bit lanes using the control in template arguments
template<uint8_t c1, uint8_t c2, uint8_t c3, uint8_t c4>
inline VecFloat32 XM_CALLCONV shuffle_ps( VecFloat32 a, VecFloat32 b )
{
	static_assert( c1 < 4 && c2 < 4 && c3 < 4 && c4 < 4, "Shuffle constants out of range" );
	constexpr int imm = _MM_SHUFFLE( (int)c4, (int)c3, (int)c2, (int)c1 );
	return shuffle_ps<imm>( a, b );
}