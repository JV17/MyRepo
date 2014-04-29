// Test Main for Line Edit Support
// a1test.cpp
//
// Fardad Soleimanloo, Chris Szalwinski
// September 22 2011
// Version 1.1
//
#include <cstring>
#include "console.h"
#include "consoleplus.h"
#include "keys.h"
using namespace std;  // version 1.1 added
using namespace cio;
const int ROW_ERRORS = 22;

int requestKey(int request);
int reportBadKey(int request, int key, const char *msg);
void label(int key);
void testLineEditor();

int main() {
    testLineEditor();
    console << "Your line editor test has completed.\n\r";
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
        if (key != ENTER) errors += reportBadKey(ENTER, key, NULL);
        if (strcmp(str, out)) errors += reportBadKey(ENTER, 0, "Incorrect string result");
        key = edit(str, 15, 5, 26, 80, &insert, &offset, &index);
        if (key != ESCAPE) errors += reportBadKey(ESCAPE, key, NULL);
        if (strcmp(str, in)) errors += reportBadKey(ESCAPE, 0, "Incorrect string result");
        index = 2;
        key = edit(str, 16, 5, 26, 80, &insert, &offset, &index);
        if (key != ENTER) errors += reportBadKey(ENTER, key, NULL);
        if (strcmp(str, ed)) errors += reportBadKey(ENTER, 0, "Incorrect string result");
        index = 9;
        key = edit(str, 14, cols - 10, strlen(str), 80, &insert, &offset, &index);
        if (key != ENTER) errors += reportBadKey(ENTER, key, NULL);
        if (strcmp(str,end)) errors += reportBadKey(ENTER, 0, "Incorrect string result");
        index = 6;
        key = edit(str, 17, 5, 26, 80, &insert, &offset, &index);
        if (key != ENTER) errors += reportBadKey(ENTER, key, NULL);
        if (strcmp(str,del)) errors += reportBadKey(ENTER, 0, "Incorrect string result");
    }

    // finish the test
    //
    console.setPosition(ROW_ERRORS - 3, 3);
    if (errors) {
        console << "Continue working! ";
    } else {
        console << "If no errors, prepare screen shot (include top row of numbers) ... ";
    }
    console.setPosition(ROW_ERRORS - 2, 3);
    console << "Press Enter key to exit!";
    console.pause();
    console.clear();
}

/* Request a key press, accept the key code and
 * report the difference if any
 */
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
    } else {
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
    } else
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


