#include "DnID.h"
#include <iostream>
class CoutDnID : public DnID 
   {
   public:
   virtual void printVals() 
      {std::cout << *(int*)data;}
   };

int main(int num, char** vals)
   {
   int a [5] = {0};
   CoutDnID dnd;
   if(num > 1)
      {
      if(!strcmp(vals[1], "int"))
         {/*
         switch(num)
            {
            case 1:
               break;
            case 2:
               dnd.sumInts(atoi(vals[2]));
               dnd.printVals();
               break;
            case 3:
               dnd.sumInts(atoi(vals[2]),atoi(vals[3]));
               dnd.printVals();
               break;//blah not gonna finish the rest
            case 4:
               dnd.sumInts(atoi(vals[2]));
               dnd.printVals();
               break;
            case 5:
               dnd.sumInts(atoi(vals[2]));
               dnd.printVals();
               break;
            case 6:
               dnd.sumInts(atoi(vals[2]));
               dnd.printVals();
               break;
               
            }*/
         for(int i = 2; i < num; i++)
            a[i - 2] = atoi(vals[i]);
            
         dnd.sumInts(a[0], a[1], a[2], a[3], a[4]);
         dnd.printVals();
         }
      }
   return 0;
   }