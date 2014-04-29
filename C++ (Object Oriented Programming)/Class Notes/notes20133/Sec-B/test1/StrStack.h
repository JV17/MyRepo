#ifndef __STRSTACK_H__      // 1 mark
#define __STRSTACK_H__
namespace oop344{           // 1 mark
  class Stack;              // 1 mark

  class Node{               // class and attr 2 marks
    char* _data;       
    Node* _next;
    Node(const char* data, Node* next);   
    virtual ~Node();          // virtual des 2 marks
    friend class StrStack;   // 1 mark
  };

  class StrStack{  // class and top 1 mark
    Node* _top;
  public:
    StrStack();           // construct and destruct 2 marks
    virtual ~StrStack();
    void push(const char* data);                // no marks for protos, already given in question desc.
    void pop(char* data);
    bool isEmpty()const;
    const char* operator[](int index)const;
  };
}
#endif 




