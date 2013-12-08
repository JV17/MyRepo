#include <string.h>
#include <iostream.h>

template <class X, class Y>
X &operator+=(X &x, const Y &y) { return x = x + y; }

class look {
public:
    virtual void see(ostream &os) const = 0;
};

ostream &operator<<(ostream &os, const look &l)
{
    l.see(os);
    return os;
}

class monster : public look {
    char s[31];
public:
    monster(char *str = "ogh") { strcpy(s, str); }
    void see(ostream &os) const { os << s; }
    monster operator+(int n) {
        monster rc(*this);
        for (int i = 0; rc.s[i]; i++) {
            cout << rc.s[i];
            rc.s[i] += n + i;
            cout << rc.s[i];
        }
        cout << '\n';
        return rc;
    }
};

template <class X>
class pocket : public look {
    X x;
public:
    pocket(char *st = NULL, int n = 1) {
        if (st)
            x = X(st); //note: else default X!
        x += n;
    }
    void see(ostream &os) const { os << x; }
};

int main() {
    pocket<monster> poke;
    pocket<monster> mon("abfr", 0);
    cout << "poke" << "mon" << '\n';
    cout << poke << mon << '\n';
    return 0;
}
