using System.Xml.Serialization;

namespace IntrinsicsDocs
{
	[XmlRoot( "intrinsics_list" )]
	public class DataSet
	{
		[XmlAttribute]
		public string version;

		[XmlAttribute]
		public string date;

		[XmlElement( "intrinsic" )]
		public Intrinsic[] intrinsic;

		public void fixAfterLoading()
		{
			foreach( var i in intrinsic )
				i.fixAfterLoading();
		}
	}
}