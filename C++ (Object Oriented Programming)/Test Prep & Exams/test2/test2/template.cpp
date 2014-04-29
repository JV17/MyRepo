#include<iostream>

using namespace std;

template <class bucky, class second>
bucky addCrap(bucky a, second b){
    return a + b;
}

template <class FIRST, class SECOND>
FIRST smaller(FIRST a, SECOND b){
    return (a < b ? a : b);
}

//template class
template <class T>
class MyClass{
    T first, second;
public:
    MyClass(T a, T b){
        first = a;
        second = b;
    }
    T bigger();
};

template <class U>
class Spunky{
public:
    Spunky(U x){
        cout << x << " is not a character" << endl;
    }
};

template<> // this is template specialization when we wanna work with an specific type of data and do something with it...
class Spunky<char>{
public:
    Spunky(char x){
        cout << x << " is indeed a character!" << endl;
    }
};

template <class T>
T MyClass<T>::bigger(){
    return (first > second ? first : second);
}

int main(){
    double x = 7.50; 
    int y = 43;

    auto z = addCrap(x, y);
    cout << z << endl;

    cout << smaller(y, x) << endl; // it will display 7 without the decimals because it will take the first parameter data type passed to the function 

    MyClass <int>boo(50, 69); // we need to specify the type of data of the object that the template class is gonna subtitute with
    cout << boo.bigger() << endl;

    Spunky<int> obj1(7);
    Spunky<double> obj2(10.20);
    Spunky<char> obj3('q');
}