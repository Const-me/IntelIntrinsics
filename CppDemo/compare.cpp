#include "stdafx.h"
#include "compare.h"
#include "Intrinsics/sse2.hpp"
#include "Intrinsics/avx2.hpp"
#include <array>

// Reference, i.e. scalar comparison implementation.
template<size_t count>
inline bool cmplt_scalar( const std::array<uint16_t, count>& a, const std::array<uint16_t, count>& b )
{
	for( int i = count - 1; i >= 0; i-- )
	{
		if( a[ i ] < b[ i ] )
			return true;
		if( a[ i ] > b[ i ] )
			return false;
	}
	return false;
}

template<size_t count>
inline void makeRandom( std::array<uint16_t, count>& x )
{
	for( uint16_t& v : x )
		v = (uint16_t)rand();
}

template<size_t count>
inline void makeRandom( std::array<uint16_t, count>& a, std::array<uint16_t, count>& b )
{
	makeRandom( a );
	makeRandom( b );
}

namespace Intrinsics
{
	namespace Sse
	{
#include "compare.inl"
	}
	namespace Avx
	{
#include "compare.inl"
	}
}

void testCompare()
{
	printf( "Testing SSE compare.. " );
	fflush( stdout );
	printf( "%s\n", Intrinsics::Sse::testCompare() ? "passed" : "FAILED" );

	printf( "Testing AVX compare.. " );
	fflush( stdout );
	printf( "%s\n", Intrinsics::Avx::testCompare() ? "passed" : "FAILED" );
}