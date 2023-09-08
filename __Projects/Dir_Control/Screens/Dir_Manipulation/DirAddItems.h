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

    std::cout << "\n\n"
              << DEFAULT_FORMAT;

    std::string Type(READ_TXT("Enter The Item Type => "));

    std::cout << "\n"
              << DEFAULT_FORMAT;

    std::string Name = "";

    if (CONFIRM("Do You Want To Add A Name To The Item? y/n? "))
    {
      std::cout << "\n"
                << DEFAULT_FORMAT;

      Name = READ_TXT("Enter The Item Name => ");
    }

    std::cout << '\n'
              << DEFAULT_FORMAT
              << "---------------------------------------\n\n"
              << DEFAULT_FORMAT << "Enter The Number Of Items => ";

    int N = _Read_pNum();

    std::cout << '\n'
              << DEFAULT_FORMAT
              << "---------------------------------------\n\n"
              << DEFAULT_FORMAT;

    if (CONFIRM("Are You Sure That You Want To Perform This Process? y/n? "))
    {
      Dir::add_n_items(Type, N, Name);

      std::cout << "\n\n"
                << DEFAULT_FORMAT << "Done Successfully";
    }
  }
};
