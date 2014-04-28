#include <iostream>
using namespace std;

const char* digit(int i){
  static char digits[10][10]={
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
  };
  return digits[i%10];
}

int addone(){
  static int a = 0;
  ++a;
  return a;
}

int main(){
  int i;
  for(i=0;i<100;i+=5){
    cout<<addone()<<endl;
  }
  for(i=0;i<10;i++){
    cout<<digit(i)<<endl;
  }
  return 0;
}