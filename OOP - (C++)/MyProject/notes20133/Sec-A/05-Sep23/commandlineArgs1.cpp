#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[]){
  int i;
  if(argc != 2){
    printf("prnfile FILENAME<ENTER>\n");
    return -1;
  }
  FILE* fptr;
  fptr = fopen(argv[1], "rt");
  if(!fptr){   // if fptr is null
    printf("Could not open file %s\n", argv[1]);
    return -2;
  }
  /*
  if(strcmp(argv[0], "prnfile")){ // if not the same rename, this has and an may not work.
    char command[1024] = "ren ";
    strcat(command, argv[0]);
    strcat(command, " prnfile");
    system(command);
    return -3;
  }
  */
  char ch;
  while(fscanf(fptr, "%c", &ch) == 1){
    putchar(ch);
  }
  fclose(fptr);
  return 0;
}