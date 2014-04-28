// header file

#define LX 1
#define VC 2
#define IOS 3
#define BC 4


#define PLATFORM LX
void gotoxy(int col, int row);

// source code (c or cpp)

#include "headerfile"

#if PLATFORM == LX
void gotoxy(int x, int y){
  Linux way;
}
#elif PLATFORM == VC

void gotoxy(int x, int y){
  Visual C way;
}
#elif PLATFORM == IOS

void gotoxy(int x, int y){
  IOS way;
}
#elif PLATFORM == BC

void gotoxy(int x, int y){
  Borland C way;
}

#else
#include <cstdio>
using namespace std;
printf(stderr, "Platform not set!");
#endif
