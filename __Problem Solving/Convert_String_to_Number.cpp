#include <iostream>
#include <string>
#include <cmath>

using namespace std;


// To check if this character is digit or not
bool isDigit(const char &C)
{
  return (C >= 48 && C <= 57);
}

long long string_to_number(const string &S)
{
  long long N{0};
  unsigned short i{0};

  if(S[0] == '-') 
    i++;

  for (i; i < S.length(); i++)
  {
    if(isDigit(S[i]))
      N = N * 10 + (S[i] - '0');
    else
      break;
  }
  return (S[0] == '-') ? N *= -1 : N;
}


int main()
{
  const string S = "";

  cout << endl;
  cout << string_to_number(S) << endl;
  cout << endl;

  return 0;
}