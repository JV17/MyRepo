#include <cstring> //for memcpy


#define ALLOC_SIZE 1280
#define NEW(type) CYODT::MemBank<type>::allocate()
#define DELETE(ptr) CYODT::_MemBankDeleteProxy(ptr)


namespace CYODT
   {
   template <class T>
   class Stack
      {
      private:
      protected:
         T* data;
         unsigned int allocSize;
         unsigned int curSize;
         void growArray() 
            {
            auto t = new T[allocSize *= 2];
            memcpy(t, data, curSize);
            delete data;
            data = t;
            }
      public:
         Stack(unsigned int init = 32) : allocSize(init), curSize(0), data(new T[init]) {}
         void push(T a) 
            {
            if(curSize == allocSize)
               growArray();
            data[curSize++] = a;
            }
         ~Stack() {delete data;}
         void pop() {curSize--;}
         T& operator[](unsigned int i) {return data[i];}
         unsigned int size() {return curSize;}
         T& getLast() {return data[curSize-1];}
      };


   template <class T>
   class MemBank
      {
      private:
         static Stack<void*> avail;
         static Stack<char*> buffers;
         struct MemBankClear
            {
            ~MemBankClear() {MemBank<T>::clearBank();}
            };
         static MemBankClear clear;
      protected:
         MemBank() {}
      public:
         static T* allocate()
            {
            clear; //this does nothing, just gets around VS bug
            if(!avail.size())
               {
               auto t = new char[ALLOC_SIZE * sizeof(T)];
               buffers.push(t);
               T* c = (T*)t;
               unsigned int a = ALLOC_SIZE;
               while(a--)
                  avail.push(c + a);
               }
            auto r = avail.getLast();
            avail.pop();
            *(T*)r = T();//relies on assignment operator and default ctor
            return (T*)r;
            }


         static void deallocate(T* a)
            {
            a->~T();
            avail.push(a);
            }


         static void clearBank()
            {
            while(avail.size())
               avail.pop();
            while(buffers.size())
               {
               delete [] buffers.getLast();
               buffers.pop();
               }
            }
      };


   template <class T>
   Stack<void*> MemBank<T>::avail;


   template <class T>
   Stack<char*> MemBank<T>::buffers;


   template <class T>
   typename MemBank<T>::MemBankClear MemBank<T>::clear;


   template <class T>
   static void _MemBankDeleteProxy(T* a) {MemBank<T>::deallocate(a);}
   };

