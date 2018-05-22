#pragma once

template<uint32_t div>
struct DivMagic;

template<>
struct DivMagic<3>
{
	static constexpr uint32_t mul32 = 0xAAAAAAAB;
	static constexpr int shift32 = 33;

	static constexpr uint16_t mul16 = 0xAAAB;
	static constexpr int shift16 = 1;
};

template<>
struct DivMagic<5>
{
	static constexpr uint32_t mul32 = 0xCCCCCCCD;
	static constexpr int shift32 = 34;

	static constexpr uint16_t mul16 = 0xCCCD;
	static constexpr int shift16 = 2;
};

template<>
struct DivMagic<6>
{
	static constexpr uint32_t mul32 = 0xAAAAAAAB;
	static constexpr int shift32 = 34;

	static constexpr uint16_t mul16 = 0xAAAB;
	static constexpr int shift16 = 2;
};