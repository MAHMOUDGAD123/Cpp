#include <iostream>

using namespace std;


class clsPerson
{
private:
	string _ID;
	string _FullName;
	string _Email;
	string _Phone;

public:
	clsPerson(string ID, string FullName, string Email, string Phone)
	{
		_ID = ID;
		_FullName = FullName;
		_Email = Email;
		_Phone = Phone;
	}

	string getID()
	{
		return _ID;
	}
	__declspec(property(get = getID)) string ID;

	void setFullName(string FullName)
	{
		_FullName = FullName;
	}
	string getFullName()
	{
		return _FullName;
	}
	__declspec(property(get = getFullName, put = setFullName)) string FullName;

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
		cout << "=> Person Info:";
		cout << "\n==============================================\n";
		cout << "- ID      : " << _ID;
		cout << "\n- FullName: " << _FullName;
		cout << "\n- Email   : " << _Email;
		cout << "\n- Phone   : " << _Phone;
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

int main()
{
	clsPerson MG("A111", "Mahmoud Gad", "hooda.gad333@gmail.com", "+201097890670");

	MG.Print();

	MG.SendEmail("Just Say Hi :-)", "How are you my friend? hope to be good");
	MG.SendSMS("Hi, MG how are you man? where are you?");

	return 0;
}