#include "console.h"

using namespace cio;
Console mycon;
int main(){
  int cols = mycon.getCols();
  int rows = mycon.getRows();
  mycon.setPos(rows/2, cols/2);
  mycon.pause();
  return 0;
}