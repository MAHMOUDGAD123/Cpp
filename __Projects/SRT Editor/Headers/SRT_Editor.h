#pragma once

#include "Date.h"
#include "MG_Util.h"
#include "SRT.h"
#include "Tools.h"

struct STR_EDITOR final
{
private:
	static void _PrintPathTag()
	{
		std::cout
				<< DEFAULT_FORMAT << "=========================================================================================\n"
				<< DEFAULT_FORMAT << "=> Path: \"" << SRT::__path << "\"\n"
				<< DEFAULT_FORMAT << "=> SRT File: \"" << SRT::__fileName << ".srt\"\n"
				<< DEFAULT_FORMAT << "=========================================================================================\n";
	}

	static void _DrawScreenHeader(const char *const Title)
	{
		CLEAR_SCREEN

		std::cout << DEFAULT_FORMAT << "_________________________________________________________________________________________\n\n"
							<< DEFAULT_FORMAT << "\t\t\t\t\t" << Title;

		std::cout << '\n'
							<< DEFAULT_FORMAT << "_________________________________________________________________________________________\n\n";

		MG::clsDate today = MG::clsDate::SystemDate();

		std::cout
				<< DEFAULT_FORMAT << "=> Time: "
				<< today.day_name() << " - "
				<< today.to_string() << " - "
				<< MG::clsDate::SystemClock();

		std::cout << '\n'
							<< DEFAULT_FORMAT << "_________________________________________________________________________________________\n\n";
	}

public:
	static void Run()
	{
		do
		{
			do
			{
				_DrawScreenHeader("SubRip Subtitle Editor");

				std::cout << "\n\n"
									<< DEFAULT_FORMAT
									<< "Ex: D:\\folder1\\folder2\n\n";

				SRT::__path = READ_TXT("Enter The Srt File Path => ");

			} while (SRT::__path[1] != ':');

			SRT::__path += '\\';

			std::cout << "\n\n";

			SRT::__fileName = READ_TXT("Enter The Srt File Name Without (.srt) => ");

			_DrawScreenHeader("\tSubRip Subtitle Editor");
			_PrintPathTag();

			std::cout << "\n\n";

			SRT::__prefix = READ_TXT("Enter The PreFix => ");

			std::cout << "\n\n";

			SRT::__postfix = READ_TXT("Enter The PostFix => ");

			std::cout << "\n\n";

			if (CONFIRM("Are You Sure That You Want To Perform This Process? y/n? "))
			{
				if (SRT::__update_srt())
					std::cout << "\n\n"
										<< DEFAULT_FORMAT
										<< "Done Successfully"
										<< std::endl;
				else
					std::cout << "\n\n"
										<< DEFAULT_FORMAT
										<< "Can't Open The File\n"
										<< DEFAULT_FORMAT
										<< "Make Sure The Path & File_Name are correct"
										<< std::endl;
			}
			std::cout << "\n\n";

		} while (CONFIRM("Enter [y] To Try Again Or [n] to Exit? "));
	}
};