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

void SumAllColumns(int Matrix[10][10], const short* Rows, const short* Columns)
{
    cout << "--- The Following Is The Sum Of Each Column In The Matrix:\n\n";
    for (unsigned short i{ 0 }; i  < *Columns; i ++)
        printf("-> Column[%d] = { %d }\n", i + 1, ColumnSum(Matrix, Rows, i));
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix[10][10];
    short Rows{ 0 }, Columns{ 0 };

    Rows = Read_Positive_Number_InRange("-> Enter The Number Of Rows: ", 1, 10);
    Columns = Read_Positive_Number_InRange("-> Enter The Number Of Columns: ", 1, 10);

    Fill_Matrix_Randomly(Matrix, &Rows, &Columns);

    Print_Matrix(Matrix, &Rows, &Columns);

    SumAllColumns(Matrix, &Rows, &Columns);


    return 0;
}