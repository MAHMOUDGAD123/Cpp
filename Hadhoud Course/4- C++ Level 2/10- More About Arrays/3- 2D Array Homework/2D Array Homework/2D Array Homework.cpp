
#include <iostream>
#include <iomanip>
#include "MGLib.h"

using namespace std;
using namespace MGLib;

// Fill Array With Multiplication Table From 1 to 10

void Fill_Int2DArrayWithMultiplicationTable(int Array[10][10], short& NumberOfRows, short& NumberOfColumns)
{
	NumberOfRows = Read_Positive_Number("Enter The Number Of Rows:--> ");
	cout << endl;
	NumberOfColumns = Read_Positive_Number("Enter The Number Of Colomns:--> ");
	cout << endl;

	for (short i = 0; i < NumberOfRows; i++)
	{
		for (short j = 0; j < NumberOfRows; j++)
		{
			Array[i][j] = (i + 1) * (j + 1);
		}
	}
}

void Print_2DArray(int Array[10][10], short NumberOfRows, short NumberOfColumns)
{
	for (short i = 0; i < NumberOfRows; i++)
	{
		for (short j = 0; j < NumberOfColumns; j++)
		{
			printf("%0*d ", 2, Array[i][j]);
		}

		cout << endl;
	}
}


int main()
{
	int Array[10][10];
	short NumberOfRows = 0, NumberOfColumns = 0;


	Fill_Int2DArrayWithMultiplicationTable(Array, NumberOfRows, NumberOfColumns);

	Print_2DArray(Array, NumberOfRows, NumberOfColumns);


	return 0;
}

