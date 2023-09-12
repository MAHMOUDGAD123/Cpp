#pragma once

#include <dirent.h>
#include "File.h"
#include "MG_Util.h"

namespace str_util = MG::utility::str_util;

struct Dir
{
  static std::string _Path;
  static int _Count;
  static bool (*_Comp)(const File &file, const std::string &ext);

  /* Compare Functions for extension comparision */
  /*==============================================*/

  static bool file_comp(const File &file, const std::string &ext)
  {
    return file._Type == ext;
  }

  static bool folder_comp(const File &file, const std::string &ext)
  {
    return file._Type.empty() && !file.empty() && file._Name[0] != '.';
  }

  /*==============================================*/

  static void read_dir()
  {
    DIR *dir = nullptr;
    struct dirent *info = nullptr;
    std::ofstream stream(File::Records_Path);
    _Count = 0;

    dir = opendir(_Path.c_str());

    if (stream)
    {
      File file; // { file_Name, file_Type }

      while (info = readdir(dir))
      {
        file = File::GetFullInfo(info->d_name);

        if (!file.empty() && file._Name[0] != '.')
        {
          stream << file._Name + File::_sep + (file._Type.empty() ? "folder" : file._Type) << std::endl;
          ++_Count;
        }
      }
      stream.close();
    }
    closedir(dir);
  }

  static void remove_substring(const std::string &target, const std::string &ext)
  {
    DIR *dir = nullptr;
    struct dirent *info = nullptr;
    File file;
    size_t found(0);

    if (ext[0] == '/')
      _Comp = folder_comp;
    else
      _Comp = file_comp;

    dir = opendir(_Path.c_str());

    while (info = readdir(dir))
    {
      file = File::GetFullInfo(info->d_name);

      if (_Comp(file, ext))
        if ((found = file._Name.find(target)) != std::string::npos)
          system(("REN \"" + _Path + info->d_name + std::string("\" \"") + file._Name.erase(found, target.size()) + '.' + file._Type + "\"").c_str());
      // rename((_Path + info->d_name).c_str(),
      //  (_Path + file._Name.erase(found, target.size()) + '.' + file._Type).c_str());
    }
    closedir(dir);
  }
  static void remove_substring_r(const std::string &target, const std::string &ext)
  {
    DIR *dir = nullptr;
    struct dirent *info = nullptr;
    File file;
    size_t found(0);

    if (ext[0] == '/')
      _Comp = folder_comp;
    else
      _Comp = file_comp;

    dir = opendir(_Path.c_str());

    while (info = readdir(dir))
    {
      file = File::GetFullInfo(info->d_name);

      if (_Comp(file, ext))
        if ((found = file._Name.rfind(target)) != std::string::npos)
          system(("REN \"" + _Path + info->d_name + std::string("\" \"") + file._Name.erase(found, target.size()) + '.' + file._Type + "\"").c_str());
      // rename((_Path + info->d_name).c_str(),
      //  (_Path + file._Name.erase(found, target.size()) + '.' + file._Type).c_str());
    }
    closedir(dir);
  }

  static void remove_all_substring(const std::string &target, const std::string &ext)
  {
    DIR *dir = nullptr;
    struct dirent *info = nullptr;
    File file;

    if (ext[0] == '/')
      _Comp = folder_comp;
    else
      _Comp = file_comp;

    dir = opendir(_Path.c_str());

    while (info = readdir(dir))
    {
      file = File::GetFullInfo(info->d_name);

      if (_Comp(file, ext))
        system(("REN \"" + _Path + info->d_name + std::string("\" \"") + std::regex_replace(file._Name, std::regex(target), "") + '.' + file._Type + "\"").c_str());
      // rename((_Path + info->d_name).c_str(),
      //  (_Path + std::regex_replace(file._Name, std::regex(target.c_str()), "") + '.' + file._Type).c_str());
    }
    closedir(dir);
  }

  static void remove_n_before(const std::string &target, size_t n, const std::string &ext)
  {
    DIR *dir = nullptr;
    struct dirent *info = nullptr;
    File file;
    size_t found(0);

    if (ext[0] == '/')
      _Comp = folder_comp;
    else
      _Comp = file_comp;

    dir = opendir(_Path.c_str());

    while (info = readdir(dir))
    {
      file = File::GetFullInfo(info->d_name);

      if (_Comp(file, ext))
        if ((found = file._Name.find(target)) != std::string::npos)
          system(("REN \"" + _Path + info->d_name + std::string("\" \"") + (found > n ? file._Name.erase(found - n, n) : file._Name.substr(found)) + '.' + file._Type + "\"").c_str());
      // rename((_Path + info->d_name).c_str(),
      //  (_Path + (found > n ? file._Name.erase(found - n, n) : file._Name.substr(found)) + '.' + file._Type).c_str());
    }
    closedir(dir);
  }

