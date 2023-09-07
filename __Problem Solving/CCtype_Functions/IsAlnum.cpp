#include <iostream>
#include <string>

using namespace std;

/*
  --> Alphabet-Numeric Sharacters <--

  - Uppercase letters (A to Z)
  - Lowercase letters (a to z)
  - Decimal digit characters (0 -> 9)

*/

bool IsDigit(const char &S)
{
  return (S >= 48 && S <= 57);
}

bool IsAlpha(const char &S)
{
  return ((S >= 65 && S <= 90) || (S >= 97 && S <= 122));
}

bool IsAlnum(const char &S)
{
  return ((S >= 65 && S <= 90) || (S >= 97 && S <= 122) || (S >= 48 && S <= 57));
}


void Test_AlphNumberic(const string &S)
{
  short *AlphNum = new short{0};
  short *Alpha = new short{0};
  short *Digit = new short{0};
  short *Non_AlphaNum = new short {0};

  for(short i{0} ; i < S.length(); i++)
  {
    if (IsAlnum(S[i]) && IsAlpha(S[i]))
    {
      (*AlphNum)++;
      (*Alpha)++;
    }
    else if (IsAlnum(S[i]) && IsDigit(S[i]))
    {
      (*AlphNum)++;
      (*Digit)++;
    }
    else
    {
      (*Non_AlphaNum)++;
    }
  }
  cout << "Number Of Alpha Characters            = " << *Alpha << endl;
  cout << "Number Of Digit Characters            = " << *Digit << endl;
  cout << "Number Of AlphaNumeric Characters     = " << *AlphNum << endl;
  cout << "Number Of Non-AlphaNumeric Characters = " << *Non_AlphaNum << endl;

  delete Alpha, Digit, AlphNum, Non_AlphaNum;
}

int main()
{

  cout << "\n_______________________________________________(1)_______________________________________________\n\n";

  string S("ag;7f9d[kr4871%$#@fdg234}8.fs!*&/f()4");

  Test_AlphNumberic(S);

  cout << "\n_________________________________________________________________________________________________\n\n\n";

  return 0;
}