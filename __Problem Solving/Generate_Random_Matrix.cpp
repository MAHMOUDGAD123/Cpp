#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

double Read_Positive_Number(string Message = "")
{
    double Number = 0;

    cout << Message;
    cin >> Number;

    while (cin.fail() || !(Number > 0))
    {
        cin.clear();
        cin.ignore(10000000, '\n');

        cout << "-> Invalid Number, Enter A Positive Number? |--> ";
        cin >> Number;
    }

    return Number;
}

long long GenerateRandomNumber_InRange(long long from, long long to)
{
    return rand() % (to - from + 1) + from;
}

void Print_DynamicMatrix(int *Matrix, const int Rows, const int Columns)
{
    int Counter{0};

    printf("\n\n-> The Following Is A (%dx%d) Random Matrix:\n\n", Rows, Columns);
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Columns; j++)
        {
            cout << setw(7) << Matrix[Counter];
            Counter++;
        }
        cout << endl
             << endl;
    }
}

void Fill_DynamicMatrix_WithRandomNumbers(int *Matrix, const int Rows, const int Columns)
{
    int Counter{0};

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Columns; j++)
        {
            Matrix[Counter] = GenerateRandomNumber_InRange(1, 100);
            Counter++;
        }
    }
}

int MatrixSum(int *Matrix, const int Rows, const int Columns)
{
    int Counter{0}, Sum{0};

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Columns; j++)
        {
            Sum += Matrix[Counter];
            Counter++;
        }
    }
    return Sum;
}

int main()
{
    srand(65478167);

    int Rows = Read_Positive_Number("\n\n-> Enter The Number Of Rows: ");
    int Columns = Read_Positive_Number("-> Enter The Number Of Columns: ");

    int *Matrix = new int[Rows * Columns];

    Fill_DynamicMatrix_WithRandomNumbers(Matrix, Rows, Columns);

    cout << "__________________________________________________________";

    Print_DynamicMatrix(Matrix, Rows, Columns);

    printf("\n-> The Matrix Sum = { %d }", MatrixSum(Matrix, Rows, Columns));

    cout << "\n__________________________________________________________\n\n\n\n";

    delete[] Matrix;

    return 0;
}