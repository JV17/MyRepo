#include <iostream>
using namespace std;

int& foo(int& i){
  return i;
}


int main(){
  int A;
  int& R = A;
  R = 5;
  cout<<A<<endl;
  foo(A) = 10;
  cout<<A<<endl;
  return 0;
}
