using System.Xml.Serialization;

namespace ParseTables
{
	[XmlRoot]
	public class InstructionsData
	{
		public class Category
		{
			[XmlAttribute]
			public int id;
			[XmlAttribute]
			public string cat;
			[XmlAttribute]
			public string group;

			public Category() { }
			public Category( int id, string cat, string group )
			{
				this.id = id;
				this.cat = cat;
				this.group = group;
			}
		}

		[XmlArray, XmlArrayItem( "c" )]
		public Category[] categories;

		public class Instruction
		{
			[XmlAttribute]
			public int cat;

			[XmlAttribute]
			public string i, op;

			[XmlAttribute( "uo" )]
			public string uops;
			[XmlAttribute( "lat" )]
			public string latency;
			[XmlAttribute( "rtp" )]
			public string throughput;
		}

		public class Sheet
		{
			[XmlAttribute]
			public string name;

			[XmlElement( "i" )]
			public Instruction[] data;
		}

		[XmlElement("sheet")]
		public Sheet[] sheets;
	}
}