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


//******************************************Tools************************************************
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

void ShowClientCard(sClient Client)
{
	cout << "\n\n-> The Following Is The Client Details:\n";
	cout << "------------------------------------------------------------------\n\n";
	cout << "-- Account Number----: " << Client.Account_Number << '\n';
	cout << "-- Name--------------: " << Client.Name << '\n';
	cout << "-- Phone Number------: " << Client.Phone_number << '\n';
	cout << "-- PIN_code----------: " << Client.PIN_Code << '\n';
	cout << "-- Account_Balance---: " << Client.Account_Balance << '$';
	cout << "\n\n------------------------------------------------------------------\n";
}

sClient ClientDataLineToRecords(const string& LineData, const char* delim = "#//#")
{
	sClient Client;

	vector <string> vRecords = Split_String(LineData, delim);

	Client.Account_Number = vRecords[0];
	Client.Name = vRecords[1];
	Client.Phone_number = vRecords[2];
	Client.PIN_Code = stoi(vRecords[3]);
	Client.Account_Balance = stoul(vRecords[4]);

	return Client;
}

string ClientRecordsToDataLine(const sClient& Client, const char* Seperator = "#//#")
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
				File << ClientRecordsToDataLine(Client) << endl;
		}
		File.close();
	}
}
//***********************************************************************************************


//**********************Show Clients List**************************
void ShowClientsListHeader(unsigned short NumberOfClients)
{
	cout << "_____________________________________________________________________________________________________________\n\n";
	cout << "\t\t\t\t\tClients List Of (" << NumberOfClients << ") Client(s)\n";
	cout << "_____________________________________________________________________________________________________________\n\n";

	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(10) << "PIN Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(20) << "Phone no.";
	cout << "| " << left << setw(20) << "Balance($)";

	cout << "\n_____________________________________________________________________________________________________________\n\n";
}

void PrintClientRecord(const sClient& Client)
{
	cout << "| " << left << setw(15) << Client.Account_Number;
	cout << "| " << left << setw(10) << Client.PIN_Code;
	cout << "| " << left << setw(40) << Client.Name;
	cout << "| " << left << setw(20) << Client.Phone_number;
	cout << "| " << left << setw(20) << Client.Account_Balance;
	cout << endl;
}

void ListAllClients(const vector <sClient>& vClients)
{
	system("cls");

	ShowClientsListHeader(vClients.size());

	for (const sClient& Client : vClients)
		PrintClientRecord(Client);

	cout << "_____________________________________________________________________________________________________________\n\n";
}
//*****************************************************************



//******************************Find Clients***************************************
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
bool FindClientByAccountNumber(string AccountNumber, vector <sClient> vClients)
{
	for (const sClient& Client : vClients)
	{
		if (Client.Account_Number == AccountNumber)
			return true;
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
bool FindClientByAccountNumber(string AccountNumber, vector <sClient> vClients, sClient& Client, unsigned short& ClientIndex)
{
	unsigned short NumberOfClients = vClients.size();

	for (unsigned short Index = 0; Index < NumberOfClients; Index++)
	{
		if (vClients[Index].Account_Number == AccountNumber)
		{
			Client = vClients[Index];
			ClientIndex = Index;
			return true;
		}
	}
	return false;
}

void ShowFindClientsScreen()
{
	system("cls");
	cout << "------------------------\n";
	cout << "-- Search For Clients --";
	cout << "\n------------------------\n\n";
}

void FindAndShowClientCard(vector <sClient> vClients)
{
	sClient Client;
	bool SearchAgain = false;
	string AccountNumber;

	do
	{
		ShowFindClientsScreen();

		AccountNumber = ReadTxt("-> Please, Enter The Account Number: ");

		if (FindClientByAccountNumber(AccountNumber, vClients, Client))
			ShowClientCard(Client);
		else
			cout << "\n\n-> Sorry, Client With Account Number (" << AccountNumber << ") Not Found :-(";

		SearchAgain = Read_YesOrNo_FromUser("\n\n-> Do you want to search again?");

	} while (SearchAgain);
}
//********************************************************************************


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
		cout << "\n\nUnable to open the file!\n\n";
	}
}

