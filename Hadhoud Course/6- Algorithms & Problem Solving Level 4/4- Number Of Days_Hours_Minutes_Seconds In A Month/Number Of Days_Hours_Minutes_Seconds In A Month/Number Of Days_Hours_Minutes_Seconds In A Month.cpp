#include <iostream>
#include <string>
#include <vector>


using namespace std;


unsigned short ReadYear(const char* Message = "")
{
	unsigned short Year = 0;

	cout << Message;
	cin >> Year;

	while (cin.fail() || !(Year > 0))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "-> Invalid Year, Enter A Valid Year:  ";
		cin >> Year;
	}

	return Year;
}

unsigned short ReadMonth(unsigned short from, unsigned short to, const char* Message = "")
{
	unsigned short Month = 0;

	cout << Message;
	cin >> Month;

	while (cin.fail() || !(Month >= from && Month <= to))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "-> Invalid Month, Range [" << from << " to " << to << "]:  ";
		cin >> Month;
	}

	return Month;
}


bool isLeapYear(unsigned short year)
{
	// if (Year % 400 == 0) => true  ---  Year is a leap year
	// else if (Year % 4 == 0) => true  ---  Year is a leap year if (Year % 100 != 0) => true

	return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}


//------------------------------- not optimized ----------------------------------------
unsigned short _NumberOfDaysInMonth(unsigned short year, unsigned short month)
{
	const unsigned short MonthsOfYear[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	const unsigned short MonthsOfLeapYear[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };

	return isLeapYear(year) ? MonthsOfLeapYear[month - 1] : MonthsOfYear[month - 1];
}
unsigned short __NumberOfDaysInMonth(unsigned short year, unsigned short month)
{
	// month validation

	const unsigned short MonthsOfYear[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return !(month < 1 || month > 12) ? isLeapYear(year) && (month == 2) ? MonthsOfYear[month - 1] + 1 : MonthsOfYear[month - 1] : 0;
}
//--------------------------------------------------------------------------------------


// Optimized 
unsigned short NumberOfDaysInMonth(unsigned short year, unsigned short month)
{
	const unsigned short MonthsOfYear[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return isLeapYear(year) && (month == 2) ? 29 : MonthsOfYear[month - 1];
}
unsigned short NumberOfHoursInMonth(unsigned short year, unsigned short month)
{
	return NumberOfDaysInMonth(year, month) * 24;
}
unsigned short NumberOfMinutesInMonth(unsigned short year, unsigned short month)
{
	return NumberOfHoursInMonth(year, month) * 60;
}
unsigned long NumberOfSecondsInMonth(unsigned short year, unsigned short month)
{
	return NumberOfMinutesInMonth(year, month) * 60;
}

void MonthInDetails(unsigned short year, unsigned short month)
{
	const string Months[12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };

	cout << "\n-----------------------------------------------------------\n";
	cout << "\n- Number Of Days    In Month [" << Months[month - 1] << "] = " << NumberOfDaysInMonth(year, month) << endl;
	cout << "\n- Number Of Hours   In Month [" << Months[month - 1] << "] = " << NumberOfHoursInMonth(year, month) << endl;
	cout << "\n- Number Of Minutes In Month [" << Months[month - 1] << "] = " << NumberOfMinutesInMonth(year, month) << endl;
	cout << "\n- Number Of Seconds In Month [" << Months[month - 1] << "] = " << NumberOfSecondsInMonth(year, month) << endl;
	cout << "\n-----------------------------------------------------------\n";
}


int main(void)
{
	unsigned short Year = 0, Month = 0;

	for (;;)
	{
		Year = ReadYear("\n\n-> Enter A Year:  ");
		Month = ReadMonth(1, 12, "\n-> Enter A Month [1 to 12]:  ");

		MonthInDetails(Year, Month);
	}

	return 0;
}