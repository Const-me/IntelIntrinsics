using System.Reflection;
using System.Linq;
using System.IO;

namespace IntrinsicsDocs.Cpp
{
	class ExtraCode
	{
		public static string extra( string f )
		{
			string find = f.ToLowerInvariant() + ".extra.hpp";
			var ass = Assembly.GetExecutingAssembly();
			string found = ass.GetManifestResourceNames().FirstOrDefault( s => s.ToLowerInvariant().EndsWith( find ) );
			if( null == found )
				return null;
			var stm = ass.GetManifestResourceStream( found );
			StreamReader sr = new StreamReader( stm );
			return sr.ReadToEnd();
		}

		const string prefix = "IntrinsicsDocs.Cpp.";

		public static void copyExtraFiles( string dest )
		{
			// "*.extra.hpp"
			var ass = Assembly.GetExecutingAssembly();
			foreach( string name in ass.GetManifestResourceNames() )
			{
				if( !name.StartsWith( prefix ) )
					continue;
				if( name.ToLowerInvariant().EndsWith( ".extra.hpp" ) )
					continue;

				string destFolder = dest;

				string nameRel = name.stripPrefix( prefix );
				if( nameRel.StartsWith( "Implementation." ) )
				{
					destFolder = Path.Combine( dest, "Implementation" );
					if( !Directory.Exists( destFolder ) )
						Directory.CreateDirectory( destFolder );
					nameRel = nameRel.stripPrefix( "Implementation." );
				}

				var stm = ass.GetManifestResourceStream( name );
				string pathDest = Path.Combine( destFolder, nameRel );
				using( var fs = File.Create( pathDest ) )
				{
					stm.Seek( 0, SeekOrigin.Begin );
					stm.CopyTo( fs );
				}
			}
		}
	}
}