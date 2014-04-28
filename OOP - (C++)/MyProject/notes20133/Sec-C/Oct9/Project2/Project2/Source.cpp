#include <iostream>
#include "Header.h"

int main()
   {
   SinglyLinkedList a;

   a.pushBack(10);
   a.pushBack(11);
   a.pushFront(9);
   a.pushFront(8);

   std::cout << "Front: " << a.getFront() << " Back: " << a.getBack() << std::endl;

   a.popBack();
   a.popBack();
   a.popFront();
   a.popFront();

   a.pushBack(10);
   a.pushBack(11);
   a.pushFront(9);
   a.pushFront(8);

   a.popFront();
   a.popBack();
   a.popFront();
   a.popBack();
   }