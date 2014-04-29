#include <iostream>
#include <string>
#include <vector>

#define NEWLINE std::cout << std::endl
#define QN(n,m) std::cout << "Part " << n << " [" << m << " Marks]---------" << std::endl

enum Type { FUSED = 1, WATER, ELECTRIC, FIRE, GRASS };

class Exception{
public:
    char msg[100];
    Exception() {}
    Exception(char* a) { strcpy_s(msg, a); }
    char* operator*() { return msg; }
};

template <Type T>
class TypedException : public Exception{
public: TypedException(char* a) : Exception(a) {}
};

class AdvancedGrassException : public TypedException<GRASS> {
public: AdvancedGrassException(char* a) : TypedException<GRASS>(a) {}
};

template <Type T>
struct ElementalCatalyst{
    static unsigned int next;
    unsigned int id;
    ElementalCatalyst() { id = (next += T); }
    void Throw() { throw(TypedException<T>("Access Violation")); }
};

template <Type R>
unsigned int ElementalCatalyst<R>::next = 0;

template <class T, class R = void, class L = void>
class Beast : public T{
    std::string name;
public:
    Beast(std::string n) : name(n) {}
    void printInfo() { std::cout << "Beast " << id << ": " << name << std::endl; }
    void printMaterial() { Throw(); }
};

template <class R, class L>
class Beast<ElementalCatalyst<FUSED>, R, L> : public R, public L{
    std::string material[2];
    std::string name;
    unsigned int fID;
public:
    Beast(std::string n, std::string m1, std::string m2) : name(n),
        fID(++ElementalCatalyst<FUSED>::next)
        { material[0] = m1; material[1] = m2; }
    void printInfo() { std::cout << "Fused Beast " << fID << ": " << name << std::endl; }
    void printMaterial() { std::cout << "Beast Materials: " << R::id << " - " << material[0] << " / " << L::id << " - " << material[1] << std::endl; }
};

int rend(int a, int b, int c, bool d = false){
    std::cout << "Rend! " << a << " " << b << " " << c << " " << d << std::endl;
    if (a < b || a < c)
        throw(AdvancedGrassException("B is out of range!"));
    if (d){
        if (a == b)
            return c;
        return rend(a, b + 1, c, !d);
    }
    else{
        if (a == c)
            return b;
        return rend(a, b, c + 1, !d);
    }
    std::cout << "Whats that smells?" << std::endl;
}

void cheer(std::vector<std::string> w){
    bool toggle = true;
    auto i = w.begin();
    auto e = w.end() - 1;
    while (i <= e){
        if (toggle)
            std::cout << *i++;
        else
            std::cout << *e--;
        toggle = !toggle;
    }
    std::cout << std::endl;
}

void confuse(){
    unsigned int victim = 255u;
    victim = victim << 3;
    victim = victim >> 2;
    victim = (170u >> 1) & victim;
    victim = (~127u) | victim;
    victim = 7u ^ victim;
    victim = victim >> 7 | victim << 1;
    std::cout << "Survey Says: " << static_cast<int>(victim) << std::endl;
}

void yellowBall() { throw(TypedException<GRASS>("Which hand will catch?")); }

void blueBall(){
    try{ throw(TypedException<FIRE>("Blue to Red")); }
    catch (TypedException<FIRE> e) {
        std::cout << "Fire ";
        yellowBall();
    }
}

void redBall(){
    try { blueBall(); }
    catch (TypedException<GRASS> e) {
        std::cout << "Grass ";
        throw(AdvancedGrassException("Red vs Adv Green"));
    }
}

void juggle(){
    try{
        try{ redBall(); }
        catch (AdvancedGrassException e) {
            std::cout << "Advanced ";
            redBall();
        }
    }
    catch (Exception e) {
        std::cout << "Base " << std::endl;
    }
}


int main(){
    auto i = 10u;
    while (i--){
        try{
            if (i == 8){
                QN(1,'2');
                Beast<ElementalCatalyst<FIRE>> fb("Ifrit");
                fb.printInfo();
                fb.printMaterial();
            }
            if (i == 7){
                QN(2,'3');
                Beast<ElementalCatalyst<WATER>> wb("Chaos");
                Beast<ElementalCatalyst<WATER>> db("Dyria");
                wb.printInfo();
                wb.printMaterial();
                db.printInfo();
                db.printMaterial();
            }
            if (i == 6){
                QN(3,'3');
                Beast <ElementalCatalyst<FUSED>, ElementalCatalyst<WATER>,
                    ElementalCatalyst <ELECTRIC>> fb("Barox", "Dyria", "Ryu");
                fb.printInfo();
                fb.printMaterial();
            }
            if (i == 5){
                QN(4,'2');
                std::cout << "Results! " << rend(15, 14, 9) << std::endl;
            }
            if (i == 4){
                QN(5,'1');
                std::cout << "Results! " << rend(342, 123, 435) << std::endl;
            }
            if (i == 3){
                QN(6,'1');
                std::vector<std::string> w;
                w.push_back("Weekend ");
                w.push_back("Starts ");
                w.push_back("Friday ");
                w.push_back("This ");
                w.push_back("Madness!! ");
                cheer(w);
            }
            if (i == 2){
                QN(7,'2');
                confuse();
            }
            if (i == 1){
                QN(8,'2');
                juggle();
            }
        }
        catch (TypedException<GRASS> e) {
            std::cout << "Grass Exception Caught: " << *e << std::endl; }
        catch (TypedException<FIRE> e) {
            std::cout << "Fire Exception Caught: " << *e << std::endl; }
        catch (TypedException<ELECTRIC> e) {
            std::cout << "Electric Exception Caught: " << *e << std::endl; }
        catch (AdvancedGrassException& e) {
            std::cout << "Adv Grass Exception Caught: " << *e << std::endl; }
        catch (Exception& e) {
            std::cout << "Base Exception Caught: " << *e << std::endl; }
        NEWLINE;
    }
    return 0;
}