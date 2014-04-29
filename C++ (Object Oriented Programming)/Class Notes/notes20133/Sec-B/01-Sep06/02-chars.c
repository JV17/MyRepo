#include <stdio.h>

int main(){
  char ch = 'A'; /* bur really it is an int */
  char a = 255;
  ch ++;
  a++;
  printf("%c\n", ch );
  printf("%d\n", a);
  return 0;
}