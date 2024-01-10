#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "MGLib.h"

using namespace std;
using namespace MGLib;


bool IsDateWithinPeriod(const sPeriod& Period, const sDate& Date)
{
	return !(IsDate1BeforeDate2(Date, Period.StartDate) || IsDate1AfterDate2(Date, Period.EndDate));
}


int main(void)
{
	sPeriod Period;
	sDate Date;

	for (;;)
	{
		Period = ReadPeriod("|->Enter Period<-|");
		Date = ReadDate("\n\nEnter A Date?");

		printf("\n- Period Start Is: %s", Day_Date(Period.StartDate).c_str());
		printf("\n- Period End Is:   %s", Day_Date(Period.EndDate).c_str());
		printf("\n\n- Date Is:         %s", Day_Date(Date).c_str());

		if (IsDateWithinPeriod(Period, Date))
			cout << "\n\n- Yes, Date Is Within The Period.\n\n";
		else
			cout << "\n\n- No, Date Isn't Within The Period.\n\n";



		printf("\n\n-----------------------------------------------------------\n\n");
	}

	return 0;
}