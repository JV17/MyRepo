#include <iostream>
using namespace std;

class Container{
  //int c; // could be buggy
  int _c;
public:
  Container(int c){
    // this->c =c ;   // could be buggy
    _c = c;
  }
  Container(){
    _c = 10;
  }
  void set(int c){
    _c = c;
  }
  int get()const{
    return _c;
  }
  Container operator+(const Container& Ro)const{
 /*   Container C(this->get()+Ro.get());
    return C;*/
    return Container(this->get()+Ro.get());
  }
 // bad: friend ostream& operator<<(ostream& os, Container& C);
};

ostream& operator<<(ostream& os,const Container& C){
// bad:  return os<<C._c;
  return os<<C.get();
}

int main(){
  Container C(1000);
  cout<<"Capacity: "<<C<<endl;
}