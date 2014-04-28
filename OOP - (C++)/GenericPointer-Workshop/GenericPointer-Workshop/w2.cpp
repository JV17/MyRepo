// Jorge E. Valbuena S.
// OOP344A
#include <iostream>

 typedef struct{
    int a;
    int b;
    double c;
    double d;
} myIns;

 template <class T>
 void swap(T& x, T& y){ // better function and simplier to swap different data types
     T temp;
     temp = x;
     x = y;
     y = temp;
 }

 /*
void swap(void *n1, void *n2, int size){ // swaps every data type
    
    unsigned char *sa = (unsigned char*)n1;
    unsigned char *sb = (unsigned char*)n2;
    unsigned char s;

    for (int i = 0; i < size; i++) { // swapping the values
        s = sa[i];
        sa[i] = sb[i];
        sb[i] = s;
    }
}
*/

int main(){

    std::cout << "  W2 - Generic Pointers " << std::endl; // displaying program header

    int a = 2;
    int b = 3;
    swap(a, b); // calling swap function
    std::cout << "\tA => " << a << std::endl; // displaying results
    std::cout << "\tB => " << b << std::endl; // displaying results
    
    double x = 10.21;
    double y = 15.22;
    swap(x, y); // calling swap function
    std::cout << "\tX => " << x << std::endl; // displaying results
    std::cout << "\tY => " << y << std::endl; // displaying results

    short c = 1;
    short d = 5;
    swap(c, d); // calling swap function
    std::cout << "\tC => " << c << std::endl; // displaying results
    std::cout << "\tD => " << d << std::endl; // displaying results

    unsigned long long e = 1000;
    unsigned long long f = 2000;
    swap(e, f); // calling swap function
    std::cout << "\tE => " << e << std::endl; // displaying results
    std::cout << "\tF => " << f << std::endl; // displaying results

    myIns myA = { 15, 17, 20.0, 40.0 };
    swap(myA.a, myA.b); // calling swap function
    std::cout << "\tmyA.a => " << myA.a << std::endl; // displaying results
    std::cout << "\tmyA.b => " << myA.b << std::endl; // displaying results

    swap(myA.c, myA.d); // calling swap function
    std::cout << "\tmyA.c => " << myA.c << std::endl; // displaying results
    std::cout << "\tmyA.d => " << myA.d << std::endl; // displaying results

    system("pause");
    return 0;
}