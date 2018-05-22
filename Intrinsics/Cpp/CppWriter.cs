using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace IntrinsicsDocs.Cpp
{
	static class CppWriter
	{
		static string argPrototype( Intrinsic.Param p )
		{
			return $"{p.type.mapType()} {p.varname}".Replace( " * ", " *" );
		}
		static string argPrototypeUnsigned( Intrinsic.Param p )
		{
			string tp = "unsigned " + p.type;
			return $"{tp.mapType()} {p.varname}".Replace( " * ", " *" );
		}

		static bool isEmptyParams( this Intrinsic i )
		{
			if( i.parameter.isEmpty() )
				return true;
			if( i.parameter.Length == 1 && i.parameter[ 0 ].type == "void" )
				return true;
			return false;
		}

		// Intel messed up types in their API. We want them to be normalized, i.e. no "long long"-s, also we want standard typedefs from <stdint.h>. Fix that.
		static readonly Dictionary<string, string> s_typeMap = new Dictionary<string, string>()
		{
			{ "unsigned char", "uint8_t" },
			{ "unsigned short", "uint16_t" },
			{ "unsigned int", "uint32_t" },
			{ "unsigned __int64", "uint64_t" },
			{ "__int64", "int64_t" },
			{ "unsigned long long", "uint64_t" },
			{ "long long", "int64_t" },
		};
		static string mapType( this string s )
		{
			bool constPointer = false;
			if( s.EndsWith( "const*" ) || s.EndsWith( "const *" ) )
			{
				constPointer = true;
				s = s.Substring( 0, s.LastIndexOf( "const" ) ).Trim();
			}

			string r;
			if( !s_typeMap.TryGetValue( s, out r ) )
				r = s;

			if( constPointer )
				return $"const {r} *";
			return r;
		}

		static string argPrototype( this Intrinsic i, bool skipImm = false )
		{
			if( i.isEmptyParams() )
				return "";
			IEnumerable<Intrinsic.Param> items = ( skipImm ) ? i.parameter.Where( ii => !isImm( ii ) ) : i.parameter;
			if( i.flipArgumentsOrder )
				items = items.Reverse();

			Func<Intrinsic.Param, string> fnProto = argPrototype;
			if( i.castArgumentsUnsigned )
				fnProto = argPrototypeUnsigned;

			return $" { String.Join( ", ", items.Select( fnProto ) ) } ";
		}
		static string templatePrototype( Intrinsic.Param p )
		{
			string type = p.type;
			type = type.stripPrefix( "const ", "const\t" );
			return $"{type.mapType()} {p.varname}";
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
			Func<Intrinsic.Param, string> fnProto = ip => ip.varname;
			if( i.castArgumentsUnsigned )
				fnProto = ip => $"({ip.type.mapType()}){ip.varname}";
			return $" { String.Join( ", ", i.parameter.Select( fnProto ) ) } ";
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
				n = n.stripPrefix( "_mm256_" ).replaceSuffix( "_si256", completeSuffix );
			else if( n.StartsWith( "_mm512_" ) )
				n = n.stripPrefix( "_mm512_" ).replaceSuffix( "_si512", completeSuffix );

			if( n.StartsWith( "set_" ) )
			{
				// What Intel calls "reverse order" is normal order i.e. increasing RAM addresses. Fix that.
				i.flipArgumentsOrder = true;
			}

			// Intel messed up in the names of "broadcast" family of intrinsics, they have type suffixes in two places in their names, e.g. _mm_broadcastsd_pd instead of _mm_broadcast_pd. Fix that.
			string sBroadcast = "broadcast";
			if( n.StartsWith( sBroadcast ) )
			{
				if( n == "broadcastsi128_si256" )
					n = "broadcast_si128";
				else
				{
					int pos = n.IndexOf( '_', sBroadcast.Length );
					n = sBroadcast + n.Substring( pos );
				}
			}

			// No need for "_all" in AES intrinsics, there's a single version of them
			if( n.StartsWith( "aes" ) && n.EndsWith( completeSuffix ) )
				n = n.replaceSuffix( completeSuffix, "" );

			return n;
		}

		static string singleLineDescription( this Intrinsic i )
		{
			string res = i.shortDescription().Replace( "\n", "" ).Replace( "\r", "" ).Replace( " \t", " " );
			if( i.flipArgumentsOrder )
				res = res.stripSuffix( " in reverse order" );
			return res.Trim();
		}

		static void write( this StreamWriter sw, Intrinsic i, string callConv )
		{
			string name = i.cppName();
			if( !String.IsNullOrWhiteSpace( callConv ) )
				callConv = " " + callConv;

			writeImpl:

			sw.WriteLine( "		// " + i.singleLineDescription() );

			if( i.isEmptyParams() || !i.parameter.Any( isImm ) )
			{
				sw.WriteLine( $"		inline { i.rettype.mapType() }{ callConv } { name }({ i.argPrototype() })" );
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
				sw.WriteLine( $"		inline { i.rettype.mapType() }{ callConv } { name }({ i.argPrototype( true ) })" );
				sw.WriteLine( "		{" );

				sw.Write( "			" );
				if( "void" != i.rettype )
					sw.Write( "return " );
				sw.WriteLine( $"{ i.name }({ i.argCall() });" );

				sw.WriteLine( "		}" );
			}

			if( name.StartsWith( "set_epi" ) || name.StartsWith( "set1_epi" ) )
			{
				name = name.Replace( "_epi", "_epu" );
				i.castArgumentsUnsigned = true;
				goto writeImpl;
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