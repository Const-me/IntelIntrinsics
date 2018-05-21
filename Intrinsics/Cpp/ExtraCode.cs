using System;
using System.Collections.Generic;
using System.Linq;

namespace IntrinsicsDocs.Cpp
{
	class ExtraCode
	{
		static readonly Dictionary<string, string> s_extraCode = new Dictionary<string, string>()
		{
			{  "avx",
@"
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
"
			}
		};

		public static string extra( string f )
		{
			f = f.ToLowerInvariant();
			string r;
			if( s_extraCode.TryGetValue( f, out r ) )
				return r;
			return null;
		}
	}
}