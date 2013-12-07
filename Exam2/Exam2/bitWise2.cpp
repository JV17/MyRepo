#include <iostream>

class Bits{
    unsigned int a = 0;
    char* b;
public:
    Bits(unsigned int p){
        a = p;
        b = new char[sizeof(int)*8+1];
    }
    operator unsigned int() const{
         return a;
    }
    operator char*() const{
        b[32] = 0;
        for (int x = (sizeof(int) * 8) -1; x >= 0 ; x--){
            b[x]= (a & (1 << (31-x))?'1':'0');
        }
        return b;
    }
    void setBits(int from, int to, bool bitVal);
    ~Bits(){
        if (b)
            delete[] b;
    }
};

// va afuera de la clase porque es overload de ostream y no the Bits
std::ostream& operator<<(std::ostream& out, const Bits& z){
    out << (const char*)z;
    return out;
}

int main(){
    unsigned int a = 0xf0f0f0f0;
    Bits B(a);
    std::cout << (unsigned int)B << ": " << B << std::endl;

    //Bits a(10);

    //std::cout << a << std::endl;

    return 0;
}