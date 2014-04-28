#include "stack.h"
namespace oop344{
  Node::Node(int data, Node* next){
    _data = data;
    _next = next;
  }
  Node::~Node(){}


  Stack::Stack(){
    _top = (Node*)0;
  }
  Stack::Stack(const Stack& S){
  }
  void Stack::reverse(){
  }
  Stack::~Stack(){
    while(!isEmpty()){
      pop();
    }
  }

  void Stack::push(int data){
    Node* newnode = new Node(data, _top);
    _top = newnode; 
  }

  int Stack::pop(){
    int ret = _top->_data;
    Node* ToDel = _top;
    _top = _top->_next;
    delete ToDel;
    return ret;
  }

  unsigned int depth(){
    return 0;
  }

  bool Stack::isEmpty(){
   // return _top == (Node*)0;
    return !_top;
  }

}