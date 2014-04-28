#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "StrStack.h"   // inc and namespace 1 mark
using namespace std;
namespace oop344{
  Node::Node(const char* data, Node* next){   // dynamic alloc and node 3 marks
    _data = new char[strlen(data)+1];
    strcpy(_data, data);
    _next = next;
  }
  Node::~Node(){       // destructor 1 mark
    delete[] _data;
  }
  StrStack::StrStack(){     // 1 mark
    _top = (Node*)0;
  }
  StrStack::~StrStack(){    // destructor 3 marks
    Node* toDel;
    while(toDel = _top){
      _top = _top->_next;
      delete toDel;
    }
  }
  void StrStack::push(const char* data){     // 2 marks
    Node* newnode = new Node(data, _top);
    _top = newnode; 
  }
  void StrStack::pop(char* data){       // copying data out 1 mark
    strcpy(data, _top->_data);          // poping 2 marks
    Node* ToDel = _top;
    _top = _top->_next;
    delete ToDel;
  }
  bool StrStack::isEmpty()const{   // 1 mark
    return !_top;
  }
  const char* StrStack::operator[](int index)const{   // index op  5 marks
    Node* cur = _top;
    int i = 0;
    while(cur && i != index){
      cur = cur->_next;
      i++;
    }
    return cur? cur->_data : (const char*)0;
  }
}