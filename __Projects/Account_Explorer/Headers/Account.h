#pragma once

#include <fstream>
#include <strstream>
#include "MG_Util.h"
#include "Date.h"

#define _Encrypt_ MG::utility::str_util::_Encrypt_
#define _Decrypt_ MG::utility::str_util::_Decrypt_
#define _Key_ MG::utility::str_util::_Key

static constexpr const char *const _Accounts_File = "../Data/Accounts.txt";

class Account final
{
  enum class en_Mode
  {
    EmptyMode = 0,
    UpdateMode = 1,
    AddNewMode = 2
  };

  en_Mode _Mode;
  std::string _Id, _Email, _Password;
  bool _DeleteFlag = false; // not a part of record

public:
  Account() noexcept
      : _Mode(en_Mode::EmptyMode), _Id(""), _Email(""), _Password("")
  {
  }

  Account(const std::string &Id) noexcept
      : _Mode(en_Mode::AddNewMode), _Id(Id), _Email(""), _Password("")
  {
  }

  Account(const Account &Acc) noexcept
      : _Mode(Acc._Mode), _Id(Acc._Id), _Email(Acc._Email), _Password(Acc._Password)
  {
  }

  Account(en_Mode Mode, const std::string &Id, const std::string &Email, const std::string &Password) noexcept
      : _Mode(Mode), _Id(Id), _Email(Email), _Password(Password)
  {
  }

private:
  static Account _RecordToAccountObj(const std::string &Record, const char *const delim = "<||>") noexcept
  {
    std::vector<std::string> _Records(MG::utility::str_util::split_str(Record, delim, 3));
    return {en_Mode::UpdateMode, _Records[0], _Decrypt_(_Records[1], _Key_), _Decrypt_(_Records[2], _Key_)};
  }

  std::string _AccountObjToRecord(const Account &Acc, const char *const sep = "<||>") noexcept
  {
    std::string _Record(Acc._Id + sep);
    _Record += _Encrypt_(Acc._Email, _Key_) + sep;
    _Record += _Encrypt_(Acc._Password, _Key_);
    return _Record;
  }

  static std::vector<Account> _LoadAccountsFromFile() noexcept
  {
    std::vector<Account> _Accounts;
    std::ifstream _File(_Accounts_File);

    if (_File)
    {
      std::string _Line;
      while (std::getline(_File, _Line))
        _Accounts.push_back(_RecordToAccountObj(_Line));

      _File.close();
    }

    return _Accounts;
  }

  void _SaveAccountsToFile(const std::vector<Account> &Accounts) noexcept
  {
    std::ofstream _File(_Accounts_File);

    if (_File)
    {
      for (const Account &Acc : Accounts)
        if (!Acc._DeleteFlag)
          _File << _AccountObjToRecord(Acc) << std::endl;

      _File.close();
    }
  }

  void _AddRecordToFile(const std::string &Record) noexcept
  {
    std::fstream _File(_Accounts_File, std::ios::in | std::ios::app); // appending

    if (_File)
    {
      _File << Record << std::endl;
      _File.close();
    }
  }

  void _Update() noexcept
  {
    std::vector<Account> _Accounts = _LoadAccountsFromFile();

    for (Account &Acc : _Accounts)
    {
      if (Acc._Id == _Id)
      {
        Acc = *this;
        break;
      }
    }
    _SaveAccountsToFile(_Accounts);
  }

  void _AddNew() noexcept
  {
    _AddRecordToFile(_AccountObjToRecord(*this));
  }

public:
  bool is_empty() const noexcept
  {
    return _Id.empty();
  }

  static Account Find(const std::string &Id) noexcept
  {
    std::ifstream File(_Accounts_File);

    if (File.is_open())
    {
      std::string Line;
      Line.reserve(3);

      Account Acc;

      while (getline(File, Line))
      {
        Acc = _RecordToAccountObj(Line);

        if (Acc._Id == Id)
        {
          File.close();
          return Acc;
        }
      }
      File.close();
    }
    return {};
  }

  static bool is_exist(const std::string &Id) noexcept
  {
    Account Acc = Find(Id);
    return !(Acc.is_empty());
  }
  static bool is_exist(const std::string &Id, Account &Acc) noexcept
  {
    Acc = Find(Id);
    return !(Acc.is_empty());
  }

  enum class en_SaveResult
  {
    svFaildEmptyObject = 0,
    svSucceeded = 1,
    svFaildAccountNumberExists = 2
  };

  en_SaveResult Save() noexcept
  {
    switch (_Mode)
    {
    case en_Mode::EmptyMode:
      return en_SaveResult::svFaildEmptyObject;

    case en_Mode::UpdateMode:
      _Update();
      return en_SaveResult::svSucceeded;

    case en_Mode::AddNewMode:
      if (is_exist(_Id))
        return en_SaveResult::svFaildAccountNumberExists;
      _AddNew();
      _Mode = en_Mode::UpdateMode; // set _Mode to update_mode
      return en_SaveResult::svSucceeded;

    default:
      return en_SaveResult::svFaildEmptyObject;
    }
  }

  static std::vector<Account> LoadAccountsList() noexcept
  {
    return _LoadAccountsFromFile();
  }

  void clear()
  {
    _Id.clear();
    _Email.clear();
    _Password.clear();
  }

  void Delete() noexcept
  {
    std::vector<Account> _Accounts = _LoadAccountsFromFile();

    for (Account &Acc : _Accounts)
    {
      if (Acc._Id == _Id)
      {
        Acc._DeleteFlag = true;
        break;
      }
    }
    _SaveAccountsToFile(_Accounts);

    this->clear(); // make empty Object
  }

  // friends list
  friend class clsScreen;
  friend class clsAddNewAccountScreen;
  friend class clsAccountsListScreen;
  friend class clsDeleteAccountScreen;
  friend class clsFindAccountScreen;
  friend class clsUpdateAccountScreen;
};
