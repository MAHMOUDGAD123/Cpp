#include <iostream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <vector>
#include "MGLib.h"

using namespace std;
using namespace MGLib;




// Fibonacci series from 1 --> 'Number'


vector <unsigned short> FibonacciSeries(const short Number)
{
	vector <unsigned short> vFibonacciSeries;

	int Prev2 = 0, Prev1 = 0;
	int Curr = 1; // Start Point

	for (unsigned short Counter = 1; Counter <= Number; Counter++)
	{
		vFibonacciSeries.push_back(Curr);

		Prev2 = Prev1;
		Prev1 = Curr;
		Curr = Prev2 + Prev1;
	}
	return vFibonacciSeries;
}


vector <unsigned short> FibonacciSeries_Recursive(unsigned short Number, bool First = true)
{
	static vector <unsigned short> vFibonacciSeries;

	static int Prev2, Prev1;
	static int Curr;

	// at first time only
	// initialization
	if (First)
	{
		Prev2 = Prev1 = 0;
		Curr = 1;
	}

	if (Number > 0)
	{
		vFibonacciSeries.push_back(Curr);

		Prev2 = Prev1;
		Prev1 = Curr;
		Curr = Prev2 + Prev1;

		FibonacciSeries_Recursive(Number - 1, false);
	}
	return vFibonacciSeries;
}


void Print_Vector(vector <unsigned short> vFibonacciSreies)
{
	for (const unsigned short& Number : vFibonacciSreies)
		cout << "  " << Number;
	cout << endl << endl;
}

int main(void)
{
	vector <unsigned short> vFibonacciSeries1;
	vector <unsigned short> vFibonacciSeries2;

	unsigned short Number = Read_Positive_Int_Number("-> Enter A Number: ");

	cout << "\n#######################################################\n\n";

	vFibonacciSeries1 = FibonacciSeries(Number);

	cout << "\n-> Fibonacci Using For Loop: ";
	Print_Vector(vFibonacciSeries1);

	cout << "\n#######################################################\n\n";

	vFibonacciSeries2 = FibonacciSeries_Recursive(Number);

	cout << "\n-> Fibonacci Using Recursion: ";
	Print_Vector(vFibonacciSeries2);

	cout << "\n#######################################################\n\n";



	return 0;
}