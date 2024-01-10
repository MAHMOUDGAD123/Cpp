#include <iostream>
#include <vector>
#include "MGLib.h"

using namespace std;
using namespace MGLib;

// using push_back() method to add elements to vector

// Din't Forget To Fill Vector By Reference (&)
void Add_ElementsToIntVector(vector <int> & vNumbers)
{
	cout << "Enter Vector Elements:" << endl;

	do 
	{
		cout << endl;
		vNumbers.push_back(Read_Number("Enter A Number:--> "));
		cout << endl;

	} while (Read_Bool_Input("Do You Want To Add More?"));

	cout << endl;
}

// Din't Forget To Print Vector By Reference (&) This is More Fast
void Print_IntVectorElements(vector <int> & vNumbers)
{
	cout << "Vector Numbers = { ";

	for (int& Number : vNumbers)
	{
		cout << Number << " ";
	}
	cout << "}" << endl;
}

int main()
{

	vector <int> vNumbers;

	
	Add_ElementsToIntVector(vNumbers);
	
	Print_IntVectorElements(vNumbers);





	return 0;
}
