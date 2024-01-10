#include <string>
#include <iostream>

using namespace std;

//**************************************************************************************
//******************************** Days ************************************************
//**************************************************************************************


enum en_WeekDays { Sat = 1, Sun = 2, Mon = 3, Tue = 4, Wed = 5, Thu = 6, Fri = 7 };
void ShowWeekDaysMenu() // Only show the days menu
{
	cout << "*************************************\n";
	cout << "*                                   *\n";
	cout << "*             WEEK DAYS             *\n";
	cout << "*                                   *\n";
	cout << "*************************************\n\n";

	cout << "1- Saturday\n";
	cout << "2- Sunday\n";
	cout << "3- Monday\n";
	cout << "4- Tuesday\n";
	cout << "5- Wednesday\n";
	cout << "6- Thursday\n";
	cout << "7- Friday\n\n\n";

	cout << "Please enter the day of the week : ";

}  
en_WeekDays ReadWeekDays() // prosedural from type enum
{
	en_WeekDays WeekDay;
	
XXX:

	string WD;
	cin >> WD;

	if (WD != "1" && WD != "2" && WD != "3" && WD != "4" && WD != "5" && WD != "6" && WD != "7")
	{
		cout << "We have Only 7 Days a weak bro enter again : ";
		goto XXX;
	}

	WeekDay = (en_WeekDays) stoi(WD);

	return WeekDay;

}
string GetWeekDayName(en_WeekDays WeekDay)
{
	switch (WeekDay)
	{
	case en_WeekDays::Sat:
		return "Today is : Saturday";
		break;

	case en_WeekDays::Sun:
		return "Today is : Sunday";
		break;

	case en_WeekDays::Mon:
		return "Today is : Monday";
		break;

	case en_WeekDays::Tue:
		return "Today is : Tuesday";
		break;

	case en_WeekDays::Wed:
		return "Today is : Wednesday";
		break;

	case en_WeekDays::Thu:
		return "Today is : Thursday";
		break;

	case en_WeekDays::Fri:
		return "Today is : Friday";
		break;

	}


}


//**************************************************************************************
//****************************** Months ************************************************
//**************************************************************************************

enum en_MonthsOfYear { 
	January = 1, 
	February = 2, 
	March = 3, 
	April = 4, 
	May = 5, 
	June = 6, 
	July = 7, 
	August = 8,
	September = 9, 
	October = 10, 
	November = 11, 
	December = 12 };

void ShowMonthsOfYear()
{
	cout << "*************************************\n";
	cout << "*                                   *\n";
	cout << "*           MONTHS OF YEAR          *\n";
	cout << "*                                   *\n";
	cout << "*************************************\n\n";

	cout << "1- January\n";
	cout << "2- February\n";
	cout << "3- March\n";
	cout << "4- April\n";
	cout << "5- May\n";
	cout << "6- June\n";
	cout << "7- July\n";
	cout << "8- August\n";
	cout << "9- September\n";
	cout << "10- October\n";
	cout << "11- November\n";
	cout << "12- December\n\n\n";

	cout << "Please enter the Month : ";



}

en_MonthsOfYear ReadMonth()
{
	en_MonthsOfYear Month;

YYY:


	string M;
	cin >> M;

	if (M != "1" && M != "2" && M != "3" && M != "4" && M != "5" && M != "6" && M != "7" 
		&& M != "8" && M != "9" && M != "10" && M != "11" && M != "12")
	{
		cout << "We have only 12 months a year my bro enter again : ";
		goto YYY;
	}

	Month = (en_MonthsOfYear)stoi(M);

	return Month;
}

string GetMonth(en_MonthsOfYear Month)
{
	switch(Month)
	{
	case en_MonthsOfYear::January:
		return "The Month is : January";
		cout << "\n" << endl;
		break;

	case en_MonthsOfYear::February:
		return "The Month is : February";
		cout << "\n" << endl;
		break;

	case en_MonthsOfYear::March:
		return "The Month is : March";
		cout << "\n" << endl;
		break;

	case en_MonthsOfYear::April:
		return "The Month is : April";
		cout << "\n" << endl;
		break;

	case en_MonthsOfYear::May:
		return "The Month is : May";
		cout << "\n" << endl;
		break;

	case en_MonthsOfYear::June:
		return "The Month is : June";
		cout << "\n" << endl;
		break;

	case en_MonthsOfYear::July:
		return "The Month is : July";
		cout << "\n" << endl;
		break;

	case en_MonthsOfYear::August:
		return "The Month is : August";
		cout << "\n" << endl;
		break;

	case en_MonthsOfYear::September:
		return "The Month is : September";
		cout << "\n" << endl;
		break;

	case en_MonthsOfYear::October:
		return "The Month is : October";
		cout << "\n" << endl;
		break;

	case en_MonthsOfYear::November:
		return "The Month is : November";
		cout << "\n" << endl;
		break;

	case en_MonthsOfYear::December:
		return "The Month is : Decembwer";
		cout << "\n" << endl;
		break;


	}


}






int main()
{

	ShowWeekDaysMenu();
	cout << "\n\n" << GetWeekDayName(ReadWeekDays()) << "\n\n" << endl;
	cout << "**********************************\n";
	cout << "**********************************\n";

	//**************************************************************


	ShowMonthsOfYear();
	cout << "\n\n" << GetMonth(ReadMonth()) << "\n\n" << endl;
	cout << "**********************************\n";
	cout << "**********************************\n";

	return 0;
}


