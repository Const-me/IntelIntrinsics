# FAQ

## Why the SIMD?

It’s the only way to approach advertised performance figures of all CPU newer than 10-15 years. For example, Avx::fmadd_ps can run 2 times per clock, and it multiplies+adds 8 floating point values. That’s 32 FLOPS/cycle: https://stackoverflow.com/a/15657772/126995

## Why not automatic vectorization?

Based on my experience, compilers can only vectorize very simple cases.

## Why not wrapper classes?

Wrappers work well for graphics code because in 99% cases it only needs Vector3f, Vector4f and arrays of them.
CPU instructions working on integer SIMD registers can process 8, 16, 32, and 64-bit lanes, some of them are signed/unsigned, and some of them use saturated math.
Not all combinations are supported for every operation/data type. This makes it very hard to design good API.

## Why stick to Intel-assigned names like “srli_epi16”, why not rename to “shiftRight16” or “operator>>”?

With original names it’s easier to use documentation or search for answers.

## Why there’s no vector dot product or matrix multiplication?

There’s already a good library for that, [Microsoft DirectXMath](https://github.com/Microsoft/DirectXMath), with MIT license.
Microsoft’s XMVECTOR is a typedef for the same `__m128` native data type, so the interop is seamless.

## Why there’s no AVX512 support?

I don’t have AVX512 hardware to test the result.

## What do these wrappers do?

Most of them do nothing, just call the original ones. There're couple of exceptions.

* set_xxx argument order is flipped so it's now correct. For example, Sse::set_ps( 1, 2, 3, 4 ) will make a register with [ 1, 2, 3, 4 ] values. setr_xxx is removed.

* Implemented additional set_xxx and set1_xxx for unsigned integer types, e.g. set1_epu8( uint8_t ), set1_epu16( uint16_t ), etc.

* renamed a few intrinsics, e.g. `_mm256_broadcastq_epi64` is exposed as `Avx::broadcast_epi64`, without the 'q'.

* Implemented a few template-based swizzle functions.