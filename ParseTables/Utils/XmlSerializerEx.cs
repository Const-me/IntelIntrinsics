using System;
using System.IO;
using System.Xml;
using System.Xml.Serialization;

namespace ParseTables
{
	/// <summary>An XmlSerializer that produces tabs instead of spaces.</summary>
	class XmlSerializerEx
	{
		readonly XmlSerializer serializer;

		public XmlSerializerEx( Type tp )
		{
			serializer = new XmlSerializer( tp );
		}

		public object Deserialize( Stream stm )
		{
			return serializer.Deserialize( stm );
		}

		public void Serialize( Stream stm, object obj )
		{
			// https://bytes.com/topic/c-sharp/answers/813598-xmlserializer-indent-tab-instead-spaces
			XmlWriterSettings settings = new XmlWriterSettings();
			settings.IndentChars = "\t";
			settings.Indent = true;
			using( XmlWriter xw = XmlWriter.Create( stm, settings ) )
			{
				serializer.Serialize( xw, obj );
				xw.Flush();
			}
			stm.Flush();
		}

		public object Deserialize( string path )
		{
			using( FileStream stm = new FileStream( path, FileMode.Open, FileAccess.Read ) )
				return serializer.Deserialize( stm );
		}
	}
}