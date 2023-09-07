#include <iostream>
#include <string>

using namespace std;

bool IsDigit(const char &C)
{
  return (C >= 48 && C <= 57);
}

void Result(const string &S)
{
  string *D = new string("");
  string *ND = new string("");
  bool NotAllDigit = false;
  for (short i = 0; i < S.length(); i++)
  {
    if (!IsDigit(S[i]))
      NotAllDigit = true;

    (IsDigit(S[i])) ? *D += S[i] : *ND += S[i];
  }
  cout << "-> Digits Characters are    : " << *D << endl;
  cout << "-> Non-Digits Characters are: " << *ND << endl;
  (NotAllDigit) ? cout << "-> Not All Characters Are Digits (Invalid Number)" : cout << "-> All Characters are Digits (Valid Number)";

  delete D;
  delete ND;
}

int main()
{

  cout << "\n_______________________________________________(1)_______________________________________________\n\n";

  string S("51A647sdf3M48");

  Result(S);

  cout << "\n_______________________________________________(2)_______________________________________________\n\n";

  string G("100152612");

  Result(G);

  cout << "\n_________________________________________________________________________________________________\n\n\n";

  return 0;
}