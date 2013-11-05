#include <iostream>
namespace test
   {
#define COMPILE_FAST
#define PRINT_SPLIT(v) std::cout << (int)*((char*)(v)) << ' ' << \
   (int)*((char*)(v) + 1) << ' ' << (int)*((char*)(v) +2) << ' ' << \
   (int)*((char*)(v)+3) << std::endl

   typedef unsigned long long uint;
   namespace er
      {
      typedef unsigned int uint;
      }
   void debug(void* data, int size = 0)
      {
      if(size == 0)
         {
         std::cout << "The data is: ";
         PRINT_SPLIT(data);
         }
      else
         {
         while(size--)
            {
            std::cout << "Data at " << size << " is: ";
            char* a = (char*)data;
            PRINT_SPLIT((a + (4*size)));
            }
         }
      }
   }
void ohBoy(void* data)
   {
   std::cout << "Oh Boy!";
   PRINT_SPLIT(data);
   ohBoy(data);
   }

#ifndef COMPILE_FAST
int main()
   {
   std::cout << "System started..." << std::endl;
   test::er::uint a = 10;
   ohBoy(&a);
   std::cout << "Test completed (somehow)..." << std::endl;
   return 1;
   }
#else
int main()
   {
   test::uint a = 19;
   test::er::uint b[] = {256,7};
   std::cout << "System started..." << std::endl;
   test::debug(b, 2);
   test::debug(&a);
   std::cout << "Test complete";
   return 0;
   }
#endif
