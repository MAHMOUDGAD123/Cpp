#pragma once

#include "../Screen.h"
#include "../../Headers/Dir.h"

class clsDirRemoveSubstringScreen : private clsScreen
{
public:
  static void Display()
  {
    _DrawScreenHeader("\tRemove Substring");
    _PrintPathTag();

    std::cout << "\n\n"
              << DEFAULT_FORMAT;

    std::string Target(READ_TXT("Enter The Targeted Substring => "));

    std::cout << "\n\n"
              << DEFAULT_FORMAT << "-> Hint: To Target Folders Enter { / }";

    std::cout << "\n\n"
              << DEFAULT_FORMAT;

    std::string ext(READ_TXT("Enter The File extention => "));

    std::cout << "\n\n"
              << DEFAULT_FORMAT;

    bool Hint(CONFIRM("Do You Want To Search Names From The End? y/n? "));

    std::cout << "\n\n"
              << DEFAULT_FORMAT;
              
    if (CONFIRM("Are You Sure That You Want To Perform This Process? y/n? "))
    {
      if (Hint)
        Dir::remove_substring_r(Target, ext);
      else
        Dir::remove_substring(Target, ext);

      std::cout << "\n\n"
                << DEFAULT_FORMAT << "Done Successfully";
    }
  }
};
