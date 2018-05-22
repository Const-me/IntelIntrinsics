using IntrinsicsDocs.Performance;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace IntrinsicsDocs
{
	/// <summary>Extension methods for <see cref="Intrinsic"> that are called by the view engine.</summary>
	public static class Html
	{
		static void span( this StringBuilder sb, string c, string content )
		{
			sb.AppendFormat( "<span class='{0}'>{1}</span>", c, content );
		}

		public static string rawTitle( this Intrinsic i )
		{
			StringBuilder sb = new StringBuilder( 256 );
			sb.span( "b", i.rettype );

			sb.AppendFormat( " {0}(", i.name );

			if( i.parameter.isEmpty() )
			{
				sb.Append( ")" );
				return sb.ToString();
			}

			sb.Append( " " );
			foreach( var p in i.parameter )
			{
				sb.span( "b", p.type );
				sb.Append( " " );
				sb.span( "g", p.varname );

				if( p == i.parameter.Last() )
					sb.Append( " )" );
				else
					sb.Append( ", " );
			}

			return sb.ToString();
		}

		public static string synopsis( this Intrinsic i )
		{
			StringBuilder sb = new StringBuilder( 256 );
			sb.AppendFormat( "#include \"{0}\"", i.header );
			sb.AppendLine();

			if( null != i.instruction )
				sb.AppendFormat( "Instruction: {0}", i.instruction.name );
			else
				sb.Append( "Instruction: N/A" );

			if( i.CPUID.notEmpty() )
			{
				sb.AppendLine();
				if( 1 == i.CPUID.Length )
					sb.AppendFormat( "CPUID Flag: {0}", i.CPUID[ 0 ] );
				else
					sb.AppendFormat( "CPUID Flags: {0}", String.Join( " + ", i.CPUID[ 0 ] ) );
			}

			if( i.category.notEmpty() )
			{
				sb.AppendLine();
				sb.AppendFormat( "Category: {0}", i.category );
			}
			return sb.ToString();
		}

		internal static PerfData perfData;
		internal static IntelPerfData.iDataSet intelPerf;

		public static bool hasPerformanceData( this Intrinsic i )
		{
			return intelPerf.hasPerformanceData( i ) || perfData.hasPerformanceData( i );
		}

		static string rawPerformanceThirdParty( this Intrinsic i )
		{

			StringBuilder sb = new StringBuilder( 256 );
			sb.AppendLine( "		<table>" );
			sb.Append( "			<tr><th>Architecture</th><th>Latency</th>" );
			sb.Append( @"<th title=""Reciprocal of the throughputs, i.e. average number of clock cycles"">Throughput</th>" );
			sb.Append( "<th>μops</th>" );
			sb.AppendLine( "</tr>" );

			if( perfData.hasPerformanceData( i ) )
			{
				var data = perfData.table( i );
				foreach( var p in data )
				{
					sb.AppendFormat( "			<tr><td>{0}</td><td>{1}</td>", p.cpu, p.latency ?? string.Empty );
					sb.AppendFormat( "<td>{0}</td>", p.throughput ?? string.Empty );
					sb.AppendFormat( "<td>{0}</td>", p.uops ?? string.Empty );
					sb.AppendLine( "</tr>" );
				}
			}
			if( intelPerf.hasPerformanceData( i ) )
			{
				foreach( var p in intelPerf.lookup( i ).entries() )
				{
					sb.AppendFormat( @"			<tr class=""i"" title=""as reported by Intel""><td>{0}</td><td>{1}</td>", p.Key, p.Value.lat ?? string.Empty );
					sb.AppendFormat( "<td>{0}</td>", p.Value.tpt ?? string.Empty );
					sb.AppendLine( "<td></td></tr>" );  // no uops
				}
			}
			sb.AppendLine( "		</table>" );
			return sb.ToString();
		}

		public static string rawPerformance( this Intrinsic i )
		{
			// return i.rawPerformanceIntel();
			return i.rawPerformanceThirdParty();
		}

		static readonly string[] stopMarkers = new string[]
		{
			", and store the result",
			", storing the result",
			".",
			" and stores the results",
			", store the result",
			";",
			" based on the comparison",
			", and set the corresponding bit",
			", rotating",
			", and return",
			// " and store",
			", storing them",
			" and performing "
		};

		static readonly Dictionary<string, string> dictReplace = new Dictionary<string, string>()
		{
			{  "single-precision (32-bit)", "single-precision" },
			{  "double-precision (64-bit)", "double-precision" },
		};

		const int minLength = 64;   // Don't truncate shorter then this count of characters

		public static string shortDescription( this Intrinsic i )
		{
			string res = i.description;

			foreach( var kvp in dictReplace )
				res = res.Replace( kvp.Key, kvp.Value );

			foreach( string m in stopMarkers )
			{
				int ind = res.IndexOf( m );
				if( ind > 0 && ind > minLength )
					res = res.Substring( 0, ind );
			}
			return res;
		}
	}
}