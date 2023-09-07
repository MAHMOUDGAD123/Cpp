#include <iostream>
#include <string>

using namespace std;

// Functions to remove '!' form a string

string RemoveExclamationMarks1(string str)
{
  string new_str = "";

  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] != '!')
    {
      new_str += str[i];
    }
  }

  return new_str;
}

string RemoveExclamationMarks2(string str)
{
  string new_str;

  for (const char &C : str)
  {
    if (C != '!')
    {
      new_str.push_back(C);
    }
  }

  return new_str;
}

int main()
{
  string Name = "M!ah!m!o!ud!!!! G!a!d!!!!!";

  cout << "\nThe Name With \'i\': " << Name << endl;

  cout << "\nThe Name Without \'i\': " << RemoveExclamationMarks2(Name) << endl;

  return 0;
}