#include <iostream>
#include <cstring>
using namespace std;
class MyExp{
    char message[256];
public:
    MyExp(const char *Message = ""){
        strncpy_s(message, Message, 256);
        message[255] = 0;
    }
    ostream &print(ostream &os){
        return os << message;
    }
};
ostream& operator<<(ostream& os, MyExp& e){
    return e.print(os);
}
class BadNum :public MyExp{
public:
    BadNum(const char* m) :MyExp(m){}
};

class BadInt :public BadNum{
public:
    BadInt(const char* m) :BadNum(m){}
};
class BadMark :public BadInt{
public:
    BadMark(const char *m = "") :BadInt(m){}
};


int main(){
    int i;
    for (i = 1; i<6; i++){
        try{
            if (i % 4 == 0) throw BadInt("N/4");
            else if (i % 3 == 0) throw BadNum("N/7");
            else if (i % 5 == 0) throw BadMark("N/5");
            else cout << i << endl;
            cout << "------------" << endl;
        }
        catch (BadMark& bm){
            cout << "BM:" << bm << endl;
        }
        catch (BadInt& bi){
            cout << "BI:" << bi << endl;
        }
        catch (MyExp& me){
            cout << "ME:" << me << endl;
        }
        catch (BadNum& bn){
            cout << "BN:" << bn << endl;
        }
    }
    return 0;
}