#include <iostream>
using namespace std;

void addone(int& R){
  R++;
}

int main(){
  int a =10;
  int b = 23;
  int& r=a;
  addone(a);
  cout<<a<<endl;
  addone(r);
  cout<<a<<endl;
  addone(b);
  cout<<b<<endl;
  return 0;
}