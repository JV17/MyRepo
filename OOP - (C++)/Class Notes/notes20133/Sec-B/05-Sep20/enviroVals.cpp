#include <iostream>
using namespace std;

int main(int argc, char* argv[], char* env[]){
  int i;
  for(i=0;env[i];i++){
    cout<<"["<<i<<"]: "<<env[i]<<endl;
  }
  return 0;
}