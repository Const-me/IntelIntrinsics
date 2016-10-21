using System;
using System.IO;
using System.Text;

namespace IntrinsicsDocs
{
	class IndexWriter : IDisposable
	{
		readonly TextWriter tw;

		int align = 0;
		string alignString()
		{
			return new string( ' ', ( align + 1 ) * 2 );
		}

		public IndexWriter( string path, bool ToC )
		{
			FileStream fs = new FileStream( path, FileMode.Create, FileAccess.Write );
			tw = new StreamWriter( fs, Encoding.UTF8 );
			tw.writeLines( "<!DOCTYPE HTML PUBLIC \"-//IETF//DTD HTML/EN\">", "<HTML>", "<BODY>" );
			if( ToC )
				tw.writeLines( "  <OBJECT type=\"text/site properties\">", "    <param name=\"ImageType\" value=\"Folder\">", "  </OBJECT>" );
		}

		public void Dispose()
		{
			while( align > 0 )
				close();
			tw.WriteLine( "</BODY>\n</HTML>" );
			tw.Flush();
			tw.Dispose();
		}

		public void open()
		{
			tw.WriteLine( "{0}<UL>", alignString() );
			align++;
		}

		public void close()
		{
			align--;
			tw.WriteLine( "{0}</UL>", alignString() );
		}

		public void item( string name, string href )
		{
			string ss = alignString();
			tw.WriteLine( "{0}<LI> <OBJECT type=\"text/sitemap\">", ss );
			tw.WriteLine( "{0}  <param name=\"Name\" value=\"{1}\">", ss, name );
			tw.WriteLine( "{0}  <param name=\"Local\" value=\"{1}\">", ss, href );
			tw.WriteLine( "{0}</OBJECT>", ss );
		}

		public void item( Intrinsic i )
		{
			item( i.id, "html\\" + i.htmlFile() );
		}

		public void item( Group g )
		{
			item( g.title, "html\\" + g.htmlFile() );
		}
	}
}