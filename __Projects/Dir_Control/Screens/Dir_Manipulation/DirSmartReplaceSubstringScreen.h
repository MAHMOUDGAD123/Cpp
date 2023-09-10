#pragma once

#include "../Screen.h"
#include "../../Headers/Dir.h"

class clsDirSmartReplaceSubstringScreen : private clsScreen
{
public:
  static void Display()
  {
    _DrawScreenHeader("Smart Replace Substring");
    _PrintPathTag();

    std::cout << "\n\n"
              << DEFAULT_FORMAT;

    std::string Target(READ_TXT("Enter The Targeted Substring => "));

    std::cout << "\n\n"
              << DEFAULT_FORMAT;

    std::string New(READ_TXT("Enter The New Substring => "));

    std::cout << "\n\n"
              << DEFAULT_FORMAT << "-> Hint: To Target Folders Enter { / }";

    std::cout << "\n\n"
              << DEFAULT_FORMAT;

    std::string ext(READ_TXT("Enter The item extention => "));


    std::cout << "\n\n"
              << DEFAULT_FORMAT;

    if (CONFIRM("Are You Sure That You Want To Perform This Process? y/n? "))
    {
      std::cout << "\n\n";
      
      Dir::replace_all_substring(Target, New, ext);

      std::cout << "\n\n"
                << DEFAULT_FORMAT << "Done Successfully";
    }
  }
};
