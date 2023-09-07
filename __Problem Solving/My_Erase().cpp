#include <iostream>

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

void Erase(string &Str, size_t start_pos = 0, size_t len = -1)
{
  // erase a 'len' characters starting from index 'start_pos' of "Str"

  size_t Str_len = Str_Size(Str);

  if (len > 0) // Do nothing when len = 0
  {
    if (start_pos == 0 && len >= Str_len)
    {
      // Erase all
      Str = "";
    }
    else
    {
      string temp_str = "";

      if (len < Str_len)
        len = start_pos + len - 1;

      for (size_t index = 0; index < Str_len; index++)
        if (index < start_pos || index > len) // Don't add this range (start_pos --> len)
          temp_str += Str[index];

      Str = temp_str;
    }
  }
}

int main(void)
{
  string Str = "Mahmoud Abdelrahman Ismail Gad";

  cout << "\nMy Erase:\n";
  cout << "- Str Before Erase: \"" << Str << "\"" << endl;
  cout << "- Size Before Erase = " << Str_Size(Str) << endl;

  Erase(Str);

  cout << "\n- Str After Erase : \"" << Str << "\"" << endl;
  cout << "- Size After Erase  = " << Str_Size(Str) << endl;
  cout << endl;

  Str = "Mahmoud Abdelrahman Ismail Gad";

  cout << "\nC++ Erase:\n";
  cout << "- Str Before Erase: \"" << Str << "\"" << endl;
  cout << "- Size Before Erase = " << Str_Size(Str) << endl;

  Str.erase();

  cout << "\n- Str After Erase : \"" << Str << "\"" << endl;
  cout << "- Size After Erase  = " << Str_Size(Str) << endl;
  cout << endl;

  return 0;
}