#include <cstdio>
using namespace std;

//#define Debug


void print(int ar[][5],unsigned int size){
  unsigned int i;
  unsigned int j;
  for(i=0;i<size;i++){
    for(j=0;j<5;j++){
#ifdef Debug
      printf("%u: ", ar[i]);
#endif
      printf("%d ", ar[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}
int main(){
  int a[3][5] = {
    {10,20,30,40,50},
    {100,200,300,400,500},
    {1000,2000,3000,4000,5000}
  };
  int b[4][5] = {
    {10,20,30,40,50},
    {100,200,300,400,500},
    {1000,2000,3000,4000,5000},
    {10000,20000,30000,40000,50000}
  };
  print(a, 3);
  print(b, 4);
  return 0;
}