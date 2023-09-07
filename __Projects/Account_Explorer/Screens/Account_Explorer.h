#pragma once

#include "Screen.h"
#include "AccountsListScreen.h"
#include "AddNewAccountScreen.h"
#include "DeleteAccountScreen.h"
#include "UpdateAccountScreen.h"
#include "FindAccountScreen.h"
#include "EraseAllScreen.h"

#define BACK_TO_MAIN_MENU return _GoBackToMainMenu();

class AccountExplorer : protected clsScreen
{
private:
  enum class en_MainMenuOptions
  {
    eShow_Accounts_List = 1,
    eAdd_New_Account = 2,
    eDelete_Account = 3,
    eFind_Account = 4,
    eUpdate_Account_Info = 5,
    eErase_All = 6,
    eExit = 0
  };

  static en_MainMenuOptions _ChooseFromMainMenu()
  {
    return (en_MainMenuOptions)_ReadUserChoice(0, 6, "Choose What To Perform From Main Menu");
  }

  static void _ShowAllAccountsScreen()
  {
    clsAccountsListScreen::ListAllAccounts();
  }

  static void _ShowAddNewAccountScreen()
  {
    clsAddNewAccountScreen::ShowAddNewAccountDisplay();
  }

  static void _ShowDeleteAccountScreen()
  {
    clsDeleteAccountScreen::ShowDeleteAccountDisplay();
  }

  static void _ShowFindAccountScreen()
  {
    clsFindAccountScreen::ShowFindAccountDisplay();
  }

  static void _ShowUpdateAccountScreen()
  {
    clsUpdateAccountScreen::ShowUpdateAccountInfoDisplay();
  }

  static void _ShowEraseAllAccountsScreen()
  {
    clsEraseAllScreen::ShowEraseAllDisplay();
  }

  static void _GoBackToMainMenu()
  {
    std::cout << "\n\t\t\t\t   -> Press any key to go back to Main Menu...";
    system("pause>0");
    _ShowMainMenu();
  }

  static void _PerformMainMenuOption(en_MainMenuOptions UserChoice)
  {
    switch (UserChoice)
    {
    case en_MainMenuOptions::eShow_Accounts_List:
      _ShowAllAccountsScreen();
      BACK_TO_MAIN_MENU

    case en_MainMenuOptions::eAdd_New_Account:
      _ShowAddNewAccountScreen();
      BACK_TO_MAIN_MENU

    case en_MainMenuOptions::eDelete_Account:
      _ShowDeleteAccountScreen();
      BACK_TO_MAIN_MENU

    case en_MainMenuOptions::eFind_Account:
      _ShowFindAccountScreen();
      BACK_TO_MAIN_MENU

    case en_MainMenuOptions::eUpdate_Account_Info:
      _ShowUpdateAccountScreen();
      BACK_TO_MAIN_MENU

    case en_MainMenuOptions::eErase_All:
      _ShowEraseAllAccountsScreen();
      BACK_TO_MAIN_MENU

    case en_MainMenuOptions::eExit:
      exit(0);
    }
  }

  static void _ShowMainMenu()
  {
    _DrawScreenHeader("\t\bWelcome \"MG\"");

    std::cout
        << DEFAULT_FORMAT << "====================================================================\n"
        << DEFAULT_FORMAT << "\t\t\t\tMain Menu\n"
        << DEFAULT_FORMAT << "====================================================================\n"
        << DEFAULT_FORMAT << "\t\t\t[1]  Show Accounts List.\n"
        << DEFAULT_FORMAT << "\t\t\t[2]  Add New Account.\n"
        << DEFAULT_FORMAT << "\t\t\t[3]  Delete Accout.\n"
        << DEFAULT_FORMAT << "\t\t\t[4]  Find Account.\n"
        << DEFAULT_FORMAT << "\t\t\t[5]  Update Account Info.\n"
        << DEFAULT_FORMAT << "\t\t\t[6]  Erase All.\n"
        << DEFAULT_FORMAT << "\t\t\t[0]  Exit.\n"
        << DEFAULT_FORMAT << "===================================================================="
        << std::endl;

    _PerformMainMenuOption(_ChooseFromMainMenu());
  }

public:
  static void Run()
  {
    _ShowMainMenu();
  }
};