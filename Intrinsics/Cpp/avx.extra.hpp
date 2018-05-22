		using VecFloat32 = __m256;
		using VecFloat64 = __m256d;
		static constexpr int allValuesMask_ps = 0xFF;
		static constexpr int allValuesMask_pd = 0xF;

		// Shuffle single-precision (32-bit) floating-point elements in "a" within 128-bit lanes using the control in template arguments
		template<uint8_t c1, uint8_t c2, uint8_t c3, uint8_t c4>
		inline __m256 XM_CALLCONV shuffle_ps( __m256 a, __m256 b )
		{
			static_assert( c1 < 4 && c2 < 4 && c3 < 4 && c4 < 4, "Shuffle constants out of range" );
			constexpr int imm = _MM_SHUFFLE( (int)c4, (int)c3, (int)c2, (int)c1 );
			return shuffle_ps<imm>( a, b );
		}

		// Shuffle double-precision (64-bit) floating-point elements within 128-bit lanes using the control in template arguments
		template<uint8_t c1, uint8_t c2, uint8_t c3, uint8_t c4>
		inline __m256d XM_CALLCONV shuffle_pd( __m256d a, __m256d b )
		{
			static_assert( c1 < 2 && c2 < 2 && c3 < 2 && c4 < 2, "Shuffle constants out of range" );
			constexpr int imm = (int)c1 | (int)( c2 << 1 ) | (int)( c3 << 2 ) | (int)( c4 << 3 );
			return shuffle_pd<imm>( a, b );
		}
