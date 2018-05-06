using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

namespace IntrinsicsDocs
{
	// Intel has designed their performance JSON data format in a way that's hard to map automatically with JSON serializer attributes. It's doable but would require custom converters, i.e. too much code to write.
	// Instead, this static class parses the complete document into JObject, then builds strongly-typed dataset from that. The JSON is merely 88kb, so performance is still good but the code is simpler.
	public static class IntelPerfData
	{
		// ==== Public interface ====
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

		public interface iTable
		{
			IEnumerable<KeyValuePair<string, Perf>> entries();
		}

		public interface iDataSet
		{
			iTable lookup( Intrinsic intr );
		}

		public static iDataSet load( string jsonFile )
		{
			// Read into string
			string content;
			using( var reader = new StreamReader( jsonFile, Encoding.UTF8 ) )
				content = reader.ReadToEnd();
			// The JSON starts with "perf_js = {", need to get rid of "perf_js = " part
			content = content.Substring( content.IndexOf( '{' ) );
			// Parse the JSON
			JObject json = JObject.Parse( content );
			// Build the dataset
			DataSet res = new DataSet();
			res.load( json );
			return res;
		}

		public static bool hasPerformanceData( this iDataSet dataSet, Intrinsic intr )
		{
			return null != dataSet.lookup( intr );
		}

		// ==== Implementation details ====
		interface iJsonLoad
		{
			void load( JToken token );
		}

		abstract class Dict<T> : Dictionary<string, T>, iJsonLoad
			where T : iJsonLoad, new()
		{
			public Dict() : base( StringComparer.OrdinalIgnoreCase )
			{ }

			/// <summary>Load JSON node into this</summary>
			public void load( JToken token )    // iJsonLoad method
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
						obj = (JObject)c;
						Debug.Assert( obj.Count == 1 );
						var prop = obj.First as JProperty;
						this[ prop.Name ] = loadValue( prop.Value );
					}
					return;
				}
				throw new ArgumentException();
			}

			/// <summary>Load JSON node into a newly constructed value</summary>
			protected virtual T loadValue( JToken token )
			{
				T res = new T();
				iJsonLoad jl = res;
				jl.load( token );   // C# doesn't support generic argument constraints like "new(JToken)", that's why iJsonLoad interface.
				return res;
			}

			/// <summary>Lookup by key, returns null if not found.</summary>
			public T lookup( string k )
			{
				T res;
				if( TryGetValue( k, out res ) )
					return res;
				return default( T );
			}
		}

		// Sort table entries by CPU generation
		static readonly Dictionary<string, int> s_generations = new Dictionary<string, int>( StringComparer.OrdinalIgnoreCase )
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
		class Table : Dict<Perf>, iTable
		{
			protected override Perf loadValue( JToken token )
			{
				// Perf is readonly class, accepts constructor arguments but doesn't actually support iJsonLoad interface. That's why overriding this method.
				var pd = (JObject)token;
				return new Perf( pd[ "l" ], pd[ "t" ] );
			}
			IEnumerable<KeyValuePair<string, Perf>> iTable.entries()
			{
				return this.OrderBy( kvp => kvp.Key.generation() );
			}
		}

		/// <summary>Key = arguments e.g. "m256, ymm, ymm". Usually contains the only key, empty string.</summary>
		class Instruction : Dict<Table> { }

		/// <summary>Key = instruction name, e.g. "VMASKMOVPD"</summary>
		class Tech : Dict<Instruction> { }

		/// <summary>Key = CPUID, e.g. "FMA"</summary>
		class DataSet : Dict<Tech>, iDataSet
		{
			Instruction lookup( Intrinsic intr )
			{
				if( null == intr.CPUID )
					return null;
				foreach( string cpu in intr.CPUID )
				{
					var res = lookup( cpu )?.lookup( intr.instruction.name );
					if( null != res )
						return res;
				}
				return null;
			}

			iTable iDataSet.lookup( Intrinsic intr )
			{
				if( null == intr.instruction )
					return null;
				Instruction instr = lookup( intr );
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
}