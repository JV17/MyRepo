#include <iostream>
using namespace std;



void bar(int len, char ch){
  int i;
  for(i=0;i<len;i++){
    cout<<ch;
  }
  cout<<endl;
}

void bar(int len){
  bar(len, '_');
}

void bar(){
  bar(60);
}

int main(){
  bar(40, '=');
  bar(30);
  bar();
  return 0;
}