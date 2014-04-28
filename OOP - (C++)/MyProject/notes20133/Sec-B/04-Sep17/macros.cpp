#include <iostream>
using namespace std;
//#define debug
#define sum(a,b) ((a)+(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define create(b, t) t b
#define makeNset(x, t, v) t x = v
int fsum(int a, int b){return a+b;}
int main(){
  int a = 10;
  makeNset(b, int, 20); // int b = 20;
  create(c, int);
  double x = 1.234;
  double y = 3.456;
  double z;
  c = sum(a,b) * 2;
  z = sum(x,y) * 2;
  cout<<z<<endl;
  cout<<c<<endl;
  z = sum(x+a,y*b) * 2;
  cout<<z<<endl;
  z = max(x,y);
  cout<<z<<endl;

#ifdef debug
  cout<<"what is the value if c? "<<c<<endl;
#endif
  return 0;
}