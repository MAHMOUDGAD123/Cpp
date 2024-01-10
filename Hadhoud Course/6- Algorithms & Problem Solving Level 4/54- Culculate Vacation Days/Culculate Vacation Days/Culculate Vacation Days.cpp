#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "MGLib.h"

using namespace std;
using namespace MGLib;


unsigned short VacationDays(sDate DateFrom, sDate DateTo)
{
	unsigned short ActualVacationDays = 0;

	while (IsDate1BeforeDate2(DateFrom, DateTo))
	{
		if (IsBusinessDay(DateFrom)) ActualVacationDays++;
		DateFrom = IncreaseDateByOneDay(DateFrom);
	}
	return ActualVacationDays;
}


int main(void)
{
	sDate StartDate;
	sDate EndDate;

	for (;;)
	{
		printf("- Vacation Starts/\n");
		StartDate = ReadDate();

		printf("\n- Vacation Ends/\n");
		EndDate = ReadDate();


		printf("\n-> Vacation From: %s \n", Day_Date(StartDate).c_str());
		printf("-> vacation To:   %s \n", Day_Date(EndDate).c_str());


		printf("\n-> Actual Vacation Days = %hu Day(s).", VacationDays(StartDate, EndDate));

		printf("\n\n-----------------------------------------------------------\n\n");
	}

	return 0;
}