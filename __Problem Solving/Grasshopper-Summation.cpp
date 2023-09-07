#include <iostream>
#include <cmath>

using namespace std;

int summation1(int num)
{
  int sum = 0;
  for (short i = 1; i <= num; i++)
    sum += i;
  return sum;
}

int summation2(int num)
{
  return (num == 0) ? 0 : num + summation2(num - 1);
}

int summation3(int num)
{
  return num * (num + 1) / 2;
}

int main()
{
  cout << endl;
  cout << summation1(10) << endl;
  cout << summation2(10) << endl;
  cout << summation3(10) << endl;
  cout << endl;

  return 0;
}
