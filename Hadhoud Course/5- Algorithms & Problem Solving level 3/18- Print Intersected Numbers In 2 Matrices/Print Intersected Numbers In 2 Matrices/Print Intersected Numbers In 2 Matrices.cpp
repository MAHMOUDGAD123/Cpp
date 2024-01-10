#include <iostream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <vector>
#include "MGLib.h"

using namespace std;
using namespace MGLib;


bool IsNumberInVector(vector <int> vIntersectedList, const int NumberToCheck)
{
	for (const int& Number : vIntersectedList)
		if (Number == NumberToCheck)
			return true;
	return false;
}

bool IsNumberInMatrix(int Matrix[10][10], const unsigned short* Rows, const unsigned short* Columns, const short NumberToCheck)
{
	for (unsigned short i = 0; i < *Rows; i++)
		for (unsigned short j = 0; j < *Columns; j++)
			if (Matrix[i][j] == NumberToCheck)
				return true;
	return false;
}

vector <int> Store_Intersected_Number(int Matrix_A[10][10], int Matrix_B[10][10], const unsigned short* Rows, const unsigned short* Columns)
{
	vector <int> vIntersectedList;

	for (unsigned short i = 0; i < *Rows; i++)
	{
		for (unsigned short j = 0; j < *Columns; j++)
		{
			// Check the list before adding the number
			if (IsNumberInVector(vIntersectedList, Matrix_A[i][j]))
				continue;

			// Add the number to the list
			if (IsNumberInMatrix(Matrix_B, Rows, Columns, Matrix_A[i][j]))
				vIntersectedList.push_back(Matrix_A[i][j]);
		}
	}

	return vIntersectedList;
}

void Print_Vector(vector <int> vIntersectedList)
{
	for (const int& Number : vIntersectedList)
		cout << "  " << Number;
	cout << endl << endl;
}


int main()
{
	Srand((unsigned)time(0));

	vector <int> vIntersectedList;
	int Matrix_A[10][10], Matrix_B[10][10];
	unsigned short Rows{ 0 }, Columns{ 0 };

	Rows = (unsigned short)Read_Positive_Number_InRange("\n\n-> Enter The Number Of Rows: ", 1, 10);
	Columns = (unsigned short)Read_Positive_Number_InRange("-> Enter The Number Of Columns: ", 1, 10);


	Matrix_ZeroFill(Matrix_A);
	Matrix_ZeroFill(Matrix_B);

	Fill_Matrix_Randomly(Matrix_A, &Rows, &Columns);
	Fill_Matrix_Randomly(Matrix_B, &Rows, &Columns);

	cout << "\n\n#################################################################################\n\n";


	printf("\n\n--- The Following Is A (%dx%d) Random Matrix_A:\n\n", Rows, Columns);
	Print_Matrix(Matrix_A, &Rows, &Columns);


	cout << "\n\n#################################################################################\n\n";


	printf("\n\n--- The Following Is A (%dx%d) Random Matrix_B:\n\n", Rows, Columns);
	Print_Matrix(Matrix_B, &Rows, &Columns);


	cout << "\n\n#################################################################################\n\n";

	vIntersectedList = Store_Intersected_Number(Matrix_A, Matrix_B, &Rows, &Columns);

	cout << "-> The Following Is The Intersected Number:\n\n";
	Print_Vector(vIntersectedList);

	cout << "\n#################################################################################\n\n";

	return 0;
}