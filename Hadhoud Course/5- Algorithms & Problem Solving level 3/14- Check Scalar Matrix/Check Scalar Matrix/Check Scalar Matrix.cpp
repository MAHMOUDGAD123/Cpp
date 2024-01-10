#include <iostream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include "MGLib.h"

using namespace std;
using namespace MGLib;



bool IsScalarMatrix(int Matrix[10][10], const unsigned short* Rows, const unsigned short* Columns)
{
	int DiagonalFirstElement = Matrix[0][0];

	for (unsigned short i = 0; i < *Rows; i++)
		for (unsigned short j = 0; j < *Columns; j++)
			if ((i == j && Matrix[i][j] != DiagonalFirstElement) || (i != j && Matrix[i][j] != 0)) // Compare with Matrix first element [0][0]
				return false;
	return true;
}

void GenerateRandomScalarMatrix(int SMatrix[10][10], const unsigned short* Rows, const unsigned short* Columns)
{
	SMatrix[0][0] = GenerateRandomNumber_InRange(1, 21);

	for (unsigned short i = 0; i < *Rows; i++)
		for (unsigned short j = 0; j < *Columns; j++)
			(i == j) ? SMatrix[i][j] = SMatrix[0][0] : SMatrix[i][j] = 0;
}



int main()
{
	srand(time(0) / 2 * time(0) / 3);

	int Matrix[10][10], SMatrix[10][10];
	unsigned short Rows{ 0 }, Columns{ 0 };

	Rows = (unsigned short)Read_Positive_Number_InRange("\n\n-> Enter The Number Of Rows: ", 1, 10);
	Columns = (unsigned short)Read_Positive_Number_InRange("-> Enter The Number Of Columns: ", 1, 10);

	Matrix_ZeroFill(Matrix);
	Matrix_ZeroFill(SMatrix);

	Fill_Matrix_Randomly(Matrix, &Rows, &Columns);
	GenerateRandomScalarMatrix(SMatrix, &Rows, &Columns);

	cout << "\n\n#################################################################################\n\n";


	printf("\n\n--- The Following Is A (%dx%d) Random Matrix:\n\n", Rows, Columns);
	Print_Matrix_Pf(Matrix, &Rows, &Columns);

	if (IsScalarMatrix(Matrix, &Rows, &Columns))
		cout << "\n-> Your Matrix Is A Scalar Matrix :-)\n\n";
	else
		cout << "\n-> Your Matrix Isn't A Scalar Matrix :-(\n\n";


	cout << "\n\n#################################################################################\n\n";


	printf("\n\n--- The Following Is A (%dx%d) Scalar Matrix:\n\n", Rows, Columns);
	Print_Matrix_Pf(SMatrix, &Rows, &Columns);


	if (IsScalarMatrix(SMatrix, &Rows, &Columns))
		cout << "\n-> Your Matrix Is A Scalar Matrix :-)\n\n";
	else
		cout << "\n-> Your Matrix Isn't A Scalar Matrix :-(\n\n";


	cout << "\n\n#################################################################################\n\n";


	return 0;
}