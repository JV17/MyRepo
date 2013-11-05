#include <cstdio>
using namespace std;

void print(int ar[][4], unsigned int size){
//  for(unsigned int i =0;i<size;i++){
 //   for(unsigned int j =0; j<4;j++){
  unsigned int i;
  unsigned int j;
  for(i =0;i<size;i++){
    for(j =0; j<4;j++){
      printf("%d ", ar[i][j]);
    }
    putchar('\n');
  }
  putchar('\n');
}

int main(){
  int a[3][4] = {{10, 20, 30, 40},
              {50, 60, 70, 80}, 
              {90, 100,110,120}};
  int b[4][4] = {{10, 20, 30, 40},
              {50, 60, 70, 80}, 
              {500, 600, 700, 800}, 
              {90, 100,110,120}};
  int* p = (int*)a;
  print(a, 3);
  print(b, 4);
  return 0;
}

