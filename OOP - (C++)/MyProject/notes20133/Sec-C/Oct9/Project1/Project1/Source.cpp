#include <iostream>

class EventSystem
   {
   int val;
   static void defaultFunc(int&, bool&) {}
   public:
   void(*over100)(int&);
   void(*under0)(int&);
   void(*preprocess)(int&,bool&);
   void setVal(int i) {val = i;}

   EventSystem() : val(0), over100(0), under0(0) 
      {
      preprocess = defaultFunc;
      }
   void process(bool& a)
      {
      preprocess(val, a);
      if(val > 100 && over100)
         over100(val);
      else if(val < 0 && under0)
         under0(val);
      }
   };

void safeZero(int& i)
   {
   i = 0;
   }

void inform100(int& i)
   {
   std::cout << "The var became " << i << std::endl;
   }

void terminate(int& a, bool& b)
   {
   if(a == 16)
      b = true;
   }

int main()
   {
   EventSystem es;
   es.over100 = inform100;
   es.under0 = safeZero;
   es.preprocess = terminate;
   bool done = false;
   while(!done)
      {
      int i = 0;
      std::cin >> i;
      es.setVal(i);
      es.process(done);
      }
   std::cout << "Function complete";
   }
