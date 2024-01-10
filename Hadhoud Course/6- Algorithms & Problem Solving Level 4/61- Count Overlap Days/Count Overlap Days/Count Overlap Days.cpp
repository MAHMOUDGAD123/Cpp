#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "MGLib.h"

using namespace std;
using namespace MGLib;



size_t CountOverlapDays(sPeriod Period1, sPeriod Period2)
{
	if (IsOverlapPeriods(Period1, Period2))
	{
		sPeriod OverlapPeriod;
		OverlapPeriod.StartDate = IsDateWithinPeriod(Period2, Period1.StartDate) ? Period1.StartDate : Period2.StartDate;
		OverlapPeriod.EndDate = IsDateWithinPeriod(Period2, Period1.EndDate) ? Period1.EndDate : Period2.EndDate;
		return DiffInDays(OverlapPeriod.StartDate, OverlapPeriod.EndDate, true);
	}
	return 0;
}

size_t _CountOverlapDays(sPeriod Period1, sPeriod Period2)
{
	if (IsOverlapPeriods(Period1, Period2))
	{
		bool isPeriod1StartWithinPeriod2 = IsDateWithinPeriod(Period2, Period1.StartDate);
		bool isPeriod1EndWithinPeriod2 = IsDateWithinPeriod(Period2, Period1.EndDate);

		// Case 1: if Period1 within Period2
		if (isPeriod1StartWithinPeriod2 && isPeriod1EndWithinPeriod2)
			return PeriodLengthInDays(Period1, true);

		// Case 2: if only Period1:StartDate within Period2
		if (isPeriod1StartWithinPeriod2 && !isPeriod1EndWithinPeriod2)
			return DiffInDays(Period1.StartDate, Period2.EndDate, true);

		// Case 3: if only Period1:EndDate within Period2
		if (!isPeriod1StartWithinPeriod2 && isPeriod1EndWithinPeriod2)
			return DiffInDays(Period2.StartDate, Period1.EndDate, true);

		// Case 4: if Period2 within Period1
		return PeriodLengthInDays(Period2, true);
	}
	return 0;
}



int main(void)
{
	sPeriod Period1;
	sPeriod Period2;

	for (;;)
	{
		Period1 = ReadPeriod("Enter Period 1/");
		Period2 = ReadPeriod("\n\nEnter Period 2/");

		printf("\n- Period1 Start Is: %s", Day_Date(Period1.StartDate).c_str());
		printf("\n- Period1 End Is:   %s", Day_Date(Period1.EndDate).c_str());

		printf("\n\n- Period2 Start Is: %s", Day_Date(Period2.StartDate).c_str());
		printf("\n- Period2 End Is:   %s", Day_Date(Period2.EndDate).c_str());

		printf("\n\n- Number Of Overlap Days = %llu", CountOverlapDays(Period1, Period2));
		printf("\n\n- Number Of Overlap Days = %llu", _CountOverlapDays(Period1, Period2));



		printf("\n\n-----------------------------------------------------------\n\n");
	}

	return 0;
}