  static void remove_n_after(const std::string &target, size_t n, const std::string &ext)
  {
    DIR *dir = nullptr;
    struct dirent *info = nullptr;
    File file;
    size_t found(0);

    if (ext[0] == '/')
      _Comp = folder_comp;
    else
      _Comp = file_comp;

    dir = opendir(_Path.c_str());

    while (info = readdir(dir))
    {
      file = File::GetFullInfo(info->d_name);

      if (_Comp(file, ext))
        if ((found = file._Name.find(target)) != std::string::npos)
          system(("REN \"" + _Path + info->d_name + std::string("\" \"") + (found + target.size() < file._Name.size() - 1 ? file._Name.erase(found + target.size(), n) : file._Name) + '.' + file._Type + "\"").c_str());
      // rename((_Path + info->d_name).c_str(),
      //  (_Path + (found + target.size() < file._Name.size() - 1 ? file._Name.erase(found + target.size(), n) : file._Name) + '.' + file._Type).c_str());
    }
    closedir(dir);
  }

  static void replace_substring(const std::string &target, const std::string &New, const std::string &ext)
  {
    DIR *dir = nullptr;
    struct dirent *info = nullptr;
    File file;
    size_t found(0);

    if (ext[0] == '/')
      _Comp = folder_comp;
    else
      _Comp = file_comp;

    dir = opendir(_Path.c_str());

    while (info = readdir(dir))
    {
      file = File::GetFullInfo(info->d_name);

      if (_Comp(file, ext))
        if ((found = file._Name.find(target)) != std::string::npos)
          system(("REN \"" + _Path + info->d_name + std::string("\" \"") + file._Name.replace(found, target.size(), New) + '.' + file._Type + "\"").c_str());
      // rename((_Path + info->d_name).c_str(),
      //  (_Path + file._Name.replace(found, target.size(), New) + '.' + file._Type).c_str());
    }
    closedir(dir);
  }
  static void replace_substring_r(const std::string &target, const std::string &New, const std::string &ext)
  {
    DIR *dir = nullptr;
    struct dirent *info = nullptr;
    File file;
    size_t found(0);

    if (ext[0] == '/')
      _Comp = folder_comp;
    else
      _Comp = file_comp;

    dir = opendir(_Path.c_str());

    while (info = readdir(dir))
    {
      file = File::GetFullInfo(info->d_name);

      if (_Comp(file, ext))
        if ((found = file._Name.rfind(target)) != std::string::npos)
          system(("REN \"" + _Path + info->d_name + std::string("\" \"") + file._Name.replace(found, target.size(), New) + '.' + file._Type + "\"").c_str());
      // rename((_Path + info->d_name).c_str(),
      //  (_Path + file._Name.replace(found, target.size(), New) + '.' + file._Type).c_str());
    }
    closedir(dir);
  }

  static void replace_all_substring(const std::string &Target, const std::string &New, const std::string &ext)
  {
    DIR *dir = nullptr;
    struct dirent *info = nullptr;
    File file;

    if (ext[0] == '/')
      _Comp = folder_comp;
    else
      _Comp = file_comp;

    dir = opendir(_Path.c_str());

    while (info = readdir(dir))
    {
      file = File::GetFullInfo(info->d_name);

      if (_Comp(file, ext))
        system(("REN \"" + _Path + info->d_name + std::string("\" \"") + std::regex_replace(file._Name, std::regex(Target), New) + '.' + file._Type + "\"").c_str());
      // rename((_Path + info->d_name).c_str(),
      //  (_Path + std::regex_replace(file._Name, std::regex(Target.c_str()), New) + '.' + file._Type).c_str());
    }
    closedir(dir);
  }

  static void rename_items_left_counter(const std::string &new_name, const std::string &ext)
  {
    DIR *dir = nullptr;
    struct dirent *info = nullptr;
    File file;
    int n(0), digits_count((int)log10f(_Count));

    if (ext[0] == '/')
      _Comp = folder_comp;
    else
      _Comp = file_comp;

    dir = opendir(_Path.c_str());

    while (info = readdir(dir))
    {
      file = File::GetFullInfo(info->d_name);

      if (_Comp(file, ext))
      {
        ++n;
        // system(("REN \"" + _Path + info->d_name + std::string("\" \"") + '#' + std::string(digits_count - (int)log10f(n), '0') + std::to_string(n) + " -- " + new_name + '.' + file._Type + "\"").c_str());
        rename((_Path + info->d_name).c_str(),
               (_Path + '#' + std::string(digits_count - (int)log10f(n), '0') + std::to_string(n) + " -- " + new_name + '.' + file._Type).c_str());
      }
    }
    closedir(dir);
  }

