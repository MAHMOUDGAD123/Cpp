#include <iostream>
#include <string>
#include <iomanip>
#include "MGLib.h"

using namespace std;
using namespace MGLib;



struct st_Student
{
	string FullName;
	unsigned short Age = 0;
	float GPA = 0.0f;
};

void Read_Studets_Data(st_Student* ptr, unsigned int NOStudents)
{
	cout << "\n\nEnter Students Data:\n\n";
	for (unsigned int i = 0; i < NOStudents; i++)
	{
		printf("\nStudent[%u]:\n\n", i + 1);

		ptr->FullName = Read_Text("- Name: ");
		ptr->Age = Read_Positive_Number("- Age: ");
		ptr->GPA = Read_NumberInRange("- GPA: ", 0, 100);
	}
	cout << endl << endl;
}


void Display_Students_Data(st_Student* ptr, unsigned int NOStudents)
{
	cout << "\n************************************\n";
	cout << "*******    Students Data    ********\n";
	cout << "************************************\n\n";

	for (unsigned int i = 0; i < NOStudents; i++)
	{
		printf("\nStudent[%u]:\n", i + 1);
		cout << "-------------\n\n";

		cout << "- Name|--> { " << ptr->FullName << " }\n";
		printf("- Age |--> { %hu }\n", ptr->Age);
		printf("- GPA |--> { %.1f }\n", ptr->GPA);
	}

	cout << "\n\n************************************\n\n";

	cout << endl << endl;
}



int main()
{
	unsigned int NOStudents = 0;

	NOStudents = Read_Positive_Number("How Much Students Do You Want to Add? |--> ");
	
	// Array of Struct memory allocation
	st_Student* ptr = new st_Student[NOStudents];


	Read_Studets_Data(ptr, NOStudents);

	Display_Students_Data(ptr, NOStudents);


	// Free up the memory ptr
	delete[] ptr;

	ptr = NULL; // Optional


	return 0;
}