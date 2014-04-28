#include <iostream>
using namespace std;

class IntArray{
  int* _data;
  unsigned int _size;
public:
  IntArray(unsigned int size){
    _data = new int[_size = size];
  }
  int& operator[](unsigned int index){
    if(index >= _size){
      size(index<1024?index+1:index + 1024);
    }
    return _data[index];
  }
  unsigned int size(){
    return _size;
  }
  void size(unsigned int newsize){
      int* temp = new int[newsize];
      for(int i=0;i<_size && i<newsize;i++){
        temp[i] = _data[i];
      }
      delete[] _data;
      _data = temp;
      _size = newsize;
  }
  virtual ~IntArray(){
    delete[] _data;
  }
};

class IntArrArr{
  IntArray** _data;
  unsigned int _size;
  unsigned int _width;
public:
  IntArrArr(unsigned int size, unsigned int width){
    _data = new IntArray*[_size = size];
    for(int i =0;i<_size;i++){
      _data[i] = (IntArray*)0;
    }
    _width = width;
  }
  unsigned int Size()const{
    return _size;
  }
  IntArray& operator[](unsigned int index){
    if(_data[index%_size] == 0){
      _data[index%_size] = new IntArray(_width);
    }
    return *_data[index%_size];
  }
  virtual ~IntArrArr(){
    for(int i=0;i<_size;i++){
      if(_data[i]){
        delete _data[i];
      }
    }
    delete[] _data;
  }
};

int main(){
  IntArrArr I(5,4);
  int i;
  int j;
  for(i=0;i<5;i++){
    for(j = 0;j<4;j++){
      I[i][j] = (i+1)*(j+1);
    }
  }
  for(i=0;i<5;i++){
    for(j = 0;j<4;j++){
      cout<<I[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}