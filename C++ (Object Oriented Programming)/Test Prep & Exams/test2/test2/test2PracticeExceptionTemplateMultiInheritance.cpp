#include <string>
#include <queue>
#include <iostream>


class A
{
public:
    int a;
};


class B : virtual public A { public: B() { a = 5; } };
class C : virtual public A { public: C() { a = 10; } };


class D : public B, public C {};




class AA
{
public:
    int a;
};


template <class T = AA>
class BB : public T { public: BB() { a = 5; } };


template <class T = AA>
class CC : public T { public: CC() { a = 10; } };


class DD : public CC<BB<>> {};










struct BaseException
{
    char msg[200];
    BaseException(char* a) { strcpy(msg, a); }
};


struct MinorException : public BaseException
{
    MinorException(char* a) : BaseException(a) {}
};


class com
{
    int address;
    char* message;
public:
    com(int a, char* m) : address(a), message(0)
    {
        if (m)
        {
            message = new char[strlen(m) + 1];
            strcpy(message, m);
        }
    }
    const char* getMessage() { return message; }
};


class comMan
{
    std::queue<com*> cq;
public:
    void addMessage(com* a)
    {
        if (!a)
            throw(BaseException("Was passed a null pointer"));
        if (!a->getMessage())
        {
            throw(MinorException("Message was empty"));
        }
        cq.push(a);
    }
};


int main()
{
    D dddd;


    dddd.a = 10;


    DD addd;


    comMan a;
    bool active = true;
    com* rr[3];
    rr[0] = new com(11, "this is a test");
    rr[1] = new com(11, 0);
    rr[2] = 0;
    int it = 0;


    while (active)
    {
        try
        {
            a.addMessage(rr[it++]);
        }
        catch (BaseException a)
        {
            std::cout << a.msg << std::endl;
            return 1;
        }
        catch (MinorException a)
        {
            std::cout << a.msg << std::endl;
        }
    }
    return 0;
}

