#include <iostream>
#include <string>

using namespace std;

string Read_Txt(const char *Message)
{
  string Txt;
  cout << Message;

  getline(cin, Txt);

  return Txt;
}

size_t Str_Size(const string &Str)
{
  size_t Counter{0};
  while (Str[Counter] != '\0')
    Counter++;
  return Counter;
}

size_t Find(const string &Str, const string &S, size_t start_pos = 0)
{
  // Search for 'S' in "Str" - starting from (start_pos) & return the index of first char in it

  size_t S_length = Str_Size(S);
  size_t Str_length = Str_Size(Str);

  if (S_length == 1)
  {
    // Work like character Find()
    for (size_t index = start_pos; index < Str_length; index++)
      if (Str[index] == S[0])
        return index;
  }
  else
  {
    size_t Target_index = 0;

    for (size_t Str_index = start_pos; Str_index < Str_length; Str_index++)
    {
      if (Str[Str_index] == S[0]) // When first character of "Str" equal to first character of "S"
      {
        Target_index = Str_index;

        for (unsigned short S_index = 1; S_index < S_length; S_index++)
        {
          Str_index++;

          if (S[S_index] != Str[Str_index])
            break;

          if (S_index == S_length - 1 && S[S_index] == Str[Str_index])
            return Target_index; // if all character found
        }
      }
    }
  }
  return -1; // 18446744073709551615ULL  --> unsigned long long overfolw
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

void Print_WordsInString(string Str)
{
  size_t found = 0;
  string delimiters = " "; // Something we need to ignore & use it to find words
  string Word;

  unsigned short delim_len = Str_Size(delimiters); // delimiters length

  // use Find() function to get the position of the delimiter
  while ((found = Find(Str, delimiters)) != string::npos)
  {
    Word = Substr(Str, 0, found); // Store Word
    if (Word != "")
      cout << Word << endl;

    // Erase --> (Word & delimiters) and move to next word
    Erase(Str, 0, (found + delim_len));
  }

  if (Str != "")
    cout << Str << endl; // Print last Word
}

int main(void)
{
  string S = Read_Txt("Enter A String--> ");

  Print_WordsInString(S);

  return 0;
}