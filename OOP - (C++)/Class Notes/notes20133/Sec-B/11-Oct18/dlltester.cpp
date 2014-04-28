#include <iostream>
#include "dlinkedlist.h"
using namespace oop344;
using namespace std;
int main(){
  DLinkedlist D;
  for(int i=10;i<=100;i+=10){
    D.add(i);
  }
  D.goHead();
  do{
    cout<<D.visit()<<", ";
  }while(D.goNext());
  return 0;
}