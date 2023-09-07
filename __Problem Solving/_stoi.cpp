#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

std::string ReadTxt(const char *const Message)
{
  std::cout << Message;
  std::string Txt;
  std::getline(std::cin >> std::ws, Txt);
  return Txt;
}

constexpr bool _isDigit(const char _Ch)
{
  return _Ch > 47 && _Ch < 58;
}

long long _stoi(const std::string &_Str)
{
  uint16_t i(0);
  long long _Num(0);

  bool _isNegative(false);

  if (_Str[0] == '-') ++i, _isNegative = true;

  for (uint16_t len(_Str.size()); i < len && _isDigit(_Str[i]); ++i)
    _Num = _Num * 10 + (_Str[i] - '0');

  return _isNegative ? -_Num : _Num;
}

long long __stoi(const std::string &_Str)
{
  long long _N(0);
  std::stringstream(_Str) >> _N;
  return _N;
}

int main()
{
  for (;;)
  {
    std::string _Str(ReadTxt("\nEnter A String Number:  "));
    std::cout << "Your string In integer Number Is: \"" << _stoi(_Str) << "\"\n\n";
    std::cout << "Your string In integer Number Is: \"" << __stoi(_Str) << "\"\n\n";
  }

  return 0;
}