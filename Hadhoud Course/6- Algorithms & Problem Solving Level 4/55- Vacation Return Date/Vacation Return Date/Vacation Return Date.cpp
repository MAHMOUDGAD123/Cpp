#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "MGLib.h"

using namespace std;
using namespace MGLib;


sDate VacationReturnDate(sDate DateFrom, unsigned short VacationDays)
{
	while (VacationDays > 0)
	{
		if (IsBusinessDay(DateFrom)) VacationDays--;
		DateFrom = IncreaseDateByOneDay(DateFrom);
	}

	// To fix if the return date is weakend day
	while (IsWeakEnd(DateFrom))
		DateFrom = IncreaseDateByOneDay(DateFrom);

	return DateFrom;
}

int main(void)
{
	sDate StartDate;

	for (;;)
	{
		printf("- Vacation Starts/\n");
		StartDate = ReadDate();

		unsigned short VacationDays = ReadNumber("\n-> Enter The Vacation Days:  ");

		printf("\n- Vacation Start Date Is:  %s \n", Day_Date(StartDate).c_str());
		printf("\n- Vacation Return Date Is: %s \n", Day_Date(VacationReturnDate(StartDate, VacationDays)).c_str());

		printf("\n\n-----------------------------------------------------------\n\n");
	}

	return 0;
}