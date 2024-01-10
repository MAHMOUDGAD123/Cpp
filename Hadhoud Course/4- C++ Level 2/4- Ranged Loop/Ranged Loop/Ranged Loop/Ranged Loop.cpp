#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <cmath>
#include <math.h>
#include "MGLib.h"

using namespace std;
using namespace MGLib;


int main()
{
	short arr[10], arr_length = 0;

	arr_length = Read_Positive_Int_Number("What is The array Length?");

	Fill_Array_With_Random_Numbers_From1toN_NoRepeating(arr, arr_length);

	for (short i : arr) // Ranged Loop
	{
		cout << i << "  ";
	}

	// *************************************************
	cout << endl << endl << endl;


	short arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


	for (short i : arr1)
	{
		cout << i << "  ";
	}


	// *************************************************
	cout << endl << endl << endl;

	for (short i : {11, 22, 33, 44, 55, 66, 77, 88, 99, 100})
	{
		cout << i << "  ";
	}

	cout << endl << endl << endl;


	short arr2[] = { 10, 20, 30, 40, 50 };

	for(short i : arr2)
	{
		cout << i << "  ";
	}

	cout << endl << endl << endl;

	char arr3[] = { 'M', 'A', 'H', 'M', 'O', 'U', 'D' };

	for (auto i : arr3) // (auto) to make the loop find out the data type by it's self
	{
		cout << i << " ";
	}

	cout << endl << endl << endl;



	string arr4[] = { "Mahmoud", "Abdelrahman", "Ismail", "Gad"};

	for (string i : arr4) // (auto) to make the loop find out the data type by it's self
	{
		cout << i << " ";
	}

	cout << endl << endl << endl;

	return 0;
}