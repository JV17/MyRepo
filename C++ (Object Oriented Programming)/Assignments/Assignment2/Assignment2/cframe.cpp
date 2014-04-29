// Jorge E. Valbuena S.
// OOP344A - Assignment #2

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstring>
#include "cframe.h"
#include "console.h"
#include "consoleplus.h"
#include "consolebackup.h"

using namespace std;

namespace cio { // continuation of namespace cio

	// The CFrame constructor receives seven values in its parameters (defaults in parentheses):
	//	int - the frame's top row position relative to its parent frame, if any (-1)
	//	int - the frame's left-most column position relative to its parent frame, if any (-1)
	//	int - the frame's width (-1)
	//	int - the frame's height (-1)
	//	bool - the frame's visibility (false)
	//	const char* -the C - style null - terminated string that describes the frame's border (C_BORDER_CHARS)
	//	CFrame* -the initial address of the parent frame, if any(NULL)

	//	If the constructor receives a negative height, the frame is fullscreen no matter what values 
	// of row, col, or width the caller specifies.If the frame is fullscreen, then its width and height 
	// are the number of rows and columns respectively that the console supports.A fullscreen frame has 
	// no border.On construction, the frame does not draw itself or cover any area of the screen.
	CFrame::CFrame(int Row, int Col, int Width, int Height, bool Visible, const char*
		Border, CFrame* Frame){
		if (Height<0){
			_row = Row;
			_col = Col;
			_width = console.getCols();
			_height = console.getRows();
			_visible = false;
			_border[0] = '\0';
			_frame = Frame;
			_covered = NULL;
			_fullScreen = true;
		}
		else {
			_row = Row;
			_col = Col;
			_width = Width;
			_height = Height;
			_visible = Visible;
			strcpy(_border, Border);
			_frame = Frame;
			_covered = NULL;
			_fullScreen = false;
		}
	}

	// The CFrame destructor deallocates any memory that the frame has allocated to hold characters 
	// hidden by the drawing of the frame.
	CFrame:: ~CFrame() {
		release(&_covered);
	}

	// returns the frame's top-most row position relative to the top-most row of the console
	int CFrame::absRow() const{
		int row;
		row = _row;
		CFrame* temp = frame();
		while (temp){
			row = row + temp->row();
			temp = temp->frame();
		}
		return row;
	}

	// returns the frame's left-most column position relative to the left-most column of the column
	int CFrame::absCol() const{
		int col;
		col = _col;
		CFrame* temp = frame();
		while (temp){
			col = col + temp->col();
			temp = temp->frame();
		}
		return col;
	}

	// creates C - style null terminated string(str) equal in length to the width of the frame and 
	// composed of the starting character(left), a sequence of the fill character(fill), and the 
	// ending character(right)
	void CFrame::setLine(char* str, char left, char fill, char right) const {
		int i;
		str[0] = left;
		for (i = 1; i<_width - 1; i++){
			str[i] = fill;
		}
		str[_width - 1] = right;
		str[_width] = 0;
	}

	// sets the position of the cursor to the middle of the frame
	void CFrame::goMiddle() {
		if (_visible){
			console.setPosition(absRow() + 1, absCol() + _width / 2);
		}
		else{
			console.setPosition(absRow(), absCol() + _width / 2);
		}
	}

	// sets the visibility of the border to the value received
	void CFrame::bordered(bool border){
		_visible = border;
	}

	// returns the visibility of the border
	bool CFrame::bordered() const{
		return _visible;
	}

	// sets the address of the parent to the address received
	void CFrame::frame(CFrame* frame){
		_frame = frame;
	}

	// returns the address of the parent, if any
	CFrame* CFrame::frame() const {
		return (CFrame*)_frame;
	}

	// sets the top row to the value received
	void CFrame::row(int row) {
		_row = row;
	}

	// returns the top row position relative to the parent frame, if any; 0 if fullsreen
	int CFrame::row() const {
		return _row;
	}

	// sets the left column to the value received
	void CFrame::col(int col){
		_col = col;
	}

	// returns the left column position relative to the parent frame, if any; 0 if fullsreen
	int CFrame::col() const{
		return _col;
	}

	// sets the height to the value received
	void CFrame::height(int height){
		_height = height;
	}

	// returns the current height
	int CFrame::height() const{
		return _height;
	}

	// sets the width to the value received
	void CFrame::width(int width){
		_width = width;
	}

	// returns the current width
	int CFrame::width() const{
		return _width;
	}

