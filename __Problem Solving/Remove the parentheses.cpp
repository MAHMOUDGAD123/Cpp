#include <iostream>
#include <string>
#include <sstream>

std::string remove_parentheses(const std::string &str)
{
  std::string S;
  int open_pars(0);
  for (const char& c : str)
  {
    if (c == '(') open_pars++;
    else if (c == ')') open_pars--;
    else if (!open_pars) S += c;
  }
  return S;
}

int main()
{
  std::cout
      << "\n\n\""
      << remove_parentheses("Mahmoud (Abdelrahman)(Gad")
      << "\"\n\n";
}
