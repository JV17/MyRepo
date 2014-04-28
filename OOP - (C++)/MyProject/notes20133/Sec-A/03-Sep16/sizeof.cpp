#include <cstdio>
using namespace std;
void print(int ar[][5],unsigned int size){
  unsigned int i;
  unsigned int j;
  printf("%u \n", sizeof(ar));

  for(i=0;i<size;i++){
    for(j=0;j<5;j++){

    }
  }
}
int main(){
  int a[3][5] = {
    {10,20,30,40,50},
    {100,200,300,400,500},
    {1000,2000,3000,4000,5000}
  };
  int* p = (int*)a;
  int b;
  printf("%u \n", sizeof(int));
  printf("%u \n", sizeof(b));
  printf("%u \n", sizeof(int*));
  printf("%u \n", sizeof(p));
  printf("%u \n", sizeof(a));


  return 0;
}