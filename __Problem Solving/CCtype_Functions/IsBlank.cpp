#include <iostream>
#include <string>

using namespace std;

/*
  --> Blank Characters <--

  By default, space ' ' and horizontal tab '\t' are considered as blank characters.

*/

bool IsBlank(const char &C)
{
  return (C == 9 || C == 32);
}

void Test_Blank(const string &S)
{
  for (short i = 0; i < S.length(); i++)
  {
    (IsBlank(S[i])) ? cout << '\n' : cout << S[i];
  }
}

int main()
{

  cout << "\n_______________________________________________(1)_______________________________________________\n\n";

  string S("Mahmoud Abdelrahaman Ismail\tAbdelrahaman Ismail\tGad");

  Test_Blank(S);

  cout << "\n_________________________________________________________________________________________________\n\n\n";

  return 0;
}