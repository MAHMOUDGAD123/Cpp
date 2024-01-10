#include <iostream>

using namespace std;



// https://www.scaler.com/topics/cpp/this-pointer-in-cpp/

// this pointer in C++ stores the address of the class instance.

// Every object in C++ has access to its own address through an important pointer called this pointer.

// The this pointer is an implicit parameter to all member functions.

// Therefore, inside a member function, this may be used to refer to the invoking object.

// Friend functions do not have a this pointer, because friends are not members of a class.
// Only member functions/member data have a this pointer.

// 'this' pointer can be used to pass current object as a parameter to another method.

// 'this' pointer can be used to refer current class instance variable.

// declaration of 'this' is:    <classname>* const this 

class clsEmployee
{
private:
	string ID;
	string FullName;
	int Salary;

public:

	// we used this pointer here because the variables have the same names
	clsEmployee(string ID, string FullName, int Salary) 
	{
		this->ID = ID;
		this->FullName = FullName;
		this->Salary = Salary;
	}


	static void Disp(const clsEmployee* const Emp)
	{
		(*Emp).Print();
		//Emp->Print();
	}

	void FunX()
	{
		// send 'this' as an attribute to Disp()
		Disp(this);
	}

	void FunY() 
	{
		this->Print();
	}

	void Print() const
	{
		cout << "\nID       : " << ID;
		cout << "\nFullName : " << FullName;
		cout << "\nSalary   : " << Salary << "$\n";

		/*cout << "\nID       : " << this->ID;
		cout << "\nFullName : " << this->FullName;
		cout << "\nSalary   : " << this->Salary << "$\n";*/
	}

};


int main()
{
	clsEmployee Emp("A111", "Mahmoud Gad", 1000000);

	// All methods will print the same results:

	Emp.Print();

	Emp.FunX(); 

	Emp.FunY();

	Emp.Disp(&Emp);



	return 0;
}