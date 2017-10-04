using System.Collections.Generic;

namespace IntrinsicsDocs
{
	static class UniqueID
	{
		static bool sameTech( this IEnumerable<Intrinsic> e )
		{
			string tt = null;
			foreach( var i in e )
			{
				string thisTech = i.tech.ToLowerInvariant().Trim();
				if( null == tt )
				{
					tt = thisTech;
					continue;
				}
				if( tt != thisTech )
					return false;
			}
			return true;
		}

		static void mergeTo( Intrinsic from, Intrinsic to )
		{
			if( to.CPUID.isEmpty() )
				to.CPUID = from.CPUID;
			if( to.category.isEmpty() )
				to.category = from.category;
		}

		public static Intrinsic[] make( Intrinsic[] arr )
		{
			List<Intrinsic> res = new List<Intrinsic>( arr.Length );
			var dictAll = Utils.dictionary<Intrinsic>();
			var dictDupes = Utils.dictionary<List<Intrinsic>>();

			foreach( var i in arr )
			{
				i.setId( false );
				res.Add( i );
				Intrinsic prev = dictAll.lookup( i.name );
				if( null == prev )
				{
					dictAll.Add( i.name, i );
					continue;
				}
				// Found a dupe
				var list = dictDupes.lookup( i.name );
				if( null == list )
				{
					list = new List<Intrinsic>( 2 );
					dictDupes.Add( i.name, list );
					list.Add( prev );
				}
				list.Add( i );
			}

			foreach( var kvp in dictDupes )
			{
				if( kvp.Value.sameTech() )
				{
					Intrinsic leave = kvp.Value[ 0 ];
					for( int i = 1; i < kvp.Value.Count; i++ )
					{
						Intrinsic skip = kvp.Value[ i ];
						mergeTo( skip, leave );
						res.Remove( skip );
					}
					continue;
				}
				foreach (var i in kvp.Value)
					i.setId( true );
			}
			return res.ToArray();
		}
	}
}