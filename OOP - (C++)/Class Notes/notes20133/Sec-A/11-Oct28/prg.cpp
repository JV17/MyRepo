#include <iostream>
using namespace std;

template <class T>
class Container{
  T _data;
  bool garbage;
public:
  Container(){
    garbage = true;
  }
  Container(T data);
  bool isGarbage()const{
    return garbage;
  }
  ostream& print(ostream& os)const{
    if(isGarbage()){
      os<<"Garbage";
    }
    else{
      os<<_data;
    }
    return os;
  }
  Container<T> operator+(const Container<T>& C){
    return Container<T>(C._data+_data); 
  }
  virtual ~Container(){
  }
};

template <class T>
Container<T>::Container(T data){
  _data = data;
  garbage = false;
}

template <class T>
ostream& operator<<(ostream& os, const Container<T>& C){
  return C.print(os);
}

int main(){

  Container<int> A;
  Container<int> B = 200;
  Container<int> C = 100;

  Container<double> X;
  Container<double> Y = 200.0;
  Container<double> Z = 100.0;
  A = B + C;
  X = Y + Z;
  cout<<A<<endl;
  cout<<X<<endl;
  return 0;
}