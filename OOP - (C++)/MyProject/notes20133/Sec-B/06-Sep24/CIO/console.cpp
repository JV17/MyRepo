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
    while(!done){
      // display UI
      // Switch to user input
    }
    return 0;
  }


}