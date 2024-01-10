#include <iostream>
#include "clsPerson.h"
#include "clsEmployee.h"

using namespace std;



// Separating Code and Classes in Libraries will make our life easier and we can control our code and organize it better.

// We must use "#pragma once" in each header file to prevent the complier from loading
// the library more than one time and have repeated code included.

// TotalEmployees initialization
unsigned int clsEmployee::_TotalEmployees = 0;


int main()
{
	clsEmployee Employee1("A111", "Mahmoud", "Gad", "hooda.gad333@gmail.com", "+201097890670", "Programming", "Software Eng", 1000000);

	Employee1.Print();
	cout << "Total Employees = " << Employee1.TotalEmployees << endl;

	return 0;
}