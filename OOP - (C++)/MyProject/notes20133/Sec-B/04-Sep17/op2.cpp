#include <iostream>
using namespace std;

int main(){
  int a[10]={1,3,4,-5,4,-7,3,0,-1,9};
  int i;
  int num = 0;
  for(i=0;i<10;i++){
    num += (a[i] < 0);
  }
  cout<<num<<endl;
  return 0;
}