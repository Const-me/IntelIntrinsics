using IntrinsicsDocs.Cpp;
using IntrinsicsDocs.Performance;
using System;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Security;
using System.Security.Permissions;
using System.Security.Policy;
using System.Xml.Serialization;

namespace IntrinsicsDocs
{
	static class Program
	{
		/// <summary>Data file with the documentation, @ intel.com</summary>
		const string remoteUri = @"https://software.intel.com/sites/landingpage/IntrinsicsGuide/files/data-3.4.1.xml";

		/// <summary>Starting from version 3.4.1, Intel decided to split the data into 2 pieces, one XML another one JSON. Obviously, in now in 2018 the XML no longer works, and user just love waiting for seconds for client-side JS rendering to complete. The more web requests, the better.</summary>
		const string perfUri = @"https://software.intel.com/sites/landingpage/IntrinsicsGuide/files/perf.json";

		static string localName { get { return "IntelIntrinsics-" + remoteUri.Split( '-' ).Last(); } }
		static string localNamePerf { get { return Path.ChangeExtension( localName, ".json" ); } }

		const string pathPerf = @"C:\Z\Fun\IntelIntrinsics\PerformanceData\performance.xml";

		static void mainImpl()
		{
			Html.perfData = new PerfData( pathPerf );

			string xml = DataSource.download( localName, remoteUri, "XML" );
			XmlSerializer ser = new XmlSerializer(typeof(DataSet));
			DataSet data;
			using( StreamReader sr = new StreamReader( xml ) )
				data = (DataSet)ser.Deserialize( sr );

			string json = DataSource.download( localNamePerf, perfUri, "perf.json" );
			Html.intelPerf = IntelPerfData.load( json );

			data.fixAfterLoading();
			data.intrinsic = UniqueID.make( data.intrinsic );

			Console.WriteLine( "Loaded the XML" );

			// string tempFolder = Utils.inTemp( "IntrinsicsChm" );
			// HelpBuilder.produce( tempFolder, data );

			CppBuilder.produce( @"C:\Temp\2remove\IntrinsicsCpp", data );
		}

		static void perfTest()
		{
			var perf = new PerfData( pathPerf, @"C:\Z\Fun\IntelIntrinsics\PerformanceData\dump.txt" );
			foreach( var p in Unpack.errors() )
				Console.WriteLine( p );
		}

		static void Main( string[] args )
		{
			// perfTest(); return;

			// https://github.com/Antaris/RazorEngine/issues/244#issuecomment-85507351
			if( AppDomain.CurrentDomain.IsDefaultAppDomain() )
			{
				// RazorEngine cannot clean up from the default appdomain...
				Console.WriteLine( "Switching to second AppDomain, for RazorEngine" );
				AppDomainSetup adSetup = new AppDomainSetup();
				adSetup.ApplicationBase = AppDomain.CurrentDomain.SetupInformation.ApplicationBase;
				var current = AppDomain.CurrentDomain;
				// You only need to add strongnames when your appdomain is not a full trust environment.
				var strongNames = new StrongName[0];

				var domain = AppDomain.CreateDomain(
					"MyMainDomain", null,
					current.SetupInformation, new PermissionSet(PermissionState.Unrestricted),
					strongNames);
				domain.ExecuteAssembly( Assembly.GetExecutingAssembly().Location );
				return;
			}

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