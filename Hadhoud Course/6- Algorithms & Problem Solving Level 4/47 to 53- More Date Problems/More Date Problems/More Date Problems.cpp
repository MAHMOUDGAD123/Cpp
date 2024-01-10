#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "MGLib.h"

using namespace std;
using namespace MGLib;



string GetDayFromDate(sDate Date)
{
	return DayShortName(DayOfWeekOrder(Date)) + ", " + to_string(Date.Day) + '/' + to_string(Date.Month) + '/' + to_string(Date.Year);
}

bool IsEndOfWeak(sDate Date)
{
	// Sat
	return DayOfWeekOrder(Date) == 6;
}

bool IsWeakEnd(sDate Date)
{
	// Fri & Sat
	unsigned short DayOrder = DayOfWeekOrder(Date);
	return (DayOrder == 5 || DayOrder == 6);
}

bool IsBusinessDay(sDate Date)
{
	return !IsWeakEnd(Date);
}

unsigned short DaysUntilTheEndOfWeak(sDate Date)
{
	return 6 - DayOfWeekOrder(Date);
}

unsigned short DaysUntilTheEndOfMonth(sDate Date)
{
	// (+1) to include the current day
	return (NumberOfDaysInAMonth(Date.Year, Date.Month) - Date.Day) + 1;
}

unsigned short DaysUnTilTheEndOfYear(sDate Date)
{
	// return the number of days left to finish the year from that (Date)
	// (+1) to include the current day
	return (NumberOfDaysInAYear(Date.Year) - DayOfYearOrder(Date)) + 1;
}



int main(void)
{
	sDate Date;

	for (;;)
	{
		Date = ReadDate();

		printf("\n-> Today Is: %s\n\n", GetDayFromDate(Date).c_str());


		if (IsEndOfWeak(Date))
			cout << "Yes, It's End Of Weak.\n\n";
		else
			cout << "No, It Isn't End Of Weak.\n\n";


		if (IsWeakEnd(Date))
			cout << "Yes, It's Weak End Day.\n\n";
		else
			cout << "No, It Isn't Weak End Day.\n\n";


		if (IsBusinessDay(Date))
			cout << "Yes, It's Business Day.\n\n";
		else
			cout << "No, It Isn't Business day.\n\n";


		printf("-> Days Until The End Of Weak  = %hu Day(s)\n", DaysUntilTheEndOfWeak(Date));
		printf("-> Days Until The End Of Month = %hu Day(s)\n", DaysUntilTheEndOfMonth(Date));
		printf("-> Days Until The End Of Year  = %hu Day(s)\n", DaysUnTilTheEndOfYear(Date));


		printf("\n\n-----------------------------------------------------------\n\n");
	}

	return 0;
}