#include <iostream>

using namespace std;


// Inheritance: Inheritance is one in which a new class is created that inherits the properties of the already exist class.
// It supports the concept of code reusability and reduces the length of the code in object-oriented programming.

// The class that inherits properties from another class is called Sub-class or Derived-Class.
// The class whose properties are inherited by a subclass is called Base-Class or Super-class.

// syntax:
// class [derived-class name] : public [super-class name] {}


// solve parameterized constructor:
/*
	[sub - class constructor name](parameters of super - class + new parameters of the sub - class) 
	: [super-class constructor name](parameters of super-class)
	{
		// initialization of sub-class data members
	}
  */

class clsPerson
{
private:
	string _ID;
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:

	clsPerson(string ID, string FirstName, string LastName, string Email, string Phone)
	{
		_ID = ID;
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}

	string getID()
	{
		return _ID;
	}

	__declspec(property(get = getID)) string ID;

	void setFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}
	string getFirstName()
	{
		return _FirstName;
	}

	__declspec(property(get = getFirstName, put = setFirstName)) string FirstName;

	void setLastName(string LastName)
	{
		_LastName = LastName;
	}
	string getLastName()
	{
		return _LastName;
	}

	__declspec(property(get = getLastName, put = setLastName)) string LastName;

	string FullName()
	{
		return _FirstName + ' ' + _LastName;
	}
	
	void setEmail(string Email)
	{
		_Email = Email;
	}
	string getEmail()
	{
		return _Email;
	}

	__declspec(property(get = getEmail, put = setEmail)) string Email;

	void setPhone(string Phone)
	{
		_Phone = Phone;
	}
	string getPhone()
	{
		return _Phone;
	}

	__declspec(property(get = getPhone, put = setPhone)) string Phone;

	void Print()
	{
		cout << "=> Info:";
		cout << "\n==============================================\n";
		cout << "- ID            : " << _ID;
		cout << "\n- First Name    : " << _FirstName;
		cout << "\n- Last Name     : " << _LastName;
		cout << "\n- Full Name     : " << FullName();
		cout << "\n- Email         : " << _Email;
		cout << "\n- Phone         : " << _Phone;
		cout << "\n==============================================\n";
	}

	void SendEmail(const char* Subject, const char* Body)
	{
		cout << "\n- The Following Email Sent Successfully to -> " << _Email;
		cout << "\nSubject: " << Subject;
		cout << "\nBody: {" << Body << "}\n";
	}

	void SendSMS(const char* MSG)
	{
		cout << "\n- The Following SMS Sent Successfully to -> " << _Phone;
		cout << "\nMessage: {" << MSG << "}\n";
	}

};


class clsEmployee : public clsPerson
{
private:
	string _Department;
	string _Title;
	float _Salary = 0;
	static unsigned int _TotalEmployees;

public:

	// to solve the problem of parameterized constructor of the super class we will use this to include all varibles of the derived class.
	// we will include all clsEmployee data members as parameters to clsEmployee constructor
	// then we will send the parameters that the clsPerson constructor needs.
	clsEmployee(string ID, string FirstName, string LastName, string Email, string Phone, string Department, string Title, float Salary)
		: clsPerson(ID, FirstName, LastName, Email, Phone), _Department(Department), _Title(Title), _Salary(Salary)
	{}

	
	void setDepartment(string Department)
	{
		_Department = Department;
	}
	string getDepartment()
	{
		return _Department;
	}
	__declspec(property(get = getDepartment, put = setDepartment)) string Department;

	void setTitle(string Title)
	{
		_Title = Title;
	}
	string getTitle()
	{
		return _Title;
	}
	__declspec(property(get = getTitle, put = setTitle)) string Title;

	void setSalary(float Salary)
	{
		_Salary = Salary;
	}
	float getSalary()
	{
		return _Salary;
	}
	__declspec(property(get = getSalary, put = setSalary)) float Salary;

	unsigned int getTotalEmployees()
	{
		return _TotalEmployees;
	}
	__declspec(property(get = getTotalEmployees)) unsigned int TotalEmployees;

};

unsigned int clsEmployee::_TotalEmployees = 0;

int main()
{
	clsEmployee Employee1("A111", "Mahmoud", "Gad", "hooda.gad333@gmail.com", "+201097890670", "Programming", "Software Eng", 1000000);

	// we will solve the problem of the print() function in the next lesson using 'Function Overriding'
	Employee1.Print();

   return 0;
}