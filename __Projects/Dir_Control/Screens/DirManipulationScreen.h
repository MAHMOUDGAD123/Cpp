#pragma once

#include "Screen.h"
#include "../Headers/Dir.h"
#include "Dir_Manipulation/DirRemoveSubstringScreen.h"
#include "Dir_Manipulation/DirRenameItemsLCScreen.h"
#include "Dir_Manipulation/DirRenameItemsRCScreen.h"
#include "Dir_Manipulation/DirRenameItemsMCScreen.h"
#include "Dir_Manipulation/DirReplaceSubstringScreen.h"
#include "Dir_Manipulation/DirSmartReplaceSubstringScreen.h"
#include "Dir_Manipulation/DirChangeExtensionsScreen.h"
#include "Dir_Manipulation/DirSmartRemoveSubstringScreen.h"
#include "Dir_Manipulation/DirTrimItemsNamesScreen.h"
#include "Dir_Manipulation/DirAppendLeftScreen.h"
#include "Dir_Manipulation/DirAppendRightScreen.h"
#include "Dir_Manipulation/DirRemoveNBeforeScreen.h"
#include "Dir_Manipulation/DirRemoveNAfterScreen.h"
#include "Dir_Manipulation/DirInsertSubstringBefore.h"
#include "Dir_Manipulation/DirInsertSubstringAfter.h"
#include "Dir_Manipulation/DirAddItems.h"
#include "Dir_Manipulation/DirEraseItems.h"
#include "Dir_Manipulation/DirSmartEraseItemsIf.h"
#include "Dir_Manipulation/DirSmartEraseFiles.h"
#include "Dir_Manipulation/DirSmartEraseFilesRec.h"

#define BACK_TO_MANIPULATION_MENU _GoBackToManipulationMenu()
#define Jump_TO_MANIPULATION_MENU ShowManipulationMenu()

class clsDirManipulationScreen : private clsScreen
{
private:
  enum class en_ManipulationMenuOptions
  {
    eRemove_Substring = 1,
    eSm_Remove_Substring = 2,
    eRemove_n_Before = 3,
    eRemove_n_After = 4,
    eReplace_Substring = 5,
    eSm_Replace_Substring = 6,
    eRename_Files_LC = 7,
    eRename_Files_RC = 8,
    eRename_Files_MC = 9,
    eTrim_Names = 10,
    eAppend_Left = 11,
    eAppend_Right = 12,
    eInsert_Before = 13,
    eInsert_After = 14,
    eChange_Extension = 15,
    eAdd_Items = 16,
    eErase_Items = 17,
    eSm_Erase_Items_If = 18,
    eSm_Erase_Files = 19,
    eSm_Erase_Files_Rec = 20,
    eBack_To_Main_Menu = 0
  };

  static en_ManipulationMenuOptions _ChooseFromManipulationMenu()
  {
    return (en_ManipulationMenuOptions)User_Input::_ReadUserChoice(
        0,
        20,
        "Choose What To Perform From Manipulation Menu");
  }

  static void _GoBackToManipulationMenu()
  {
    std::cout << "\n\n"
              << DEFAULT_FORMAT << "-> Press any key to go back to Manipulation Menu...";
    PAUSE;
    ShowManipulationMenu();
  }

  /* Screens */
  /*====================================================================================================*/

  static void _ShowDirRemoveSubstringScreen()
  {
    clsDirRemoveSubstringScreen::Display();
  }

  static void _ShowDirSmartRemoveSubstringScreen()
  {
    clsDirSmartRemoveSubstringScreen::Display();
  }

  static void _ShowDirRemoveNBeforeScreen()
  {
    clsDirRemoveNBeforeScreen::Display();
  }

  static void _ShowDirRemoveNAfterScreen()
  {
    clsDirRemoveNAfterScreen::Display();
  }

  static void _ShowDirReplaceSubstringScreen()
  {
    clsDirReplaceSubstringScreen::Display();
  }

  static void _ShowDirSmartReplaceSubstringScreen()
  {
    clsDirSmartReplaceSubstringScreen::Display();
  }