sClient ReadNewClientData()
{
	sClient NewClient;

	NewClient.Account_Number = ReadTxt("\n\n-> Enter The Account Number:  ");

	while (FindClientByAccountNumber(NewClient.Account_Number, NewClient))
	{
		cout << "\n- Client with Account Number [" << NewClient.Account_Number << "] already exists, ";
		cout << "Enter another client number:  ";
		getline(cin, NewClient.Account_Number);
	}

	cout << "-> Enter The Name:  ";
	getline(cin, NewClient.Name);

	cout << "-> Enter The Phone Number:  ";
	getline(cin, NewClient.Phone_number);

	NewClient.PIN_Code = Read_Positive_Int_Number(4, "-> Enter The PIN Code {4 Digits}:  ");
	NewClient.Account_Balance = Read_Positive_Int_Number("-> Enter The Account Balance:  ");

	return NewClient;
}

void AddNewClient()
{
	sClient Client = ReadNewClientData();
	string DataLine = ClientRecordsToDataLine(Client);

	AddDataLineToFile(ClientsFileName, DataLine);
}

void ShowAddNewClientsScreen()
{
	system("cls");
	cout << "------------------------\n";
	cout << "-- Adding New Clients --";
	cout << "\n------------------------";
}

void AddNewClients(vector <sClient>& vClients)
{
	bool AddMore = false;

	do
	{
		ShowAddNewClientsScreen();

		// Check Client by Account Number Before Adding
		AddNewClient();

		// update vClients after adding new clients
		vClients = LoadClientsDataFromFile(ClientsFileName);

		AddMore = Read_YesOrNo_FromUser("\n\n-> Client added successfully, Do you want to add more clients?");

	} while (AddMore);
}
//*****************************************************************



//**********************************Delete Client*********************************************

//__________________________________________Not used______________________________________________________
void MarkClientForDeleteByAccountNumber(const string& AccountNumber, vector <sClient>& vClients)
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
//________________________________________________________________________________________________________

void DeleteClientByAccountNumber(const string& AccountNumber, vector <sClient>& vClients)
{
	sClient Client;
	unsigned short ClientIndex;

	if (FindClientByAccountNumber(AccountNumber, vClients, Client, ClientIndex))
	{
		ShowClientCard(Client);

		bool Delete = Read_YesOrNo_FromUser("\n\n-> Are you sure you want to delete this client?");

		if (Delete)
		{
			vClients[ClientIndex].DeleteFlag = true; // Prepare client for delete

			SaveClientsDataToFile(ClientsFileName, vClients);

			// Update & Refresh vClients vector after deletion
			vClients = LoadClientsDataFromFile(ClientsFileName);

			cout << "\n\n-> Client Deleted Successfully.\n\n";
		}
	}
	else
	{
		cout << "\n\n-> Sorry, Client With Account Number (" << AccountNumber << ") Not Found :-(";
	}
}

void ShowDeleteClientsScreen()
{
	system("cls");
	cout << "--------------------\n";
	cout << "-- Delete Clients --";
	cout << "\n--------------------\n\n";
}

void DeleteClients(vector <sClient>& vClients)
{
	bool deleteMore = false;
	string AccountNumber;

	do
	{
		ShowDeleteClientsScreen();

		cout << "-> Enter The Account Number:  ";
		getline(cin >> ws, AccountNumber);

		DeleteClientByAccountNumber(AccountNumber, vClients);

		deleteMore = Read_YesOrNo_FromUser("\n\n-> Do you want to delete more clients?");

	} while (deleteMore);
}

//********************************************************************************************



//***********************************Update Clients*******************************************
sClient UpdateClientRecord(string AccountNumber)
{
	sClient Client;

	// Update all record except 'Account Number'

	Client.Account_Number = AccountNumber;

	cout << "\n-> Enter The Name:  ";
	getline(cin >> ws, Client.Name);

	cout << "-> Enter The Phone Number:  ";
	getline(cin, Client.Phone_number);

	Client.PIN_Code = Read_Positive_Int_Number(4, "-> Enter The PIN Code {4 Digits}: ");
	Client.Account_Balance = Read_Positive_Int_Number("-> Enter The Account Balance: ");

	return Client;
}

