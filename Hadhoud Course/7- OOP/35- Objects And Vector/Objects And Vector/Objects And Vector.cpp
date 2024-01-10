#include <iostream>
#include <vector>
#include "clsEmployee.h"
#include "MGLib.h"

using namespace std;

clsEmployee ReadEmployeeData()
{
	clsEmployee Emp;
	return Emp;
}

vector <clsEmployee> ReadEmployeesData()
{
	vector <clsEmployee> vEmployees;

	do
	{
		vEmployees.push_back(ReadEmployeeData());

	} while (MGLib::Read_YesOrNo("\n\nDo You Want to Add More Employees? y/n? "));

	return vEmployees;
}

void PrintEmployees(const vector <clsEmployee>& vEmployees)
{
	for (const clsEmployee& Emp : vEmployees)
		Emp.Print();
}

int main()
{
	vector <clsEmployee> vEmployees;

	vEmployees = ReadEmployeesData();

	PrintEmployees(vEmployees);

	cout << "Total Employees = " << clsEmployee::TotalEmployees() << endl;

	return 0;
}