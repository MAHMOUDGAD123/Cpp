#include <iostream>

using namespace std;

// https://www.programiz.com/cpp-programming/pure-virtual-funtion

// A pure virtual function doesn't have the function body and it must end with = 0.

// If you have one pure virtual function in a class then it will be converted to abstract class.

// Abstract Class is the same concept of Interface Class and they are both contracts.

// Abstract Class/Interface Class is a class with pure virtual functions.

// You can't have an object of abstract class, you can only inherit it.

// An abstract class in C++ has at least one pure virtual function by definition.
// In other words, a function that has no definition.

// The abstract class's descendants (derived classes) must define the pure virtual function; 
// otherwise, it is not allowed and you will get error.

// Derived Classes from abstract class can have extra methods other than the methods in the abstract class.


// The C++ interfaces are implemented using abstract classes and these abstract classes should not be confused with data abstraction
// which is a concept of keeping implementation details separate from associated data.


// Abstract class - Interface - Contract
class clsShape
{
protected:
	double _Dimention;

public:
	// Constructor
	clsShape(double Dimention) : _Dimention(Dimention) {}

	// pure virtual functions
	virtual double Area() = 0;
	virtual double Circumference() = 0;
	virtual void Print(const char* ShapeName) = 0;
};


class clsCircle : clsShape
{
private:
	long double _PI = 3.141592653589793238462643383279L;

public:
	// constructor override
	clsCircle(double Dimention) : clsShape(Dimention) {}

	double Area() override
	{
		return _PI * _Dimention * _Dimention;
	}

	double Circumference() override
	{
		return 2 * _PI * _Dimention;
	}

	void Print(const char* ShapeName) override
	{
		cout << "- The Area Of The " << ShapeName << " = " << Area() << endl;
		cout << "- The Circumference Of The " << ShapeName << " = " << Circumference() << endl;
	}
};


class clsSquare : clsShape
{
public:
	// constructor override
	clsSquare(double Dimention) : clsShape(Dimention) {}

	double Area() override
	{
		return _Dimention * _Dimention;
	}

	double Circumference() override
	{
		return 4 * _Dimention;
	}

	void Print(const char* ShapeName) override
	{
		cout << "- The Area Of The " << ShapeName << " = " << Area() << endl;
		cout << "- The Circumference Of The " << ShapeName << " = " << Circumference() << endl;
	}
};


int main()
{
	clsCircle Circle(3);
	Circle.Print("Circle");

	cout << "\n\n";

	clsSquare Square(2);
	Square.Print("Square");


	return 0;
}