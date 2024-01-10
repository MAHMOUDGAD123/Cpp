#include <iostream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include "MGLib.h"

using namespace std;
using namespace MGLib;


// 'Sparse Matrix' --> { Zero frequency is bigger than the frequency of the Non-zero Numbers in the Matrix}


unsigned short GetNumberFrequencyInMatrix(int Matrix[10][10], const unsigned short* Rows, const unsigned short* Columns, const short NumberToCheck)
{
	unsigned short Counter = 0;

	for (unsigned short i = 0; i < *Rows; i++)
		for (unsigned short j = 0; j < *Rows; j++)
			if (Matrix[i][j] == NumberToCheck)
				Counter++;
	return Counter;
}


bool IsSparseMatrix(int Matrix[10][10], const unsigned short* Rows, const unsigned short* Columns)
{
	const unsigned short MatrixSize = *Rows * *Columns;
	const unsigned short ZeroFrequency = GetNumberFrequencyInMatrix(Matrix, Rows, Columns, 0);
	const unsigned short NonZeroFrequency = MatrixSize - ZeroFrequency;

	return (ZeroFrequency >= NonZeroFrequency);
}

bool IsSparseMatrix_Hadhoud(int Matrix[10][10], const unsigned short Rows, const unsigned short Columns)
{
	short MatrixSize = Rows * Columns;

	return (GetNumberFrequencyInMatrix(Matrix, &Rows, &Columns, 0) >= ceil((float)MatrixSize / 2));
}



void GenerateRandomSparseMatrix(int SpMatrix[10][10], const unsigned short* Rows, const unsigned short* Columns)
{
	const unsigned short MatrixSize = *Rows * *Columns;

	// Random Number Of Non-Zero Elements in the Matrix
	unsigned short NonZeroElements = (unsigned short)RandomNumber(MatrixSize / 4, MatrixSize / 2);

	Matrix_ZeroFill(SpMatrix); // Fill the Matrix with zeros

	unsigned short RandRowPosition = (unsigned short)RandomNumber(0, *Rows - 1);
	unsigned short RandColumnPosition = (unsigned short)RandomNumber(0, *Columns - 1);

	for (unsigned short i = 0; i <= NonZeroElements; i++)
	{
		SpMatrix[RandRowPosition][RandColumnPosition] = RandomNumber(1, 9);

		RandRowPosition = (unsigned short)RandomNumber(0, *Rows - 1);
		RandColumnPosition = (unsigned short)RandomNumber(0, *Columns - 1);
	}
}


int main()
{
	srand((unsigned)time(0));


	int Matrix[10][10], SpMatrix[10][10];
	unsigned short Rows{ 0 }, Columns{ 0 };


	Rows = (unsigned short)Read_Positive_Number_InRange("\n\n-> Enter The Number Of Rows: ", 1, 10);
	Columns = (unsigned short)Read_Positive_Number_InRange("-> Enter The Number Of Columns: ", 1, 10);

	unsigned short Size = Rows * Columns;

	Matrix_ZeroFill(Matrix);

	Fill_Matrix_Randomly(Matrix, &Rows, &Columns);
	GenerateRandomSparseMatrix(SpMatrix, &Rows, &Columns);

	cout << "\n\n#################################################################################\n\n";


	printf("\n\n--- The Following Is A (%dx%d) Random Matrix:\n\n", Rows, Columns);
	Print_Matrix(Matrix, &Rows, &Columns);

	unsigned short ZeroFrequency = GetNumberFrequencyInMatrix(Matrix, &Rows, &Columns, 0);

	cout << "\n-> Matrix Size = " << Size << endl;
	cout << "-> Number Of Zero Elements     = " << ZeroFrequency << endl;
	cout << "-> Number Of Non-Zero Elements = " << Size - ZeroFrequency << endl;

	if (IsSparseMatrix(Matrix, &Rows, &Columns))
		cout << "\n-> Your Matrix Is A Sparse Matrix :-)\n\n";
	else
		cout << "\n-> Your Matrix Isn't A Sparse Matrix :-(\n\n";


	cout << "\n\n#################################################################################\n\n";


	printf("\n\n--- The Following Is A (%dx%d) Sparse Matrix:\n\n", Rows, Columns);
	Print_Matrix(SpMatrix, &Rows, &Columns);

	ZeroFrequency = GetNumberFrequencyInMatrix(SpMatrix, &Rows, &Columns, 0);

	cout << "\n-> Matrix Size = " << Size << endl;
	cout << "-> Number Of Zero Elements     = " << ZeroFrequency << endl;
	cout << "-> Number Of Non-Zero Elements = " << Size - ZeroFrequency << endl;


	if (IsSparseMatrix(SpMatrix, &Rows, &Columns))
		cout << "\n-> Your Matrix Is A Sparse Matrix :-)\n\n";
	else
		cout << "\n-> Your Matrix Isn't A Sparse Matrix :-(\n\n";


	cout << "\n\n#################################################################################\n\n";


	return 0;
}