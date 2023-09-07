#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

long long ReadNumber(const char *const Msg = "")
{
  long long Number(0);
  cout << Msg;

  while (!(cin >> Number))
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nEnter A Valid Number:  ";
  }
  // to discard any non_numerics in the end of input
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  return Number;
}

string _to_string(long long _Num)
{
  if (_Num == 0)
    return "0";

  bool _isNegative(false);

  if (_Num < 0)
    _isNegative = true, _Num = -_Num;

  string s_Num;

  for (; _Num > 0; _Num /= 10)
    s_Num += ((_Num % 10) + '0'); // ex: 1 + 48 = 49 in ascii table

  if (_isNegative)
    s_Num += '-';

  return { s_Num.crbegin(), s_Num.crend() };
}

string __to_string(const long long N)
{
  stringstream ss;
  string Str;

  ss << N;
  ss >> Str;
  return Str;
}

int main()
{
  long long N{};

  for (;;)
  {
    N = ReadNumber("\nEnter A Number:  ");
    cout << "Your Number In String Is: \"" << _to_string(N) << "\"\n";
    cout << "Your Number In String Is: \"" << __to_string(N) << "\"\n";
  }

  return 0;
}