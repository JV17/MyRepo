// Jorge E. Valbuena S.
// OOP344A - Assignment #2

#include "cbutton.h"
#include <cstring>

using namespace std;

namespace cio{

	// The CButton constructor receives five values in its parameters (defaults in parentheses):
	//	const char* -the address of a C - style null - terminated string that contains the button's label
	//	int - the row position relative to the parent frame, if any
	//	int - the left - most column position relative to the parent frame, if any
	//	bool - the visibility of the button's border (true)
	//	const char* -a C - style null - terminated string describing the button's border (C_BORDER_CHARS)
	CButton::CButton(const char *Str, int Row, int Col, bool Bordered, const char* Border)
		: CField(Row, Col, (Bordered) ? (strlen(Str) + 4) : (strlen(Str) + 2), (Bordered) ? (3) : (1), NULL, Bordered, Border) {
		allocateAndCopy(Str);
	}

	// allocates dynamic memory for the data at the received address and copies that data into the 
	// new memory.  This method reserves an empty space as a prefix to the string and an empty 
	// space as a suffix to the string and stores the prefixed-suffixed string.
	void CButton::allocateAndCopy(const char* data) {
		unsigned int i;

		char* str = new char[strlen(data) + 3];
		str[0] = ' ';

		for (i = 1; i < strlen(data) + 1; i++) {
			str[i] = data[i - 1];
		}

		str[i] = ' ';
		str[i + 1] = '\0';

		CField::data(str);
	}

	// The CButton destructor deallocates the dynamic memory that stored in data.
	CButton::~CButton(){
		delete[] (char*)data();
	}

	// draws the button's frame according to the specified value (C_NO_FRAME) and displays its data
	// without offset
	void CButton::draw(int fn){
		CFrame::draw(fn);
		cio::display((const char*)data(), absRow() + 1, absCol() + 1);
	}

	// captures the press of the button
	//	draws the button's frame
	//	changes the prefix and suffix on the label's string to [ and ] resepctively
	//	displays the label
	//	places the cursor in the middle of the label
	//	retrieves a key from the user
	//	changes the key code to C_BUTTON_HIT if the user has pressed the ENTER or SPACE key
	//	reverts to the empty space prefix and suffix notation on the label
	//	places the cursor in the middle of the label
	//	returns the key code
	int CButton::edit() {
		int key;

		CFrame::draw();

		char* str = new char[strlen((char*)CField::data()) + 1];
		strcpy(str, (char*)CField::data());

		str[0] = '[';
		str[strlen(str) - 1] = ']';
		CField::data(str); 

		cio::display((char*)data(), absRow() + 1, absCol() + 1, width() - 2);
		CFrame::goMiddle();

		console >> key;

		if (key == ENTER || key == SPACE) {
			key = C_BUTTON_HIT;
		}

		str[0] = ' ';
		str[strlen(str) - 1] = ' ';
		CField::data(str);  

		cio::display((char*)data(), absRow() + 1, absCol() + 1, width() - 2);
		CFrame::goMiddle();

		return key;
	}

	// returns true
	bool CButton::editable()const {
		return true;
	}

	// deallocates the dynamic memory allocated for the button's label, allocates dynamic memory 
	// for the C-style null-terminated string at the address received, copies the string into the 
	// newly allocated memory, and resets the width and the height of the button
	void CButton::set(const void* str) {
		delete[] (char*)data();
		allocateAndCopy((char*)str);
		CFrame::height((CFrame::bordered()) ? (3) : (1));
		CFrame::width((CFrame::bordered()) ? (strlen((char*)str) + 4) : (strlen((char*)str) + 2));
	}
}