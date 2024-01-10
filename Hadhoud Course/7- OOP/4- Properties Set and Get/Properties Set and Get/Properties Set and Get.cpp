#include <iostream>

using namespace std;

//
// 
// _________________________________________________________________
// | you shouldn't use a public data members anymore in your class |
// -----------------------------------------------------------------
// 
// but you should make all data members private
// and use properities set/get to update the value of the private data member
// set/get are functions & procedures allows you to store and get date from private members
// set -> used to setting the value of any data member inside the class
// get -> used to retrieve any data member from the class


class clsPerson
{

private:
	string _FirstName, _LastName, _NationalId;

public:
	// _FirstName set/get
	void setFirstName(string firstname)
	{
		_FirstName = firstname;
	}
	string getFirstName()
	{
		return _FirstName;
	}

	// _LastName set/get
	void setLastName(string lastname)
	{
		_LastName = lastname;
	}
	string getLastName()
	{
		return _LastName;
	}

	// get fullname
	string getFullName()
	{
		return _FirstName + ' ' + _LastName;
	}


	// _NationalId set/get
	void setNationalId(string NId)
	{
		_NationalId = NId;
	}
	string getNationalId()
	{
		return _NationalId;
	}

};



int main()
{
	clsPerson Person;

	Person.setFirstName("Mahmoud");
	Person.setLastName("Gad");
	Person.setNationalId("29709101204993");

	cout << "- First Name  : " << Person.getFirstName() << endl;
	cout << "- Last Name   : " << Person.getLastName() << endl;
	cout << "- Full Name   : " << Person.getFullName() << endl;
	cout << "- National Id : " << Person.getNationalId() << endl;

	cout << "\n\n";

	return 0;
}