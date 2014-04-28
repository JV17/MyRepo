#ifndef _FS_CONSOLE_H_
#define _FS_CONSOLE_H_

// Console Input Output Library - C++ Module
// console.h
//
// Fardad Soleimanloo, Chris Szalwinski
// August 25 2011
// Version 1.0
//

namespace cio {

// Console holds the state of the Console Input Output Facility
//
class Console {
    char* buffer;        // screen buffer
    int   curRow;        // cursor position - current row
    int   curCol;        // cursor position - current column
    int   bufrows;       // number of rows
    int   bufcols;       // number of columns
    Console& operator=(const Console&); // prevent assignments
    Console(const Console&);            // prevent copying
    void  clearBuffer(); // clear the buffer
    int   getKey();       // extract a key from console input
  public:
    Console();
    ~Console();
    int   getRows() const;
    int   getCols() const;
    void  getPosition(int& row, int& col) const;
    void  setPosition(int r, int c);
    char  getCharacter() const;
    void  setCharacter(char c);
    void  drawCharacter();
    void  clear();
    void  pause();
    friend Console& operator>>(Console&, int&);
    friend Console& operator<<(Console&, char);
};

Console& operator<<(Console&, const char*);

extern Console console; // console object - external linkage

} // end namespace cio
#endif