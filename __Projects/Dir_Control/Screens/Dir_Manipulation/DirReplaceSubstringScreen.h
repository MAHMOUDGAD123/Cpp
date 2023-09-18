#pragma once

#include "../Screen.h"
#include "../../Headers/Dir.h"

class clsDirReplaceSubstringScreen : private clsScreen
{
public:
  static void Display()
  {
    _DrawScreenHeader("\tReplace Substring");
    _PrintPathTag();

    std::cout << "\n\n";

    std::string Target(READ_TXT("Enter The Targeted Substring => "));

    std::cout << "\n\n";

    std::string New(READ_TXT("Enter The New Substring => "));

    std::cout << "\n\n"
              << DEFAULT_FORMAT << "-> Hint: To Target Folders Enter { / }";

    std::cout << "\n\n";

    std::string ext(READ_TXT("Enter The item extention => "));

    std::cout << "\n\n";

    bool Hint(CONFIRM("Do You Want To Search Names From The End? y/n? "));

    std::cout << "\n\n";

    if (CONFIRM("Are You Sure That You Want To Perform This Process? y/n? "))
    {
      std::cout << "\n\n";

      bool __res;

      if (Hint)
        __res = Dir::replace_substring_r(Target, New, ext);
      else
        __res = Dir::replace_substring(Target, New, ext);

      if (__res)
        std::cout << "\n\n"
                  << DEFAULT_FORMAT << "Done Successfully";
      else
        std::cout << "\n\n"
                  << DEFAULT_FORMAT << "There is an error, Be careful You may lose data";
    }
  }
};
