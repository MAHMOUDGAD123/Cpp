#include <iostream>
#include <string>

bool validParentheses(const std::string &str)
{
  char open_par = '(', close_par = ')';
  uint16_t len(str.size()), open_count(0), close_count(0);

  for (uint16_t i(0); i < len; i++)
  {
    if (str[i] == open_par)
      open_count++;
    if (str[i] == close_par)
      close_count++;
    if (close_count > open_count)
      return false;
  }
  return open_count == close_count;
}

int main()
{
  std::cout << "\n\n" << std::boolalpha << validParentheses("()()(456)()()()") << "\n";
  std::cout << std::boolalpha << validParentheses("())(()()()()()") << "\n\n";
}
