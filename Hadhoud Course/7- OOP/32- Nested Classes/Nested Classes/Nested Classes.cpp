#include <iostream>

using namespace std;



// Nested or Inner Classes : A class can also contain another class definition inside itself, which is called “Inner Class” in C++.

// In the case of nested of inner classes, the containing class is referred to as the “Enclosing Class”.
// The Inner Class definition is considered to be a member of the Enclosing Class.

// An Inner class is a member and as such has the same access rights as any other member of the enclosure class.

// The members of an enclosing class have no special access to members of a nested class; the usual access rules shall be obeyed.


class clsPerson
{
private:

	class clsAddress
	{
	private:

		string _AddressLine;
		string _City;
		string _Country;

	public:
		clsAddress() {}

		clsAddress(string AL, string City, string Country) :
			_AddressLine(AL), _City(City), _Country(Country) {}

		void setAddressLine(const string& AL)
		{
			_AddressLine = AL;
		}
		string getAddressLine()
		{
			return _AddressLine;
		}

		__declspec(property(get = getAddressLine, put = setAddressLine)) string AddressLine;

		void setCity(const string& City)
		{
			_City = City;
		}
		string getCity()
		{
			return _City;
		}

		__declspec(property(get = getCity, put = setCity)) string City;

		void setCountry(const string& Country)
		{
			_Country = Country;
		}
		string getCountry()
		{
			return _Country;
		}

		__declspec(property(get = getCountry, put = setCountry)) string Country;

		void PrintAddress()
		{
			cout << "Address:\n";
			cout << "--------\n";
			cout << "Address Line-> " << _AddressLine << '\n';
			cout << "City-> " << _City << '\n';
			cout << "Country-> " << _Country << '\n';
		}
	};

	string _FullName;
	clsAddress _Address;
	static unsigned int _PersonCount;

public:

	clsPerson(string FN, string AL, string City, string Country) :
		_FullName(FN), _Address(AL, City, Country) {
		++_PersonCount;
	}

	void setFullName(const string& FullName)
	{
		_FullName = FullName;
	}
	string getFullName()
	{
		return _FullName;
	}

	__declspec(property(get = getFullName, put = setFullName)) string FullName;

	void PrintAddress()
	{
		_Address.PrintAddress();
	}

	void PrintInfo()
	{
		cout << "\n\nPerson" << _PersonCount << " Info:\n";
		cout << "-------------\n";
		cout << "FullName-> " << _FullName << '\n';
		cout << "Address-> " << _Address.AddressLine;
		cout << " - " << _Address.City;
		cout << " - " << _Address.Country << '\n';
	}
};

unsigned int clsPerson::_PersonCount = 0;


int main()
{
	// 2 methods to creat an object:

	// [1] method 1
	clsPerson Person1("Mahmoud Abdelrahman Ismail Gad", "Alhantery st - Mansoura Qism 1", "Mansoura", "Egypt");

	Person1.PrintInfo();

	// [2] method 2
	clsPerson Person2 = clsPerson("Amira Abdelrahman Ismail Gad", "Alhantery st - Mansoura Qism 1", "Mansoura", "Egypt");

	Person2.PrintInfo();



	return 0;
}