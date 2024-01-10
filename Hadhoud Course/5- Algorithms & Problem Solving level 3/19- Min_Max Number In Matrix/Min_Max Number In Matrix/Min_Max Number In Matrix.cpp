#include <iostream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <vector>
#include "MGLib.h"

using namespace std;
using namespace MGLib;

enum en_MaxOrMin { Max = 1, Min = 2 };

int Matrix_Max(int Matrix[10][10], const unsigned short* Rows, const unsigned short* Columns)
{
	int Max = Matrix[0][0]; // Assume that the first element is the Max

	for (unsigned short i = 0; i < *Rows; i++)
		for (unsigned short j = 0; j < *Columns; j++)
			if (Matrix[i][j] > Max)
				Max = Matrix[i][j];
	return Max;
}

int Matrix_Min(int Matrix[10][10], const unsigned short* Rows, const unsigned short* Columns)
{
	int Min = Matrix[0][0]; // Assume that the first element is the Min

	for (unsigned short i = 0; i < *Rows; i++)
		for (unsigned short j = 0; j < *Columns; j++)
			if (Matrix[i][j] < Min)
				Min = Matrix[i][j];
	return Min;
}

int MatrixMaxOrMin(int Matrix[10][10], const unsigned short* Rows, const unsigned short* Columns, en_MaxOrMin Choice)
{
	switch (Choice)
	{
	case Max:
		return Matrix_Max(Matrix, Rows, Columns);
	case Min:
		return Matrix_Min(Matrix, Rows, Columns);
	}
}



int main()
{
	Srand((unsigned)time(0));

	int Matrix[10][10];
	unsigned short Rows{ 0 }, Columns{ 0 };

	Rows = (unsigned short)Read_Positive_Number_InRange("\n\n-> Enter The Number Of Rows: ", 1, 10);
	Columns = (unsigned short)Read_Positive_Number_InRange("-> Enter The Number Of Columns: ", 1, 10);


	Matrix_ZeroFill(Matrix);

	Fill_Matrix_Randomly(Matrix, &Rows, &Columns);

	cout << "\n\n#################################################################################\n\n";


	printf("\n\n--- The Following Is A (%dx%d) Random Matrix:\n\n", Rows, Columns);
	Print_Matrix(Matrix, &Rows, &Columns);

	cout << "\n-> Matrix Max Element = " << MatrixMaxOrMin(Matrix, &Rows, &Columns, Max);
	cout << "\n-> Matrix Min Element = " << MatrixMaxOrMin(Matrix, &Rows, &Columns, Min);


	cout << "\n\n#################################################################################\n\n";





	return 0;
}