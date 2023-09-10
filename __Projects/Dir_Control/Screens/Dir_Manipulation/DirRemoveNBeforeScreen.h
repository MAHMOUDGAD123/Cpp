#pragma once

#include "../Screen.h"
#include "../../Headers/Dir.h"

class clsDirRemoveNBeforeScreen : private clsScreen
{
public:
  static void Display()
  {
    _DrawScreenHeader("\tRemove N Before");
    _PrintPathTag();

    std::cout << "\n\n"
              << DEFAULT_FORMAT;

    std::string Target(READ_TXT("Enter The Targeted Substring => "));

    std::cout << "\n\n"
              << DEFAULT_FORMAT << "Enter How Many Characters To Remove => ";

    size_t N(_Read_pNum());

    std::cout << "\n\n"
              << DEFAULT_FORMAT << "-> Hint: To Target Folders Enter { / }";

    std::cout << "\n\n"
              << DEFAULT_FORMAT;

    std::string ext(READ_TXT("Enter The item extention => "));

    std::cout << "\n\n"
              << DEFAULT_FORMAT;

    if (CONFIRM("Are You Sure That You Want To Perform This Process? y/n? "))
    {
      std::cout << "\n\n";
      
      Dir::remove_n_before(Target, N, ext);

      std::cout << "\n\n"
                << DEFAULT_FORMAT << "Done Successfully";
    }
  }
};
