#include <iostream>
#include "StrStack.h"
using namespace std;
using namespace oop344;
// note that this is only a test and the length of the strings 
// pushed into the stack are limited only by the size of the memory available. 
int main(){
  char str[81];
  StrStack S;
  int i;
  S.push("Hello");
  S.push("this");
  S.push("is");
  S.push("a");
  S.push("test!");
  for(i=0;S[i];i++); // finding the last index 
  for(i--;i>=0;i--){   // printing in reverse order
    cout<<S[i]<<" ";
  }
  cout<<endl;
  while(!S.isEmpty()){
    S.pop(str);
    cout<<str<<endl;
  }
  return 0;
}
