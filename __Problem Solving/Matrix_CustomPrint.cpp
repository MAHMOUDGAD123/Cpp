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

unsigned short String_Size(const char *S)
{
  unsigned short Counter{0};

  while (S[Counter] != '\0')
    Counter++;

  return Counter;
}

bool IsDigit(const char &C)
{
  return (C >= 48 && C <= 57);
}

void Print_Column(int Matrix[10][10], const unsigned short *Rows, const unsigned short ColumnNumber)
{
  cout << "\n--> Column (" << ColumnNumber + 1 << ")\n\n";
  for (unsigned short i = 0; i < *Rows; i++)
  {
    cout << setw(3) << Matrix[i][ColumnNumber];
    cout << "\n\n";
  }
}

void Print_Row(int Matrix[10][10], const unsigned short *Columns, const unsigned short RowNumber)
{
  cout << "\n--> Row (" << RowNumber + 1 << ")\n\n";
  for (unsigned short i = 0; i < *Columns; i++)
  {
    cout << setw(7) << Matrix[RowNumber][i];
  }
  cout << endl;
}

bool Check_Digits(const char *Target, unsigned short StartPoint = 0, unsigned short EndPoint = 0)
{
  EndPoint = (EndPoint == 0) ? String_Size(Target) : EndPoint++;

  // Check from element[1]
  for (unsigned short i{StartPoint}; i < EndPoint; i++)
  {
    if (!IsDigit(Target[i]))
      return false;
  }
  return true;
}

bool CharacterFind(const char C, const char *CheckList)
{
  unsigned short length{String_Size(CheckList)};

  for (unsigned short i = 0; i < length; i++)
  {
    if (C == CheckList[i])
      return true;
  }
  return false;
}

unsigned short StringToNumber(const char *Target)
{
  unsigned short length{String_Size(Target)};
  unsigned short Number{0};

  for (unsigned short i = 1; i < length; i++)
    Number = Number * 10 + (Target[i] - '0');

  return Number;
}

void MatrixCustomPrint(int Matrix[10][10], const unsigned short *Rows, const unsigned short *Columns, const char *Target = nullptr)
{
  if (Target == nullptr || Target[0] == '\0') // Print All Matrix if input is { Empty or "" }
  {
    printf("\n\n--- The Following Is A (%dx%d) Random Matrix:\n\n", *Rows, *Columns);
    Print_Matrix(Matrix, Rows, Columns);
  }
  // Check the user input first
  // If element[0] != 'R' || 'r' || 'C' || 'c' --> Invalid
  // All elements after element[0] must be 'Digits'
  // Element[1] can't be '0'
  else if (CharacterFind(Target[0], "CcRr") && Check_Digits(Target, 1) && Target[1] != '0')
  {
    if (Target[0] == 'C' || Target[0] == 'c')
    {
      unsigned short ColumnNumber = StringToNumber(Target);

      if (ColumnNumber <= *Columns)
        Print_Column(Matrix, Rows, ColumnNumber - 1);
      else
        cout << "\n\n-> Column " << ColumnNumber << " Is Invalid :-(\n\n";
    }
    else if (Target[0] == 'R' || Target[0] == 'r')
    {
      unsigned short RowNumber = StringToNumber(Target);

      if (RowNumber <= *Rows)
        Print_Row(Matrix, Columns, RowNumber - 1);
      else
        cout << "\n\n-> Row " << RowNumber << " Is Invalid :-(\n\n";
    }
  }
  else
  {
    cout << "\nInvalid Input :-(, Input Must Be Something Like The Following:\n";
    cout << "- For Columns -> \"C7\" Or \"c5\".\n";
    cout << "- For Rows    -> \"R7\" Or \"r5\".\n";
    cout << "- Starting From 1 -> \"C0\" or \"R0\" Is Invalid.\n";
    cout << "- If The Input Is Empty Or \"\" -> The Function Will Print The Full Matrix.";
    cout << endl
         << endl;
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

  // MatrixCustomPrint(Matrix, &Rows, &Columns);
  // MatrixCustomPrint(Matrix, &Rows, &Columns, "");

  MatrixCustomPrint(Matrix, &Rows, &Columns, "R7");
  MatrixCustomPrint(Matrix, &Rows, &Columns, "c7");

  return 0;
}