#include <iostream>

template <class Y>
class nd {
    Y y;
    nd<Y> *nx;
public:
    nd(Y something, nd<Y> *another = NULL) { y = something; nx = another; }
    nd<Y> *setn(nd<Y> *another) { return nx = another; }
    nd<Y> *getn() { return nx; }
    Y get() { return y; }
};
template <class Y>
class twister {
    nd<Y> *beg;
    nd<Y> *end;
    int toggle;
public:
    twister() { toggle = 0; beg = end = NULL; }
    ~twister();
    void a(Y);

};
template <class Y>        // assume there WILL be enough memory
void twister<Y>::a(Y y) {
    if (beg == NULL)
        beg = end = new nd<Y>(y);
    else if (toggle)
        beg = new nd<Y>(y, beg);
    else
        end = end->setn(new nd<Y>(y, NULL));
    toggle = !toggle;
}
template <class Y>
twister<Y>::~twister() {
    nd<Y> *temp = beg;
    while (temp) {
        cout << temp->get();
        beg = beg->getn();
        delete temp;
        temp = beg;
    }
    cout << endl;
}

void foo(char s[]) {
    twister<char> t; // don't forget: this local variable get destroyed!
    for (int i = 0; s[i]; i++)
        t.a(s[i] - 1);
}

int main() {
    foo("PCVBSM");
    foo("FSTOUV");
    return 0;
}