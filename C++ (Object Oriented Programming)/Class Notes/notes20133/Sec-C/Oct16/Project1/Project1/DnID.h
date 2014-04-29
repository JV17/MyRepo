class DnID 
   {
   private:
      int id;
      static unsigned int count;
   protected:
      void* data;
   public:
      DnID() 
         {
         //static unsigned int count = 0;
         id = count++;
         data = 0;
         }
      ~DnID() 
         {
         if(data)
            delete (int*)data;
         }
      void sumInts(int a, int b = 0, int c = 0,
         int d = 0, int e = 0) 
         {
         //int i;
         //data = &i;
         data = new int;
         *(int*)data = a + b + c + d + e;
         }
      virtual void printVals() = 0;
   };

unsigned int DnID::count = 0;