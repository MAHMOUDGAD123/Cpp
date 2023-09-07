#include <iostream>
#include <string>

using namespace std;

bool IsLower(const char &C)
{
  return ((C >= 97 && C <= 122));
}

void Result(const string &S)
{
  string *L = new string("");
  string *NL = new string("");
  bool *AllLowerCase = new bool{true};
  for (short i = 0; i < S.length(); i++)
  {
    if (IsLower(S[i])) 
      *L += S[i];
    else
    {
      *NL += S[i];
      *AllLowerCase = false;
    }
  }
  if(*AllLowerCase)
  {
    cout << "-> All Lower_Case Letters\n";
    cout << "-> Lower_Case Characters are    : " << *L << endl;
  }
  else
  {
    cout << "-> Not All Lower_Case Letters\n";
    cout << "-> Lower_Case Characters are    : " << *L << endl;
    cout << "-> Non-Lower_Case Characters are: " << *NL << endl;
  }
  delete L, NL, AllLowerCase;
}

int main()
{

  cout << "\n_______________________________________________(1)_______________________________________________\n\n";

  string S("abcdefghi");

  Result(S);

  cout << "\n_______________________________________________(2)_______________________________________________\n\n";

  string G("aBcDEfgHi");

  Result(G);

  cout << "\n_________________________________________________________________________________________________\n\n\n";

  return 0;
}