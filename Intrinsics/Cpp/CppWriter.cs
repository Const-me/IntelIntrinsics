using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace IntrinsicsDocs.Cpp
{
	static class CppWriter
	{
		static string argPrototype( Intrinsic.Param p )
		{
			return $"{p.type} {p.varname}";
		}

		static bool isEmptyParams( this Intrinsic i )
		{
			if( i.parameter.isEmpty() )
				return true;
			if( i.parameter.Length == 1 && i.parameter[ 0 ].type == "void" )
				return true;
			return false;
		}

		static string argPrototype( this Intrinsic i, bool skipImm = false )
		{
			if( i.isEmptyParams() )
				return "";
			IEnumerable<Intrinsic.Param> items = ( skipImm ) ? i.parameter.Where( ii => !isImm( ii ) ) : i.parameter;
			return $" { String.Join( ", ", items.Select( argPrototype ) ) } ";
		}
		static string templatePrototype( Intrinsic.Param p )
		{
			string type = p.type;
			type = type.stripPrefix( "const ", "const\t" );
			return $"{type} {p.varname}";
		}
		static string templatePrototype( this Intrinsic i )
		{
			IEnumerable<Intrinsic.Param> items = i.parameter.Where( ii => isImm( ii ) );
			return $"{ String.Join( ", ", items.Select( templatePrototype ) ) }";
		}
		static string argCall( this Intrinsic i )
		{
			if( i.isEmptyParams() )
				return "";
			return $" { String.Join( ", ", i.parameter.Select( ip => ip.varname ) ) } ";
		}

		static bool isImm( Intrinsic.Param p )
		{
			return p.type.EndsWith( "int" ) && p.varname.StartsWith( "imm" );
		}

		const string completeSuffix = "_all";

		static string cppName( this Intrinsic i )
		{
			if( i.name.StartsWith("_mm_"))
				return i.name.stripPrefix( "_mm_" ).replaceSuffix( "_si128", completeSuffix );

			if( i.name.StartsWith( "_mm256_" ) )
				return i.name.stripPrefix( "_mm256_" ).replaceSuffix( "_si256", completeSuffix );

			if( i.name.StartsWith( "_mm512_" ) )
				return i.name.stripPrefix( "_mm512_" ).replaceSuffix( "_si512", completeSuffix );

			return i.name;
		}

		static string singleLineDescription( this Intrinsic i )
		{
			return i.shortDescription().Replace( "\n", "" ).Replace( "\r", "" ).Replace( " \t", " " );
		}

		public static void write( this StreamWriter sw, Intrinsic i, string callConv )
		{
			sw.WriteLine( "	// " + i.singleLineDescription() );

			if( !String.IsNullOrWhiteSpace( callConv ) )
				callConv = " " + callConv;

			if( i.isEmptyParams() || !i.parameter.Any( isImm ) )
			{
				sw.WriteLine( $"	inline { i.rettype }{ callConv } { i.cppName() }({ i.argPrototype() })" );
				sw.WriteLine( "	{" );
				sw.WriteLine( $"		return { i.name }({ i.argCall() });" );
				sw.WriteLine( "	}" );
			}
			else
			{
				sw.WriteLine( $"	template<{i.templatePrototype()}>" );
				sw.WriteLine( $"	inline { i.rettype }{ callConv } { i.cppName() }({ i.argPrototype( true ) })" );
				sw.WriteLine( "	{" );
				sw.WriteLine( $"		return { i.name }({ i.argCall() });" );
				sw.WriteLine( "	}" );
			}

			sw.WriteLine();
		}
	}
}