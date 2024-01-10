#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "MGLib.h"

using namespace std;
using namespace MGLib;


//######################## Decrease Date ########################

sDate DecreaseDateByOneDay(sDate Date)
{
	//if (Date.Day == 1)
	//{
	//	if (Date.Month == 1)
	//	{
	//		Date.Day = 31;
	//		Date.Month = 12;
	//		Date.Year--;
	//	}
	//	else
	//	{
	//		Date.Day = NumberOfDaysInAMonth(Date.Year, --Date.Month);
	//	}
	//}
	//else
	//{
	//	Date.Day--;
	//}

	(Date.Day == 1) ? ((Date.Month == 1) ? Date.Day = 31, Date.Month = 12, Date.Year-- : Date.Day = NumberOfDaysInAMonth(Date.Year, --Date.Month)) : Date.Day--;

	return Date;
}
sDate DecreaseDateByXDays(sDate Date, size_t Days)
{
	for (size_t i = 1; i <= Days; i++)
		Date = DecreaseDateByOneDay(Date);

	return Date;
}

sDate DecreaseDateByOneWeak(sDate Date)
{
	for (size_t i = 1; i <= 7; i++)
		Date = DecreaseDateByOneDay(Date);

	return Date;
}
sDate DecreaseDateByXWeaks(sDate Date, size_t Weaks)
{
	for (size_t i = 1; i <= Weaks; i++)
		Date = DecreaseDateByOneWeak(Date);

	return Date;
}

sDate DecreaseDateByOneMonth(sDate Date)
{
	(Date.Month == 1) ? Date.Month = 12, Date.Year-- : Date.Month--;

	unsigned short MaxDaysOfNewMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);

	if (MaxDaysOfNewMonth < Date.Day)
		Date.Day = MaxDaysOfNewMonth;

	return Date;
}
sDate DecreaseDateByXMonths(sDate Date, size_t Months)
{
	for (size_t i = 1; i <= Months; i++)
		Date = DecreaseDateByOneMonth(Date);

	return Date;
}

sDate DecreaseDateByOneYear(sDate Date)
{
	(Date.Month == 2 && Date.Day == 29) ? Date.Year--, Date.Day-- : Date.Year--;
	return Date;
}
sDate DecreaseDateByXYears(sDate Date, size_t Years)
{
	Date.Year -= Years;

	if (Date.Month == 2 && Date.Day == 29)
		if (NumberOfDaysInAMonth(Date.Year, 2) == 28)
			Date.Day--;

	return Date;
}

sDate DecreaseDateByOneDecade(sDate Date)
{
	Date = DecreaseDateByXYears(Date, 10);
	return Date;
}
sDate DecreaseDateByXDecades(sDate Date, size_t Decades)
{
	Date = DecreaseDateByXYears(Date, Decades * 10);
	return Date;
}

sDate DecreaseDateByOneCentury(sDate Date)
{
	Date = DecreaseDateByXYears(Date, 100);
	return Date;
}

sDate DecreaseDateByOneMillennium(sDate Date)
{
	Date = DecreaseDateByXYears(Date, 1000);
	return Date;
}

//###############################################################


int main(void)
{
	sDate Date;

	for (;;)
	{
		Date = ReadDate();

		printf("\n-> Original Date Is:   %2hu/%2hu/%llu\n\n", Date.Day, Date.Month, Date.Year);

		printf("- Date After Subtracting:\n");
		printf("-------------------------\n\n");


		Date = DecreaseDateByOneDay(Date);
		printf("(1)- One Day Is:         %2hu/%2hu/%llu\n\n", Date.Day, Date.Month, Date.Year);

		Date = DecreaseDateByXDays(Date, 10);
		printf("(2)- 10 Days Is:         %2hu/%2hu/%llu\n\n", Date.Day, Date.Month, Date.Year);

		Date = DecreaseDateByOneWeak(Date);
		printf("(3)- One Weak Is:        %2hu/%2hu/%llu\n\n", Date.Day, Date.Month, Date.Year);

		Date = DecreaseDateByXWeaks(Date, 10);
		printf("(4)- 10 Weaks Is:        %2hu/%2hu/%llu\n\n", Date.Day, Date.Month, Date.Year);

		Date = DecreaseDateByOneMonth(Date);
		printf("(5)- One Month Is:       %2hu/%2hu/%llu\n\n", Date.Day, Date.Month, Date.Year);

		Date = DecreaseDateByXMonths(Date, 5);
		printf("(6)- 5 Months Is:        %2hu/%2hu/%llu\n\n", Date.Day, Date.Month, Date.Year);

		Date = DecreaseDateByOneYear(Date);
		printf("(7)- One Year Is:        %2hu/%2hu/%llu\n\n", Date.Day, Date.Month, Date.Year);

		Date = DecreaseDateByXYears(Date, 10);
		printf("(8)- 10 Years Is:        %2hu/%2hu/%llu\n\n", Date.Day, Date.Month, Date.Year);

		Date = DecreaseDateByOneDecade(Date);
		printf("(9)- One Decade Is:      %2hu/%2hu/%llu\n\n", Date.Day, Date.Month, Date.Year);

		Date = DecreaseDateByXDecades(Date, 10);
		printf("(10)- 10 Decades Is:     %2hu/%2hu/%llu\n\n", Date.Day, Date.Month, Date.Year);

		Date = DecreaseDateByOneCentury(Date);
		printf("(11)- One Century Is:    %2hu/%2hu/%llu\n\n", Date.Day, Date.Month, Date.Year);

		Date = DecreaseDateByOneMillennium(Date);
		printf("(12)- One Millennium Is: %2hu/%2hu/%llu\n\n", Date.Day, Date.Month, Date.Year);



		printf("\n\n-----------------------------------------------------------\n\n");
	}

	return 0;
}