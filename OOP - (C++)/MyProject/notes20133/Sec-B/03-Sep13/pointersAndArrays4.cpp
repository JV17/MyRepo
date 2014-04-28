#include <cstdio>
using namespace std;


int main(){
  int a[3][4] = {{10, 20, 30, 40},
              {50, 60, 70, 80}, 
              {90, 100,110,120}};
  int b[4][4] = {{10, 20, 30, 40},
              {50, 60, 70, 80}, 
              {500, 600, 700, 800}, 
              {900, 1000,1100,1200}};
  int (*p)[4] = a;
  printf("%d\n", p[1][5]);
  printf("%d\n", p[1][3]);
  p = b;
  printf("%d\n", p[2][3]);
  printf("%d\n", p[2][5]);
  return 0;
}

