#pragma once

#include "../Screen.h"
#include "../../Headers/Dir.h"

class clsDirSmartEraseItemsIfScreen : private clsScreen
{
public:
  static void Display()
  {
    _DrawScreenHeader("Smart Erase Items If");
    _PrintPathTag();

    std::cout << "\n\n"
              << DEFAULT_FORMAT
              << "!! This Will Erase All Items That Contains A Specific Sequences !!\n\n"
              << DEFAULT_FORMAT
              << "Enter The Items In The Following Format:\n\n"
              << DEFAULT_FORMAT
              << "=>  seq1///seq2///seq3///... \n\n";

    std::string Format(READ_TXT("Here => "));

    std::cout << '\n'
              << DEFAULT_FORMAT
              << "---------------------------------------";

    std::cout << "\n\n";

    if (CONFIRM("Are You Sure That You Want To Perform This Process? y/n? "))
    {
      std::cout << "\n\n";

      if (Dir::smart_erase_items_if(Format))
        std::cout << "\n\n"
                  << DEFAULT_FORMAT << "Done Successfully";
      else
        std::cout << "\n\n"
                  << DEFAULT_FORMAT << "There is an error, Be careful You may lose data";
    }
  }
};
