#include <cstdio>
#include <cstring>
using namespace std;


bool validYear(int year, char* errmes){
  bool res = false;
  if(year >= 2010 && year <= 2020){
    res  = true;
  }
  else{
    strcpy(errmes, "Invalid year (2010<=year<=2020)");
  }
  return res;
}

bool validMonth(int mon, char* errmes){
  bool res = false;
  if(mon > 0 && mon <=12){
    res  = true;
  }
  else{
    strcpy(errmes, "Invalid month (1<=month<=12)");
  }
  return res;
}

bool validCCV(int ccv, char* errmes){
  bool res = false;
  if(ccv >= 100 && ccv<= 999){
    res  = true;
  }
  else{
    strcpy(errmes, "Invalid CCV (Three digit number)");
  }
  return res;
}


int getInt(const char* prompt, bool  (*valid)(int,char*) = 0 ){
  int num;
  char newline = 0;
  bool done;
  char errmes[71];
  fflush(stdin);
  printf(prompt);
  do{
    done = true;
    scanf("%d%c", &num, &newline);
    fflush(stdin);
    if(newline != '\n'){
      printf("Invalid integer, try again: ");
      done = false;
    }
    if(valid && done && !valid(num,errmes)){
      printf(errmes);
      done = false;
    }
  }while(!done);
  return num;
}

int main(){
  int year = 0;
  int mon = 0;
  int ccv= 0;
  int num;
  num = getInt("gimmi some number: ");
  printf("Please enter expiry date for your creditcard;\n");
  year = getInt("year: ",validYear);
  mon = getInt("month: ",validMonth);
  ccv = getInt("please enter security code: ", validCCV);
  printf(" your card expiry is %d/%d and your ccv is: %d\n", mon, year, ccv);
  return 0;
}

