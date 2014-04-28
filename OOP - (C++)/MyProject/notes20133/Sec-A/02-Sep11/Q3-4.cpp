#include <iostream>
using namespace std;

class Container{
  //unsigned int c;
  double _c;
public:
  Container(double c){
    // this->c = c; buggy
    _c = c;
  }
  Container(){
    _c = 10.0;
  }
  void set(double c){
    _c = c;
  }
  double get()const{
    return _c;
  }
  Container operator+(const Container& Ro)const{
    return Container(this->_c+Ro._c);
  }
};

ostream& operator<<(ostream& os,const Container& C){
  return os<<C.get();
}

class Box:public Container{
  double _w;
  double _h;
  double _l;
public:
  //Box(double w, double h, double l):Container(w*h*l){
  //};
  Box(double w, double h, double l){
    set(w*h*l);
    _w = w;
    _h = h;
    _l = l;
  };
  Box():Container(1000){
    _w = _h = _l = 10;
  };
};
