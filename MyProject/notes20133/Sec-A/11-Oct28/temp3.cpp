#include <iostream>
using namespace std;
template <class type>
type add(type x, type y){
  return x + y;
}

class Account{
  double _bal;
public:
  Account(double bal = 100){
    _bal = bal;
  }
  ostream& print(ostream& os)const{
    return os<<"Account balance is: "<<_bal;
  }
  Account operator+(const Account& A)const{
    return Account(_bal+A._bal);
  }
};

ostream& operator<<(ostream& os,const Account& A){
  return A.print(os);
}


int main(){
  Account A = 200;
  Account B(300);
  Account C;
  int a = 10;
  int b(20);
  int c ;
  double f = 1.234;
  double g = 2.345;
  double r;
  C = add(A, B);
  c = add(a, b);
  r = add(f, g);
  cout<<C<<endl;
  cout<<c<<endl;
  cout<<r<<endl;
  return 0;
}