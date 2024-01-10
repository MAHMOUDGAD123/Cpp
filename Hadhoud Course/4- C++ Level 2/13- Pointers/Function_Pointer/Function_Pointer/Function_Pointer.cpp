#include <iostream>
#include <vector>

using namespace std;

// We use function pointer to --> be able to pass a function as a parameter to another function to increase the 'Reusability'

// Watch this here (Code Beauty) --> https://youtu.be/kiUGf_Z08RQ?t=6476

// look here too --> https://www.geeksforgeeks.org/function-pointer-in-c/

/*
	Syntaics:

	date_type (* pointer_name) (parameters of the target fumction);  when function have parameters

	date_type (* pointer_name) ();   when function have no parameters

*/

//***************************************************************************************************

void Swap2Numbers(int* N1, int* N2)
{
	int temp{ 0 };

	temp = *N1;
	*N1 = *N2;
	*N2 = temp;
}

bool AscendingCompare(const int NumberToCheck, const int Comparative)
{
	return (NumberToCheck < Comparative);
}

bool DescendingCompare(const int NumberToCheck, const int Comparative)
{
	return (NumberToCheck > Comparative);
}

void VectorCustomSorting(vector <int>& vNumbers, bool(*Compare_ptr)(const int, const int))
{
	unsigned short Size{ (unsigned short)vNumbers.size() };
	unsigned short BestIndex{ 0 };

	for (unsigned short StartIndex = 0; StartIndex < Size; StartIndex++)
	{
		BestIndex = StartIndex;

		for (unsigned short CurrentIndex = StartIndex + 1; CurrentIndex < Size; CurrentIndex++)
		{
			if (Compare_ptr(vNumbers[CurrentIndex], vNumbers[BestIndex]))
				BestIndex = CurrentIndex;
		}
		Swap2Numbers(&vNumbers[StartIndex], &vNumbers[BestIndex]);
	}
}

void Print_Vector(vector <int>& vNumbers)
{
	cout << "-> Vector Numbers: {  ";
	for (const int& Number : vNumbers)
		cout << Number << "  ";

	cout << "}" << endl << endl;
}

int main()
{
	vector <int> vNumbers{ 7,4,1,2,3,6,9,10,8,5 };

	// function pointer
	bool(*Compare_ptr)(const int, const int);

	cout << "\n___________________________ Ascending Sorting ___________________________\n\n\n";

	// Make the 'Compare_ptr' points to "AscendingCompare"
	Compare_ptr = AscendingCompare;

	// Now 'VectorCustomSorting' ---> Works as Ascending Sorting
	VectorCustomSorting(vNumbers, Compare_ptr);

	Print_Vector(vNumbers);


	cout << "__________________________ Descending Sorting ___________________________\n\n\n";

	// Switch to Descending Sorting
	Compare_ptr = DescendingCompare;

	// Now 'VectorCustomSorting' ---> Works as Descending Sorting
	VectorCustomSorting(vNumbers, Compare_ptr);

	Print_Vector(vNumbers);
	
	cout << "_________________________________________________________________________\n\n";

	Compare_ptr = NULL;

	return 0;
}