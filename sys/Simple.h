#ifndef _Simple_h_
#define _Simple_h_
/* Simple.h
 *
 * Copyright (C) 1992-2012,2015 Paul Boersma
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
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Data.h"

#include "Simple_def.h"

autoSimpleInt SimpleInt_create (int number);
autoSimpleLong SimpleLong_create (long number);
autoSimpleDouble SimpleDouble_create (double number);
autoSimpleString SimpleString_create (const char32 *string);

int SimpleString_compare (SimpleString me, SimpleString thee) noexcept;

/* End of file Simple.h */
#endif
