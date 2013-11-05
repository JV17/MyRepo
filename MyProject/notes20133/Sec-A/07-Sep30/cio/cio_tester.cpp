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
  int key;
  int curpos = 5;
  int offset = 10;
  char str[81] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  str[20] = 0;
  prnBox();
  mycon.edit(str, 11, 11, 20, 80, &offset, &curpos);
  mycon.display(str, 15, 0);
  mycon.pause();
  return 0;
}