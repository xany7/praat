#ifndef _ManPage_h_
#define _ManPage_h_
/* ManPage.h
 *
 * Copyright (C) 1996-2011,2015 Paul Boersma
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

#include "Graphics.h"

#include "ManPage_enums.h"

typedef struct structManPage_Paragraph {
	short type;
	const char32 *text;
	double width, height;
	void (*draw) (Graphics g);
} *ManPage_Paragraph;

Thing_define (ManPage, Thing) {
	const char32 *title, *author;
	long date;
	struct structManPage_Paragraph *paragraphs;
	long nlinksHither, nlinksThither;
	long *linksHither, *linksThither;
	double recordingTime;
};

/* End of file ManPage.h */
#endif
