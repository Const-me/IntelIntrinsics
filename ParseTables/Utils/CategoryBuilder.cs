using System;
using System.Collections.Generic;

namespace ParseTables
{
	class CategoryBuilder
	{
		readonly List<InstructionsData.Category> m_categories = new List<InstructionsData.Category>();

		readonly Dictionary<string, int> m_dict = new Dictionary<string, int>( StringComparer.OrdinalIgnoreCase );

		public InstructionsData.Category[] categories => m_categories.ToArray();

		public int id( string cat, string group )
		{
			string key = $"{cat}/{group}";
			int res;
			if( m_dict.TryGetValue( key, out res ) )
				return res;
			res = m_categories.Count + 1;
			m_categories.Add( new InstructionsData.Category( res, cat, group ) );
			m_dict[ key ] = res;
			return res;
		}
	}
}