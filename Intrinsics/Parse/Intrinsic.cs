using System;
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

			// For names ending with a number, zero-extend that number into 3 digits. This improves their sorting order.
			int trailingDigits = 0;
			for( ; char.IsDigit( sortKey[ sortKey.Length - trailingDigits - 1 ] ); trailingDigits++ ) ;
			if( trailingDigits > 0 && trailingDigits < 3 )
				sortKey = sortKey.Substring( 0, sortKey.Length - trailingDigits ) + new string( '0', 3 - trailingDigits ) + sortKey.Substring( sortKey.Length - trailingDigits );

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
		public bool flipArgumentsOrder = false;

		[XmlIgnore]
		public bool castArgumentsUnsigned = false;

		public override string ToString()
		{
			return name;
		}
	}
}