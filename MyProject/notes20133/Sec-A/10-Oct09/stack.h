#ifndef __FS_STACK_H__
#define __FS_STACK_H__
namespace oop344{
  class Stack;

  class Node{
    int _data;
    Node* _next;
    Node(int data, Node* next = (Node*)0);
    friend class Stack;
    virtual ~Node();
  };


  class Stack{
    Node* _top;
  public:
    Stack();
    Stack(const Stack& S);
    void reverse();
    void push(int data);
    int pop();
    bool isEmpty();
    virtual ~Stack();
    unsigned int depth();
  };

}
#endif