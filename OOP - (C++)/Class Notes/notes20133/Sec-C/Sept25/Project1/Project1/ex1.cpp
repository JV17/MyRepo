#include <iostream>
int g_i = 0;
void doStuff();

#include "Header.h"
//int A::derp = 0;

int main()
   {
   doStuff();
   std::cout << g_i;
   
   return 0;
   }