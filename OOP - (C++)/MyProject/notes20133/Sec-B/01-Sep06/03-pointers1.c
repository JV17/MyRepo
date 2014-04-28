#include <stdio.h>

int main(){
  int i = 3;
  int* p;
  double* dp = (double*) 16;
  int j;
  p = &i;
  j = *p;
  printf("sizeof int:%u\n", sizeof(int));
  printf("sizeof double:%u\n", sizeof(double));
  printf("%u\n", dp);
  printf("%u\n", p);
  printf("%d\n", j);
  j++;
  p++;
  dp++;
  printf("%u\n", dp);
  printf("%u\n", p);
  printf("%d\n", j);
  return 0;
}