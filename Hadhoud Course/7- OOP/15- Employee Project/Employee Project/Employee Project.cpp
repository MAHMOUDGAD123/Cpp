#include <iostream>

using namespace std;


class clsEmployee
{
private:
	string _ID;
	string _FirstName;
	string _LastName;
	string _Title;
	string _Email;
	string _Phone;
	string _Department;
	float _Salary = 0;
	static int NumbersOfEmployees;

	string getID()
	{
		return _ID;
	}

	void setFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}
	string getFirstName()
	{
		return _FirstName;
	}

	void setLastName(string LastName)
	{
		_LastName = LastName;
	}
	string getLastName()
	{
		return _LastName;
	}

	void setTitle(string Title)
	{
		_Title = Title;
	}
	string getTitle()
	{
		return _Title;
	}

	void setEmail(string Email)
	{
		_Email = Email;
	}
	string getEmail()
	{
		return _Email;
	}

	void setPhone(string Phone)
	{
		_Phone = Phone;
	}
	string getPhone()
	{
		return _Phone;
	}

	void setDepartment(string Department)
	{
		_Department = Department;
	}
	string getDepartment()
	{
		return _Department;
	}

	void setSalary(int Salary)
	{
		_Salary = Salary;
	}
	int getSalary()
	{
		return _Salary;
	}

public:

	clsEmployee(string ID, string FirstName, string LastName, string Title, string Email, string Phone, string Department, int Salary)
	{
		NumbersOfEmployees++;
		_ID = ID;
		_FirstName = FirstName;
		_LastName = LastName;
		_Title = Title;
		_Email = Email;
		_Phone = Phone;
		_Department = Department;
		_Salary = Salary;
	}

	~clsEmployee()
	{
		cout << "\n\nEmployee" << NumbersOfEmployees << " deleted\n\n\n";
	}

	__declspec(property(get = getID)) string ID;

	__declspec(property(get = getFirstName, put = setFirstName)) string FirstName;

	__declspec(property(get = getLastName, put = setLastName)) string LastName;

	__declspec(property(get = getTitle, put = setTitle)) string Title;

	__declspec(property(get = getEmail, put = setEmail)) string Email;

	__declspec(property(get = getPhone, put = setPhone)) string Phone;

	__declspec(property(get = getDepartment, put = setDepartment)) string Department;

	__declspec(property(get = getSalary, put = setSalary)) int Salary;

	string FullName()
	{
		return _FirstName + ' ' + _LastName;
	}

	void Print()
	{
		cout << "=> Employee Info:";
		cout << "\n==============================================\n";
		cout << "- ID            : " << _ID;
		cout << "\n- First Name    : " << _FirstName;
		cout << "\n- Last Name     : " << _LastName;
		cout << "\n- Full Name     : " << FullName();
		cout << "\n- Title         : " << _Title;
		cout << "\n- Email         : " << _Email;
		cout << "\n- Phone         : " << _Phone;
		cout << "\n- Department    : " << _Department;
		cout << "\n- Salary        : " << _Salary << " $";
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

int clsEmployee::NumbersOfEmployees = 0;


int main()
{
	clsEmployee* Employee1 = new clsEmployee("A111", "Mahmoud", "Gad", "Software Engineer", "hooda.gad333@gmail.com", "+201097890670", "Software", 1000000);

	Employee1->Print();

	Employee1->SendEmail("Good News", "You are going to be a great programmer one day MG :-)");

	Employee1->SendSMS("Keep working and never stop learning this is only the beginning");

	delete Employee1;

	clsEmployee* Employee2 = new clsEmployee("A333", "Amira", "Gad", "Fastion Designer", "Mera8382@gmail.com", "+201021743008", "Design", 2000000);

	Employee2->Print();

	Employee2->SendEmail("Good News", "You are going to be a great fastion designer one day Mera :-)");

	Employee2->SendSMS("Keep working and never stop learning this is only the beginning");

	delete Employee2;


	return 0;
}