#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Not used
int SumOfDigits(int N)
{
  int Sum = 0;

  while (N > 0)
  {
    Sum += N % 10;
    N /= 10;
  }

  return Sum;
}

int SumOfDigits_Recursive(int N)
{
  return (N == 0) ? 0 : (N % 10) + SumOfDigits_Recursive(N / 10);
}

// It's a bullshit function
string SubtractSum(int N)
{
  vector<string> Fruits = {"kiwi", "pear", "banana", "melon", "pineapple", "apple", "cucumber", "orange", "grape", "cherry"};

  do
  {
    N -= SumOfDigits_Recursive(N);

  } while (N > Fruits.size());

  return Fruits[N];
}

int main()
{

  cout << SubtractSum(11) << endl;

  return 0;
}