  static void rename_items_right_counter(const std::string &new_name, const std::string &ext)
  {
    DIR *dir = nullptr;
    struct dirent *info = nullptr;
    File file;
    int n(0), digits_count((int)log10f(_Count));

    if (ext[0] == '/')
      _Comp = folder_comp;
    else
      _Comp = file_comp;

    dir = opendir(_Path.c_str());

    while (info = readdir(dir))
    {
      file = File::GetFullInfo(info->d_name);

      if (_Comp(file, ext))
      {
        ++n;
        // system(("REN \"" + _Path + info->d_name + std::string("\" \"") + new_name + " -- #" + std::string(digits_count - (int)log10f(n), '0') + std::to_string(n) + '.' + file._Type + "\"").c_str());
        rename((_Path + info->d_name).c_str(),
               (_Path + new_name + " -- #" + std::string(digits_count - (int)log10f(n), '0') + std::to_string(n) + "." + file._Type).c_str());
      }
    }
    closedir(dir);
  }

  static void rename_items_mid_counter(const std::string &lhs, const std::string &rhs, const std::string &ext)
  {
    DIR *dir = nullptr;
    struct dirent *info = nullptr;
    File file;
    int n(0), digits_count((int)log10f(_Count));

    if (ext[0] == '/')
      _Comp = folder_comp;
    else
      _Comp = file_comp;

    dir = opendir(_Path.c_str());

    while (info = readdir(dir))
    {
      file = File::GetFullInfo(info->d_name);

      if (_Comp(file, ext))
      {
        ++n;
        // system(("REN \"" + _Path + info->d_name + std::string("\" \"") + lhs + " -- #" + std::string(digits_count - (int)log10f(n), '0') + std::to_string(n) + " -- " + rhs + '.' + file._Type + "\"").c_str());
        rename((_Path + info->d_name).c_str(),
               (_Path + lhs + " -- #" + std::string(digits_count - (int)log10f(n), '0') + std::to_string(n) + " -- " + rhs + "." + file._Type).c_str());
      }
    }
    closedir(dir);
  }

  static void change_extensions(const std::string &old_ext, const std::string &new_ext)
  {
    DIR *dir = nullptr;
    struct dirent *info = nullptr;
    File file;

    dir = opendir(_Path.c_str());

    while (info = readdir(dir))
    {
      file = File::GetFullInfo(info->d_name);

      if (file._Type == old_ext)
        system(("REN \"" + _Path + info->d_name + std::string("\" \"") + file._Name + '.' + new_ext + "\"").c_str());
      // rename((_Path + info->d_name).c_str(),
      //  (_Path + file._Name + '.' + new_ext).c_str());
    }
    closedir(dir);
  }

  static void add_n_folders(int n, const std::string &f_name)
  {
    int digits_count((int)log10f(n));
    std::string folder;

    while (n)
    {
      folder = _Path + f_name + "___#" + std::string(digits_count - (int)log10f(n), '0') + std::to_string(n);
      std::filesystem::create_directory(folder);
      --n;
    }
  }

  static void add_n_files(const std::string &Extension, int n, const std::string &f_name)
  {
    int digits_count((int)log10f(n));
    std::string file;

    while (n)
    {
      file = _Path + f_name + "___#" + std::string(digits_count - (int)log10f(n), '0') + std::to_string(n) + '.' + Extension;
      std::ofstream os;
      os.open(file);
      os.close();
      --n;
    }
  }

  static void add_n_items(const std::string &Extension, int n, const std::string &item_name)
  {
    if (!n)
      return;

    if (Extension[0] == '/')
      add_n_folders(n, item_name.empty() ? "Folder" : item_name);
    else
      add_n_files(Extension, n, item_name.empty() ? "File" : item_name);
  }

  static void erase_items(const std::string &format)
  {
    std::vector<std::string> targets(str_util::split_str(format, "///"));

    for (const std::string &item : targets)
      std::filesystem::remove_all(_Path + item);
  }

  static void smart_erase_items_if(const std::string &format)
  {
    DIR *dir = nullptr;
    struct dirent *info = nullptr;

    dir = opendir(_Path.c_str());

    std::vector<std::string> targets(str_util::split_str(format, "///"));

    while (info = readdir(dir))
      for (const std::string &item : targets)
        if (std::regex_search(info->d_name, std::regex(item)))
          std::filesystem::remove_all(_Path + info->d_name);
  }

