using System;
using System.Collections.Generic;

namespace IntrinsicsDocs.Performance
{
	enum eRegSize : byte
	{
		None = 0,
		mmx = 1,
		xmm = 2,
		ymm = 4,
		zmm = 8,
	}

	static class RegSizes
	{
		public static eRegSize regSize( this Intrinsic i )
		{
			if( i.CPUID.isEmpty() )
				return eRegSize.None;

			string cpuid = String.Join( "/", i.CPUID ).ToLowerInvariant();
			if( cpuid.Contains( "sse" ) || cpuid.Contains( "aes" ) )
				return eRegSize.xmm;
			if( cpuid.Contains( "avx512" ) )
				return eRegSize.zmm;
			if( cpuid.Contains( "avx" ) )
				return eRegSize.ymm;
			if( cpuid.Contains( "mmx" ) )
				return eRegSize.mmx;

			if( i.instruction.form.StartsWith( "xmm" ) )
				return eRegSize.xmm;
			if( cpuid == "fma" || cpuid == "fp16c" || cpuid== "kncni" )
			{
				if( i.id.StartsWith( "_mm256_" ) )
					return eRegSize.ymm;
				if( i.id.StartsWith( "_mm_" ) )
					return eRegSize.xmm;
				if( i.id.StartsWith( "_mm512_" ) )
					return eRegSize.zmm;

				throw new NotImplementedException();
			}
			switch( cpuid )
			{
				case "fxsr":
				case "xsave":
				case "xsave/xsaveopt":
					return eRegSize.None;
			}
			throw new NotImplementedException();
			// return eRegSize.None;
		}

		public static bool match( this eArgumentsMask argMask, eRegSize regSize )
		{
			eArgumentsMask thisMask = eArgumentsMask.None;
			switch( regSize )
			{
				default:
					return true;
				case eRegSize.mmx:
					thisMask = ArgTypes.mmxBits;
					break;
				case eRegSize.xmm:
					thisMask = ArgTypes.sseBits;
					break;
				case eRegSize.ymm:
					thisMask = ArgTypes.avxBits;
					break;
				case eRegSize.zmm:
					thisMask = ArgTypes.avx512Bits;
					break;
			}
			return eArgumentsMask.None == ( argMask & ( ArgTypes.vectorBits ^ thisMask ) );
		}

		public static bool regsOnly( this eArgumentsMask argMask )
		{
			return 0 == ( argMask & eArgumentsMask.memory );
		}
	}
}