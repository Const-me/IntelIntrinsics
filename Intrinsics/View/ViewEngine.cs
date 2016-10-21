using RazorEngine.Configuration;
using RazorEngine.Templating;
using System.Collections.Generic;
using System.IO;

namespace IntrinsicsDocs
{
	/// <summary>A wrapper around RazorEngine</summary>
	static class ViewEngine
	{
		static readonly string HtmlRoot;

		static ViewEngine()
		{
			string exe = System.Reflection.Assembly.GetEntryAssembly().Location;
			string dir = Path.GetDirectoryName( exe );
			HtmlRoot = Path.Combine( dir, "Html" );

			var config = new TemplateServiceConfiguration();
			config.TemplateManager = new ResolvePathTemplateManager( new string[ 1 ] { HtmlRoot } );
			config.Debug = true;
			service = RazorEngineService.Create( config );
		}

		static IRazorEngineService service;

		/// <summary>Copy a file from Html to destination folder.</summary>
		static void copy( string destFolder, string file )
		{
			string src = Path.Combine( HtmlRoot, file );
			if( !File.Exists( src ) )
				throw new FileNotFoundException();
			string dest = Path.Combine( destFolder, file );
			if( File.Exists( dest ) )
				File.Delete( dest );
			File.Copy( src, dest );
		}

		static void runTemplate( string destFolder, string fileName, string template, object model )
		{
			string path = Path.Combine( destFolder, fileName );
			using( FileStream fs = new FileStream( path, FileMode.Create, FileAccess.Write ) )
			using( StreamWriter writer = new StreamWriter( fs, System.Text.Encoding.UTF8, 1024, true ) )
				service.RunCompile( template, writer, model.GetType(), model );
		}

		/// <summary>Generate an html for each intrinsic.</summary>
		public static void produceHtml( string destFolder, IEnumerable<Intrinsic> intrinsics )
		{
			if( !Directory.Exists( destFolder ) )
				Directory.CreateDirectory( destFolder );

			copy( destFolder, "intrinsics.css" );

			foreach( var model in intrinsics )
				runTemplate( destFolder, model.htmlFile(), "intrinsic", model );
		}

		/// <summary>Generate index.html</summary>
		public static void produceIndex( string destFolder, DataSet model )
		{
			runTemplate( destFolder, "index.html", "index", model );
		}

		/// <summary>Generate an HTML for some group of intrinsics</summary>
		public static void produceGroup( string destFolder, Group model )
		{
			runTemplate( destFolder, model.htmlFile(), "group", model );
		}

		public static void produceGroupList( string destFolder, GroupList model  )
		{
			runTemplate( destFolder, model.htmlFile(), "groupList", model );
		}
	}
}