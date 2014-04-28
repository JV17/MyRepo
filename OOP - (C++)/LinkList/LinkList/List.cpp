#include <iostream>

using namespace std;

class Data{
private:
	int data;
public:
	Data(int d = 0) : data(d){}
	int getData() const { return data; }
};


struct Node{
	Data data;
	Node* next;
	Node* prev;
	Node(const Data& d, Node* n, Node* p) : data(d), next(n), prev(p){}
	//Node* getNext() const { return next; }
	//Data getObj() const { return data; }
};


class MyList{
	Node* head;
	Node* tail;
	Node* curr;
public:
	MyList() : head(NULL), tail(NULL), curr(NULL){}
	~MyList(){
		while (curr = head){
			head = head->next;
			delete curr;
		}
	}
	void goHead(){
		curr = head;
	}
	void goNext(){
		if (curr)
			curr = curr->next;
	}
	void remove(){
		if (curr){
			Node* p = curr;
			if (curr == head){
				head = head->next;
			}
			else{
				curr->next->prev = curr->prev;
				curr->prev->next = curr->next;
				curr = curr->next;
			}
			delete p;
		}
	}
	bool end(){
		return !curr;
	}
	Data get() const{
		return curr ? curr->data : Data();
	}
	void insertBefore(const Data& a){
		if (curr){
			Node* p = new (nothrow) Node(a, curr, curr->prev);	// nothrow is constant value usued as an argument for the new operator 
																// to indication to this function shall not throw an exception on failer
																// but return a null pointer instead
			if (p){
				if (curr->prev)
					curr->prev->next = p;
				else
					head = p;
				curr->prev = p;
			}
		}
		else{
			Node* p = new (nothrow)Node(a, NULL, NULL);	// nothrow is constant value usued as an argument for the new operator 
														// to indication to this function shall not throw an exception on failer
														// but return a null pointer instead
			if (p)
				head = tail = curr = p;
		}
	}
	void insertAfter(const Data& a){
		if (curr){
			Node* p = new (nothrow) Node(a, curr->next, curr);	// nothrow is constant value usued as an argument for the new operator 
																// to indication to this function shall not throw an exception on failer
																// but return a null pointer instead
			if (p){
				if (curr->next)
					curr->next->prev = p;
				else
					tail = p;
				curr->next = p;
			}
		}
		else {
			Node* p = new (nothrow) Node(a, NULL, NULL);	// nothrow is constant value usued as an argument for the new operator 
															// to indication to this function shall not throw an exception on failer
															// but return a null pointer instead
			if (p)
				head = tail = curr = p;
		}
	}
};



int main(){
	MyList r;

	// Insert Data
	r.insertAfter(3);
	r.insertAfter(5);
	//r.goHead();
	r.insertAfter(9);
	//r.goNext();
	r.insertAfter(8);
	//r.remove();

	// Display Data
	//r.goHead();
	while (!r.end()) {
		cout << r.get().getData() << ' ';
		r.goNext();
	}
	cout << endl;

	system("pause");
	return 0;
}