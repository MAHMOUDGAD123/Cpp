#pragma once

#include "Screen.h"
#include "../Headers/Dir.h"
#include "Dir_Manipulation/DirRemoveSubstringScreen.h"
#include "Dir_Manipulation/DirRenameFilesLCScreen.h"
#include "Dir_Manipulation/DirRenameFilesRCScreen.h"
#include "Dir_Manipulation/DirRenameFilesMCScreen.h"
#include "Dir_Manipulation/DirReplaceSubstringScreen.h"
#include "Dir_Manipulation/DirReplaceAllSubstringScreen.h"
#include "Dir_Manipulation/DirChangeExtensionsScreen.h"
#include "Dir_Manipulation/DirRemoveAllSubstringScreen.h"
#include "Dir_Manipulation/DirTrimFilesNamesScreen.h"
#include "Dir_Manipulation/DirAppendLeftScreen.h"
#include "Dir_Manipulation/DirAppendRightScreen.h"
#include "Dir_Manipulation/DirRemoveNBeforeScreen.h"
#include "Dir_Manipulation/DirRemoveNAfterScreen.h"
#include "Dir_Manipulation/DirInsertSubstringBefore.h"
#include "Dir_Manipulation/DirInsertSubstringAfter.h"
#include "Dir_Manipulation/DirAddItems.h"
#include "Dir_Manipulation/DirRemoveItems.h"
#include "Dir_Manipulation/DirRemoveItemsRec.h"

#define BACK_TO_MANIPULATION_MENU _GoBackToManipulationMenu()
#define Jump_TO_MANIPULATION_MENU ShowManipulationMenu()

class clsDirManipulationScreen : private clsScreen
{
private:
  enum class en_ManipulationMenuOptions
  {
    eRemove_Substring = 1,
    eRemove_All_Substring = 2,
    eRemove_n_Before = 3,
    eRemove_n_After = 4,
    eReplace_Substring = 5,
    eReplace_All_Substring = 6,
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
    eRemove_Items = 17,
    eRemove_Items_Rec = 18,
    eBack_To_Main_Menu = 0
  };

  static en_ManipulationMenuOptions _ChooseFromManipulationMenu()
  {
    return (en_ManipulationMenuOptions)_ReadUserChoice(0, 18, "Choose What To Perform From Manipulation Menu");
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

  static void _ShowDirRemoveAllSubstringScreen()
  {
    clsDirRemoveAllSubstringScreen::Display();
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

  static void _ShowDirReplaceAllSubstringScreen()
  {
    clsDirReplaceAllSubstringScreen::Display();
  }

  static void _ShowDirRenameFilesLCScreen()
  {
    clsDirRenameFilesLCScreen::Display();
  }

  static void _ShowDirRenameFilesRCScreen()
  {
    clsDirRenameFilesRCScreen::Display();
  }

  static void _ShowDirRenameFilesMCScreen()
  {
    clsDirRenameFilesMCScreen::Display();
  }

  static void _ShowDirTrimFilesNamesScreen()
  {
    clsDirTrimFilesNamesScreen::Display();
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

  static void _ShowDirRemoveItemsScreen()
  {
    clsDirRemoveItemsScreen::Display();
  }
  
  static void _ShowDirRemoveItemsRecScreen()
  {
    clsDirRemoveItemsRecScreen::Display();
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

    case en_ManipulationMenuOptions::eRemove_All_Substring:
      _ShowDirRemoveAllSubstringScreen();
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

    case en_ManipulationMenuOptions::eReplace_All_Substring:
      _ShowDirReplaceAllSubstringScreen();
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

    case en_ManipulationMenuOptions::eRemove_Items:
      _ShowDirRemoveItemsScreen();
      BACK_TO_MANIPULATION_MENU;
      return;

    case en_ManipulationMenuOptions::eRemove_Items_Rec:
      _ShowDirRemoveItemsRecScreen();
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
        << DEFAULT_FORMAT << "\t\t\t[1]   Remove Substring.\n"
        << DEFAULT_FORMAT << "\t\t\t[2]   Remove All Substring.\n"
        << DEFAULT_FORMAT << "\t\t\t[3]   Remove N Before.\n"
        << DEFAULT_FORMAT << "\t\t\t[4]   Remove N After.\n"
        << DEFAULT_FORMAT << "\t\t\t[5]   Replace Substring.\n"
        << DEFAULT_FORMAT << "\t\t\t[6]   Replace All Substring.\n"
        << DEFAULT_FORMAT << "\t\t\t[7]   Rename All (Left Counter).\n"
        << DEFAULT_FORMAT << "\t\t\t[8]   Rename All (Right Counter).\n"
        << DEFAULT_FORMAT << "\t\t\t[9]   Rename All (Mid Counter).\n"
        << DEFAULT_FORMAT << "\t\t\t[10]  Trim All Names.\n"
        << DEFAULT_FORMAT << "\t\t\t[11]  Names Append Left.\n"
        << DEFAULT_FORMAT << "\t\t\t[12]  Names Append Right.\n"
        << DEFAULT_FORMAT << "\t\t\t[13]  Insert Substring Before.\n"
        << DEFAULT_FORMAT << "\t\t\t[14]  Insert Substring After.\n"
        << DEFAULT_FORMAT << "\t\t\t[15]  Change Files Extention.\n"
        << DEFAULT_FORMAT << "\t\t\t[16]  Add Items (folder | file).\n"
        << DEFAULT_FORMAT << "\t\t\t[17]  Remove Items (folder | file).\n"
        << DEFAULT_FORMAT << "\t\t\t[18]  Remove Items Rec (folder | file).\n"
        << DEFAULT_FORMAT << "\t\t\t[0]   Back To Main Menu.\n"
        << DEFAULT_FORMAT << "===================================================================="
        << std::endl;

    _PerformManipulationMenuOption(_ChooseFromManipulationMenu());
  }
};