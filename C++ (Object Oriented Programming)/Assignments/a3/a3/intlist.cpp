// Jorge E. Valbuena S.
// OOP344A - Assignment #3

#include <iostream>
#include <string>
#include "intlist.h"

using namespace std;

/********************** IntListNode Implementation ***********************************/
// Accepts two arguments:
//    1) Integer to initialize node's value. Defaults to a default constructed int.
//    2) Pointer to next node in list.Defaults to NULL.
IntListNode::IntListNode(int d, IntListNode* n) : _data(d), _next(n){};

// Initializes internal value as a copy of the source's internal value. Sets this object's next pointer to NULL. 
IntListNode::IntListNode(const IntListNode &obj){
	_next = NULL;
	_data = obj._data;
};

// Assigns source's internal value to the current object's internal value. Sets this object's next pointer to NULL. 
// Does not alter the object in the case of self-assignment. Returns a reference to the current object. 
IntListNode& IntListNode::operator=(const IntListNode &obj){
	if (this != &obj){
		_next = NULL;
		_data = obj._data;
	}
	return *this;
};

// Val getter. Const function. Does not accept parameters. Returns internal value. 
int IntListNode::val() const{ return _data; };

// Val setter. Receives an int. Sets internal value to received int. Does not return anything. 
void IntListNode::val(int d) { _data = d; };

// Next getter. Const function. Does not accept parameters. Returns pointer to the next node. 
IntListNode* IntListNode::next() const{ return _next; };

// Next setter. Receives a ListNode pointer. Sets internal value to received reference. Does not return anything. 
void IntListNode::next(IntListNode* n) { _next = n; }


/********************** IntList Implementation ***********************************/
// Does not accept parameters. Initializes list to safe empty state. 
IntList::IntList() : _size(0), _head(NULL) {
	_size = 0;
	_head = 0;
};

// Initializes object to safe state then copies source list into current list. Similar to assignment operator. 
IntList::IntList(const IntList &obj){
	*this = obj;
};

// Should ensure that all memory allocated by the list has been deallocated. You are encouraged to use the functions available to you. 
IntList::~IntList(){
	clear();
};

// Clears this list of all nodes. Then, refills list with the same number of nodes as in the source list. 
// Value of each new node should equal the value of corresponding node in source list. Should not alter object in the case of self-assignment. 
// Should return a reference to the current object. 
IntList& IntList::operator=(const IntList &obj){
	if (this != &obj){
		clear();
		_head = 0;
		IntListNode* p = obj._head;
		while (p){
			push(p->val());
			p = p->next();
		}
	}
	return *this;
};

// Size getter. Const function. Does not receive parameters. Should return number of nodes in list. 
int IntList::size() const { return _size; };

// Head getter. Const function. Returns pointer to head node in list. 
IntListNode* IntList::head() const { return _head; };

// Adds a new node to the end of the list. I'll say that again, END OF THE LIST. Receives an int parameter. 
// The new node's value should be set to the received int. 
void IntList::push(int d){
	IntListNode* n = new (nothrow) IntListNode(d, 0);
	IntListNode* p = head();
	
	for (; p && p->next(); p = p->next());
	
	if (!p)
		_head = n;
	else
		p->next(n);
		
	++_size;
};

// Destroys the last node in the list. I'll say that again, LAST NODE IN THE LIST. Does not receive any arguments. 
// Does not return anything. 
void IntList::pop(){
	
	if (_size == 1){
		delete _head;
		_head = NULL;
		--_size;
	}
	else {
		IntListNode* p = head();
		
		for (; p && p->next() && p->next()->next(); p = p->next());
		
		delete p->next();
		
		p->next(NULL);
		--_size;
	}
};

// Removes all nodes in the list. Has no effect if the list is empty. Does not accept parameters. Does not return anything. 
void IntList::clear(){
	while (!empty()){
		pop();
	}
};

// Check if the list is empty
bool IntList::empty() { return _head == NULL; }