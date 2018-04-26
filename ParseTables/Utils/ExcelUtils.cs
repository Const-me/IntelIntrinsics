using Excel = Microsoft.Office.Interop.Excel;

namespace ParseTables
{
	static class ExcelUtils
	{
		public static string cellText( this Excel.Worksheet sheet, int r, int c = 1 )
		{
			object obj = ( sheet.Cells[ r, c ] as Excel.Range ).Value;
			if( null == obj )
				return null;
			string s = obj as string;
			if( null != s ) return s;
			return obj.ToString();
		}

		public static string[] cells( this Excel.Worksheet sheet, int r, params int[] columns )
		{
			string[] res = new string[ columns.Length ];
			for( int i = 0; i < columns.Length; i++ )
				res[ i ] = sheet.cellText( r, columns[ i ] );
			return res;
		}
	}
}