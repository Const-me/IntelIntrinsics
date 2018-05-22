template<uint8_t divisor>
bool testDiv_epu8()
{
	return testAll<uint8_t, VecInteger>( []( uint8_t i ) { return i / divisor; }, []( VecInteger v ) { return div_epu8<divisor>( v ); } );
}
bool testDiv_epu8_all()
{
	return testDiv_epu8<2>() && testDiv_epu8<3>() && testDiv_epu8<4>() && testDiv_epu8<5>() && testDiv_epu8<6>();
}

template<uint16_t divisor>
bool testDiv_epu16()
{
	return testAll<uint16_t, VecInteger>( []( uint16_t i ) { return i / divisor; }, []( VecInteger v ) { return div_epu16<divisor>( v ); } );
}
bool testDiv_epu16_all()
{
	return testDiv_epu16<2>() && testDiv_epu16<3>() && testDiv_epu16<4>() && testDiv_epu16<5>() && testDiv_epu16<6>();
}

template<uint32_t divisor>
bool testDiv_epu32()
{
	return testAll<uint32_t, VecInteger>( []( uint32_t i ) { return i / divisor; }, []( VecInteger v ) { return div_epu32<divisor>( v ); } );
}
bool testDiv_epu32_all()
{
	return testDiv_epu32<2>() && testDiv_epu32<3>() && testDiv_epu32<4>() && testDiv_epu32<5>() && testDiv_epu32<6>();
}

bool testEverything()
{
	return testDiv_epu8_all() && testDiv_epu16_all() && testDiv_epu32_all();
}