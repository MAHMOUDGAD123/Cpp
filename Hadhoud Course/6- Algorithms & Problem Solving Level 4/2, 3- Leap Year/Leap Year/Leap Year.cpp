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
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "-> Invalid Number, Enter A Positive Integer Number|--> ";
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


int main(void)
{
	do
	{
		unsigned short Year = Read_Positive_Int_Number("\n\n-> Enter A Number: ");

		if (isLeapYear(Year))
			printf("\n-> [%hu] Is A Leap Year:\n\n", Year);
		else
			printf("\n-> [%hu] Is Not A Leap Year:\n\n", Year);

	} while (true);





	return 0;
}