#pragma once

#include "../Screen.h"
#include "../../Headers/Dir.h"

class clsDirAppendLeftScreen : private clsScreen
{
public:
  static void Display()
  {
    _DrawScreenHeader("\tAppend Left");
    _PrintPathTag();

    std::cout << "\n\n"
              << DEFAULT_FORMAT;

    std::string insert(READ_TXT("Enter The Inserted Substring => "));

    std::cout << "\n\n"
              << DEFAULT_FORMAT << "-> Hint: To Target Folders Enter { / }";

    std::cout << "\n\n"
              << DEFAULT_FORMAT;

    std::string ext(READ_TXT("Enter The File extention => "));

    std::cout << "\n\n"
              << DEFAULT_FORMAT;
              
    if (CONFIRM("Are You Sure That You Want To Perform This Process?y/n? "))
    {
        Dir::append_left(insert, ext);

      std::cout << "\n\n"
                << DEFAULT_FORMAT << "Done Successfully";
    }
  }
};
