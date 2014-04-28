#include <iostream>
#include <cstdarg>

int sum(int num, ...)
   {
   va_list arg;
   int sum = 0;

   va_start(arg, num);
   for( int i = 0; i < num; i++)
      {
      sum+= va_arg(arg, int);
      }
   va_end(arg);
   return sum;
   }

int main(int argc, char* argv[])
   {
   int i = 0;
   for(;i< argc; i++)
      {
      std::cout << i << " element is: " << argv[i] << std::endl;
      }
   //std::cout << "I like " << argv[1] << " but not " << argv[2];

   std::cout << "The sum is " << sum(6,1,2,3,4,5,6);
   return 0;
   }
