		// Broadcast the low packed 8-bit integer from ""a"" to all elements of ""dst""
		inline void __vectorcall broadcast_epi8( __m128i &dst, __m128i a )
		{
			dst = _mm_broadcastb_epi8( a );
		}
		// Broadcast the low packed 8-bit integer from ""a"" to all elements of ""dst""
		inline void __vectorcall broadcast_epi8( __m256i &dst, __m128i a )
		{
			dst = _mm256_broadcastb_epi8( a );
		}

		// Broadcast the low packed 16-bit integer from ""a"" to all elements of ""dst"".
		inline void __vectorcall broadcast_epi16( __m128i &dst, __m128i a )
		{
			dst = _mm_broadcastw_epi16( a );
		}
		// Broadcast the low packed 16-bit integer from ""a"" to all elements of ""dst"".
		inline void __vectorcall broadcast_epi16( __m256i &dst, __m128i a )
		{
			dst = _mm256_broadcastw_epi16( a );
		}

		// Broadcast the low packed 32-bit integer from ""a"" to all elements of ""dst"".
		inline void __vectorcall broadcast_epi32( __m128i &dst, __m128i a )
		{
			dst = _mm_broadcastd_epi32( a );
		}
		// Broadcast the low packed 32-bit integer from ""a"" to all elements of ""dst"".
		inline void __vectorcall broadcast_epi32( __m256i &dst, __m128i a )
		{
			dst = _mm256_broadcastd_epi32( a );
		}

		// Broadcast the low packed 64-bit integer from ""a"" to all elements of ""dst"".
		inline void __vectorcall broadcast_epi64( __m128i &dst, __m128i a )
		{
			dst = _mm_broadcastq_epi64( a );
		}
		// Broadcast the low packed 64-bit integer from ""a"" to all elements of ""dst"".
		inline void __vectorcall broadcast_epi64( __m256i &dst, __m128i a )
		{
			dst = _mm256_broadcastq_epi64( a );
		}

		// Broadcast 128 bits of integer data from ""a"" to all 128-bit lanes in ""dst"". 
		inline void __vectorcall broadcast_si128( __m256i &dst, __m128i a )
		{
			dst = _mm256_broadcastsi128_si256( a );
		}

		using VecInteger = __m256i;
		static constexpr int allBytesMask = 0xFFFFFFFF;