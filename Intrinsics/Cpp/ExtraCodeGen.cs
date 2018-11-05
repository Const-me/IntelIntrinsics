using System;
using System.IO;
using System.Text;

namespace IntrinsicsDocs.Cpp
{
	static class ExtraCodeGen
	{
		class ExtraWriter : IDisposable
		{
			StreamWriter writer;

			static readonly Encoding s_enc = new UTF8Encoding( false, true );

			readonly string ns;

			public ExtraWriter( string destFolder, string name, string ns, params string[] extraIncludes )
			{
				string path = Path.Combine( destFolder, name );
				path += ".hpp";
				writer = new StreamWriter( path, false, s_enc );
				this.ns = ns;
				writer.WriteLine( HeaderFile.headerComment );
				writer.WriteLine( "#pragma once" );
				foreach( string inc in extraIncludes )
					writer.WriteLine( "#include {0}", inc );
				writer.WriteLine();
				writer.WriteLine( "namespace Intrinsics" );
				writer.WriteLine( "{" );
				writer.WriteLine( "	namespace {0}", ns );
				writer.WriteLine( "	{" );
			}

			public void Dispose()
			{
				writer.WriteLine( "	}}	// namespace Intrinsics::{0}", ns );
				writer.Write( "}	// namespace Intrinsics" );

				writer.Flush();
				writer.Close();
				writer.Dispose();
				writer = null;
			}

			public void writeExtra( eExtra what, string VECTOR_TYPE, string TYPE_SUFFIX )
			{
				ExtraCodeParser.write( writer, what, 2, VECTOR_TYPE, TYPE_SUFFIX );
			}
			public void writeExtra( eExtra what, string VECTOR_TYPE, string TYPE_SUFFIX, string cns )
			{
				writer.WriteLine( "		namespace {0}", cns );
				writer.WriteLine( "		{" );
				ExtraCodeParser.write( writer, what, 3, VECTOR_TYPE, TYPE_SUFFIX );
				writer.WriteLine( "		}}	// namespace Intrinsics::{0}::{1}", ns, cns );
			}
			public void line()
			{
				writer.WriteLine();
			}
			public void line( string l )
			{
				writer.WriteLine( l );
			}
		}

		public static bool hasExtraHeader( string cpuid )
		{
			switch( cpuid )
			{
				case "sse": return true;
				case "sse2": return true;
				case "sse4.2": return true;
				case "avx": return true;
				case "avx2": return true;
			}
			return false;
		}

		static void extraFloat( this ExtraWriter w, string f, string suffix, bool avx )
		{
			if( avx )
				w.writeExtra( eExtra.float_avx_cmp, f, suffix );
			w.writeExtra( eExtra.float_math, f, suffix );
			w.writeExtra( eExtra.float_cmp_ops, f, suffix );
			w.writeExtra( eExtra.bitwise, f, suffix );
		}
		static void extraInteger( this ExtraWriter w, string i, bool avx )
		{
			w.writeExtra( eExtra.int_common, i, "all" );
			w.writeExtra( eExtra.bitwise, i, "all" );

			w.line();
			w.line( "		// ==== Couple missing integer comparison intrinsics ====" );
			w.writeExtra( eExtra.int_math, i, "epi8" );
			w.writeExtra( eExtra.int_math, i, "epi16" );
			w.writeExtra( eExtra.int_math, i, "epi32" );
			if( avx )
				w.writeExtra( eExtra.int_math, i, "epi64" );

			w.line();
			w.line( "#if INTRINSICS_SUPPORT_OPERATORS" );
			w.writeExtra( eExtra.int_math_ops, i, "epi8", "Int8" );
			w.writeExtra( eExtra.int_math_ops, i, "epi16", "Int16" );
			w.writeExtra( eExtra.int_math_ops, i, "epi32", "Int32" );
			if( avx )
				w.writeExtra( eExtra.int_math_ops, i, "epi64", "Int64" );
			w.line( "#endif // INTRINSICS_SUPPORT_OPERATORS" );
		}

		public static void generateExtras( string destFolder )
		{
			ExtraCodeParser.copyStatic( "fp16c.hpp", destFolder );

			string extra = Path.Combine( destFolder, "Extra" );
			if( !Directory.Exists( extra ) )
				Directory.CreateDirectory( extra );
			ExtraCodeParser.copyStatic( "common.hpp", extra );

			string f = "__m128";
			string d = "__m128d";
			string i = "__m128i";

			// SSE1
			using( var w = new ExtraWriter( extra, "sse-extra", "Sse" ) )
			{
				w.writeExtra( eExtra.sse1, f, "ps" );
				w.extraFloat( f, "ps", false );
			}

			// SSE2
			using( var w = new ExtraWriter( extra, "sse2-extra", "Sse", @"""../sse.hpp""" ) )
			{
				// Double stuff
				w.writeExtra( eExtra.sse2, d, "pd" );
				w.extraFloat( d, "pd", false );
				w.line();
				w.extraInteger( i, false );
			}

			// SSE 4.2
			using( var w = new ExtraWriter( extra, "sse4.2-extra", "Sse", @"""../sse2.hpp""", @"""../sse4.1.hpp""" ) )  // cmpeq_epi64 is SSE 4.1, while cmpgt_epi64 is SSE 4.2. Looks like Intel forgot about that, and fixed later :-)
			{
				w.writeExtra( eExtra.sse42, null, null );
				w.writeExtra( eExtra.int_math, i, "epi64" );
				w.line();
				w.line( "#if INTRINSICS_SUPPORT_OPERATORS" );
				w.writeExtra( eExtra.int_math_ops, i, "epi64", "Int64" );
				w.line( "#endif // INTRINSICS_SUPPORT_OPERATORS" );
			}

			// AVX1
			f = "__m256";
			d = "__m256d";
			i = "__m256i";
			using( var w = new ExtraWriter( extra, "avx-extra", "Avx" ) )
			{
				w.writeExtra( eExtra.avx1, f, "ps" );
				w.extraFloat( f, "ps", true );
				w.extraFloat( d, "pd", true );
			}

			// AVX2
			using( var w = new ExtraWriter( extra, "avx2-extra", "Avx", @"""../avx.hpp""" ) )
			{
				w.writeExtra( eExtra.avx2, f, "ps" );
				w.extraInteger( i, true );
			}
		}
	}
}