﻿using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;

namespace IntrinsicsDocs.Performance
{
	static class TableBuilder
	{
		static bool match( this PerfData.Instruction ii, eRegSize rs )
		{
			return ii.args.Any( aa => aa.match( rs ) );
		}
		static bool regsOnly( this PerfData.Instruction ii )
		{
			return ii.args.Any( aa => aa.regsOnly() );
		}

		public static bool hasPerformanceData( this PerfData pd, Intrinsic i )
		{
			if( null == i.instruction )
				return false;
			var data = pd.lookup( i.instruction.name );
			if( null == data )
				return false;
			eRegSize regSize = i.regSize();
			if( regSize == eRegSize.None )
				return false;
			return data.Any( ii => ii.match( regSize ) );
		}

		public static List<PerfData.Instruction> table( this PerfData pd, Intrinsic intr )
		{
			// if( intr.name == "_mm256_sad_epu8" && Debugger.IsAttached ) Debugger.Break();	// Break on building the perf.table for "_mm256_sad_epu8" intrinsic

			if( null == intr.instruction )
				return null;
			IEnumerable<PerfData.Instruction> data = pd.lookup( intr.instruction.name );
			if( null == data )
				return null;

			eRegSize regSize = intr.regSize();
			var grouped = data.GroupBy( i => i.cpu );
			List<PerfData.Instruction> res = new List<PerfData.Instruction>( grouped.Count() );

			foreach( var g in grouped )
			{
				if( 1 == g.Count() )
				{
					// This CPU only has a single version of that instruction
					res.Add( g.First() );
					continue;
				}

				var matched = g.FirstOrDefault( ii => ii.match( regSize ) );
				if( null != matched )
				{
					res.Add( matched );
					continue;
				}
				matched = g.FirstOrDefault( ii => ii.regsOnly() );
				if( null != matched )
				{
					res.Add( matched );
					continue;
				}
				// throw new NotSupportedException();
			}
			return res;
		}
	}
}