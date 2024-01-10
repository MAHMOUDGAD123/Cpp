#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "MGLib.h"

using namespace std;
using namespace MGLib;


long long PeriodLengthInDays(sPeriod Period, bool IncludeEndDay = false)
{
	return DiffInDays(Period.StartDate, Period.EndDate, IncludeEndDay);
}


int main(void)
{
	sPeriod Period;

	for (;;)
	{
		Period = ReadPeriod("|->Enter Period<-|");

		printf("\n- Period Start Is:  %s \n", Day_Date(Period.StartDate).c_str());
		printf("\n- Period End Is:    %s \n", Day_Date(Period.EndDate).c_str());

		printf("\n- Period Length In Days                     = %lld", PeriodLengthInDays(Period));
		printf("\n- Period Length In Days (Including End Day) = %lld", PeriodLengthInDays(Period, true));

		printf("\n\n-----------------------------------------------------------\n\n");
	}

	return 0;
}