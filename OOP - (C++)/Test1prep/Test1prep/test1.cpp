#include <iostream>
#include <string>
#include <vector>
using namespace std;
namespace mySpace{

#define WEEK myStr
#undef WEEK
#define SUM(a,b) a+b // Why is it global when is under a namespace
#define MULTI(a,b) (a)*(b)	// Why is it global when is under a namespace

#define SWAP(x,z,t) { \
	t temp = x; x = z; z = temp; \
	std::cout << " (A) -> " << x; \
	std::cout << "   (B) -> " << z << std::endl; \
}

	int a = 0;
	int b = 0;

	std::string myStr;

	void display(const char* str){
		std::cout << str << std::endl;
	}
};

class Base{
public:
	 virtual void FirstMethod(){ cout << "First Base Method" << endl; }
	 virtual void SecondMethod(){ cout << "Second Base (virtual)Method" << endl; }
};

class Child1 : public Base{
public:
	void FirstMethod(){ cout << "First Child1 Method" << endl; }
};

class Child2 : public Base{
public:
	virtual void FirstMethod(){ cout << "First Child2 Method" << endl; }
	void SecondMethod(){ cout << "Second Child2 Method" << endl; }
};


enum TrafficLight { red, yellow, green };
typedef enum TrafficLight Signal;

void display(Signal s){

	switch (s){
	case red: std::cout << "red" << std::endl;
		break;
	case yellow: std::cout << "yellow" << std::endl;
		break;
	case green: std::cout << "green" << std::endl;
		break;
	}
}

void change(Signal *s){
	static int second = 0;

	switch (*s){
	case red:
		if (second % 3 == 2){
			*s = green;
			second = 0;
		}
		else {
			second++;
		}
		break;
	case yellow:
		*s = red;
		second = 0;
		break;
	case green:
		if (second % 3 == 2){
			*s = yellow;
			second = 0;
		}
		else{
			second++;
		}
		break;
	}
}


template<typename T>
void swaping(T a, T b){
	T tmp = a;
	a = b;
	b = tmp;

	std::cout << " A -> " << a << " (Multi of a and b)" << std::endl;
	std::cout << " B -> " << b << " (Sum of a and b)" << std::endl;
}


void(*Writer)();
void Black(){ cout << "Black" << endl; }
void White(){ cout << "White" << endl; }
void Yellow(){ cout << "Yellow" << endl; }
void Green(){ cout << "Green" << endl; }
void Blue(){ cout << "Blue" << endl; }
/*
Writer Emit(){

}
*/

// declare the type Colour
//enum Colour { white = 20, red, green, blue };


int main(){

	Base f;

	string str = "Hello";

	Child1 child1;
	Child2 child2;

	child1.FirstMethod();
	child1.SecondMethod();
	child2.FirstMethod();
	child2.SecondMethod();
	
	((Base)child2).FirstMethod();
	((Base)child2).SecondMethod();


	str.push_back('ada'); // using vector

	cout << "\nMy String -> " << str << endl;

	/*
#define F0 1058
#define F(n) ((n) + F0)
#define NKEYS 5

	//Colour wall, ceiling; // define two Colour variables

	//wall = red;
	//ceiling = white;

	//std::cout << wall << ' ' << ceiling << std::endl;
	//std::cout << std::endl;

	int i, n;

	std::cout << "Key Value" << std::endl;
		for (i = 0; i < NKEYS; i++)
			std::cout << "n = " << i + 1 << " F(n) = " << F(i + 1) << std::endl;

	std::cout << "The name of the source file is " << __FILE__ << std::endl;
	std::cout << "The date of its translation is " << __DATE__ << std::endl;
	std::cout << "The time of its translation is " << __TIME__ << std::endl;

//	std::cout << "Please enter semester week: ";
//	std::getline(std::cin, mySpace::myStr);

	std::cout << std::endl;
	//std::cout << mySpace::WEEK << std::endl;

	std::cout << "Wanna sum something???\nfirst -> ";
	std::cin >> mySpace::a;
	std::cout << "second -> ";
	std::cin >> mySpace::b;
	std::cout << "Sum -> " << SUM(mySpace::a, mySpace::b) << std::endl;
	std::cout << "Multi -> " << MULTI(mySpace::a, mySpace::b) << std::endl;
	
	std::cout << "\n\n MACROS!!!" << std::endl;
	std::cout << "Swaping this  -> ";
	SWAP(mySpace::a, mySpace::b, int);
	

	std::cout << "\n\n********* TEMPLATE SWAP ***********\n" << std::endl;
	swaping(SUM(mySpace::a, mySpace::b), MULTI(mySpace::a, mySpace::b));
	SWAP(mySpace::a, mySpace::b, int);

	std::cout << "\n\n********* Keele at Finch (Light) ***********\n" << std::endl;
	

	Signal keeleAtFinch = red;

	for (int i = 0; i < 10; i++){
		change(&keeleAtFinch);
		display(keeleAtFinch);
	}
	*/
	system("pause");
	return 0;
}