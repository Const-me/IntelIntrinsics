﻿using System;
using System.Xml.Serialization;

namespace IntrinsicsDocs
{
	/// <summary>A model class for a single intrinsic. XmlSerializer reads them from the XML data, RazorEngine writes them into HTML articles.</summary>
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

		[XmlElement]
		public string header;

		static readonly Param[] s_emptyParams = new Param[ 0 ];

		public void fixAfterLoading()
		{
			Utils.trim( ref description );
			Utils.trim( ref operation );
			sortKey = name.TrimStart( '_' )
				.ToLowerInvariant()
				.stripPrefix( "mm_", "mm256_", "mm512_", "m_" );
			if( null == parameter ) parameter = s_emptyParams;
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

		[XmlIgnore]
		public bool is64bitOnly = false;

		[XmlIgnore]
		public bool fixedSetOrder = false;
	}
}