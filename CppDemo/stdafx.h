#pragma once
#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
#include <random>

inline float randomFloat()
{
	// https://stackoverflow.com/a/36527160/126995
	static std::default_random_engine e;
	static std::uniform_real_distribution<> dis( 0, 1 ); // rage 0 - 1
	return (float)dis( e );
}

#include <stdint.h>
#include <intrin.h>
#include <emmintrin.h>
#include <immintrin.h>