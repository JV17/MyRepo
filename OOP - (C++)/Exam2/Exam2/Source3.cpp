#include <iostream>
using namespace std;
class Base{
    int
    data;
public:
    Base(int data = 0){
        this->data = data;
        cout << "CB:" << data << endl;
    }
    virtual void Act(){
        cout << "Base Acts." << endl;
    }
    void work(){
        cout << "Base Works." << endl;
    }
    int Data(){
        return data;
    }
    ~Base(){
        cout << "BG" << endl;
    }
};


class Derived :public Base{
public:
    Derived(int data) :Base(data / 2){
        cout << "CD:" << Data() << endl;
    }
    void Act(){
        cout << "Derived Acts." << endl;
    }
    void work(){
        cout << "Derived Works." << endl;
    }
    ~Derived(){
        cout << "DG" << endl;
    }
};
int main(void){
    Derived D(10);
    Base& R = D;
    Base* P = new Derived(30);
    P->Act();
    P->work();
    R.Act();
    R.work();
    delete P;
    D.Act();
    D.work();
    return 0;
}