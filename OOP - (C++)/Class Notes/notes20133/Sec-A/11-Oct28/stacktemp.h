#ifndef __FS_STACKTEMP_H__
#define __FS_STACKTEMP_H__
namespace oop344{

  template <class T>
  class Stack;

  template <class T>
  class Node{
    T _data;
    Node<T>* _next;
    Node(T data, Node<T>* next = (Node<T>*)0);
    friend class Stack<T>;
    virtual ~Node();
  };


  template <class T>
  class Stack{
    Node<T>* _top;
  public:
    Stack();
    Stack(const Stack<T>& S);
    void reverse();
    void push(T data);
    T pop();
    bool isEmpty();
    virtual ~Stack();
    unsigned int depth();
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
    Node<T>* toDel = _top;
    _top = _top->_next;
    delete toDel;
    return ret;
  }

  template <class T>
  bool Stack<T>::isEmpty(){
  //  return _top == (Node<T>*)0;
    return !_top;
  }

  template <class T>
  unsigned int Stack<T>::depth(){
  }

  template <class T>
  void Stack<T>::reverse(){
  }

  template <class T>
  Stack<T>::Stack(const Stack<T>& S){
  }
}

#endif