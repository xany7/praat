/* Matrix_def.h
 *
 * Copyright (C) 1992-2011,2013,2015 Paul Boersma
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */


#define ooSTRUCT Matrix
oo_DEFINE_CLASS (Matrix, SampledXY)

	#if oo_READING
		if (Melder_debug == 45)
			Melder_casual ("structMatrix :: read: Going to read %ld rows of %ld columns.", ny, nx);
		if (localVersion >= 2) {
			oo_DOUBLE_MATRIX (z, ny, nx)
		} else {
			oo_FLOAT_MATRIX (z, ny, nx)
		}
	#else
		oo_DOUBLE_MATRIX (z, ny, nx)
	#endif

	#if oo_DECLARING
		void v_info ()
			override;
		bool v_hasGetNrow ()
			override { return true; }
		double v_getNrow ()
			override { return ny; }
		bool v_hasGetNcol ()
			override { return true; }
		double v_getNcol ()
			override { return nx; }
		bool v_hasGetMatrix ()
			override { return true; }
		double v_getMatrix (long irow, long icol)
			override;
		bool v_hasGetFunction2 ()
			override { return true; }
		double v_getFunction2 (double x, double y)
			override;
		double v_getValueAtSample (long isamp, long ilevel, int unit)
			override;
	#endif

oo_END_CLASS (Matrix)
#undef ooSTRUCT


/* End of file Matrix_def.h */
