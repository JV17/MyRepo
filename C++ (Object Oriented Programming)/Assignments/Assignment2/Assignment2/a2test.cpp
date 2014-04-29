// Test Master for Assignment 2
// OOP344 - BTP300
// a2test.cpp
// 
// August 27 2011
// Fardad Soleimanloo, Chris Szalwinski
// Version 1.0

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cstdio>
#include "console.h"
#include "consoleplus.h"
#include "keys.h"
#include "cframe.h"      // for test 0
#include "cdialog.h"     // for test 1
#include "clabel.h"      // for test 2
#include "cline.h"       // for test 3
#include "cbutton.h"     // for test 4

#define TEST_NO 3        // select your test here

using namespace cio;
const int ROW_ERRORS = 22;

int  requestKey(int request);
int  reportBadKey(int request, int key, const char *msg);
void label(int key);
void testLineEditor();
void testFrame();
void testDialogLabel();
void testLineEdit();
void testButton();

int main() {
#if TEST_NO == 0
	testLineEditor();
#elif TEST_NO == 1
	testFrame();
#elif TEST_NO == 2
	testDialogLabel();
#elif TEST_NO == 3
	testLineEdit();
#elif TEST_NO == 4
	testButton();
#endif
	console << "Your test " << TEST_NO + '0' << " is complete.\n\r\n\r";
	console << "Press Enter key to finish ... \n\r";
	console.pause();
}

void testLineEditor() {
	bool insert = false;
	int i, j, key, rows, cols, errors = 0;
	int offset = 0, index = 0;
	char str[81] = "abcdefghijklmnopqrstuvwxyz";
	char  in[81] = "AbcdefghiJKLmnopqrstuvwxyZ";
	char out[81] = "AbcdefghiJKLmnopqrstuvwxyZ";
	char  ed[81] = "AbCdefghiJKLmnopqrstuv12";
	char end[81] = "AbCdefg12JKLmnopqrstuv12";
	char del[81] = "AbCdef7892JKLmnopqrstuv12";

	// draw the top and left borders
	//
	rows = console.getRows();
	cols = console.getCols();
	console.clear();
	console.setPosition(0, 0);
	j = (int)'0';
	for (i = 0; i < cols; i++) {
		console << j;
		if (j == (int)'9')
			j = (int)'0';
		else
			j++;
	}
	j = (int) '0';
	for (i = 0; i < rows; i++) {
		console.setPosition(i, 0);
		console << j;
		if (j == (int)'9')
			j = (int)'0';
		else
			j++;
	}

	// display instructions
	//
	display("abcdefghijklmnopqrstuvwxyz", 12, 5, 0);
	display("Perform the following instructions in turn", 1, 1, 0);
	display("Press Right Arrow Twice, Down Arrow Twice", 3, 3, 0);
	display("Using Arrow and ASCII keys, change \"jkl\" to \"JKL\"", 4, 3, 0);
	display("Press Home, A, End, Left Arrow, Z, Home, Enter", 5, 3, 0);
	display("Press Home, a, End, Left Arrow, z, Home, Escape", 6, 3, 0);
	display("Press C, End, Backspace 4 times, 1, 2, Home, Enter", 7, 3, 0);
	display("Press End, Home, Right Arrow 7 times, 1, 2, Enter", 8, 3, 0);
	display("Press Delete Twice, Insert, 7, 8, 9, Enter", 9, 3, 0);

	// start the test
	//
	console.setPosition(3, 3);
	errors += requestKey(RIGHT);
	if (!errors)console.setPosition(3, 4);
	errors += requestKey(RIGHT);
	if (!errors)console.setPosition(3, 5);
	errors += requestKey(DOWN);
	if (!errors)console.setPosition(4, 5);
	errors += requestKey(DOWN);
	if (!errors)console.setPosition(5, 5);
	if (!errors) {
		key = edit(str, 14, 5, 26, 80, &insert, &offset, &index);
		if (key != ENTER) errors += reportBadKey(ENTER, key, (const char*)NULL);
		if (strcmp(str, out)) errors += reportBadKey(ENTER, 0, "Incorrect string result");
		key = edit(str, 15, 5, 26, 80, &insert, &offset, &index);
		if (key != ESCAPE) errors += reportBadKey(ESCAPE, key, (const char*)NULL);
		if (strcmp(str, in)) errors += reportBadKey(ESCAPE, 0, "Incorrect string result");
		index = 2;
		key = edit(str, 16, 5, 26, 80, &insert, &offset, &index);
		if (key != ENTER) errors += reportBadKey(ENTER, key, (const char*)NULL);
		if (strcmp(str, ed)) errors += reportBadKey(ENTER, 0, "Incorrect string result");
		index = 9;
		key = edit(str, 14, cols - 10, strlen(str), 80, &insert, &offset, &index);
		if (key != ENTER) errors += reportBadKey(ENTER, key, (const char*)NULL);
		if (strcmp(str, end)) errors += reportBadKey(ENTER, 0, "Incorrect string result");
		index = 6;
		key = edit(str, 17, 5, 26, 80, &insert, &offset, &index);
		if (key != ENTER) errors += reportBadKey(ENTER, key, (const char*)NULL);
		if (strcmp(str, del)) errors += reportBadKey(ENTER, 0, "Incorrect string result");
	}

	// finish the test
	//
	console.setPosition(ROW_ERRORS - 3, 3);
	if (errors)
		console << "Continue working! ";
	else
		console << "If no errors, prepare screen shot (include top row of numbers) ... ";

	console.setPosition(ROW_ERRORS - 2, 3);
	console << "Press Enter key to exit!";
	console.pause();
	console.clear();
}

