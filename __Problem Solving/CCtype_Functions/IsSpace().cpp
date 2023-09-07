#include <iostream>
#include <string>

using namespace std;


/*
  -- Whitespace Characters --

  space (0x20, ' ')
  form feed (0x0c, '\f')
  line feed (0x0a, '\n')
  carriage return (0x0d, '\r')
  horizontal tab (0x09, '\t')
  vertical tab (0x0b, '\v')

*/


bool isSpace(const char &C)
{
  return (C == ' ' || C == '\f' || C == '\n' || C == '\r' || C == '\t' || C == '\v');
}

void Remove_WhiteSpaces(const string &S)
{
  string *New_S = new string("");
  for (short i = 0; i < S.length(); i++)
  {
    if (!isSpace(S[i])) 
      *New_S += S[i];
  }
  cout << "\n-> S After Remove Whitespaces Characters: " << *New_S << endl;

  delete New_S;
}

int main()
{

  cout << "\n_______________________________________________(1)_______________________________________________\n\n";


    string S("Mahm\toud_Abd\telrah\fman\n_ Ismail_\nGad");

    cout << "-> S Before Remove Whitespace Characters: " << S << endl;

    Remove_WhiteSpaces(S);


  cout << "\n_________________________________________________________________________________________________\n\n\n";

  return 0;
}