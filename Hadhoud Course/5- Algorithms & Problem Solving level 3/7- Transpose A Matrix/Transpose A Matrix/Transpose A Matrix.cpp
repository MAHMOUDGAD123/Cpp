#include <iostream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include "MGLib.h"

using namespace std;
using namespace MGLib;



void Matrix_ZeroFill(int Matrix[10][10])
{
	for (unsigned short i = 0; i < 10; i++)
		for (unsigned short j = 0; j < 10; j++)
			Matrix[i][j] = 0;
}

void FillMatrixWithOrderdNumbers(int Matrix[10][10], const unsigned short* Rows, const unsigned short* Columns)
{
	unsigned short Counter{ 1 };

	for (unsigned short i = 0; i < *Rows; i++)
	{
		for (unsigned short j = 0; j < *Columns; j++)
		{
			Matrix[i][j] = Counter;
			Counter++;
		}
	}
}

void Transpose_SquareMatrix(int Matrix[10][10], int TransposedMatrix[10][10], const unsigned short* Rows, const unsigned short* Columns)
{
	unsigned short Dimension = (*Rows > *Columns) ? *Rows : (*Rows < *Columns) ? *Columns : *Rows;

	for (unsigned short i{ 0 }; i < Dimension; i++)
		for (unsigned short j{ 0 }; j < Dimension; j++)
			TransposedMatrix[i][j] = Matrix[j][i];
}



int main()
{
	int Matrix[10][10], TransposedMatrix[10][10];
	unsigned short Rows{ 0 }, Columns{ 0 };
	unsigned short TRows{ 0 }, TColumns{ 0 };

	Rows = (unsigned short)Read_Positive_Number_InRange("\n\n-> Enter The Number Of Rows: ", 1, 10);
	Columns = (unsigned short)Read_Positive_Number_InRange("-> Enter The Number Of Columns: ", 1, 10);

	Matrix_ZeroFill(Matrix);
	Matrix_ZeroFill(TransposedMatrix);

	TRows = Columns, TColumns = Rows;

	FillMatrixWithOrderdNumbers(Matrix, &Rows, &Columns);

	printf("\n\n--- The Following Is A (%dx%d) Ordered Matrix:\n\n", Rows, Columns);
	Print_Matrix(Matrix, &Rows, &Columns);

	Transpose_SquareMatrix(Matrix, TransposedMatrix, &Rows, &Columns);

	printf("\n\n--- The Following Is The Transposed (%dx%d) Matrix:\n\n", TRows, TColumns);
	Print_Matrix(TransposedMatrix, &TRows, &TColumns);



	return 0;
}