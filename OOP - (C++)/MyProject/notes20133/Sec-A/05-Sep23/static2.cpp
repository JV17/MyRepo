#include <iostream>

using namespace std;
int foo(){
  static int a = 0;
  return ++a;
}



int main(){
  int i;
  for(i=0;i<20;i++){
    cout<<foo()<<endl;
  }
  return 0;
}