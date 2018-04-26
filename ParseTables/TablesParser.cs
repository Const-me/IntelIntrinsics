using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using Excel = Microsoft.Office.Interop.Excel;

namespace ParseTables
{
	class TablesParser
	{
		public static InstructionsData parse( string path )
		{
			var excelApp = new Excel.Application();
			excelApp.Visible = false;
			var wb = excelApp.Workbooks.Open( path, null, true );

			try
			{
				var tp = new TablesParser( wb );
				return tp.result();
			}
			finally
			{
				wb.Close( false );
				excelApp.Quit();
				releaseObject( wb );
				releaseObject( excelApp );
			}
		}

		static void releaseObject( object obj )
		{
			Marshal.ReleaseComObject( obj );
		}

		static readonly HashSet<string> hsSheets = new HashSet<string>( StringComparer.OrdinalIgnoreCase )
		{
			"Sandy Bridge",
			"Ivy Bridge",
			"Haswell",
			"Broadwell",
			"Skylake",
			"Knights Landing",
			"Jaguar",
			"Ryzen",
		};

		readonly CategoryBuilder categories = new CategoryBuilder();
		readonly List<InstructionsData.Sheet> sheets = new List<InstructionsData.Sheet>();

		InstructionsData result()
		{
			InstructionsData r = new InstructionsData();
			r.categories = categories.categories;
			r.sheets = sheets.ToArray();
			return r;
		}

		TablesParser( Excel.Workbook workbook )
		{
			foreach( Excel.Worksheet s in workbook.Sheets )
			{
				if( !hsSheets.Contains( s.Name ) )
					continue;
				// Console.WriteLine( s.Name );
				var sheet = new InstructionsData.Sheet();
				sheet.name = s.Name;
				sheet.data = parseSheet( s ).ToArray();
				sheets.Add( sheet );
			}
		}

		static bool isTableHeader( bool instructionColumnTitlePresent, string[] cells )
		{
			if( instructionColumnTitlePresent )
			{
				if( null == cells[ 0 ] || null == cells[ 1 ] )
					return false;
				return cells[ 0 ].ToLowerInvariant() == "instruction" && cells[ 1 ].ToLowerInvariant() == "operands";
			}
			if( null == cells[ 1 ] )
				return false;
			return cells[ 1 ].ToLowerInvariant() == "operands";
		}
		static bool isEmpty( string[] cells )
		{
			return cells.All( String.IsNullOrWhiteSpace );
		}

		static string titleOrNull( string[] cells )
		{
			if( String.IsNullOrWhiteSpace( cells[ 0 ] ) )
				return null;
			if( cells.Skip( 1 ).Any( c => !String.IsNullOrWhiteSpace( c ) ) )
				return null;
			return cells[ 0 ];
		}

		static InstructionsData.Instruction inst( int cat, string[] fields )
		{
			InstructionsData.Instruction res = new InstructionsData.Instruction();
			res.cat = cat;
			res.i = fields[ 0 ];
			res.op = fields[ 1 ];
			res.uops = fields[ 2 ];
			res.latency = fields[ 3 ];
			res.throughput = fields[ 4 ];
			return res;
		}

		IEnumerable<InstructionsData.Instruction> parseSheet( Excel.Worksheet sheet )
		{
			string sheetName = sheet.Name;
			bool instructionColumnTitlePresent = sheetName != "Knights Landing";

			int totalRows = sheet.UsedRange.Rows.Count;
			int r;
			string category = null, group = null;
			for( r = 1; r < totalRows; r++ )
			{
				string txt = sheet.cellText( r );
				if( txt == "Integer instructions" )
				{
					group = txt;
					r++;
					break;
				}
			}
			if( r >= totalRows )
				yield break;

			for( ; r < totalRows; r++ )
			{
				string[] f2 = sheet.cells( r, 1, 2 );
				if( isTableHeader( instructionColumnTitlePresent, f2 ) )
					break;
			}
			if( r >= totalRows )
				yield break;

			// Find the data columns. The first 2 ones are always instruction and operands
			int uo=0, lat=0, rtp=0;
			for( int c = 3; c < 15 && ( 0 == uo || 0 == lat || 0 == rtp ); c++ )
			{
				string txt = sheet.cellText( r, c );
				if( null == txt )
					continue;
				txt = txt.ToLowerInvariant();
				if( txt.Contains( "ops" ) && 0 == uo )
				{
					uo = c;
					continue;
				}
				if( txt.Contains( "latency" ) )
				{
					lat = c;
					continue;
				}
				if( txt.Contains( "through" ) )
				{
					rtp = c;
					continue;
				}
			}

			if( 0 == uo || 0 == lat || 0 == rtp )
			{
				Console.WriteLine( "{0}: unable to find the columns", sheetName );
				yield break;
			}
			Console.WriteLine( "{0}: detected the columns", sheetName );

			bool newHeader = true;
			int? idCat = null;
			int nAdded = 0;
			for( r++; r < totalRows; r++ )
			{
				string[] fields = sheet.cells( r, 1, 2, uo, lat, rtp );
				if( isEmpty( fields ) )
					continue;
				string t = titleOrNull( fields );
				if( null != t )
				{
					idCat = null;
					if( newHeader )
					{
						category = group;
						newHeader = false;
					}
					group = t;
					continue;
				}
				if( isTableHeader( instructionColumnTitlePresent, fields ) )
				{
					newHeader = true;
					continue;
				}
				if( !idCat.HasValue )
					idCat = categories.id( category, group );
				yield return inst( idCat.Value, fields );
				nAdded++;
			}

			Console.WriteLine( "{0}: parsed {1} instructions", sheetName, nAdded );
		}
	}
}