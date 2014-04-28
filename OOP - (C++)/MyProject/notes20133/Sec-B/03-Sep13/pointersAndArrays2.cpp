#include <cstdio>
using namespace std;

int main(){
  int a[3][4] = {{10, 20, 30, 40},
              {50, 60, 70, 80}, 
              {90, 100,110,120}};
  int* p = (int*)a;
  for(int i=0;i<12;i++){
     printf("%d ", p[i]);
  }
  putchar('\n');
  printf("a: %u\n", a);
  printf("a+1: %u\n", a+1);
  printf("a[0]: %u\n", a[0]);
  printf("a[0]+1: %u\n", a[0]+1);
  return 0;
}

