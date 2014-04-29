#include <iostream>
using namespace std;
int& number(){
  static int a = 0;
  return a;
}
int& addone(int& x){
  x++;
  return x;
}
int main(){
  int i = 10;
  cout<<number()<<endl;
  number()++;
  cout<<number()<<endl;
  addone(i)++;
  cout<<i<<endl;
  addone(number())+=2;  // just a mind thingy....
  cout<<number()<<endl;
  return 0;
}