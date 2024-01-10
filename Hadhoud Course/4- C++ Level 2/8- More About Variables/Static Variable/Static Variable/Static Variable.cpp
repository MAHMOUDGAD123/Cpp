
#include <iostream>

using namespace std;

void Increase_Number()
{
	int Number = 10;

	cout << "Local Number = " << Number << endl;

	Number++;
}

void Increase_StaticNumber()
{
	static int Number = 10;

	cout << "Static Number = " << Number << endl;

	Number++;
}



int main()
{
	cout << "Local Number Increament:" << endl << endl;;
	Increase_Number();
	Increase_Number();
	Increase_Number();

	cout << endl << endl;

	cout << "Static Number Increament:" << endl << endl;;
	Increase_StaticNumber();
	Increase_StaticNumber();
	Increase_StaticNumber();


	return 0;
}
