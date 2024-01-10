#include <iostream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include "MGLib.h"

using namespace std;
using namespace MGLib;

void FillMatrixWithOrderdNumbers(int Matrix[10][10], const unsigned short* Rows, const unsigned short* Columns)
{
    unsigned short Counter{ 1 };

    for (unsigned short i = 0; i < *Rows; i++)
    {
        for (unsigned short j = 0; j < *Columns; j++)
        {
            Matrix[i][j] = Counter;
            Counter++;
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix[10][10];
    unsigned short Rows{ 0 }, Columns{ 0 };

    Rows = (unsigned short)Read_Positive_Number_InRange("-> Enter The Number Of Rows: ", 1, 10);
    Columns = (unsigned short)Read_Positive_Number_InRange("-> Enter The Number Of Columns: ", 1, 10);

    FillMatrixWithOrderdNumbers(Matrix, &Rows, &Columns);

    printf("\n\n--- The Following Is A (%dx%d) Ordered Matrix:\n\n", Rows, Columns);
    Print_Matrix(Matrix, &Rows, &Columns);


    return 0;
}