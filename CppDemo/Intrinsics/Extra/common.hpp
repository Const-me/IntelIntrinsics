#pragma once
#include <stdint.h>

// Calling convention for these SIMD functions
#ifndef XM_CALLCONV
#if defined( _MSC_VER ) || defined( __clang__ )
// Both VC++ and clang support __vectorcall keyword. Not that it's too important, should be inlined anyway, but compilers are free to ignore `inline` keyword as they see fit.
#define XM_CALLCONV __vectorcall
#else
// Other compilers don't support __vectorcall.
#define XM_CALLCONV
#endif
#endif

// https://stackoverflow.com/a/1489971/126995
#define SIMD_OP_IMPL_2( FUN, SUFFIX ) FUN ## _ ## SUFFIX
#define SIMD_OP_IMPL( FUN, SUFFIX ) SIMD_OP_IMPL_2( FUN, SUFFIX )

// Append type suffix to the name, e.g. when TYPE_SUFFIX is defined to 'ps', SIMD_OP( mul ) will expand into mul_ps name. This is used internally to implement same operators for e.g. 32 and 64 bit floats.
#define SIMD_OP( OP ) SIMD_OP_IMPL( OP, TYPE_SUFFIX )

namespace Intrinsics
{
	// Workaround for a bug in clang: https://stackoverflow.com/q/50552347/126995

#ifdef _MSC_VER
	// On Windows, everything just work out of the box. But because the code is cross-platform, we still need the typedefs.
	using real_int64_t = int64_t;
	using real_uint64_t = uint64_t;
#else
	// On Linux, int64_t type is incompatible with `long long`, and <emmintrin.h> / <immintrin.h> headers use `long long` instead of the standard int64_t / uint64_t types.
	// So we need to cast every single time. Fortunately everything is auto-generated, so it wasn't that hard.
	using real_int64_t = long long;
	using real_uint64_t = unsigned long long;
#endif
}

// Workaround for "overloaded operator must have at least one parameter of class or enumeration type" in clang / "must have an argument of class or enumerated type" in gcc: disabling overloaded operators.
#ifdef _MSC_VER
#define INTRINSICS_SUPPORT_OPERATORS 1
#else
#define INTRINSICS_SUPPORT_OPERATORS 0
#endif