#include <iostream>

using namespace std;



// A virtual function is a member function in the base class that we expect to redefine in derived classes.

// Basically, a virtual function is used in the base class in order to ensure that the function is overridden.

// This especially applies to cases where a *pointer or a &reference of base class points to an object of a derived class.

// Using the (override) identifier prompts the compiler to display error messages when some mistakes are made,
// look here for this mistakes: https://www.programiz.com/cpp-programming/virtual-functions


class clsPerson
{
public:
	void Print()
	{
		cout << "Hi, i'm Person class print function!\n";
	}

	virtual void Disp()
	{
		cout << "Hi, i'm Person class Disp function!\n";
	}
};

class clsEmployee : public clsPerson
{
public:
	void Print()
	{
		cout << "Hi, i'm Employee class Print function!\n";
	}

	void Disp() override
	{
		cout << "Hi, i'm Employee class Disp function!\n";
	}
};

class clsStudent : public clsPerson
{
public:
	void Print()
	{
		cout << "Hi, i'm Student class print function!\n";
	}

	void Disp() override
	{
		cout << "Hi, i'm Student class Disp function!\n\n";
	}
};


int main()
{
	clsEmployee Employee;
	clsStudent Student;

	Employee.Print();
	Employee.Disp();

	Student.Print();
	Student.Disp();

	// using pointers up_casting
	clsPerson* Person1 = &Employee;
	clsPerson* Person2 = &Student;

	// both will call the function of clsPerson class
	Person1->Print();
	Person2->Print();

	cout << endl;

	Person1->Disp(); // this will call the clsEmployee function
	Person2->Disp(); // this will call the clsStudent function

	cout << endl;

	// using references up_casting
	clsPerson& Person3 = Employee;
	clsPerson& Person4 = Student;

	// both functions will be the clsPerson class function
	Person3.Print();
	Person4.Print();

	cout << endl;

	Person3.Disp(); // this will be clsEmployee function
	Person4.Disp(); // this will be clsStudent function

	// as we can see when we use pointer or reference:
	// base-class Print() function didn't overrided because it isn't a virtual function
	// base-class Disp() function overrided because it is a virtual function

	return 0;
}