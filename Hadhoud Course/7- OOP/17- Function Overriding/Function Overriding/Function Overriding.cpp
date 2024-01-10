#include <iostream>
#include <iomanip>

using namespace std;


// Function Overriding : The function in derived class overrides the function in base class.

// If you override a function in base class you won't be able to access this function from the object of derived class.
// but you you can access this function inside derived class using the following syntax:
// -> [base-class name] :: [function name];

// you can't access the private data members in the base-class directly so you will use { set & get properties }

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

	string getFullName()
	{
		return _FirstName + ' ' + _LastName;
	}

	__declspec(property(get = getFullName)) string FullName;

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

	virtual void Print()
	{
		cout << "=> Info:";
		cout << "\n==============================================\n";
		cout << "- ID            : " << _ID;
		cout << "\n- First Name    : " << _FirstName;
		cout << "\n- Last Name     : " << _LastName;
		cout << "\n- Full Name     : " << FullName;
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

	clsEmployee(string ID, string FirstName, string LastName, string Email, string Phone, string Department, string Title, float Salary)
		: clsPerson(ID, FirstName, LastName, Email, Phone)
	{
		++_TotalEmployees;
		_Department = Department;
		_Title = Title;
		_Salary = Salary;
	}


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



	// this function will override the Print() function in the clsPerson class
	void Print() override
	{
		cout << "\n=> Employee(" << _TotalEmployees << ") Info:";
		cout << "\n==============================================\n";
		cout << "- ID            : " << ID;
		cout << "\n- First Name    : " << FirstName;
		cout << "\n- Last Name     : " << LastName;
		cout << "\n- Full Name     : " << FullName;
		cout << "\n- Email         : " << Email;
		cout << "\n- Phone         : " << Phone;
		cout << "\n- Department    : " << _Department;
		cout << "\n- Title         : " << _Title;
		cout << "\n- Salary        : " << fixed << setprecision(0) << _Salary;
		cout << "\n==============================================\n";
	}

	void Print1()
	{
		// calling the base-class overrided function
		clsPerson::Print();
	}

};

unsigned int clsEmployee::_TotalEmployees = 0;

int main()
{
	clsEmployee Employee1("A111", "Mahmoud", "Gad", "hooda.gad333@gmail.com", "+201097890670", "Programming", "Software Eng", 1000000);

	Employee1.Print(); // this will only call the new print() function 

	cout << "-> Total Employees = " << Employee1.TotalEmployees;

	cout << "\n\n\n\n";

	Employee1.Print1(); // this will call the base-class print() function 

	cout << "\n\n\n\n";

	// you can call the function of the base-class using this too
	Employee1.clsPerson::Print();

	return 0;
}