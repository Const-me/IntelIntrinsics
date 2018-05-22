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
			if( p.type.EndsWith( "int" ) && p.varname.StartsWith( "imm" ) )
				return true;
			if( p.type == "const int" )
				return true;
			if( p.type == "int" && ( p.varname == "rounding" || p.varname == "count" || p.varname == "index" || p.varname == "scale" ) )
				return true;
			return false;
		}

		const string completeSuffix = "_all";

		static string cppName( this Intrinsic i )
		{
			string n = i.name;
			if( n.StartsWith( "_mm_" ) )
				n = n.stripPrefix( "_mm_" ).replaceSuffix( "_si128", completeSuffix );
			else if( n.StartsWith( "_mm256_" ) )
				return n.stripPrefix( "_mm256_" ).replaceSuffix( "_si256", completeSuffix );
			else if( n.StartsWith( "_mm512_" ) )
				return n.stripPrefix( "_mm512_" ).replaceSuffix( "_si512", completeSuffix );

			if( n.StartsWith( "setr_" ) )
			{
				// Intel messed up in the headers, what they call "reverse order" is normal order i.e. increasing RAM addresses.
				// They probably meant "reverse order" compared to the native stack but that's meaningless for C++ developers, people expect left to right order to be normal.
				n = n.Replace( "setr_", "set_" );
				i.fixedSetOrder = true;
			}

			return n;
		}

		static string singleLineDescription( this Intrinsic i )
		{
			string res = i.shortDescription().Replace( "\n", "" ).Replace( "\r", "" ).Replace( " \t", " " );
			if( i.fixedSetOrder )
				res = res.stripSuffix( " in reverse order" );
			return res.Trim();
		}

		static void write( this StreamWriter sw, Intrinsic i, string callConv )
		{
			string name = i.cppName();
			sw.WriteLine( "		// " + i.singleLineDescription() );

			if( !String.IsNullOrWhiteSpace( callConv ) )
				callConv = " " + callConv;

			if( i.isEmptyParams() || !i.parameter.Any( isImm ) )
			{
				sw.WriteLine( $"		inline { i.rettype }{ callConv } { name }({ i.argPrototype() })" );
				sw.WriteLine( "		{" );

				sw.Write( "			" );
				if( "void" != i.rettype )
					sw.Write( "return " );
				sw.WriteLine( $"{ i.name }({ i.argCall() });" );

				sw.WriteLine( "		}" );
			}
			else
			{
				sw.WriteLine( $"		template<{i.templatePrototype()}>" );
				sw.WriteLine( $"		inline { i.rettype }{ callConv } { name }({ i.argPrototype( true ) })" );
				sw.WriteLine( "		{" );

				sw.Write( "			" );
				if( "void" != i.rettype )
					sw.Write( "return " );
				sw.WriteLine( $"{ i.name }({ i.argCall() });" );

				sw.WriteLine( "		}" );
			}
		}

		public static void write( this StreamWriter sw, IEnumerable<Intrinsic> all, string callConv )
		{
			bool first = true;
			foreach( var i in all )
			{
				if( first )
					first = false;
				else
					sw.WriteLine();
				sw.write( i, callConv );
			}
		}
	}
}