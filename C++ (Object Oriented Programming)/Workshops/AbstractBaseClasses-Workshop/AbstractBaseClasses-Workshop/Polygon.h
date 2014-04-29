// Jorge E. Valbuena S.
// OOP344-A
// Week 5 - Abstract Base Classes (Workshop)
#pragma once
#ifndef _POLYGON_H_
#define _POLYGON_H_

#include<iostream>
#include<string.h>
#define SHAPE_NAME 30

using namespace std;

// Design and code an interface named Showable for displaying objects on an ostream.  Your class includes

	// 1. a pure virtual function named ostream& display(ostream& os) const that receives a reference 
	//	    to an ostream object and returns a reference to the same ostream object; and
	// 2. an insertion operator that calls the most derived version of display.

class Showable{
private:
	virtual ostream& display(ostream& os) const = 0;
	friend ostream& operator<<(ostream& out, Showable& S){
		return S.display(out);
	}
}; // end of Showable class


// Derive from Showable a class named Point that holds the coordinates of a single point in space.
// Upon instantiation, a Point object receives optionally the x and y coordinates of the point.
// Your class includes a definition of ostream& display(ostream& os) that inserts the coordinates 
// of the point into the output stream os in the format(x, y).Your design also includes two non - 
// member helper functions :

	// 1. an addition operator that receives references to two unmodifiable Point objects and 
		  //returns a Point object that holds the result of adding the coordinates of the two objects;
	// 2. a division operator that receives a reference to an unmodifiable Point object and an integer and 
		  //returns a Point object that holds the result of dividing the coordinates of the object by the integer value.

class Point: virtual private Showable{
private:
	float x;
	float y;
public:
	Point() : x(0.0), y(0.0){}
	Point(float _x, float _y) : x(_x), y(_y){}
	Point(Point& src){
		x = src.x;
		y = src.y;
	}
	ostream& display(ostream& os) const{
		os.setf(ios::fixed);
		os.precision(1);
		os << "Centroid (" << x << "," <<  y << ")";
		return os;
	}
	Point& operator=(const Point& assign){
		if (this != &assign){
			x = assign.x;
			y = assign.y;
		}
		return *this;
	}
	friend Point operator+(const Point& a, const Point& b){
		Point tmp;
		tmp.x = a.x + b.x;
		tmp.y = a.y + b.y;
		return tmp;
	}
	friend Point& operator+=(Point& c, Point& d){
		c.x += d.x;
		c.y += d.y;
		return c;
	}
	friend Point operator/(const Point& e, int div){
		Point tmp;
		tmp.x = e.x / div;
		tmp.y = e.y / div;
		return tmp;
	}
}; // end of Point class


// Derive from Showable a second abstract base class named Shape that holds the name of some 
// geometric shape.  You may assume that the name held occupies no more than 30 characters.  Your design includes

	// 1. a definition of display(ostream& os) that inserts the name into the output stream os; and
	// 2. a pure virtual function that returns the location of the centroid of the shape object.

class Shape : virtual public Showable{
private:
	char shapeName[SHAPE_NAME + 1];
protected:
	ostream& display(ostream& os) const{
		os << shapeName << ' ';
		return os;
	}
public:
	Shape(char* _name){
		strcpy(shapeName, _name);
	}
	virtual Point centroid() const = 0;
}; // end of Shape class


// Finally, derive from Shape a class named Polygon that holds information describing a polygon.  
// Upon instantiation, a Polygon object receives its name in a null-terminated C-style string and 
// the number of vertices.  The object allocates memory to hold the coordinates for the specified 
// number of vertices.  Since your design involves dynamic memory allocation, your class includes 
// an assignment operator, a copy constructor and a destructor. 

// Your class includes the following member functions :

	// 1. Point& operator()(int i) - a call operator that receives an integer and returns a reference 
		  //to the Point object that holds the coordinates for the vertex associated with the index received.
	// 2. ostream& display(ostream& os) const - a query that inserts the name of the polygon object 
		  //and the location of its centroid into the output stream os;
	// 3. Point centroid() const - a query that returns a Point object that holds the coordinates 
		  //of the centroid of the polygon.The formula for the coordinates of a centroid is the sum 
		  //of the coordinates of the vertices of the polygon divided by the number of vertices.

class Polygon : public Shape{
private:
	Point* vertex;
	int vertices;
	char sName[SHAPE_NAME + 1];
	void copy(Polygon& src){
		vertices = src.vertices;
		vertex = new Point[vertices];
		strcpy(sName, src.sName);
		for (int i = 0; i < vertices; i++)
			vertex[i] = src.vertex[i];
	}
public:
	Polygon(char* str, int v) : Shape(str), vertices(v){
		vertex = new Point[vertices];
		strcpy(sName, str);
	}
	Polygon(Polygon &obj) : Shape(obj.sName){
		copy(obj);
	}
	~Polygon(){
		if (vertex)
			delete[] vertex;
	}
	Point centroid() const{
		Point sum, add;
		for (int i = 0; i < vertices; i++) {
			if (i + 1 < vertices)
				sum = vertex[i] + vertex[++i];
			else
				sum = vertex[i] + vertex[i - 1];
			add += sum;
		}
		add = add / vertices;
		return add;
	}
	ostream& display(ostream& os) const {
		Point a = centroid();
		Shape::display(os);
		return a.display(os);
	}
	Point& operator()(int i) {
		return vertex[i];
	}
	Polygon& operator=(Polygon& assign) {
		if (this != &assign) {
			if (vertex) delete[] vertex;
			copy(assign);
		}
		return *this;
	}
}; // end of Polygon class
#endif