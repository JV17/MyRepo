#include "TLL.h"
#include <iostream>


int main()
{
    LinkedList<int> a;
    LinkedList<float> b;
    LinkedList<char*> c;
    int d = 100;
    while (d--)
    {
        a.push_back(3);
        a.push_back(4);
        a.push_back(5);
        a.push_front(2);
        a.push_front(1);
        a.push_front(0);


        std::cout << a.getFront() << std::endl;
        a.pop_front();
        std::cout << a.getFront() << std::endl;
        a.pop_front();
        std::cout << a.getFront() << std::endl;
        a.pop_front();
        std::cout << a.getLast() << std::endl;
        a.pop_back();
        std::cout << a.getLast() << std::endl;
        a.pop_back();
        std::cout << a.getLast() << std::endl;
        a.pop_back();




        b.push_back(3.3);
        b.push_back(4.2);
        b.push_back(5.1);
        b.push_front(2.11);
        b.push_front(1.55);
        b.push_front(0.4);


        std::cout << b.getFront() << std::endl;
        b.pop_front();
        std::cout << b.getFront() << std::endl;
        b.pop_front();
        std::cout << b.getFront() << std::endl;
        b.pop_front();
        std::cout << b.getLast() << std::endl;
        b.pop_back();
        std::cout << b.getLast() << std::endl;
        b.pop_back();
        std::cout << b.getLast() << std::endl;
        b.pop_back();


        char herp[30] = "three";
        c.push_back(herp);
        strcpy(herp, "four");
        c.push_back(herp);
        strcpy(herp, "five");
        c.push_back(herp);
        strcpy(herp, "two");
        c.push_front(herp);
        strcpy(herp, "one");
        c.push_front(herp);
        strcpy(herp, "zero");
        c.push_front(herp);
        strcpy(herp, "error");


        std::cout << c.getFront() << std::endl;
        c.pop_front();
        std::cout << c.getFront() << std::endl;
        c.pop_front();
        std::cout << c.getFront() << std::endl;
        c.pop_front();
        std::cout << c.getLast() << std::endl;
        c.pop_back();
        std::cout << c.getLast() << std::endl;
        c.pop_back();
        std::cout << c.getLast() << std::endl;
        c.pop_back();




    }
    return 0;
}