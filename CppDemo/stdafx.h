#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#ifdef _MSC_VER
#include <intrin.h>
#endif
#include <emmintrin.h>
#include <immintrin.h>

inline float randomFloat()
{
	constexpr float mul = ( float )1.0f / (float)RAND_MAX;
	return mul * rand();
}