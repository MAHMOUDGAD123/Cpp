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

void Fill_Matrix_Randomly(int Matrix[10][10], const unsigned short *Rows, const unsigned short *Columns)
{
  for (int i = 0; i < *Rows; i++)
  {
    for (int j = 0; j < *Columns; j++)
    {
      Matrix[i][j] = GenerateRandomNumber_InRange(1, 10);
    }
  }
}

void Print_Matrix(int Matrix[10][10], const unsigned short *Rows, const unsigned short *Columns)
{
  for (int i = 0; i < *Rows; i++)
  {
    for (int j = 0; j < *Columns; j++)
      cout << setw(7) << Matrix[i][j];
    cout << endl
         << endl;
  }
}

void Matrix_ZeroFill(int Matrix[10][10])
{
  for (unsigned short i = 0; i < 10; i++)
    for (unsigned short j = 0; j < 10; j++)
      Matrix[i][j] = 0;
}

void Print_DiagonalOfMatrix(int Matrix[10][10], const unsigned short *Rows, const unsigned short *Columns)
{
  printf("The Following Is The Diagonal Of (%dx%d) Matrix:\n\n", *Rows, *Columns);

  for (unsigned short i = 0; i < *Rows; i++)
  {
    for (unsigned short j = 0; j < *Columns; j++)
      (i == j) ? cout << setw(5) << Matrix[i][j] : cout << setw(5) << '\0';
    cout << endl << endl;
  }
}

int main()
{
  srand(1667982348);

  int Matrix[10][10];
  unsigned short Rows{0}, Columns{0};

  Rows = (unsigned short)Read_Positive_Number_InRange("\n\n-> Enter The Number Of Rows: ", 1, 10);
  Columns = (unsigned short)Read_Positive_Number_InRange("-> Enter The Number Of Columns: ", 1, 10);

  Matrix_ZeroFill(Matrix);

  Fill_Matrix_Randomly(Matrix, &Rows, &Columns);

  printf("\n\n--- The Following Is A (%dx%d) Random Matrix:\n\n", Rows, Columns);
  Print_Matrix(Matrix, &Rows, &Columns);

  cout << "\n\n#################################################################################\n\n";

  Print_DiagonalOfMatrix(Matrix, &Rows, &Columns);

  return 0;
}