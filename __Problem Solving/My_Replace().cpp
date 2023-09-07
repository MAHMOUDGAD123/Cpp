#include <iostream>

using namespace std;

size_t Str_Size(const char *S)
{
  size_t Counter = 0;

  while (S[Counter] != '\0')
    Counter++;

  return Counter;
}
size_t Str_Size(const string &S)
{
  size_t Counter = 0;

  while (S[Counter] != '\0')
    Counter++;

  return Counter;
}

// Replace a (len) characters of "Str" starting from index (start_pos) with the following:

string Replace(const string &Str, size_t start_pos, size_t len, const string &S)
{
  unsigned short Str_len = Str_Size(Str);

  if (start_pos >= Str_len)
    return Str;

  if (start_pos == 0 && len >= Str_len)
    return S;

  string temp_str = "";

  if (len == 0) // if len = 0 this will work like insertion
  {
    for (unsigned short index = 0; index < Str_len; index++)
    {
      if (index == start_pos)
        temp_str += S;

      temp_str += Str[index];
    }

    return temp_str;
  }

  unsigned short end_pos = start_pos + len - 1; // the last index of the replaced part of "Str"

  for (unsigned short Str_index = 0; Str_index < Str_len; Str_index++)
  {
    if (Str_index < start_pos || Str_index > end_pos)
      temp_str += Str[Str_index];
    else
    {
      temp_str += S;       // add "S"
      Str_index = end_pos; // to continue adding the rest of "Str"
    }
  }

  return temp_str;
}

string Replace(const string &Str, size_t start_pos, size_t len, const string &S, size_t sub_start_pos, size_t sub_len = -1)
{
  unsigned short Str_len = Str_Size(Str);

  if (start_pos >= Str_len)
    return Str;

  unsigned short S_len = Str_Size(S);

  if (sub_start_pos >= S_len)
    return Str;

  if (start_pos == 0 && len >= Str_len)
    return S;

  string temp_str = "";

  if (len == 0) // if len = 0 this will work like insertion
  {
    if (sub_len > S_len)
      sub_len = S_len;

    for (unsigned short Str_index = 0; Str_index < Str_len; Str_index++)
    {
      if (Str_index == start_pos)
        for (unsigned short S_index = sub_start_pos; S_index < sub_len; S_index++)
          temp_str += S[S_index];

      temp_str += Str[Str_index];
    }

    return temp_str;
  }

  unsigned short end_pos = start_pos + len - 1;

  for (unsigned short Str_index = 0; Str_index < Str_len; Str_index++)
  {
    if (Str_index < start_pos || Str_index > end_pos)
      temp_str += Str[Str_index];
    else
    {
      if (sub_start_pos == 0 && sub_len >= S_len)
        temp_str += S;
      else
      {
        unsigned short sub_end_pos = (sub_len > S_len) ? S_len : sub_start_pos + sub_len;

        for (unsigned short S_index = sub_start_pos; S_index < sub_end_pos; S_index++)
          temp_str += S[S_index];
      }

      Str_index = end_pos; // to continue adding the rest of "Str"
    }
  }

  return temp_str;
}

string Replace(const string &Str, size_t start_pos, size_t len, const char *S)
{
  unsigned short Str_len = Str_Size(Str);

  if (start_pos >= Str_len)
    return Str;

  if (start_pos == 0 && len >= Str_len)
    return S;

  string temp_str = "";

  if (len == 0) // if len = 0 this will work like insertion
  {
    for (unsigned short index = 0; index < Str_len; index++)
    {
      if (index == start_pos)
        temp_str += S;

      temp_str += Str[index];
    }

    return temp_str;
  }

  unsigned short end_pos = start_pos + len - 1; // the last index of the replaced part of "Str"

  for (unsigned short Str_index = 0; Str_index < Str_len; Str_index++)
  {
    if (Str_index < start_pos || Str_index > end_pos)
      temp_str += Str[Str_index];
    else
    {
      temp_str += S;
      Str_index = end_pos;
    }
  }

  return temp_str;
}

