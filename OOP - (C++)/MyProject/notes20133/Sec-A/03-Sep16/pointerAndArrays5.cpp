#include <cstdio>
using namespace std;

int main(){
  int a[3][5] = {
    {10,20,30,40,50},
    {100,200,300,400,500},
    {1000,2000,3000,4000,5000}
  };
  unsigned int i;
  unsigned int j;
  int  (*ar)[5] = a;
  for(i=0;i<3;i++){
    for(j=0;j<5;j++){
      printf("%u ", ar[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  return 0;
}