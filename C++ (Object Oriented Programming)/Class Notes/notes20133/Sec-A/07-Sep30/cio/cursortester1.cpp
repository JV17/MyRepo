#include "console.h"

using namespace cio;

int main(){
  bool done = false;
  Console mycon;
  int cols = mycon.getCols();
  int rows = mycon.getRows();
  int r = rows/2;
  int c = cols/2;
  int key = 0;
  while(!done){
    // display the interface
    mycon.setPos(r, c);
    // ger user response
    key = mycon.getKey();
    switch(key){
    case UP:
      r--;
      break;
    case DOWN:
      r++;
      break;
    case RIGHT:
      if(c < cols-1){
        c++;
      }
      else{
        mycon.alarm();
      }
      break;
    case LEFT:
      c--;
      break;
    case ESCAPE:
    case F(12):
      done = true;
      break;
    }
  
  
  }
  return 0;
}