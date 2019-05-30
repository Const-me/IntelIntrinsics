bool testCompare()
{
	srand( 0 );

	constexpr int iterations = 1024;
	constexpr int items = sizeof( VecInteger ) / 2;
	alignas( alignof( VecInteger ) ) std::array<uint16_t, items> as, bs;
	for( int i = 0; i < iterations; i++ )
	{
		makeRandom( as, bs );
		const VecInteger a = load_all( (const VecInteger *)as.data() );
		const VecInteger b = load_all( (const VecInteger *)bs.data() );
		if( cmplt_all( a, b ) != cmplt_scalar( as, bs ) )
			return false;
	}
	return true;
}