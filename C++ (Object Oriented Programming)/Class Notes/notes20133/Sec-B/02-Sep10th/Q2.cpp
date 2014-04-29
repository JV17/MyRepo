#include <string>
using namespace std;

void sswap(char* a, char* b){
  //char* v = new char[(strlen(a)>strlen(b)?strlen(a):strlen(b))+1];// test:ok project:bad
  char* v = new char[strlen(a)+1];
  strcpy(v, a);
  strcpy(a, b);
  strcpy(b, v);
  delete[] v;
}