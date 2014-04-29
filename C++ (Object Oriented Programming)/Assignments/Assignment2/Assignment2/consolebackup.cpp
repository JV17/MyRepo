// Console Input Output Library - Backup and Restore Support
// consolebackup.cpp
//
// Fardad Soleimanloo, Chris Szalwinski
// August 27 2011
// Version 1.0
//
#include "console.h"
#include "consolebackup.h"
#include "cfg.h"         // for the CDirection enumeration constants

namespace cio {

	// capture backs up a portion of the console buffer to newly
	// allocated memory and returns the address of that memory
	//
	void* capture(int row, int col, int height, int width) {
		int i = 0;
		char* capbuf = new char[height * width];

		if (capbuf) {
			for (int r = 0; r < height; r++) {
				for (int c = 0; c < width; c++) {
					console.setPosition(row + r, col + c);
					capbuf[i++] = console.getCharacter();
				}
			}
		}
		return (void*)capbuf;
	}

	// restore retrieves a previously backed up portion of
	// the console buffer and displays those characters from
	// the restored buffer that have changed as a result of
	// the motion (dir)
	//
	void restore(int row, int col, int height, int width,
		CDirection dir, void* capbuf) {
		int i = 0;

		if (capbuf) {
			for (int r = 0; r < height; r++) {
				for (int c = 0; c < width; c++) {
					console.setPosition(row + r, col + c);
					console.setCharacter(((char*)capbuf)[i++]);
				}
			}
			// redraws all or part of the restored portion
			if (dir == C_MOVED_DOWN) {
				// redraw the top border
				for (int c = 0; c < width; c++) {
					console.setPosition(row, col + c);
					console.drawCharacter();
				}
			}
			else if (dir == C_MOVED_RIGHT) {
				// redraw the left border
				for (int r = 0; r < height; r++) {
					console.setPosition(row + r, col);
					console.drawCharacter();
				}
			}
			else if (dir == C_MOVED_LEFT) {
				// redraw the right border
				for (int r = 0; r < height; r++) {
					console.setPosition(row + r, col + width - 1);
					console.drawCharacter();
				}
			}
			else if (dir == C_MOVED_UP) {
				// redraw the bottom border
				for (int c = 0; c < width; c++) {
					console.setPosition(row + height - 1, col + c);
					console.drawCharacter();
				}
			}
			else if (dir == C_STATIONARY) {
				// redraw the entire portion
				for (int r = 0; r < height; r++) {
					for (int c = 0; c < width; c++) {
						console.setPosition(row + r, col + c);
						console.drawCharacter();
					}
				}
			}
		}
	}

	// release deallocates the memory for the backed-up portion of
	// the console buffer at *capbuf and sets the address of that
	// memory to NULL
	//
	void release(void** capbuf) {

		if (*capbuf) {
			delete[](char*)*capbuf;
			*capbuf = (void*)0;
		}
	}

} // end of namespace cio for now