  static void _ShowDirRenameFilesLCScreen()
  {
    clsDirRenameItemsLCScreen::Display();
  }

  static void _ShowDirRenameFilesRCScreen()
  {
    clsDirRenameItemsRCScreen::Display();
  }

  static void _ShowDirRenameFilesMCScreen()
  {
    clsDirRenameItemsMCScreen::Display();
  }

  static void _ShowDirTrimFilesNamesScreen()
  {
    clsDirTrimItemsNamesScreen::Display();
  }

  static void _ShowDirApprendLeftScreen()
  {
    clsDirAppendLeftScreen::Display();
  }

  static void _ShowDirApprendRightScreen()
  {
    clsDirAppendRightScreen::Display();
  }

  static void _ShowDirInsertBeforeScreen()
  {
    clsDirInsertBeforeScreen::Display();
  }

  static void _ShowDirInsertAfterScreen()
  {
    clsDirInsertAfterScreen::Display();
  }

  static void _ShowDirChangeExtensionsScreen()
  {
    clsDirChangeExtensionsScreen::Display();
  }

  static void _ShowDirAddItemsScreen()
  {
    clsDirAddItemsScreen::Display();
  }

  static void _ShowDirEraseItemsScreen()
  {
    clsDirEraseItemsScreen::Display();
  }

  static void _ShowDirSmartEraseItemsIfScreen()
  {
    clsDirSmartEraseItemsIfScreen::Display();
  }

  static void _ShowDirSmartEraseFilesScreen()
  {
    clsDirSmartEraseFilesScreen::Display();
  }

  static void _ShowDirSmartEraseFilesRecScreen()
  {
    clsDirSmartEraseFilesRecScreen::Display();
  }

  /*====================================================================================================*/

