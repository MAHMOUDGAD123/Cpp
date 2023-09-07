#pragma once

#include <iostream>
#include <iomanip>
#include "../Headers/Date.h"

#define CLEAR_SCREEN system("cls");
#define DEFAULT_FORMAT std::setw(_width) << std::left << ""
#define READ_TXT MG::utility::input_valid::ReadTxt
#define CONFIRM MG::utility::input_valid::Read_YesOrNo


class clsScreen
{
protected:
	constexpr static uint8_t _width = 35;

	static short _ReadUserChoice(short from, short to, const char* msg = "Choose A Number Between")
	{
		short num(0);
		std::cout << DEFAULT_FORMAT << msg << " [" << from << " -> " << to << "]? ";
		while (!(std::cin >> num) || num < from || num > to)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << DEFAULT_FORMAT << msg << " [" << from << " -> " << to << "]? ";
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return num;
	}

	static void _DrawScreenHeader(const char* const Title)
	{
		CLEAR_SCREEN

		std::cout
			<< DEFAULT_FORMAT << "____________________________________________________________________\n\n"
			<< DEFAULT_FORMAT << "\t\t\t     " << Title;

		std::cout << '\n'
			<< DEFAULT_FORMAT << "____________________________________________________________________\n\n";

		MG::clsDate today = MG::clsDate::SystemDate();

		std::cout
			<< DEFAULT_FORMAT << "=> Time: "
			<< today.day_name() << " - "
			<< today.to_string() << " - "
			<< MG::clsDate::SystemClock();

		std::cout << '\n'
			<< DEFAULT_FORMAT << "____________________________________________________________________\n\n";
	}

	static void _PrintAccountCard(const Account &Acc)
  {
    std::cout << "\n\t\t\t\t   Account Info:";
    std::cout << "\n\t\t\t\t   --------------------------------------------------------------------";
    std::cout << "\n\t\t\t\t   Id          : " << Acc._Id;
    std::cout << "\n\t\t\t\t   Email/Phone : " << Acc._Email;
    std::cout << "\n\t\t\t\t   Password    : " << Acc._Password;
    std::cout << "\n\t\t\t\t   --------------------------------------------------------------------\n";
  }

};