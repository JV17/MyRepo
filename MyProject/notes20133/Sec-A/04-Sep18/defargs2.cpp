#include <iostream>
using namespace std;

void bar(int len = 60, char ch = '_'){
  int i;
  for(i=0;i<len;i++){
    cout<<ch;
  }
  cout<<endl;
}
int main(){
  bar(40, '=');
  bar(30);
  bar();
  return 0;
}