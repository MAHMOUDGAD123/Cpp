#include <iostream>

using namespace std;

size_t CStr_length(const string &Str, size_t start_pos = 0)
{
  size_t Counter = 0;

  for (size_t index = start_pos; Str[index] != '\0'; index++)
    Counter++;

  return Counter;
}

int main(void)
{
  string Str = "Mahmoud Gad";
  Str = "";

  cout << CStr_length(Str) << endl;
  cout << CStr_length(Str, 7) << endl;

  return 0;
}