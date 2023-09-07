#pragma once

#include "Screen.h"
#include "../Headers/Account.h"

class clsUpdateAccountScreen : protected clsScreen
{
private:
	static void _ReadAccountInfo(Account &Acc)
	{
		Acc._Email = MG::utility::input_valid::ReadTxt("\n\t\t\t\t   Enter Email/Phone:  ");
		Acc._Password = MG::utility::input_valid::ReadTxt("\n\t\t\t\t   Enter Password:  ");
	}

public:
	static void ShowUpdateAccountInfoDisplay()
	{
		_DrawScreenHeader("Update Account Info");

		Account _Account;
		std::string Id = READ_TXT("\t\t\t\t   Enter Id:  ");

		if (!Account::is_exist(Id, _Account))
		{
			std::cout << "\n\t\t\t\t   Not Found :-(\n\n";
		}
		else
		{
			_PrintAccountCard(_Account);

			if (MG::utility::input_valid::Read_YesOrNo("\n\t\t\t\t   Are You Sure You Want To Update This Account? y/n? "))
			{
				std::cout << "\n\n\t\t\t\t   Updating Acocunt Info:";
				std::cout << "\n\t\t\t\t   ---------------------\n";

				_ReadAccountInfo(_Account);

				switch (_Account.Save())
				{
				case Account::en_SaveResult::svSucceeded:
					std::cout << "\n\t\t\t\t   Account Updated Successfully :-)\n";
					_PrintAccountCard(_Account);
					break;
				case Account::en_SaveResult::svFaildEmptyObject:
					std::cout << "\n\t\t\t\t   Error, Saving Data Faild Because It's Empty :-(\n";
					break;
				}
			}
		}
	}
};
