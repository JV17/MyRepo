#include <iostream>
#include "stacktemp.h"
using namespace std;
using namespace oop344;
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
  Stack<Account> AS;
  Stack<int> S;
  int val;
  for(val = 10; val <= 50; val+=10){
    S.push(val);
  }
  while(!S.isEmpty()){
    cout<<S.pop()<<endl;
  }
  for(val = 10; val <= 50; val+=10){
    AS.push(val);
 //   AS.push(Account(val)); compiler does this for you
  }
  while(!AS.isEmpty()){
    cout<<AS.pop()<<endl;
  }

  return 0;
}