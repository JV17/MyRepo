#include <iostream>
#include <cstdarg>
// A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
using namespace std;
#define V2
#define mul(a, b) (a*b)
#define CrtSet(v, t, c)  t v = c
int a[3][5] = {{10, 20, 30, 40, 50},
               {60, 70, 80, 90, 100}, 
               {110, 120, 130, 140, 150}};
void w1(int n, char* args[]){
  cout<<"W1:"<<endl
      <<n<<endl
      <<args[1]<<endl
      <<a[args[1][0]-'0'][args[1][1]-'0']<<endl;
}
void w2(){
  int* p = a[0]+2;
  cout<<"W2:"<<endl
      <<p[0]<<endl
      <<*(p+2)<<endl
      <<p[10]<<endl;
}
void w3(){
  CrtSet(x, int, 4);
  CrtSet(y, int, 5);
  CrtSet(z, int ,6);
  cout<<"W3:"<<endl;
#ifdef V1
  x = mul(x+2, y);
#endif
#ifdef V2
  x = mul(x, y+2);
#endif
  cout<<x<<endl;
}
void w4(void* p){
  int (*ar)[4] = (int(*)[4])p;
  cout<<"W4:"<<endl<<ar[2][2]<<endl;
}
int w5(int a, int b = 10, int c = 20){
  cout<<"W5:"<<endl;
  return a+b+c;
}
int& w6f(){
  static int x = 4;
  x++;
  return x;
}
void w6(){
  cout<<"w6:"<<endl;
  for(int i=0;i<5;i++){
    cout<<w6f()++<<" ";
  }
  cout<<endl;
}
void w7(const char* s, ...){
  va_list vl;
  va_start(vl, s);
  int a;
  int i=0;
  cout<<"w7:"<<endl;
  while(a = va_arg(vl, int)){
    cout<<char(s[i++]+a);
  }
  cout<<"!"<<endl;
  va_end(vl);
}
int main(int argc, char* argv[]){
  w1(argc, argv);   // 3 marks
  w2();   // 3 marks
  w3();   // 2 marks
  w4(a);  // 1 mark
  cout<<w5(30, 40)<<endl; // 1 mark
  w6(); // 2 marks
  w7("Walking",-17,8,2,-6,0); // 3 marks
  return 0;
}

/* output:
W1:  3 marks
3
12
80
W2:  3 marks
30
50
130
W3:  2 marks
22
W4:  1 mark
110
W5:  1 mark
90
w6:  2 marks
5 7 9 11 13
w7:  3 marks;
Fine!
*/