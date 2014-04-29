#include <string.h>
#include <iostream>

#define DOWN

namespace Quick
{
    typedef float retVal;
    void out(retVal a) { std::cout << a << std::endl; }
    retVal fire(char* a)
    {
        if (strcmp(a, a + 1) > 0)
            return (retVal)10 / 4;
        else
            return (retVal)4 / 10;
    }
#define OUT(a) {std::cout << a << std::endl;}
}
namespace Slow
{
    typedef int retVal;
    void out(retVal a) { std::cout << "The output is: \"" << a << "\"" << std::endl; }
    retVal water(char* a)
    {
        if (strcmp(a, a + 1) > 0)
            return (retVal)10 / 4;
        else
            return (retVal)4 / 10;
    }
#define OUT(a) {std::cout << "The output is: \"" << a << "\"" << std::endl;}
}


int lightning(char* a)
{
    char* b = a;
    while (*b) b++;
    return b - a;
}


int main(int argc, char* argv[])
{
    void* funcs[] = { Quick::fire, Slow::water, lightning };
#ifndef DOWN
    for (int i = 0; i < argc; i++)
#else
    for (int i = 3; i >= 0; i--)
#endif
    {
        if (!strcmp(argv[i], "one"))
        {
            auto r = (*(Slow::retVal(*)(char*))(funcs[1]))(argv[i]);
            Slow::out(r);
        }
        else if (!strcmp(argv[i], "two"))
        {
            auto r = (*(Quick::retVal(*)(char*))(funcs[0]))(argv[i]);
            Quick::out(r);
        }
        else if (!strcmp(argv[i], "three"))
        {
            auto r = (*(int(*)(char*))(funcs[2]))(argv[i]);
            OUT(r);
        }
        else
        {
            OUT(argv[i]);
        }
    }
    return 0;
}
