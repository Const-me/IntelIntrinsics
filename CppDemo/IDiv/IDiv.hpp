#pragma once
#include "../Intrinsics/sse2.hpp"
#include "../Intrinsics/avx.hpp"
#include "../Intrinsics/avx2.hpp"

namespace Intrinsics
{
	namespace
	{
#include "DivMagic.hpp"
	}
	namespace Sse
	{
#include "DivImpl.inl"
	}
	namespace Avx
	{
#include "DivImpl.inl"
	}
}