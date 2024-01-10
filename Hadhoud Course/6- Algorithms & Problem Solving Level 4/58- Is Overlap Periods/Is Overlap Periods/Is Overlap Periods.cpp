#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "MGLib.h"

using namespace std;
using namespace MGLib;

sPeriod ReadPeriod(const char* Message = "")
{
	sPeriod Period;
	printf("\n\n%s\n\n", Message);

	printf("Enter Start Date");
	printf("\n----------------\n");
	Period.StartDate = ReadDate();
	printf("\nEnter End Date");
	printf("\n----------------\n");
	Period.EndDate = ReadDate();

	while (IsDate1AfterDate2(Period.StartDate, Period.EndDate))
	{
		printf("\n\n)-: Start_Date Can't Be After End_Date :-(\n\n");
		printf("Enter End Date Again");
		printf("\n--------------------\n");
		Period.EndDate = ReadDate();
	}
	return Period;
}

bool IsPeriod1BeforePeriod2(sPeriod Period1, sPeriod Period2)
{
	return IsDate1BeforeDate2(Period1.EndDate, Period2.StartDate);
}
bool IsPeriod1AfterPeriod2(sPeriod Period1, sPeriod Period2)
{
	return IsDate1AfterDate2(Period1.StartDate, Period2.EndDate);
}
bool IsPeriod1EqualToPeriod2(sPeriod Period1, sPeriod Period2)
{
	return (IsDate1EqualToDate2(Period1.StartDate, Period2.StartDate) && IsDate1EqualToDate2(Period1.EndDate, Period2.EndDate));
}

bool IsOverlapPeriods(sPeriod Period1, sPeriod Period2)
{
	return !(IsPeriod1BeforePeriod2(Period1, Period2) || IsPeriod1AfterPeriod2(Period1, Period2));
}


int main(void)
{
	sPeriod Period1;
	sPeriod Period2;

	for (;;)
	{
		Period1 = ReadPeriod("|->Enter Period1<-|");
		Period2 = ReadPeriod("|->Enter Period2<-|");

		printf("\n- Period1 Start Is:  %s \n", Day_Date(Period1.StartDate).c_str());
		printf("\n- Period1 End Is:    %s \n", Day_Date(Period1.EndDate).c_str());

		printf("\n- Period2 Start Is:  %s \n", Day_Date(Period2.StartDate).c_str());
		printf("\n- Period2 End Is:    %s \n", Day_Date(Period2.EndDate).c_str());


		if (IsOverlapPeriods(Period1, Period2))
			cout << "\n- Yes, Periods Overlaped.";
		else
			cout << "\n- No, There's No Overlaping.";


		printf("\n\n-----------------------------------------------------------\n\n");
	}

	return 0;
}