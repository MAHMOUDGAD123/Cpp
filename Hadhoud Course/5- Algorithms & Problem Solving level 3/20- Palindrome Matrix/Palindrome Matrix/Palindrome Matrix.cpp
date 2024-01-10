#include <iostream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <vector>
#include "MGLib.h"

using namespace std;
using namespace MGLib;


bool IsPalindromeRows(int Matrix[10][10], const unsigned short* Rows, const unsigned short* Columns)
{
	for (unsigned short Row = 0; Row < *Rows; Row++)
		for (unsigned short Column = 0; Column < *Columns / 2; Column++)
			if (Matrix[Row][Column] != Matrix[Row][*Columns - 1 - Column])
				return false;
	return true;
}

bool IsPalindromeColumns(int Matrix[10][10], const unsigned short* Rows, const unsigned short* Columns)
{
	for (unsigned short Column = 0; Column < *Columns; Column++)
		for (unsigned short Row = 0; Row < *Rows / 2; Row++)
			if (Matrix[Row][Column] != Matrix[*Rows - 1 - Row][Column])
				return false;
	return true;
}

bool IsPalindromeMatrix(int Matrix[10][10], const unsigned short* Rows, const unsigned short* Columns)
{
	return IsPalindromeRows(Matrix, Rows, Columns) && IsPalindromeColumns(Matrix, Rows, Columns);
}


void GeneratePalindromRows(int Matrix[10][10], const unsigned short* Rows, const unsigned short* Columns)
{
	for (unsigned short Row = 0; Row < *Rows; Row++)
		for (unsigned short Column = 0; Column < *Columns / 2; Column++)
			Matrix[Row][Column] = Matrix[Row][*Columns - 1 - Column] = RandomNumber(1, 9);
}

void MakeColumnsPalindrome(int Matrix[10][10], const unsigned short* Rows, const unsigned short* Columns)
{
	for (unsigned short Column = 0; Column < *Columns; Column++)
		for (unsigned short Row = 0; Row < *Rows / 2; Row++)
			Matrix[Row][Column] = Matrix[*Rows - 1 - Row][Column];
	
	// Fill the forgotten Column in the middle
	// This happen only when Columns is odd
	if (*Columns % 2 != 0)
	{
		unsigned short Row = *Rows / 2;
		unsigned short Column = *Columns / 2;

		// For the forgotten middle element
		// this happen when Rows & Columns are odd
		if (*Rows % 2 != 0)
			Matrix[Row][Column] = RandomNumber(1, 9);

		for (Row = 0; Row < *Rows / 2; Row++)
		{
			Matrix[Row][Column] = Matrix[*Rows - 1 - Row][Column] = RandomNumber(1, 9);
		}
	}
}

void GeneratePalindromeMatrix(int Matrix[10][10], const unsigned short* Rows, const unsigned short* Columns)
{
	GeneratePalindromRows(Matrix, Rows, Columns);
	MakeColumnsPalindrome(Matrix, Rows, Columns);
}

int main(void)
{
	Srand((unsigned)time(0));

	int Matrix[10][10], PMatrix[10][10];
	unsigned short Rows{ 3 }, Columns{ 3 };

	Rows = (unsigned short)Read_Positive_Number_InRange("\n\n-> Enter The Number Of Rows: ", 1, 10);
	Columns = (unsigned short)Read_Positive_Number_InRange("-> Enter The Number Of Columns: ", 1, 10);


	Matrix_ZeroFill(Matrix);
	Matrix_ZeroFill(PMatrix);

	Fill_Matrix_Randomly(Matrix, &Rows, &Columns);
	GeneratePalindromeMatrix(PMatrix, &Rows, &Columns);

	cout << "\n\n#################################################################################\n\n";


	printf("\n\n--- The Following Is A (%dx%d) Random Matrix:\n\n", Rows, Columns);
	Print_Matrix(Matrix, &Rows, &Columns);


	if (IsPalindromeMatrix(Matrix, &Rows, &Columns))
		cout << "\n-> The Matrix Is Palindorme.\n\n";
	else
		cout << "\n-> The Matrix Isn't Palindorme.\n\n";


	cout << "\n\n#################################################################################\n\n";
	

	printf("\n\n--- The Following Is A (%dx%d) Random Palindrome Matrix:\n\n", Rows, Columns);
	Print_Matrix(PMatrix, &Rows, &Columns);


	if (IsPalindromeMatrix(PMatrix, &Rows, &Columns))
		cout << "\n-> The Matrix Is Palindorme.\n\n";
	else
		cout << "\n-> The Matrix Isn't Palindorme.\n\n";

	
	cout << "\n\n#################################################################################\n\n";





	return 0;
}