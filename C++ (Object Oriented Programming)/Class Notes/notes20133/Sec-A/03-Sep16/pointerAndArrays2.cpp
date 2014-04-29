#include <cstdio>
using namespace std;

int main(){
  int a[3][5] = {
    {10,20,30,40,50},
    {100,200,300,400,500},
    {1000,2000,3000,4000,5000}
  };
  int* p = (int*)a;
  for(int i=0;i<15;i++){
    printf("%d ", p[i]);
  }
  printf("\n");
  printf("%u \n", p);
  printf("%u \n", p+1);
  //p += 200;   can point anywhere in memory, hopefully it is ours!!!!
  //printf("%d \n", *p);
  printf("%u \n", a);
  printf("%u \n", a+1);
  printf("%u \n", a[0]);
  printf("%u \n", a[0]+1);

  return 0;
}