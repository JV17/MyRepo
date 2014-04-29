#include <iostream>
using namespace std;
//#define debug
//#define sum a+b
int main(){
  int a = 10;
  int b = 20;
  int c;
#ifdef sum
  c = sum * 2;
  cout<<c<<endl;
#endif
#ifndef sum
  cout<<"sum is not defined"<<endl;
#endif
#ifdef debug
  cout<<"what is the value if c? "<<c<<endl;
#endif
  return 0;
}