// Jorge E. Valbuena S.
// OOP344A
// Workshop 3 - Callback Functions

#include <iostream>
using namespace std;

/* Write a callback function named isEven() with the following parameters:

a generic pointer to an input value
a generic pointer to an output value

Your function works with ints and returns true if the input value is even, false otherwise.
Moreover, if the value is even, your function adds the value to that pointed to by the second
parameter. */

bool isEven(void* x, void* z){
	// casting x
	static int a;
	a = *static_cast<int*>(x);

	// casting z
	static int b;
	b = *static_cast<int*>(z);

	if ((a % 2) == 0) { // finding even numbers
		b += a;
		*static_cast<int*>(z) = b; // adding the number of elements 
		return true;
	}
	else {
		return false;
	}
}

/* Write another callback function named isPrime() with the following parameters:

a generic pointer to an input value
a generic pointer to an output value

Your function works with ints and returns true if the input value is a prime number, false otherwise.
Moreover, if the value is prime, your function adds the value to that pointed to by the second
parameter. */

bool isPrime(void* x, void* z){
	// casting x
	static int a;
	a = *static_cast<int*>(x);

	// casting z
	static int b;
	b = *static_cast<int*>(z);

	// looping to check if not prime
	for (int i = 2; i < a; i ++){
		if (a % i == 0)
			return false;
	}
	
	// prime found :) and adding the number of elements
	b += a;
	*static_cast<int*>(z) = b;
	return true;

}


/* Write an enumeration function named sum() with the following parameters:


    a generic pointer
    an int that holds the number of elements in the array pointed to
    an int that holds the size in bytes of a single element
    a pointer to a function that has two generic pointer parameters and returns a bool
    a generic pointer

Your function moves through the array pointed to by the first parameter element by element.  
For each element, your function calls the function pointed to and passes the element's address along 
with the address stored in the last parameter.  Your function returns the number of elements for 
which the function pointed to returned true. 

Since your first function parameter is a generic pointer and your function can handle any type, 
you will need to cast the address of the input array to the address of a chars in order to move 
from one element to the next.  */

int sum(void* x, int n, int s, bool(*f)(void*, void*), void* z){
	// casting x
	char *arr = static_cast<char*>(x);
	
	// intiger to count the elements founds
	int count = 0;
	
	// looping to through the array and calling the function pointer
	for (int i=0; i < n-1; i++){
		arr += s;
		count += f(arr, z);
	}

	// returning the count of elements found in even and in prime
	if ((n % 2) == 0)
		return count;
	else
		return count;

}

void display(const char* c, int* x, int f, int t, int n) {
    cout << f << ' ' << c << " found in {";
    for (int i = 0; i < n - 1; i++)
        cout << x[i] << ',';
    cout << x[n - 1] << "} sum is " << t << endl;
}

int main() {
    int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
    int e = 0, p = 0, n;

	// added some nice welcoming to the program
	cout << "\n\tWorkshop#5 OOP344A(Winter2014)\n" << endl;

    n = sum(a, 11, sizeof(int), isEven, &e);
    display("evens", a, n, e, 11);

    n = sum(a, 11, sizeof(int), isPrime, &p);
    display("primes", a, n, p, 11);

	// added a nice footer to the program
	cout << endl;
	cout << "\t" << (char)0xA9 << "Jorgedeveloper.com, 2014\n" << endl;
	cout << endl;

    //system("pause");
    return 0;
}