#include <cstdio>
using namespace std;
void memDump(void* p, unsigned int size){
  unsigned int i;
  unsigned char* cp = (unsigned char*)p;
  for(i=0;i<size;i++){
    printf("%X ", cp[i]);
    if((i+1)%8 == 0){
      putchar('\n');
    }
  }
  putchar('\n');
}

int main(){
  double d = 1234567.890877;
  memDump(&d, sizeof(double));
  return 0;
}