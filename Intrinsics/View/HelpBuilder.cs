using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace IntrinsicsDocs
{
	static class HelpBuilder
	{
		static void writeIntrinsics( this IndexWriter w, IEnumerable<Intrinsic> e )
		{
			w.open();
			foreach( var i in e )
				w.item( i );
			w.close();
		}

		const string projectName = "intrinsics.hhp";

		static string produceProject( string destFolder, DataSet dataSet )
		{
			string helpProj = @"[OPTIONS]
Compatibility=1.1 or later
Compiled file=Intrinsics.%VERSION%.chm
Contents file=contents.hhc
Index file=index.hhk
Default Topic=html/index.html
Full-text search=Yes
Language=0x409 English (United States)
Title=Intel Intrinsics Guide, version %VERSION%, from %DATE%
[FILES]
html\*.html
html\*.css
[INFOTYPES]";
			helpProj = helpProj.Replace( "%VERSION%", dataSet.version );
			helpProj = helpProj.Replace( "%DATE%", dataSet.date );

			string path = Path.Combine( destFolder, projectName );
			using( FileStream fs = new FileStream( path, FileMode.Create, FileAccess.Write ) )
			using( StreamWriter tw = new StreamWriter( fs, Encoding.ASCII ) )
				tw.Write( helpProj );

			return path;
		}

		static bool isAvx512( Intrinsic i )
		{
			if( i.name.StartsWith( "_mm512_" ) )
				return true;
			string[] cpu = i.CPUID;
			if( null == cpu )
				return false;
			if( cpu.Any( s => s.StartsWith( "AVX512", StringComparison.InvariantCultureIgnoreCase ) ) )
				return true;
			if( cpu.Contains( "KNCNI" ) )
				return true;
			return false;
		}

		static bool notAvx512( Intrinsic i )
		{
			return !isAvx512( i );
		}

		public static void produce( string destFolder, DataSet dataSet )
		{
			if( !Directory.Exists( destFolder ) )
				Directory.CreateDirectory( destFolder );

			// Drop AVX512 intrinsics
			dataSet.intrinsic = dataSet.intrinsic.Where( notAvx512 ).ToArray();

			// The main content
			string html = Path.Combine( destFolder, "html" );
			ViewEngine.produceHtml( html, dataSet.intrinsic );

			// Index.html
			ViewEngine.produceIndex( html, dataSet );

			// Index
			string hhk = Path.Combine( destFolder, "index.hhk" );
			using( IndexWriter w = new IndexWriter( hhk, false ) )
				w.writeIntrinsics( dataSet.intrinsic.OrderBy( p => p.id ) );

			// ToC
			string hhc = Path.Combine( destFolder, "contents.hhc" );
			using( IndexWriter w = new IndexWriter( hhc, true ) )
			{
				w.open();
				w.item( "Intel Intrinsics Guide", "html/index.html" );
				w.open();

				// All of them
				{
					Group all = Group.all( dataSet.intrinsic );
					ViewEngine.produceGroup( html, all );
					w.item( "All of them", "html/" + all.htmlFile() );
					w.writeIntrinsics( dataSet.intrinsic.OrderBy( p => p.id ) );
				}

				// Technology
				{
					List<Group> byTech = Group.group( dataSet.intrinsic, "tech", i => i.tech );
					// Sort "Other" to the end
					Group other = byTech.FirstOrDefault( g => g.title.ToLowerInvariant() == "other" );
					if( null != other )
					{
						byTech.Remove( other );
						byTech.Add( other );
					}

					GroupList gl = new GroupList( byTech, "Technologies" );
					ViewEngine.produceGroupList( html, gl );

					w.item( "Technology", "html/" + gl.htmlFile() );
					w.open();
					foreach( var g in byTech )
					{
						ViewEngine.produceGroup( html, g );
						w.item( g );
						w.writeIntrinsics( g.items );
					}
					w.close();
				}

				// Category
				{
					List<Group> byCat = Group.group( dataSet.intrinsic, "cat", i => i.category );
					GroupList gl = new GroupList( byCat, "Categories" );
					ViewEngine.produceGroupList( html, gl );
					w.item( "Category", "html/" + gl.htmlFile() );
					w.open();
					foreach( var g in byCat )
					{
						ViewEngine.produceGroup( html, g );
						w.item( g );
						w.writeIntrinsics( g.items );
					}
					w.close();
				}
			}

			// Project
			string hhp = produceProject( destFolder, dataSet );

			// Report success
			Console.WriteLine( "Produced the HTML Help Project:" );
			Console.WriteLine( hhp );
			Console.WriteLine( "Use following command to build the CHM: " );
			Console.WriteLine( "hhc.exe {0}", projectName );
			Console.WriteLine( "If you don't have hhc.exe, install from there:" );
			Console.WriteLine( "https://www.microsoft.com/en-us/download/details.aspx?id=21138" );
		}
	}
}