using System;
using System.IO;
using System.Net;

namespace IntrinsicsDocs
{
	static class DataSource
	{
		public static string getXml( string localName, string remoteUri )
		{
			string local = Utils.inTemp( localName );
			if( File.Exists( local ) )
			{
				Console.WriteLine( "Found XML in the local cache" );
				return local;
			}

			Console.WriteLine( "The XML not found in the local cache, downloading.." );

			WebClient wc = new WebClient();
			string tmp = local + ".tmp";
			Uri intelDataFile = new Uri( remoteUri, UriKind.Absolute );
			wc.DownloadFile( intelDataFile, tmp );
			File.Move( tmp, local );

			Console.WriteLine( "Downloaded the XML from intel.com" );
			return local;
		}
	}
}