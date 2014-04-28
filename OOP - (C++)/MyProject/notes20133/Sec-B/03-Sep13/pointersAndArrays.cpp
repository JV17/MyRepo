#include <cstdio>
using namespace std;

int main(){
  int a[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  int* p = a;
  printf("%d\n", *a);
  printf("%d\n", *a+1);
  printf("%d\n", *(a+1));
  printf("%d\n", *(a+0));
  printf("%d\n", a[0]);
  printf("%d\n", p[5]);
  return 0;
}

