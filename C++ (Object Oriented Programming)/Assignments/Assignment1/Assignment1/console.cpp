// Console Input Output Library - Unified Implementation
// console.cpp
//
// Fardad Soleimanloo, Chris Szalwinski
// August 25 2011
// Version 1.0
//

/* table of platforms */
#define CIO_LINUX       1
#define CIO_MICROSOFT   2
#define CIO_BORLAND     3
#define CIO_UNIX        4

/* auto-select your platform here */
#if   defined __BORLANDC__
    #define CIO_PLATFORM CIO_BORLAND
    #define CIO_LOWER_LEVEL_H_ <conio.h>
#elif defined _MSC_VER
    #define CIO_PLATFORM CIO_MICROSOFT
    #include <windows.h>
    #define CIO_LOWER_LEVEL_H_ <conio.h>
#elif defined __MACH__
    #define CIO_PLATFORM CIO_UNIX
    #define CIO_LOWER_LEVEL_H_ <curses.h>
#elif defined __GNUC__
    #define CIO_PLATFORM CIO_LINUX
    #define CIO_LOWER_LEVEL_H_ <ncurses.h>
#elif !defined __BORLANDC__ && !defined _MSC_VER && !defined __GNUC__ && !defined __MACH__
    #error CONSOLE_PLT is undefined
#endif

extern "C" {
    #include CIO_LOWER_LEVEL_H_
}

#include "console.h"
#include "keys.h"

