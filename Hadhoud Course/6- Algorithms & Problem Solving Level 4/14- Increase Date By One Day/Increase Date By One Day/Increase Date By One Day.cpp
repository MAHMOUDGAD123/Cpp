#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

size_t ReadNumberInRange(size_t from, size_t to = -1, const char* Message = "")
{
	size_t Number = 0;

	cout << Message;
	cin >> Number;

	while (cin.fail() || !(Number >= from && Number <= to))
	{
		cin.clear();
		cin.ignore(10000000, '\n');

		cout << "-> Invalid Number, Range [" << from << " to " << to << "]:  ";
		cin >> Number;
	}

	return Number;
}

size_t ReadNumber(const char* Message = "")
{
	size_t Number = 0;

	cout << Message;
	cin >> Number;

	while (cin.fail() || !(Number > 0))
	{
		cin.clear();
		cin.ignore(100000000, '\n');

		cout << "-> Invalid Number, Enter A Positive Number:  ";
		cin >> Number;
	}

	return Number;
}

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

short DayOfWeekOrder(unsigned short day, unsigned short month, size_t year)
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

struct sDate
{
	unsigned short Day = 0, Month = 0;
	size_t Year = 0;
};

unsigned short DateToDayOrderInYear(sDate Date)
{
	unsigned short TotalDays = 0;

	for (unsigned short MonthOrder = 1; MonthOrder <= Date.Month - 1; MonthOrder++)
		TotalDays += NumberOfDaysInAMonth(Date.Year, MonthOrder);

	return TotalDays + Date.Day;
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
	size_t RemainingDays = DaysToAdd + DateToDayOrderInYear(Date);

	Date.Month = 1; // Initialize the month

	// Years loop - This loop make the process faster
	while (true)
	{
		if (RemainingDays >= (YearDays = NumberOfDaysInAYear(Date.Year)))
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

sDate ReadDate()
{
	sDate Date;

	Date.Year = ReadNumber("-> Enter A Year:  ");
	Date.Month = ReadNumberInRange(1, 12, "-> Enter A Month:  ");
	Date.Day = ReadNumberInRange(1, NumberOfDaysInAMonth(Date.Year, Date.Month), "-> Enter A Day:  ");

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


int main(void)
{
	sDate Date;

	for (;;)
	{
		Date = ReadDate();

		printf("\n-> Date Before Increament Is:  %2hu/%2hu/%llu\n", Date.Day, Date.Month, Date.Year);

		Date = IncreaseDateByOneDay(Date);

		printf("\n-> Date After Adding One Day Is :  %2hu/%2hu/%llu\n", Date.Day, Date.Month, Date.Year);

		printf("\n\n-----------------------------------------------------------\n\n");
	}

	return 0;
}