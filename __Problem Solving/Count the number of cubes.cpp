#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

int CountCubes(int cuts)
{
  int TotalNumberOfCubes = (abs(cuts) != 0) ? pow(abs(cuts) + 1, 3): 1;

  int NumberOfHiddenCubes = (abs(cuts) != 0) ? pow(abs(cuts) - 1, 3): 0;

  return TotalNumberOfCubes - NumberOfHiddenCubes;
}

int main()
{
  int cuts = abs(-1);
  cout << "Number Of Cubes of [" << cuts << "] cuts"
       << " = " << CountCubes(cuts) << endl;

  return 0;
}