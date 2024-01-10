#include <iostream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include "MGLib.h"

using namespace std;
using namespace MGLib;


bool IsIdentityMatrix(int Matrix[10][10], const unsigned short* Rows, const unsigned short* Columns)
{
	for (unsigned short i = 0; i < *Rows; i++)
		for (unsigned short j = 0; j < *Columns; j++)
			if ((i == j && Matrix[i][j] != 1) || (i != j && Matrix[i][j] != 0))
				return false;

	return true;
}

void Generate_IdentityMatrix(int IMatrix[10][10], const unsigned short* Rows, const unsigned short* Columns)
{
	for (unsigned short i = 0; i < *Rows; i++)
		for (unsigned short j = 0; j < *Columns; j++)
			(i == j) ? IMatrix[i][j] = 1 : IMatrix[i][j] = 0;
}



int main()
{
	srand(time(0));

	int Matrix[10][10], IMatrix[10][10];
	unsigned short Rows{ 0 }, Columns{ 0 };

	Rows = (unsigned short)Read_Positive_Number_InRange("\n\n-> Enter The Number Of Rows: ", 1, 10);
	Columns = (unsigned short)Read_Positive_Number_InRange("-> Enter The Number Of Columns: ", 1, 10);

	Matrix_ZeroFill(Matrix);

	Fill_Matrix_Randomly(Matrix, &Rows, &Columns);
	Generate_IdentityMatrix(IMatrix, &Rows, &Columns);

	cout << "\n\n#################################################################################\n\n";


	printf("\n\n--- The Following Is A (%dx%d) Random Matrix:\n\n", Rows, Columns);
	Print_Matrix_Pf(Matrix, &Rows, &Columns);

	if (IsIdentityMatrix(Matrix, &Rows, &Columns))
		cout << "\n-> Your Matrix Is An Identity Matrix :-)\n\n";
	else
		cout << "\n-> Your Matrix Isn't An Identity Matrix :-(\n\n";


	cout << "\n\n#################################################################################\n\n";


	printf("\n\n--- The Following Is A (%dx%d) Identity Matrix:\n\n", Rows, Columns);
	Print_Matrix_Pf(IMatrix, &Rows, &Columns);


	if (IsIdentityMatrix(IMatrix, &Rows, &Columns))
		cout << "\n-> Your Matrix Is An Identity Matrix :-)\n\n";
	else
		cout << "\n-> Your Matrix Isn't An Identity Matrix :-(\n\n";

	cout << "\n\n#################################################################################\n\n";


	return 0;
}