void testFrame() {
	bool done = false;
	CFrame frame;
	CFrame outer(5, 10, 50, 15, true, "+-+|+-+|", &frame);
	CFrame inner(5, 10, 20, 5, true, C_BORDER_CHARS, &outer);

	outer.draw();
	inner.draw();
	console.setPosition(0, 0);
	console << "Press any key...";
	console.pause();

	do {
		int key;
		console.setPosition(0, 0);
		console << "ESC: exit, F6: Move Container, F7: Move Inner border";
		console >> key;
		switch (key) {
		case ESCAPE:
			done = true;
			break;
		case F(6):
			move(outer);
			inner.draw();
			break;
		case F(7):
			move(inner);
			break;
		}
	} while (!done);

	outer.hide();
	inner.hide();
	console.clear();
}

void testDialogLabel() {
	bool i = true;
	bool done = false;
	int  loop = 0;
	bool visible = false;

	// background
	for (int k = 0; k < console.getRows(); k += 2) {
		for (int m = 0; m < console.getCols() - 10; m += 10) {
			console.setPosition(k, m);
			i = !i;
			console << (i ? "OOP344" : "BTP300");
		}
	}

	CDialog screen;
	CDialog dialog(&screen, 5, 10, 53, 16, true, "+-+|+-+|");
	CLabel  label("This is a non-dynamic label", 5, 3);

	dialog.add(new CLabel("Testing Read Only Dialog", 1, 12));
	dialog << new CLabel("A trimmed dynamic label goes here, and I'm checking if it is trimmed", 3, 3, 50) << label;
	int mesIndx = dialog.add(new CLabel("Test", 7, 3, 40));
	dialog << new CLabel("ESC to exit, F6 to move, other to loop", 9, 3);
	dialog[mesIndx].set("Setting the message to see what happens");
	dialog << new CLabel("Press F6, Right Arrow Twice, Up Arrow Once, ESC", 11, 3);
	dialog << new CLabel("If there are no errors take your screen shot!", 13, 3);
	dialog.draw();

	do {
		int key = dialog.edit(mesIndx + 1);
		loop++;
		std::sprintf((char*)dialog[mesIndx].data(), "LOOP No: %d", loop);
		switch (key) {
		case ESCAPE:
			done = true;
			break;
		case F(6):
			move(dialog);
			break;
		}
	} while (!done);

	dialog.hide();
	console.clear();
}

void testLineEdit() {
	int  loop = 0;
	bool i = true;
	bool insert = true;
	bool done = false;
	char str[81] = "I want to edit this thing!";

	// background
	for (int k = 0; k < console.getRows(); k += 2) {
		for (int m = 0; m < console.getCols() - 10; m += 10) {
			console.setPosition(k, m);
			i = !i;
			console << (i ? "OOP344" : "BTP300");
		}
	}

	CDialog app;
	CDialog dialog(&app, 5, 10, 50, 15, true, "+-+|+-+|");
	CLabel  label("Enter some text down here:", 6, 4);

	app << new CLabel("Dialog and Line Editor Tester", 0, 0);

	dialog.add(new CLabel("Testing Label and Line edit", 0, 12));
	dialog << new CLabel("Name: ", 4, 3)
		<< new CLine(4, 9, 20, 40, &insert) << label
		<< new CLine(str, 7, 4, 40, 80, &insert, true);
	int mesIndx = dialog.add(new CLabel(10, 5, 40));
	dialog << new CLabel("ESC/F2 to exit, F6 to Move, F7 to loop++", 2, 3);
	dialog[mesIndx].set("Setting the message to see what happens");
	dialog.draw();

	do {
		int key = dialog.edit(mesIndx + 1);
		loop++;
		std::sprintf((char*)dialog[mesIndx].data(), "LOOP No: %d", loop);
		switch (key) {
		case ESCAPE:
		case F(2):
			done = true;
			break;
		case F(6):
			move(dialog);
			break;
		case F(7):
			break;
		}
	} while (!done);

	console.clear();
	console.setPosition(10, 0);
	console << "First  Lineedit data:";
	console.setPosition(10, 23);
	console << (char*)dialog[2].data();
	console.setPosition(12, 0);
	console << "Second Lineedit data:";
	console.setPosition(12, 23);
	console << (char*)dialog[4].data();
	console.setPosition(14, 0);
}

