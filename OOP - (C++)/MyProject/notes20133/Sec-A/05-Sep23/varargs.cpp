#include <iostream>
#include <cstdarg>
using namespace std;

double aver(int cnt, ...){
  va_list vargs;
  double sum=0;
  double arg;
  int i;
  va_start(vargs, cnt);
  for(i=0;i<cnt;i++){
    arg = va_arg(vargs, double);
    sum+=arg;
  }
  va_end(vargs);
  return sum/cnt;
}


int main(){
  cout<<aver(4, 1.0,2.0,3.0,4.0)<<endl;
  cout<<aver(4, 1.0,2.0,3.0,4.0,5.0,6.0)<<endl;
  cout<<aver(20, 1.0,2.0,3.0)<<endl;
  return 0;
}