  static void smart_files_erase(const std::string &format)
  {
    std::vector<std::string> targets(str_util::split_str(format, "///"));

    for (const std::string &item : targets)
      system(("DEL /Q \"" + _Path + item + '\"').c_str());
  }

  static void smart_files_erase_rec(const std::string &format)
  {
    std::vector<std::string> targets(str_util::split_str(format, "///"));

    for (const std::string &item : targets)
      system(("DEL /S /Q \"" + _Path + item + '\"').c_str());
  }

  static void trim_names()
  {
    DIR *dir = nullptr;
    struct dirent *info = nullptr;
    File file;

    dir = opendir(_Path.c_str());

    while (info = readdir(dir))
    {
      file = File::GetFullInfo(info->d_name);
      system(("REN \"" + _Path + info->d_name + std::string("\" \"") + str_util::trim(file._Name) + '.' + file._Type + "\"").c_str());
      // rename((_Path + info->d_name).c_str(),
      //  (_Path + MG::utility::str_util::trim(file._Name) + '.' + file._Type).c_str());
    }
    closedir(dir);
  }

  static void append_left(const std::string &insert, const std::string &ext)
  {
    DIR *dir = nullptr;
    struct dirent *info = nullptr;
    File file;

    if (ext[0] == '/')
      _Comp = folder_comp;
    else
      _Comp = file_comp;

    dir = opendir(_Path.c_str());

    while (info = readdir(dir))
    {
      file = File::GetFullInfo(info->d_name);

      if (_Comp(file, ext))
        system(("REN \"" + _Path + info->d_name + std::string("\" \"") + insert + file._Name + '.' + file._Type + "\"").c_str());
      // rename((_Path + info->d_name).c_str(),
      //  (_Path + insert + file._Name + '.' + file._Type).c_str());
    }
    closedir(dir);
  }

  static void append_right(const std::string &insert, const std::string &ext)
  {
    DIR *dir = nullptr;
    struct dirent *info = nullptr;
    File file;

    if (ext[0] == '/')
      _Comp = folder_comp;
    else
      _Comp = file_comp;

    dir = opendir(_Path.c_str());

    while (info = readdir(dir))
    {
      file = File::GetFullInfo(info->d_name);

      if (_Comp(file, ext))
        system(("REN \"" + _Path + info->d_name + std::string("\" \"") + file._Name + insert + '.' + file._Type + "\"").c_str());
      // rename((_Path + info->d_name).c_str(),
      //  (_Path + file._Name + insert + '.' + file._Type).c_str());
    }
    closedir(dir);
  }

  static void insert_before(const std::string &target, const std::string &insert, const std::string &ext)
  {
    DIR *dir = nullptr;
    struct dirent *info = nullptr;
    File file;
    size_t found(0);

    if (ext[0] == '/')
      _Comp = folder_comp;
    else
      _Comp = file_comp;

    dir = opendir(_Path.c_str());

    while (info = readdir(dir))
    {
      file = File::GetFullInfo(info->d_name);

      if (_Comp(file, ext))
        if ((found = file._Name.find(target)) != std::string::npos && found)
          system(("REN \"" + _Path + info->d_name + std::string("\" \"") + file._Name.insert(found, insert) + '.' + file._Type + "\"").c_str());
      // rename((_Path + info->d_name).c_str(),
      //  (_Path + file._Name.insert(found, insert) + '.' + file._Type).c_str());
    }
    closedir(dir);
  }
  static void insert_after(const std::string &target, const std::string &insert, const std::string &ext)
  {
    DIR *dir = nullptr;
    struct dirent *info = nullptr;
    File file;
    size_t found(0);

    if (ext[0] == '/')
      _Comp = folder_comp;
    else
      _Comp = file_comp;

    dir = opendir(_Path.c_str());

    while (info = readdir(dir))
    {
      file = File::GetFullInfo(info->d_name);

      if (_Comp(file, ext))
        if ((found = file._Name.find(target)) != std::string::npos)
          system(("REN \"" + _Path + info->d_name + std::string("\" \"") + (found + target.size() < file._Name.size() ? file._Name.insert(found + target.size(), insert) : file._Name.append(insert)) + '.' + file._Type + "\"").c_str());
      // rename((_Path + info->d_name).c_str(),
      //  (_Path + file._Name.insert(found + target.size(), insert) + '.' + file._Type).c_str());
    }
    closedir(dir);
  }
};

std::string Dir::_Path = "";
int Dir::_Count = 0;
bool (*Dir::_Comp)(const File &, const std::string &) = nullptr; // file compare by default
