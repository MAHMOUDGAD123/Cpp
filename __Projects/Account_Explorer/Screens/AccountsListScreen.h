#pragma once

#include "Screen.h"
#include "../Headers/Account.h"

class clsAccountsListScreen : protected clsScreen
{
private:
  static void _ShowClientsListHeader(int TotalAccounts)
  {
    std::cout << std::setw(5) << ""
              << "______________________________________________________________________________________________________________________________\n\n";

    std::cout << std::setw(5) << ""
              << "| Total Accounts = (" + std::to_string(TotalAccounts) + ") Account(s)\n";

    std::cout << std::setw(5) << ""
              << "______________________________________________________________________________________________________________________________\n\n";

    std::cout << std::setw(5) << ""
              << "| " << std::left << std::setw(30) << "{Account Id}"
              << "| " << std::left << std::setw(40) << "{Email/Phone}"
              << "| " << std::left << std::setw(30) << "{Password}"
              << std::endl;

    std::cout << std::setw(5) << ""
              << "______________________________________________________________________________________________________________________________\n\n";
  }

  static void _PrintClientRecord(const Account &Acc) noexcept
  {
    std::cout << std::setw(5) << ""
              << "| " << std::left << std::setw(30) << Acc._Id
              << "| " << std::left << std::setw(40) << Acc._Email
              << "| " << std::left << std::setw(30) << Acc._Password
              << std::endl;
  }

public:
  static void ListAllAccounts()
  {
    std::vector<Account> _Accounts = Account::_LoadAccountsFromFile();
    uint32_t _TotalAccounts = (uint32_t)_Accounts.size();

    _DrawScreenHeader("   Accounts List");

    _ShowClientsListHeader(_TotalAccounts);

    if (_TotalAccounts)
      for (Account &Acc : _Accounts)
        _PrintClientRecord(Acc);
    else
      std::cout << "\t\t\t\t\t     No Accounts Avaiable In The System :-(\n";

    std::cout << std::setw(5) << ""
              << "______________________________________________________________________________________________________________________________\n\n";
  }
};
