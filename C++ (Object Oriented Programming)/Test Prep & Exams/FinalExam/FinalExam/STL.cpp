#include <iostream>
#include <iomanip>
#include <list>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <bitset>

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

using namespace std;

class Student{
	string _name;
public:
	Student(const char* name) : _name(name){};
	friend ostream& operator<<(ostream& out, const Student& other){
		out << "[Student " << other._name << "]";
		return out;
	}
};


int main(){

	list<Student> a;

	a.push_back("Jorge");
	a.push_back("Juan");
	a.push_back("Pedro");
	a.push_back("Lucia");


	for (list<Student>::iterator it = a.begin(); it != a.end(); ++it)
		cout << *it << endl;
	

	cout << "\n" << endl;
	system("pause");
	return 0;
}