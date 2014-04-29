
class DyArray
   {
   private:
      unsigned int size;
      int* data;
      unsigned int allocSize;
   protected:
      void resize();
   public:

      DyArray() : size(0), data(new int[8]), 
         allocSize(8) {}
      ~DyArray();
      void pushBack(int);
      void popBack();
      int& operator[](unsigned int);
   };