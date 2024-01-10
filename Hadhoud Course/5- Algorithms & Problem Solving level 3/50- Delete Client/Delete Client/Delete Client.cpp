#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include "MGLib.h"

using namespace std;
using namespace MGLib;


const char* ClientsFileName = "Clients.txt"; // Gobal variable

struct sClient
{
	string Account_Number = "";
	string Name = "";
	string Phone_number = "";
	unsigned short PIN_Code = 0;
	unsigned long Account_Balance = 0;
	bool DeleteFlag = false;
};



unsigned short CountRecordsInFile(const char* FileName)
{
	// Count lines in the file

	unsigned short NumberOfRecords = 0;
	string Line;

	ifstream File(FileName);

	if (File.is_open())
	{
		while (getline(File, Line))
			NumberOfRecords++;

		File.close();
	}

	return NumberOfRecords;
}

sClient Read_Client_Data()
{
	sClient Client_Data;


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

void DispalyClientCard(sClient Client_Data)
{
	cout << "\n\n-> The Following Is The Client Details:\n";
	cout << "------------------------------------------------------------------\n\n";
	cout << "-- Account Number----: " << Client_Data.Account_Number << '\n';
	cout << "-- Name--------------: " << Client_Data.Name << '\n';
	cout << "-- Phone Number------: " << Client_Data.Phone_number << '\n';
	cout << "-- PIN_code----------: " << Client_Data.PIN_Code << '\n';
	cout << "-- Account_Balance---: " << Client_Data.Account_Balance;
	cout << "\n\n------------------------------------------------------------------\n";
}

sClient ClientDataLineToRecords(const string& LineData, const char* delim = "#//#")
{
	sClient Client;

	vector <string> vRecords = Split_String(LineData, delim);;

	Client.Account_Number = vRecords[0];
	Client.Name = vRecords[1];
	Client.Phone_number = vRecords[2];
	Client.PIN_Code = stoi(vRecords[3]);
	Client.Account_Balance = stoul(vRecords[4]);

	return Client;
}

string ClientRecordsToDataLine(sClient Client, const char* Seperator = "#//#")
{
	string Record = "";

	Record += Client.Account_Number + Seperator;
	Record += Client.Name + Seperator;
	Record += Client.Phone_number + Seperator;
	Record += to_string(Client.PIN_Code) + Seperator;
	Record += to_string(Client.Account_Balance);

	return Record;
}

vector <sClient> LoadClientsDataFromFile(const char* FileName)
{
	vector <sClient> vClients;

	ifstream File(FileName); // read mode by default

	if (File.is_open())
	{
		string Line;

		while (getline(File, Line))
			vClients.push_back(ClientDataLineToRecords(Line));

		File.close();
	}

	return vClients;
}

void SaveClientsDataToFile(const char* FileName, const vector <sClient>& vClients)
{
	ofstream File(FileName);

	if (File.is_open())
	{
		for (const sClient& Client : vClients)
		{
			// Only add Clients with 'false' delete flag
			if (Client.DeleteFlag == false)
			{
				File << ClientRecordsToDataLine(Client) << endl;
			}
		}
		File.close();
	}
}


//******************************Add Data***************************
void AddDataLineToFile(const char* FileName, const string& DataLine)
{
	fstream File(FileName, ios::out | ios::app);

	if (File.is_open())
	{
		if (DataLine != "")
			File << DataLine << endl;

		File.close();
	}
	else
	{
		cout << "\nUnable to open the file!\n";
	}
}

void AddNewClient()
{
	sClient Client = Read_Client_Data();
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
//*****************************************************************



//**********************Show Clients List**************************
void ShowClientsListHeader(unsigned short NumberOfClients)
{
	cout << "\n\n_____________________________________________________________________________________________________________\n\n";
	cout << "\t\t\t\t\tClients List Of (" << NumberOfClients << ") Client(s)\n";
	cout << "_____________________________________________________________________________________________________________\n\n";

	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(10) << "PIN Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(20) << "Phone no.";
	cout << "| " << left << setw(20) << "Balance";

	cout << "\n_____________________________________________________________________________________________________________\n\n";
}

void PrintClientRecord(sClient Client)
{
	cout << "| " << left << setw(15) << Client.Account_Number;
	cout << "| " << left << setw(10) << Client.PIN_Code;
	cout << "| " << left << setw(40) << Client.Name;
	cout << "| " << left << setw(20) << Client.Phone_number;
	cout << "| " << left << setw(20) << Client.Account_Balance;
	cout << endl;
}

void ShowAllClientsList(vector <sClient> vClients)
{
	ShowClientsListHeader(vClients.size());

	for (const sClient& Client : vClients)
		PrintClientRecord(Client);

	cout << "_____________________________________________________________________________________________________________\n\n";
}
//*****************************************************************



//**************************Find Clients***************************************
bool FindClientByAccountNumber(string AccountNumber, sClient& Client)
{
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

	for (const sClient& _Client : vClients)
	{
		if (_Client.Account_Number == AccountNumber)
		{
			Client = _Client;
			return true;
		}
	}
	return false;
}
bool FindClientByAccountNumber(string AccountNumber, vector <sClient> vClients, sClient& Client)
{
	for (const sClient& _Client : vClients)
	{
		if (_Client.Account_Number == AccountNumber)
		{
			Client = _Client;
			return true;
		}
	}
	return false;
}

void FindAndDisplayClientCard()
{
	sClient Client;
	string AccountNumber = ReadTxt("-> Please, Enter The Account Number: ");

	if (FindClientByAccountNumber(AccountNumber, Client))
		DispalyClientCard(Client);
	else
		cout << "\n\n-> Sorry, Client With Account Number (" << AccountNumber << ") Not Found :-(\n\n";
}
//*****************************************************************************



//**********************************Delete Client*********************************************
void MarkClientForDeleteByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
	for (sClient& Client : vClients)
	{
		if (Client.Account_Number == AccountNumber)
		{
			Client.DeleteFlag = true;
			break;
		}
	}
}

void DeleteClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
	sClient Client;

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		DispalyClientCard(Client);

		bool Delete = Read_YesOrNo_FromUser("\n\n-> Are you sure you want to delete this client?");

		if (Delete)
		{
			MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
			SaveClientsDataToFile(ClientsFileName, vClients);
			
			// Update & Refresh vClients vector after deletion
			vClients = LoadClientsDataFromFile(ClientsFileName);

			cout << "\n\n-> Client Deleted Successfully.\n\n";
		}

	}
	else
	{
		cout << "\n\n-> Sorry, Client With Account Number (" << AccountNumber << ") Not Found :-(\n\n";
	}
}

void FindAndDeleteClient()
{
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	string AccountNumber = ReadTxt("\n\n-> Please, Enter The Account Number: ");

	DeleteClientByAccountNumber(AccountNumber, vClients);
}
//********************************************************************************************

int main(void)
{
	AddClients();

	ShowAllClientsList(LoadClientsDataFromFile(ClientsFileName));

	FindAndDeleteClient();

	ShowAllClientsList(LoadClientsDataFromFile(ClientsFileName));

	return 0;
}