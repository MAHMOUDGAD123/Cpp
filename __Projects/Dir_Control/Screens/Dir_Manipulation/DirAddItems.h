#pragma once

#include "../Screen.h"
#include "../../Headers/Dir.h"

class clsDirAddItemsScreen : private clsScreen
{
public:
  static void Display()
  {
    _DrawScreenHeader("\tAdd Items");
    _PrintPathTag();

    std::cout << "\n\n"
              << DEFAULT_FORMAT << "-> Hint: To Add Folders Enter { / }";

    std::cout << "\n\n";

    std::string ext(READ_TXT("Enter The Item Extension => "));

    std::cout << "\n";

    std::string Name;

    if (CONFIRM("Do You Want To Add A Name To The Item? y/n? "))
    {
      std::cout << "\n";

      Name = READ_TXT("Enter The Item Name => ");
    }

    std::cout << '\n'
              << DEFAULT_FORMAT
              << "---------------------------------------\n\n"
              << DEFAULT_FORMAT << "Enter The Number Of Items => ";

    int N = User_Input::_Read_pNum();

    std::cout << '\n'
              << DEFAULT_FORMAT
              << "---------------------------------------\n\n";

    if (CONFIRM("Are You Sure That You Want To Perform This Process? y/n? "))
    {
      if (Dir::add_n_items(ext, N, Name))
        std::cout << "\n\n"
                  << DEFAULT_FORMAT << "Done Successfully";
      else
        std::cout << "\n\n"
                  << DEFAULT_FORMAT << "There is an error, Be careful You may lose data";
    }
  }
};
