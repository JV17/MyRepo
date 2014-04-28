#include<iostream>

template <class T>
class DArray{
    T size;
public:
    DArray(T size){
        size = size;
    }
    ~DArray(){
        if (size)
            delete size;
    }
    int getSize(){
        return size;
    }
    int &operator[](T size){
        if(size)
            return 0;
        return size;
    }
    ostream& operator<<(ostream& out, T& x){
        out << x.getSize() << " " << x.getSize() << endl;
        return out;
    }
};