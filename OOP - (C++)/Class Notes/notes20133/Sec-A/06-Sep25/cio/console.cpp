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
    while(!done){
      // display UI
      // get user response
      // act on it
    }
    return 0;
  }



}