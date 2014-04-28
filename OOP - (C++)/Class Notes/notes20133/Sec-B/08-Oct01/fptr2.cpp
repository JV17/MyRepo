#include <iostream>
using namespace std;

int add(int a, int b){
  return a + b;
}
int prnch(int ch, int n){
  while(n-- != 0){
  	cout<<char(ch);
  }
  cout<<endl;
  return n;
}
int main(){
  int x = 10;
  int y = 20;
  int z;
  int (*fptr)(int, int) = add;

  z = fptr(x, y);
  cout<<z<<endl;
  fptr= prnch;
  fptr('A', 10);
  return 0;
}