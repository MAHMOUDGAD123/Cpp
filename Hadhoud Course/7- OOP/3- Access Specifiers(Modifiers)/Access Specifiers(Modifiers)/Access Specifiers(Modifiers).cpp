#include <iostream>
#include <string>

using namespace std;



// Who can access or use the class members?
// [1] any member inside the class itself
// [2] any object from the class
// [3] any class inherits the class

// you can control accessibility of the class members using {access specifiers}
// There's 3 types of access specitiers(modifiers):
// [1] private ---> accessable inside the class only (only class members can access) & friends too
// [2] protected -> accessable inside the class and all classes inherits this class
// [3] public  ---> accessable by everyone



class clsPerson
{

private:
	// accessable inside the class only (only class members can access)
	int variable1 = 123;
	int function1()
	{
		return 1500;
	}

protected:
	// accessable inside the class and all classes inherits this class (we will come to this later)
	int variable2 = 456;
	int function2()
	{
		return 750;
	}

public:
	// accessable by everyone
	string FirstName, LastName;
	string NationalId, Martial_Status;

	string fullName()
	{
		return FirstName + ' ' + LastName;
	}

	void function3()
	{
		cout << function1() + function2() + variable1 - variable2 << endl;
	}

};




int main()
{
	clsPerson Person;

	cout << "=========================================================================\n\n";

	Person.FirstName = "Mahmoud";
	Person.LastName = "Gad";
	Person.NationalId = "29709101204993";
	Person.Martial_Status = "Single";
	//Person.variable1   -> private member can't access
	//Person.function1() -> private member can't access
	//Person.variable2   -> protected member can't access
	//Person.function2() -> protected member can't access

	cout << "Person Full Name: " << Person.fullName() << endl;
	Person.function3();

	cout << "\n\n=========================================================================\n\n";
}