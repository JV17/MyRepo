#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Node{
	T _data;
	Node* _next;
public:
	Node(T d, Node* n) : _data(d), _next(n){}
	T data() const{ return _data; }
	Node* next() const { return _next; }
	void setnext(Node* n) { _next = n; }
};

template <typename T>
class Stack{
	Node<T>* head;
public:
	Stack() : head(NULL){}
	~Stack(){
		while (Node<T>* p = head){
			head = head->next();
			delete p;
		}
	}
	void push_front(T d){ head = new (nothrow)Node<T>(d, head); }
	T pop_front(){
		T data;
		if (head){
			Node<T>* p = head;
			data = head->data();
			head = head->next();
			delete p;
		}
		return data;
	}
	bool empty() { return head == NULL; }

};


template <typename T>
class Queue{
	Node<T>* head;
	Node<T>* tail;
public:
	Queue() : head(NULL), tail(NULL){}
	~Queue(){
		while (Node<T>* p = head){
			head = head->next();
			delete p;
		}
	}
	void push_end(T d){
		Node<T>* n = new (nothrow)Node<T>(d, 0);
		if (head)
			tail->setnext(n);
		else
			head = n;
		tail = n;
	}
	T pop_end(){
		T data;
		if (head){
			Node<T>* p = head;
			data = head->data();
			head = head->next();
			delete p;
			if (!head) tail = NULL;
		}
		return data;
	}
	bool empty() { return head == NULL; }
	T operator[](unsigned int x){
		T a;
		if (head){
			Node<T>* p = head;
			int count = 0;
			while (p){
				if (x == count){
					a = p->data();
					break;
				}
				if (!p->next())
					break;
				p = p->next();
				count++;
			}
		}
		return a;
	}
};


int main(){
	Stack<string> a;
	Queue<string> b;

	a.push_front("Valbuena");
	a.push_front("Jorge");
	a.push_front("My name is: ");

	while (!a.empty())
		cout << a.pop_front();
	cout << endl;

	

	b.push_end("Prepping for ");
	b.push_end("Test 2 ");
	b.push_end("YEAH!! BABY!!");

	cout << b[1].data() << endl;

	while (!b.empty())
		cout << b.pop_end();
	cout << endl;

	

	system("pause");
	return 0;
}