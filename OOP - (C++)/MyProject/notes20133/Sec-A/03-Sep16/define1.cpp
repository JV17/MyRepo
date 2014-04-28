#include <iostream>
using namespace std;

#define sum a+b

int main(){
  int a = 10;
  int b = 20;
  cout<<sum*2<<endl;  // output is 50, NOT 60!!!!!
  return 0;
}