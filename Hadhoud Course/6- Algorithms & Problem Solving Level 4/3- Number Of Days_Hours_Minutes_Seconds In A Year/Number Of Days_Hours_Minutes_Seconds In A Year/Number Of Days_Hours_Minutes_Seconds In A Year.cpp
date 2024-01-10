#include <iostream>
#include <string>
#include <vector>


using namespace std;


unsigned long long Read_Positive_Int_Number(const char* Message = "")
{
	unsigned long long Number = 0;

	cout << Message;
	cin >> Number;

	while (cin.fail() || !(Number >= 0))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "-> Invalid Number, Enter A Positive Integer Number|--> ";
		cin >> Number;
	}

	return Number;
}

bool isLeapYear(unsigned short year)
{
	// if (Year % 400 == 0) => true  ---  Year is a leap year
	// else if (Year % 4 == 0) => true  ---  Year is a leap year if (Year % 100 != 0) => true

	return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}


unsigned long NumberOfDaysInYear(unsigned short year)
{
	return isLeapYear(year) ? 366 : 365;
}
unsigned long NumberOfHoursInYear(unsigned short year)
{
	return NumberOfDaysInYear(year) * 24;
}
unsigned long NumberOfMinutesInYear(unsigned short year)
{
	return NumberOfHoursInYear(year) * 60;
}
unsigned long NumberOfSecondsInYear(unsigned short year)
{
	return NumberOfMinutesInYear(year) * 60;
}


void YearInDetails(unsigned short year)
{
	printf("\n-> Number Of Days    In Year [%hu] = {%lu}\n", year, NumberOfDaysInYear(year));
	printf("\n-> Number Of Hours   In Year [%hu] = {%lu}\n", year, NumberOfHoursInYear(year));
	printf("\n-> Number Of Minutes In Year [%hu] = {%lu}\n", year, NumberOfMinutesInYear(year));
	printf("\n-> Number Of Seconds In Year [%hu] = {%lu}\n", year, NumberOfSecondsInYear(year));
}


int main(void)
{
	for (;;)
		YearInDetails(Read_Positive_Int_Number("\n\n-> Enter A Year:  "));



	return 0;
}