#include <iostream>
#include <string>
#include <vector>


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


short DayOfWeekOrder(short day, short month, int year)
{
	unsigned short a = (14 - month) / 12;
	unsigned short y = year - a;
	unsigned short m = month + 12 * a - 2;

	return (day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
}

string DayName(short DayOrder)
{
	const string DaysOfWeek[7] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };

	return DaysOfWeek[DayOrder];
}

void DayOfBirth(unsigned short day, unsigned short month, unsigned short year)
{
	unsigned short DayOrder = DayOfWeekOrder(day, month, year);

	cout << "\n-------------------------\n";
	printf("- Data: %hu/%hu/%hu\n", day, month, year);
	printf("- Day Order: %hu\n", DayOrder);
	cout << "- Day Name: " << DayName(DayOrder);
	cout << "\n-------------------------\n";
}



int main(void)
{
	unsigned short Day = 0, Month = 0, Year = 0;

	for (;;)
	{
		Day = ReadNumberInRange(1, 31, "-> Enter A Day [1 to 31]:  ");
		Month = ReadNumberInRange(1, 12, "-> Enter A Month [1 to 12]:  ");
		Year = ReadNumber("-> Enter A Year:  ");

		DayOfBirth(Day, Month, Year);
	}



	return 0;
}