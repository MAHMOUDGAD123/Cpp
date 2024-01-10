#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include "MGLib.h"

using namespace std;
using namespace MGLib;


const char* ClientsFileName = "Clients.txt"; // Gobal variable

struct sClient_Data
{
	string Account_Number = "";
	string Name = "";
	string Phone_number = "";
	unsigned short PIN_Code = 0;
	unsigned long Account_Balance = 0;
};



sClient_Data Read_Client_Data()
{
	sClient_Data Client_Data;


	cout << "-> Enter The Account Number:  ";
	getline(cin >> ws, Client_Data.Account_Number);

	cout << "-> Enter The Name:  ";
	getline(cin, Client_Data.Name);

	cout << "-> Enter The Phone Number:  ";
	getline(cin, Client_Data.Phone_number);

	Client_Data.PIN_Code = Read_Positive_Int_Number(4, "-> Enter The PIN Code {4 Digits}: ");
	Client_Data.Account_Balance = Read_Positive_Int_Number("-> Enter The Account Balance: ");

	return Client_Data;
}

void Dispaly_Client_Data(sClient_Data Client_Data)
{
	cout << "\n\n---------------------------------------------------------------------------\n\n";
	cout << "-- Account Number:---- {  " << Client_Data.Account_Number << "  }" << "\n";
	cout << "-- Name:-------------- {  " << Client_Data.Name << "  }" << "\n";
	cout << "-- Phone Number:------ {  " << Client_Data.Phone_number << "  }" << "\n";
	cout << "-- PIN_code:---------- {  " << Client_Data.PIN_Code << "  }" << "\n";
	cout << "-- Account_Balance:--- {  " << fixed << Client_Data.Account_Balance << "  }";
	cout << "\n\n---------------------------------------------------------------------------\n\n";
}

sClient_Data ClientDataLineToRecords(const string& LineData, const char* delim = "#//#")
{
	sClient_Data Client_Data;

	vector <string> vRecords = Split_String(LineData, delim);;

	Client_Data.Account_Number = vRecords[0];
	Client_Data.Name = vRecords[1];
	Client_Data.Phone_number = vRecords[2];
	Client_Data.PIN_Code = stoi(vRecords[3]);
	Client_Data.Account_Balance = stoul(vRecords[4]);

	return Client_Data;
}

string ClientRecordsToDataLine(sClient_Data Client_Data, const char* Seperator = "#//#")
{
	string Record = "";

	Record += Client_Data.Account_Number + Seperator;
	Record += Client_Data.Name + Seperator;
	Record += Client_Data.Phone_number + Seperator;
	Record += to_string(Client_Data.PIN_Code) + Seperator;
	Record += to_string(Client_Data.Account_Balance);

	return Record;
}

void AddDataLineToFile(const char* FileName, const string& DataLine)
{
	ofstream Clients(FileName, ios::out | ios::app);

	if (Clients.is_open())
	{
		Clients << DataLine << endl;
		Clients.close();
	}
	else
	{
		cout << "\nUnable to open the file!\n";
	}
}

void AddNewClient()
{
	sClient_Data Client = Read_Client_Data();
	AddDataLineToFile(ClientsFileName, ClientRecordsToDataLine(Client));
}

void AddClients()
{
	bool AddMore = false;

	do
	{
		system("cls");

		cout << "-----------------------\n";
		cout << "-- Adding new client --";
		cout << "\n-----------------------\n\n";

		AddNewClient();

		AddMore = Read_Bool_Input("\n\n-> Client added successfully, Do you want to add more clients?");

	} while (AddMore);
}

void ReadClientsFile(const char* FileName)
{
	ifstream Clients(FileName);
	string DataLine;

	if (Clients.is_open())
	{
		while (getline(Clients, DataLine))
			cout << "-> " << DataLine << endl;

		Clients.close();
	}
	cout << "\n\n";
}



int main(void)
{
	AddClients();

	cout << "\n\n-------------\n\n";
	cout << "Clients Data:\n";
	cout << "-------------\n\n";
	ReadClientsFile(ClientsFileName);


	return 0;
}