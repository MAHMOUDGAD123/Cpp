#pragma once

#include "Screen.h"
#include "../Headers/Account.h"
#include <Windows.h>

class clsEraseAllScreen : protected clsScreen
{
private:
  static void _EraseAll()
  {
    std::fstream File(_Accounts_File, std::ios::out | std::ios::trunc);
		if (File) File.close();
  }

public:
  static void ShowEraseAllDisplay()
  {
    _DrawScreenHeader("  Erase All Accounts");

    if (CONFIRM("\n\t\t\t\t   Are You Sure That You Want To Erase All Accounts? y/n? "))
    {
      _EraseAll();
      std::cout << "\n\t\t\t\t   Erase All Done!\n";
    }
  }
};
