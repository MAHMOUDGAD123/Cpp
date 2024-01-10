#include "clsEmployee.h"
#include "MGLib.h"



// clsEmployees static variable initialization
unsigned int clsEmployee::_TotalEmployees = 0;



clsEmployee* ReadEmployeesData(clsEmployee* Employees, const int& TotalEmployees)
{
	for (unsigned short index = 0; index < TotalEmployees; index++)
		Employees[index] = clsEmployee(index + 1);

	return Employees;
}

void PrintEmployees(const clsEmployee* Employees, const int& TotalEmployees)
{
	for (size_t index = 0; index < TotalEmployees; index++)
		Employees[index].Print();
}



int main()
{
	int Total = MGLib::ReadNumber("Enter Total Employees: ");

	clsEmployee* Employees = new clsEmployee[Total];

	PrintEmployees(ReadEmployeesData(Employees, Total), Total);

	cout << "Total Employees = " << clsEmployee::TotalEmployees() << endl;

	delete[] Employees;

	return 0;
}