#include <iostream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include "MGLib.h"

using namespace std;
using namespace MGLib;


long GenerateRandomNumber_InRange(long from, long to)
{
    return rand() % (to - from + 1) + from;
}

void Fill_Matrix_Randomly(int Matrix[10][10], const short* Rows, const short* Columns)
{
    for (int i = 0; i < *Rows; i++)
    {
        for (int j = 0; j < *Columns; j++)
        {
            Matrix[i][j] = GenerateRandomNumber_InRange(1, 100);
        }
    }
}

void Print_Matrix(int Matrix[10][10], const short* Rows, const short* Columns)
{
    printf("\n\n--- The Following Is A (%dx%d) Random Matrix:\n\n", *Rows, *Columns);

    for (int i = 0; i < *Rows; i++)
    {
        for (int j = 0; j < *Columns; j++)
        {
            cout << setw(7) << Matrix[i][j];
        }
        cout << endl << endl;
    }
}

int ColumnSum(int Matrix[10][10], const short* Rows, const short TargetColumn)
{
    int Sum{ 0 };

    for (unsigned short i{ 0 }; i < *Rows; i++)
        Sum += Matrix[i][TargetColumn];

    return Sum;
}

void FillArrayWithSumOfMatrixColumns(int Matrix[10][10], const short* Rows, const short* Columns, int SumArray[10])
{
    for (unsigned short i = 0; i < *Columns; i++)
        SumArray[i] = ColumnSum(Matrix, Rows, i);
}

void Print_SumArray(int SumArray[10], const short* length)
{
    cout << "\n--- The Following Is The Sum Of Each Column In The Matrix:\n\n";
    for (unsigned short i{ 0 }; i < *length; i++)
        printf("-> Column[%d] = { %d }\n", i + 1, SumArray[i]);
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix[10][10];
    short Rows{ 0 }, Columns{ 0 };
    int SumArray[10];  // Array length == Columns

    Rows = Read_Positive_Number_InRange("-> Enter The Number Of Rows: ", 1, 10);
    Columns = Read_Positive_Number_InRange("-> Enter The Number Of Columns: ", 1, 10);

    Fill_Matrix_Randomly(Matrix, &Rows, &Columns);

    FillArrayWithSumOfMatrixColumns(Matrix, &Rows, &Columns, SumArray);

    Print_Matrix(Matrix, &Rows, &Columns);

    Print_SumArray(SumArray, &Columns);

    return 0;
}