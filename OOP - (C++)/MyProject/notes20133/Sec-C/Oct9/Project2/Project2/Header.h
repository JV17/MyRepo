
struct Node
   {
   int val;
   Node* next;
   };

class SinglyLinkedList
   {
   private:
      Node* front;
      Node* back;
      unsigned int size;
   protected:
   public:
      SinglyLinkedList() : front(nullptr), back(nullptr), size(0) {}
      void pushBack(int val)
         {
         auto t = new Node();
         t->val = val;
         t->next = nullptr;
         if(!front)
            front = back = t;
         else
            {
            back->next = t;
            back = t;
            }
         size++;
         }
      void pushFront(int val)
         {
         auto t = new Node();
         t->val = val;
         t->next = front;
         if(!front)
            front = back = t;
         else
            front = t;
         size++;
         }

      void popBack()
         {
         if(back)
            {
            size--;
            if(back == front)
               {
               delete back;
               back = front = nullptr;
               }
            else
               {
               auto t = front;
               while(t->next != back)
                  t = t->next;
               t->next = nullptr;
               delete back;
               back = t;
               }
            }
         }
      void popFront()
         {
         if(front)
            {
            auto t = front;
            front = front->next;
            delete t;
            if(!front)
               back = front;
            size--;
            }
         }

      int getFront() {return front->val;}
      int getBack() {return back->val;}
      
      bool isEmpty() {return !size;}
      unsigned int getSize() {return size;}
      
      ~SinglyLinkedList() 
         {
         while(!isEmpty())
            popFront();
         }
   };