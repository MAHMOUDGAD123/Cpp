#pragma once

#include "../Headers/Account.h"
#include "Screen.h"

class clsAddNewAccountScreen : protected clsScreen
{
private:
  static void _ReadAccountInfo(Account &Acc)
  {
    Acc._Email = MG::utility::input_valid::ReadTxt("\t\t\t\t   Enter Email/Phone:  ");
    Acc._Password = MG::utility::input_valid::ReadTxt("\n\t\t\t\t   Enter Password:  ");
  }

public:
  static void ShowAddNewAccountDisplay() noexcept
  {
    _DrawScreenHeader(" Add New Account");

    std::string Id = READ_TXT("\t\t\t\t   Enter Id:  ");

    if (Account::is_exist(Id))
    {
      std::cout << "\n\t\t\t\t   Account Already Exist\n\n";
    }
    else
    {
      Account NewAccount(Id);

      std::cout << "\n\n\t\t\t\t   Adding New Account:";
      std::cout << "\n\t\t\t\t   ------------------\n";

      _ReadAccountInfo(NewAccount);

      switch (NewAccount.Save())
      {
      case Account::en_SaveResult::svSucceeded:
        std::cout << "\n\t\t\t\t   Account Added Successfully :-)\n";
        _PrintAccountCard(NewAccount);
        break;
      case Account::en_SaveResult::svFaildEmptyObject:
        std::cout << "\n\t\t\t\t   Error, Saving Data Faild Because It's Empty :-(\n";
        break;
      case Account::en_SaveResult::svFaildAccountNumberExists:
        std::cout << "\n\t\t\t\t   Error, Account Wasn't Saved Because Id Is Used!\n";
        break;
      }
    }
  }
};