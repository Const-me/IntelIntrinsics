using System;
using System.Collections.Generic;
using System.Linq;

namespace IntrinsicsDocs.Performance
{
	[Flags]
	enum eArgumentsMask : ushort
	{
		None = 0,

		mmx = 1,
		mmx_xmm = 2,
		mmx_xmm_ymm = 4,
		xmm = 8,
		xmm_ymm = 0x10,
		mmx_xmm_ymm_zmm = 0x20,
		ymm = 0x40,
		ymm_zmm = 0x80,
		zmm = 0x100,
		reg = 0x200,
		memory = 0x8000,
	}

	static class ArgTypes
	{
		static readonly char[] s_comma = new char[ 1 ] { ',' };
		static readonly char[] s_slash = new char[ 2 ] { '/', '\\' };

		public const eArgumentsMask vectorBits = (eArgumentsMask)0x1FF;
		public const eArgumentsMask mmxBits = eArgumentsMask.mmx | eArgumentsMask.mmx_xmm | eArgumentsMask.mmx_xmm_ymm | eArgumentsMask.mmx_xmm_ymm_zmm;
		public const eArgumentsMask sseBits = eArgumentsMask.mmx_xmm | eArgumentsMask.mmx_xmm_ymm | eArgumentsMask.xmm | eArgumentsMask.xmm_ymm | eArgumentsMask.mmx_xmm_ymm_zmm;
		public const eArgumentsMask avxBits = eArgumentsMask.xmm_ymm | eArgumentsMask.mmx_xmm_ymm | eArgumentsMask.mmx_xmm_ymm_zmm | eArgumentsMask.ymm_zmm | eArgumentsMask.ymm;
		public const eArgumentsMask avx512Bits = eArgumentsMask.zmm | eArgumentsMask.ymm_zmm | eArgumentsMask.mmx_xmm_ymm_zmm;

		static readonly Dictionary<string, eArgumentsMask> s_dict = new Dictionary<string, eArgumentsMask>(StringComparer.OrdinalIgnoreCase)
		{
			{ "x", eArgumentsMask.xmm },
			{ "(x)mm", eArgumentsMask.mmx_xmm },
			{ "x/m", eArgumentsMask.xmm },
			{ "y/m", eArgumentsMask.ymm },
			{ "m128", eArgumentsMask.memory },
			{ "i", eArgumentsMask.None },
			{ "m256", eArgumentsMask.memory },
			{ "m512", eArgumentsMask.memory },
			{ "m64", eArgumentsMask.memory },
			{ "mm", eArgumentsMask.mmx },
			{ "m32", eArgumentsMask.memory },
			{ "xmm", eArgumentsMask.xmm },
			{ "m", eArgumentsMask.memory },
			{ "y", eArgumentsMask.ymm },
			{ "z", eArgumentsMask.zmm },
			{ "y/z", eArgumentsMask.ymm_zmm },
			{ "v", eArgumentsMask.mmx_xmm_ymm_zmm }, // any vector register
		};

		static IEnumerable<eArgumentsMask> parseImpl( string raw )
		{

			foreach( string s in raw.Split( s_slash, StringSplitOptions.RemoveEmptyEntries ) )
			{
				eArgumentsMask res = eArgumentsMask.None;
				string[] fields = s.Split( s_comma, StringSplitOptions.RemoveEmptyEntries );
				foreach( string opt in fields )
				{
					eArgumentsMask m;
					if( s_dict.TryGetValue( opt, out m ) )
						res |= m;
				}
				yield return res;
			}
		}

		static readonly Dictionary<string, eArgumentsMask[]> s_cache = new Dictionary<string, eArgumentsMask[]>( StringComparer.OrdinalIgnoreCase );
		static readonly eArgumentsMask[] s_empty = new eArgumentsMask[ 0 ];

		public static eArgumentsMask[] parse( string raw )
		{
			if( String.IsNullOrWhiteSpace( raw ) )
				return s_empty;

			eArgumentsMask[] c;
			if( s_cache.TryGetValue( raw, out c ) )
				return c;
			c = parseImpl( raw ).ToArray();
			s_cache[ raw ] = c;
			return c;
		}
	}
}