void testButton() {
	bool done = false;
	bool i = true;
	int fn = C_FULL_FRAME;

	for (int k = 0; k < console.getRows(); k += 2) {
		for (int m = 0; m < console.getCols() - 10; m += 10) {
			console.setPosition(k, m);
			i = !i;
			console << (i ? "OOP344" : "BTP300");
		}
	}

	CDialog app;
	CDialog dialog(&app, 5, 10, 50, 15, true, "+-+|+-+|");
	CButton inc("Increase", 9, 10);
	CButton dec("Decrease", 9, 30);
	dialog.add(new CLabel("Testing Buttons (bordered)", 1, 12, 30));
	dialog.add(new CLabel("Press F10 to toggle button borders visiblity", 3, 3));
	int mesIndx = dialog.add(new CLabel(7, 24, 10));

	int j = 100;
	dialog << inc << dec
		<< new CLabel("Press Escape to exit", 12, 15);
	dialog[mesIndx].set("100");

	do {
		int key = dialog.edit(fn);
		switch (key){
		case ESCAPE:
			done = true;
			break;
		case F(10):
			inc.bordered(!inc.bordered());
			dec.bordered(!dec.bordered());
			dialog[0].set(inc.bordered() ? "Testing Buttons (bordered)" : "Testing Buttons (no border)");
			dialog.draw();
			break;
		case F(6):
			move(dialog);
			break;
		case C_BUTTON_HIT:
			if (&dialog.curField() == &inc) {
				j++;
				fn = 4;
			}
			else {
				j--;
				fn = 5;
			}
			std::sprintf((char*)dialog[mesIndx].data(), "%d", j);
			dialog[mesIndx].draw();
			break;
		}
	} while (!done);

	console.clear();
	console.setPosition(10, 0);
	console << "Final Button Value:";
	console.setPosition(10, 23);
	console << (char*)dialog[mesIndx].data();
	console.setPosition(12, 0);
}

//--------------------------- test 0 functions ------------------------------
//
// Request a key press, accept the key code and
// report the difference if any
//
int requestKey(int request) {
	int key, rc = 0;

	console >> key;
	if (key != request) {
		rc = reportBadKey(request, key, 0);
	}
	return rc;
}

/* Report a faulty key press */
int reportBadKey(int request, int key, const char *msg) {
	static int row = ROW_ERRORS;

	if (row != ROW_ERRORS) {
		console.setPosition(ROW_ERRORS - 1, 8);
		console << "s!";
	}
	else {
		console.setPosition(ROW_ERRORS - 1, 3);
		console << "Error!";
	}
	console.setPosition(row++, 3);
	if (key != 0) {
		console << "Key requested : ";
		label(request);
		console.setPosition(row++, 3);
		console << "You pressed   : ";
		label(key);
	}
	else
		console << msg;
	return 1;
}

// Displays key label at the current cursor position 
//
void label(int key) {
	if (key >= ' ' && key <= '~') {
		console << key;
		console << "            ";
	}
	else {
		switch (key) {
		case LEFT:      console << "Left Arrow   "; break;
		case RIGHT:     console << "Right Arrow  "; break;
		case HOME:      console << "Home         "; break;
		case END:       console << "End          "; break;
		case INSERT:    console << "Insert       "; break;
		case DEL:       console << "Delete       "; break;
		case BACKSPACE: console << "Backspace    "; break;
		case ESCAPE:    console << "Escape       "; break;
		case ENTER:     console << "Enter        "; break;
		case TAB:       console << "Tab          "; break;
		case UP:        console << "Up Arrow     "; break;
		case DOWN:      console << "Down Arrow   "; break;
		case PGUP:      console << "Page Up      "; break;
		case PGDN:      console << "Page Down    "; break;
		case F(1):      console << "F1           "; break;
		case F(2):      console << "F2           "; break;
		case F(3):      console << "F3           "; break;
		case F(4):      console << "F4           "; break;
		case F(5):      console << "F5           "; break;
		case F(6):      console << "F6           "; break;
		case F(7):      console << "F7           "; break;
		case F(8):      console << "F8           "; break;
		case F(9):      console << "F9           "; break;
		case F(10):     console << "F10          "; break;
		case F(11):     console << "F11          "; break;
		case F(12):     console << "F12          "; break;
		case UNKNOWN:   console << "Unknown Key  "; break;
		default:        console << "non-ASCII key";
		}
	}
}