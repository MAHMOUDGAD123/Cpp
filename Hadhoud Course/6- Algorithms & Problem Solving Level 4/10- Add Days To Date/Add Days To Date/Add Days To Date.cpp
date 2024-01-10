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

unsigned short NumberOfDaysInMonth(size_t year, unsigned short month)
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
	unsigned short NumberOfDays = NumberOfDaysInMonth(year, month);
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

unsigned short DateToDayOrderInYear(size_t year, unsigned short month, unsigned short day)
{
	unsigned short TotalDays = 0;

	for (unsigned short MonthOrder = 1; MonthOrder <= month - 1; MonthOrder++)
		TotalDays += NumberOfDaysInMonth(year, MonthOrder);

	return TotalDays + day;
}

struct sDate
{
	unsigned short Day = 0, Month = 0;
	size_t Year = 0;
};

sDate DayOrderInYearToDate(size_t year, unsigned short DayOrder)
{
	sDate Date;

	Date.Year = year;
	Date.Month = 1;
	unsigned short RemainingDays = DayOrder;
	unsigned short MonthDays = 0;

	while (true)
	{
		MonthDays = NumberOfDaysInMonth(year, Date.Month);

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
	size_t RemainingDays = DaysToAdd + DateToDayOrderInYear(Date.Year, Date.Month, Date.Day);

	Date.Month = 1; // Initialize the month

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
		if (RemainingDays > (MonthDays = NumberOfDaysInMonth(Date.Year, Date.Month)))
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
	Date.Day = ReadNumberInRange(1, NumberOfDaysInMonth(Date.Year, Date.Month), "-> Enter A Day:  ");

	return Date;
}


int main(void)
{
	size_t DaysToAdd;

	sDate Date;

	for (;;)
	{
		Date = ReadDate();
		DaysToAdd = ReadNumber("-> Enter How Much Days Do You Want To Add:  ");

		printf("\n-> Old Date Before Adding Days {%llu} Is:  %2hu/%2hu/%llu", DaysToAdd, Date.Day, Date.Month, Date.Year);

		Date = DateAddDays(Date, DaysToAdd);

		printf("\n-> New Date After Adding Days  {%llu} Is:  %2hu/%2hu/%llu", DaysToAdd, Date.Day, Date.Month, Date.Year);

		printf("\n\n-----------------------------------------------------------\n\n");
	}

	return 0;
}