#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cstdarg>
#include "MGLib.h"

using namespace std;
using namespace MGLib;


string Replace_Word(string Str, const string& old_txt, const string& new_txt)
{
	size_t found;
	unsigned short old_txt_len = old_txt.length();

	while ((found = Str.find(old_txt)) != string::npos)
		Str = Str.replace(found, old_txt_len, new_txt);

	return Str;
}

string _FormatDate(sDate Date, string DateFormat = "%d/%m/%y")
{
	string FormattedDateString = "";
	FormattedDateString = Replace_Word(DateFormat, "%d", to_string(Date.Day));
	FormattedDateString = Replace_Word(FormattedDateString, "%m", to_string(Date.Month));
	FormattedDateString = Replace_Word(FormattedDateString, "%y", to_string(Date.Year));
	return FormattedDateString;
}



string FormatDate(const sDate* const Date, const char* format = "%d/%m/%y")
{
	// %d -> day, %m -> month, %y -> year 
	string frm = format;
	frm.replace(frm.find("%d"), 2, to_string(Date->Day));   // replace day
	frm.replace(frm.find("%m"), 2, to_string(Date->Month)); // replace month
	frm.replace(frm.find("%y"), 2, to_string(Date->Year));  // replace year
	return frm;
}


string frmtDate(const char* format, ...)
{
	string frmdate;
	va_list args; // argument list variable
	va_start(args, format); // initialize argument list variable (args)

	// any string or array of character have a NULL character ('\0') at the end of it
	// if (*format == '\0') this mean that we reach the end
	while (*format != '\0') {
		if (*format == '%') {
			format++; // make format pointer points to next character of "format"

			// get & convert the value of the next argument to string & push it to "frmdate"
			// %d -> day, %m -> month, %y -> year, %% -> %
			if (*format == 'd') frmdate += to_string(va_arg(args, int));
			else if (*format == 'm') frmdate += to_string(va_arg(args, int));
			else if (*format == 'y') frmdate += to_string(va_arg(args, int));
			else if (*format == '%') frmdate += *format;
		}
		else frmdate += *format;
		format++; // make format pointer points to next character of "format"
	}
	va_end(args); // End using argument list variable (args)
	return frmdate;
}


int main(void)
{
	sDate Date;

	for (;;)
	{
		Date = StringToDate(ReadStringDate("Please, Enter Date (dd/mm/yyyy)?  "));

		cout << FormatDate(&Date) << endl;

		// format using frmDate() function
		cout << frmtDate("\n- Today is: %d-%m-%y so, 100%% Tomorrow Is: %d-%m-%y", Date.Day, Date.Month, Date.Year, Date.Day + 1, Date.Month, Date.Year);

		// format using C++ printf() function
		printf("\n- Today is: %hu-%hu-%llu so, 100%% Tomorrow Is: %hu-%hu-%llu", Date.Day, Date.Month, Date.Year, Date.Day + 1, Date.Month, Date.Year);

		printf("\n\n-----------------------------------------------------------\n\n");
	}

	return 0;
}