#pragma once

#include "../Screen.h"
#include "../../Headers/Dir.h"

class clsDirRemoveNAfterScreen : private clsScreen
{
public:
  static void Display()
  {
    _DrawScreenHeader("\tRemove N After");
    _PrintPathTag();

    std::cout << "\n\n"
              << DEFAULT_FORMAT;

    std::string Target(READ_TXT("Enter The Targeted Substring => "));

    std::cout << "\n\n"
              << DEFAULT_FORMAT << "Enter How Many Characters To Remove => ";

    int N(_Read_pNum());

    std::cout << "\n\n"
              << DEFAULT_FORMAT << "-> Hint: To Target Folders Enter { / }";

    std::cout << "\n\n"
              << DEFAULT_FORMAT;

    std::string ext(READ_TXT("Enter The File extention => "));

    std::cout << "\n\n"
              << DEFAULT_FORMAT;

    if (CONFIRM("Are You Sure That You Want To Perform This Process? y/n? "))
    {
      Dir::remove_n_after(Target, N, ext);

      std::cout << "\n\n"
                << DEFAULT_FORMAT << "Done Successfully";
    }
  }
};
