#include <cstdio>
using namespace std;

bool validYear(int year){
  bool res = false;
  if(year >= 2010 && year <= 2020){
    res  = true;
  }
  return res;
}

bool validMonth(int mon){
  return mon > 0 && mon <=12;
}

bool validCCV(int ccv){
  return ccv >= 100 && ccv <= 999;
}
int getInt( bool (*valid)(int) ){
  int num = 0;
  char newline = 0;
  bool done;
  fflush(stdin);
  do{
    done = true;
    scanf("%d%c", &num, &newline);
    fflush(stdin);
    if(newline != '\n'){
      printf("Invalid integer, try again:");
      done = false;
    }
    if( done && !valid(num)){
      printf("%d is not acceptable, try again:", num);
      done = false;
    }
  }while(!done);
  return num;
}
int main(){
  int year = 0, mon = 0, ccv= 0;
  printf("Please enter expiry date for your creditcard;\n");
  printf("year: ");
  year = getInt(validYear);
  printf("month: ");
  mon = getInt(validMonth);
  printf("please enter security code: ");
  ccv = getInt(validCCV);
  printf(" your card expiry is %d/%d and your ccv is: %d\n", mon, year, ccv);
  return 0;
}