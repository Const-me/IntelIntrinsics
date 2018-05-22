#pragma once
// Calling convention for SIMD functions
#ifndef XM_CALLCONV
#define XM_CALLCONV __vectorcall
#endif

// Append type suffix to the name, e.g. when TYPE_SUFFIX is defined to 'ps', SIMD_OP( mul ) will expand into mul_ps name. This is used internally to implement same operators for 32 and 64 bit floats.
#define SIMD_OP( OP ) OP ## _ ## TYPE_SUFFIX