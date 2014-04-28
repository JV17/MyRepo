// Jorge E. Valbuena S.
// OOP344A - Assignment #2

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "console.h"
#include <cstring>
#include "clabel.h"

using namespace std;

namespace cio { // continuation of namespace cio

	// The CLabel copy constructor copies the source object's data into the dynamic memory that 
	// stores the label's data.
	CLabel::CLabel(const CLabel& L) :CField(L){
		allocateAndCopy((char*)L.data()); 
	}

	// allocates dynamic memory for the C-style null-terminated string at the received address and 
	// copies that data into the newly allocated memory.  The maximum memory needed here is the 
	// width of the field plus 1 for the null byte.
	void CLabel::allocateAndCopy(const char *Str){
		void* tmp = new char[width() + 1];
		data(tmp);
		strncpy((char*)data(), Str, width());
		((char*)data())[width()] = '\0';
		
	}

	// The first CLabel constructor receives four values in its parameters (default in parentheses):
	//  const char* -the address of a C - style null - terminated string that contains the label's data
	//	int - the row position relative to the parent frame, if any
	//	int - the left - most column position relative to the parent frame, if any
	//	int - the length of the label field(-1)
	CLabel::CLabel(const char *Str, int Row, int Col, int Len) : CField(Row, Col, Len == -1 ? strlen(Str) : Len){
		allocateAndCopy(Str);
	}

	// The second constructor receives three values in its parameters and stores an empty string as 
	// the label's data:
	//  int - the row position relative to the parent frame, if any
	//	int - the left - most column position relative to the parent frame, if any
	//	int - the length of the label field
	CLabel::CLabel(int Row, int Col, int Len) : CField(Row, Col, Len){
		allocateAndCopy("");
	}

	// The CLabel destructor deallocates the dynamic memory that stored the label's data.
	CLabel::~CLabel(){
		delete[] (char*)data(); 
	}

	// displays the label (C_NO_FRAME)
	void CLabel::draw(int fn){
		
		int tmp_width;
		int _addBor = 0, _addRow = 0;

		if (_visible){
			_addBor = 2;
			_addRow = 1;
		}

		tmp_width = _width - _addBor;

		if (_frame){
			if (_col + _width + _addBor >= _frame->width()){
				tmp_width = _frame->width() - _col - _addBor;
				if (_frame->bordered()){
					tmp_width--; tmp_width--;
				}
			}
		}
		cio::display((char*)data(), absRow() + _addRow + 1, absCol() + _addBor + 1, tmp_width);
		
	}

	// draws the label and returns the key code C_NOT_EDITABLE
	int CLabel::edit(){
		draw();
		return C_NOT_EDITABLE;
	}

	// returns false
	bool CLabel::editable()const{
		return false;
	}

	// deallocates the dynamic memory where the label's data has been stored, resets the width of 
	// the field to the length of the C-style null-terminated string at the received address, 
	// allocates dynamic memory for that data, and copies the data in the newly allocated memory
	void CLabel::set(const void* Str){
		/*
		// set new string, up to max length
		if (width() > 0) {
			unsigned i;
			unsigned len = strlen((const char*)Str);
			for (i = 0; i < width() && i < len; i++)
			{
				((char*)_data)[i] = ((char*)Str)[i];
			}
			((char*)_data)[i] = '\0';
		}
		// set new string, no max length
		else if (width() == 0) {
			if (_data)
				delete[](char*)_data;
			_data = new char[strlen((const char*)Str + 1)];
			allocateAndCopy((const char*)Str);
		}
		*/

		width((int)strlen((const char*)Str));
		delete[](char*)data();
		allocateAndCopy((const char*)Str);
	}

}//end of namespace cio