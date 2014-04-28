#include <cstdio>
using namespace std;
int add(int , int );
int prnch(int , int );
int mul(int , int);
int main(){
  int (*fptr[3])(int, int) = {add, mul, prnch};
  int x = 10;
  int y = 20;
  int z=0;
  int i;
  for(i=0;i<3;i++){
    z += fptr[i](x, y);
  }
  printf("z: %d\n", z);
  return 0;
}

int add(int a, int b){
  return printf("sum: %d\n", a+b);
}
int mul(int a, int b){
  return printf("mul: %d\n", a*b);
}
int prnch(int m, int n){
  while(n--){
    putchar('-');
  }
  putchar('\n');
  while(m--){
    putchar('-');
  }
  putchar('\n');
  return m - n;
}