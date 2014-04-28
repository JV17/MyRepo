static int g_i = 0;

class Foo
   {
   private:
      int i;
      static int b;
   public:
      
      int id;
      Foo() 
         {
         id = b++;
         i = 0;
         }
      void doStuff();
      static void reset();
   };