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
		using VecInteger = __m256i;