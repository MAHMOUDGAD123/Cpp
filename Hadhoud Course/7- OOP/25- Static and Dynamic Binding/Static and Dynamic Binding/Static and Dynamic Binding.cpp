#include <iostream>

using namespace std;


// Static Binding: The binding which can be resolved at compile time by the compiler is known as static or early binding.
// The binding of all the static, private methods is done at compile-time.

// Dynamic Binding: In Dynamic binding compiler doesn’t decide the method to be called.
// Overriding is a perfect example of dynamic binding.
// In overriding both parent and child classes have the same method.


// Early Binding and Static Binding are the same.
// Late Binding and Dynamic Binding are the same.

// Early Binding / Static Binding are done at the compilation time.
// Late Binding/Dynamic Binding are done at run time.

// Early Binding is faster than Dynamic Binding


// Static binding: the target of a function call is determined at compile time,
// based on the type of the object or argument being passed to the function.

// Late binding: the target of a function call is determined at runtime,
// based on the type of the object being referred to.


// for more -> https://www.scaler.com/topics/static-binding-and-dynamic-binding/



class clsPerson
{
public:
	virtual void Print()
	{
		cout << "Hi, i'm Person class!\n";
	}

};

class clsEmployee : public clsPerson
{
public:
	void Print() override
	{
		cout << "Hi, i'm Employee class!\n";
	}

};

class clsStudent : public clsPerson
{
public:
	void Print() override
	{
		cout << "Hi, i'm Student class!\n";
	}

};


int main()
{
	clsEmployee Employee;
	clsStudent Student;

	// Static Binding (Early Binding) at compilation-time
	cout << "- This is Static-Binding:\n\n";
	Employee.Print();
	Student.Print();
	

	clsPerson* Person1 = &Employee;
	clsPerson* Person2 = &Student;

	// Dynamic Binding (Late Binding) at run-time
	cout << "\n\n- This is Dynamic-Binding:\n\n";
	Person1->Print();
	Person2->Print();



	return 0;
}