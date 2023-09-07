#pragma once

#include "../Screen.h"
#include "../../Headers/Dir.h"

class clsDirTrimFilesNamesScreen : private clsScreen
{
public:
  static void Display()
  {
    _DrawScreenHeader("\tTrim Names");
    _PrintPathTag();

    std::cout << "\n\n"
              << DEFAULT_FORMAT;

    if (CONFIRM("Are You Sure That You Want To Perform This Process?y/n? "))
    {
      Dir::trim_names();

      std::cout << "\n\n"
                << DEFAULT_FORMAT << "Done Successfully";
    }
  }
};
