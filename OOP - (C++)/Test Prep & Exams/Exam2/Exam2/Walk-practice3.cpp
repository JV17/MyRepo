#include <iostream>
using namespace std;

class moveable {
public:
    virtual int next() = 0;
    virtual void down() = 0;
    virtual void across() = 0;
};
class coord : public moveable {
    int r;
    int c;
    bool cols;
public:
    coord(int rr = 0, int cc = 0) { r = rr; c = cc; cols = true; }
    int next() { return cols ? ++c : ++r; } // N.B. only one ++ happens!
    void down()     { cols = false; }
    void across()   { cols = true; }
    int row() const { return r; }
    int col() const { return c; }
    // Note that = doesn't copy cols on purpose:
    coord &operator=(coord x) { r = x.r; c = x.c; return *this; }
};
template <class XXX>
class toodee : public moveable {
    XXX *data;
    coord sz;
    coord pos;
public:
    toodee(int r, int c, XXX val) {
        data = new XXX[r * c];     // assume allocation succeeds
        for (int i = 0; i < r * c; i++)
            data[i] = val;
        sz = coord(r, c);
    }
    ~toodee() { delete[] data; }
    friend ostream &operator<<(ostream &os, const toodee<XXX> &x) {
        for (int i = 0; i < x.sz.row() * x.sz.col(); i++) {
            if (i > 0 && i % x.sz.col() == 0)
                os << endl;
            os << x.data[i];
        }
        return os;
    }
    void line(int len, XXX val) {
        for (int i = 0; i < len; i++)
            *this << val;
    }
    toodee<XXX> &operator<<(XXX x) {
        data[pos.row()*sz.col() + pos.col()] = x;
        next();
        return *this;
    }
    toodee<XXX> &operator<<(coord c) { pos = c; return *this; }
    int next()                       { return pos.next(); }
    void down()                      { pos.down(); }
    void across()                    { pos.across(); }
};


int main()
{
    toodee<char> x(10, 10, ' ');

    x.down();
    x << coord(2, 0);
    x.line(6, '|');
    x << coord(4, 4);
    x.line(3, '|');
    x << coord(2, 9);
    x.line(6, '|');
    x << coord(1, 1) << '/' << coord(1, 8) << '\\';
    x << coord(8, 1) << '\\' << coord(8, 8) << '/';
    x << coord(3, 2) << 'X' << coord(3, 7) << 'X';
    x << coord(6, 5) << '_' << coord(7, 7) << '/';
    x.across();
    x << coord(7, 2) << '\\';
    x.line(4, '_');
    x << coord(0, 2);
    x.line(6, '-');
    x << coord(9, 2);
    x.line(6, '-');
    cout << x;
    return 0;
}