string Replace(const string &Str, size_t start_pos, size_t len, const char *S, size_t n)
{
  // n is the number of characters of "S" that will be replace with sub-string of "Str"

  unsigned short Str_len = Str_Size(Str);

  if (start_pos >= Str_len)
    return Str;

  if (start_pos == 0 && len >= Str_len)
    return S;

  string temp_str = "";

  if (len == 0) // if len = 0 this will work like insertion
  {
    for (unsigned short Str_index = 0; Str_index < Str_len; Str_index++)
    {
      if (Str_index == start_pos)
        for (unsigned short S_index = 0; S_index < n; S_index++)
          temp_str += S[S_index];

      temp_str += Str[Str_index];
    }

    return temp_str;
  }

  unsigned short end_pos = start_pos + len - 1; // the last index of the replaced part of "Str"
  unsigned short S_len = Str_Size(S);

  for (unsigned short Str_index = 0; Str_index < Str_len; Str_index++)
  {
    if (Str_index < start_pos || Str_index > end_pos)
      temp_str += Str[Str_index];
    else
    {
      if (n >= S_len)
      {
        temp_str += S;
        Str_index = end_pos;
      }
      else
      {
        for (unsigned short S_index = 0; S_index < n; S_index++)
          temp_str += S[S_index];

        Str_index = end_pos;
      }
    }
  }

  return temp_str;
}

string Replace(const string &Str, size_t start_pos, size_t len, size_t n, char C)
{
  // n is the number of copies of 'C' that will be replace with sub-string of "Str"

  unsigned short Str_len = Str_Size(Str);

  if (start_pos >= Str_len)
    return Str;

  string temp_str = "";

  if (start_pos == 0 && len >= Str_len)
  {
    // replace all "Str" characters with n copies of 'C'
    for (unsigned short i = 0; i < n; i++)
      temp_str += C;

    return temp_str;
  }

  if (len == 0) // if len = 0 this will work like insertion
  {
    for (unsigned short index = 0; index < Str_len; index++)
    {
      if (index == start_pos)
        for (unsigned short i = 0; i < n; i++)
          temp_str += C;

      temp_str += Str[index];
    }

    return temp_str;
  }

  unsigned short end_pos = start_pos + len - 1; // the last index of the replaced part of "Str"

  for (unsigned short Str_index = 0; Str_index < Str_len; Str_index++)
  {
    if (Str_index < start_pos || Str_index > end_pos)
      temp_str += Str[Str_index];
    else
    {
      for (size_t i = 0; i < n; i++)
        temp_str += C;

      Str_index = end_pos;
    }
  }

  return temp_str;
}

int main(void)
{
  string Str = "Mahmoud Abdelrahman Ismail Gad";
  //            012345678901234567890123456789
  string S = "Amira";

  // cout << "\n\"" << Replace(Str, 7, 1, S) << "\"\n";
  // cout << '\"' << Str.replace(7, 1, S) << "\"\n";

  // Str = "Mahmoud Abdelrahman Ismail Gad";
  //     012345678901234567890123456789

  // cout << "\n\"" << Replace(Str, 8, 0, S, 5) << "\"\n";
  // cout << '\"' << Str.replace(8, 0, S, 5) << "\"\n";

  // Str = "Mahmoud Abdelrahman Ismail Gad";
  // //     012345678901234567890123456789

  // cout << "\n\"" << Replace(Str, 0, 0, "Amira") << "\"\n";
  // cout << '\"' << Str.replace(0, 0, "Amira") << "\"\n";

  // Str = "Mahmoud Abdelrahman Ismail Gad";
  // //     012345678901234567890123456789

  // cout << "\n\"" << Replace(Str, 8, 0, "Amira", 3) << "\"\n";
  // cout << '\"' << Str.replace(8, 0, "Amira", 3) << "\"\n";

  // Str = "Mahmoud Abdelrahman Ismail Gad";
  // //     012345678901234567890123456789

  cout << "\n\"" << Replace(Str, 8, 0, 3, '&') << "\"\n";
  cout << '\"' << Str.replace(8, 0, 3, '&') << "\"\n";

  return 0;
}