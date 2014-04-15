#include <iostream>

int main(){

    unsigned int x = 1;
    int a = 1;

    a = a << 1;
    x = x << 1;

    std::cout << a << " " << x << std::endl;

    a = a >> 1;
    x = x >> 1;

    std::cout << a << " " << x << std::endl;

    return 0;
}