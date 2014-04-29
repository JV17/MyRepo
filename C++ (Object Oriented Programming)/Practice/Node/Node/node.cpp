#include <iostream>

using namespace std;

class Data{
private:
	int data;
public:
	Data(int d) : data(d){}
	int getData() const{
		return data;
	}
};

struct Node{
	Data data;
	Node* next;
	Node(const Data& d, Node* n) : data(d), next(n){}
};


int main(){

	Node* head = NULL;

	// creating elements
	head = new Node(3, head);
	head = new Node(5, head);
	head = new Node(9, head);
	head = new Node(8, head);

	// removing the head node
	Node* remove = head;
	head = head->next;
	delete remove;

	// Display elements from head to tail
	for (Node* p = head; p; p = p->next)
		cout << p->data.getData() << ' ';
	cout << endl;

	// deallocating elements
	while (Node* p = head){
		head = head->next;
		delete p;
	}


	system("pause");
	return 0;
}