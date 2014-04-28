// Class Nov. 18
// Implicit Cast
#include<cstring>
#include<iostream>
#include<string>

class Foo
{
private:
    char* string;

public:
    Foo(char* a = 0){
        if(a){
            string = new char[strlen(a)+1];
            strcpy(string, a);
        } else {
            string = 0;
        }
    }
    ~Foo(){
        if(string)
            delete [] string;
    }
    operator bool(){
        if(string)
            return true;
        return false;
    }
    operator char*(){
        return string;
    }
    operator std::string(){
        return std::string(string);
    }
};

void cout(std::string a){
    std::cout << a << std::endl; 
}

int main(){
    std::string r;
    r = "this is a test";
    r += " and this is too";
    char rs = r[4];
    cout(r.c_str()); 
    Foo a("Something");
    Foo b("");
    Foo c(0);
    Foo d;
    if(a){
        cout(a); //std::cout << a << std::endl;
    }
    if(b){
        cout(b); //std::cout << b << std::endl;
    }
    if(c){
        cout(c); //std::cout << c << std::endl;
    }
    if(d){
        cout(d); //std::cout << d << std::endl;
    }

    return 0;
}