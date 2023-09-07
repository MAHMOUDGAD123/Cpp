#include <iostream>
#include <string>

using namespace std;

/*
  --> Alphabets Characters <--

  - Uppercase letters (A to Z)
  - Lowercase letters (a to z)

*/

bool IsAlpha(const char &C)
{
  return ((C >= 65 && C <= 90) || (C >= 97 && C <= 122));
}

void Test_Alphabets(const string &S)
{
  short *NOAlphbets = new short{0};
  string *Alpha = new string{""};
  string *Non_Alpha = new string{""};

  for (short i = 0; i < S.length(); i++)
  {
    if (IsAlpha(S[i]))
    {
      (*NOAlphbets)++;
      *Alpha += S[i];
    }
    else
    {
      *Non_Alpha += S[i];
    }
  }
  cout << "-> The String: \" " << S << " \"\n\n";
  cout << "-> Number Of Alphabets Characters     = " << *NOAlphbets << endl;
  cout << "-> Number Of Non-Alphabets Characters = " << S.length() - *NOAlphbets << endl;
  cout << endl;
  cout << "-> Alphabets Characters are    : \" " << *Alpha << " \"\n";
  cout << "-> Non-Alphabets Characters are: \" " << *Non_Alpha << " \"\n";

  delete NOAlphbets, Alpha, Non_Alpha;
}

int main()
{

  cout << "\n_______________________________________________(1)_______________________________________________\n\n";

  string S("AB149vk;22M37hgho.erHM,][=y-87fg");

  Test_Alphabets(S);

  cout << "\n_________________________________________________________________________________________________\n\n\n";

  return 0;
}