#pragma once

#include "Screen.h"
#include "../Headers/Account.h"

class clsDeleteAccountScreen : protected clsScreen
{
public:
  static void ShowDeleteAccountDisplay()
  {
    _DrawScreenHeader("   Delete Account");

    Account _Account;
    std::string Id = READ_TXT("\t\t\t\t   Enter Id:  ");

    if (!Account::is_exist(Id, _Account))
    {
      std::cout << "\n\t\t\t\t   Not Found :-(\n\n";
    }
    else
    {
      _PrintAccountCard(_Account);

      if (MG::utility::input_valid::Read_YesOrNo("\n\t\t\t\t   Are You Sure You Want To Delete This Account? y/n? "))
      {
        _Account.Delete();
        std::cout << "\n\t\t\t\t   Account Deleted Succesfully\n\n";
      }
    }
  }
};
