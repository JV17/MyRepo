#include <iostream>
#define SCLASS(name) class name : public CYODT::MemCheck<name>


namespace CYODT 
   {
   template <class T>
   class MemCheck
      {
      static unsigned int cnt;
      class Alert
         {
         public:
         ~Alert()
            {
            if(cnt != 0u)
               {
               int a;
               std::cout << "Warning: " << cnt << " objects were not deallocated" << std::endl;
               std::cin >> a;
               }
            }
         };
      static Alert alert;
      protected:
      MemCheck() 
      {
      alert; // this is just to force VS to actually create the inner variable
      cnt++;
      }
      virtual ~MemCheck() {cnt--;}
      };
   }


template <class T>
unsigned int CYODT::MemCheck<T>::cnt = 0;


template <class T>
typename CYODT::MemCheck::Alert CYODT::MemCheck<T>::alert;

