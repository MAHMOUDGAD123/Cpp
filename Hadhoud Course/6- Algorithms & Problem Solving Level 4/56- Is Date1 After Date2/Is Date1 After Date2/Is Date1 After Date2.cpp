#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "MGLib.h"

using namespace std;
using namespace MGLib;

bool IsDate1AfterDate2(sDate Date1, sDate Date2)
{
	return Date1.Year > Date2.Year ? true : (Date1.Year == Date2.Year ? (Date1.Month > Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day > Date2.Day : false)) : false);

	// or
	//return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualToDate2(Date1, Date2));
}


int main(void)
{
	sDate Date1;
	sDate Date2;

	for (;;)
	{
		printf("- Enter Date1/\n");
		Date1 = ReadDate();

		printf("\n- Enter Date2/\n");
		Date2 = ReadDate();


		printf("\n- Date1 Is:  %s \n", Day_Date(Date1).c_str());
		printf("\n- Date2 Is:  %s \n", Day_Date(Date2).c_str());

		if (IsDate1AfterDate2(Date1, Date2))
			cout << "\n\n- Yes, Date1 Is After Date2.";
		else
			cout << "\n\n- No, Date1 Isn't After Date2.";

		printf("\n\n-----------------------------------------------------------\n\n");
	}

	return 0;
}