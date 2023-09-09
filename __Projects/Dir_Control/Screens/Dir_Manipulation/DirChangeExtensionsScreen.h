#pragma once

#include "../Screen.h"
#include "../../Headers/Dir.h"

class clsDirChangeExtensionsScreen : private clsScreen
{
public:
  static void Display()
  {
    _DrawScreenHeader("\tExtesions Change");
    _PrintPathTag();

    std::cout << "\n\n"
              << DEFAULT_FORMAT;

    std::string old_ext(READ_TXT("Enter The Targeted File extention => "));

    std::cout << "\n\n"
              << DEFAULT_FORMAT << "-> Hint: To Target Folders Enter { / }";

    std::cout << "\n\n"
              << DEFAULT_FORMAT;

    std::string new_ext(READ_TXT("Enter The New Extention => "));

    std::cout << "\n\n"
              << DEFAULT_FORMAT;

    if (CONFIRM("Are You Sure That You Want To Perform This Process? y/n? "))
    {
      Dir::change_extensions(old_ext, new_ext);

      std::cout << "\n\n"
                << DEFAULT_FORMAT << "Done Successfully";
    }
  }
};
