		// Broadcast a single-precision (32-bit) floating-point element from memory to all elements of ""dst"".
		inline void broadcast_ss( __m128 &dst, float const *mem_addr )
		{
			dst = _mm_broadcast_ss( mem_addr );
		}

		// Broadcast a single-precision (32-bit) floating-point element from memory to all elements of ""dst"".
		inline void broadcast_ss( __m256 &dst, float const *mem_addr )
		{
			dst = _mm256_broadcast_ss( mem_addr );
		}

		using VecFloat32 = __m256;
		using VecFloat64 = __m256d;
		static constexpr int allValuesMask_ps = 0xFF;
		static constexpr int allValuesMask_pd = 0xF;

		// Shuffle single-precision (32-bit) floating-point elements in "a" within 128-bit lanes using the control in template arguments
		template<uint8_t c1, uint8_t c2, uint8_t c3, uint8_t c4>
		inline __m128 __vectorcall shuffle_ps( __m128 a, __m128 b )
		{
			static_assert( c1 < 4 && c2 < 4 && c3 < 4 && c4 < 4, "Shuffle constants out of range" );
			constexpr int imm = _MM_SHUFFLE( (int)c4, (int)c3, (int)c2, (int)c1 );
			return shuffle_ps<imm>( a, b );
		}

		// Shuffle double-precision (64-bit) floating-point elements within 128-bit lanes using the control in template arguments
		template<uint8_t c1, uint8_t c2, uint8_t c3, uint8_t c4>
		inline __m128d __vectorcall shuffle_pd( __m128d a, __m128d b )
		{
			static_assert( c1 < 2 && c2 < 2 && c3 < 2 && c4 < 2, "Shuffle constants out of range" );
			constexpr int imm = (int)c1 | (int)( c2 << 1 ) | (int)( c3 << 2 ) | (int)( c4 << 3 );
			return shuffle_pd<imm>( a, b );
		}
