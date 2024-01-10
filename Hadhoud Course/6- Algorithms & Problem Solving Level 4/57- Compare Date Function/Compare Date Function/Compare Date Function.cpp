#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "MGLib.h"

using namespace std;
using namespace MGLib;


enum CompareResults { Before = -1, Equal = 0, After = 1 };

short Compare2Dates(sDate Date1, sDate Date2)
{
	/*if (IsDate1BeforeDate2(Date1, Date2))
		return CompareDatesResults::Before;

	if (IsDate1EqualToDate2(Date1, Date2))
		return CompareDatesResults::Equal;

	return CompareDatesResults::After;*/

	return IsDate1BeforeDate2(Date1, Date2) ? Before : (IsDate1EqualToDate2(Date1, Date2) ? Equal : After);
}


int main(void)
{
	sDate Date1;
	sDate Date2;

	for (;;)
	{
		printf("/\\ Enter Date1/\\");
		printf("\n----------------\n");
		Date1 = ReadDate();

		printf("\n/\\ Enter Date2/\\");
		printf("\n----------------\n");
		Date2 = ReadDate();


		printf("\n- Date1 Is:  %s \n", Day_Date(Date1).c_str());
		printf("\n- Date2 Is:  %s \n", Day_Date(Date2).c_str());

		printf("\n- Compare Result = %hi", Compare2Dates(Date1, Date2));

		printf("\n\n-----------------------------------------------------------\n\n");
	}

	return 0;
}