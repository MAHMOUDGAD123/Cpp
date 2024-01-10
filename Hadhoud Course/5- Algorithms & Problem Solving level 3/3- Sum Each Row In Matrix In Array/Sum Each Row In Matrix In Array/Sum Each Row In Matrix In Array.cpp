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

void Fill_Matrix_Randomly(int Matrix[10][10], const short Rows, const short Columns)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Columns; j++)
        {
            Matrix[i][j] = GenerateRandomNumber_InRange(1, 100);
        }
    }
}

void Print_Matrix(int Matrix[10][10], const short Rows, const short Columns)
{
    printf("\n\n--- The Following Is A (%dx%d) Random Matrix:\n\n", Rows, Columns);
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Columns; j++)
        {
            cout << setw(7) << Matrix[i][j];
        }
        cout << endl << endl;
    }
}

int RowSum(int Matrix[10][10], const short Columns, const short RowNumber)
{
    int Sum{ 0 };

    for (int j = 0; j < Columns; j++)
        Sum += Matrix[RowNumber][j];

    return Sum;
}

void Fill_ArrayWithTheSumOfMatrixRows(int Matrix[10][10], const short Rows, const short Columns, int SumArray[10])
{
    for (int i = 0; i < Rows; i++)
        SumArray[i] = RowSum(Matrix, Columns, i);
}

void Print_SumArray(int SumArray[10], const short length)
{
    cout << "--- The Following Is The Sum Of Each Raw In The Matrix:\n\n";
    for (int i = 0; i < length; i++)
        printf("-> Row[%d] = { %d }\n", i + 1, SumArray[i]);
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix[10][10];
    short Rows{ 0 }, Columns{ 0 };
    int SumArray[10]; // SumArray[] length == Rows

    Rows = Read_Positive_Number_InRange("-> Enter The Number Of Rows: ", 1, 10);
    Columns = Read_Positive_Number_InRange("-> Enter The Number Of Columns: ", 1, 10);

    Fill_Matrix_Randomly(Matrix, Rows, Columns);

    Print_Matrix(Matrix, Rows, Columns);

    Fill_ArrayWithTheSumOfMatrixRows(Matrix, Rows, Columns, SumArray);

    Print_SumArray(SumArray, Rows);

    return 0;
}