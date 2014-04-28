#include <vector>
#include <iostream>


int main()
{
    std::vector<int> a;
    a.push_back(0);
    a.push_back(1);
    //a.pop_back();
    a.front() = 10;
    a.back() = 8;
    //a.pop_back();
    a.front();


    //auto i = a.begin();
    //auto t = *i;


    //auto e = a.end();


    for (auto i = a.begin(), end = a.end(); i != end; i++)
        *i += 1;


    int cnt = 100;
    while (cnt--)
        a.push_back(cnt);



    for (auto i = a.begin(), end = a.end(); i != end; i++)
        std::cout << *i << std::endl;
    return 0;
}