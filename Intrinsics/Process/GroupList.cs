using System;
using System.Collections.Generic;
using System.Linq;

namespace IntrinsicsDocs
{
	public class GroupList
	{
		public readonly string title;
		public readonly List<Group> groups;

		public GroupList( List<Group> groups, string title )
		{
			this.title = title;
			this.groups = groups;
		}

		public string htmlFile()
		{
			return "misc_" + title + ".html";
		}
	}
}