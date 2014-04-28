#include <iostream>
using namespace std;

class IntArray{
  int* _data;
  unsigned int _size;
public:
  IntArray(unsigned int size){
    _data = new int[_size = size];
  }
  int element(unsigned int index){
    return _data[index%_size];
  }
  void setElem(unsigned int index, int val){
    _data[index%_size] = val;
  }
  virtual ~IntArray(){
    delete[] _data;
  }
};
int main(){
  IntArray I(5);
  int i;
  for(i=0;i<7;i++){
    I.setElem(i, i*10);
  }
  for(i=0;i<5;i++){
    cout<<I.element(i)<<", ";
  }
  cout<<endl;
  return 0;
}