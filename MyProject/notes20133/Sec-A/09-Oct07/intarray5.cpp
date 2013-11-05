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
      int* temp = new int[index+1<1024?index+1:index+1+1024];
      for(int i=0;i<_size;i++){
        temp[i] = _data[i];
      }
      delete[] _data;
      _data = temp;
      _size = index + 1;
    }
    return _data[index];
  }
  unsigned int size(){
    return _size;
  }
  virtual ~IntArray(){
    delete[] _data;
  }
};
int main(){
  IntArray I(5);
  int i;
  for(i=0;i<7;i++){
    //I.operator[](i) = i*10;
    I[i] = i*10;
  }
  for(i=0;i<I.size();i++){
    cout<<I[i]<<", ";
  }
  cout<<endl;
  return 0;
}