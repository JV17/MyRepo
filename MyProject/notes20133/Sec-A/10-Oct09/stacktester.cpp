#include <iostream>
#include "stack.h"
using namespace oop344;
using namespace std;

int main(){
  Stack S;
  for(int val = 10; val <= 50; val+=10){
    S.push(val);
  }
  while(!S.isEmpty()){
    cout<<S.pop()<<endl;
  }
  return 0;
}


