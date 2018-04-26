using System.Globalization;
using System.IO;
using System.Threading;

namespace ParseTables
{
	class Program
	{
		const string src = @"C:\Temp\instruction_tables.ods";
		const string dest = @"C:\Z\Fun\IntelIntrinsics\PerformanceData\performance.xml";

		static void Main( string[] args )
		{
			Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
			Thread.CurrentThread.CurrentUICulture = CultureInfo.InvariantCulture;

			var data = TablesParser.parse( src );
			var ser = new XmlSerializerEx(typeof(InstructionsData));
			using( var fs = File.Create( dest ) )
				ser.Serialize( fs, data );
		}
	}
}