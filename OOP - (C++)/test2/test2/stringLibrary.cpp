#include <cstring>
#include <iostream>
#include <string>


class Foo
{
private:
    char* string;
protected:
public:
    Foo(char* a = 0)
    {
        if (a)
        {
            string = new char[strlen(a) + 1];
            strcpy(string, a);
        }
        else
            string = 0;
    }
    ~Foo()
    {
        if (string)
            delete[] string;
    }
    operator char*()
    {
        return string;
    }
    operator bool()
    {
        if (string)
            return true;
        return false;
    }
    operator std::string()
    {
        return std::string(string);
    }
};


void cout(std::string a)
{
    std::cout << a << std::endl;
}


int main()
{
    std::string r;
    r = "this is a test";
    r += " and this is too";
    char rs = r[4];
    cout(r.c_str());
    Foo a("something");
    Foo b("");
    Foo c(0);
    Foo d;
    if (a)
    {
        cout(a);
    }
    if (b)
    {
        cout(a);
    }
    if (c)
    {
        cout(a);
    }
    if (d)
    {
        cout(a);
    }


    return 0;
}

