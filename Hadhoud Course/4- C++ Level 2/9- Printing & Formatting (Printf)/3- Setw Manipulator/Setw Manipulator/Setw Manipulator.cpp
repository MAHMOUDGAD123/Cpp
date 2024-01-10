
#include <iostream>
#include <iomanip> // Include <iomanip> to use (setw)
#include <cstdio>
#include "MGLib.h"

using namespace std;
using namespace MGLib;



// using setw() function to build a table




string Scores(unsigned short NumberOfTabs)
{
	string Scores = "";

	for (short i = 1; i <= NumberOfTabs; i++)
	{
		Scores += "-";
	}

	return Scores;
}

string Spaces(unsigned short NumberOfTabs)
{
	string Spaces = "";

	for (short i = 1; i <= NumberOfTabs; i++)
	{
		Spaces += " ";
	}

	return Spaces;
}


// Student Data
struct st_StudentInfo
{
	string Name;
	unsigned int Id = 0;
	unsigned short Mark = 0;

};

struct st_Students
{
	st_StudentInfo Student[100];
	unsigned int NumberOfStudents = 0;
};


void Print_TableHead(short TableWidth)
{
	// Colomns Names
	string C1 = "Code";
	string C2 = "Name";
	string C3 = "Mark/100";


	cout << "Students Table:" << endl;
	cout << "**************" << endl;


	cout << "|" << Scores(TableWidth) << "|" << Scores(TableWidth) << "|" << Scores(TableWidth) << "|" << endl;

	cout << "|"
		<< Spaces(TableWidth / 2 - C1.length() / 2) << C1 << Spaces(TableWidth / 2 - C1.length() / 2) << "|"
		<< Spaces(TableWidth / 2 - C2.length() / 2) << C2 << Spaces(TableWidth / 2 - C2.length() / 2) << "|"
		<< Spaces(TableWidth / 2 - C3.length() / 2) << C3 << Spaces(TableWidth / 2 - C3.length() / 2) << "|"
		<< endl;

	cout << "|" << Scores(TableWidth) << "|" << Scores(TableWidth) << "|" << Scores(TableWidth) << "|" << endl;
}

void Print_TableFooter(short TableWidth, unsigned int NumberOfStudents)
{
	cout << "|" << S_UnderScores(TableWidth) << "|" << S_UnderScores(TableWidth) << "|" << S_UnderScores(TableWidth) << "|" << endl;

	cout << endl << "|-> Total Number Of students = " << NumberOfStudents << endl;

	cout << S_UnderScores(TableWidth * 3 + 4)<< endl;
}

st_Students ReadData()
{
	bool AddMore = false;

	unsigned int Counter = 0;

	st_Students Students;

	printf("Enter The Students Data\n\n");
	
	do
	{
		printf("- Student [%u]: \n", Counter + 1);
		cout << "***************" << endl << endl;

		
		Students.Student[Counter].Id = Read_Positive_Int_Number_OfNDigits("-> Id: ", 10);
		Students.Student[Counter].Name = Read_Text("-> Name: ");
		Students.Student[Counter].Mark = Read_Positive_Int_Number_OfNDigits("-> Mark: ", 3);

		cout << endl;

		Counter++;

		cout << "Do You Want To Add More Students? ";
		AddMore = Read_Bool_Input();

	} while (AddMore);

	Students.NumberOfStudents = Counter;
	
	return Students;
}

void Print_TableBody(short TableWidth, st_Students Students)
{
	for (short i = 0; i < Students.NumberOfStudents; i++)
	{
		cout << "|"
			<< setw(TableWidth / 2 + 1) << Students.Student[i].Id << setw(TableWidth / 2) << "|"
			<< setw(TableWidth / 2 + 1) << Students.Student[i].Name << setw(TableWidth / 2) << "|"
			<< setw(TableWidth / 2 + 1) << Students.Student[i].Mark << setw(TableWidth / 2) << "|"
			<< endl;
	}
}


int main()
{
	st_Students Students;

	short TableWidth = 0;
	
	Students = ReadData();

	do
	{
		TableWidth = Read_Positive_Number("Enter The Width Of Your Table: (Even >= 20)--> ");

	} while (TableWidth < 20 || TableWidth % 2 != 0);



	Print_TableHead(TableWidth);

	Print_TableBody(TableWidth, Students);

	Print_TableFooter(TableWidth, Students.NumberOfStudents);

	

	
	return 0;
}