#include <stdio.h>
#include "fout.h"

void Output::print(int a){
  printf("%d", a);
}

void Output::print(const char* s){
  printf(s);
}