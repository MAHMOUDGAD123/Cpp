#pragma once

#include "Screen.h"
#include "../Headers/Account.h"
#include <Windows.h>

class clsFindAccountScreen : protected clsScreen
{
private:
  static void _ShowCopyDataDisplay(const Account &Acc)
  {
    while (true)
    {
      _DrawScreenHeader("   Find Account");

      _PrintAccountCard(Acc);

      const char *Choice;
      size_t len(0);

      std::cout << "\n\t\t\t\t   ---------------------------------";
      std::cout << "\n\t\t\t\t   [1] Copy Email";
      std::cout << "\n\t\t\t\t   [2] Copy Password";
      std::cout << "\n\t\t\t\t   [3] Back To Main Menu";
      std::cout << "\n\t\t\t\t   ---------------------------------\n";

      switch (_ReadUserChoice(1, 3, "Choose A Number Between"))
      {
      case 1:
        Choice = Acc._Email.c_str();
        len = Acc._Email.size() + 1;
        break;
      case 2:
        Choice = Acc._Password.c_str();
        len = Acc._Password.size() + 1;
        break;
      case 3:
        return;
      }

      OpenClipboard(NULL);
      EmptyClipboard();
      HGLOBAL Hg = GlobalAlloc(GMEM_MOVEABLE, len);
      memcpy(GlobalLock(Hg), Choice, len);
      GlobalUnlock(Hg);
      SetClipboardData(CF_TEXT, Hg);
      CloseClipboard();
      GlobalFree(Hg);
      std::cout << "\n\t\t\t\t   Copied Successfully!\n";
      Sleep(2000);
    }
  }

public:
  static void ShowFindAccountDisplay()
  {
    _DrawScreenHeader("   Find Account");

    Account _Account;
    std::string Id = READ_TXT("\t\t\t\t   Enter Id:  ");

    if (!Account::is_exist(Id, _Account))
    {
      std::cout << "\n\t\t\t\t   Not Found :-(\n\n";
    }
    else
    {
      if (_Account.is_empty())
      {
        std::cout << "\n\t\t\t\t   Account Wasn't Found :-(\n";
      }
      else
      {
        _ShowCopyDataDisplay(_Account);
      }
    }
  }
};
