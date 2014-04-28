#include <iostream>
using namespace std;
class A{
private:
    int data;
public:
    A(int data = -1){  // defaults the A with -1
        this->data = data;
    }
    int print(){
        cout << "A: " << data << endl;
        return data;
    }
};
class B : virtual public A{
private:
    int data;
public:
    B(int data){
        this->data = data;
    }
    int print(){
        A::print();
        cout << "B: " << data << endl;
        return data;
    }
};
class C : virtual public A{
private:
    int data;
public:
    C(int data = 10) :A(data / 2){
        this->data = data;
    }
    int print(){
        A::print();
        cout << "C: " << data << endl;
        return data;
    }
};
class D :public B, public C{
private:
    int data;
public:
    D(int data) :B(data / 2){
        this->data = data;
    }
    int print(){
        B::print();
        C::print();
        cout << "D: " << data << endl;
        return data;
    }
};
int main(){
    D d(50);
    C c(20);
    c.print();
    cout << "--------------" << endl;
    d.print();
    cout << "--------------" << endl;
    B(d).print();
    cout << "--------------" << endl;
    C(d).print();
    cout << "--------------" << endl;
    A(B(d)).print();
    cout << "--------------" << endl;
    A(C(d)).print();
    cout << "--------------" << endl;
    d.B::A::print();
    cout << "--------------" << endl;
    d.C::A::print();
    return 0;
}