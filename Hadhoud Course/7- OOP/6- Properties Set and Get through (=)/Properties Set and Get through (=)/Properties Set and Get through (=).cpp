#include <iostream>

using namespace std;


// using declaration specification:
// __declspec(property(get = 'getfunctionName', put = 'setfunctionName')) [datatype] [Name];

class clsPerson
{
private:
	string _FirstName, _LastName;
	string _NationalId = "29709101204993";

public:
	void setFirstName(string firstname)
	{
		_FirstName = firstname;
	}
	string getFirstName()
	{
		return _FirstName;
	}

	// declaration property for FirstName
	__declspec(property(get = getFirstName, put = setFirstName)) string FirstName;

	void setLastName(string lastname)
	{
		_LastName = lastname;
	}
	string getLastName()
	{
		return _LastName;
	}

	// declaration property for LastName
	__declspec(property(get = getLastName, put = setLastName)) string LastName;


	string getNationalId()
	{
		return _NationalId;
	}

	__declspec(property(get = getNationalId)) string NationalId;

};



int main()
{
	clsPerson Person;

	Person.FirstName = "Mahmoud";
	cout << "First Name: " << Person.FirstName << endl;

	Person.LastName = "Gad";
	cout << "Last Name : " << Person.LastName << endl;
	
	cout << "National Id: " << Person.NationalId << endl;

	return 0;
}