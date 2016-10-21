using System;
using System.Collections.Generic;
using System.Linq;

namespace IntrinsicsDocs
{
	public class Group
	{
		public readonly string title;
		readonly string prefix;

		public List<string> sectionNames { get; private set; }
		public List<List<Intrinsic>> sections { get; private set; }
		public IEnumerable<Intrinsic> items { get { return sections.SelectMany( ll => ll ); } }

		static string sectionName( int commonPrefixLength, Intrinsic i, string none )
		{
			string key = i.sortKey;
			if( key.Length <= commonPrefixLength )
				return none;
			return key.Substring( commonPrefixLength, 1 ).ToUpperInvariant();
		}

		Group( IEnumerable<Intrinsic> g, string title, string prefix = "misc" )
		{
			this.prefix = prefix;
			this.title = title;

			List<Intrinsic> items = g.OrderBy( p => p.sortKey ).ToList();

			int commonPrefixLength = items.Select( i => i.sortKey ).longestCommonPrefix();

			var groups = items.GroupBy( ii => sectionName( commonPrefixLength, ii, "" ) )
				.OrderBy( gg => gg.Key)
				.ToList();

			sectionNames = groups
				.Select( gg => sectionName( commonPrefixLength, gg.First(), "None" ) )
				.ToList();
			sections = groups
				.Select( gg => gg.OrderBy( ii => ii.sortKey ).ToList() )
				.ToList();
		}

		Group( IGrouping<string, Intrinsic> g, string prefix ) : this( g, g.Key, prefix )
		{ }

		public static List<Group> group( IEnumerable<Intrinsic> i, string prefix, Func<Intrinsic, string> key )
		{
			return i.GroupBy( key )
				.Where( g => g.Key.notEmpty() )
				.Select( g => new Group( g, prefix ) )
				.OrderBy( g => g.title )
				.ToList();
		}

		public static Group all( IEnumerable<Intrinsic> i )
		{
			return new Group( i, "All" );
		}

		public string htmlFile()
		{
			return prefix + "_" + Utils.htmlFile( title );
		}
	}
}