void UpdateClientDataByAccountNumber(const string& AccountNumber, vector <sClient>& vClients)
{
	sClient Client;
	unsigned short ClientIndex = 0;

	if (FindClientByAccountNumber(AccountNumber, vClients, Client, ClientIndex))
	{
		ShowClientCard(Client);

		bool Update = Read_YesOrNo_FromUser("\n\n-> Are you sure you want to update this client data?");

		if (Update)
		{
			vClients[ClientIndex] = UpdateClientRecord(AccountNumber);

			SaveClientsDataToFile(ClientsFileName, vClients);

			cout << "\n\n-> Client Updated Successfully.\n\n";
		}
	}
	else
	{
		cout << "\n\n-> Sorry, Client With Account Number (" << AccountNumber << ") Not Found :-(\n\n";
	}
}

void ShowUpdateClientsScreen()
{
	system("cls");
	cout << "-------------------------\n";
	cout << "-- Update Clients Data --";
	cout << "\n-------------------------\n\n";
}

void UpdateClientData(vector <sClient>& vClients)
{
	bool UpdateMore = false;
	string AccountNumber;

	do
	{
		ShowUpdateClientsScreen();

		cout << "-> Enter The Account Number:  ";
		getline(cin >> ws, AccountNumber);

		UpdateClientDataByAccountNumber(AccountNumber, vClients);

		UpdateMore = Read_YesOrNo_FromUser("\n\n-> Do you want to update more clients?");

	} while (UpdateMore);
}
//********************************************************************************************



//_______________________________________________________________________________________________________________
//_______________________________________________________________________________________________________________
//_______________________________________________________________________________________________________________

enum MainMenuOptions
{
	Show_Client_List = 1,
	Add_New_Client = 2,
	Delete_Client = 3,
	Update_Client_Info = 4,
	Find_Client = 5,
	Exit = 6
};

void MainMenuScreen()
{
	system("cls");
	cout << "====================================================================\n";
	cout << "\t\t\tMain Menu Screen";
	cout << "\n====================================================================\n";
	cout << "\t\t[1] Show Clients List.\n";
	cout << "\t\t[2] Add New Client.\n";
	cout << "\t\t[3] Delete Client.\n";
	cout << "\t\t[4] Update Client Info.\n";
	cout << "\t\t[5] Find Client.\n";
	cout << "\t\t[6] Exit.\n";
	cout << "====================================================================\n";
}

void BackToMainMenu()
{
	cout << "\n\n- Press any key to go back to main menue.....";
	system("pause>0"); // or you can use { cin.get() }
}

void ShowEndScreen()
{
	system("cls");

	cout << "----------------------------------------------------------------\n";
	cout << "-------------------- Program Ends See You :-) ------------------";
	cout << "\n----------------------------------------------------------------\n\n";
}


MainMenuOptions ChooseFromMainMenu()
{
	return (MainMenuOptions)Read_Positive_Number_InRange(1, 6, "- Choose what do you want to do? [1 to 6]? ");
}

bool MainProcess(MainMenuOptions UserChoice)
{
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

	switch (UserChoice)
	{
	case Show_Client_List:
		ListAllClients(vClients);
		BackToMainMenu();
		return false;

	case Add_New_Client:
		AddNewClients(vClients);
		BackToMainMenu();
		return false;

	case Delete_Client:
		DeleteClients(vClients);
		BackToMainMenu();
		return false;

	case Update_Client_Info:
		UpdateClientData(vClients);
		BackToMainMenu();
		return false;

	case Find_Client:
		FindAndShowClientCard(vClients);
		BackToMainMenu();
		return false;

	case Exit:
		ShowEndScreen();
		return true;
	}
}

void Bank()
{
	bool Exit = false;

	while (!Exit)
	{
		MainMenuScreen();

		Exit = MainProcess(ChooseFromMainMenu());
	}
}


int main(void)
{
	Bank();

	return 0;
}