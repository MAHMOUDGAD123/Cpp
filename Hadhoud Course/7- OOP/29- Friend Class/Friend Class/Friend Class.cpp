#include <iostream>

using namespace std;

// https://www.programiz.com/cpp-programming/friend-function-class

// We can use a friend Class in C++ using the "friend" keyword.

// A friend class can access both private and protected members of the class in which it has been declared as friend.

// Since ClassB is a friend of ClassA, we can access all members of ClassA from inside ClassB.
// However, we cannot access members of ClassB from inside ClassA.
// It is because friend relation in C++ is only granted, not taken.



class clsA
{
private:
	int _Var1;

protected:
	int __Var2;

public:
	int Var3;

	// Constructor
	clsA() : _Var1(10), __Var2(20), Var3(30) {}


	// Friend Class
	friend class clsB;

};


class clsB
{
public:

	void Display(clsA Obj_A)
	{
		cout << "--> I'm class B and i can access everything in class A through an object of Class A, because i'm a friend of him.\n";
		cout << "=> Class A Var1 = " << Obj_A._Var1 << endl;
		cout << "=> Class A Var2 = " << Obj_A.__Var2 << endl;
		cout << "=> Class A Var3 = " << Obj_A.Var3 << endl;
	}

};

class clsC
{
public:

	void Display(clsA Obj_A)
	{
		cout << "\n--> I'm class C and i can only access the Public members of class A through an object of him.\n";
		cout << "=> Class A Var3 = " << Obj_A.Var3 << endl;
	}

};

int main()
{
	clsA A;
	clsB B;
	clsC C;

	B.Display(A);
	C.Display(A);


	return 0;
}