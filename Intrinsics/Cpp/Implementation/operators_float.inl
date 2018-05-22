#define VECTOR_TYPE VecFloat32
#define TYPE_SUFFIX ps
#include "operators_bitwise.inl"
#include "operators_float_impl.inl"
#undef VECTOR_TYPE
#undef TYPE_SUFFIX

#define VECTOR_TYPE VecFloat64
#define TYPE_SUFFIX pd
#include "operators_bitwise.inl"
#include "operators_float_impl.inl"
#undef VECTOR_TYPE
#undef TYPE_SUFFIX