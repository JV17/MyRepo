namespace Color{
    enum ColorEnum
    {
        RED = 6, // allows to keep inside the typedef so if you are using a++ 
        GREEN = 10, // eg. Color a; a++ es igual a RED and then GREEN until get BLUE and goes back to the first
        BLUE // this will be 11.. becasue the keep the sequence 
    };
};

Color::RED; // need to use namespace to be able to use legaly the enum members..

// nested classes...

template<class T>
class A{
public:// if makes it public everyone can access it.. with A::B
    class B
    {}
};

// working with templates classes could be totally different so to work with it..
typename A<int>::B a;
