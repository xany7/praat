#ifndef _TextEditor_h_
#define _TextEditor_h_
/* TextEditor.h
 *
 * Copyright (C) 1997-2011,2012,2013,2015 Paul Boersma
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

#include "Editor.h"

Thing_define (TextEditor, Editor) {
	structMelderFile file;
	GuiText textWidget;
	UiForm openDialog, saveDialog, printDialog, findDialog;
	int dirty;
	GuiDialog dirtyNewDialog, dirtyOpenDialog, dirtyCloseDialog;
	GuiMenuItem fontSizeButton_10, fontSizeButton_12, fontSizeButton_14, fontSizeButton_18, fontSizeButton_24;

	void v_destroy ()
		override;
	void v_nameChanged ()
		override;
	void v_goAway ()
		override;
	void v_createChildren ()
		override;
	void v_createMenus ()
		override;
	bool v_hasQueryMenu ()
		override { return false; }

	virtual bool v_fileBased () { return true; };   // if true, have New, Open..., Save; if false, have Clear
	virtual void v_clear () { }

	#include "TextEditor_prefs.h"
};

void TextEditor_init (TextEditor me,
	const wchar_t *initialText
);
TextEditor TextEditor_create (
	const wchar_t *initialText   // may be NULL
);

void TextEditor_showOpen (TextEditor me);

/* End of file TextEditor.h */
#endif
