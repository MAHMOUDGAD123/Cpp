#pragma once

#include "MG_Util.h"

struct File
{
  static constexpr inline const char *const Records_Path = "../Data/Files.txt";
  static constexpr inline const char *const _sep = "<||>";

private:
  std::string _Name, _Type;

  static File _RecordTofileObj(const std::string &Record) noexcept
  {
    std::vector<std::string> _Records(MG::utility::str_util::split_str(Record, _sep, 2));
    return {_Records[0], _Records[1]};
  }

  std::string _FileObjToRecord(const File &file) noexcept
  {
    std::string _Record(file._Name + _sep);
    _Record += file._Type;
    return _Record;
  }

  static std::vector<File> _LoadFilesFromFile() noexcept
  {
    std::vector<File> _files;
    std::ifstream _File(Records_Path);

    if (_File)
    {
      std::string _Line;

      while (std::getline(_File, _Line))
        _files.push_back(_RecordTofileObj(_Line));

      _File.close();
    }

    return _files;
  }

  void _SavefilesToFile(const std::vector<File> &files) noexcept
  {
    std::ofstream _File(Records_Path);

    if (_File)
    {
      for (const File &file : files)
        _File << _FileObjToRecord(file) << std::endl;

      _File.close();
    }
  }

public:
  File() noexcept
      : _Name{}, _Type{}
  {
  }

  File(const std::string &name, const std::string &type) noexcept
      : _Name(name), _Type(type)
  {
  }

  File(const File &file) noexcept
      : _Name(file._Name), _Type(file._Type)
  {
  }

  bool empty() const noexcept
  {
    return _Name.empty();
  }

  static File Find(const std::string &name) noexcept
  {
    std::ifstream _File(Records_Path);

    if (_File)
    {
      std::string Line;
      File file;

      while (getline(_File, Line))
      {
        file = _RecordTofileObj(Line);

        if (file._Name == name)
        {
          _File.close();
          return file;
        }
      }
      _File.close();
    }
    return {};
  }

  std::string full_name() const noexcept
  {
    return this->_Name + '.' + this->_Type;
  }

  static std::string GetFileName(const std::string &data) noexcept
  {
    if (data.empty())
      return {};

    size_t found(0);

    if ((found = data.rfind('.')) == std::string::npos)
      return data;

    return data.substr(0, found);
  }

  static std::string GetFileType(const std::string &data) noexcept
  {
    if (data.empty())
      return {};

    size_t found(0);

    if ((found = data.rfind('.')) == std::string::npos)
      return "folder";

    return data.substr(found + 1);
  }

  static File GetFullInfo(const std::string &data) noexcept
  {
    if (data.empty())
      return {};

    size_t found(0);

    if ((found = data.rfind('.')) == std::string::npos)
      return {data, "folder"};

    return {data.substr(0, found), data.substr(found + 1)};
  }
  
  // friends list
  friend class clsScreen;
  friend class clsListAllFilesScreen;
  friend struct Dir;
};
