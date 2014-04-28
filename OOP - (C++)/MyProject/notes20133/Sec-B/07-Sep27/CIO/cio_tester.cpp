#include "console.h"

using namespace cio;
Console mycon;


void prnBox(){
  int i;
  mycon.setPos(10, 10);
  for(i=0;i<22;mycon.putChar('@'), i++);
  mycon.setPos(11, 10);
  for(i=0;i<22;mycon.putChar('@'), i++);
  mycon.setPos(12, 10);
  for(i=0;i<22;mycon.putChar('@'), i++);
}
int main(){
  char str[81] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJLKMNOPQRSTUVWXYZ";
  str[20] = 0;
  int key = 0;
  int offset = 4;
  int curpose = 3;
  prnBox();
  key = mycon.edit(str, 11, 11, 20, 80, &offset, &curpose);
  mycon.display(str, 15, 0);
  mycon.pause();
  return 0;
}