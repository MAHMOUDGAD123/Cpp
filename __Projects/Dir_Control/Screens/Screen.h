#pragma once

#include "../Headers/Dir.h"
#include "../Headers/Date.h"
#include "../Headers/File.h"

#define CLEAR_SCREEN system("cls");
#define PAUSE system("pause>0")
#define DEFAULT_FORMAT std::setw(_width) << std::left << ""
#define READ_TXT MG::utility::input_valid::ReadTxt
#define CONFIRM MG::utility::input_valid::Read_YesOrNo

class clsScreen
{
protected:
	constexpr static uint8_t _width = 60;

	static short _ReadUserChoice(short from, short to, const char *const msg = "Choose A Number Between")
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

	static void _PrintPathTag()
	{
		std::cout
				<< DEFAULT_FORMAT << "====================================================================\n"
				<< DEFAULT_FORMAT << "=> Path: \"" << Dir::_Path << "\"\n"
				<< DEFAULT_FORMAT << "=> " <<  Dir::_Count << " File(s)\n"
				<< DEFAULT_FORMAT << "====================================================================\n";
	}

	static void _DrawScreenHeader(const char *const Title)
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

	static void _PrintFileInfo(const File &file)
	{
		std::cout << "\n\t\t\t\t   File Info:";
		std::cout << "\n\t\t\t\t   --------------------------------------------------------------------";
		std::cout << "\n\t\t\t\t   Name    : " << file._Name;
		std::cout << "\n\t\t\t\t   Type    : " << file._Type;
		std::cout << "\n\t\t\t\t   --------------------------------------------------------------------\n";
	}
};