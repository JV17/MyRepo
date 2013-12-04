#include <iostream>
/*
Topics:
1.Static
2.++u u++
3.operator overload
4.ostream
5.comma
6.init ctor
7.binary hex
8.virtual ctor diamond
9.exceptions
10.ios::seek files, tell, read, write
11.std::stackt queue 
12.fun ptr
13.binary file loading
14.binary signed
*/

int main(){
    //the comma operator
    for (int i = 0; i < e; i++,e--){
        ...
    }
    
    auto a = i++, e--; // the right value e-- is the final to be assign to the a


    //binary hex

    i = 10;
    e = 10u;
    f = 10.0;
    r = 10.0f;
    h = 0xA43;
    oct = 0621;

    //binary signed
    uchar 0-255     1111 1111
    char -128-127   0111 1111 = 127
                    1111 1111 = -1 // is the negatition of the value that you think it is...
                    0000 0000 = 0
                    1000 0000 = -128

    //bitwise operator
    0000 0000 << 1
    0000 0010 >> 1 //answer of above
    0000 0001 << 7 //answer of above
    1000 0000 >> 1 //answer of above
    1100 0000 >> 6 //answer of above
    1111 1111      //answer of above
    return 0;
}