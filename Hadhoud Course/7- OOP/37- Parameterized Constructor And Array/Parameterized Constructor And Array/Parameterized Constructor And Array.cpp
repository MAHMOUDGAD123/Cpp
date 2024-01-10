#include <array>
#include "clsEmployee.h"

// clsEmployees static variable initialization
unsigned int clsEmployee::_TotalEmployees = 0;





void PrintEmployees(const clsEmployee Employees[], const int& TotalEmployees)
{
	for (size_t index = 0; index < TotalEmployees; index++)
		Employees[index].Print();
}

void PrintEmployees(const array <clsEmployee, 3>& Employees, const int& TotalEmployees)
{
	for (size_t index = 0; index < TotalEmployees; index++)
		Employees[index].Print();
}



int main()
{
	const int Total = 3;

	clsEmployee Employees[Total]{ clsEmployee(1), clsEmployee(2), clsEmployee(3) };

	//array <clsEmployee, Total> Employees = { clsEmployee(1), clsEmployee(2), clsEmployee(3) };
	
	PrintEmployees(Employees, Total);

	cout << "Total Employees = " << clsEmployee::TotalEmployees() << endl;


	return 0;
}