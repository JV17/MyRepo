#include <iostream>
#include "stack.h"
using namespace std;
using namespace oop344;


int main(){
  Stack S;
  int val;
  for(val = 10; val <= 50; val+=10){
    S.push(val);
  }
  while(!S.isEmpty()){
    cout<<S.pop()<<endl;
  }
  return 0;
}