#include <iostream>
using namespace std;

int add(int x, int y){
  return x + y;
}
double  add(double x, double y){
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