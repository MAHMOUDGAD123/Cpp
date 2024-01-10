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


bool AreTypicalMatrices(int Matrix1[10][10], int Matrix2[10][10], const unsigned short* Rows, const unsigned short* Columns)
{
	for (unsigned short i = 0; i < *Rows; i++)
		for (unsigned short j = 0; j < *Columns; j++)
			if (Matrix1[i][j] != Matrix2[i][j])
				return false;

	return true;
}




int main()
{
	srand(time(0));

	int Matrix1[10][10], Matrix2[10][10];
	unsigned short Rows{ 0 }, Columns{ 0 };

	Rows = (unsigned short)Read_Positive_Number_InRange("\n\n-> Enter The Number Of Rows: ", 1, 10);
	Columns = (unsigned short)Read_Positive_Number_InRange("-> Enter The Number Of Columns: ", 1, 10);

	Matrix_ZeroFill(Matrix1);
	Matrix_ZeroFill(Matrix2);

	Fill_Matrix_Randomly(Matrix1, &Rows, &Columns);
	Fill_Matrix_Randomly(Matrix2, &Rows, &Columns);

	//FillMatrixWithOrderdNumbers(Matrix1, &Rows, &Columns);
	//FillMatrixWithOrderdNumbers(Matrix2, &Rows, &Columns);

	printf("\n\n--- The Following Is A (%dx%d) Random Matrix1:\n\n", Rows, Columns);
	Print_Matrix_Pf(Matrix1, &Rows, &Columns);

	printf("\n\n--- The Following Is A (%dx%d) Random Matrix2:\n\n", Rows, Columns);
	Print_Matrix_Pf(Matrix2, &Rows, &Columns);

	cout << "\n\n#################################################################################\n\n";

	if (AreTypicalMatrices(Matrix1, Matrix2, &Rows, &Columns))
	{
		cout << "\n-> The 2 Matrices Are Typical :-)\n\n";
	}
	else
	{
		cout << "\n-> The 2 Matrices Aren't Typical :-)\n\n";
	}



	return 0;
}