  static void _PerformManipulationMenuOption(en_ManipulationMenuOptions UserChoice)
  {
    switch (UserChoice)
    {
    case en_ManipulationMenuOptions::eRemove_Substring:
      _ShowDirRemoveSubstringScreen();
      BACK_TO_MANIPULATION_MENU;
      return;

    case en_ManipulationMenuOptions::eSm_Remove_Substring:
      _ShowDirSmartRemoveSubstringScreen();
      BACK_TO_MANIPULATION_MENU;
      return;

    case en_ManipulationMenuOptions::eRemove_n_Before:
      _ShowDirRemoveNBeforeScreen();
      BACK_TO_MANIPULATION_MENU;
      return;

    case en_ManipulationMenuOptions::eRemove_n_After:
      _ShowDirRemoveNAfterScreen();
      BACK_TO_MANIPULATION_MENU;
      return;

    case en_ManipulationMenuOptions::eReplace_Substring:
      _ShowDirReplaceSubstringScreen();
      BACK_TO_MANIPULATION_MENU;
      return;

    case en_ManipulationMenuOptions::eSm_Replace_Substring:
      _ShowDirSmartReplaceSubstringScreen();
      BACK_TO_MANIPULATION_MENU;
      return;

    case en_ManipulationMenuOptions::eRename_Files_LC:
      _ShowDirRenameFilesLCScreen();
      BACK_TO_MANIPULATION_MENU;
      return;

    case en_ManipulationMenuOptions::eRename_Files_RC:
      _ShowDirRenameFilesRCScreen();
      BACK_TO_MANIPULATION_MENU;
      return;

    case en_ManipulationMenuOptions::eRename_Files_MC:
      _ShowDirRenameFilesMCScreen();
      BACK_TO_MANIPULATION_MENU;
      return;

    case en_ManipulationMenuOptions::eTrim_Names:
      _ShowDirTrimFilesNamesScreen();
      BACK_TO_MANIPULATION_MENU;
      return;

    case en_ManipulationMenuOptions::eAppend_Left:
      _ShowDirApprendLeftScreen();
      BACK_TO_MANIPULATION_MENU;
      return;

    case en_ManipulationMenuOptions::eAppend_Right:
      _ShowDirApprendRightScreen();
      BACK_TO_MANIPULATION_MENU;
      return;

    case en_ManipulationMenuOptions::eInsert_Before:
      _ShowDirInsertBeforeScreen();
      BACK_TO_MANIPULATION_MENU;
      return;

    case en_ManipulationMenuOptions::eInsert_After:
      _ShowDirInsertAfterScreen();
      BACK_TO_MANIPULATION_MENU;
      return;

    case en_ManipulationMenuOptions::eChange_Extension:
      _ShowDirChangeExtensionsScreen();
      BACK_TO_MANIPULATION_MENU;
      return;

    case en_ManipulationMenuOptions::eAdd_Items:
      _ShowDirAddItemsScreen();
      BACK_TO_MANIPULATION_MENU;
      return;

    case en_ManipulationMenuOptions::eErase_Items:
      _ShowDirEraseItemsScreen();
      BACK_TO_MANIPULATION_MENU;
      return;

    case en_ManipulationMenuOptions::eSm_Erase_Items_If:
      _ShowDirSmartEraseItemsIfScreen();
      BACK_TO_MANIPULATION_MENU;
      return;

    case en_ManipulationMenuOptions::eSm_Erase_Files:
      _ShowDirSmartEraseFilesScreen();
      BACK_TO_MANIPULATION_MENU;
      return;

    case en_ManipulationMenuOptions::eSm_Erase_Files_Rec:
      _ShowDirSmartEraseFilesRecScreen();
      BACK_TO_MANIPULATION_MENU;
      return;

    case en_ManipulationMenuOptions::eBack_To_Main_Menu:
      return;
    }
  }

public:
  static void ShowManipulationMenu()
  {
    _DrawScreenHeader("\tDir Manipulation");
    _PrintPathTag();

    std::cout
        << DEFAULT_FORMAT << "\t\t\t\b\b\b[1]   Remove Substring.\n"
        << DEFAULT_FORMAT << "\t\t\t\b\b\b[2]   Smart Remove Substring.\n"
        << DEFAULT_FORMAT << "\t\t\t\b\b\b[3]   Remove N Before.\n"
        << DEFAULT_FORMAT << "\t\t\t\b\b\b[4]   Remove N After.\n"
        << DEFAULT_FORMAT << "\t\t\t\b\b\b[5]   Replace Substring.\n"
        << DEFAULT_FORMAT << "\t\t\t\b\b\b[6]   Smart Replace Substring.\n"
        << DEFAULT_FORMAT << "\t\t\t\b\b\b[7]   Rename All (Left Counter).\n"
        << DEFAULT_FORMAT << "\t\t\t\b\b\b[8]   Rename All (Right Counter).\n"
        << DEFAULT_FORMAT << "\t\t\t\b\b\b[9]   Rename All (Mid Counter).\n"
        << DEFAULT_FORMAT << "\t\t\t\b\b\b[10]  Trim All Names.\n"
        << DEFAULT_FORMAT << "\t\t\t\b\b\b[11]  Names Append Left.\n"
        << DEFAULT_FORMAT << "\t\t\t\b\b\b[12]  Names Append Right.\n"
        << DEFAULT_FORMAT << "\t\t\t\b\b\b[13]  Insert Substring Before.\n"
        << DEFAULT_FORMAT << "\t\t\t\b\b\b[14]  Insert Substring After.\n"
        << DEFAULT_FORMAT << "\t\t\t\b\b\b[15]  Change Files Extention.\n"
        << DEFAULT_FORMAT << "\t\t\t\b\b\b[16]  Add Items.\n"
        << DEFAULT_FORMAT << "\t\t\t\b\b\b[17]  Erase Items.\n"
        << DEFAULT_FORMAT << "\t\t\t\b\b\b[18]  Smart Erase Items If.\n"
        << DEFAULT_FORMAT << "\t\t\t\b\b\b[19]  Smart Erase Files.\n"
        << DEFAULT_FORMAT << "\t\t\t\b\b\b[20]  Smart Erase Files Rec.\n"
        << DEFAULT_FORMAT << "\t\t\t\b\b\b[0]   Back To Main Menu.\n"
        << DEFAULT_FORMAT << "===================================================================="
        << std::endl;

    _PerformManipulationMenuOption(_ChooseFromManipulationMenu());
  }
};