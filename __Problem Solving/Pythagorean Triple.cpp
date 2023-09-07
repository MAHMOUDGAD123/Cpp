#include <iostream>
#include <string>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

bool PythagoreanTriple1(const unsigned int a, const unsigned int b, const unsigned int c)
{
  // Using pointers
  // (L) -> longest side ----- (S1,S2) -> other sides __ of Triangle
  const unsigned int *L, *S1, *S2;

  if (a > b && a > c)
  {
    L = &a;
    S1 = &b;
    S2 = &c;
  }
  else if(b > a && b > c)
  {
    L = &b;
    S1 = &a;
    S2 = &c;
  }
  else
  {
    L = &c;
    S1 = &a;
    S2 = &b;
  }

  return (pow(*L, 2) == pow(*S1, 2) + pow(*S2, 2));
}

bool PythagoreanTriple2(const unsigned int a, const unsigned int b, const unsigned int c)
{
  if (a > b && a > c)
  {
    return (a * a == b * b + c * c);
  }
  else if (b > a && b > c)
  {
    return (b * b == a * a + c * c);
  }
  else
  {
    return (c * c == b * b + a * a);
  }
}

bool PythagoreanTriple3(const unsigned int a, const unsigned int b, const unsigned int c)
{
  vector<unsigned int> v{a, b, c};

  // Sort vector elements from smaller to larger.
  sort(v.begin(), v.end());

  return (v[0] * v[0] + v[1] * v[1] == v[2] * v[2]);
}

bool PythagoreanTriple4(const unsigned int a, const unsigned int b, const unsigned int c)
{
  return (a * a == b * b + c * c) || (b * b == a * a + c * c) || (c * c == b * b + a * a);
}

int main()
{
  cout << PythagoreanTriple2(3, 4, 5) << endl; // true
  cout << PythagoreanTriple2(86, 45, 10) << endl; // false

  return 0;
}