#pragma once

#include "../Screen.h"
#include "../../Headers/Dir.h"

class clsDirEraseItemsScreen : private clsScreen
{
public:
  static void Display()
  {
    _DrawScreenHeader("\tErase Items");
    _PrintPathTag();

    std::cout << "\n\n"
              << DEFAULT_FORMAT
              << "Enter The Items In The Following Format:\n\n"
              << DEFAULT_FORMAT
              << "=>  file.txt///folder///file.mp3///...\n\n"
              << DEFAULT_FORMAT;

    std::string Format(READ_TXT("Here => "));

    std::cout << '\n'
              << DEFAULT_FORMAT
              << "---------------------------------------";

    std::cout << "\n\n"
              << DEFAULT_FORMAT;

    if (CONFIRM("Are You Sure That You Want To Perform This Process? y/n? "))
    {
      std::cout << "\n\n";

      Dir::erase_items(Format);

      std::cout << "\n\n"
                << DEFAULT_FORMAT << "Done Successfully" << std::endl;
      ;
    }
  }
};
