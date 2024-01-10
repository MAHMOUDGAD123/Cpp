#include <iostream>

using namespace std;

// read/write -> we use set and get properties
// read only  -> we use get property
// write only -> we use set property


class clsPerson
{

private:
	string _FirstName, _LastName;
	string _NationalId = "29709101204993";
	bool _isMarried = false;


public:

	// read/write properties
	void setFirstName(string firstname)
	{
		_FirstName = firstname;
	}
	string getFirstName()
	{
		return _FirstName;
	}

	// read/write properties
	void setLastName(string lastname)
	{
		_LastName = lastname;
	}
	string getLastName()
	{
		return _LastName;
	}
	
	string fullname()
	{
		return _FirstName + ' ' + _LastName;
	}

	// read only property for NationalId
	string getNationalId()
	{
		return _NationalId;
	}

	// Write only property
	void setMartialStatus(bool Status)
	{
		_isMarried = Status;
	}

	string MartialStatus()
	{
		return (_isMarried) ? "Married" : "Single";
	}

	const static int Age = 25;

};


int main()
{
	clsPerson Person;

	Person.setFirstName("Mahmoud");
	Person.setLastName("Gad");
	Person.setMartialStatus(true);

	cout << "- First Name     : " << Person.getFirstName() << endl;
	cout << "- Last Name      : " << Person.getLastName() << endl;
	cout << "- Full Name      : " << Person.fullname() << endl;
	cout << "- National Id    : " << Person.getNationalId() << endl;
	cout << "- Martial Status : " << Person.MartialStatus() << endl;

	cout << clsPerson::Age << endl;

	cout << "\n\n";

	return 0;
}