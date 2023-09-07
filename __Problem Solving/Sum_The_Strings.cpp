#include <iostream>
#include <string>
#include <cmath>
#include <chrono>

using namespace std;
using namespace std::chrono;

bool IsDigit(char C)
{
  return (C >= 48 && C <= 57);
}

long long To_Number(const string &S)
{
  long long N = 0;
  unsigned short i = 0;
  const unsigned short len = S.length();

  for (((S[0] == '-') ? ++i : i); i < len; i++)
  {
    if (IsDigit(S[i]))
      N = N * 10 + (S[i] - '0');
    else
      break;
  }
  return (S[0] == '-') ? -N : N;
}

string Reverse_String(const string &str)
{
  string R_str = "";

  for (int i = (int)str.length() - 1; i >= 0; i--)
    R_str += str[i];

  return R_str;
}

string To_String(const long long &N)
{
  if (N == 0)
    return "0";

  string S = "";
  long long Num = (N < 0) ? -N : N;

  // '0' = 48
  while (Num > 0)
    S += (Num % 10) + 48, Num /= 10;

  return Reverse_String((N < 0) ? S + '-' : S);
}

string sum_str(const string &a, const string &b)
{
  return To_String(To_Number(a) + To_Number(b));
}

//**********************************************************************************
// if either input is an empty "" string, consider it as zero "0".
// Using built in functions
string sum_str1(const string &a, const string &b)
{
  return to_string(stoi((a == "") ? "0" : a) + stoi((b == "") ? "0" : b));
}

int main()
{
  const string S1 = "";
  const string S2 = "";

  cout << '\n';

  auto start = high_resolution_clock::now();

  cout << "Result = " << sum_str(S1, S2); // test

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<microseconds>(stop - start);

  cout << "\nTime taken by function: " << duration.count() << " microseconds"
       << "\n\n";

  //=========================================================================================

  // start = high_resolution_clock::now();

  // cout << "Result = " << sum_str1(S1, S2); // test

  // stop = high_resolution_clock::now();

  // duration = duration_cast<microseconds>(stop - start);

  // cout << "\nTime taken by function: " << duration.count() << " microseconds" << "\n\n";

  return 0;
}