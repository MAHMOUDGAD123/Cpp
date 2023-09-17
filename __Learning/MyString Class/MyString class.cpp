#include "clsString.h"
#include <initializer_list>

class Employee
{
private:
	MG::String fullname;

public:
	Employee() = default; // default constructor

	// copy constructor
	Employee(const MG::String& name) : fullname(name) {}

	// move constructor - to just move the String data
	Employee(MG::String&& name) noexcept : fullname(std::move(name)) {}

	void print() { cout << "Employee Name: " << fullname << endl; }
};


MG::String temp()
{
	MG::String M("Nahmoud");
	return M;
}


int main(void)
{
	MG::String S1 = "Mahmoud";
	MG::String S2 = "Abdelrahman";
	MG::String S3 = "Gad";

	cout << temp() << endl;

	// cout << "Before Moving:\n\n";

	// S1.print("S1 = ");
	// S2.print("S2 = ");
	// S3.print("S3 = ");


	// MG::String S4 = std::move(S1); // using move constructor
	// MG::String S5;
	// MG::String S6;

	// // both are the same
	// S5 = std::move(S2);				// using move assignment operator =
	// S6.operator= (std::move(S3)); // using move assignment operator =

		
	// cout << "\n\nAfter Moving:\n\n";

	// S1.print("S1 = "); // @expected(26800)
	// S2.print("S2 = "); // @expected(26800)
	// S3.print("S3 = "); // @expected(26800)
	// S4.print("S4 = ");
	// S5.print("S5 = ");
	// S6.print("S5 = ");


	cout << "\n\n";

	return 0;
}