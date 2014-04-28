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
  prnBox();
  mycon.display("abcdefghijklmnopqrstuvwxyz", 11, 11, 20);
  mycon.pause();
  prnBox();
  mycon.display("abcdefgh", 11, 11, 20);
  mycon.pause();
  prnBox();
  mycon.display("abcdefghijklmnopqrstuvwxyz", 11, 11);
  mycon.pause();
  prnBox();
  mycon.display("abcdefgh", 11, 11, 20,3);
  mycon.pause();
  return 0;
}