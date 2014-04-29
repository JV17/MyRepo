// JorgeDeveloper.com
#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

int main(){

	list<string> str;
	
	list<string> a;

	a.push_front("Swapped! :)");
	a.push_front("Filling up with some stuff! :)");
	a.push_back("LAST? :)");

	cout << "\n/***************** C++ STL :) **********************************\\\n\n" << endl;
	
	str.push_front("Im loving it, so much easier than writing your own list.. lol..");
	str.push_front("Testing the C++ STL");
	str.push_front("New Front?");
	str.push_back("BACK?");
	str.push_back("Deleted back :(");
	str.push_front("Deleted front :(");

	for (list<string>::iterator it = str.begin(); it != str.end(); ++it)
		cout << *it << endl;

	str.pop_front();
	str.pop_back();

	cout << "\n\n/***************** After Deletes ********************************\\\n\n" << endl;

	for (list<string>::iterator it = str.begin(); it != str.end(); ++it)
		cout << *it << endl;


	cout << "\n\n/***************** Sorting & other fun stuff ***********************\\\n" << endl;

	str.sort();

	cout << "\t\t\tSorting..!" << endl;

	for (list<string>::iterator it = str.begin(); it != str.end(); ++it)
		cout << *it << endl;

	str.swap(a);

	cout << "\t\t\tSwapping..!" << endl;

	for (list<string>::iterator it = str.begin(); it != str.end(); ++it)
		cout << *it << endl;

	cout << endl;

	system("pause");
	return 0;
}