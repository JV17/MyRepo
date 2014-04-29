#include <iostream>

using namespace std;


struct Node{
	int data;
	Node* next;
	Node(int d = 0, Node* n = NULL) : data(d), next(n){}
	int getData() const { return data; }
};


class List{
private:
	Node* head;
public:
	//Node data;
	List() : head(NULL){}
	
	void push(int d){ 
		head = new(nothrow)Node(d, head); 
		cout << "New Node cretated " << head->getData() << endl;
	}
	int pop(){
		int data = 0;
		if (head){
			Node* p = head;
			cout << "Node deleted " << head->getData() << endl;
			data = head->getData();
			head = head->next;
			delete p;
			cout << "Now Head is pointing to  " << head->getData() << endl;
		} 
		return data;
	}
	bool empty(){ return head == NULL; }
};

int main(){
	List a;

	a.push(1);
	a.push(2);
	a.push(3);


	while (!a.empty()){
		cout << a.pop() << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}