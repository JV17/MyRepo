// Jorge E. Valbuena S.
// OOP344A - Assingment #3

#pragma once
#ifndef __INTLIST_H__
#define __INTLIST_H__

#include <iostream>

class IntListNode{
private:
	int _data; // holds the data of the node
	IntListNode* _next; // pointer to the next node
	void next(IntListNode* n); // updates the next pointer of the node
	friend class IntList;
public:
	IntListNode(int d = int(), IntListNode* n = NULL); // contruct used to create new nodes
	IntListNode(const IntListNode &obj); // copy constructor
	IntListNode& operator=(const IntListNode &obj); // assignment operator
	int val() const; // gets and return the data of the node
	void val(int a); // updates the data of the node
	IntListNode* next() const; // gets and return the pointer to next node
};


class IntList{
private:
	IntListNode* _head; // pointer to the head of the node
	unsigned int _size; //  size of the node
public:
	IntList(); // dummy constructor 
	IntList(const IntList &obj); // copy constructor
	~IntList(); // destructor deallocates all node
	IntList& operator=(const IntList &obj); // assignment operator
	int size() const; // gets and return the size of the node
	IntListNode* head() const; // gets and return the head pointer of node
	void push(int d); // create nodes at the end of the list
	void pop(); // delete nodes at the end of the list
	void clear(); // delete all node in the list
	bool empty(); // checks if the list is empty
};

#endif