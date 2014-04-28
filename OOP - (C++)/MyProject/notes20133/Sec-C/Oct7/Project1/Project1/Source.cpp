#include "DynamicArray.h"
#include <vector>
#include <string>

int main()
   {
   std::vector<int> vc;
   vc.push_back(3);
   vc.pop_back();
   vc.push_back(00);
   int s = vc.size();
   vc[0] = 1;
   for(int i = 0; i < vc.size(); i++)
      vc[i] = 10;
   //std::string str;

   DyArray ar[15];
   int i = 30;
   while(i--)
      ar[0].pushBack(i);
   ar[0][3] = 10;
   return 0;
   }