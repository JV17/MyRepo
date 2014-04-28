// Jorge E. Valbuena S.
// OOP344A - Assignment #2
#pragma once
#ifndef _CLINE_H_
#define _CLINE_H_

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "cfield.h"

namespace cio{ // continuation of namespace cio

	class CLine : public CField{
		bool alloc;
		bool _bordered;
		int _maxDatalen;
		bool _insMode;
		int refreshed;
		int cursor;
		int offset;
		void allocateAndCopy(const char*);
	public:
		CLine(const char* Str, int Row, int Col, int Width,
			int Maxdatalen, bool* Insertmode,
			bool Bordered = false,
			const char* Border = C_BORDER_CHARS);
		CLine(int Row, int Col, int Width,
			int Maxdatalen, bool* Insertmode,
			bool Bordered = false,
			const char* Border = C_BORDER_CHARS);
		~CLine();
		void draw(int Refresh = C_NO_FRAME);
		int edit();
		bool editable()const;
		void set(const void* Str);
	};

} // end of namespace cio
#endif