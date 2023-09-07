#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int quarter_of1(int month)
{
  return (month >= 1 && month <= 3) ? 1 
       : (month >= 4 && month <= 6) ? 2
     : (month >= 7 && month <= 9)   ? 3
     : (month >= 10 && month <= 12) ? 4
                                    : 0;
}

int quarter_of2(int month)
{
  return (month + 2) / 3;
}

int quarter_of3(int month)
{
  return ceil(month / 3.0);
}

int main()
{

  cout << quarter_of1(9) << endl;
  cout << quarter_of2(9) << endl;
  cout << quarter_of3(9) << endl;

  return 0;
}