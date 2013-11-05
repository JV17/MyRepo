#include "console.h"
namespace cio{
  bool Console::_insertMode = true;
  void Console::display(const char* str, int row, int col, 
                int len, int curpos){
    int i = 0;
    setPos(row, col);
    if(len){ // max fieldlen cars
      for(;i<len && str[i];i++){
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
    if(curpos >=0){
      setPos(row, col + curpos);
    }
  }
    
  int  Console::edit(char *str, int row, int col, int fieldLength, int maxStrLength, 
      int* strOffset, int* curPosition,  
        bool InTextEditor, bool ReadOnly, bool& insertMode){
    bool done = false;
    int key = 0;
    int idx = 0;
    while(!done){
      // display UI
      display(str + (*strOffset), row, col, fieldLength, *curPosition);
      // get user response
      key = getKey();
      // act on it
      switch(key){
      case INSERT:
  /*      if(insertMode){
          insertMode = false;
        }
        else{
          insertMode = true;
        } */
     /*   insertMode = insertMode?false: true; */
        insertMode = !insertMode;
        break;
      case HOME:
        *strOffset = *curPosition = 0;
        break;
      case BACKSPACE:
        for(idx = *curPosition+*strOffset-1;idx >=0 && str[idx];idx++){
          str[idx] = str[idx+1];
        }
        if((*curPosition) > 0){
          (*curPosition)--;
        }
        else if((*strOffset) > 0){
          (*strOffset)--;
        }
        else{
          // beep?
        }
        break;
      case LEFT:
        if((*curPosition) > 0){
          (*curPosition)--;
        }
        else if((*strOffset) > 0){
          (*strOffset)--;
        }
        else{
          // beep?
        }
        break;
      case ENTER:
        done = true;
        break;
      case ESCAPE:
        done = true;
        break;
      default:
        if(key >= ' ' && key <= '~'){ // printable chars
          if(insertMode){

          } 
          else { // overstrike
            if(str[*strOffset+*curPosition] == 0){
              str[*strOffset+*curPosition+1] = 0;
            }
            str[*strOffset+*curPosition] = key;
            (*curPosition)++;
          }
        }
        break;
      }
    }
    return key;
  }



}