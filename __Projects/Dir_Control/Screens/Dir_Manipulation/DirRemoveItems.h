#pragma once

#include "../Screen.h"
#include "../../Headers/Dir.h"

class clsDirRemoveItemsScreen : private clsScreen
{
public:
  static void Display()
  {
    _DrawScreenHeader("\tRemove Items");
    _PrintPathTag();

    std::cout << "\n\n"
              << DEFAULT_FORMAT
              << "Enter The Items In The Following Format:"
              << "\n\n"
              << DEFAULT_FORMAT
              << "=>  item1.txt///item2.mp4///item3.mp3///.... "
              << "\n\n"
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

      Dir::remove_items(Format);

      std::cout << "\n\n"
                << DEFAULT_FORMAT << "Done Successfully" << std::endl;
      ;
    }
  }
};
