using System;

namespace IntrinsicsDocs.Performance
{
	enum eRegSize : byte
	{
		None = 0,
		mmx = 1,
		xmm = 2,
		ymm = 4,
		zmm = 8,
		scalar8 = 0x10,
		scalar16 = 0x20,
		scalar32 = 0x40,
		scalar64 = 0x80,
		scalarMask = 0xF0,
	}

	static class RegSizes
	{
		static eRegSize regSizeScalar( this Intrinsic i )
		{
			string name = i.name.ToLowerInvariant();
			if( name.EndsWith( "_u8" ) ) return eRegSize.scalar8;
			if( name.EndsWith( "_u16" ) || name.EndsWith( "16_step" ) ) return eRegSize.scalar16;
			if( name.EndsWith( "_u32" ) || name.EndsWith( "32_step" ) ) return eRegSize.scalar32;
			if( name.EndsWith( "_u64" ) || name.EndsWith( "64_step" ) ) return eRegSize.scalar64;
			return eRegSize.None;
		}

		public static eRegSize regSize( this Intrinsic i )
		{
			if( i.instruction.name == "crc32" )
				return i.regSizeScalar();
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
				case "popcnt":
				case "rdrand":
				case "rdseed":
					return i.regSizeScalar();
			}
			throw new NotImplementedException();
			// return eRegSize.None;
		}

		public static bool match( this eArgumentsMask argMask, eRegSize regSize )
		{
			eArgumentsMask thisMask = eArgumentsMask.None;
			if( 0 != ( regSize & eRegSize.scalarMask ) )
			{
				if( 0 != ( argMask & eArgumentsMask.memory ) )
					return false;
				argMask &= ArgTypes.scalarBits;
				switch( regSize  )
				{
					case eRegSize.scalar8:
						thisMask = eArgumentsMask.reg8;
						break;
					case eRegSize.scalar16:
						thisMask = eArgumentsMask.reg16 | eArgumentsMask.reg16_32 | eArgumentsMask.reg16_32_64;
						break;
					case eRegSize.scalar32:
						thisMask = eArgumentsMask.reg32 | eArgumentsMask.reg16_32 | eArgumentsMask.reg16_32_64;
						break;
					case eRegSize.scalar64:
						thisMask = eArgumentsMask.reg64 | eArgumentsMask.reg16_32_64;
						break;
				}
				return 0 != ( argMask & thisMask );
			}

			switch( regSize )
			{
				default:
					return eArgumentsMask.None == ( argMask & eArgumentsMask.memory );
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