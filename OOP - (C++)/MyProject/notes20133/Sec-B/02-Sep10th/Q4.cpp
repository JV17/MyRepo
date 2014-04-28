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


class Box:public Container{
  int _w;
  int _h;
  int _l;
public:
  Box(){
    _w = _h = _l = 10;
    set(1000);
  }
  Box(int w, int h , int l){
    _w = w;
    _h = h;
    _l = l;
    set(w * h * l);
  }

};