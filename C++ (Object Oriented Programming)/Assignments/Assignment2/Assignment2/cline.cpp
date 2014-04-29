// Jorge E. Valbuena S.
// OOP344A - Assignment #2

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstring>
#include "cline.h"
#include "consoleplus.h"

namespace cio{ // continuation of namespace cio

	// The first CLine constructor receives eight values in its parameters (defaults in parentheses):
	// const char* -the address of a C - style null - terminated string that contains the line field's data
	//	int - the row position relative to the parent frame, if any
	//	int - the left - most column position relative to the parent frame, if any
	//	int - the length of the line field
	//	int - the maximum number of characters in the line field
	//	bool - the insert mode for the line field
	//	bool - the visibility of the line field's border (false)
	//	const char* -a C - style null - terminated string describing the field's border (C_BORDER_CHARS)
	CLine::CLine(const char* Str, int Row, int Col, int Width,
		int Maxdatalen, bool* Insertmode,
		bool Bordered,
		const char* Border) : CField(Row, Col, Width, Bordered ? 3 : 1, (void*)Str, Bordered, Border) {
		alloc = false;
		cursor = 0;
		offset = 0;
		_maxDatalen = Maxdatalen;
		_insertMode = Insertmode;
		allocateAndCopy(Str);
		//set(Str);
	}

	// The second CLine constructor receives seven values in its parameters:
	//  int - the row position relative to the parent frame, if any
	//	int - the left - most column position relative to the parent frame, if any
	//	int - the length of the line field
	//	int - the maximum number of characters in the line field
	//	bool - the insert mode for the line field
	//	bool - the visibility of the line field's border (false)
	//	const char* -a C - style null - terminated string describing the line field's border (C_BORDER_CHARS)
	CLine::CLine(int Row, int Col, int Width,
		int Maxdatalen, bool* Insertmode,
		bool Bordered,
		const char* Border) : CField(Row, Col, Width, Bordered ? 3 : 1, NULL, Bordered, Border) {
		cursor = 0;
		offset = 0;
		_maxDatalen = Maxdatalen;
		//_insertMode = Insertmode;
		allocateAndCopy("");
	}

	// The CLine destructor deallocates the dynamic memory allocated for the data string.  
	// If the current object was constructed using the first constructor and not reset for a new 
	// string, the memory allocated for the string remained outside the current object, and the 
	// destructor does not deallocate that memory.
	CLine::~CLine(){
		if (alloc)
			delete[] (char*)data();
	}

	// allocates dynamic memory for the C-style null-terminated string at the received address and 
	// copies that data into the newly allocated memory
	void CLine::allocateAndCopy(const char* Str){
		alloc = true;
		void* tmp = new char[_maxDatalen + 1];
		data(tmp);
		std::strcpy((char*)data(), Str);
		((char*)data())[_maxDatalen] = '\0';
	}

	// draws the frame for the line field according to the specified value (C_NO_FRAME) and 
	// displays the data in that field starting at the current offset
	void CLine::draw(int Refresh){
		CFrame::draw(Refresh);
		CFrame::bordered() ? cio::display((char*)data() + offset, absRow() +1, absCol() +1, width() -2) : cio::display((char*)data() + offset, absRow() -1, absCol()-1, width()+2);
		/*
		if (CFrame::bordered())
			cio::display((char*)data() + offset, absRow() + 1, absCol() + 1, width() - 2);
		else
			cio::display((char*)data() + offset, absRow(), absCol(), width());
		*/
	}

	// edits the line field according to the editing state and returns the key that causes the 
	// editing to finish
	int CLine::edit(){
		return CFrame::bordered() ? cio::edit((char*)data() + offset, absRow()+1, absCol()+1 , width()-2, _maxDatalen, &_insMode, &offset, &cursor, 0, 0) : cio::edit((char*)data() + offset, absRow()+1, absCol()+1, width()-2, _maxDatalen, &_insMode, &offset, &cursor, 0, 0);
		/*
		if (CFrame::bordered())
			return cio::edit((char*)_data + offset, absRow() + 1, absCol() + 1, width() - 2, _maxDatalen, &_insMode, &offset, &cursor, 0, 0);
		else
			return cio::edit((char*)data() + offset, absRow(), absCol(), width(), _maxDatalen, &_insMode, &offset, &cursor, 0, 0);
		*/
	}

	// returns true
	bool CLine::editable()const{
		return true;
	}

	// associates a new C-style null-terminated string with the line field.  If the current object 
	// allocated memory for the string currently associated with the field, this method deallocates 
	// that memory.  The method allocates new dynamic memory for the new string and copies it into 
	// the newly allocated memory. 
	void CLine::set(const void* Str){
		if (alloc)
			delete[] (char*)data();
		allocateAndCopy((const char*)Str);
	}

} // end of namespace cio