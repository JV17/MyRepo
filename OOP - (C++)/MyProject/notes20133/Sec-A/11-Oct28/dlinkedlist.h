#ifndef __FS__DLINKEDLIST_H__
#define __FS__DLINKEDLIST_H__
namespace oop344{
  
  class DLinkedlist;
  class Node{
    Node* _next;
    Node* _prev;
    int _data;
    // _data is initialized but _next and _prev are set to values.....
    Node(int data, Node* prev = (Node*)0, Node* next = (Node*)0):_data(data){
      _next = next;
      _prev = prev;
    }
    friend class DLinkedlist;
  };


  class DLinkedlist{
    Node* _head;
    Node* _tail;
    Node* _curr;
  public:
    DLinkedlist();
    void add(int data);
    int remove();
    int visit();
    void del(); // maybe int del(); or even bool del();
    void insertAfter(int data);
    void insertBefore(int data);
    bool goNext();
    bool goPrev();
    bool goHead();
    bool goTail();
    virtual ~DLinkedlist();
    bool isEmpty();
  };

}
#endif
