using System;
using System.Xml.Serialization;

namespace IntrinsicsDocs
{
	public class Intrinsic
	{
		[XmlAttribute]
		public string tech, rettype, name;

		[XmlElement]
		public string type;

		[XmlElement]
		public string[] CPUID;

		[XmlElement]
		public string category;

		public class Param
		{
			[XmlAttribute]
			public string varname, type;
		}

		[XmlElement]
		public Param[] parameter;

		[XmlElement]
		public string description, operation;

		public class Instr
		{
			[XmlAttribute]
			public string name, form;
		}

		[XmlElement]
		public Instr instruction;

		public class Perf
		{
			[XmlAttribute]
			public string arch;
			[XmlAttribute]
			public string lat;
			[XmlAttribute]
			public string tpt;  // Sometimes empty
		}

		[XmlElement]
		public Perf[] perfdata;

		[XmlElement]
		public string header;

		public void fixAfterLoading()
		{
			Utils.trim( ref description );
			Utils.trim( ref operation );
			sortKey = name.TrimStart( '_' )
				.ToLowerInvariant()
				.stripPrefix( "mm_", "mm256_", "mm512_", "m_" );
		}

		[XmlIgnore]
		public string id { get; private set; }

		[XmlIgnore]
		public string sortKey { get; private set; }

		internal string setId( bool addTech )
		{
			if( addTech )
				id = String.Format( "{0} {1}", name, tech );
			else
				id = name;
			return id;
		}

		public string htmlFile()
		{
			return Utils.htmlFile( id );
		}
	}
}