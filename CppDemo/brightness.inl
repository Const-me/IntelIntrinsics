inline VecInteger packRed( VecInteger a, VecInteger b )
{
	const auto mask = set1_epi32( 0xFF );
	a &= mask;
	b &= mask;
	const auto packed = packus_epi32( a, b );
	return slli_all<1>( packed );
}

inline VecInteger packGreen( VecInteger a, VecInteger b )
{
	const auto mask = set1_epi32( 0xFF00 );
	a &= mask;
	b &= mask;
	return packus_epi32( a, b );
}

inline VecInteger packBlue( VecInteger a, VecInteger b )
{
	const auto mask = set1_epi32( 0xFF00 );
	a = srli_all<1>( a );
	b = srli_all<1>( b );
	a &= mask;
	b &= mask;
	return packus_epi32( a, b );
}

inline void loadRgb( const VecInteger *src, VecInteger& red, VecInteger& green, VecInteger& blue )
{
	const auto a = loadu_all( src );
	const auto b = loadu_all( src + 1 );
	red = packRed( a, b );
	green = packGreen( a, b );
	blue = packBlue( a, b );
}

inline VecInteger brightness( VecInteger r, VecInteger g, VecInteger b )
{
	r = mulhi_epu16( r, set1_epu16( mulRed ) );
	g = mulhi_epu16( g, set1_epu16( mulGreen ) );
	b = mulhi_epu16( b, set1_epu16( mulBlue ) );
	const auto result = adds_epu16( adds_epu16( r, g ), b );
	return srli_epi16<8>( result );
}

static void convertToGrayscale( const uint32_t* sourcePixels, uint8_t* destinationBytes, size_t count )
{
	assert( 0 == ( count % sizeof( VecInteger ) ) );

	const VecInteger* src = (const VecInteger*)sourcePixels;
	const VecInteger* const srcEnd = (const VecInteger*)( sourcePixels + count );
	VecInteger* dest = (VecInteger*)destinationBytes;

	while( src < srcEnd )
	{
		VecInteger r, g, b;

		loadRgb( src, r, g, b );
		const auto low = brightness( r, g, b );

		loadRgb( src + 2, r, g, b );
		const auto hi = brightness( r, g, b );

		const auto bytes = packus_epi16( low, hi );
		storeu_all( dest, bytes );

		src += 4;
		dest++;
	}
}

void testBrightness()
{
	const std::vector<uint32_t> source = randomImage();
	std::vector<uint8_t> result( count );

	const auto start = std::chrono::high_resolution_clock::now();

	convertToGrayscale( source.data(), result.data(), count );

	const auto finish = std::chrono::high_resolution_clock::now();
	const std::chrono::duration<double, std::milli> elapsed = finish - start;
	const double ms = elapsed.count();

	// Compute and print XOR of the result to make sure compiler doesn't optimize away things
	uint8_t x = 0;
	for( uint8_t b : result )
		x ^= b;
	printf( "%f ms, the xor value is 0x%02x\n", ms, (int)x );
}