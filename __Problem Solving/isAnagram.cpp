#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <map>

// solution 1
const char &to_lower(char &_ch) { return (_ch = _ch > 64 && _ch < 91 ? _ch + ' ' : _ch); }
auto less = [](char &_ch1, char &_ch2) -> bool { return to_lower(_ch1) < to_lower(_ch2); };

bool isAnagram_1(std::string T, std::string O)
{
  if (T.size() != O.size())
    return false;
  if (T.size() == 1)
  {
    (void)to_lower(T[0]);
    (void)to_lower(O[0]);
  }
  else
  {
    std::sort(T.begin(), T.end(), less);
    std::sort(O.begin(), O.end(), less);
  }
  return T == O;
}

// solution 2
bool isAnagram_2(const std::string &T, std::string O)
{
  if (T.size() != O.size())
    return false;

  std::string::iterator it(nullptr);
  for (short i(0), len(T.size()); i < len; ++i)
  {
    const char &_ch(::tolower(T[i]));
    if ((it = std::find_if(O.begin() + i, O.end(), [&](const char &_C)
                           { return ::tolower(_C) == _ch; })) == O.end())
      return false;
    std::swap(*it, O[i]);
  }
  return true;
}

// solution 3
bool isAnagram_3(const std::string &T, const std::string &O)
{
  std::map<const char, uint8_t> M;
  for (const char &c : T + O)
    ++M[::tolower(c)];
  for (const auto &[K, V] : M)
    if (V & 1)
      return false;
  return true;
}

// solution 4
bool isAnagram_4(const std::string &T, const std::string &O)
{
  int test(0);
  for (const char &c : T + O) test ^= (c | ' ');
  return !test;
}

int main()
{
  std::cout << std::boolalpha << isAnagram_4("foefet", "toffee") << "\n";
}