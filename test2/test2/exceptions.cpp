#include<iostream>
using namespace std;

int main(){
    /*
    try{
        int momAge = 50;
        int sonsAge = 34;

        if (sonsAge > momAge){
            throw 99;
        }
    }
    catch (int x){
        cout << "son cannot be older than mom, ERROR NUMBER: " << x << endl;
    }
    */

    try{
        int num1;
        cout << "enter first number: ";
        cin >> num1;
        cout << endl;

        int num2;
        cout << "enter second number: ";
        cin >> num2;
        cout << endl;

        if (num2 == 0)
            throw 0;

        cout << "The result: " << num1 / num2 << endl;
    }
    catch (...){ // to catch any type of errors.. can be int or char or double....
        cout << "you cant divide by 0" << endl;
    }
}