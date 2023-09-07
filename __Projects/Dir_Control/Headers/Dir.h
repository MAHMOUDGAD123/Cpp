#pragma once

#include <dirent.h>
#include "File.h"
#include "MG_Util.h"

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
          stream << file._Name + File::_sep + (file._Type.empty() ? "file" : file._Type) << std::endl;
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

      // if (file._Type == ext)
      if (_Comp(file, ext))
        if ((found = file._Name.find(target)) != std::string::npos)
          rename((_Path + info->d_name).c_str(),
                 (_Path + file._Name.erase(found, target.size()) + '.' + file._Type).c_str());
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

    dir = opendir(_Path.c_str());

    while (info = readdir(dir))
    {
      file = File::GetFullInfo(info->d_name);

      if (_Comp(file, ext))
        if ((found = file._Name.rfind(target)) != std::string::npos)
          rename((_Path + info->d_name).c_str(),
                 (_Path + file._Name.erase(found, target.size()) + '.' + file._Type).c_str());
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

    dir = opendir(_Path.c_str());

    while (info = readdir(dir))
    {
      file = File::GetFullInfo(info->d_name);

      if (_Comp(file, ext))
        rename((_Path + info->d_name).c_str(),
               (_Path + std::regex_replace(file._Name, std::regex(target.c_str()), "") + '.' + file._Type).c_str());
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

    dir = opendir(_Path.c_str());

    while (info = readdir(dir))
    {
      file = File::GetFullInfo(info->d_name);

      if (_Comp(file, ext))
        if ((found = file._Name.find(target)) != std::string::npos)
          rename((_Path + info->d_name).c_str(),
                 (_Path + (found > n ? file._Name.erase(found - n, n) : file._Name.substr(found)) + '.' + file._Type).c_str());
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

    dir = opendir(_Path.c_str());

    while (info = readdir(dir))
    {
      file = File::GetFullInfo(info->d_name);

      if (_Comp(file, ext))
        if ((found = file._Name.find(target)) != std::string::npos)
          rename((_Path + info->d_name).c_str(),
                 (_Path + (found + target.size() < file._Name.size() - 1 ? file._Name.erase(found + target.size(), n) : file._Name) + '.' + file._Type).c_str());
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

    dir = opendir(_Path.c_str());

    while (info = readdir(dir))
    {
      file = File::GetFullInfo(info->d_name);

      if (_Comp(file, ext))
        if ((found = file._Name.find(target)) != std::string::npos)
          rename((_Path + info->d_name).c_str(),
                 (_Path + file._Name.replace(found, target.size(), New) + '.' + file._Type).c_str());
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

    dir = opendir(_Path.c_str());

    while (info = readdir(dir))
    {
      file = File::GetFullInfo(info->d_name);

      if (_Comp(file, ext))
        if ((found = file._Name.rfind(target)) != std::string::npos)
          rename((_Path + info->d_name).c_str(),
                 (_Path + file._Name.replace(found, target.size(), New) + '.' + file._Type).c_str());
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

    dir = opendir(_Path.c_str());

    while (info = readdir(dir))
    {
      file = File::GetFullInfo(info->d_name);

      if (_Comp(file, ext))
        rename((_Path + info->d_name).c_str(),
               (_Path + std::regex_replace(file._Name, std::regex(Target.c_str()), New) + '.' + file._Type).c_str());
    }
    closedir(dir);
  }

  static void rename_files_left_counter(const std::string &new_name, const std::string &ext)
  {
    DIR *dir = nullptr;
    struct dirent *info = nullptr;
    File file;
    int n(0), digits_count((int)log10f(_Count));

    if (ext[0] == '/')
      _Comp = folder_comp;

    dir = opendir(_Path.c_str());

    while (info = readdir(dir))
    {
      file = File::GetFullInfo(info->d_name);

      if (_Comp(file, ext))
      {
        ++n;
        rename((_Path + info->d_name).c_str(),
               (_Path + '#' + std::string(digits_count - (int)log10f(n), '0') + std::to_string(n) + " -- " + new_name + '.' + file._Type).c_str());
      }
    }
    closedir(dir);
  }

  static void rename_files_right_counter(const std::string &new_name, const std::string &ext)
  {
    DIR *dir = nullptr;
    struct dirent *info = nullptr;
    File file;
    int n(0), digits_count((int)log10f(_Count));

    if (ext[0] == '/')
      _Comp = folder_comp;

    dir = opendir(_Path.c_str());

    while (info = readdir(dir))
    {
      file = File::GetFullInfo(info->d_name);

      if (_Comp(file, ext))
      {
        ++n;
        rename((_Path + info->d_name).c_str(),
               (_Path + new_name + " -- #" + std::string(digits_count - (int)log10f(n), '0') + std::to_string(n) + "." + file._Type).c_str());
      }
    }
    closedir(dir);
  }

  static void rename_files_mid_counter(const std::string &lhs, const std::string &rhs, const std::string &ext)
  {
    DIR *dir = nullptr;
    struct dirent *info = nullptr;
    File file;
    int n(0), digits_count((int)log10f(_Count));

    if (ext[0] == '/')
      _Comp = folder_comp;

    dir = opendir(_Path.c_str());

    while (info = readdir(dir))
    {
      file = File::GetFullInfo(info->d_name);

      if (_Comp(file, ext))
      {
        ++n;
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
        rename((_Path + info->d_name).c_str(),
               (_Path + file._Name + '.' + new_ext).c_str());
    }
    closedir(dir);
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

      rename((_Path + info->d_name).c_str(),
             (_Path + MG::utility::str_util::trim(file._Name) + '.' + file._Type).c_str());
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

    dir = opendir(_Path.c_str());

    while (info = readdir(dir))
    {
      file = File::GetFullInfo(info->d_name);

      if (_Comp(file, ext))
        rename((_Path + info->d_name).c_str(),
               (_Path + insert + file._Name + '.' + file._Type).c_str());
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

    dir = opendir(_Path.c_str());

    while (info = readdir(dir))
    {
      file = File::GetFullInfo(info->d_name);

      if (_Comp(file, ext))
        rename((_Path + info->d_name).c_str(),
               (_Path + file._Name + insert + '.' + file._Type).c_str());
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

    dir = opendir(_Path.c_str());

    while (info = readdir(dir))
    {
      file = File::GetFullInfo(info->d_name);

      if (_Comp(file, ext))
        if ((found = file._Name.find(target)) != std::string::npos && found)
          rename((_Path + info->d_name).c_str(),
                 (_Path + file._Name.insert(found, insert) + '.' + file._Type).c_str());
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

    dir = opendir(_Path.c_str());

    while (info = readdir(dir))
    {
      file = File::GetFullInfo(info->d_name);

      if (_Comp(file, ext))
        if ((found = file._Name.find(target)) != std::string::npos)
          if (found + target.size() < file._Name.size())
            rename((_Path + info->d_name).c_str(),
                   (_Path + file._Name.insert(found + target.size(), insert) + '.' + file._Type).c_str());
    }
    closedir(dir);
  }
};

std::string Dir::_Path = "";
int Dir::_Count = 0;
bool (*Dir::_Comp)(const File &, const std::string &) = nullptr; // file compare by default
