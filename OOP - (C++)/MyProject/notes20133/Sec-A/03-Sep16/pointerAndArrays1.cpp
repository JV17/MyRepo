#include <stdio.h>
int main(){
  int a[5] = {10,20,30,40,50};
  int* p = a;
  printf("%d\n", *a);
  printf("%d\n", p[3]);
  p++;
  printf("%d\n", p[3]);

  printf("%d\n", *a+2);
  printf("%d\n", *(a+2));
  printf("%d\n", a[2]);
  printf("%d\n", *(a+0));
  printf("%d\n", a[0]);


  return 0;
}