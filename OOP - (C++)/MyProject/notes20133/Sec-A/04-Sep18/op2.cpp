#include <iostream>
using namespace std;

int main(){
  int a[10]={1,3,4,-5,4,-7,3,0,-1,9};
  int i;
  int neg = 0;
  int pos = 0;
  int noz = 0;
  for(i=0;i<10;i++){
    neg += (a[i]<0);
    pos += (a[i]>0);
    noz += (a[i] !=0);
    noz += !!a[i];
  }
  cout<<neg<<endl;
  cout<<pos<<endl;
  cout<<noz<<endl;
  return 0;
}