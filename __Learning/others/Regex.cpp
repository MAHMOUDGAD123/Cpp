#include <iostream>
#include <string>
#include <regex>

int main()
{
  std::string Str("h12ooda.gad333@gmail.com");
  std::regex reg("\\w*.\\w*@\\w*.[a-zA-Z]*");
  std::cout << std::boolalpha << "\n"
            << std::regex_match(Str, reg) << std::endl;

  std::cout << "\n====================================\n"
            << std::endl;

  std::string _Str("My Name Is Mahmoud Gad & i'm 25 years old.");
  std::regex _reg("Mahmoud Gad");

  std::cout << "Before Replace =>  " << _Str << std::endl;

  std::cout << "                             |-----------|\n";
  std::cout << "                                   |\n";
  std::cout << "                              ------\n";
  std::cout << "                              |\n";
  std::cout << "                             |--|\n";

  std::cout << "After Replace  =>  " << std::regex_replace(_Str, _reg, "MG");

  return 0;
}