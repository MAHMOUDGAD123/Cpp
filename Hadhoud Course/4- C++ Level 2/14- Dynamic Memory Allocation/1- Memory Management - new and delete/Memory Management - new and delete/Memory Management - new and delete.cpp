#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


int main()
{
	// Declare an integer pointer
	int* ptri;

	// Declare a float pointer
	float* ptrf;

	// declare a string pointer
	string* ptrS;

	// Dynamiclly allocate memory using (new) operator.
	// The (new) operator returns the address of the memory location.
	ptri = new int;
	ptrf = new float;
	ptrS = new string;

	// Assigning value to the memory.
	*ptri = 245;
	*ptrf = 21.1234565f;
	*ptrS = "Mahmoud Gad";

	cout << *ptri << endl;
	cout << setprecision(9) << *ptrf << endl;
	cout << *ptrS << endl;


	// Once we no longer need to use a variable that we have declared dynamically.
	// we can deallocate the memory occupied by the variable.
	// Deallocate the memory using (delete) operator.
	// The (delete) operator returns the memory to the operating system.
	// This is known as memory deallocation.
	// This means that the pointer now are pointing to nothing
	delete ptri;
	delete ptrf;
	delete ptrS;


	cout << "\n_______________________________________________\n\n";

	// You can assign the pointer the value directly
	// while allocating the memory pointer
	ptri = new int(77);
	ptrf = new float(77.77f);
	ptrS = new string("Mahmoud Gad");

	cout << *ptri << endl;
	cout << setprecision(3) << *ptrf << endl;
	cout << *ptrS << endl;


	delete ptri;
	delete ptrf;
	delete ptrS;

	// You can add the following to make the pointer points to nothing (this is a good practice)
	ptri = NULL;
	ptrf = NULL;
	ptrS = NULL;


	return 0;
}
