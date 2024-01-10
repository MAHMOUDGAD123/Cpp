
#include <iostream>
#include <string>
#include <vector>
#include "MGLib.h"

using namespace std;
using namespace MGLib;



struct st_Employee
{
	string FName, LName;
	unsigned int Salary;
};


void Read_EmployeesData(vector <st_Employee>& vEmployees, unsigned short& NOEmployees)
{
	st_Employee Employee;

	cout << "Enter The Empolyees Data." << endl;
	cout << "-------------------------" << endl << endl;

	do
	{
		NOEmployees++;

		printf("\nEmployee[%hu]:\n", NOEmployees);
		cout << "------------\n\n";

		Employee.FName = Read_Text("Enter First Name: ");
		Employee.LName = Read_Text("Enter Last Name: ");
		Employee.Salary = Read_Positive_Number("Enter Salary: ");

		vEmployees.push_back(Employee);

		cout << endl;

	} while (Read_Bool_Input("Do You Want To Add More Employee?"));
}

void Print_EmployeesData(vector <st_Employee>& vEmployees, unsigned short NOEmployees)
{
	unsigned short Counter = 1;

	cout << "\n\n_________________________________________\n\n";

	cout << "\n\n--------------------\n";
	cout << "|->Empolyees Data<-|\n";
	cout << "--------------------\n\n\n";

	for (st_Employee& Employee : vEmployees)
	{
		printf("Employee[%hu]:\n", Counter);
		cout << "------------\n\n";

		cout << "- First Name: " << Employee.FName << endl;
		cout << "- Last Name : " << Employee.LName << endl;
		printf("- Salary    : %u$ ", Employee.Salary);

		Counter++;

		cout << endl;
	}

	printf("\n-> Total Number Of Employees = (%hu)\n\n", NOEmployees);
}

void Print_StVector(vector <st_Employee>& vEmployees, unsigned short NOEmployees)
{
	cout << "\n\n_________________________________________\n\n";

	cout << "\n\n--------------------\n";
	cout << "|->Empolyees Data<-|\n";
	cout << "--------------------\n\n\n";


	for (short i = 0; i < NOEmployees; i++)
	{
		printf("Employee[%hu]:\n", i + 1);
		cout << "------------\n\n";

		// The at() function is preferred over []:
		// Because at() throws an exception whenever the vector is out of bound,
		// While [] gives a garbage value.

		cout << "- First Name: " << vEmployees.at(i).FName << endl; // == vEmployees[i].FName
		cout << "- Last Name : " << vEmployees.at(i).LName << endl; // == vEmployees[i].LName
		cout << "- Salary    : " << vEmployees.at(i).Salary << endl; // == vEmployees[i].Salary

		cout << endl;
	}

	printf("\n-> Total Number Of Employees = (%hu)\n\n", NOEmployees);

}


int main()
{
	vector <st_Employee> vEmployees;
	unsigned short NOEmployees = 0;


	Read_EmployeesData(vEmployees, NOEmployees);
	
	Print_EmployeesData(vEmployees, NOEmployees);

	//Print_StVector(vEmployees, NOEmployees);


	return 0;
}
