#include <iostream>
#include <iomanip>

using namespace std;


// Muktilevel Inheritance: A class can also be derived from one class, which is already derived from another class.


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

	void Print()
	{
		cout << "\n\n=> Info:";
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


// this class inherits clsPerson
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

	static unsigned int Total()
	{
		return _TotalEmployees;
	}

	void Print()
	{
		cout << "\n\n=> Employee(" << _TotalEmployees << ") Info:";
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

};

unsigned int clsEmployee::_TotalEmployees = 0;


// this class inherits clsEmployee
class clsDeveloper : public clsEmployee
{
private:
	string _MainProgrammingLanguage;
	static unsigned int _TotalDevlopers;

public:

	clsDeveloper(string ID, string FirstName, string LastName, string Email, string Phone, string Department, string Title, float Salary, string MainProgLan)
		: clsEmployee(ID, FirstName, LastName, Email, Phone, Department, Title, Salary)
	{
		_TotalDevlopers++;
		_MainProgrammingLanguage = MainProgLan;
	}

	void setMainProgrammingLanguage(string MainProgLang)
	{
		_MainProgrammingLanguage = MainProgLang;
	}
	string getMainProgrammingLanguage()
	{
		return _MainProgrammingLanguage;
	}

	__declspec(property(get = getMainProgrammingLanguage, put = setMainProgrammingLanguage)) string MainProgrammingLanguage;

	// Overriding
	static unsigned int Total()
	{
		return _TotalDevlopers;
	}


	// Overriding
	void Print()
	{
		cout << "\n\n=> Developer(" << _TotalDevlopers << ") Info:";
		cout << "\n==============================================";
		cout << "\n- ID                 : " << ID;
		cout << "\n- First Name         : " << FirstName;
		cout << "\n- Last Name          : " << LastName;
		cout << "\n- Full Name          : " << FullName;
		cout << "\n- Email              : " << Email;
		cout << "\n- Phone              : " << Phone;
		cout << "\n- Department         : " << Department;
		cout << "\n- Title              : " << Title;
		cout << "\n- Main Prog Language : " << _MainProgrammingLanguage;
		cout << "\n- Salary             : " << fixed << setprecision(0) << Salary << '$';
		cout << "\n==============================================\n";
	}
};

unsigned int clsDeveloper::_TotalDevlopers = 0;


int main()
{
	cout << "-> Total Developers = " << clsDeveloper::Total();


	clsDeveloper Developer1("A111", "Mahmoud", "Gad", "hooda.gad333@gmail.com", "+201097890670", "Programming", "Software Eng", 1000000, "C++");
	Developer1.Print();

	cout << "-> Total Developers = " << clsDeveloper::Total();

	clsDeveloper Developer2("A555", "Mohammed", "Gad", "mogad7@gmail.com", "+201013171345", "Programming", "AI Develper", 1500000, "Python");
	Developer2.Print();

	cout << "-> Total Developers = " << clsDeveloper::Total();

	cout << "\n\n";
	return 0;
}