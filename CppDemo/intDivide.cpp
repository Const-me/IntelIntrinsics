#include "stdafx.h"
#include "intDivide.h"
#include "IDiv/IDiv.hpp"
#include <array>
#include <limits>
#include "Intrinsics/sse2.hpp"
#include "Intrinsics/avx2.hpp"

template<class TScalar, class TVector, class FuncScalar, class FuncVector>
static inline bool testAll( FuncScalar fnScalar, FuncVector fnSimd )
{
	// For operators !=
	using namespace Intrinsics::Sse;
	using namespace Intrinsics::Avx;

	constexpr int64_t VAL_MAX = (int64_t)( 1 ) << ( sizeof( TScalar ) * 8 );
	constexpr size_t regLen = sizeof( TVector ) / sizeof( TScalar );

	bool res = true;
#pragma omp parallel for
	for( int64_t i = 0; i < VAL_MAX; i += regLen )
	{
		TVector src, resultScalar;

		TScalar* pSrc = (TScalar*)( &src );
		TScalar* pScalar = (TScalar*)( &resultScalar );

		for( size_t j = 0; j < regLen; j++ )
		{
			const TScalar val = (TScalar)( i + j );
			pSrc[ j ] = val;
			pScalar[ j ] = fnScalar( val );
		}

		const TVector resultSimd = fnSimd( src );
		if( cmpneq_all( resultSimd, resultScalar ) )
			res = false;
	}
	return res;
}

namespace Intrinsics
{
	namespace Sse
	{
#include "intDivide.inl"
	}
	namespace Avx
	{
#include "intDivide.inl"
	}
}

void testIntDivide()
{
	printf( "Testing SSE division.. " );
	fflush( stdout );
	printf( "%s\n", Intrinsics::Sse::testEverything() ? "passed" : "FAILED" );

	printf( "Testing AVX division.. " );
	fflush( stdout );
	printf( "%s\n", Intrinsics::Avx::testEverything() ? "passed" : "FAILED" );
}