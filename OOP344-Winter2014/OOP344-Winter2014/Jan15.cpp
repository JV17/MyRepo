//Quizz solution...
#include<iostream>

//Constructor...
class Badger(){


public:
    Badger(){
        _storage = NULL;
    }

    Badger(const char* c){
        _storage = 0;
        set(c);
    }

    Badger(const Badger& src){
        _storage = 0;
        set(src._storage);
    }

    ~Badger(){
        if (_storage)
            delete[] _storage;
    }

    void set(const char* c){
        if (_storage){
            delete[] _storage;
            _storage = NULL;
        }
        if (c){
            _storage = new char[strlen(c)+1];
            strcpy(_storage, c);
        }
    }
    void print() const{
        if (_storage)
            std::cout << _storage;
    }

    int lenght() const{
        if (_storage)
            return strlen(_storage);
        return 0;
    }
};


int main(){

    return 0;
}