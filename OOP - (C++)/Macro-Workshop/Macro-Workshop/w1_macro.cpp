// Jorge E. Valbuena S.
// OOP344A
#include <stdio.h>
#include <time.h> 
#include <cstring>
#include <iostream>

// to display just the file name and not the full path
#define FILE (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__) 

// macro swapping two variables of the same type
#define SWAP(x,y,t) { t temp = x; x = y; y = temp;}

int main(){

    clock_t t1, t2;

    int i = 0; // loop variable 
    int z = 0; // loop variable
    int mil = 1000000000; // loop variable for million times

    std::cout << "File " << FILE << std::endl; // displaying file name

    // initialize new clock
    t1 = clock();
    int a = 2;
    int b = 3;
    
    // looping a million times 
    for (; i < mil; i++)
        SWAP(a, b, int);
   
    // stopping the clock
    t1 = clock() - t1;
    std::cout << "Process time for ints is     " << (((float)t1) / CLOCKS_PER_SEC) << " seconds" << std::endl;

    // initialize new clock
    t2 = clock();
    double x = 10.21;
    double y = 15.22;

    // looping a million times
    for (; z < mil; z++)
        SWAP(x, y, double);
        
    // stopping the clock 
    t2 = clock() - t2;    
    std::cout << "Process time for doubles is  " << (((float)t2) / CLOCKS_PER_SEC) << " seconds" << std::endl;

    system("pause");
    return 0;
}