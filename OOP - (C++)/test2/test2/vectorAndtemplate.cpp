#include <vector>


int herp(char* a, int d = 0)
{
    if (!*a)
        return d;
    else
        return herp(a + 1, d + 1);
}


int derp(std::vector<int> a, bool toggle, int val)
{
    if (a.empty())
        return val;
    if (toggle)
    {
        val -= a.front();
        a.erase(a.begin());
    }
    else
    {
        val += a.back();
        a.pop_back();
    }
    return derp(a, !toggle, val);
}




enum test
{
    aaa = 0,
    bbb = 2,
    ccc = 4,
    ddd = 8,
    eee = 16
};


template <test T>
class Test
{
private:
    int id;
    static int next;
public:
    Test() : id(next++) {}
};


template <test T>
int Test<T>::next = 0;


template <class T>
struct Node
{
    Node* next;
    T val;
    Node(T a) : val(a), next(0) {}
};


template <>
Node<char*>::Node(char* a)
{
    val = new char[strlen(a) + 1];
    strcpy(val, a);
    next = 0;
}


template<class T>
void doStuff(int a)
{
    T ab = 0;
    //std::cout << a << std::endl;
}


template<class T>
T add(T a, T b)
{
    return a + b;
}


template <test T>
class Break {};


template <>
class Break<aaa>
{
    int a;
    int b;
public:
    Break(int r, int e) : a(r), b(e) {}
};




template <>
class Break<bbb>
{
    int a;
    int b;
    char n;
public:
    Break(int r, int e) : a(-r), b(-e), n('n') {}
};






int main()
{
    Break<aaa> po(10, 12);
    Break<bbb> op(21, 12);




    Test<aaa> a;
    Test<aaa> b;
    Test<bbb> c;
    Test<ccc> d;
    Test<ddd> e;
    Test<ccc> f;
    Test<aaa> g;


    Node<int> aadd(10);


    auto rr = new Node<int>(10);


    int daaa = add(21, 23);
    auto dbbb = add<float>(21.3f, 32.12);


    doStuff<int>(1);
    doStuff<float>(1);
    /*
    std::vector<int> ab;
    int r = 20;
    while(r--)
    a.push_back(r);


    auto dd = derp(a, true, 0);


    char str[] = "This is a test";


    auto ca = herp(str);*/


    return 0;
}