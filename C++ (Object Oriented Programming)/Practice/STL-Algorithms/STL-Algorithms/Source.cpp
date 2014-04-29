#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<string>

using namespace std;

void myfunction(int n) {  
	cout << ' ' << n;
}

int main(){
	int array[] = { 10, 20, 30, 40, 50, 30, 30 };
	//int *ptr;
	
	vector<int> num;

	num.push_back(10);
	num.push_back(20);
	num.push_back(30);

	cout << "Inside my vector:" << endl;
	for_each(num.begin(), num.end(), myfunction); // loops through the elements
	cout << "\n" << endl;

	vector<int> myvec (array, array + 4); // ask the meaning of array +4 & why cant use a vector 
										  // that you have pushed elements in it...
	vector<int>::iterator it;

	it = find(myvec.begin(), myvec.end(), 30); // iterates through the list and finds the element after the one specify
	++it;
	cout << "Element after : " << *it << endl;


	int mycount = count(array, array + 7, 30); // counting an specific element
	cout << "\nElement 30 appers: " << mycount << " times." << endl;
	
	cout << "\nReplaced 30 for 31:";
	replace(myvec.begin(), myvec.end(), 30, 31);
	for (vector<int>::iterator i = myvec.begin(); i != myvec.end(); ++i)
		cout << ' ' << *i;
	cout << endl;

	vector<int> tmpvec(7);
	cout << "\n Copied my vector:";
	copy(array, array + 7, tmpvec.begin());
	for (vector<int>::iterator x = tmpvec.begin(); x != tmpvec.end(); ++x)
		cout << ' ' << *x;
	cout << endl;

	system("pause");
	return 0;
}