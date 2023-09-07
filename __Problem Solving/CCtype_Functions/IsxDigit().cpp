#include <iostream>
#include <string>

using namespace std;

bool IsxDigit(const char &C)
{
  return ((C >= 48 && C <= 57) || (C >= 65 && C <= 70) || (C >= 97 && C <= 102)) ? true : false;
}

void Result(const string &S)
{
  string *xD = new string("");
  string *NxD = new string("");
  bool NotAllxDigit = false;
  for (short i = 0; i < S.length(); i++)
  {
    if (!IsxDigit(S[i]))
      NotAllxDigit = true;

    (IsxDigit(S[i])) ? *xD += S[i] : *NxD += S[i];
  }
  cout << "-> xDigits Characters are    : " << *xD << endl;
  cout << "-> Non-xDigits Characters are: " << *NxD << endl;
  (NotAllxDigit) ? cout << "-> Not All Characters Are xDigits (Invalid xNumber)" : cout << "-> All Characters are xDigits (Valid xNumber)";

  delete xD;
  delete NxD;
}

int main()
{

  cout << "\n_______________________________________________(1)_______________________________________________\n\n";

    string S("51FfG");

    Result(S);

  cout << "\n_______________________________________________(2)_______________________________________________\n\n";

    string G("10cFF");

    Result(G);

  cout << "\n_________________________________________________________________________________________________\n\n\n";

  return 0;
}