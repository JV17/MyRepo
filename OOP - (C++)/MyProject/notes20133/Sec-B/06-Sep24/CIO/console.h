#ifndef __FS_CONSOLE_H__
#define __FS_CONSOLE_H__

#include "bconsole.h"


namespace cio{

  class Console:public bio::BConsole{
    static bool _insertMode;
  public:
  void display(const char* str, int row, int col, int len = 0, int curPosition = -1);
  int  edit(char *str, int row, int col, int fieldLength, int maxStrLength, 
        int* strOffset=(int*)0, int* curPosition=(int*)0,  
         bool InTextEditor = false, bool ReadOnly = false, bool& insertMode=_insertMode );


  };
}


#endif
