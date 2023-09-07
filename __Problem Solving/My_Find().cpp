#include <iostream>
#include <string>
#include <iomanip>

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

char ToLowerCase(const char ch)
{
  return (ch >= 65 && ch <= 90) ? ch + ' ' : ch;
}

size_t Find(const string &Str, const char &C, size_t start_pos = 0)
{
  // Search for 'C' in "Str" - starting from (start_pos) & return it's index

  size_t length = Str_Size(Str);

  for (size_t index = start_pos; index < length; index++)
    if (Str[index] == C)
      return index;

  return -1; // 18446744073709551615ULL  --> unsigned long long overfolw
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
size_t Find(const string &Str, const char *S, size_t start_pos = 0)
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

size_t rFind(const string &Str, const char &C, size_t start_pos = -1)
{
  size_t length = Str_Size(Str);

  if (length == 0)
    return -1;

  if (start_pos >= length)
    start_pos = length - 1;

  for (size_t index = start_pos; index >= 0; index--)
    if (Str[index] == C)
      return index;

  return -1; // 18446744073709551615ULL  --> unsigned long long overfolw
}
size_t rFind(const string &Str, const string &S, size_t start_pos = -1)
{
  // Search for 'S' in "Str" - starting from (start_pos) & return the index of first character if found

  size_t S_length = Str_Size(S);
  size_t Str_length = Str_Size(Str);

  if (Str_length == 0 || S_length == 0)
    return -1;

  if (S_length == 1) // when "S" is just a character
  {
    for (long long index = start_pos; index >= 0; index--)
      if (Str[index] == S[0])
        return index;
  }
  else
  {
    size_t Target_index = 0;

    if (start_pos >= Str_length)
      start_pos = Str_length - 1;

    for (long long Str_index = start_pos; Str_index >= 0; Str_index--)
    {
      if (Str[Str_index] == S[0]) // When first character of "Str" equal to first character of "S"
      {
        Target_index = Str_index; // Make the target_index = index of first character of word

        // Search for the other characters of "S"
        for (unsigned short S_index = 1; S_index < S_length; S_index++)
        {
          Str_index++;

          if (S[S_index] != Str[Str_index])
          {
            Str_index = Target_index; // restore Str_index to the last value to continue from it
            break;                    // Break this loop if any char of "S" not equal to "Str" char
          }

          if (S_index == S_length - 1 && S[S_index] == Str[Str_index])
            return Target_index; // if all character found
        }
      }
    }
  }
  return -1; // return 18446744073709551615ULL -- when fail to find
}
size_t rFind(const string &Str, const char *S, size_t start_pos = -1)
{
  // Search for 'S' in "Str" - starting from (start_pos) & return the index of first character if found

  size_t S_length = Str_Size(S);
  size_t Str_length = Str_Size(Str);

  if (Str_length == 0 || S_length == 0)
    return -1;

  if (S_length == 1) // when "S" is just a character
  {
    for (long long index = start_pos; index >= 0; index--)
      if (Str[index] == S[0])
        return index;
  }
  else
  {
    size_t Target_index = 0;

    if (start_pos >= Str_length)
      start_pos = Str_length - 1;

    for (long long Str_index = start_pos; Str_index >= 0; Str_index--)
    {
      if (Str[Str_index] == S[0]) // When first character of "Str" equal to first character of "S"
      {
        Target_index = Str_index; // Make the target_index = index of first character of word

        // Search for the other characters of "S"
        for (unsigned short S_index = 1; S_index < S_length; S_index++)
        {
          Str_index++;

          if (S[S_index] != Str[Str_index])
          {
            Str_index = Target_index; // restore Str_index to the last value to continue from it
            break;                    // Break this loop if any char of "S" not equal to "Str" char
          }

          if (S_index == S_length - 1 && S[S_index] == Str[Str_index])
            return Target_index; // if all character found
        }
      }
    }
  }
  return -1; // return 18446744073709551615ULL -- when fail to find
}

size_t Find_NoCs(const string &Str, const char &C, size_t start_pos = 0)
{
  // Search for 'C' in "Str" - starting from (start_pos) & return it's index

  size_t length = Str_Size(Str);

  for (size_t index = start_pos; index < length; index++)
    if (ToLowerCase(Str[index]) == ToLowerCase(C))
      return index;

  return -1; // 18446744073709551615ULL  --> unsigned long long overfolw
}
size_t Find_NoCs(const string &Str, const string &S, size_t start_pos = 0)
{
  // {NoCs} --> No Case_Sensitive
  // Search for 'S' in "Str" - starting from (start_pos) & return the index of first char in it

  size_t S_length = Str_Size(S);
  size_t Str_length = Str_Size(Str);

  if (S_length == 1)
  {
    // Work like character Find()
    for (size_t index = start_pos; index < Str_length; index++)
      if (ToLowerCase(Str[index]) == ToLowerCase(S[0]))
        return index;
  }
  else
  {
    size_t Target_index = 0;

    for (size_t Str_index = start_pos; Str_index < Str_length; Str_index++)
    {
      if (ToLowerCase(Str[Str_index]) == ToLowerCase(S[0])) // When first character of "Str" equal to first character of "S"
      {
        Target_index = Str_index;

        for (unsigned short S_index = 1; S_index < S_length; S_index++)
        {
          Str_index++;

          if (ToLowerCase(S[S_index]) != ToLowerCase(Str[Str_index]))
            break;

          if (S_index == S_length - 1 && ToLowerCase(S[S_index]) == ToLowerCase(Str[Str_index]))
            return Target_index; // if all character found
        }
      }
    }
  }
  return -1; // 18446744073709551615ULL  --> unsigned long long overfolw
}
size_t Find_NoCs(const string &Str, const char *S, size_t start_pos = 0)
{
  // Search for 'S' in "Str" - starting from (start_pos) & return the index of first char in it

  size_t S_length = Str_Size(S);
  size_t Str_length = Str_Size(Str);

  if (S_length == 1)
  {
    // Work like character Find()
    for (size_t index = start_pos; index < Str_length; index++)
      if (ToLowerCase(Str[index]) == ToLowerCase(S[0]))
        return index;
  }
  else
  {
    size_t Target_index = 0;

    for (size_t Str_index = start_pos; Str_index < Str_length; Str_index++)
    {
      if (ToLowerCase(Str[Str_index]) == ToLowerCase(S[0])) // When first character of "Str" equal to first character of "S"
      {
        Target_index = Str_index;

        for (unsigned short S_index = 1; S_index < S_length; S_index++)
        {
          Str_index++;

          if (ToLowerCase(S[S_index]) != ToLowerCase(Str[Str_index]))
            break;

          if (S_index == S_length - 1 && ToLowerCase(S[S_index]) == ToLowerCase(Str[Str_index]))
            return Target_index; // if all character found
        }
      }
    }
  }
  return -1; // 18446744073709551615ULL  --> unsigned long long overfolw
}

size_t rFind_NoCs(const string &Str, const char &C, size_t start_pos = -1)
{
  size_t length = Str_Size(Str);

  if (length == 0)
    return -1;

  if (start_pos >= length)
    start_pos = length - 1;

  for (size_t index = start_pos; index >= 0; index--)
    if (ToLowerCase(Str[index]) == ToLowerCase(C))
      return index;

  return -1; // 18446744073709551615ULL  --> unsigned long long overfolw
}
size_t rFind_NoCs(const string &Str, const string &S, size_t start_pos = -1)
{
  // Search for 'S' in "Str" - starting from (start_pos) & return the index of first character if found

  size_t S_length = Str_Size(S);
  size_t Str_length = Str_Size(Str);

  if (Str_length == 0 || S_length == 0)
    return -1;

  if (S_length == 1) // when "S" is just a character
  {
    for (long long index = start_pos; index >= 0; index--)
      if (ToLowerCase(Str[index]) == ToLowerCase(S[0]))
        return index;
  }
  else
  {
    size_t Target_index = 0;

    if (start_pos >= Str_length)
      start_pos = Str_length - 1;

    for (long long Str_index = start_pos; Str_index >= 0; Str_index--)
    {
      if (ToLowerCase(Str[Str_index]) == ToLowerCase(S[0])) // When first character of "Str" equal to first character of "S"
      {
        Target_index = Str_index; // Make the target_index = index of first character of word

        // Search for the other characters of "S"
        for (unsigned short S_index = 1; S_index < S_length; S_index++)
        {
          Str_index++;

          if (ToLowerCase(S[S_index]) != ToLowerCase(Str[Str_index]))
          {
            Str_index = Target_index; // restore Str_index to the last value to continue from it
            break;                    // Break this loop if any char of "S" not equal to "Str" char
          }

          if (S_index == S_length - 1 && ToLowerCase(S[S_index]) == ToLowerCase(Str[Str_index]))
            return Target_index; // if all characters found
        }
      }
    }
  }
  return -1; // return 18446744073709551615ULL -- when fail to find
}
size_t rFind_NoCs(const string &Str, const char *S, size_t start_pos = -1)
{
  // Search for 'S' in "Str" - starting from (start_pos) & return the index of first character if found

  size_t S_length = Str_Size(S);
  size_t Str_length = Str_Size(Str);

  if (Str_length == 0 || S_length == 0)
    return -1;

  if (S_length == 1) // when "S" is just a character
  {
    for (long long index = start_pos; index >= 0; index--)
      if (ToLowerCase(Str[index]) == ToLowerCase(S[0]))
        return index;
  }
  else
  {
    size_t Target_index = 0;

    if (start_pos >= Str_length)
      start_pos = Str_length - 1;

    for (long long Str_index = start_pos; Str_index >= 0; Str_index--)
    {
      if (ToLowerCase(Str[Str_index]) == ToLowerCase(S[0])) // When first character of "Str" equal to first character of "S"
      {
        Target_index = Str_index; // Make the target_index = index of first character of word

        // Search for the other characters of "S"
        for (unsigned short S_index = 1; S_index < S_length; S_index++)
        {
          Str_index++;

          if (ToLowerCase(S[S_index]) != ToLowerCase(Str[Str_index]))
          {
            Str_index = Target_index; // restore Str_index to the last value to continue from it
            break;                    // Break this loop if any char of "S" not equal to "Str" char
          }

          if (S_index == S_length - 1 && ToLowerCase(S[S_index]) == ToLowerCase(Str[Str_index]))
            return Target_index; // if all character found
        }
      }
    }
  }
  return -1; // return 18446744073709551615ULL -- when fail to find
}


int main(void)
{
  size_t found = 0;

  string Str = "Mahmoud gad";
  //            01234567890
  string S = "Gad";
  string S1 = "";
  char C = 'A';

  found = Find_NoCs(Str, "Gad");
  cout << found << endl;


  // found = Find(Str, 'A');
  // cout << found << endl;

  // found = Find(Str, C, found + 1);
  // cout << found << endl;

  // found = Find(Str, "Gad");
  // cout << found << endl;

  // found = Find(Str, S, found + 1);
  // cout << found << endl;

  return 0;
}