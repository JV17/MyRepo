#ifndef __FS__STACK_H__
#define __FS__STACK_H__
namespace oop344{
  template <class T>
  class Stack;
 
  template <class T>
  class Node{
    T _data;
    Node<T>* _next;
    Node(T data, Node<T>* next=(Node<T>*)0);
    virtual ~Node();
    friend class Stack<T>;
  };
  template <class T>
  class Stack{
    Node<T>* _top;
  public:
    Stack();
    virtual ~Stack();
    void reverse();
    void push(T data);
    T pop();
    bool isEmpty();
  };
  template <class T>
   Node<T>::Node(T data, Node<T>* next){
    _data = data;
    _next = next;
  }
  template <class T>
  Node<T>::~Node(){}

  template <class T>
  Stack<T>::Stack(){
    _top = (Node<T>*)0;
  }
  template <class T>
  Stack<T>::~Stack(){
    while(!isEmpty()){
      pop();
    }
  }

  template <class T>
  void Stack<T>::push(T data){
    Node<T>* newnode = new Node<T>(data, _top);
    _top = newnode; 
  }

  template <class T>
  T Stack<T>::pop(){
    T ret = _top->_data;
    Node<T>* ToDel = _top;
    _top = _top->_next;
    delete ToDel;
    return ret;
  }


  template <class T>
  bool Stack<T>::isEmpty(){
   // return _top == (Node*)0;
    return !_top;
  }
}
#endif