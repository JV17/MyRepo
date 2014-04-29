// Jorge E. Valbuena S.
// OOP344A - Assingment #3

#pragma once
#ifndef __LIST_H__
#define __LIST_H__

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class List;

template<typename T>
class ListNode{
private:
	T _data; // holds the data of the node
	ListNode<T>* _next; // pointer to the next node

	friend class List<T>;

	// Next setter. Receives a ListNode pointer type T. Sets internal value to received reference. Does not return anything. 
	void next(ListNode<T>* n){ _next = n; }
public:
	// Accepts two arguments.
	//    1) Important const T reference to initialize node's value. Defaults to a default constructed T.
	//	  2) Pointer to next node in the list.Defaults to NULL.
	ListNode(const T d = T(), ListNode<T>* n = NULL) : _data(d), _next(n){};

	// Initializes internal value as a copy of the source's internal value. Sets this object's next pointer to NULL. 
	ListNode(const ListNode<T> &obj){
		_next = NULL;
		_data = obj._data;
	};

	// Assigns source's internal value to the current object's internal value. Sets this object's next pointer to NULL. 
	// Does not alter the object in the case of self-assignment. Returns a reference to the current object. 
	ListNode<T>& operator=(const ListNode<T> &obj){
		if (this != &obj){
			_next = NULL;
			_data = obj._data;
		}
		return *this;
	};

	// Val getter. Const function. Does not accept parameters. Returns internal value. 
	T val() const{ return _data; };

	// Val setter. Important receives a const T reference. Sets internal value to received reference. Does not return anything. 
	void val(const T d){ _data = d; };

	// Next getter. Const function. Does not accept parameters. Returns pointer to next node. 
	ListNode<T>* next() const{ return _next; };
};



template<typename T>
class List{
private:
	ListNode<T>* _head; // pointer to the head of the node
	unsigned int _size; //  size of the node
public:
	// Does not accept parameters. Initializes list to safe empty state. 
	List() : _size(0), _head(NULL) {};

	// Initializes object to safe state then copies source list into current list. Similar to assignment operator. 
	List(const List<T> &obj){
		*this = obj;
	}

	// Should ensure that all memory allocated by the list has been deallocated. 
	// You are encouraged to use the functions available to you. 
	~List(){
		clear();
	}

	// Clears this list of all nodes. Then, refills list with the same number of nodes as in the source list. 
	// Value of each new node should equal the value of corresponding node in source list. 
	// Should not alter object in the case of self-assignment. Should return a reference to the current object. 
	List<T>& operator=(const List<T> &obj){
		if (this != &obj){
			clear();
			_head = 0;
			ListNode<T>* p = obj._head;
			while (p){
				push(p->val());
				p = p->next();
			}
		}
		return *this;
	}

	// Size getter. Const function. Does not receive parameters. Should return number of nodes in list. 
	int size() const{ return _size; }

	// Head getter. Const function. Returns pointer to head node in list. 
	ListNode<T>* head() const{ return _head; }

	// Adds a new node to the end of the list. I'll say that again, END OF THE LIST. 
	// Important receives a const T reference. The new node's value should be set to the received reference. 
	void push(const T d){
		ListNode<T>* n = new (nothrow) ListNode<T>(d, 0);
		ListNode<T>* p = head();

		for (; p && p->next(); p = p->next()){};

		if (!p)
			_head = n;
		else
			p->next(n);

		++_size;
	}

	// Destroys the last node in the list. I'll say that again, LAST NODE IN THE LIST. 
	// Does not receive any arguments. Does not return anything. 
	void pop(){
		
		if (_size == 1){
			delete _head;
			_head = NULL;
			--_size;
		}
		else {
			ListNode<T>* p = head();

			for (; p && p->next() && p->next()->next(); p = p->next());

			delete p->next();

			p->next(NULL);
			--_size;
		}
	}

	// Removes all nodes in the list. Has no effect if the list is empty. Does not accept parameters. 
	// Does not return anything. 
	void clear(){
		while (!empty()){
			pop();
		}
	}

	// Checks if the list is empty
	bool empty() { return _head == NULL; }
};

#endif