	// draws the frame
	// captures the characters in the console buffer that drawing of the frame will cover
	// draws the frame's border and fills the frame with blank spaces if the frame has a border and 
	// that border is visible
	void CFrame::draw(int draw){
		int i;
		char* str;
		str = new char[width() + 1];

		CFrame::capture();

		for (i = 0; i<width() + 1; i++)
		{
			str[i] = ' ';
		}
		
		if (_frame && _visible && draw != C_NO_FRAME) {

			console.setPosition(absRow(), absCol());
			//setLine(str, _border[7], ' ', _border[3]);
			setLine(str, _border[0], _border[1], _border[2]);
			cio::display(str, absRow(), absCol());
			//console << str;

			for (i = 1; i<(height() - 1); i++) {
				
				console.setPosition((absRow() + 1 + i), absCol());
				setLine(str, _border[7], ' ', _border[3]);
				cio::display(str, absRow() + i, absCol());
				//console << str;
			}

			console.setPosition((absRow() + 1 + i), absCol());
			setLine(str, _border[6], _border[5], _border[4]);
			cio::display(str, absRow() + i, absCol());
			//console << str;
		}
		delete[] str;
	}

	bool CFrame::fullscreen()const{
		return  /*_row < 0 || _col < 0 ||*/ _height < 0 || _width < 0;
	}

	// captures the characters in the console buffer that are within the rectangle where the frame 
	// will draw itself, if those characters have not already been captured
	void CFrame::capture() {
		if (!_covered){
			if (!_frame || fullscreen()){
				_covered = cio::capture(0, 0, console.getRows(), console.getCols());
			}
			else{
				_covered = cio::capture(absRow(), absCol(), _height, _width);
			}
		}
	}

	// hides the frame
	// restores the characters that were hidden by the drawing of the frame
	// deallocates the dynamic memory that held the hidden characters
	void CFrame::hide(cio::CDirection hide){
		if (!_frame || fullscreen())
			cio::restore(0, 0, console.getRows()-1, console.getCols(), hide, _covered);
		else 
			cio::restore(absRow(), absCol(), _height, _width, hide, _covered);
		
		cio::release((void**)&_covered);
	}

	// translates the frame one unit in the specified direction
	// hides the frame
	// changes the row or column position of the frame's top-left corner, if possible
	// draws the frame in its updated position
	// This method does not allow the frame to move beyond the screen boundaries.
	void CFrame::move(cio::CDirection move){
		if (move == C_MOVED_DOWN){
			if (_frame){
				if (bordered()){
					if (absRow() + _height<_frame->absRow() + _frame->height() - 1){
						hide(move);
						_row = _row + 1;
						draw();
					}
				}
				else{
					if (absRow()>_frame->absRow() && absRow()>0){
						hide(move);
						_row = _row - 1;
						draw();
					}
				}
			}
		}
		else if (move == C_MOVED_UP){
			if (_frame){
				if (bordered()){
					if (absRow()>_frame->absRow() + 1 && absRow()>0){
						hide(move);
						_row = _row - 1;
						draw();
					}
				}
				else{
					if (absRow()>_frame->absRow() && absRow()>0){
						hide(move);
						_row = _row - 1;
						draw();
					}
				}
			}
		}
		else if (move == C_MOVED_LEFT){
			if (_frame){
				if (bordered()){
					if (absCol()>_frame->absCol() + 1 && absCol()>0){
						hide(move);
						_col = _col - 1;
						draw();
					}
				}
			}
			else{
				if (absCol()>_frame->absCol() && absCol()>0){
					hide(move);
					_col = _col - 1;
					draw();
				}
			}
		}
		else if (move == C_MOVED_RIGHT){
			if (_frame){
				if (bordered()){
					if (absCol() + _width<_frame->absCol() + _frame->width() - 1){
						hide(move);
						_col = _col + 1;
						draw();
					}
				}
				else{
					if (absCol() + _width<_frame->absCol() + _frame->width()){
						hide(move);
						_col = _col + 1;
						draw();
					}
				}
			}
		}
		else if (move == C_STATIONARY){
			draw();
		}
	}

	// moves the frame referred to in the parameter. 
	// displays the message "Moving! ESC: exit" along the top line of the screen
	// collects a key press from the user
	// moves the frame by one character unit :
	// up
	// down
	// left
	// right
	// continues responding to move instructions from the user until the user presses ESCAPE
	// removes the message along the top line of the screen
	void move(iFrame &mover){
		int key;
		console.setPosition(0, console.getCols() - 8);
		console << "Moving!";
		console >> key;
		while (key != ESCAPE){
			if (key == UP){
				mover.move(C_MOVED_UP);
			}
			else if (key == DOWN){
				mover.move(C_MOVED_DOWN);
			}
			else if (key == LEFT){
				mover.move(C_MOVED_LEFT);
			}
			else if (key == RIGHT){
				mover.move(C_MOVED_RIGHT);
			}
			console >> key;
		}
		mover.draw();
	}

}//end of namespace cio