#include <iostream>
#include <string>
using namespace std;


template <class TYPE>
class foo {
    TYPE x;
    bool(*cf)(TYPE);
public:
    foo(TYPE t, bool(*f)(TYPE) = NULL) { cf = f; *this = t; }
    foo<TYPE> &operator=(TYPE t) {
        if (cf && !cf(t))
            throw t;
        x = t;
        return *this;
    }
    TYPE bar() const { return x; }
};

class barr {
    char s[40];
    int n;
public:
    barr(const char *s1 = "toh") { strcpy_s(s, s1); n = strlen(s); }
    char operator[](int i) const { return s[i < n ? n - i - 1 : n]; }
};

template <class TYPE>
ostream &operator<<(ostream &os, foo<TYPE> f) { return os << f.bar(); }

ostream &operator<<(ostream &os, const barr &b)
{
    for (int i = 0; b[i]; i++)
        os << b[i];
    return os;
}

bool func(barr b) { return b[0] != '\0'; }

int main()
{
    int i = 0;
    try {
        foo<barr> f1("ae2"); // note: autocasts string to barr
        i++;
        cout << f1;
        i++;
        foo<barr> f2("ys", func);
        i++;
        cout << f2;
        i++;
        foo<barr> f3("", func);
        i++;
        cout << f3;
    }
    catch (int num) { cout << "int: " << num; }
    catch (barr b)  { cout << i << b; }
    cout << "me" << endl;
    return 0;
};