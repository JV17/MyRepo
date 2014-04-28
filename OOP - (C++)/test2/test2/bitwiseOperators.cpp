#include <cstdio>
using namespace std;


int main(){
    char A = 0x3A;
    char B = 0x95;
    char C;
    C = A & B;
    printf("A & B: %X\n", C);
    C = A | B;
    printf("A | B: %X\n", C);
    C = A ^ B;
    printf("A ^ B: %X\n", C);
    C = ~A;
    printf("~A: %X\n", C);
    C = A << 1;
    printf("A << 1: %X\n", C);
    C = B << 1;
    printf("B << 1: %X\n", C);
    C = B << 2;
    printf("B << 2: %X\n", C);
    C = A >> 1;
    printf("A << 1: %X\n", C);
    C = B >> 1;
    printf("B << 1: %X\n", C);
    C = B >> 2;
    printf("B << 2: %X\n", C);


    return 0;
}

