#include <iostream>
#include <cstdarg>
using namespace std;


double aver(int num, ...){
  va_list va;
  va_start(va, num);
  double sum = 0;
  double arg;
  int i;
  for(i=0;i<num;i++){
    arg = va_arg(va, double);
    sum += arg;
  }
  va_end(va);
  return sum/num;
}
int main(){
  cout<<aver(4, 1.2,2.3,3.4,4.5)<<endl;
  cout<<aver(4, 1.2,2.3,3.4,4.5,5.6,4.5)<<endl;
  cout<<aver(4, 1.2,2.3)<<endl;
  return 0;
}