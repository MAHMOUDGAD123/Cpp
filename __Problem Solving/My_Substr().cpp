#include <iostream>
#include <string>

using namespace std;

size_t Str_Size(const string &Str)
{
  size_t Counter{0};
  while (Str[Counter] != '\0')
    Counter++;
  return Counter;
}
size_t Str_Size(const char *Str)
{
  size_t Counter{0};
  while (Str[Counter] != '\0')
    Counter++;
  return Counter;
}

string Substr(const string &Str, size_t start_pos = 0, size_t Sub_len = -1)
{
  // Copy a sub-string of length (Sub_len) starting from index (start_pos) of "Str"

  size_t Str_len = Str_Size(Str);

  if (start_pos == 0 && Sub_len >= Str_len)
    return Str;

  if (Sub_len < Str_len)
    Sub_len += start_pos;

  string Sub_str = "";

  for (size_t index = start_pos; (index < Sub_len && index < Str_len); index++)
    Sub_str += Str[index];

  return Sub_str;
}

int main(void)
{
  string Str = "Mahmoud_Abdelrahman_Ismail_Gad";

  cout << endl;
  cout << Substr(Str, 0, 10) << endl;
  cout << Str.substr(0, 10) << endl;
  cout << endl;

  return 0;
}