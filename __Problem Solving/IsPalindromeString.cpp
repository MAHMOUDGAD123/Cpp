#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*
  && To reverse a string use this:
  -->  reverse(str.begin(), str.end());
  or
  -->  str = string(str.rbegin(), str.rend());



  && To reverse a vector use this:
  -->  V = vector(V.rbegin(), V.rend());

*/

void StringToUpperCase(string &str)
{
  for (char &C : str)
  {
    if (C >= 97 && C <= 122) // Check if a small letter
      C -= ' ';              // ' ' == 32
  }
}

string ReverseAString(string str)
{
  string R_str;

  for (short i = str.length() - 1; i >= 0; i--)
    R_str += str[i];

  return R_str;
}

bool isPalindrom1(const string &str)
{
  return (str == ReverseAString(str));
}

bool isPalindrom2(const string &str)
{
  string lstr = str;
  for (char &c : lstr)
    c = toupper(c);
  return lstr == string(lstr.rbegin(), lstr.rend());
}

int main()
{
  string Text = "";

  cout << "\n\nEnter A Text:--> ";
  cin >> Text;

  if (isPalindrom1(Text))
  {
    cout << "\n\nText Is Plaindrome\n\n";
  }
  else
  {
    cout << "\n\nYour Text Isn't Palindrome\n\n";
  }

  return 0;
}