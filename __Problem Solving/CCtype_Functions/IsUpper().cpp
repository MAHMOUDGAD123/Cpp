#include <iostream>
#include <string>

using namespace std;

bool IsUpper(const char C)
{
  return ((C >= 65 && C <= 90));
}

void Result(const string &S)
{
  string *U = new string("");
  string *NU = new string("");
  bool *AllUpperCase = new bool{true};
  for (short i = 0; i < S.length(); i++)
  {
    if (IsUpper(S[i])) 
      *U += S[i];
    else
    {
      *NU += S[i];
      *AllUpperCase = false;
    }
  }
  if(*AllUpperCase)
  {
    cout << "-> All Upper_Case Letters\n";
    cout << "-> Upper_Case Characters are    : " << *U << endl;
  }
  else
  {
    cout << "-> Not All Upper_Case Letters\n";
    cout << "-> Upper_Case Characters are    : " << *U << endl;
    cout << "-> Non-Upper_Case Characters are: " << *NU << endl;
  }
  delete U, NU, AllUpperCase;
}

int main()
{

  cout << "\n_______________________________________________(1)_______________________________________________\n\n";

  string S("ABCDEFGHI");

  Result(S);

  cout << "\n_______________________________________________(2)_______________________________________________\n\n";

  string G("ABCDEfGHi");

  Result(G);

  cout << "\n_________________________________________________________________________________________________\n\n\n";

  return 0;
}