#include <bits/stdc++.h>

bool is_palindrome(const std::string &S, size_t from, size_t to)
{
  for (; from < to; ++from, --to)
    if (S[from] != S[to])
      return false;
  return true;
}

int longest_palindrome(const std::string &S)
{
  if (S.empty())
    return 0;

  std::set<int> vals{1};

  for (size_t i(0), found(0); i < S.size(); ++i)
    if ((found = S.rfind(S[i])) != std::string::npos)
      if (is_palindrome(S, i, found) && found != i)
        vals.emplace(found - i + 1);

  return *vals.rbegin();
}

int main()
{

  const char *const Str("baablkj12345432133d");

  std::cout << longest_palindrome(Str) << std::endl;

  return 0;
}