#include <iostream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include "MGLib.h"

using namespace std;
using namespace MGLib;


void Multiply2Matrices(int Matrix1[10][10], int Matrix2[10][10], int MultiplyMatrix[10][10], unsigned short* Rows, unsigned short* Columns)
{
	for (unsigned short i = 0; i < *Rows; i++)
		for (unsigned short j = 0; j < *Columns; j++)
			MultiplyMatrix[i][j] = Matrix1[i][j] * Matrix2[i][j];
}


int main()
{
	int Matrix1[10][10], Matrix2[10][10], MultiplyMatrix[10][10];
	unsigned short Rows{ 0 }, Columns{ 0 };

	Rows = (unsigned short)Read_Positive_Number_InRange("\n\n-> Enter The Number Of Rows: ", 1, 10);
	Columns = (unsigned short)Read_Positive_Number_InRange("-> Enter The Number Of Columns: ", 1, 10);

	Matrix_ZeroFill(Matrix1);
	Matrix_ZeroFill(Matrix2);
	Matrix_ZeroFill(MultiplyMatrix);

	Fill_Matrix_Randomly(Matrix1, &Rows, &Columns);
	Fill_Matrix_Randomly(Matrix2, &Rows, &Columns);

	printf("\n\n--- The Following Is A (%dx%d) Random Matrix1:\n\n", Rows, Columns);
	Print_Matrix(Matrix1, &Rows, &Columns);

	printf("\n\n--- The Following Is A (%dx%d) Random Matrix2:\n\n", Rows, Columns);
	Print_Matrix(Matrix2, &Rows, &Columns);


	Multiply2Matrices(Matrix1, Matrix2, MultiplyMatrix, &Rows, &Columns);


	printf("\n\n--- The Following Is The (%dx%d) Result Matrix:\n\n", Rows, Columns);
	Print_Matrix(MultiplyMatrix, &Rows, &Columns);




	return 0;
}