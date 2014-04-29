#include "DynamicArray.h"

void DyArray::resize() 
   {
   //find our next alloc size
   allocSize *= 2;
   //alloc a new array of that size
   int* t = new int[allocSize];
   //copy all values from previous array
   for(int i = 0; i < size; i++)
      t[i] = data[i];
   //destroy old array
   delete [] data;
   //set data pointer to new array
   data = t;
   }

DyArray::~DyArray()
   {
   delete [] data;
   }

void DyArray::pushBack(int i)
   {
   if(size == allocSize)
      resize();
   data[size] = i;
   size++;
   }

void DyArray::popBack()
   {
   if(size)
      size--;
   }

int& DyArray::operator[](unsigned int i)
   {
   return data[i];
   }