#include "console.h"

using namespace cio;

int main(){
  Console C;
  bool done = false;
  int rows = C.getRows();
  int cols = C.getCols();
  int r = rows/2;
  int c = cols/2;
  int ch = 0;
  while(!done){
    C.setPos(r, c);
    ch = C.getKey();
    switch (ch){
    case UP:
      r--;
      break;
    case DOWN:
      r++;
      break;
    case LEFT:
      c--;
      break;
    case RIGHT:
      if(c < (cols-1)){
        c++;
      }
      else{
        C.alarm();
      }
      break;
    case ESCAPE:
    case F(10):
      done = true;
      break;
    }
  }
  return 0;
}