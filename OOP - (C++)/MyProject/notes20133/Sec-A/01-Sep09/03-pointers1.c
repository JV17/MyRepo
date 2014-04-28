#include <stdio.h>
int main(){
  int a = 20;
  int j;
  int*  p = &a;
  j = *p;
  printf("%u\n", p);
  printf("%u\n", &a);
  printf("%d\n", a);
  a++;
  printf("%d\n", *p);
  printf("%d\n", j);
  p++;
  printf("%u\n", p);
  printf("%u\n", &a);
  printf("%d\n", *p);
  return 0;
}