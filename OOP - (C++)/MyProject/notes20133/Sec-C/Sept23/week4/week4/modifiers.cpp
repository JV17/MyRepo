#include <vector>
#include <iostream>

class A{};
class B : public A {};
class C : public B {};

#include "mod.h"

void Foo::doStuff()
   {
   i++;
   }

int Foo::b = 0;

void Foo::reset()
   {
   b = 0;
   }





void doStuff()
   {
   g_i++;
   }

int main()
   {
   Foo foos[10];
   //foos[0].reset();
   Foo::reset();
   Foo newfoo;
   std::cout << "id of [0] " << foos[0].id << std::endl;

   float g_i;
   g_i = 1;
   doStuff();
   doStuff();

   std::vector<int> v;
   int i = 1;
   unsigned int b = 3;
   std::vector<int>::iterator c = v.begin();

   A* aa = new A();
   B* bb = new B();
   C* cc = new C();

   A* ac = new C();

   auto _c = v.begin();
   //auto _a;
   //_a = new A();

   float f = 0;
   int ff = 0;

   auto fff = ff = f = 0 + 1.5;

   auto _aa = new A();
   auto _bb = new B();
   auto _cc = new C();
   auto _ac = new C();



   }