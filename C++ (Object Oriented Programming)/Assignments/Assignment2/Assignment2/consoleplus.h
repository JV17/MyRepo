// Jorge E. Valbuena S.
// OOP344A - Assignment #1
#pragma once
#ifndef __FS_CONSOLEPLUS_H__
#define __FS_CONSOLEPLUS_H__

#include "keys.h"
#include "console.h"
#include <iostream>

namespace cio{ // continuation of namespace cio

	static bool _insertMode;
	static int _tabsize;

	// The Display function handles all the display functionalities of text editor like displaying string and curpos
	void display(const char* str, int row, int col, int fieldLen = 0, int curPosition = -1);

	// The Edit function handles all edit functionalities like user inputs of text editor like pressing ENTER
	int  edit(char *str, int row, int col, int fieldLength, int maxStrLength,
		bool* insertMode = (bool*)_insertMode, int* strOffset = (int*)0, int* curPosition = (int*)0,
		bool InTextEditor = false, bool ReadOnly = false);

} // end of namespace cio
#endif