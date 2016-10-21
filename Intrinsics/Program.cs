using System;
using System.IO;
using System.Xml.Serialization;

namespace IntrinsicsDocs
{
	static class Program
	{
		const string localName = "IntelIntrinsics-3.3.15.xml";
		const string remoteUri = @"https://software.intel.com/sites/landingpage/IntrinsicsGuide/files/data-3.3.15.xml";

		static void mainImpl()
		{
			string xml = DataSource.getXml( localName, remoteUri );
			XmlSerializer ser = new XmlSerializer(typeof(DataSet));
			DataSet data;
			using( StreamReader sr = new StreamReader( xml ) )
				data = (DataSet)ser.Deserialize( sr );

			data.fixAfterLoading();
			data.intrinsic = UniqueID.make( data.intrinsic );

			Console.WriteLine( "Loaded the XML" );

			string tempFolder = Utils.inTemp( "IntrinsicsChm" );
			HelpBuilder.produce( tempFolder, data );
		}

		static void Main( string[] args )
		{
			try
			{
				mainImpl();

				Console.WriteLine( "Press any key to continue." );
				Console.ReadKey();
			}
			catch( Exception ex )
			{
				Console.WriteLine( "Failed: {0}", ex.Message );
				Console.WriteLine( ex.ToString() );
			}
		}
	}
}