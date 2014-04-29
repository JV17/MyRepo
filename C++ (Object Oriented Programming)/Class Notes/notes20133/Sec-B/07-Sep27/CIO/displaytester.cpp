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
  char str[81] = "abcdefghijklmnopqrstuvwxyz";
  str[10] = 0;
  prnBox();
  mycon.display(str, 11, 11, 20);
  mycon.pause();
  prnBox();
  mycon.display(str, 11, 11, 20, 4);
  mycon.pause();
/*  prnBox();
  mycon.display(str, 11, 11);
  mycon.pause();
  str[10] = 'X';
  prnBox();
  mycon.display(str, 11, 11);
  mycon.pause();
*/  return 0;
}