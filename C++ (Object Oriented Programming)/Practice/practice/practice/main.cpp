//
//  main.cpp
//  practice
//
//  Created by Jorge Valbuena on 2015-03-17.
//  Copyright (c) 2015 com.jorgedeveloper. All rights reserved.
//

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int ROWS = 3;
const int SIZE = 5;

class Node {
    int _data;
    Node *_next;
public:
    Node(int d, Node *n) : _data(d), _next(n) {}
    int data() const { return _data; }
    void setData(int d) { _data = d; }
    Node *next() const { return _next; }
    void setNext(Node *n) { _next = n; }
};

class LinkList {
    Node *head;
public:
    LinkList() : head(nullptr) {}
    
    ~LinkList() {
        while (Node *p = head) {
            head = head->next();
            delete p;
        }
    }
    
    Node *getHead() const { return head; }
    
    void push_front(int d) {
        head = new (nothrow) Node(d, head);
    }
    
    int pop_front() {
        int data;
        if(head) {
            Node *p = head;
            data = head->data();
            head = head->next();
            delete p;
        }
        return data;
    }
    
    void print_list(int x) {
        cout << "list[" << x << "]:";
        for (Node *index = head; index->next() != nullptr; index = index->next()) {
            cout << index->data() << " ";
            x++;
        }
        cout << endl;
    }
    
    bool empty() {
        return head == nullptr;
    }
    
    void sort_ascending() {
        for (Node *index = head; index->next() != nullptr; index = index->next()) {
            for (Node *selection = index->next(); selection != nullptr; selection = selection->next()) {
                if (index->data() < selection->data()) {
                    swap(index, selection);
                }
            }
        }
    }
    
    void sort_descending() {
        for (Node *index = head; index->next() != nullptr; index = index->next()) {
            for (Node *selection = index->next(); selection != nullptr; selection = selection->next()) {
                if (index->data() > selection->data()) {
                    swap(index, selection);
                }
            }
        }
    }
    
    void swap(Node *a, Node *b) {
        int tmp;
        tmp = a->data();
        a->setData(b->data());
        b->setData(tmp);
    }
};


// helper class for string compare without case sensitive
struct myclass {
    bool operator() (int i,int j) { return (i<j);}
} myobject;


int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    
    LinkList a[SIZE];
    
    // create an array of linked lists
    for(int x = 0; x < SIZE; x++) {
        a[x].push_front(rand() % 100);
        a[x].push_front(rand() % 100);
        a[x].push_front(rand() % 100);
        a[x].push_front(rand() % 100);
        a[x].push_front(rand() % 100);
    }
    
    cout << "\nunsorted list" << endl;

    // printing all data within lists
    for(int y = 0; y < SIZE; y++) {
        a[y].print_list(y+1);
    }
    
    // sorting list
    for(int i = 0; i < SIZE; i++) {
        a[i].sort_descending();
    }
    
    cout << "\nsorted list" << endl;
    
    // printing all data within lists
    for(int y = 0; y < SIZE; y++) {
        a[y].print_list(y+1);
    }

//    list<int> myList[SIZE];
//    list<int> tmp;
//    
//    for(int x = 0; x < SIZE; x++)
//    {
//        myList[x].push_front(rand() % 100);
//        myList[x].push_front(rand() % 100);
//        myList[x].push_front(rand() % 100);
//        myList[x].push_front(rand() % 100);
//        myList[x].push_front(rand() % 100);
//    }
//    
//    cout << "\nBefore sorting values!" << endl;
//    cout << "======================" << endl;
//    
//    for(int x = 0; x < SIZE; x++)
//    {
//        cout << "list[" << x << "]: ";
//        for (list<int>::iterator it = myList[x].begin(); it != myList[x].end(); ++it)
//        {
//            cout << *it << " ";
//        }
//        cout << "" << endl;
//    }
//    
//    cout << "\nAfter sorting values!" << endl;
//    cout << "=====================" << endl;
//    
//    for(int x = 0; x < SIZE; x++)
//    {
//        myList[x].sort();
//    }
//    
//    for(int x = 0; x < SIZE; x++)
//    {
//        cout << "list[" << x << "]: ";
//        for (list<int>::iterator it = myList[x].begin(); it != myList[x].end(); ++it)
//        {
//            cout << *it << " ";
//        }
//        cout << "" << endl;
//    }

    return 0;
}