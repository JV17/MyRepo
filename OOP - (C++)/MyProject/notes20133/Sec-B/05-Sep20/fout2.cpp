#include <stdio.h>
#include "fout.h"

Output& Output::print(int a){
  printf("%d", a);
  return *this;
}

Output& Output::print(const char* s){
  printf(s);
  return *this;
}