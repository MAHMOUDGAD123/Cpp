#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

#include <iostream>
#include <string>
#include <ctime>
#include <time.h>

using namespace std;

struct sDate
{
	unsigned short Day = 0, Month = 0;
	size_t Year = 0;
};


bool isLeapYear(size_t Year)
{
	// if (Year % 400 == 0) => true  ---  Year is a leap year
	// else if (Year % 4 == 0) => true  ---  Year is a leap year if (Year % 100 != 0) => true

	return ((Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0));
}

unsigned short NumberOfDaysInAMonth(size_t year, unsigned short month)
{
	unsigned short NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return isLeapYear(year) && (month == 2) ? 29 : NumberOfDays[month - 1];
}

unsigned short YearDayOrder(sDate Date)
{
	unsigned short Days = 0;

	for (unsigned short month = 1; month < Date.Month; month++)
		Days += NumberOfDaysInAMonth(Date.Year, month);

	return Days + Date.Day;
}

unsigned short DayOfWeekOrder(unsigned short day, unsigned short month, size_t year)
{
	unsigned short a = (14 - month) / 12;
	size_t y = year - a;
	unsigned short m = month + 12 * a - 2;

	return (day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
}

string DayName(unsigned short DayOrder)
{
	const string DaysOfWeek[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

	return DaysOfWeek[DayOrder];
}

string MonthName(unsigned short MonthNumber)
{
	const string Months[13] = { "", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

	return Months[MonthNumber];
}

void PrintMonthCalendar(size_t year, unsigned short month)
{
	unsigned short NumberOfDays = NumberOfDaysInAMonth(year, month);
	unsigned short StartDayOrder = DayOfWeekOrder(1, month, year) + 1; // the order of the first day of the month (0 -> 6)

	printf("\n\n");
	printf("   __________________%s__________________\n\n", MonthName(month).c_str());

	printf("   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n\n");

	// Print spaces if the first day isn't 'Sun'
	unsigned short Count7Days; // This will count 7 days to print '\n'
	for (Count7Days = 1; Count7Days < StartDayOrder; Count7Days++)
		printf("      ");

	// Print the days
	for (unsigned short day = 1; day <= NumberOfDays; day++, Count7Days++)
	{
		printf("%6hu", day);

		if (Count7Days == 7)
		{
			printf("\n\n");
			Count7Days = 0;
		}
	}
	printf("\n   _______________________________________\n");

	return;
}

void PrintYearCalendar(size_t year)
{
	printf("\n   _______________________________________\n\n");

	printf("             Calendar  -  %4llu", year);

	printf("\n   _______________________________________\n");

	for (unsigned short month = 1; month <= 12; month++)
		PrintMonthCalendar(year, month);

	return;
}

sDate DayOrderInYearToDate(size_t year, unsigned short DayOrder)
{
	sDate Date;

	Date.Year = year;
	Date.Month = 1;
	unsigned short RemainingDays = DayOrder;
	unsigned short MonthDays = 0;

	while (true)
	{
		MonthDays = NumberOfDaysInAMonth(year, Date.Month);

		if (RemainingDays > MonthDays)
		{
			RemainingDays -= MonthDays;
			Date.Month++;
		}
		else
		{
			Date.Day = RemainingDays;
			break;
		}
	}

	return Date;
}

unsigned short NumberOfDaysInAYear(size_t year)
{
	return isLeapYear(year) ? 366 : 365;
}

sDate DateAddDays(sDate Date, size_t DaysToAdd)
{
	unsigned short YearDays = 0, MonthDays = 0;

	// Start from the beginning of the year
	size_t RemainingDays = DaysToAdd + YearDayOrder(Date);

	Date.Month = 1; // Initialize the Month

	// Years loop - This loop make the process faster
	while (true)
	{
		if (RemainingDays > (YearDays = NumberOfDaysInAYear(Date.Year)))
		{
			RemainingDays -= YearDays;
			Date.Year++;
		}
		else
			break;
	}

	// Months & Days loop
	while (true)
	{
		if (RemainingDays > (MonthDays = NumberOfDaysInAMonth(Date.Year, Date.Month)))
		{
			RemainingDays -= MonthDays;

			if (Date.Month == 12)
			{
				Date.Year++;
				Date.Month = 1;
			}
			else
			{
				Date.Month++;
			}
		}
		else
		{
			Date.Day = RemainingDays;
			break;
		}
	}

	return Date;
}

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
	// return true if (Date1 < Date2)

	/*
		if (Date1.Year < Date2.Year)
			return true;
		else if (Date1.Year == Date2.Year)
		{
			if (Date1.Month < Date2.Month)
				return true;
			else if (Date1.Month == Date2.Month)
			{
				if (Date1.Day < Date2.Day)
					return true;
			}
			else
				return false; // if (Date1.Month > Date2.Month)
		}
		return false; // if (Date1.Year > Date2.Year)
	*/

	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? ((Date1.Month < Date2.Month) ? true : ((Date1.Month == Date2.Month) ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualToDate2(sDate Date1, sDate Date2)
{
	//return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
	return (Date1.Year == Date2.Year) && (Date1.Month == Date2.Month) && (Date1.Day == Date2.Day);
}

bool IsLastDayInMonth(sDate Date)
{
	return (Date.Day == NumberOfDaysInAMonth(Date.Year, Date.Month));
}

bool IsLastMonthInYear(unsigned short month)
{
	return (month == 12);
}

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

unsigned short NumberOfDaysTillTheEndOfTheYear(sDate Date)
{
	// return the number of days left to finish the year from that (Date)
	return NumberOfDaysInAYear(Date.Year) - YearDayOrder(Date);
}

size_t ReadNumber(const char* Message = "")
{
	size_t Number = 0; // positive integer number

	cout << Message;
	cin >> Number;

	while (cin.fail() || Number <= 0)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << Message;
		cin >> Number;
	}
	return Number;
}

size_t ReadNumberInRange(size_t from, size_t to, const char* Message = "")
{
	size_t Number = 0; // positive integer number

	cout << Message;
	cin >> Number;

	while (cin.fail() || !(Number >= from && Number <= to))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << Message;
		cin >> Number;
	}
	return Number;
}

sDate ReadDate()
{
	sDate Date;

	Date.Year = ReadNumber("-> Enter A Year:  ");
	Date.Month = (unsigned short)ReadNumberInRange(1, 12, "-> Enter A Month:  ");
	Date.Day = (unsigned short)ReadNumberInRange(1, NumberOfDaysInAMonth(Date.Year, Date.Month), "-> Enter A Day:  ");

	return Date;
}

void Swap2Dates(sDate* Date1, sDate* Date2)
{
	sDate temp_Date;

	temp_Date = *Date1;
	*Date1 = *Date2;
	*Date2 = temp_Date;
}

size_t DiffInDays(sDate StartDate, sDate EndDate, bool includeEndDay = false)
{
	if (!IsDate1BeforeDate2(StartDate, EndDate))
		Swap2Dates(&StartDate, &EndDate);

	size_t DiffDays = 0, CurrentYear = StartDate.Year;

	unsigned short StartDate_DayOrder = YearDayOrder(StartDate);
	unsigned short EndDate_DayOrder = YearDayOrder(EndDate);

	while (CurrentYear < EndDate.Year)
		DiffDays += NumberOfDaysInAYear(CurrentYear++);
	
	DiffDays += (size_t)(EndDate_DayOrder - StartDate_DayOrder);

	return includeEndDay ? ++DiffDays : DiffDays;
}

sDate GetSystemDate()
{
	sDate DateNow;
	time_t timenow = time(NULL);
	tm* LocalTime = localtime(&timenow);

	DateNow.Year = (size_t)LocalTime->tm_year + 1900;
	DateNow.Month = LocalTime->tm_mon + 1;
	DateNow.Day = LocalTime->tm_mday;

	return DateNow;
}

size_t AgeInDays(sDate DateOfBirth)
{
	return DiffInDays(DateOfBirth, GetSystemDate());
}



int main()
{
	sDate DateOfBirth;

	while (true)
	{
		printf("# Please, Enter Your Age/\n\n");

		DateOfBirth = ReadDate();

		printf("\n\n- Your Date Of Birth Is:  %hu/%hu/%llu\n\n", DateOfBirth.Day, DateOfBirth.Month, DateOfBirth.Year);

		printf("- Your Age In Days    = %llu\n\n", AgeInDays(DateOfBirth)); // days
		printf("- Your Age In Hours   = %llu\n\n", AgeInDays(DateOfBirth) * 24); // hours 
		printf("- Your Age In Minutes = %llu\n\n", AgeInDays(DateOfBirth) * 24 * 60); // minutes
		printf("- Your Age In Seconds = %llu\n\n", AgeInDays(DateOfBirth) * 24 * 60 * 60); // seconds

		printf("---------------------------------------------------\n\n");
	}


	return 0;
}