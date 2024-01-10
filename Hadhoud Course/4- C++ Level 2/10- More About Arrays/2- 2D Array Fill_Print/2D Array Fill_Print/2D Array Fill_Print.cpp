
#include <iostream>
#include <iomanip>
#include "MGLib.h"

using namespace std;
using namespace MGLib;



void Fill_Int2DimentionalArray(int Array[10][10], short& NumberOfRows, short& NumberOfColumns)
{
	NumberOfRows = Read_Positive_Number("Enter The Number Of Rows:--> ");
	cout << endl;
	NumberOfColumns = Read_Positive_Number("Enter The Number Of Colomns:--> ");
	cout << endl;

	cout << "Enter The Array Elements:\n\n";
	for (short i = 0; i < NumberOfRows; i++)
	{
		for (short j = 0; j < NumberOfColumns; j++)
		{
			printf("Array[%d][%d]: ", i, j);
			Array[i][j] = Read_Number("");
		}
	}

	cout << endl << endl;
}

void Print_2DArray(int Array[10][10], short NumberOfRows, short NumberOfColumns)
{
	for (short i = 0; i < NumberOfRows; i++)
	{
		for (short j = 0; j < NumberOfColumns; j++)
		{
			cout << setw(5) << Array[i][j];
		}

		cout << endl << endl;
	}
}


int main()
{
	// Fill Integer 2 Dimentional Array By User Input & Print it

	int IArray[10][10];
	short NumberOfRows = 0, NumberOfColumns = 0;

	Fill_Int2DimentionalArray(IArray, NumberOfRows, NumberOfColumns);

	Print_2DArray(IArray, NumberOfRows, NumberOfColumns);

	return 0;
}