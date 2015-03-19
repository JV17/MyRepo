//
//  main.cpp
//  practice
//
//  Created by Jorge Valbuena on 2015-03-17.
//  Copyright (c) 2015 com.jorgedeveloper. All rights reserved.
//

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

const int ROWS = 3;
const int SIZE = 5;

template <typename T>
class Node {
    T _data;
    Node *_next;
public:
    Node(T d, Node *n) : _data(d), _next(n) {}
    T data() const { return _data; }
    void setData(T d) { _data = d; }
    Node *next() const { return _next; }
};


template <typename T>
class LinkList {
    Node<T> *head;
public:
    LinkList() : head(NULL) {}
    
    ~LinkList() {
        while (Node<T> *p = head) {
            head = head->next();
            delete p;
        }
    }
    
    void push_front(T d) {
        head = new (nothrow) Node<T>(d, head);
    }
    
    T pop_front() {
        T data;
        if(head) {
            Node<T> *p = head;
            data = head->data();
            head = head->next();
            delete p;
        }
        return data;
    }
    
    T getData() const {
        return head->data();
    }
    
    void setData(T d) {
        if(head)
            head->setData(d);
    }
    
    bool empty() {
        return head == NULL;
    }
    
};

int *sortList(int arr[]) {
    
    return arr;
}

bool myfunction (int i,int j) { return (i<j); }

struct myclass {
    bool operator() (int i,int j) { return (i<j);}
} myobject;

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";

    list<int> myList[SIZE];
    list<int> tmp;
    
    for(int x = 0; x < SIZE; x++)
    {
        myList[x].push_front(x);
        myList[x].push_front(x*3);
        myList[x].push_front(x*5);
        myList[x].push_front(x*7);
        myList[x].push_front(x*9);
    }
    
    cout << "\n***** Before sorting values! *****\n" << endl;
    
    for(int x = 0; x < SIZE; x++)
    {
        cout << "list[" << x << "]: ";
        for (list<int>::iterator it = myList[x].begin(); it != myList[x].end(); ++it)
        {
            cout << *it << " ";
        }
        cout << "" << endl;
    }
    
    cout << "\n***** After sorting values! *****\n" << endl;
    
    for(int x = 0; x < SIZE; x++)
    {
        myList[x].sort();
    }
    
    for(int x = 0; x < SIZE; x++)
    {
        cout << "list[" << x << "]: ";
        for (list<int>::iterator it = myList[x].begin(); it != myList[x].end(); ++it)
        {
            cout << *it << " ";
        }
        cout << "" << endl;
    }
    
    
//    int myints[] = {32,71,12,45,26,80,53,33};
//    vector<int> myvector (myints, myints+8);               // 32 71 12 45 26 80 53 33
    
    // using default comparison (operator <):
//    sort (myvector.begin(), myvector.begin()+4);           //(12 32 45 71)26 80 53 33
    
    // using function as comp
//    sort (myvector.begin()+4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)
    
    // using object as comp
//    sort (myvector.begin(), myvector.end(), myobject);     //(12 26 32 33 45 53 71 80)
    
    // print out content:
//    cout << "myvector contains:";
//    for (vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
//        cout << ' ' << *it;
//    cout << '\n';
    
    
//    List<int> a[ROWS][SIZE];
//    
//    for(int y = 0; y < ROWS; y++)
//    {
//        for(int x = 0; x < SIZE; x++)
//        {
//            a[y][x].push_front(x);
//            a[y][x].push_front(x);
//            a[y][x].push_front(x);
//        }
//    }
//
//    int tmp;
//    // sorting array
//    for(int y = 0; y < ROWS; y++)
//    {
//        for(int x = 0; x < SIZE; x++)
//        {
//            for(int j = 0; j < SIZE; j++)
//            {
//                if(a[y][x].getData() > a[y][j].getData())
//                {
//                    tmp = a[y][x].getData();
//                    a[y][x].setData(a[y][j].getData());
//                    a[y][j].setData(tmp);
//                }
//            }
//        }
//    }
//    
//    // Display Data
//    for(int y = 0; y < ROWS; y++)
//    {
//        for(int x = 0; x < SIZE; x++)
//        {
//            while (!a[y][x].empty())
//            {
//                cout << a[y][x].pop_front() << ' ';
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }
    
    return 0;
}