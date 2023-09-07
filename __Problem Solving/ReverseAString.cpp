#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string ReadTxt(const char *Message = "")
{
  cout << Message;
  string Txt;
  getline(cin >> ws, Txt);
  return Txt;
}

string Reverse_String(const string &str)
{
  string R_str = "";

  for (int i = (int)str.length() - 1; i >= 0; i--)
    R_str += str[i];

  return R_str;
}

string RevStr(const string &Str)
{
  return string(Str.rbegin(), Str.rend());
}

int main()
{
  string Str;

  for (;;)
  {
    Str = ReadTxt("\n\n=> Enter A String:  ");

    cout << "\n- Original String Is: \"" << Str << "\"\n\n";

    cout << "- String After Reverse Is: \"" << Reverse_String(Str) << '\"';
    cout << "\n- String After Reverse Is: \"" << RevStr(Str) << '\"';
  }

  return 0;
}