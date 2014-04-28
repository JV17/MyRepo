// Jorge E. Valbuena S.
// OOP344A - Template Workshop
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

template<typename E = double>
class Array{
private:
	E* ptr;                                 // pointer to first element of array
	unsigned int size;                      // size of the array
	E Dummy;
public:
	Array(int);							    // default constructor
	Array(const Array &);                   // copy constructor
	~Array();                               // destructor
	unsigned int getSize() const;                    // return size of array
	const Array& operator=(const Array &);  // assign arrays
	E& operator[] (unsigned int i);			// Overloaded subscript operator
	template<typename T>
	friend void sort(Array<T> &array);		// sorts elements of the array
};


// Default constructor for class Array
template <typename E>
Array<E>::Array(int arraySize) : size(arraySize){
	ptr = new E[size];						 // create space for array
};


// Copy constructor for class Array
template <typename E>
Array<E>::Array(const Array<E> &init) {
	size = init.size;
	ptr = new E[size];

	for (int i = 0; i < size; i++)
		ptr[i] = init.ptr[i];
};


// Get the size of the array
template<typename E>
unsigned int Array<E>::getSize() const { return size; };


// Destructor for class Array
template <typename E>
Array<E>::~Array() {
	delete[] ptr;
	ptr = NULL;
};


// Overloaded subscript operator, terminates if subscript out of range error
template <typename E>
E& Array<E>::operator[](unsigned int i) {
	if (i >= 0 && i < size)
		return ptr[i];
	else
		return Dummy;
};


// Overloaded assignment operator
template <typename E>
const Array<E>& Array<E>::operator=(const Array<E>& right) {
	if (&right != this) {               // check for self-assignment
		delete[] ptr;
		size = right.size;
		ptr = new E[size];

		for (int i = 0; i < size; i++)
			ptr[i] = right.ptr[i];
	}
	return *this;
};


// CHALLENGE function to sorts the elements in an Array object
template <typename T>
void sort(Array<T> &array){
	for (unsigned int i = 0; i < array.getSize(); i++){ // using unsigned int to avoid compile warnings when the values are compare
		for (unsigned int j = 0; j < array.getSize() - 1; j++){
			if (array[j] > array[j + 1]){
				auto temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
};

#endif