#pragma once

#include "../Screen.h"
#include "../../Headers/Dir.h"

class clsDirSmartEraseFilesRecScreen : private clsScreen
{
public:
  static void Display()
  {
    _DrawScreenHeader("\bSmart Erase Files Rec");
    _PrintPathTag();

    std::cout << "\n\n"
              << DEFAULT_FORMAT
              << "!! Files Will Be Erased From The Whole Tree !!\n\n"
              << DEFAULT_FORMAT
              << "Enter The Items In The Following Format:"
              << "\n\n"
              << DEFAULT_FORMAT
              << "=>  file.txt///file.mp4///file.mp3///... "
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

      Dir::smart_files_erase_rec(Format);

      std::cout << "\n\n"
                << DEFAULT_FORMAT << "Done Successfully" << std::endl;
      ;
    }
  }
};
