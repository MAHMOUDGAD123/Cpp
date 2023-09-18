#pragma once

#include "Screen.h"
#include <windows.h>
#include "../Headers/Dir.h"
#include "ListAllFilesScreen.h"
#include "DirManipulationScreen.h"

#define BACK_TO_MAIN_MENU return _GoBackToMainMenu()
#define Jump_TO_MAIN_MENU return _ShowMainMenu()

class DirManager : private clsScreen
{
private:
  enum class en_MainMenuOptions
  {
    eList_All_Files = 1,
    eChange_Path = 2,
    eSearch_Path = 3,
    eDir_Manipulation = 4,
    eExit = 0
  };

  static en_MainMenuOptions _ChooseFromMainMenu()
  {
    return (en_MainMenuOptions)User_Input::_ReadUserChoice(
        0,
        4,
        "Choose What To Perform From Main Menu");
  }

  static void _GoBackToMainMenu()
  {
    std::cout << "\n\n"
              << DEFAULT_FORMAT << "-> Press any key to go back to Main Menu...";
    PAUSE;
    _ShowMainMenu();
  }

  /* Screens */
  /*====================================================================================================*/

  static void _ShowListAllFilesScreen()
  {
    clsListAllFilesScreen::ListAllFiles();
  }

  static void _ShowDirManipulationScreen()
  {
    clsDirManipulationScreen::ShowManipulationMenu();
  }

  /*====================================================================================================*/

  static void _PerformMainMenuOption(en_MainMenuOptions UserChoice)
  {
    switch (UserChoice)
    {
    case en_MainMenuOptions::eList_All_Files:
      _ShowListAllFilesScreen();
      BACK_TO_MAIN_MENU;

    case en_MainMenuOptions::eChange_Path:
      Run();
      BACK_TO_MAIN_MENU;

    case en_MainMenuOptions::eSearch_Path:
      Dir::read_dir();
      std::cout << "\n\n"
                << DEFAULT_FORMAT << "Dir Info Updated Succesfully :-)";
      Sleep(2000);
      Jump_TO_MAIN_MENU;

    case en_MainMenuOptions::eDir_Manipulation:
      _ShowDirManipulationScreen();
      Jump_TO_MAIN_MENU;

    case en_MainMenuOptions::eExit:
      exit(0);
    }
  }

  static void _ShowMainMenu()
  {
    _DrawScreenHeader("\tDir Manager");
    _PrintPathTag();

    std::cout
        << DEFAULT_FORMAT << "\t\t\t[1]  List All Files In Dir.\n"
        << DEFAULT_FORMAT << "\t\t\t[2]  Change Dir Path.\n"
        << DEFAULT_FORMAT << "\t\t\t[3]  Search Path Again.\n"
        << DEFAULT_FORMAT << "\t\t\t[4]  Dir Manipulation Menu.\n"
        << DEFAULT_FORMAT << "\t\t\t[0]  Exit.\n"
        << DEFAULT_FORMAT << "===================================================================="
        << std::endl;

    _PerformMainMenuOption(_ChooseFromMainMenu());
  }

public:
  static void Run()
  {
    _DrawScreenHeader("\tDir Manager");

    std::cout << DEFAULT_FORMAT << "ex: D:\\folder1\\folder2\\...\n\n";
    Dir::_Path = READ_TXT("Enter The Path Here ==> ");

    while (Dir::_Path[1] != ':')
      Dir::_Path = READ_TXT("Enter A Valid Path ==> ");

    Dir::_Path += '\\';

    Dir::read_dir();

    _ShowMainMenu();
  }
};