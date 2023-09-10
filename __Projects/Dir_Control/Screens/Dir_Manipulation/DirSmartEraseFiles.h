#pragma once

#include "../Screen.h"
#include "../../Headers/Dir.h"

class clsDirSmartEraseFilesScreen : private clsScreen
{
public:
  static void Display()
  {
    _DrawScreenHeader("Smart Erase Files");
    _PrintPathTag();

    std::cout << "\n\n"
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

      Dir::smart_files_erase(Format);

      std::cout << "\n\n"
                << DEFAULT_FORMAT << "Done Successfully" << std::endl;
      ;
    }
  }
};
