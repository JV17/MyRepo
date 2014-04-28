#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
using namespace std;
#include "Polygon.h"

int main() {

	// added some nice welcoming to the program
	cout << "\n Workshop#5 OOP344A(Winter2014)\n" << endl;
	cout << "------------OUTPUT------------" << endl;

	Polygon rect("Rectangle", 4);
	rect(0) = Point(1, 1);
	rect(1) = Point(2, 1);
	rect(2) = Point(2, 4);
	rect(3) = Point(1, 4);

	cout << ' ' << rect << endl;

	// added a nice footer to the program
	cout << "------------------------------" << endl;
	cout << endl;
	cout << ' ' << (char)0xA9 << "Jorgedeveloper.com, 2014\n" << endl;
	cout << endl;

	system("pause");
	return 0;
}