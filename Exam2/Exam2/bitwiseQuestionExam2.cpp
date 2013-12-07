#include <iostream>

enum Access{
    NONE,
    VIEW,
    EDIT = 2,
    NEW = 4,
    DELETE = 8,
    EDIT_ALL = 16,
    DELETE_ALL = 32
};

class Accessor{
public:
    unsigned int access=0;
    unsigned int getAccess(){
        return access;
    }
};

class Prof : public Accessor{
public:
    Prof(){
        access = access | VIEW; // to modified the bit corresponding to the access level | permission
        access = access | EDIT; // 0 1 | 1 0 = 1 1;
        access = access | EDIT_ALL;
        access = access | NEW;
        access = access | DELETE;
        access = access | DELETE_ALL;
    }
};

class Student : public Accessor{
public:
    Student(){
        access = access | VIEW;
        access = access | EDIT;
        access = access | NEW;
        access = access | DELETE;
    }
};

class Unkown : public Accessor{
public:
    Unkown(){
        access = access | VIEW;
    }
};

bool Validate(Accessor* ph, Access p){
    return (ph->access & p); // chequeo de que el 1 este activado en los dos
}

int main(){
   
    Prof a;
    Student b;
    Unkown c;

    std::cout << a.getAccess() << std::endl;
    std::cout << b.getAccess() << std::endl;
    std::cout << c.getAccess() << std::endl;

    std::cout << Validate(&(Accessor)c, DELETE) << std::endl;

    return 0;
}