template<uint32_t div>
inline VecInteger XM_CALLCONV div_epu32( VecInteger x );

template<uint16_t div>
inline VecInteger XM_CALLCONV div_epu16( VecInteger x );

template<uint8_t div>
inline VecInteger XM_CALLCONV div_epu8( VecInteger x );

// Divide by 2
template<>
inline VecInteger XM_CALLCONV div_epu32<2>( VecInteger x )
{
	return srli_epi32<1>( x );
}
template<>
inline VecInteger XM_CALLCONV div_epu16<2>( VecInteger x )
{
	return srli_epi16<1>( x );
}
template<>
inline VecInteger XM_CALLCONV div_epu8<2>( VecInteger x )
{
	return and_all( srli_epi32<1>( x ), set1_epu8( 0x7F ) );
}

// Divide by 4
template<>
inline VecInteger XM_CALLCONV div_epu32<4>( VecInteger x )
{
	return srli_epi32<2>( x );
}
template<>
inline VecInteger XM_CALLCONV div_epu16<4>( VecInteger x )
{
	return srli_epi16<2>( x );
}
template<>
inline VecInteger XM_CALLCONV div_epu8<4>( VecInteger x )
{
	return and_all( srli_epi32<2>( x ), set1_epu8( 0x3F ) );
}

// Divide by the rest of them, using constants in DivMagic.hpp
namespace SimdDivImpl
{
	template<int shift>
	inline VecInteger XM_CALLCONV mulShift_epu32( VecInteger x, VecInteger mul )
	{
		// Multiply 32-bit elements #0 and #3
		const VecInteger mm = mul_epu32( x, mul );
		// Shift
		const VecInteger sh = srli_epi64<shift>( mm );
		return sh;
	}

	template<uint32_t mul32, int shift>
	inline VecInteger XM_CALLCONV div_epu32_impl( VecInteger x )
	{
		const VecInteger mul = set1_epi32( mul32 );
		const VecInteger even = mulShift_epu32<shift>( x, mul );
		const VecInteger odd = mulShift_epu32<shift>( srli_all<4>( x ), mul );
		return or_all( even, slli_all<4>( odd ) );
	}

	template<uint16_t mul16, int shift>
	inline VecInteger XM_CALLCONV div_epu16_impl( VecInteger x )
	{
		const VecInteger mul = set1_epu16( mul16 );
		x = mulhi_epu16( x, mul );
		x = srli_epi16<shift>( x );
		return x;
	}
}

template<uint32_t div>
inline VecInteger XM_CALLCONV div_epu32( VecInteger x )
{
	using tMagic = DivMagic<div>;
	return SimdDivImpl::div_epu32_impl<tMagic::mul32, tMagic::shift32>( x );
}

template<uint16_t div>
inline VecInteger XM_CALLCONV div_epu16( VecInteger x )
{
	using tMagic = DivMagic<div>;
	return SimdDivImpl::div_epu16_impl<tMagic::mul16, tMagic::shift16>( x );
}

template<uint8_t div>
inline VecInteger XM_CALLCONV div_epu8( VecInteger x )
{
	const VecInteger even = div_epu16<div>( and_all( x, set1_epu16( 0xFF ) ) );
	const VecInteger odd = div_epu16<div>( srli_epi16<8>( x ) );
	return or_all( even, slli_epi16<8>( odd ) );
}