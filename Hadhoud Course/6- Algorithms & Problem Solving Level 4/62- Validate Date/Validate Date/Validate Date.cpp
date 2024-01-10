#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "MGLib.h"

using namespace std;
using namespace MGLib;


bool IsValidDate(sDate Date)
{
	return
		Date.Year > 0
		&&
		(Date.Month >= 1 && Date.Month <= 12)
		&&
		(Date.Day >= 1 && Date.Day <= NumberOfDaysInAMonth(Date.Year, Date.Month));
}




int main(void)
{
	sDate Date;

	for (;;)
	{
		//Date = ReadDate("Enter Date/");

		cout << "- Enter A Date?\n\n";
		Date.Day = ReadNumber("-> Enter A Day:  ");
		Date.Month = ReadNumber("-> Enter A Month:  ");
		Date.Year = ReadNumber("-> Enter A Year:  ");

		const char* Result = (IsValidDate(Date)) ? "valid date :-)" : "invalid date :-(";

		printf("\n=> (%hu/%hu/%hu) is %s", Date.Day, Date.Month, Date.Year, Result);


		printf("\n\n-----------------------------------------------------------\n\n");
	}

	return 0;
}