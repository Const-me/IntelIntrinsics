﻿using System;
using System.Collections.Generic;

namespace IntrinsicsDocs.Cpp
{
	/// <summary>Intel messed up types in their API. We want them to be normalized, i.e. no "long long"-s, also we want standard typedefs from <stdint.h>.</summary>
	static class TypeMapping
	{
		static readonly Dictionary<string, string> s_typeMap = new Dictionary<string, string>()
		{
			{ "unsigned char", "uint8_t" },
			{ "unsigned short", "uint16_t" },
			{ "unsigned int", "uint32_t" },

			{ "__int32", "int32_t" },
			{ "__int16", "int16_t" },
			{ "__int8", "int8_t" },

			{ "unsigned __int64", "uint64_t" },
			{ "__int64", "int64_t" },
			{ "unsigned long long", "uint64_t" },
			{ "long long", "int64_t" },
		};

		public static string mapType( this string s )
		{
			bool constPointer = false;
			bool pointer = false;
			if( s.EndsWith( "const*" ) || s.EndsWith( "const *" ) )
			{
				constPointer = true;
				s = s.Substring( 0, s.LastIndexOf( "const" ) ).Trim();
			}
			else if( s.Trim().EndsWith( "*" ) )
			{
				pointer = true;
				s = s.Substring( 0, s.LastIndexOf( "*" ) ).Trim();
			}

			string r;
			if( !s_typeMap.TryGetValue( s, out r ) )
				r = s;

			if( constPointer )
				return $"const {r} *";
			else if( pointer )
				return $"{r} *";
			return r;
		}

		static readonly Tuple<string, string>[] i64Types = new Tuple<string, string>[]
		{
			Tuple.Create( "uint64_t", "real_uint64_t" ),
			Tuple.Create( "int64_t", "real_int64_t" ),
		};

		public static string returnValueCast( string s )
		{
			s = s.mapType();
			foreach( var ii in i64Types )
				if( s.Contains( ii.Item1 ) )
					return $"({s})";
			return "";
		}

		public static string castArgNative( this string s, bool alwaysCast )
		{
			s = s.mapType();
			foreach( var ii in i64Types )
				if( s.Contains( ii.Item1 ) )
					return $"({s.Replace( ii.Item1, ii.Item2 )})";
			return alwaysCast ? $"({ s })" : String.Empty;
		}
	}
}