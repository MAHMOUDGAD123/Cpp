#pragma once

#include "../Screen.h"
#include "../../Headers/Dir.h"

class clsDirRenameItemsMCScreen : private clsScreen
{
public:
  static void Display()
  {
    _DrawScreenHeader("\tRename Items MC");
    _PrintPathTag();

    std::cout << "\n\n";

    std::string lhs(READ_TXT("Enter The LHS text => "));

    std::cout << "\n\n";

    std::string rhs(READ_TXT("Enter The RHS text => "));

    std::cout << "\n\n"
              << DEFAULT_FORMAT << "-> Hint: To Target Folders Enter { / }";

    std::cout << "\n\n";

    std::string ext(READ_TXT("Enter The Item Extention => "));

    std::cout << "\n\n";

    if (CONFIRM("Are You Sure That You Want To Perform This Process? y/n? "))
    {
      std::cout << "\n\n";

      if (Dir::rename_items_mid_counter(lhs, rhs, ext))
        std::cout << "\n\n"
                  << DEFAULT_FORMAT << "Done Successfully";
      else
        std::cout << "\n\n"
                  << DEFAULT_FORMAT << "There is an error, Be careful You may lose data";
    }
  }
};