namespace cio { // continuation of cio namespace

//----------------- Platform-Dependent Section ------------------------------
//

#if CIO_PLATFORM == CIO_LINUX || CIO_PLATFORM == CIO_UNIX

// Console initializes the Console Input Output object
//
Console::Console() {
    ::initscr();
    ::noecho();
    ::cbreak();
    ::keypad(stdscr,1);
    bufrows = LINES;
    bufcols = COLS;
    if (bufrows * bufcols > 0)
        buffer  = new char[bufrows * bufcols];
    else
        buffer = 0;
    clear();
}

Console::~Console() {
    clear();
    setPosition(0, 0);
    delete [] buffer;
    ::endwin();
}

void Console::clear() {
    ::erase();
    clearBuffer();
}

int Console::getKey() {
    int key;
    ::refresh();
    key = ::getch();
    switch(key) {
        // KEY_* is defined in *curses.h
        case KEY_HOME:  key = HOME;   break;
        case KEY_UP:    key = UP;     break;
        case KEY_DOWN:  key = DOWN;   break;
        case KEY_LEFT:  key = LEFT;   break;
        case KEY_RIGHT: key = RIGHT;  break;
        case KEY_END:   key = END;    break;
        case KEY_NPAGE: key = PGDN;   break;
        case KEY_PPAGE: key = PGUP;   break;
        case KEY_DC:    key = DEL;    break;
        case KEY_IC:    key = INSERT; break;
        case KEY_F(1):  key = F(1);   break;
        case KEY_F(2):  key = F(2);   break;
        case KEY_F(3):  key = F(3);   break;
        case KEY_F(4):  key = F(4);   break;
        case KEY_F(5):  key = F(5);   break;
        case KEY_F(6):  key = F(6);   break;
        case KEY_F(7):  key = F(7);   break;
        case KEY_F(8):  key = F(8);   break;
        case KEY_F(9):  key = F(9);   break;
        case KEY_F(10): key = F(10);  break;
        case KEY_F(11): key = F(11);  break;
        case KEY_F(12): key = F(12);  break;
        case KEY_ENTER: key = ENTER;  break;
        case KEY_BACKSPACE: key = BACKSPACE; break;
        default:
            if (key < 0 || key > '~')
                key = UNKNOWN;
    }

    return key;
}

// setPosition moves the cursor to row r column c
//
void Console::setPosition(int r, int c) {
    curRow = r;
    curCol = c;
    ::move(r, c);
}

// drawCharacter draws the character at the current cursor position
//
void Console::drawCharacter() {
    if (buffer) ::addch(buffer[curRow * bufcols + curCol]);
}

// << inserts character c at the current cursor position
//
Console& operator<<(Console& os, char c) {
    ::addch(c);
    os.setCharacter(c);
    return os;
}

#elif CIO_PLATFORM == CIO_MICROSOFT

HANDLE  consh;
CONSOLE_SCREEN_BUFFER_INFO bufinfo;

// Console initializes the Console Input Output object
//
Console::Console() {
    consh = ::GetStdHandle(STD_OUTPUT_HANDLE);
    ::GetConsoleScreenBufferInfo(consh, &bufinfo);
    bufrows = bufinfo.srWindow.Bottom + 1;
    bufcols = bufinfo.srWindow.Right + 1;
    if (bufrows * bufcols > 0)
        buffer  = new char[bufrows * bufcols];
    else
        buffer = 0;
    clear();
}

Console::~Console() {
    clear();
    setPosition(0, 0);
    delete [] buffer;
}

void Console::clear() {
    DWORD
        len = bufrows * bufcols,
        actual;
    TCHAR ch = ' ';
    COORD coord;
    coord.X = 0;
    coord.Y = 0;
    ::FillConsoleOutputCharacter(consh, ch, len, coord, &actual);
    clearBuffer();
}

int Console::getKey() {
    int key;
    key = ::_getch();
    /* Platform Specific Key Code */
    #define KEY_ENTER  13
    if (key == 0) {
        key = ::_getch();
        /* Platform Specific Key Codes */
        #define KEY_F0     58
        #define KEY_F(n)   (KEY_F0+(((n)<=10)?(n):((n) + 64)))
        switch(key) {
            case KEY_F(1):  key = F(1);   break;
            case KEY_F(2):  key = F(2);   break;
            case KEY_F(3):  key = F(3);   break;
            case KEY_F(4):  key = F(4);   break;
            case KEY_F(5):  key = F(5);   break;
            case KEY_F(6):  key = F(6);   break;
            case KEY_F(7):  key = F(7);   break;
            case KEY_F(8):  key = F(8);   break;
            case KEY_F(9):  key = F(9);   break;
            case KEY_F(10): key = F(10);  break;
            default: key = UNKNOWN;
        }
    } else if (key == 224) {
        key = ::_getch();
        /* Platform Specific Key Codes */
        #define KEY_HOME   71
        #define KEY_UP     72
        #define KEY_DOWN   80
        #define KEY_LEFT   75
        #define KEY_RIGHT  77
        #define KEY_END    79
        #define KEY_NPAGE  81
        #define KEY_PPAGE  73
        #define KEY_DC     83
        #define KEY_IC     82
        #define KEY_ENTER  13
        switch(key) {
            case KEY_HOME:  key = HOME;   break;
            case KEY_UP:    key = UP;     break;
            case KEY_DOWN:  key = DOWN;   break;
            case KEY_LEFT:  key = LEFT;   break;
            case KEY_RIGHT: key = RIGHT;  break;
            case KEY_END:   key = END;    break;
            case KEY_NPAGE: key = PGDN;   break;
            case KEY_PPAGE: key = PGUP;   break;
            case KEY_DC:    key = DEL;    break;
            case KEY_IC:    key = INSERT; break;
            case KEY_F(11): key = F(11);  break;
            case KEY_F(12): key = F(12);  break;
            default: key = UNKNOWN;
        }
    } else if (key < 0 || key > '~')
        key = UNKNOWN;
    else if (key == KEY_ENTER)
        key = ENTER;

    return key;
}

// setPosition moves the cursor to row r column c
//
void Console::setPosition(int r, int c) {
    curRow = r;
    curCol = c;
    COORD coord;
    coord.X = c;
    coord.Y = r;
    ::SetConsoleCursorPosition(consh, coord);
}

// drawCharacter draws the character at the current cursor position
//
void Console::drawCharacter() {
    if (buffer) ::_putch(buffer[curRow * bufcols + curCol]);
}

// << inserts character c at the current cursor position
//
Console& operator<<(Console& os, char c) {
    ::_putch(c);
    os.setCharacter(c);
    return os;
}

#elif CIO_PLATFORM == CIO_BORLAND

// Console initializes the Console Input Output object
//
Console::Console() {
    struct text_info x;
    ::gettextinfo(&x);
    bufrows = x.screenheight;
    bufcols = x.screenwidth;
    if (bufrows * bufcols > 0)
        buffer  = new char[bufrows * bufcols];
    else
        buffer = 0;
    clear();
}

Console::~Console() {
    clear();
    setPosition(0, 0);
    delete [] buffer;
}

void Console::clear(){
    ::clrscr();
    clearBuffer();
}

int Console::getKey() {
    int key;
    key = ::getch();
    /* Platform Specific Key Code */
    #define KEY_ENTER  13
    if (key == 0) {
        key = ::getch();
        /* Platform Specific Key Codes */
        #define KEY_HOME   71
        #define KEY_UP     72
        #define KEY_DOWN   80
        #define KEY_LEFT   75
        #define KEY_RIGHT  77
        #define KEY_END    79
        #define KEY_NPAGE  81
        #define KEY_PPAGE  73
        #define KEY_DC     83
        #define KEY_IC     82
        #define KEY_F0     58
        #define KEY_F(n)   (KEY_F0+(((n)<=10)?(n):((n) + 64)))
        switch(key) {
            case KEY_HOME:  key = HOME;   break;
            case KEY_UP:    key = UP;     break;
            case KEY_DOWN:  key = DOWN;   break;
            case KEY_LEFT:  key = LEFT;   break;
            case KEY_RIGHT: key = RIGHT;  break;
            case KEY_END:   key = END;    break;
            case KEY_NPAGE: key = PGDN;   break;
            case KEY_PPAGE: key = PGUP;   break;
            case KEY_DC:    key = DEL; break;
            case KEY_IC:    key = INSERT; break;
            case KEY_F(1):  key = F(1);   break;
            case KEY_F(2):  key = F(2);   break;
            case KEY_F(3):  key = F(3);   break;
            case KEY_F(4):  key = F(4);   break;
            case KEY_F(5):  key = F(5);   break;
            case KEY_F(6):  key = F(6);   break;
            case KEY_F(7):  key = F(7);   break;
            case KEY_F(8):  key = F(8);   break;
            case KEY_F(9):  key = F(9);   break;
            case KEY_F(10): key = F(10);  break;
            case KEY_F(11): key = F(11);  break;
            case KEY_F(12): key = F(12);  break;
            default:
                key = UNKNOWN;
        }
    } else if (key < 0 || key > '~')
        key = UNKNOWN;
    else if (key == KEY_ENTER)
        key = ENTER;

    return key;
}

// setPosition moves the cursor to row r column c
//
void Console::setPosition(int r, int c) {
    curRow = r;
    curCol = c;
    ::gotoxy(c + 1, r + 1);
}

// drawCharacter draws the character at the current cursor position
//
void Console::drawCharacter() {
    if (buffer) ::putch(buffer[curRow * bufcols + curCol]);
}

// << inserts character c at the current cursor position
//
Console& operator<<(Console& os, char c) {
    ::putch(c);
    os.setCharacter(c);
    return os;
}

#endif

//--------------------------- Platform-Independent Section ------------------

// Definition of the Console Input Output object
//
Console console;

// getRows retrieves the number of rows in the output object
//
int  Console::getRows() const {
    return bufrows;
}

// getCols retrieves the number of columns in the output object
//
int  Console::getCols() const {
    return bufcols;
}

// getPosition retrieves the current position of the cursor
//
void Console::getPosition(int& r, int& c) const {
    r = curRow;
    c = curCol;
}

// clearBuffer clears the cio buffer and resets the cursor
// position to the top left corner
//
void Console::clearBuffer() {
    for (int i = 0; buffer && i < bufrows * bufcols; i++)
        buffer[i] = ' ';
    setPosition(0, 0);
}

// pause accepts a key press from the input object
//
void Console::pause() {
    getKey();
}

// setCharacter sets the character at the current cursor position to c
// and moves the currect cursor position one character towards the end
//
void Console::setCharacter(char c) {
    if (buffer)
        buffer[curRow * bufcols + curCol++] = c;
}

// getCharacter returns the character at the current cursor position
//
char Console::getCharacter() const {
    return buffer ? buffer[curRow * bufcols + curCol] : ' ';
}

// >> extracts the next key from the input object
//
Console& operator>>(Console& is, int& c) {
    c = is.getKey();
    return is;
}

// << inserts string str at the current cursor position

Console& operator<<(Console& os, const char* str) {
    for(int i = 0; str[i]; i++)
        os << str[i];
    return os;
}

} // end namespace cio
