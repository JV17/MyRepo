// Jorge E. Valbuena S.
// ID 063-519-102
// OOP344A - Assignment #1

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "consoleplus.h"
#include <cstring>
    

    /************************************************ FUNCTION DISPLAY**********************************************************************
    void display(const char *str, int row, int col, int fieldfieldLen)
    This function displays the C-style, null-terminated string pointed to by str, starting at row row and column col of the console screen in a
    field of fieldLen characters.

    Row value 0 refers to the top row, and column value 0 refers to the left-most column.  If the string is longer than fieldLen, your function
    displays the first fieldLen characters.  If the string is shorter than fieldLen, your function displays the portion of the entire string that
    fits on the screen, followed by enough trailing spaces to fill out the field completely.  If fieldLen is 0 or less, your function displays the
    portion of the entire string that fits on the screen with no trailing spaces.

    Your function positions the cursor after the last character displayed, but excluding any added trailing spaces, if the last character is not in
    the last column of the screen; otherwise, your function positions the cursor under the last character on the screen.  Your function does not flush
    the output buffer.  The results are undefined if the starting position of the string is not within the dimensions of the screen.
    */

    void display(const char* str, int row, int col, int fieldLen, int curPosition){
       
        if (!str) return;
        
        int maxRow = cio::console.getRows(); //Maximum rows 
        int maxCol = cio::console.getCols(); //Maximum columns
        int strLen = strlen(str); //String length
        int i=0; //For loop intiger counter
        int lastChar = 0; 

        cio::console.setPosition(row, col);
        
        if (fieldLen <= 0){
            cio::console << str;
            cio::console.setPosition(row, col + (strLen - 1));
        }
        else if (strLen < fieldLen){
            for (; i <= strLen && (i + col) < maxCol; i++){
                cio::console << str[i];
            }
            lastChar = i;
            cio::console.setPosition(row, col + i - 1);
            if (col + i<maxCol){
                for (; strLen + i <= fieldLen - 1; i++){
                    cio::console << ' ';
                }
            }
        }
        else if (strLen >= fieldLen){
            if ((strLen + col) <= maxCol){
                for (; i<fieldLen; i++){
                    cio::console << str[i];
                }
            }
            else{
                for (; (i + col) < maxCol && i <fieldLen; i++){
                    cio::console << str[i];
                }
                cio::console.setPosition(row, col + i - 1);
            }
        }
        if (curPosition >= 0){
            cio::console.setPosition(row, col + curPosition);
        }
        else{ //Position the cursor after the last Character of the string if curPosition < 0
            cio::console.setPosition(row, col + lastChar);
        }
     

    }/*************************************** END OF DISPLAY FUNCTION **********************************************************************/


    /**************************************** FUNCTION EDIT **********************************************************************************

    int edit(char *str, int row, int col, int fieldfieldLength, int maxStrfieldLength, bool* insertMode, int* strOffset, int* curPosition)

    This function edits the C-style, null-terminated string pointed to by str.  The parameter row holds the row
    (0 is the top row) of the string on the console screen.  The parameter col holds the starting column (0 is the left-most column) on the screen.
    The parameter fieldfieldLength holds the fieldLength of the editable field.  The string may be larger than the field itself, in which case part of the
    string is hidden from view.  The parameter maxStrfieldLength holds the maximum fieldLength of the string, excluding the null byte.  The parameter insertMode
    points to a bool variable that holds the current insert mode of the string.  The parameter insertMode receives the address of a variable that stores
    the current editing mode - insert or overwrite.  The parameter strOffset points to an int variable that holds the initial offset of the string
    within the field; that is, the index of the character in the string that initially occupies the first character position in the field.  The parameter
    curPosition points to an int variable that holds the initial cursor position within the field; that is, the index of the character in the field at
    which the cursor is initially placed.

    If the initial offset is beyond the end of the string, your function resets the offset to the fieldLength of the string; that is, to the index of the character
    immediately beyond the end of the string.  If no offset variable is pointed to; that is, if the address of the variable is NULL, your function sets the
    offset to the index of the first character in the string; that is, to 0.

    If the initial cursor position is beyond the end of the field, your function resets the position to the last character in the field.  If the position is
    beyond the end of the string, your function resets the position to that immediately beyond the end of the string.  If no cursor position variable is pointed to;
    that is, if the address of the variable is NULL, your function sets the cursor position to the first position in the field; that is, to position 0.

    The function does not allow the cursor to move before the start of the field or past the end of the field.  If the field ends at the right edge of the screen,
    your function does not allow the cursor to the right of that edge.

    The function uses the symbolic names for non-ASCII and special keys defined in the keys.h header file.  These names are the same symbolic names as those
    used in the original library module.

    The user terminates editing by pressing ENTER, TAB, ESCAPE, UP, DOWN, PGUP, PGDN or any of the Function keys F(1) through F(12) inclusive.  If the user
    presses ESCAPE, the function aborts editing, replaces the contents of the string with the original contents upon entry into your function, and leaves the
    offset and cursor position values unaltered.  In order to be able to revert to the original string, the function needs to allocate memory at run time.

    At termination, the function passes back through the same int variables the current values of the offset and the cursor position, unless no variables were
    pointed to upon entry into the function; that is, unless the value of either address was NULL.

    The function returns an int identifying the key that the user pressed to exit the function.

    The function takes no action (other than perhaps beeping) if the user tries to enter too many characters (if, for example, the string is full in insert mode,
    or the cursor is positioned after the last character of a full string in overstrike mode).

    The function handles the non-ASCII keys as follows
    ->LEFT - moves the cursor left one character, if possible, changing the offset, if necessary.

    ->RIGHT - moves the cursor right one character, if possible, changing the offset, if necessary.

    ->HOME - moves the cursor to the beginning of the string, changing the offset, if necessary.

    ->END - moves the cursor to the position to the right of the last character in the string, changing the offset, if necessary.  If the last character is at
    the edge of the screen, moves the cursor to that character.

    ->INSERT - toggles Insert/Overstrike mode.  In Insert mode, the function inserts a printable character into the string at the current cursor position, moves
    the remainder of the string to the right to make room for the inserted character, and positions the cursor just to the right of the inserted character.
    The printable characters are the characters from space (' ') to tilde ('~') inclusive in the ASCII table.  In Overstrike mode, the function overwrites the
    character (if any) at the current cursor position with a printable character and advances the cursor just to the right of the new character.  If the cursor
    is past the end of the string, the function appends a printable character to the string as long as the string isn't full, regardless of the mode.

    ->DEL - discards the character at the current cursor position and moves all characters to the right of the cursor position one position to the left.

    ->BACKSPACE - discards the character to the left of the current cursor position, if possible, moves the characters at and to the right of the cursor position
    one position to the left, if possible, and positions the cursor one character to the left, if possible.

    The edit() function always displays blanks in any part of the field that is not occupied by the string.  UNDER NO CIRCUMSTANCES DOES THE FUNCTION CHANGE ANY
    POSITION ON THE SCREEN OUTSIDE THE FIELD.  For example, the function does not display status information (such as "INS" or "OVR") elsewhere on the screen,
    since such displays limit the programmer's ability to design their own screen layouts.
    */

    int edit(char *str, int row, int col, int fieldLength, int maxStrLength,
        bool* insertMode, int* strOffset, int* curPosition,
        bool InTextEditor, bool ReadOnly){
    
        bool _insertMode=true;
        int _tabsize=4;

        bool done = false;
        int keyTmp = 0;
        int ix = 0;
        int offSetTmp = 0;

        int curPosTmp = 0;
        if (strOffset == 0)
            strOffset = &offSetTmp;
        else {

            offSetTmp = *strOffset;
        }
        if (curPosition == 0)
            curPosition = &curPosTmp;
        else {
            curPosTmp = *curPosition;
        }
        char *strTmp = new char[strlen(str) + 1];
        strcpy(strTmp, str);
        while (!done){
            if (*strOffset > strlen(str)) *strOffset = strlen(str);
            if (*curPosition > fieldLength) *curPosition = fieldLength - 1;
            if (*curPosition > strlen(str)) *curPosition = strlen(str);
            // display UI
            display(str + *strOffset, row, col, fieldLength, *curPosition);
            // get the user input
            cio::console >> keyTmp;
            // Switch to user input
            switch (keyTmp){
                // Backspace keyboard functionality
            case BACKSPACE:
                if (!ReadOnly){
                    if (*strOffset + *curPosition > 0){
                        for (ix = *strOffset + *curPosition - 1; str[ix]; ix++){
                            str[ix] = str[ix + 1];
                        }
                        if (*curPosition > 0){
                            (*curPosition)--;
                        }
                        else if (*strOffset > 0){
                            (*strOffset)--;
                        }
                    }
                }
                break;
                // Dell keyboard functionality
            case DEL:
                for (ix = *strOffset + *curPosition; ix < (int)strlen(str); ix++)
                    str[ix] = str[ix + 1];
                break;
                // Insert keyboard functionality 
            case INSERT:
                *insertMode = !*insertMode;
                break;
                // Home keyboard functionality
            case HOME:
                *strOffset = *curPosition = 0;
                break;
                // End keyboard functionality
            case END:
                if (((int)strlen(str) - *strOffset) > fieldLength)
                    *curPosition = fieldLength - 1;
                else
                    *curPosition = strlen(str) - *strOffset;
                *strOffset = (strlen(str) - *curPosition);
                break;
                // Left arrow keyboard functionality 
            case LEFT:
                if (*curPosition > 0){
                    (*curPosition)--;
                }
                else if (*strOffset > 0){ // move the string to right
                    (*strOffset)--;
                }
                else{
                    //alarm();
                }
                break;
                // Right arrow keyboard functionality
            case RIGHT:
                if (*strOffset + *curPosition < ((int)strlen(str)) && (*curPosition < (fieldLength - 1))){
                    (*curPosition)++;
                }
                else if (*strOffset < ((int)strlen(str) - *curPosition)){ // move the string to right
                    (*strOffset)++;
                }
                else{
                    //alarm();
                }
                break;
                // Tab keyboard functionality
            case TAB:
                // Enter keyboard functionality 
            case ENTER:
                // Up arrow keyboard functionality
            case UP:
                // Down arrow keyboard functionality
            case DOWN:
                // PageUp keyboard functionality 
            case PGUP:
                // PageDown keyboard functionality
            case PGDN:
                // F1 keyboard functionality 
            case F(1):
                // F2 keyboard functionality
            case F(2):
                // F3 keyboard functionality
            case F(3):
                // F4 keyboard functionality
            case F(4):
                // F5 keyboard functionality
            case F(5):
                // F6 keyboard functionality
            case F(6):
                // F7 keyboard functionality
            case F(7):
                // F8 keyboard functionality
            case F(8):
                // F9 keyboard functionality
            case F(9):
                // F10 keyboard functionality
            case F(10):
                // F11 keyboard functionality
            case F(11):
                // F12 keyboard functionality
            case F(12):
                done = true;
                break;
                // Escape keyboard functionality
            case ESCAPE:
                if (!InTextEditor){
                    *strOffset = offSetTmp;
                    *curPosition = curPosTmp;
                    strcpy(str, strTmp);
                }
                done = true;
                break;
            default:
                if (keyTmp >= ' ' && keyTmp <= '~'){ // it is printable
                    if (!ReadOnly){
                        if (*insertMode){
                            if (strlen(str) != maxStrLength){
                                for (ix = strlen(str) + 1; ix>(*strOffset + *curPosition); ix--){
                                    str[ix] = str[ix - 1];
                                }
                                str[*strOffset + *curPosition] = keyTmp;
                                if (*curPosition == fieldLength - 1)
                                    (*strOffset)++;
                                else
                                    (*curPosition)++;
                            }
                        }
                        else{  // overstrike
                            if (*strOffset + *curPosition != maxStrLength){
                                if (str[*strOffset + *curPosition] == 0) str[*strOffset + *curPosition + 1] = 0;
                                str[*strOffset + *curPosition] = keyTmp;
                                if (*curPosition == fieldLength - 1)
                                    (*strOffset)++;
                                else
                                    (*curPosition)++;
                            }
                        }
                    }
                }
                break;
            }  // end switch(key)
            if (InTextEditor && offSetTmp != *strOffset)
                return 0;
            if (ReadOnly){
                strcpy(str, strTmp);
            }
        } // end of while(!done)
        delete[] strTmp;
        return keyTmp;

    }/********************************************** END OF EDIT FUNCTION **********************************************************/
