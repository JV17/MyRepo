#include <stdio.h>
#include "fout.h"
Output fout;
Output& Output::operator<<(int a){
  printf("%d", a);
  return *this;
}

Output& Output::operator<<(const char* s){
  printf(s);
  return *this;
}