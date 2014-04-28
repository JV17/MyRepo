#include <iostream>

int add(int a, int b)
   {return a + b;}

int sub(int, int);

int sub(int a, int b)
   {return a - b;}

void operate(int*, int, int, int(*)(int,int));

void operate(int* a, int b, int c, int(*ptr)(int,int))
   {
   *a = ptr(b,c);
   }

int main()
   {
   int test = 0;
   operate(&test, 10, 12, add);
   std::cout << "value is " << test << std::endl;
   operate(&test, 11, 3, sub);
   std::cout << "value is " << test << std::endl;
   return 0;
   }