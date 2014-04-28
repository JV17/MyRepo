// Jorge E. Valbuena S.
// OOP344A - Template Workshop
#include "Array.h"

int main(){
	cout << endl;
	cout << "OOP344A - Workshop#3 (templates)" << endl;
	cout << endl;
	cout << "First Program\n(without sorting)" << endl;

	Array<int> x(3);
	for (int i = 0; i < 3; i++)
		x[i] = 9 - i;
	x[-1] = 99;
	for (int i = 0; i < 6; i++)
		cout << "    " << x[i] << endl;

	Array<> y(2);
	y[0] = 2.1;
	y[1] = 1.1;
	for (int i = 0; i < 2; i++)
		cout << "    " << y[i] << endl;
	
	cout << "\nSecond Program\n(with sorting)" << endl;

	Array<int> w(3);
	for (int i = 0; i < 3; i++)
		w[i] = 9 - i;
	w[-1] = 99;
	sort(w);
	for (int i = 0; i < 6; i++)
		cout << "    " << w[i] << endl;

	Array<> z(2);
	z[0] = 2.1;
	z[1] = 1.1;
	sort(z);
	for (int i = 0; i < 2; i++)
		cout << "    " << z[i] << endl;

	cout << endl;
	cout << (char)0xA9 << "Jorgedeveloper.com, 2014" << endl;
	cout << endl;

    system("pause");
    return 0;
}