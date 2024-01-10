#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include "MGLib.h"

using namespace std;
using namespace MGLib;

long long GenerateRandomNumber_InRange(long long from, long long to)
{
    return rand() % (to - from + 1) + from;
}

void Fill_Matrix_Randomly(int Array2D[10][10], const int Rows, const int Columns)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Columns; j++)
        {
            Array2D[i][j] = GenerateRandomNumber_InRange(1, 100);
        }
    }
}

void Print_Matrix(int Matrix[10][10], const int Rows, const int Columns)
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

int RowSum(int Matrix[10][10], const int Columns, const short RowNumber)
{
    int Sum{ 0 };
    
    for (int j = 0; j < Columns; j++)
        Sum += Matrix[RowNumber][j];
    
    return Sum;
}

void Print_MatrixAllRowsSum(int Matrix[10][10], const int Rows, const int Columns)
{
    cout << "--- The Following Is The Sum Of Each Raw In The Matrix:\n\n";
    for (int i = 0; i < Rows; i++)
        printf("-> Row[%d] = { %d }\n", i + 1, RowSum(Matrix, Columns, i));
}


int main()
{
    srand((unsigned)time(NULL));

    int Matrix[10][10];
    int Rows{ 0 }, Columns{ 0 };

    Rows = Read_Positive_Number_InRange("-> Enter The Number Of Rows: ", 1, 10);
    Columns = Read_Positive_Number_InRange("-> Enter The Number Of Columns: ", 1, 10);

    Fill_Matrix_Randomly(Matrix, Rows, Columns);

    Print_Matrix(Matrix, Rows, Columns);

    Print_MatrixAllRowsSum(Matrix, Rows, Columns);



    return 0;
}