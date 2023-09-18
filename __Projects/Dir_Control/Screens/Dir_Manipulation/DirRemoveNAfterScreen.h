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

    std::cout << "\n\n";

    std::string Target(READ_TXT("Enter The Targeted Substring => "));

    std::cout << "\n\n"
              << DEFAULT_FORMAT << "Enter How Many Characters To Remove => ";

    int N(User_Input::_Read_pNum());

    std::cout << "\n\n"
              << DEFAULT_FORMAT << "-> Hint: To Target Folders Enter { / }";

    std::cout << "\n\n";

    std::string ext(READ_TXT("Enter The item extention => "));

    std::cout << "\n\n";

    if (CONFIRM("Are You Sure That You Want To Perform This Process? y/n? "))
    {
      std::cout << "\n\n";

      if (Dir::remove_n_after(Target, N, ext))
        std::cout << "\n\n"
                  << DEFAULT_FORMAT << "Done Successfully";
      else
        std::cout << "\n\n"
                  << DEFAULT_FORMAT << "There is an error, Be careful You may lose data";
    }
  }
};
