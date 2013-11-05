#include <iostream>
using namespace std;

#define sum(a,b) ((a)+(b))
#define make(v, t) t v
#define makeNset(v, t, val) t v = val
#define max(a, b) ((a)>(b)?(a):(b))

int fsum(int a, int b){return a+b;}

class Cont{
  int _a;
public:
  Cont(int a=0){
    _a = a;
  }
  int get()const{
    return _a;
  }
  Cont operator+(const Cont& C){
    return Cont(_a+C.get());
  }
};



ostream& operator<<(ostream& os, const Cont& C){
  return os<<C.get();
}

int main(){
  int i = 10;
  int j = 20;
  double x = 10.2;
  double y = 20.4;
  make(z, double);
  makeNset(A, Cont, 10);
  Cont B = 20;
  Cont C;
  cout<<sum(i,j)*2<<endl;  // output is 50, NOT 60!!!!!
  z = sum(x,y);
  cout<<z<<endl;
  C = sum(A, B);
  int k = sum(i*z, z+j*y);
  cout<<C<<endl;
  return 0;
}