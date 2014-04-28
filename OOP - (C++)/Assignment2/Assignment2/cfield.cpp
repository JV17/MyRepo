// Jorge E. Valbuena S.
// OOP344A - Assignment #2

#include "cfield.h"
//#include "consoleplus.h"

namespace cio{ // continuation of namespace cio

	// The CField constructor receives seven values in its parameters and passes all values except 
	// the data address to its base class constructor (defaults in parentheses):
	//	int - the field's top-most row position relative to the parent frame, if any (0)
	//	int - the field's left-most column position relative to the parent frame, if any (0)
	//	int - the field's width (0)
	//	int - the field's height (0)
	//	void* -the address of the data that associated with the frame(NULL)
	//	bool - the visibility of the field's border (false)
	//	const char* -a C - style null - terminated string describing the field's border (C_BORDER_CHARS)
	CField::CField(int row, int col, int width, int height, void* data,
		bool visible, const char* border) : CFrame(row, col, width, height, visible, border) {
		_data = data;
	}

	// The CField destructor is empty.
	CField::~CField() {}

	// returns the address of the pointer to field's data
	void* CField::data() const{
		return _data;
	}

	// sets the address of the field's data
	void CField::data(void* tmp) {
		_data = tmp;
	}
	
} // end of namespace cio