
#include <string>
#include <iostream>

using namespace std;


struct Information
{
	string FName;
	string LName;
	string age;
	string PhoneNumber;
	string NId;
	string Country;
	string City;

};


void ReadInfo(Information &info)
{
	cout << "Please we need some information." << endl;
	
	cout << "First Name : ";
	cin >> info.FName;
	cout << "\n";

	cout << "Last Name : ";
	cin >> info.LName;
	cout << "\n";

	cout << "age :";
	cin >> info.age;
	cout << "\n";

	cout << "Phone Number : ";
	cin >> info.PhoneNumber;
	cout << "\n";

	cout << "NId: ";
	cin >> info.NId;
	cout << "\n";

	cout << "Country : ";
	cin >> info.Country;
	cout << "\n";

	cout << "City : ";
	cin >> info.City;
	cout << "\n";

}


void PrintInfo(Information info)
{

	cout << "********************************************************" << endl;
	cout << "Full Name :" << info.FName + " " + info.LName << endl;
	cout << "age :" << info.age << endl;
	cout << "Phone number :" << info.PhoneNumber << endl;
	cout << "NId :" << info.NId << endl;
	cout << "Country :" << info.Country << endl;
	cout << "City :" << info.City << endl;
	cout << "********************************************************" << endl;

}



int main()
{
	Information myInfo;

	ReadInfo(myInfo);
	PrintInfo(myInfo);


	return 0;
}


