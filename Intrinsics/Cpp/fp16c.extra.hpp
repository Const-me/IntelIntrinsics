		// Convert packed half-precision (16-bit) floating-point elements in ""a"" to packed single-precision floating-point elements
		inline void __vectorcall cvtph_ps( __m128 &dst, __m128i a )
		{
			dst = _mm_cvtph_ps( a );
		}

		// Convert packed half-precision (16-bit) floating-point elements in ""a"" to packed single-precision floating-point elements
		inline void __vectorcall cvtph_ps( __m256 &dst, __m128i a )
		{
			dst = _mm256_cvtph_ps( a );
		}
