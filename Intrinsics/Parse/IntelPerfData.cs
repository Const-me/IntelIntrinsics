using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

namespace IntrinsicsDocs
{
	public static class IntelPerfData
	{
		public interface iJsonLoad
		{
			void load( JToken token );
		}

		public class Perf : iJsonLoad
		{
			public readonly string lat, tpt;
			public Perf( JToken l, JToken t )
			{
				lat = ( l as JValue )?.Value as string;
				tpt = ( t as JValue )?.Value as string;
			}
			public Perf() { throw new NotSupportedException(); }
			public void load( JToken token ) { throw new NotSupportedException(); }
		}

		public abstract class Dict<T> : Dictionary<string, T>, iJsonLoad
			where T : iJsonLoad, new()
		{
			public Dict() : base( StringComparer.OrdinalIgnoreCase )
			{ }

			public void load( JToken token )
			{
				var obj = token as JObject;
				if( null != obj )
				{
					foreach( var v in obj )
						this[ v.Key ] = loadValue( v.Value );
					return;
				}
				var arr = token as JArray;
				if( null != arr )
				{
					foreach( var c in arr )
					{
						obj = c as JObject;
						Debug.Assert( obj.Count == 1 );
						var prop = obj.First as JProperty;
						this[ prop.Name ] = loadValue( prop.Value );
					}
					return;
				}
				throw new ArgumentException();
			}

			protected virtual T loadValue( JToken token )
			{
				T res = new T();
				iJsonLoad jl = res;
				jl.load( token );
				return res;
			}

			public T lookup( string k )
			{
				T res;
				if( TryGetValue( k, out res ) )
					return res;
				return default( T );
			}
		}

		static readonly Dictionary<string, int> s_generations = new Dictionary<string, int>(StringComparer.OrdinalIgnoreCase)
		{
			{ "Sandy Bridge", 2 },
			{ "Ivy Bridge", 3 },
			{ "Haswell", 4 },
			{ "Broadwell", 5 },
			{ "Skylake", 6 },
			{ "Knights Landing", 7 },
		};

		static int generation( this string arch )
		{
			int res;
			if( s_generations.TryGetValue( arch, out res ) )
				return res;
			return 100;
		}

		/// <summary>Key = architecture, value = performance</summary>
		public class Table : Dict<Perf>
		{
			protected override Perf loadValue( JToken token )
			{
				var pd = token as JObject;
				return new Perf( pd[ "l" ], pd[ "t" ] );
			}
			public IEnumerable<KeyValuePair<string, Perf>> entries()
			{
				return this.OrderBy( kvp => kvp.Key.generation() );
			}
		}

		/// <summary>Key = arguments e.g. "m256, ymm, ymm". Usually empty.</summary>
		public class Instruction : Dict<Table> { }

		/// <summary>Key = instruction name, e.g. "VMASKMOVPD"</summary>
		public class Tech : Dict<Instruction> { }

		/// <summary>Key = tech, e.g. "FMA"</summary>
		public class DataSet : Dict<Tech> { }

		public static DataSet load( string jsonFile )
		{
			string content;
			using( var reader = new StreamReader( jsonFile, Encoding.UTF8 ) )
				content = reader.ReadToEnd();
			content = content.Substring( content.IndexOf( '{' ) );
			JObject json = JObject.Parse( content );

			DataSet res = new DataSet();
			res.load( json );
			return res;
		}

		public static bool hasPerformanceData( this DataSet dataSet, Intrinsic intr )
		{
			return null != dataSet.lookup( intr );
		}
		public static Table lookup( this DataSet dataSet, Intrinsic intr )
		{
			if( null == intr.instruction )
				return null;
			Instruction instr = dataSet.lookup( intr.tech )?.lookup( intr.instruction.name );
			if( null == instr )
				return null;
			foreach( var kvp in instr )
			{
				if( String.Equals( kvp.Key, intr.instruction.form, StringComparison.OrdinalIgnoreCase ) )
					return kvp.Value;
			}
			return instr.lookup( string.Empty );
		}
	}
}