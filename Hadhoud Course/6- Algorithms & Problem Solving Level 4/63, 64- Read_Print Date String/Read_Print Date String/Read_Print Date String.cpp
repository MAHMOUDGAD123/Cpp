#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "MGLib.h"

using namespace std;
using namespace MGLib;




vector <string> Split_String(const string& Str, const string& delim)
{
	vector <string> vWords;
	size_t found = 0;
	size_t Str_len = Str.length();
	unsigned short delim_len = (unsigned short)delim.length();

	for (unsigned short index = 0; index < Str_len; index++)
	{
		// Find first delimiter & store its index
		if ((found = Str.find(delim, index)) != string::npos)
		{
			// if (found == index) this means that the word that we will store is empty ""
			if (found != index)
				vWords.push_back(Str.substr(index, found - index)); // Store word

			// to continue from the next word
			index = (unsigned short)(found + delim_len - 1);
		}
		else
		{
			// Store the last word and break loop
			vWords.push_back(Str.substr(index, Str_len - 1));
			break;
		}
	}
	return vWords;
}

string ReadStringDate(const char* Message = "")
{
	string strDate;
	cout << Message;
	getline(cin >> ws, strDate);
	return strDate;
}

string DateToString(const sDate& Date)
{
	return to_string(Date.Day) + '/' + to_string(Date.Month) + '/' + to_string(Date.Year);
}

// No validation - using split function
sDate _StringToDate(const string& strDate)
{
	sDate Date;
	vector <string> vDate = Split_String(strDate, "/");

	Date.Day = stoi(vDate[0]);
	Date.Month = stoi(vDate[1]);
	Date.Year = stoull(vDate[2]);

	return Date;
}

// With validation
sDate StringToDate(const string& strDate)
{
	sDate Date;
	string arrDate[3], tempstr;
	unsigned short Index = 0;

	for (const char& C : strDate)
	{
		if (C == '/') arrDate[Index++] = tempstr, tempstr = "";
		else if (IsDigit(C)) tempstr += C; // only store digits

		if (Index == 3) break; // to store only 3 numbers - day/month/year
	}
	if (tempstr != "") arrDate[Index] = tempstr; // store year

	// Save date - store 0 if empty "" 
	Date.Day = (arrDate[0] == "") ? 0 : stoi(arrDate[0]);
	Date.Month = (arrDate[1] == "") ? 0 : stoi(arrDate[1]);
	Date.Year = (arrDate[2] == "") ? 0 : stoi(arrDate[2]);

	// make sure that this date is a valid date - ask user to enter again if invalid (unsing recursion)
	return (IsValidDate(Date)) ? Date : StringToDate(ReadStringDate("Invalid Date, Enter Again (dd/mm/yyyy)?  "));
}



int main(void)
{
	sDate Date;

	for (;;)
	{
		Date = StringToDate(ReadStringDate("Please, Enter Date (dd/mm/yyyy)?  "));

		cout << "\n- Day = " << Date.Day;
		cout << "\n- Month = " << Date.Month;
		cout << "\n- Year = " << Date.Year;

		printf("\n\n=> Date is: %s", DateToString(Date).c_str());


		printf("\n\n-----------------------------------------------------------\n\n");
	}

	return 0;
}