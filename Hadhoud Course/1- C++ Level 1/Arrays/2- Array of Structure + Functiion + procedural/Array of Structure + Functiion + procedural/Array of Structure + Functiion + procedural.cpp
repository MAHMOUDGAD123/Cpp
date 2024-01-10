
#include <iostream>
#include <string>

using namespace std;

struct ClientInfo
{
	string FName;
	string LName;
	string Age;
	string PhoneNumber;

};

void ReadInfo(ClientInfo& Client)
{
	
	cout << "First name : ";
	cin >> Client.FName;
	cout << "\n";

	cout << "Last name : ";
	cin >> Client.LName;
	cout << "\n";

	cout << "Age : ";
	cin >> Client.Age;
	cout << "\n";

	cout << "Phone Number : ";
	cin >> Client.PhoneNumber;
	cout << "\n";


}


void PrintInfo(ClientInfo Client)
{
	cout << "*************************************" << endl;
	cout << "First name : " << Client.FName << endl;
	cout << "Last name : " << Client.LName << endl;
	cout << "Age : " << Client.Age << endl;
	cout << "Phone Number : " << Client.PhoneNumber << endl;
	cout << "*************************************" << endl;

}



void ReadClientsInfo(ClientInfo Client[100], int& NumberOfClients)
{

	cout << "Please enter the number of clients (max = 100) : ";
	cin >> NumberOfClients;
	cout << "\n\n";
	while (NumberOfClients > 100)
	{
		cout << "Maximum clients = 100\n\n";
		cout << "Please enter the number of clients (max = 100) : ";
		cin >> NumberOfClients;
		cout << "\n\n";
	}

	for (int i = 0; i < NumberOfClients; i++)
	{
		cout << "Please enter clients " << i + 1 << " Data \\\n" << endl;
		ReadInfo(Client[i]);
	}

}

void PrintClientsInfo(ClientInfo Client[100], int NumberOfClients)
{
	for (int i = 0; i < NumberOfClients; i++)
	{
		cout << "\nClient " << i + 1 << " \\" << endl;
		PrintInfo(Client[i]);
	}
	
}

int main()
{
	ClientInfo Client[100];
	int NumberOfClients;


	ReadClientsInfo(Client, NumberOfClients);
	PrintClientsInfo(Client, NumberOfClients);


	
	return 0;
}


