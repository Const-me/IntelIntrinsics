#include "stdafx.h"
#include "brightness.h"
#include "Intrinsics/sse2.hpp"
#include "Intrinsics/sse4.1.hpp"
#include "Intrinsics/avx2.hpp"
#include <assert.h>
#include <random>
#include <algorithm>
#include <chrono>

constexpr uint16_t mulRed = (uint16_t)( 0.29891 * 0x10000 );
constexpr uint16_t mulGreen = (uint16_t)( 0.58661 * 0x10000 );
constexpr uint16_t mulBlue = (uint16_t)( 0.11448 * 0x10000 );

constexpr size_t count = 1024 * 1024;

std::vector<uint32_t> randomImage()
{
	std::independent_bits_engine<std::default_random_engine, 32, uint32_t> re{ 11 };
	std::vector<uint32_t> data( count );
	std::generate( begin( data ), end( data ), std::ref( re ) );
	return std::move( data );
}

namespace Sse
{
	using namespace Intrinsics::Sse;
#include "brightness.inl"
}

namespace Avx
{
	using namespace Intrinsics::Avx;
#include "brightness.inl"
}

void testImageBrightness()
{
	printf( "SSE brightness: " ); Sse::testBrightness();
	// printf( "AVX brightness: " ); Avx::testBrightness();
}