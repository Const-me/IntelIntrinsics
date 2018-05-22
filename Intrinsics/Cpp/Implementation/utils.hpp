#pragma once

// Append type suffix to the name, e.g. when TYPE_SUFFIX is defined to 'ps', SIMD_OP( add ) will expand into add_ps name
#define SIMD_OP( OP ) OP ## _ ## TYPE_SUFFIX

// Calling convention for SIMD functions
#define XM_CALLCONV __vectorcall