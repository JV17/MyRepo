// Jorge E. Valbuena S.
// OOP344A
#include <stdio.h>
#include <time.h> 
#include <cstring>
#include <iostream>

// to display just the file name and not the full path
#define FILE (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__) 

template <typename T>
void swap(T &n1, T &n2){ // swaps every data type and performance is improved
    T tmp = n1;
    n1 = n2;
    n2 = tmp;
}

void swap_i(int n1, int n2){ // not in use because is slower than templated function
    int tmp = n1;
    n1 = n2;
    n2 = tmp;
}

void swap_d(double n1, double n2){ // not in use because is slower than templated function
    double tmp = n1;
    n1 = n2;
    n2 = tmp;
}

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
        swap(a, b);
    
    // stopping the clock
    t1 = clock() - t1;
    std::cout << "Process time for ints is     " << (((float)t1) / CLOCKS_PER_SEC) << " seconds" << std::endl;
    
    // initialize new clock
    t2 = clock();
    double x = 10.21;
    double y = 15.22;
    
    // looping a million times
    for (; z < mil; z++)
        swap(x, y);
    
    // stopping the clock 
    t2 = clock() - t2;
    std::cout << "Process time for doubles is  " << (((float)t2) / CLOCKS_PER_SEC) << " seconds" << std::endl;

    system("pause");
    return 0;
}