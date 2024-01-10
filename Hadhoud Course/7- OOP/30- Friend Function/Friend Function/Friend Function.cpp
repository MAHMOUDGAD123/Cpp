#include <iostream>

using namespace std;

// https://www.programiz.com/cpp-programming/friend-function-class

// The friend function is declared using the friend keyword inside the body of the class.

// By using the keyword, the ‘friend’ compiler understands that the given function is a friend function.

// A friend function in C++ is defined as a function that can access private, protected and public members of a class.

// We declare friend function inside the body of a class, whose private and protective data needs to be accessed,
// starting with the keyword friend to access the data. 
// We use them when we need to operate between two different classes at the same time.

// Friend functions of the class are granted permission to access private and protected members of the class in C++.
// They are defined globally outside the class scope.
// Friend functions are not member functions of the class.

// A friend function in C++ is a function that is declared outside a class but,
// is capable of accessing the private and protected members of the class.
// There could be situations in programming wherein we want two classes to share their members. 
// These members may be data members, class functions or function templates.
// In such cases, we make the desired function, a friend to both these classes which
// will allow accessing private and protected data of members of the class.




// Forward declaration of class B
class clsB;

class clsA
{
private:
	int _VarA;

public:

	clsA() : _VarA(100) {}

	// Friend function
	friend int Sum(const clsA&, const clsB&);

};


class clsB
{
private:
	int _VarB;

public:

	clsB() : _VarB(150) {}

	// Friend function
	friend int Sum(const clsA&, const clsB&);
};


// Friend function of class A,B -> can access to all members of them
int Sum(const clsA& Obj_A,const clsB& Obj_B)
{
	return (Obj_A._VarA + Obj_B._VarB);
}



int main()
{
	clsA A;
	clsB B;

	cout << "-> The Sum Of Class A,B Private Variables = " << Sum(A, B) << "\n\n";

	return 0;
}