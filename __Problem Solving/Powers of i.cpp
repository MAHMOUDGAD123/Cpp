#include <iostream>
#include <cmath>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

string pofi1(unsigned n)
{
  if (n % 2 == 0)
  {
    if ((n / 2) % 2 == 0)
    {
      return "1";
    }
    else
    {
      return "-1";
    }
  }
  else
  {
    if (((n - 1) / 2) % 2 == 0)
    {
      return "i";
    }
    else
    {
      return "-i";
    }
  }
}

string pofi2(unsigned n)
{
  return vector<string>{"1", "i", "-1", "-i"}[n % 4];
}

string pofi3(unsigned n)
{
  return (string[]){"1", "i", "-1", "-i"}[n % 4];
}

string pofi4(unsigned n)
{
  return (n % 4 == 0) ? "1" : (n % 4 == 1) ? "i" : (n % 4 == 2) ? "-1" : "-i";
}


int main()
{
  short n = 11;

  cout << pofi2(n) << endl;

  return 0;
}
