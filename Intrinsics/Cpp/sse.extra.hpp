
		using VecFloat32 = __m128;
		using VecFloat64 = __m128d;
		static constexpr int valuesMask_ps = 0xF;
		static constexpr int valuesMask_pd = 0x3;

		// Shuffle single-precision floating-point elements in "a" using the control in template arguments
		template<uint8_t c1, uint8_t c2, uint8_t c3, uint8_t c4>
		inline __m128 __vectorcall shuffle_ps( __m128 a, __m128 b )
		{
			static_assert( c1 < 4 && c2 < 4 && c3 < 4 && c4 < 4, "Shuffle constants out of range" );
			constexpr int imm = _MM_SHUFFLE( (int)c4, (int)c3, (int)c2, (int)c1 );
			return shuffle_ps<imm>( a, b );
		}

		// Shuffle double-precision floating-point elements using the control in template arguments
		template<uint8_t c1, uint8_t c2>
		inline __m128d __vectorcall shuffle_pd( __m128d a, __m128d b )
		{
			static_assert( c1 < 2 && c2 < 2, "Shuffle constants out of range" );
			constexpr int imm = (int)c1 | (int)( c2 << 1 );
			return shuffle_pd<imm>( a, b );
		}
