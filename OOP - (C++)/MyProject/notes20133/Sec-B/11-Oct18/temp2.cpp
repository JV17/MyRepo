#include <iostream>
using namespace std;
template <class heehaw>
heehaw add(heehaw x, heehaw y){
  return x + y;
}

int main(){
  int a = 10;
  int b = 20;
  int c ;
  double f = 1.234;
  double g = 2.345;
  double r;
  c = add(a, b);
  r = add(f, g);
  cout<<c<<endl;
  cout<<r<<endl;
  return 0;
}