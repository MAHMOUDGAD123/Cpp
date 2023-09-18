#pragma once

#include "../Screen.h"
#include "../../Headers/Dir.h"

class clsDirInsertBeforeScreen : private clsScreen
{
public:
  static void Display()
  {
    _DrawScreenHeader("\tInsert Before");
    _PrintPathTag();

    std::cout << "\n\n";

    std::string Target(READ_TXT("Enter The Targeted Substring => "));

    std::cout << "\n\n";

    std::string insert(READ_TXT("Enter The Inserted Substring => "));

    std::cout << "\n\n"
              << DEFAULT_FORMAT << "-> Hint: To Target Folders Enter { / }";

    std::cout << "\n\n";

    std::string ext(READ_TXT("Enter The item extention => "));

    std::cout << "\n\n";

    if (CONFIRM("Are You Sure That You Want To Perform This Process? y/n? "))
    {
      std::cout << "\n\n";

      if (Dir::insert_before(Target, insert, ext))
        std::cout << "\n\n"
                  << DEFAULT_FORMAT << "Done Successfully";
      else
        std::cout << "\n\n"
                  << DEFAULT_FORMAT << "There is an error, Be careful You may lose data";
    }
  }
};
