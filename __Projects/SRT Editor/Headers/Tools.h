#pragma once

#include <iostream>
#include <iomanip>

#define CLEAR_SCREEN system("cls");
#define PAUSE system("pause>0")
#define DEFAULT_FORMAT std::setw(_width) << std::left << ""
#define READ_TXT User_Input::_ReadTxtFromUser
#define CONFIRM User_Input::_Read_YesOrNo

constexpr static inline const uint8_t _width = 30;

namespace User_Input
{
  static std::string _ReadTxtFromUser(const char *const msg = "")
  {
    std::string txt;
    std::cout << DEFAULT_FORMAT << msg;
    std::getline(std::cin >> std::ws, txt);
    return txt;
  }

  static bool _Read_YesOrNo(const char *const msg = "")
  {
    std::string S;
    do
    {
      std::cout << DEFAULT_FORMAT << msg;
      std::cin >> S;

    } while (!(S == "Y" || S == "y" || S == "N" || S == "n"));

    return (S == "Y" || S == "y");
  }

}