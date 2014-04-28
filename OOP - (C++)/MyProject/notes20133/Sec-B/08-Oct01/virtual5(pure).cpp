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
  virtual void Act()=0;

  int Data(){
    return data;
  }
  ostream &print(ostream &os){
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
  ~Derived3(){
    cout<<"Derived three with "<<Data()<<" is gone."<<endl;
  }
};
class Derived4:public Base{
public:
  Derived4(int data):Base(data*1000){
    cout<<"Creating Derived Four with "<<Data()<<endl;
  }
  ~Derived4(){
    cout<<"Derived Four with "<<Data()<<" is gone."<<endl;
  }
};

class Derived41:public Derived4{
public:
  Derived41(int data):Derived4(data*1000){
    cout<<"Creating Derived Four-One with "<<Data()<<endl;
  }
  void Act(void){
    cout<<"Acts like a Derived Four-one."<<endl;   
  }
  ~Derived41(){
    cout<<"Derived Four-One with "<<Data()<<" is gone."<<endl;
  }
};
class Derived31:public Derived3{
public:
  Derived31(int data):Derived3(data*1000){
    cout<<"Creating Derived Three-One with "<<Data()<<endl;
  }
  void Act(void){
    cout<<"Acts like a Derived Three-one."<<endl;   
  }
  ~Derived31(){
    cout<<"Derived Three-One with "<<Data()<<" is gone."<<endl;
  }
};
int main(void){
  Base*
    Bptr[3] = {/* new Base(10) can not cause it is abstract ,*/
                 new Derived1(10), new Derived2(20), new Derived3(30)};
  //Derived1 d1(50);
  //Base& B = d1;
  //B.Act();
  Derived3* d3p = new Derived31(10);
  d3p->Act();
  int i;
  for(i=0;i<3;i++){
    //Bptr[i]->Act();
    (*Bptr[i]).Act();
  }
  for(i=0;i<3;i++){
    cout<<(*Bptr[i])<<endl;
  }
  for(i=0;i<3;i++){
    delete Bptr[i];
  }
  return 0;
}

