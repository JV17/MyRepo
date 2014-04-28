/* Singly Linked Lists - Stack
  * stack.cpp
  * Jun 3 2007
  */
 #include <iostream>
 using namespace std;

 class Element {
     int data;
 public:
     Element(int d = 0) : data(d) {}
     int out() const { return data;}
 };

 struct Node {
     Element data;
     Node* next;
     Node(int d, Node* n) : data(d), next(n) {}
 };

 class Stack {
     Node* head;
 public:
     Stack() : head(NULL) {}
     ~Stack() {
         while (Node* p = head) {
             head = head->next;
             delete p;
         }
     }
     void push(int d) { head = new Node (d, head);} 
     Element pop() {
         Element data;
         if (head) {
             Node* p = head;
             data = head->data;
             head = head->next;
             delete p;
         }
         return data;
     }
     bool empty() { return head == NULL;}
 };

 int main () {
     Stack s;

     // Push Data Onto Stack
     s.push(3);
     s.push(5);
     s.push(9);
     s.push(8);

     // Remove first Node
     s.pop();

     // Pop Data Off Stack
     while (!s.empty())
         cout << s.pop().out() << ' ';
     cout << endl;

     return 0;
 }