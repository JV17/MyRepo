// header file

#define UX 1
#define LX 2
#define VC 3
#define BC 4

#define PF LX
int gotoxy(int, int);


// C file

#if PF == UX
int gotoxy(int x, int y){
  unix way
}
#elif PF == LX
int gotoxy(int x, int y){
  linux way
}
#elif PF == VC
int gotoxy(int x, int y){
  Microsoft way
}
#elif PF == BC
int gotoxy(int x, int y){
  Borland way
}
#else
   fprintf(strerr, "Platform not defined");
   exit(0);
#endif


