#include <iostream>
#include <string>

using namespace std;

//***************************************************************************************************
//************************************ Global Functions *********************************************
//***************************************************************************************************

bool CheckNumber_InRange(string N, int from, int to)
{
	if (stoi(N) >= from && stoi(N) <= to)
		return true;
	else
		return false;
}

bool Check_PositiveOrNot(string N)
{
	if (stoi(N) > 0)
		return true;
	else
		return false;
}

bool IsItDigitOrNot(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '.' || c == '-')
		return true;
	else
		return false;
}

bool Integer_Only(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '-')
		return true;
	else
		return false;
}

bool Check_Number(string N)
{
	for (int i = 0; i < N.length(); i++)
	{
		if (IsItDigitOrNot(N[i]) == false)
			return false;
	}

	return true;
}

bool Check_Number_Int(string N)
{
	for (int i = 0; i < N.length(); i++)
	{
		if (Integer_Only(N[i]) == false)
			return false;
	}

	return true;
}

int Read_Int_Number(string Message)
{
	string N;

	do
	{
		cout << Message << endl;
		cout << "your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!Check_Number_Int(N));

	return stoi(N);
}

int Read_Positive_Int_Number(string Message)
{
	string N;

	do
	{
		cout << Message << endl;
		cout << "your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!(Check_Number_Int(N) && Check_PositiveOrNot(N)));

	return stoi(N);
}

float Read_Positive_Number(string Message)
{
	string N;

	do
	{
		cout << Message << endl;
		cout << "your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!(Check_Number(N) && Check_PositiveOrNot(N)));

	return stof(N);
}

float ReadNumber(string Message)
{
	string N;

	do
	{
		cout << Message << endl;
		cout << "your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!Check_Number(N));

	return stof(N);
}

int Read_Positive_Int_NumberInRange(string Message, int from, int to)
{
	string N;
	do
	{
		cout << "Enter a number between " << from << " & " << to << " : " << endl;
		cout << Message << endl;
		cout << "Your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!(Check_Number_Int(N) && CheckNumber_InRange(N, from, to) && Check_PositiveOrNot(N)));

	return stoi(N);
}

int ReadNumberInRange(string Message, int from, int to)
{
	string N;
	do
	{
		cout << "Enter A Number Between " << from << " & " << to << " : " << endl;
		cout << Message << endl;
		cout << "Your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!(Check_Number(N) && CheckNumber_InRange(N, from, to)));

	return stoi(N);
}


//*********************************************************************************************************
//*********************************************************************************************************

//******************************************* Program 1 ***************************************************
// Weeks & Days & Months in (Number Of Hours)


float HoursToDays(float Hours)
{
	return Hours / 24;
}
float HoursToWeeks(float Hours)
{
	return Hours / (24 * 7);
}
float HoursToMonths(float Hours)
{
	return Hours / (24 * 7 * 4);
}


//******************************************* Program 2 ***************************************************
// Task Duration in seconds


struct st_TaskDuration
{
	int Seconds, Minutes, Hours, Days;
};

st_TaskDuration ReadTaskDuration()
{
	st_TaskDuration TD;

	TD.Seconds = Read_Positive_Int_Number("Please, Enter The Total Seconds?");
	TD.Minutes = Read_Positive_Int_Number("Please, Enter The Total Minutes?");
	TD.Hours = Read_Positive_Int_Number("Please, Enter The Total Hours?");
	TD.Days = Read_Positive_Int_Number("Please, Enter The Total Days?");

	return TD;
}

int TaskDurationInSeconds(st_TaskDuration TD)
{
	return TD.Seconds + TD.Minutes * 60 + TD.Hours * 60 * 60 + TD.Days * 24 * 60 * 60;
}


//******************************************* Program 3 ***************************************************
// Seconds in (Days & Hours & Minutes)


st_TaskDuration SecondsToTaskDuration(int T_Secs)
{
	st_TaskDuration TD;
	int R;

	TD.Days = floor(T_Secs / (24 * 60 * 60));
	R = T_Secs % (24 * 60 * 60);
	TD.Hours = floor(R / (60 * 60));
	R %= (60 * 60);
	TD.Minutes = floor(R / 60);
	R %= 60;
	TD.Seconds = R;

	return TD;

}

void PrintTaskDuration(st_TaskDuration TD)
{
	cout << "****************************\n" << endl;
	cout << "- The Total Days = " << TD.Days << endl;
	cout << "- The Total Hours = " << TD.Hours << endl;
	cout << "- The Total Minutes = " << TD.Minutes << endl;
	cout << "- The Total Seconds = " << TD.Seconds << endl;
	cout << "\n\n * * * * * * * * * * * * * * * * *" << endl;
	cout << "* Task Duration = " << TD.Days << " : " << TD.Hours << " : " << TD.Minutes << " : " << TD.Seconds << " *" << endl;
	cout << " * * * * * * * * * * * * * * * * *\n" << endl;
}


//******************************************* Program 4 ***************************************************
// Day Of Week


enum en_DayOfWeek{ Sat = 1, Sun = 2, Mon = 3, Tue = 4, Wed = 5, Thu = 6, Fri = 7 };

en_DayOfWeek ReadDayOfWeek()
{
	string Message = " (1) Saturday\n (2) Sunday\n (3) Monday\n (4) Tuesday\n (5) Wednesday\n (6) Thursday\n (7) Friday\n";

	return (en_DayOfWeek)Read_Positive_Int_NumberInRange(Message, 1, 7);

}

string GetDayOfWeek(en_DayOfWeek Day)
{
	switch (Day)
	{
	case en_DayOfWeek::Sat:
		return "Today is : Saturday";
	case en_DayOfWeek::Sun:
		return "Today is : Sunday";
	case en_DayOfWeek::Mon:
		return "Today is : Monday";
	case en_DayOfWeek::Tue:
		return "Today is : Tuesday";
	case en_DayOfWeek::Wed:
		return "Today is : Wednesday";
	case en_DayOfWeek::Thu:
		return "Today is : Thursday";
	case en_DayOfWeek::Fri:
		return "Today is : Friday";
	default:
		return "Not A Valid Day";
	}
}



//******************************************* Program 5 ***************************************************
// Months Of year

enum en_MonthOfYear { January = 1, February = 2, March = 3,
	                  April = 4, May = 5, June = 6,July = 7,
	                  August = 8, September = 9, October = 10,
	                  November = 11, December = 12 };

en_MonthOfYear ReadMonthOfYear()
{
	string Message = "- Months Of year :\n (1) January\n (2) February\n (3) March\n (4) April\n (5) May\n (6) June\n (7) July\n (8) August\n (9) September\n (10) October\n (11) November\n (12) December\n\n*************************************************";
	return (en_MonthOfYear)Read_Positive_Int_NumberInRange(Message, 1, 12);
}

string GetMonthOfYear(en_MonthOfYear Month)
{
	switch (Month)
	{
	case en_MonthOfYear::January:
		return "January";
	case en_MonthOfYear::February:
		return "February";
	case en_MonthOfYear::March:
		return "March";
	case en_MonthOfYear::April:
		return "April";
	case en_MonthOfYear::May:
		return "May";
	case en_MonthOfYear::June:
		return "June";
	case en_MonthOfYear::July:
		return "July";
	case en_MonthOfYear::August:
		return "August";
	case en_MonthOfYear::September:
		return "September";
	case en_MonthOfYear::October:
		return "October";
	case en_MonthOfYear::November:
		return "November";
	case en_MonthOfYear::December:
		return "December";
	default:
		return "Not A Valid Month";
	}
}






//*********************************************************************************************************
//*********************************************************************************************************


int main()
{

	// Program 1

	/*float Hours = Read_Positive_Number("Please, Enter The Hours?");
	float Days = HoursToDays(Hours);
	float Weeks = HoursToWeeks(Hours);
	float Months = HoursToMonths(Hours);

	cout << "\n\n******************************\n";
	cout << "Total Hours = " << Hours << endl;
	cout << "Total Days = " << Days << endl;
	cout << "Total Weeks = " << Weeks << endl;
	cout << "Total Months = " << Months << endl;
	cout << "******************************\n\n" << endl;*/

	//***************************************************************************************************************************
	//***************************************************************************************************************************


	// Program 2
	
	//cout << "Task Duration in seconds = " << TaskDurationInSeconds(ReadTaskDuration()) << endl;



	//***************************************************************************************************************************
	//***************************************************************************************************************************

	// Program 3
	
	/*float TotalSeconds = Read_Positive_Int_Number("Please, Enter The Number Of Seconds?");
	PrintTaskDuration(SecondsToTaskDuration(TotalSeconds));*/



	//***************************************************************************************************************************
	//***************************************************************************************************************************

	//Program 4
	//cout << GetDayOfWeek(ReadDayOfWeek()) << endl;
	

	//***************************************************************************************************************************
	//***************************************************************************************************************************

	// Program 5
	cout << "***************************\n" <<  "- This Month is : " << GetMonthOfYear(ReadMonthOfYear()) << "\n***************************" << endl;




	return 0;
}