#include <iostream>

using namespace std;


// https://www.geeksforgeeks.org/destructors-c/?ref=lbp
// https://www.geeksforgeeks.org/private-destructor-in-cpp/



// Destructor is an instance member function which is invoked automatically whenever an object is going to be destroyed.
// Meaning, a destructor is the last function that is going to be called before an object is destroyed.

// Destructor has the same name as their class name preceded by a tilde (~) symbol. { ~ClassName }

// The destructor is only one way to destroy the object create by constructor.
// Hence destructor can not be overloaded.
// destructor is not like constructor
// you can overload constructor but you can't overload destructor
// so, It is not possible to define more than one destructor this will get compile error.

// Destructor neither requires any argument (parameters) nor returns any value.
// It is automatically called when object goes out of scope.


class clsPerson
{

private:
	string _fullName;

public:

	// This is Instructor will be called when object is built.
	clsPerson()
	{
		_fullName = "Mahmoud Gad";
		cout << "\nHi, I'm Constructor :-)\n";
	}

	// This is destructor will be called when object is destroyed.
	~clsPerson()
	{
		cout << "\nHi, I'm Destructor :-(\n";
	}

	void Destruct() { delete this; };

};


// after exiting from function, object will be destroyed and destructor will be called.
//always use (delete) whenever you use (new), otherwise object will remain in memory and destructor will not be called


void Fun1()
{
	cout << "In Fun1() both constructor & destructor will be called.\n";
	clsPerson Person1;
}

void Fun2()
{
	// dynamic memory allocation
	cout << "\n\nIn Fun2() only constructor will be called because we didn't use delete.\n";
	clsPerson* Person2 = new clsPerson;
}

void Fun3()
{
	// dynamic memory allocation
	cout << "\n\nIn Fun3() constructor & destructor will be called, because we called the Destruct() function\n";
	clsPerson* Person2 = new clsPerson;
	Person2->Destruct(); // calling the destructor
}

void Fun4()
{
	// dynamic memory allocation
	cout << "\n\nIn Fun4() both constructor & destructor will be called because we use delete.\n";
	clsPerson* Person3 = new clsPerson;
	delete Person3;
}



int main()
{
	Fun1();
	Fun2();
	Fun3();
	Fun4();



	return 0;
}