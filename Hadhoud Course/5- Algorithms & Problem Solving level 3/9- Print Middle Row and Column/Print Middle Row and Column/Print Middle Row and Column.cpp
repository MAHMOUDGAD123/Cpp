#include <iostream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include "MGLib.h"

using namespace std;
using namespace MGLib;



void Print_Middle_Column(int Matrix[10][10], const unsigned short* Rows, const unsigned short* Columns)
{
	if (*Columns % 2 != 0)
	{
		unsigned short MiddleColumn = *Columns / 2;

		printf("\n-> The Middle Column Of Your Matrix Is: \n\n");
		for (unsigned short i = 0; i < *Rows; i++)
		{
			cout << setw(5) << Matrix[i][MiddleColumn];
			cout << "\n\n";
		}
	}
	else
	{
		cout << "\n-> There's No Middle Column :-(\n\n";
	}
}

void Print_Middle_Row(int Matrix[10][10], const unsigned short* Rows, const unsigned short* Columns)
{
	if (*Rows % 2 != 0)
	{
		unsigned short MiddleRow = *Rows / 2;

		printf("\n-> The Middle Row Of Your Matrix Is: \n\n");
		for (unsigned short i = 0; i < *Columns; i++)
		{
			cout << setw(7) << Matrix[MiddleRow][i];
		}
		cout << endl;
	}
	else
	{
		cout << "\n-> There's No Middle Row :-(\n\n";
	}
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
	Print_Matrix(Matrix, &Rows, &Columns);


	cout << "\n\n#################################################################################\n\n";

	Print_Middle_Row(Matrix, &Rows, &Columns);
	Print_Middle_Column(Matrix, &Rows, &Columns);




	return 0;
}