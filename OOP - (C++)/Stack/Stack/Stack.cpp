#include <iostream>

using namespace std;

class Data{
private:
	int data;
public:
	Data(int d = 0) : data(d){}
	int getData() const{
		return data;
	}
};


struct Node{
	Data data;
	Node* next;
	Node(const Data& d, Node* n) : data(d), next(n){}
};


class Stack{
private:
	Node* head;
public:
	Stack() : head(NULL){}
	~Stack(){
		while (Node* p = head){
			head = head->next;
			delete p;
		}
	}
	void push(int d){
		head = new Node(d, head);
	}
	Data pop(){
		Data data;
		if (head){
			Node* p = head;
			data = head->data;
			head = head->next;
			delete p;
		}
		return data;
	}
	bool empty(){
		return head == NULL;
	}
};


int main(){
	Stack s;

	// push Data Onto Stack
	s.push(3);
	s.push(5);
	s.push(9);
	s.push(8);

	// remove first Node
	s.pop();

	// Pop Data of Stack
	while (!s.empty())
		cout << s.pop().getData() << ' ';
	cout << endl;

	system("pause");
	return 0;
}