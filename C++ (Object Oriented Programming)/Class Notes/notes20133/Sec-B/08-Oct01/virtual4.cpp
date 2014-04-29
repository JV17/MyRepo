#include <iostream>
using namespace std;

class Base{
  int
    data;
public:
  Base(int data = 0){
    this->data = data;
    cout<<"Creating Base with "<<data<<endl;
  }
  virtual void Act(void)=0 ;
  int Data(){
    return data;
  }
  virtual ostream &print(ostream &os){
    return os<<"Printing: "<<data;
  }
  virtual ~Base(){
    cout<<"Base is gone..."<<endl;
  }
};

ostream &operator<<(ostream &os, Base &B){
  return B.print(os);
}


class Derived1:public Base{
public:
  Derived1(int data):Base(data*100){
    cout<<"Creating Derived one with "<<Data()<<endl;
  }
  void Act(void){
    cout<<"Acts like a Derived one."<<endl;
  }
  ostream &print(ostream &os){
    return os<<"Printing: "<<Data()<<" of Derived 1";
  }

  ~Derived1(){
    cout<<"Derived one with "<<Data()<<" is gone."<<endl;
  }
};

class Derived2:public Base{
public:
  Derived2(int data):Base(data*100){
    cout<<"Creating Derived two with "<<Data()<<endl;
  }
  void Act(void){
    cout<<"Acts like a Derived two."<<endl;
  }
  ostream &print(ostream &os){
    return os<<"Printing: "<<Data()<<" of Derived 2";
  }
  ~Derived2(){
    cout<<"Derived two with "<<Data()<<" is gone."<<endl;
  }
};


class Derived3:public Base{
public:
  Derived3(int data):Base(data*100){
    cout<<"Creating Derived three with "<<Data()<<endl;
  }
  void Act(void){
    cout<<"Acts like a Derived three."<<endl;
  }
  ostream &print(ostream &os){
    return os<<"Printing: "<<Data()<<" of Derived 3";
  }

  ~Derived3(){
    cout<<"Derived three with "<<Data()<<" is gone."<<endl;
  }
};

int main(void){
  Base*
    Bptr[3] = {/*new Base(0), */ new Derived1(10),
                         new Derived2(20), new Derived3(30)};
  int i;
  for(i=0;i<3;i++){
    Bptr[i]->Act();
  }
  for(i=0;i<3;i++){
    cout<<(*Bptr[i])<<endl;
  }
  for(i=0;i<3;i++){
    delete Bptr[i];
  }
  return 0;
}
