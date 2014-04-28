// Jorge E. Valbuena S.
// OOP344A - Assignment #2
#pragma once
#ifndef __CFRAME_H__
#define __CFRAME_H__

#include "iframe.h"
#include "keys.h"

namespace cio { // continuation of namespace cio

	class CFrame : public iFrame{
	protected:
		int _row; // relative row of left top corner to the container frame or the screen if _frame is null
		int _col; // relative col of left top corner to the container frame or the screen if _frame is null
		int _height; // height of frame
		int _width; // width of frame
		char _border[9]; // border characters
		bool _visible; // is bordered or not
		CFrame* _frame; // pointer to the container of the frame (the frame, surrounding this frame)
		void* _covered; // pointer to the characters of the screen which are covered by this frame, when displayed
		bool _fullScreen; // fullscreen
		void setLine(char* str, char left, char fill, char right) const;
		void capture();
		int absRow()const;
		int absCol()const;
	public:
		CFrame(int Row = -1, int Col = -1, int Width = -1, int Height = -1, bool Visible = false, const char* Border = C_BORDER_CHARS, CFrame* Frame = 0);
		virtual ~CFrame();
		bool fullscreen()const;
		void goMiddle();
		void bordered(bool border);
		bool bordered() const;
		void frame(CFrame* frame);
		CFrame* frame() const;
		void row(int row);
		int row() const;
		void col(int col);
		int col() const;
		void height(int height);
		int height() const;
		void width(int width);
		int width() const;
		virtual void draw(int = C_FULL_FRAME);
		void hide(CDirection = C_STATIONARY);
		void move(cio::CDirection move);
	};
	void move(cio::iFrame& mover);

} // end of namespace cio
#endif