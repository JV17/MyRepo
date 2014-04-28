#ifndef _FS_CONBIO_H_
#define _FS_CONBIO_H_

// BConsole Input Output Library - C++ Module
// conbio.h
//
// Fardad Soleimanloo, Chris Szalwinski
// Feb 01 2013
// Version 1.02

namespace bio {

    /* Virtual Key Codes */

    #define TAB       '\t'
    #define BACKSPACE '\b'
    #define ALARM     '\a'
    #define ESCAPE    27
    #define ENTER     '\n'
    #define SPACE     ' '
    #define HOME      1000
    #define UP        1001
    #define DOWN      1002
    #define LEFT      1003
    #define RIGHT     1004
    #define END       1005
    #define PGDN      1006
    #define PGUP      1007
    #define DEL       1008
    #define INSERT    1009
    #define F(n)      (1009+(n))
    #define UNKNOWN   9999

    // BConsole holds the state of the BConsole Input Output Facility
    //
    class BConsole {
        char* buffer;        // screen buffer
        int   curRow;        // cursor position - current row
        int   curCol;        // cursor position - current column
        int   bufrows;       // number of rows
        int   bufcols;       // number of columns
        BConsole& operator=(const BConsole&); // prevent assignments
        BConsole(const BConsole&);            // prevent copying
        void  clearBuffer(); // clear the buffer
        void  setBufChar(char c);
        char  getBufChar() const;
    public:
        BConsole();
        virtual ~BConsole();
        char* capture(int row, int col, int height, int width);
        void  restore(int row, int col, int height, int width, char* capbuf);
        int   getRows() const;
        int   getCols() const;
        void  getPos(int& row, int& col) const;
        void  setPos(int r, int c);
        void  clear();
        void  pause()const;
        void  alarm()const;
        int   getKey()const;       // extract a key from console input
        BConsole& putChar(char);
    };

    //tools
    unsigned int strlen(const void* str);
    char* strcpy(void* des, const void* src);
    char* strncpy(void* des, const void* src, unsigned int len);
    char* strcat(void* des, const void *src);
    //end tools

} // end namespace bio
#endif