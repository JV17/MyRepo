#include <iostream>


namespace CYODT 
   {
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
      MemCheck() {cnt++;}
      virtual ~MemCheck() {cnt--;}
      };
   }

