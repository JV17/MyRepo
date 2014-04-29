#include <cstdio>
using namespace std;
int getInt(){
  int num = 0;
  char newline = 0;
  fflush(stdin);
  do{
    scanf("%d%c", &num, &newline);
    fflush(stdin);
  }while((newline != '\n') && printf("Invalid number, try again:"));
  return num;
}

int main(){
  int year = 0, mon = 0, ccv= 0;
  printf("Please enter expiry date for your creditcard;\n");
  printf("year: ");
  do{
    year = getInt();
  }
  while((year > 2020 || year < 2010) && printf("invalid (2020 < year < 2010) try again:"));
  printf("month: ");
  do{
    mon = getInt();
  }
  while((mon > 12 || mon < 0) && printf("invalid month, try again:"));
  printf("please enter security code: ");
  do{
    ccv = getInt();
  }
  while((ccv > 999 || ccv < 100) && printf("invalid security cod, try again:"));

  printf(" your card expiry is %d/%d and your ccv is: %d\n", mon, year, ccv);
  return 0;
}