
#include <iostream>
using namespace std;

int main(){
  int a = 10;
  int b = 20;
  int c;
  int d;
  d = c = a + b;
  cout<<c<<endl;
  cout<<d<<endl;
  c = a > b;
  cout<<c<<endl;
  d = a < b;
  cout<<d<<endl;
  return 0;
}