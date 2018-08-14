/* VEC.cpp
 *
 * Copyright (C) 2017,2018 Paul Boersma
 *
 * This code is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This code is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this work. If not, see <http://www.gnu.org/licenses/>.
 */

#include "melder.h"
#include "../dwsys/NUM2.h"   /* for NUMsort2 */

autoVEC VECcopy (VEC x) {
	autoVEC result (x.size, kTensorInitializationType::RAW);
	for (integer i = 1; i <= x.size; i ++)
		result [i] = x [i];
	return result;
}

inline static double inner_stride_ (VEC x, VEC y, integer stride) {
	if (x.size != y.size)
		return undefined;
	PAIRWISE_SUM (longdouble, sum, integer, x.size,
		double *xx = & x [0];
		double *yy = & y [1 - stride],
		(++ xx, yy += stride),   // this goes way beyond the confines of y
		(longdouble) *xx * (longdouble) *yy)
	return (double) sum;
}

autoVEC VECmul (VEC vec, MAT mat) {
	if (mat.nrow != vec.size)
		return autoVEC();
	autoVEC result (mat.ncol, kTensorInitializationType::RAW);
	VECmul_inplace (result.get(), vec, mat);
	return result;
}

void VECmul_inplace (VEC target, VEC vec, MAT mat) {
	for (integer j = 1; j <= mat.ncol; j ++) {
		if ((false)) {
			target [j] = 0.0;
			for (integer i = 1; i <= mat.nrow; i ++)
				target [j] += vec [i] * mat [i] [j];
		} else {
			target [j] = inner_stride_ (vec, VEC (& mat [1] [j] - 1, mat.nrow), mat.ncol);
		}
	}
}

autoVEC VECmul (MAT mat, VEC vec) {
	if (vec.size != mat.ncol)
		return autoVEC();
	autoVEC result (mat.nrow, kTensorInitializationType::RAW);
	VECmul_inplace (result.get(), mat, vec);
	return result;
}

void VECmul_inplace (VEC target, MAT mat, VEC vec) {
	for (integer i = 1; i <= mat.nrow; i ++) {
		if ((false)) {
			target [i] = 0.0;
			for (integer j = 1; j <= vec.size; j ++)
				target [i] += mat [i] [j] * vec [j];
		} else {
			target [i] = NUMinner (VEC (& mat [i] [1] - 1, mat.ncol), vec);
		}
	}
}

void VECsort_inplace (VEC x) {
	NUMsort_d (x.size, x.at);
}

/* End of file VEC.cpp */
