#pragma once

#include "Screen.h"

class clsListAllFilesScreen : private clsScreen
{
private:
  static inline const uint16_t W = 3;
  static inline const uint16_t E1 = 160;

  static void _ShowFilesListHeader(int TotalFiles)
  {
    std::cout << std::setw(W) << ""
              << "_______________________________________________________________________________________________________________________________________________________________________________________\n\n";

    std::cout << std::setw(W) << ""
              << "| Total Files = (" + std::to_string(TotalFiles) + ") File(s)\n";

    std::cout << std::setw(W) << ""
              << "_______________________________________________________________________________________________________________________________________________________________________________________\n\n";

    std::cout << std::setw(W) << ""
              << "| " << std::left << std::setw(E1) << "{Name}"
              << "| " << std::left << std::setw(30) << "{Type}"
              << std::endl;

    std::cout << std::setw(W) << ""
              << "_______________________________________________________________________________________________________________________________________________________________________________________\n\n";
  }

  static void _PrintFileRecord(const File &file) noexcept
  {
    std::cout << std::setw(W) << ""
              << "| " << std::left << std::setw(E1) << file._Name
              << "| " << std::left << std::setw(30) << file._Type
              << std::endl;
  }

public:
  static void ListAllFiles()
  {
    std::vector<File> Files = File::_LoadFilesFromFile();
    uint32_t _TotalFiles = (uint32_t)Files.size();

    _DrawScreenHeader("  Files Info List");
    _PrintPathTag();

    _ShowFilesListHeader(_TotalFiles);

    if (_TotalFiles)
      for (File &file : Files)
        _PrintFileRecord(file);
    else
      std::cout << DEFAULT_FORMAT << "No Files Available In The Dir :-(\n";

    std::cout << std::setw(W) << ""
              << "______________________________________________________________________________________________________________________________________________________________________________________\n\n";
  }
};