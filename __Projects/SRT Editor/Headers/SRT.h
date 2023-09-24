#pragma once

#include <iostream>
#include <fstream>
#include <cctype>
#include "Tools.h"

namespace SRT
{
  static std::string __path;
  static std::string __fileName;
  static std::string __prefix;
  static std::string __postfix;

  static bool __is_subtitle(const std::string &_l)
  {
    if (_l.empty())
      return false;

    return !(isdigit(_l[0]) && isdigit(_l[_l.size() - 1]));
  }

  static bool __update_srt()
  {
    std::ifstream _file(__path + __fileName + ".srt");

    // check _file first
    if (!_file)
      return false;

    std::ofstream _updated(__path + __fileName + " -- Updated.srt", std::ios::out | std::ios::app);
    std::string _line;

    // add first line (to fix first line bug)
    std::getline(_file, _line);
    _updated << _line << std::endl;

    while (std::getline(_file, _line))
    {
      if (__is_subtitle(_line))
        _updated << __prefix + _line + __postfix << std::endl;
      else
        _updated << _line << std::endl;
    }

    _file.close();

    if (_updated)
      _updated.close();

    return true;
  }
}