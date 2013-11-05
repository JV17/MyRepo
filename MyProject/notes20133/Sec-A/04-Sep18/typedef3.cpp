#include <stdio.h>

typedef
  struct {
  char first[41];
  char last[51];
}
  Name;


typedef struct{
  char mode[40];
  char name[50];
  int year;
}  Car;

int main(){
  Name N;
  strcpy(N.first,"Fardad"); 
  return 0;
}