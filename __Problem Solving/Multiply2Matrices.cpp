#include <iostream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>

using namespace std;

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

long GenerateRandomNumber_InRange(long from, long to)
{
  return rand() % (to - from + 1) + from;
}

void Print_Matrix(int Matrix[10][10], const unsigned short Rows, const unsigned short Columns)
{
  for (int i = 0; i < Rows; ++i)
  {
    for (int j = 0; j < Columns; ++j)
    {
      cout << setw(7) << Matrix[i][j];
    }
    cout << endl
         << endl;
  }
}

void Matrix_ZeroFill(int Matrix[10][10])
{
  for (unsigned short i = 0; i < 10; ++i)
    for (unsigned short j = 0; j < 10; ++j)
      Matrix[i][j] = 0;
}

void Fill_Matrix_Randomly(int Matrix[10][10], const unsigned short Rows, const unsigned short Columns)
{
  for (int i = 0; i < Rows; i++)
    for (int j = 0; j < Columns; j++)
      Matrix[i][j] = GenerateRandomNumber_InRange(1, 10);
}

int MultiplyRow_Column(int Matrix_A[10][10], int Matrix_B[10][10], unsigned short Dimension,
                       unsigned short RowNumber, unsigned short ColumnNumber)
{
  // Dimension = A_Columns = B_Rows
  int Result{0};

  for (unsigned short i = 0; i < Dimension; ++i)
    Result += Matrix_A[RowNumber][i] * Matrix_B[i][ColumnNumber];

  return Result;
}

void Multiply2Matrices(int Matrix_A[10][10], int Matrix_B[10][10], int Matrix_AB[10][10],
                       unsigned short A_Rows, unsigned short A_Columns,
                       unsigned short B_Rows, unsigned short B_Columns)
{
  // Result = A x B => (A_Columns x B_Rows) => Matrix_AB
  // Coulmns of A must equal to Rows of B

  if (A_Columns == B_Rows)
  {
    for (unsigned short i = 0; i < A_Rows; ++i)
      for (unsigned short j = 0; j < B_Columns; ++j)
        Matrix_AB[i][j] = MultiplyRow_Column(Matrix_A, Matrix_B, A_Columns, i, j);
  }
  else
  {
    cout << "\n\n--> Invalid, Matrix Multiplication { A_Columns != B_Rows }" << endl
         << endl;
  }
}


int main()
{
  int Matrix_A[10][10], Matrix_B[10][10], Matrix_AB[10][10];
  unsigned short A_Rows{0}, A_Columns{0};
  unsigned short B_Rows{0}, B_Columns{0};

  A_Rows = (unsigned short)Read_Positive_Number_InRange("\n\n-> Enter The Rows Of Matrix_A: ", 1, 10);
  A_Columns = (unsigned short)Read_Positive_Number_InRange("-> Enter The Columns Of Matrix_A: ", 1, 10);

  B_Rows = (unsigned short)Read_Positive_Number_InRange("\n-> Enter The Rows Of Matrix_B: ", 1, 10);
  B_Columns = (unsigned short)Read_Positive_Number_InRange("-> Enter The Columns Of Matrix_B: ", 1, 10);

  Matrix_ZeroFill(Matrix_A);
  Matrix_ZeroFill(Matrix_B);
  Matrix_ZeroFill(Matrix_AB);

  Fill_Matrix_Randomly(Matrix_A, A_Rows, A_Columns);
  Fill_Matrix_Randomly(Matrix_B, B_Rows, B_Columns);

  printf("\n\n--- The Following Is A (%dx%d) Random Matrix_A:\n\n", A_Rows, A_Columns);
  Print_Matrix(Matrix_A, A_Rows, A_Columns);

  printf("\n\n--- The Following Is A (%dx%d) Random Matrix_B:\n\n", B_Rows, B_Columns);
  Print_Matrix(Matrix_B, B_Rows, B_Columns);

  Multiply2Matrices(Matrix_A, Matrix_B, Matrix_AB, A_Rows, A_Columns, B_Rows, B_Columns);

  if (A_Columns == B_Rows) // Validation --> A_Columns must equals to B_Rows
  {
    printf("\n\n--- The Following Is The (%dx%d) Result Matrix:\n\n", A_Rows, B_Columns);
    Print_Matrix(Matrix_AB, A_Rows, B_Columns);
  }

  return 0;
}