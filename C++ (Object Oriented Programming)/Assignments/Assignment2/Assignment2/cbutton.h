// Jorge E. Valbuena S.
// OOP344A - Assignment #2
#pragma once
#ifndef __cbutton_H__
#define __cbutton_H__

#include "cfg.h"
#include "cfield.h"
#include "cframe.h"
#include "console.h"
#include "consoleplus.h"
#include "keys.h"

namespace cio { // continuation of namespace cio

	class CField;
	class CButton : public CField {
		int b_frame;
		void allocateAndCopy(const char* data);
	public:
		CButton(const char* Str, int Row, int Col, bool Bordered = true, const char* Border = C_BORDER_CHARS);
		virtual ~CButton();
		void draw(int fn = C_NO_FRAME);
		int edit();
		bool editable()const;
		void set(const void* str);
	};

} // end of namespace cio
#endif