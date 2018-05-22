#pragma once
#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>

inline float randomFloat()
{
	constexpr float mul = ( float )1.0f / (float)RAND_MAX;
	return mul * rand();
}

#include <stdint.h>
#include <intrin.h>
#include <emmintrin.h>
#include <immintrin.h>