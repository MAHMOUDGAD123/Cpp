#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


unsigned short ReadNumberInRange(unsigned short from, unsigned short to, const char* Message = "")
{
	unsigned short Number = 0;

	cout << Message;
	cin >> Number;

	while (cin.fail() || !(Number >= from && Number <= to))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "-> Invalid Number, Range [" << from << " to " << to << "]:  ";
		cin >> Number;
	}

	return Number;
}

unsigned short ReadNumber(const char* Message = "")
{
	unsigned short Number = 0;

	cout << Message;
	cin >> Number;

	while (cin.fail() || !(Number > 0))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "-> Invalid Number, Enter A Positive Number:  ";
		cin >> Number;
	}

	return Number;
}

bool isLeapYear(unsigned short Year)
{
	// if (Year % 400 == 0) => true  ---  Year is a leap year
	// else if (Year % 4 == 0) => true  ---  Year is a leap year if (Year % 100 != 0) => true

	return ((Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0));
}

unsigned short NumberOfDaysInMonth(unsigned short year, unsigned short month)
{
	unsigned short NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return isLeapYear(year) && (month == 2) ? 29 : NumberOfDays[month - 1];
}

short DayOfWeekOrder(unsigned short day, unsigned short month, unsigned short year)
{
	unsigned short a = (14 - month) / 12;
	unsigned short y = year - a;
	unsigned short m = month + 12 * a - 2;

	return (day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
}

string DayName(unsigned short DayOrder)
{
	const string DaysOfWeek[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

	return DaysOfWeek[DayOrder];
}

string MonthName(unsigned short MonthNumber)
{
	const string Months[13] = { "","Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

	return Months[MonthNumber];
}

void PrintMonthCalendar(unsigned short year, unsigned short month)
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

void PrintYearCalendar(unsigned short year)
{
	printf("\n   _______________________________________\n\n");

	printf("             Calendar  -  %4hu", year);

	printf("\n   _______________________________________\n");

	for (unsigned short month = 1; month <= 12; month++)
		PrintMonthCalendar(year, month);

	return;
}

unsigned short DateToDayOrder(unsigned short year, unsigned short month, unsigned short day)
{
	unsigned short TotalDays = 0;

	for (unsigned short MonthOrder = 1; MonthOrder <= month - 1; MonthOrder++)
		TotalDays += NumberOfDaysInMonth(year, MonthOrder);

	return TotalDays + day;
}


struct sDate
{
	unsigned short Day = 0, Month = 0, Year = 0;
};

sDate DayOrderToDate(unsigned short year, unsigned short DayOrder)
{
	sDate Date;

	Date.Year = year;
	Date.Month = 1;
	unsigned short RemainingDay = DayOrder;
	unsigned short MonthDays = 0;

	while (true)
	{
		MonthDays = NumberOfDaysInMonth(year, Date.Month);

		if (RemainingDay > MonthDays)
		{
			RemainingDay -= MonthDays;
			Date.Month++;
		}
		else
		{
			Date.Day = RemainingDay;
			break;
		}
	}

	return Date;
}



int main(void)
{
	unsigned short year, month, day, DayOrder;
	sDate Date;

	for (;;)
	{
		year = ReadNumber("-> Enter A Year:  ");
		month = ReadNumberInRange(1, 12, "-> Enter A Month:  ");
		day = ReadNumberInRange(1, NumberOfDaysInMonth(year, month), "-> Enter A Day:  ");

		DayOrder = DateToDayOrder(year, month, day);

		printf("\n- Total Days From The Beginning Of The Year = %hu\n\n", DayOrder);

		Date = DayOrderToDate(year, DayOrder);

		printf("-> Date For {%hu} Is:  %hu/%hu/%hu", DayOrder, Date.Day, Date.Month, Date.Year);


		printf("\n\n-----------------------------------------------------------\n\n");
	}

	return 0;
}