#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "MGLib.h"

using namespace std;
using namespace MGLib;


sDate IncreaseDateByOneDay(sDate Date)
{
	/*
		if (IsLastDayInMonth(Date))
		{
			Date.Day = 1;

			if (IsLastMonthInYear(Date.Month))
			{
				Date.Year++;
				Date.Month = 1;
			}
			else
				Date.Month++;
		}
		else
			Date.Day++;
	*/

	IsLastDayInMonth(Date) ? (IsLastMonthInYear(Date.Month) ? (Date.Day = 1, Date.Month = 1, Date.Year++) : (Date.Day = 1, Date.Month++)) : (Date.Day++);

	return Date;
}
sDate IncreaseDateByXDays(sDate Date, size_t Days)
{
	for (size_t i = 1; i <= Days; i++)
		Date = IncreaseDateByOneDay(Date);

	return Date;
}

sDate IncreaseDateByOneWeak(sDate Date)
{
	for (size_t i = 1; i <= 7; i++)
		Date = IncreaseDateByOneDay(Date);

	return Date;
}
sDate IncreaseDateByXWeaks(sDate Date, size_t Weaks)
{
	for (size_t i = 1; i <= Weaks; i++)
		Date = IncreaseDateByOneWeak(Date);

	return Date;
}

sDate IncreaseDateByOneMonth(sDate Date)
{
	(Date.Month == 12) ? Date.Month = 1, Date.Year++ : Date.Month++;

	unsigned short MaxDaysOfTheNewMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);

	if (MaxDaysOfTheNewMonth < Date.Day)
		Date.Day = MaxDaysOfTheNewMonth;

	return Date;
}
sDate IncreaseDateByXMonths(sDate Date, size_t Months)
{
	for (size_t i = 1; i <= Months; i++)
		Date = IncreaseDateByOneMonth(Date);

	return Date;
}

sDate IncreaseDateByOneYear(sDate Date)
{
	(Date.Month == 2 && Date.Day == 29) ? Date.Year++, Date.Day-- : Date.Year++;
	return Date;
}
sDate IncreaseDateByXYears(sDate Date, size_t Years)
{
	Date.Year += Years;

	if (Date.Month == 2 && Date.Day == 29)
		if (NumberOfDaysInAMonth(Date.Year, 2) == 28)
			Date.Day--;

	return Date;
}

sDate IncreaseDateByOneDecade(sDate Date)
{
	// 10 years
	Date = IncreaseDateByXYears(Date, 10);
	return Date;
}
sDate IncreaseDateByXDecades(sDate Date, size_t Decades)
{
	Date = IncreaseDateByXYears(Date, Decades * 10);
	return Date;
}

sDate IncreaseDateByOneCentury(sDate Date)
{
	// 100 years
	Date = IncreaseDateByXYears(Date, 100);
	return Date;
}

sDate IncreaseDateByOneMillennium(sDate Date)
{
	// 1000 years
	Date = IncreaseDateByXYears(Date, 1000);

	return Date;
}


int main(void)
{
	sDate Date;

	for (;;)
	{
		Date = ReadDate();

		printf("\n-> Original Date Is:  %2hu/%2hu/%llu\n\n", Date.Day, Date.Month, Date.Year);

		printf("- Date After Adding:\n");
		printf("--------------------\n\n");

		Date = IncreaseDateByOneDay(Date);
		printf("(1)- One Day Is:         %2hu/%2hu/%llu\n\n", Date.Day, Date.Month, Date.Year);

		Date = IncreaseDateByXDays(Date, 10);
		printf("(2)- 10 Days Is:         %2hu/%2hu/%llu\n\n", Date.Day, Date.Month, Date.Year);

		Date = IncreaseDateByOneWeak(Date);
		printf("(3)- One Weak Is:        %2hu/%2hu/%llu\n\n", Date.Day, Date.Month, Date.Year);

		Date = IncreaseDateByXWeaks(Date, 10);
		printf("(4)- 10 Weaks Is:        %2hu/%2hu/%llu\n\n", Date.Day, Date.Month, Date.Year);

		Date = IncreaseDateByOneMonth(Date);
		printf("(5)- One Month Is:       %2hu/%2hu/%llu\n\n", Date.Day, Date.Month, Date.Year);

		Date = IncreaseDateByXMonths(Date, 5);
		printf("(6)- 5 Months Is:       %2hu/%2hu/%llu\n\n", Date.Day, Date.Month, Date.Year);

		Date = IncreaseDateByOneYear(Date);
		printf("(7)- One Year Is:        %2hu/%2hu/%llu\n\n", Date.Day, Date.Month, Date.Year);

		Date = IncreaseDateByXYears(Date, 10);
		printf("(8)- 10 Years Is:        %2hu/%2hu/%llu\n\n", Date.Day, Date.Month, Date.Year);

		Date = IncreaseDateByOneDecade(Date);
		printf("(9)- One Decade Is:      %2hu/%2hu/%llu\n\n", Date.Day, Date.Month, Date.Year);

		Date = IncreaseDateByXDecades(Date, 10);
		printf("(10)- 10 Decades Is:     %2hu/%2hu/%llu\n\n", Date.Day, Date.Month, Date.Year);

		Date = IncreaseDateByOneCentury(Date);
		printf("(11)- One Century Is:    %2hu/%2hu/%llu\n\n", Date.Day, Date.Month, Date.Year);

		Date = IncreaseDateByOneMillennium(Date);
		printf("(12)- One Millennium Is: %2hu/%2hu/%llu\n\n", Date.Day, Date.Month, Date.Year);

		printf("\n\n-----------------------------------------------------------\n\n");
	}

	return 0;
}