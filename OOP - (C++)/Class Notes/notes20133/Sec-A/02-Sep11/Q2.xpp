#include <string>
using namespace std;

void strswap(char* a, char* b){
  //char* x = new char[(strlen(a)>strlen(b)?strlen(a):strlen(b))+1 ];
  char* x = new char[strlen(a)+1];
  strcpy(x, a);
  strcpy(a, b);
  strcpy(b, x);
  delete[] x;
}
