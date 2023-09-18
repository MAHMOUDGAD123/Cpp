#pragma once

#include "../Screen.h"
#include "../../Headers/Dir.h"

class clsDirTrimItemsNamesScreen : private clsScreen
{
public:
  static void Display()
  {
    _DrawScreenHeader("\tTrim Names");
    _PrintPathTag();

    std::cout << "\n\n";

    if (CONFIRM("Are You Sure That You Want To Perform This Process? y/n? "))
    {
      std::cout << "\n\n";

      if (Dir::trim_names())
        std::cout << "\n\n"
                  << DEFAULT_FORMAT << "Done Successfully";
      else
        std::cout << "\n\n"
                  << DEFAULT_FORMAT << "There is an error, Be careful You may lose data";
    }
  }
};
