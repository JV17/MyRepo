// Jorge E. Valbuena S.
// OOP344A - Assignment #2
#pragma once
#ifndef __CLABEL_H__
#define __CLABEL_H__

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "console.h"
#include "consoleplus.h"
#include "cfield.h"


namespace cio { // continuation of namespace cio

	class CLabel : public CField{
		void allocateAndCopy(const char* Str);
		int offset;
	public:
		CLabel(const char *Str, int Row, int Col, int Len = -1);
		CLabel(int Row, int Col, int Len);
		void draw(int fn = C_NO_FRAME);
		void set(const void* Str);
		CLabel(const CLabel& L);
		bool editable() const;
		int edit();
		~CLabel();
	};

}//end of namespace cio
#endif