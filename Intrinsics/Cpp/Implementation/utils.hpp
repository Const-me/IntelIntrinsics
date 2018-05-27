#pragma once
#include <stdint.h>

// Calling convention for SIMD functions
#ifndef XM_CALLCONV
#define XM_CALLCONV __vectorcall
#endif

// https://stackoverflow.com/a/1489971/126995
#define SIMD_OP_IMPL_2( FUN, SUFFIX ) FUN ## _ ## SUFFIX
#define SIMD_OP_IMPL( FUN, SUFFIX ) SIMD_OP_IMPL_2( FUN, SUFFIX )

// Append type suffix to the name, e.g. when TYPE_SUFFIX is defined to 'ps', SIMD_OP( mul ) will expand into mul_ps name. This is used internally to implement same operators for 32 and 64 bit floats.
#define SIMD_OP( OP ) SIMD_OP_IMPL( OP, TYPE_SUFFIX )

namespace Intrinsics
{
#ifndef _MSC_VER
	// Workaround for a bug in clang: https://stackoverflow.com/q/50552347/126995
	using int64_t = long long;
	using uint64_t = unsigned long long;
#endif
}