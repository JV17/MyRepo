#include "console.h"

namespace cio{
  bool Console::_insertMode = true;
  void Console::display(const char* str, int row, int col, int len, int curPosition){
    int i=0;
    setPos(row, col);
    if(len){ //limited number of chars
      for(;i<len&&str[i];i++){
        putChar(str[i]);
      }
      for(;i<len;i++){
        putChar(' ');
      }
    }
    else{  // print the whole thing
      for(;str[i];i++){
        putChar(str[i]);
      }    
    }
    if(curPosition >= 0){
      setPos(row, col + curPosition);
    }

  }

  int  Console::edit(char *str, int row, int col, int fieldLength, int maxStrLength, 
        int* strOffset, int* curPosition,  
         bool InTextEditor, bool ReadOnly, bool& insertMode){
    bool done = false;
    int key = 0;
    int ix = 0;
    while(!done){
      // display UI
      display(str + *strOffset,row, col, fieldLength, *curPosition);
      // get the user input
      key = getKey();
      // Switch to user input
      switch(key){
      case BACKSPACE:
        if(*strOffset+*curPosition > 0){
          for(ix = *strOffset + *curPosition -1;str[ix];ix++){
            str[ix] = str[ix+1];
          }
          if(*curPosition > 0){
            (*curPosition)--;
          }
          else if(*strOffset > 0){
            (*strOffset)--;
          }
        }
        break;
      case INSERT:
        insertMode  = !insertMode;
        break;
      case HOME:
        *strOffset = *curPosition = 0;
        break;
      case LEFT:
        if(*curPosition > 0){
          (*curPosition)--;
        }
        else if(*strOffset > 0){ // move the string to right
          (*strOffset)--;
        }
        else{
          // do I beep?
        }
      break;       
      case ENTER:
        done = true;
        break;
      case ESCAPE:
        done = true;
        break;
      default:
        if(key >= ' ' && key <= '~'){ // it is printable
          if(insertMode){
          }
          else{  // overstrike
            str[*strOffset + *curPosition] = key;
            (*curPosition)++;
          }
        }
        break;      
      }  // end switch(key)
    } // end of while(!done)
    return 0;
  }


}