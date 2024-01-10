#include <iostream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include "MGLib.h"

using namespace std;
using namespace MGLib;



void Print_Matrix_Pf(int Matrix[10][10], const unsigned short* Rows, const unsigned short* Columns)
{
	for (int i = 0; i < *Rows; i++)
	{
		for (int j = 0; j < *Columns; j++)
			printf("  %02d  ", Matrix[i][j]);
		cout << endl << endl;
	}
}



int MatrixSum(int Matrix[10][10], const unsigned short* Rows, const unsigned short* Columns)
{
	int Sum{ 0 };

	for (int i = 0; i < *Rows; i++)
	{
		for (int j = 0; j < *Columns; j++)
		{
			Sum += Matrix[i][j];
		}
	}
	return Sum;
}



int main()
{
	srand(14976513);

	int Matrix[10][10];
	unsigned short Rows{ 0 }, Columns{ 0 };

	Rows = (unsigned short)Read_Positive_Number_InRange("\n\n-> Enter The Number Of Rows: ", 1, 10);
	Columns = (unsigned short)Read_Positive_Number_InRange("-> Enter The Number Of Columns: ", 1, 10);

	Matrix_ZeroFill(Matrix);

	Fill_Matrix_Randomly(Matrix, &Rows, &Columns);

	printf("\n\n--- The Following Is A (%dx%d) Random Matrix:\n\n", Rows, Columns);
	Print_Matrix_Pf(Matrix, &Rows, &Columns);


	printf("\n-> The Matrix Sum = { %d }", MatrixSum(Matrix, &Rows, &Columns));


	cout << "\n\n#################################################################################\n\n";





	return 0;
}