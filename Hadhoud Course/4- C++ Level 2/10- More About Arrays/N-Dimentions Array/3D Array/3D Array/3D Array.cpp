
#include <iostream>
#include <iomanip>
#include <array>
#include "MGLib.h"


using namespace std;
using namespace MGLib;

void Read_Int3DArray(int Array[2][3][4], short& NumberOfDimentions, short& NumberOfRows, short& NumberOfColumns)
{
	NumberOfDimentions = Read_Positive_Number("Enter Dimention 1 [?][][]:--> ");
	NumberOfRows = Read_Positive_Number("Enter Dimention 2 [][?][]:--> ");
	NumberOfColumns = Read_Positive_Number("Enter Dimention 3 [][][?]:--> ");


	cout << endl << "Enter 3D Array Elements: " << endl << endl;

	for (short z = 0; z < NumberOfDimentions; z++)
	{
		for (short y = 0; y < NumberOfRows; y++)
		{
			for (short x = 0; x < NumberOfColumns; x++)
			{
				printf("Array[%hi][%hi][%hi]: ", z, y, x);
				Array[z][y][x] = Read_Number("");
			}
		}
	}
}

void Print_3DArray(int Array[2][3][4], short NumberOfDimentions, short NumberOfRows, short NumberOfColumns)
{
	for (short z = 0; z < NumberOfDimentions; z++)
	{
		for (short y = 0; y < NumberOfRows; y++)
		{
			for (short x = 0; x < NumberOfColumns; x++)
			{
				printf("%0*d ", 2, Array[z][y][x]);
			}

			cout << endl;
		}

		cout << endl;
	}
}




int main()
{
	short _1DArray[10] = { 1, 2,3,4,5,6,7,8,9,10 };


	// 2DArray = 3 X 1DArray
	short _2DArray[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };


	// 3DArray = 2 X 2DArray
	int _3DArray[2][3][4] =
	{
		{ { 1, 2, 3, 4},{ 5, 6, 7, 8},{ 9, 10, 11, 12} },
		{ { 13, 14, 15, 16},{ 17, 18, 19, 20},{ 21, 22, 23, 24} }
	};

	short NumberOfDimentions = 0, NumberOfRows = 0, NumberOfColumns = 0;

	Read_Int3DArray(_3DArray, NumberOfDimentions, NumberOfRows, NumberOfColumns);
	
	cout << endl << endl;

	Print_3DArray(_3DArray, NumberOfDimentions, NumberOfRows, NumberOfColumns);




	return 0;
}

