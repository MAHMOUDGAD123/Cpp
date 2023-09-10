#pragma once

#include "../Screen.h"
#include "../../Headers/Dir.h"

class clsDirRenameItemsRCScreen : private clsScreen
{
public:
  static void Display()
  {
    _DrawScreenHeader("\tRename Items RC");
    _PrintPathTag();

    std::cout << "\n\n"
              << DEFAULT_FORMAT;

    std::string NewName(READ_TXT("Enter The items New Name => "));

    std::cout << "\n\n"
              << DEFAULT_FORMAT << "-> Hint: To Target Folders Enter { / }";

    std::cout << "\n\n"
              << DEFAULT_FORMAT;

    std::string ext(READ_TXT("Enter The item Extention => "));

    std::cout << "\n\n"
              << DEFAULT_FORMAT;

    if (CONFIRM("Are You Sure That You Want To Perform This Process? y/n? "))
    {
      std::cout << "\n\n";
      
      Dir::rename_items_right_counter(NewName, ext);

      std::cout << "\n\n"
                << DEFAULT_FORMAT << "Done Successfully";
    }
  }
};
