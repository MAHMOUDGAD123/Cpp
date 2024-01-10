#include <iostream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include "MGLib.h"

using namespace std;
using namespace MGLib;



unsigned short GetNumberFrequencyInMatrix(int Matrix[10][10], const unsigned short* Rows, const unsigned short* Columns, const short NumberToCheck)
{
	unsigned short Counter = 0;

	for (unsigned short i = 0; i < *Rows; i++)
		for (unsigned short j = 0; j < *Rows; j++)
			if (Matrix[i][j] == NumberToCheck)
				Counter++;
	return Counter;
}

bool IsNumberInMatrix(int Matrix[10][10], const unsigned short* Rows, const unsigned short* Columns, const short NumberToCheck)
{
	for (unsigned short i = 0; i < *Rows; i++)
		for (unsigned short j = 0; j < *Columns; j++)
			if (Matrix[i][j] == NumberToCheck)
				return true;
	return false;
}

int main()
{
	srand((unsigned)time(0));


	int Matrix[10][10];
	unsigned short Rows{ 0 }, Columns{ 0 };


	Rows = (unsigned short)Read_Positive_Number_InRange("\n\n-> Enter The Number Of Rows: ", 1, 10);
	Columns = (unsigned short)Read_Positive_Number_InRange("-> Enter The Number Of Columns: ", 1, 10);

	unsigned short Size = Rows * Columns;

	Matrix_ZeroFill(Matrix);

	Fill_Matrix_Randomly(Matrix, &Rows, &Columns);

	cout << "\n\n#################################################################################\n\n";


	printf("\n\n--- The Following Is A (%dx%d) Random Matrix:\n\n", Rows, Columns);
	Print_Matrix(Matrix, &Rows, &Columns);

	const unsigned short NumberToCheck = Read_Number("-> Enter A Number To Check It --> ");

	unsigned short NumberFrequency = GetNumberFrequencyInMatrix(Matrix, &Rows, &Columns, NumberToCheck);

	printf("\n-> Number {%hu} Found (%hu) Times In The Matrix.\n", NumberToCheck, NumberFrequency);

	if (IsNumberInMatrix(Matrix, &Rows, &Columns, NumberToCheck))
		cout << "\n-> Found :-)\n\n";
	else
		cout << "\n-> Not Found :-(\n\n";


	cout << "\n\n#################################################################################\n\n";



	return 0;
}