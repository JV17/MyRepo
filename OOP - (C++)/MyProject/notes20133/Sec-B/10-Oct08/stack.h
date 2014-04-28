#ifndef __FS__STACK_H__
#define __FS__STACK_H__
namespace oop344{
  class Stack;

  class Node{
    int _data;
    Node* _next;
    Node(int data, Node* next=(Node*)0);
    virtual ~Node();
    friend class Stack;
  };

  class Stack{
    Node* _top;
  public:
    Stack();
    Stack(const Stack& S);
    virtual ~Stack();
    void reverse();
    void push(int data);
    int pop();
    bool isEmpty();
    unsigned int depth();
  };















}
#endif