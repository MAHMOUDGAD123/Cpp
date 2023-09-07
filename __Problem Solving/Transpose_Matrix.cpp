#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>

using namespace std;

void Print_Matrix(unsigned short Matrix[10][10], const unsigned short *Rows, const unsigned short *Columns)
{
	for (int i = 0; i < *Rows; i++)
	{
		for (int j = 0; j < *Columns; j++)
		{
			cout << setw(7) << Matrix[i][j];
		}
		cout << endl
				 << endl;
	}
}

double Read_Positive_Number_InRange(const char *Message, int from, int to)
{
	double Number = 0;

	cout << Message;
	cin >> Number;

	while (cin.fail() || !((Number >= 0) && (Number >= from && Number <= to)))
	{
		cin.clear();
		cin.ignore(1000000, '\n');

		cout << "-> Invalid Number, Range (" << from << " -> " << to << ") |--> ";
		cin >> Number;
	}

	return Number;
}

void Swap2Numbers(unsigned short *A, unsigned short *B)
{
	unsigned short temp{0};
	temp = *A;
	*A = *B;
	*B = temp;
}

//************************************************************************************************************************

void Matrix_ZeroFill(unsigned short Matrix[10][10])
{
	for (unsigned short i = 0; i < 10; i++)
		for (unsigned short j = 0; j < 10; j++)
			Matrix[i][j] = 0;
}

void FillMatrixWithOrderdNumbers(unsigned short Matrix[10][10], const unsigned short *Rows, const unsigned short *Columns)
{
	unsigned short Counter{1};

	for (unsigned short i = 0; i < *Rows; i++)
	{
		for (unsigned short j = 0; j < *Columns; j++)
		{
			Matrix[i][j] = Counter;
			Counter++;
		}
	}
}

void Transpose_Matrix(unsigned short Matrix[10][10], unsigned short *Rows, unsigned short *Columns)
{
	unsigned short Dimension = (*Rows > *Columns) ? *Rows : (*Rows < *Columns) ? *Columns : *Rows;
	unsigned short i{0}, j{0};

	// Rows --> Columns & Columns --> Rows | when -> Rows != Columns
	if (*Rows != *Columns)
		Swap2Numbers(Rows, Columns);

	for (i; i < Dimension; i++)
	{
		j = i + 1;
		for (j; j < Dimension; j++)
			Swap2Numbers(&Matrix[i][j], &Matrix[j][i]);
	}
}

int main()
{

	unsigned short Matrix[10][10];
	unsigned short Rows{0}, Columns{0};

	Rows = (unsigned short)Read_Positive_Number_InRange("\n\n-> Enter The Number Of Rows: ", 1, 10);
	Columns = (unsigned short)Read_Positive_Number_InRange("-> Enter The Number Of Columns: ", 1, 10);

	Matrix_ZeroFill(Matrix); // Fill all Matrix elements with --> 'zero'

	FillMatrixWithOrderdNumbers(Matrix, &Rows, &Columns);

	printf("\n\n--- The Following Is A (%dx%d) Ordered Matrix:\n\n", Rows, Columns);
	Print_Matrix(Matrix, &Rows, &Columns);

	Transpose_Matrix(Matrix, &Rows, &Columns);

	printf("\n\n--- The Following Is The Transposed (%dx%d) Matrix:\n\n", Rows, Columns);
	Print_Matrix(Matrix, &Rows, &Columns);

	return 0;
}