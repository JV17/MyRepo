// Console Input Output Library - Backup and Restore Support
// consolebackup.h
//
// Fardad Soleimanloo, Chris Szalwinski
// August 27 2011
// Version 1.0
//
#pragma once
#ifndef __FS_CONSOLEBACKUP_H__
#define __FS_CONSOLEBACKUP_H__

#include "cfg.h"

namespace cio{ // continuation of namespace cio
	
	// backs up the contents of a rectangle of height h, width w, with its top-left corner at row r and column c 
	// of the screen and returns the address of the dynamic memory that holds the captured rectangle 
	void* capture(int r, int c, int h, int w);
	
	//  restores the captured rectangle at address b of height h and width w with the top-left corner at row r 
	// and column c of the screen after a movement in direction d 
	void restore(int r, int c, int h, int w, CDirection d, void* b);
	
	// deallocates the dynamic memory for the captured rectangle stored at the received address and resets that 
	// address to NULL 
	void release(void**);

} // end of namespace cio
#endif