#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include "MGLib.h"

using namespace std;
using namespace MGLib;



struct sClient
{
	string Account_Number = "";
	string Name = "";
	string Phone_number = "";
	unsigned short PIN_Code = 0;
	unsigned long Account_Balance = 0;
	bool DeleteFlag = false;
	bool AccountLockedFlag = false;
};

struct sUser
{
	string UserName = "";
	string UserPassword = "";
	int Permissions = 0;
	bool DeleteFlag = false;
};

static const char* ClientsFileName = "Clients.txt"; // Gobal variable
static const char* UsersFileName = "Users.txt"; // Gobal variable

sUser CurrentUser; // Global Variable





//******************************************Tools************************************************
//***********************************************************************************************
void ShowEndScreen()
{
	system("cls");
	cout << "----------------------------------------------------------------\n";
	cout << "-------------------- Program Ends See You :-) ------------------";
	cout << "\n----------------------------------------------------------------\n\n";
}

short ReadUserChoice(short from, short to, const char* Message = "")
{
	short Number = 0; // positive integer number
	cout << Message;
	cin >> Number;

	while (cin.fail() || Number < from || Number > to)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << Message;
		cin >> Number;
	}

	// to discard any non_numerics in the end of input
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return Number;
}

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

void AddDataLineToFile(const char* FileName, const string& DataLine)
{
	fstream File(FileName, ios::out | ios::app);

	if (File.is_open())
	{
		if (DataLine != "")
			File << DataLine << '\n';

		File.close();
	}
	else
	{
		cout << "\n\nUnable to open the file!\n\n";
	}

	return;
}

void ShowClientCard(sClient Client)
{
	cout << "\n\n-> The Following Is The Client Details:\n";
	cout << "------------------------------------------------------------------\n\n";
	cout << "-- Account Number----: " << Client.Account_Number << '\n';
	cout << "-- Name--------------: " << Client.Name << '\n';
	cout << "-- Phone Number------: " << Client.Phone_number << '\n';
	cout << "-- PIN_code----------: " << Client.PIN_Code << '\n';
	cout << "-- Account_Balance---: " << Client.Account_Balance << " $\n";
	cout << "-- Locked Flag-------: " << Client.AccountLockedFlag;
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
	Client.AccountLockedFlag = stoi(vRecords[5]);

	return Client;
}
sUser UserDataLineToRecords(const string& LineData, const char* delim = "#//#")
{
	sUser User;
	vector <string> vRecords = Split_String(LineData, delim);

	User.UserName = vRecords[0];
	User.UserPassword = vRecords[1];
	User.Permissions = stoi(vRecords[2]);

	return User;
}

string ClientRecordsToDataLine(const sClient& Client, const char* Seperator = "#//#")
{
	string Record = "";

	Record += Client.Account_Number + Seperator;
	Record += Client.Name + Seperator;
	Record += Client.Phone_number + Seperator;
	Record += to_string(Client.PIN_Code) + Seperator;
	Record += to_string(Client.Account_Balance) + Seperator;
	Record += to_string(Client.AccountLockedFlag);

	return Record;
}
string UserRecordsToDataLine(const sUser& User, const char* Seperator = "#//#")
{
	string Record = "";

	Record += User.UserName + Seperator;
	Record += User.UserPassword + Seperator;
	Record += to_string(User.Permissions);
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
			if (Line != "")
				vClients.push_back(ClientDataLineToRecords(Line));

		File.close();
	}
	return vClients;
}
vector <sUser> LoadUsersDataFromFile(const char* FileName)
{
	vector <sUser> vUsers;
	ifstream File(FileName); // read mode by default

	if (File.is_open())
	{
		string Line;

		while (getline(File, Line))
			if (Line != "")
				vUsers.push_back(UserDataLineToRecords(Line));

		File.close();
	}
	return vUsers;
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
				File << ClientRecordsToDataLine(Client) << '\n';
		}
		File.close();
	}
}
void SaveUsersDataToFile(const char* FileName, const vector <sUser>& vUsers)
{
	ofstream File(FileName);

	if (File.is_open())
	{
		for (const sUser& User : vUsers)
		{
			// Only add Clients with 'false' delete flag
			if (User.DeleteFlag == false)
				File << UserRecordsToDataLine(User) << '\n';
		}
		File.close();
	}
}
//***********************************************************************************************
//***********************************************************************************************


//***************************Show Clients List*******************************
//***************************************************************************
void ShowClientsListHeader(const unsigned short& NumberOfClients)
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
//***************************************************************************
//***************************************************************************



//******************************Find Clients**************************************
//********************************************************************************
bool FindClientByAccountNumber(const string& AccountNumber)
{
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

	for (const sClient& Client : vClients)
		if (Client.Account_Number == AccountNumber)
			return true;

	return false;
}
bool FindClientByAccountNumber(const string& AccountNumber, sClient& Client)
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
bool FindClientByAccountNumber(const string& AccountNumber, const vector <sClient>& vClients)
{
	for (const sClient& Client : vClients)
	{
		if (Client.Account_Number == AccountNumber)
			return true;
	}
	return false;
}
bool FindClientByAccountNumber(const string& AccountNumber, const vector <sClient>& vClients, unsigned short& ClientIndex)
{
	unsigned short NumberOfClients = vClients.size();

	for (unsigned short Index = 0; Index < NumberOfClients; Index++)
	{
		if (vClients[Index].Account_Number == AccountNumber)
		{
			ClientIndex = Index;
			return true;
		}
	}
	return false;
}
bool FindClientByAccountNumber(const string& AccountNumber, const vector <sClient>& vClients, sClient& Client)
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
bool FindClientByAccountNumber(const string& AccountNumber, const vector <sClient>& vClients, sClient& Client, unsigned short& ClientIndex)
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

void FindAndShowClientCard(const vector <sClient>& vClients)
{
	unsigned short ClientIndex;
	string AccountNumber;

	do
	{
		ShowFindClientsScreen();

		AccountNumber = ReadTxt("-> Please, Enter The Account Number: ");

		if (FindClientByAccountNumber(AccountNumber, vClients, ClientIndex))
			ShowClientCard(vClients[ClientIndex]);
		else
			cout << "\n\n-> Sorry, Client With Account Number (" << AccountNumber << ") Not Found :-(";

	} while (Read_YesOrNo("\n\n-> Do you want to search again?"));
}
//********************************************************************************
//********************************************************************************




//******************************Add Clients****************************
//*********************************************************************

short Read_PIN(short NumberOfDigits, const char* Message = "")
{
	short Number = 0;

	cout << Message;
	cin >> Number;

	while (cin.fail() || Number < 0 || !Check_HowManyDigits(Number, NumberOfDigits))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "-> Please, Enter A PIN Of " << NumberOfDigits << " Digits:  ";
		cin >> Number;
	}

	return Number;
}

long long Read_Balance(const char* Message = "")
{
	long long Number = 0; // integer number

	cout << Message;
	cin >> Number;

	while (cin.fail() || Number < 0)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "-> Enter A Valid Balance:  ";
		cin >> Number;
	}

	// to discard any non_numerics in the end of input
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return Number;
}

sClient ReadNewClientData()
{
	sClient NewClient;

	cout << "\n\n-> Enter The Account Number:  ";
	getline(cin >> ws, NewClient.Account_Number);

	while (FindClientByAccountNumber(NewClient.Account_Number, NewClient))
	{
		cout << "\n- Client With Account Number [" << NewClient.Account_Number << "] Already Exists, ";
		cout << "Enter Another Client Number:  ";
		getline(cin, NewClient.Account_Number);
	}

	cout << "-> Enter The Name:  ";
	getline(cin, NewClient.Name);

	cout << "-> Enter The Phone Number:  ";
	getline(cin, NewClient.Phone_number);

	NewClient.PIN_Code = Read_PIN(4, "-> Enter The PIN Code {4 Digits}:  ");
	NewClient.Account_Balance = Read_Balance("-> Enter The Account Balance:  ");
	NewClient.AccountLockedFlag = false;

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
	do
	{
		ShowAddNewClientsScreen();

		// Check Client by Account Number Before Adding
		AddNewClient();

		// update vClients after adding new clients
		vClients = LoadClientsDataFromFile(ClientsFileName);

	} while (Read_YesOrNo("\n\n-> Client added successfully, Do you want to add more clients?"));
}
//*********************************************************************
//*********************************************************************



//**********************************Delete Client*********************************************
//********************************************************************************************

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
	unsigned short ClientIndex;

	if (FindClientByAccountNumber(AccountNumber, vClients, ClientIndex))
	{
		ShowClientCard(vClients[ClientIndex]);

		bool Delete = Read_YesOrNo("\n\n-> Are you sure you want to delete this client?");

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
	string AccountNumber;

	do
	{
		ShowDeleteClientsScreen();

		cout << "-> Enter The Account Number:  ";
		getline(cin >> ws, AccountNumber);

		DeleteClientByAccountNumber(AccountNumber, vClients);

	} while (Read_YesOrNo("\n\n-> Do you want to delete more clients?"));
}
//********************************************************************************************
//********************************************************************************************



//***********************************Update Clients*******************************************
//********************************************************************************************
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
	Client.AccountLockedFlag = false;

	return Client;
}

void UpdateClientDataByAccountNumber(const string& AccountNumber, vector <sClient>& vClients)
{
	unsigned short ClientIndex = 0;

	if (FindClientByAccountNumber(AccountNumber, vClients, ClientIndex))
	{
		ShowClientCard(vClients[ClientIndex]);

		bool Update = Read_YesOrNo("\n\n-> Are You Sure You Want To Update This Client Data?");

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
	string AccountNumber;

	do
	{
		ShowUpdateClientsScreen();

		cout << "-> Enter The Account Number:  ";
		getline(cin >> ws, AccountNumber);

		UpdateClientDataByAccountNumber(AccountNumber, vClients);

	} while (Read_YesOrNo("\n\n-> Do you want to update more clients?"));
}
//********************************************************************************************
//********************************************************************************************



//_______________________________________________________________________________________________________________
//_______________________________________________________________________________________________________________
//_______________________________________________________________________________________________________________


enum enTransactionMenuOptions
{
	Deposit = 1,
	Withdraw = 2,
	Money_Transfer = 3,
	Total_Balances = 4,
	Main_Menu = 5
};


//***********************************Transactions*********************************************
//********************************************************************************************

enTransactionMenuOptions ChooseATransaction()
{
	return (enTransactionMenuOptions)ReadUserChoice(1, 5, "- Choose what do you want to do? [1 to 5]? ");
}

void TransactionsMenuScreen()
{
	system("cls");
	cout << "=============================================================\n";
	cout << "\t\t\tTransaction Menu";
	cout << "\n=============================================================\n";
	cout << "\t\t[1] Deposit.\n";
	cout << "\t\t[2] Withdraw.\n";
	cout << "\t\t[3] Money Transfer (Client to Client).\n";
	cout << "\t\t[4] Total Balances.\n";
	cout << "\t\t[5] Main Menu.\n";
	cout << "=============================================================\n";
	return;
}

//--------------------------Deposit Transaction-------------------------
void ShowDepositScreen()
{
	system("cls");
	cout << "-------------------\n";
	cout << "-- Deposit Money --";
	cout << "\n-------------------\n\n";
}

void DepositMoney(unsigned long& ClientBalance)
{
	unsigned long DepositAmount = Read_Positive_Int_Number("\n\n-> Please, Enter The Deposit Amount:  ");

	if (Read_YesOrNo("\n\n-> Are You Sure You Want To Perform This Transaction?"))
	{
		ClientBalance += DepositAmount;
		cout << "\n\n-> Deposit Transaction Done Successfully, New Balance = ";
		cout << ClientBalance << "$.";
	}
}

void DepositTransaction(vector <sClient>& vClients)
{
	string AccountNumber;
	unsigned short ClientIndex;

	do
	{
		ShowDepositScreen();

		cout << "-> Please, Enter The Account Number:  ";
		getline(cin >> ws, AccountNumber);

		while (!FindClientByAccountNumber(AccountNumber, vClients, ClientIndex))
		{
			cout << "\n\n-> Sorry, Client With Account Number (" << AccountNumber << ") Not Found :-(";
			cout << "\n\n-> Please, Enter Another Account Number:  ";
			getline(cin >> ws, AccountNumber);
		}

		ShowClientCard(vClients[ClientIndex]);

		DepositMoney(vClients[ClientIndex].Account_Balance);

		SaveClientsDataToFile(ClientsFileName, vClients);

	} while (Read_YesOrNo("\n\n-> Do You Want To Deposit More Money?"));
}
//----------------------------------------------------------------------


//--------------------------Withdraw Transaction-------------------------
void ShowWithdrawScreen()
{
	system("cls");
	cout << "--------------------\n";
	cout << "-- Withdraw Money --";
	cout << "\n--------------------\n\n";
}

void WithdrawMoney(unsigned long& ClientBalance)
{
	unsigned long WithdrawAmount = Read_Positive_Int_Number("\n\n-> Please, Enter The Withdraw Amount:  ");

	while (WithdrawAmount > ClientBalance)
	{
		cout << "\n\n-> Amount Exceeds The Balance, You Can Withdraw Up To : " << ClientBalance << "$.";

		WithdrawAmount = Read_Positive_Int_Number("\n\n-> Please, Enter The Withdraw Amount:  ");
	}

	if (Read_YesOrNo("\n\n-> Are You Sure You Want To Perform This Transaction?"))
	{
		ClientBalance -= WithdrawAmount;
		cout << "\n\n-> Withdraw Transaction Done Successfully, New Balance = ";
		cout << ClientBalance << "$.";
	}
}

void WithdrawTransaction(vector <sClient>& vClients)
{
	string AccountNumber;
	unsigned short ClientIndex;

	do
	{
		ShowWithdrawScreen();

		cout << "-> Please, Enter The Account Number:  ";
		getline(cin >> ws, AccountNumber);

		while (!FindClientByAccountNumber(AccountNumber, vClients, ClientIndex))
		{
			cout << "\n\n-> Sorry, Client With Account Number (" << AccountNumber << ") Not Found :-("
				  << "\n\n-> Please, Enter Another Account Number:  ";
			getline(cin >> ws, AccountNumber);
		}

		ShowClientCard(vClients[ClientIndex]);

		WithdrawMoney(vClients[ClientIndex].Account_Balance);

		SaveClientsDataToFile(ClientsFileName, vClients);

	} while (Read_YesOrNo("\n\n-> Do You Want To Withdraw More Money?"));
}
//----------------------------------------------------------------------



//---------------------Transfer Money Between Clients-------------------
void ReadAccountNumberOfSenderAndReceiver(string& SenderAN, string& ReceiverAN, unsigned short& SenderIndex, unsigned short& ReceiverIndex, const vector <sClient>& vClients)
{
	cout << "\n\n-> Please, Enter The Account Number Of The Sender Client:  ";
	getline(cin >> ws, SenderAN);

	while (!FindClientByAccountNumber(SenderAN, vClients, SenderIndex))
	{
		cout << "\n\n-> Sorry, Client With Account Number (" << SenderAN << ") Not Found :-(";
		cout << "\n\n-> Please, Enter Another Account Number:  ";
		getline(cin, SenderAN);
	}

	ShowClientCard(vClients[SenderIndex]);

	cout << "\n\n-> Please, Enter The Account Number Of The Receiver Client:  ";
	getline(cin, ReceiverAN);

	while (!FindClientByAccountNumber(ReceiverAN, vClients, ReceiverIndex))
	{
		cout << "\n\n-> Sorry, Client With Account Number (" << ReceiverAN << ") Not Found :-(";
		cout << "\n\n-> Please, Enter Another Account Number:  ";
		getline(cin, ReceiverAN);
	}

	ShowClientCard(vClients[ReceiverIndex]);
}

void TransferMoney(unsigned short SenderIndex, unsigned short ReceiverIndex, vector <sClient>& vClients)
{
	unsigned long Amount = Read_Positive_Int_Number("\n\n-> Please, Enter The Money Amount:  ");

	while (Amount > vClients[SenderIndex].Account_Balance)
	{
		cout << "\n\n-> Amount Exceeds The Balance, You Can Withdraw Up To : " << vClients[SenderIndex].Account_Balance << "$.";

		Amount = Read_Positive_Int_Number("\n\n-> Please, Enter The Money Amount:  ");
	}

	if (Read_YesOrNo("\n\n-> Are You Sure You Want To Perform This Transaction?"))
	{
		vClients[SenderIndex].Account_Balance -= Amount;
		vClients[ReceiverIndex].Account_Balance += Amount;
		cout << "\n\n-> Transaction Done Successfully.\n\n";
		cout << "-> New Balance Of \"" << vClients[SenderIndex].Name << "\" = " << vClients[SenderIndex].Account_Balance << "$." << endl;
		cout << "-> New Balance Of \"" << vClients[ReceiverIndex].Name << "\" = " << vClients[ReceiverIndex].Account_Balance << "$." << endl;
	}

	cout << "\n\n-> Press Any Key To Back To Transaction Menu Screen...";
	system("pause>0");
}

void ClientToClientMoneyTransfer(vector <sClient>& vClients)
{
	string SenderAccountNumber, ReceiverAccountNumber;
	unsigned short SenderIndex, ReceiverIndex;

	ReadAccountNumberOfSenderAndReceiver(SenderAccountNumber, ReceiverAccountNumber, SenderIndex, ReceiverIndex, vClients);

	TransferMoney(SenderIndex, ReceiverIndex, vClients);

	SaveClientsDataToFile(ClientsFileName, vClients);
}
//----------------------------------------------------------------------


//--------------------Clients Total Balances Screen---------------------
void ShowClientsBalancesListHeader(unsigned short NumberOfClients)
{
	cout << "____________________________________________________________________________\n\n";
	cout << "\t\t\tClients List Of (" << NumberOfClients << ") Client(s)\n";
	cout << "____________________________________________________________________________\n\n";

	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(20) << "Balance($)";

	cout << "\n____________________________________________________________________________\n\n";
}

void PrintClientBalanceInfo(const sClient& Client)
{
	cout << "| " << left << setw(15) << Client.Account_Number;
	cout << "| " << left << setw(40) << Client.Name;
	cout << "| " << left << setw(20) << Client.Account_Balance;
	cout << endl;
}

void ShowTotalBalancesScreen(const vector <sClient>& vClients)
{
	system("cls");

	unsigned long TotlaBalances = 0;

	ShowClientsBalancesListHeader(vClients.size());

	for (const sClient& Client : vClients)
	{
		PrintClientBalanceInfo(Client);
		TotlaBalances += Client.Account_Balance; // Get Balances Sum
	}

	cout << "____________________________________________________________________________\n\n";
	cout << "\t\t\tTotal Balances = " << TotlaBalances;
	cout << "\n____________________________________________________________________________\n";

	cout << "\n\n-> Press Any Key To Back To Transaction Menu Screen...";
	system("pause>0");
}
//----------------------------------------------------------------------

void MoneyTransactions(vector <sClient>& vClients)
{
	bool BackToMainMenu = false;

	do
	{
		TransactionsMenuScreen();

		switch (ChooseATransaction())
		{
		case Deposit:
			DepositTransaction(vClients);
			break;

		case Withdraw:
			WithdrawTransaction(vClients);
			break;

		case Money_Transfer:
			ClientToClientMoneyTransfer(vClients);
			break;

		case Total_Balances:
			ShowTotalBalancesScreen(vClients);
			break;

		case Main_Menu:
			BackToMainMenu = true;
			break;
		}

	} while (!BackToMainMenu);
}
//********************************************************************************************
//********************************************************************************************




//****************************** Lock/Unlock Client Account **********************************
//********************************************************************************************
enum LockOrUnlockAccount
{
	Unlock = 1,
	Lock = 2,
	Back_To_Main_Menu = 3
};

void ShowLock_UnlockClientScreen()
{
	system("cls");
	cout << "========================================================\n";
	cout << "             Lock/Unclock Client Account\n";
	cout << "========================================================\n";
	cout << "           [1] Unlock Account\n";
	cout << "           [2] Lock Account\n";
	cout << "           [3] Back To Main Menu\n";
	cout << "========================================================\n";
	return;
}

void UnlockAccountByAccountNumber(vector <sClient>& vClients)
{
	unsigned short ClientIndex = 0;
	string AccountNumber;

	cout << "\n-> Enter The Account Number:  ";
	getline(cin >> ws, AccountNumber);

	if (FindClientByAccountNumber(AccountNumber, vClients, ClientIndex))
	{
		ShowClientCard(vClients[ClientIndex]);

		if (vClients[ClientIndex].AccountLockedFlag == true)
		{
			if (Read_YesOrNo("\n\n-> Are You Sure You Want To Unlock This Client Account?"))
			{
				vClients[ClientIndex].AccountLockedFlag = false;

				SaveClientsDataToFile(ClientsFileName, vClients);

				cout << "\n\n-> Client Account Unlocked Successfully.\n\n";
			}
		}
		else
			cout << "\n\n-> Client Account Is Already Unlocked.\n\n";
	}
	else
	{
		cout << "\n\n-> Sorry, Client With Account Number (" << AccountNumber << ") Not Found :-(\n\n";
	}
}

void LockAccountByAccountNumber(vector <sClient>& vClients)
{
	unsigned short ClientIndex = 0;
	string AccountNumber;

	cout << "\n-> Enter The Account Number:  ";
	getline(cin >> ws, AccountNumber);

	if (FindClientByAccountNumber(AccountNumber, vClients, ClientIndex))
	{
		ShowClientCard(vClients[ClientIndex]);

		if (vClients[ClientIndex].AccountLockedFlag == false)
		{
			if (Read_YesOrNo("\n\n-> Are You Sure You Want To Lock This Client Account?"))
			{
				vClients[ClientIndex].AccountLockedFlag = true;

				SaveClientsDataToFile(ClientsFileName, vClients);

				cout << "\n\n-> Client Account Locked Successfully.\n\n";
			}
		}
		else
			cout << "\n\n-> Client Account Is Already Locked.\n\n";
	}
	else
	{
		cout << "\n\n-> Sorry, Client With Account Number (" << AccountNumber << ") Not Found :-(\n\n";
	}
}

void LockOrUnlockClientAccount(vector <sClient>& vClients)
{
	LockOrUnlockAccount UserChoice;

	ShowLock_UnlockClientScreen();
	UserChoice = (LockOrUnlockAccount)ReadUserChoice(1, 3, "- Choose what do you want to do [1 to 3]? ");

	switch (UserChoice)
	{
	case LockOrUnlockAccount::Unlock:
		UnlockAccountByAccountNumber(vClients);
		break;
	case LockOrUnlockAccount::Lock:
		LockAccountByAccountNumber(vClients);
		break;
	case LockOrUnlockAccount::Back_To_Main_Menu:
		break;
	}
}
//********************************************************************************************
//********************************************************************************************




enum enUsersMenuOptions
{
	List_Users = 1,
	Add_New_User = 2,
	Delete_User = 3,
	Update_User = 4,
	Find_User = 5,
	MainMenu = 6
};

enum enMainMenuPermissions
{
	canAccessToAll = -1,
	canShowClientsList = 1,
	canAddNewClient = 2,
	canDeleteClient = 4,
	canUpdateClient = 8,
	canFindClient = 16,
	canMakeTransActions = 32,
	canUnlockClientAccount = 64,
	canManageUsers = 128
};

// 1 ->   000000001
// 2 ->   000000010
// 4 ->   000000100
// 8 ->   000001000
// 16 ->  000010000
// 32 ->  000100000
// 64 ->  001000000
// 128 -> 010000000
// 256 -> 100000000
// -1 ->  111111111


//======================================== Users Managment ========================================
//=================================================================================================
enUsersMenuOptions ChooseFromUsersMenu()
{
	return (enUsersMenuOptions)ReadUserChoice(1, 6, "- Choose what do you want to do? [1 to 6]? ");
}

void UsersManagmentMenuScreen()
{
	system("cls");
	cout << "=======================================================\n";
	cout << "\t\tUsers Managment Menu";
	cout << "\n=======================================================\n";
	cout << "\t\t[1] List Users.\n";
	cout << "\t\t[2] Add New User.\n";
	cout << "\t\t[3] Delete User.\n";
	cout << "\t\t[4] Update User.\n";
	cout << "\t\t[5] Find User.\n";
	cout << "\t\t[6] Main Menu.\n";
	cout << "=======================================================\n";
}

//--------------------------------- Users List ---------------------------------
void PrintUsersMenuHeader(unsigned short NumberOfUsers)
{
	cout << "____________________________________________________________________________\n\n";
	cout << "\t\t\tUsers List Of (" << NumberOfUsers << ") User(s)\n";
	cout << "____________________________________________________________________________\n\n";

	cout << "| " << left << setw(15) << "UserName";
	cout << "| " << left << setw(40) << "Password";
	cout << "| " << left << setw(20) << "Permissions";

	cout << "\n____________________________________________________________________________\n\n";
}

void PrintUserInfo(const sUser& User)
{
	cout << "| " << left << setw(15) << User.UserName;
	cout << "| " << left << setw(40) << User.UserPassword;
	cout << "| " << left << setw(20) << User.Permissions;
	cout << endl;
}

void ShowUsersList(const vector <sUser>& vUsers)
{
	system("cls");

	PrintUsersMenuHeader(vUsers.size());

	for (const sUser& User : vUsers)
		PrintUserInfo(User);

	cout << "____________________________________________________________________________";

	cout << "\n\n\n-> Press Any Key To Back To Users Managment Menu Screen...";
	system("pause>0");
}
//------------------------------------------------------------------------------


//-------------------------------- Add New Users --------------------------------
void ShowAddNewUsersScreen()
{
	system("cls");
	cout << "------------------------\n";
	cout << "--- Adding New Users ---";
	cout << "\n------------------------";
	return;
}

bool IsUserAlreadyExist(const string& UserName)
{
	vector <sUser> vUsers = LoadUsersDataFromFile(UsersFileName);

	for (const sUser& User : vUsers)
	{
		if (User.UserName == UserName)
			return true;
	}
	return false;
}

int ReadPermissions(const string& UserName)
{
	int Permissions = 0;

	if (Read_YesOrNo("\n- Do You Want To Give " + UserName + " Full Access To System?"))
	{
		return enMainMenuPermissions::canAccessToAll; // full access
	}
	else
	{
		cout << "\n---------------------------------------------------------------------\n";
		cout << "\n# Do You Want To Give \"" << UserName << "\" The Premission To:\n\n";

		if (Read_YesOrNo("=> Show Clients List?"))
			Permissions |= enMainMenuPermissions::canShowClientsList;

		if (Read_YesOrNo("=> Add New Client?"))
			Permissions |= enMainMenuPermissions::canAddNewClient;

		if (Read_YesOrNo("=> Delete Client?"))
			Permissions |= enMainMenuPermissions::canDeleteClient;

		if (Read_YesOrNo("=> Update Client?"))
			Permissions |= enMainMenuPermissions::canUpdateClient;

		if (Read_YesOrNo("=> Search & Find Clients?"))
			Permissions |= enMainMenuPermissions::canFindClient;

		if (Read_YesOrNo("=> Make Money Transactions?"))
			Permissions |= enMainMenuPermissions::canMakeTransActions;

		if (Read_YesOrNo("=> Unlock Client Account?"))
			Permissions |= enMainMenuPermissions::canUnlockClientAccount;

		if (Read_YesOrNo("=> Manage Users?"))
			Permissions |= enMainMenuPermissions::canManageUsers;

		if (Permissions == 255)
			return enMainMenuPermissions::canAccessToAll; // full access
	}
	return Permissions;
}

sUser ReadNewUserData()
{
	sUser NewUser;

	cout << "\n\n-> Enter The UserName:  ";
	getline(cin >> ws, NewUser.UserName);

	while (IsUserAlreadyExist(NewUser.UserName))
	{
		cout << "\n- [" << NewUser.UserName << "] Already Exists, ";
		cout << "Enter Another UserName:  ";
		getline(cin, NewUser.UserName);
	}

	cout << "-> Enter The Password:  ";
	getline(cin, NewUser.UserPassword);

	NewUser.Permissions = ReadPermissions(NewUser.UserName);

	return NewUser;
}

void AddNewUser()
{
	sUser User = ReadNewUserData();
	string DataLine = UserRecordsToDataLine(User);

	AddDataLineToFile(UsersFileName, DataLine);
	return;
}

void AddNewUsers(vector <sUser>& vUsers)
{
	do
	{
		ShowAddNewUsersScreen();
		AddNewUser();

		// update vUsers after adding new User
		vUsers = LoadUsersDataFromFile(UsersFileName);

	} while (Read_YesOrNo("\n\n-> User added successfully, Do you want to add more Users?"));

	return;
}
//-------------------------------------------------------------------------------


//---------------------------- Delete User --------------------------------------
bool FindUserByUserName(const string& UserName, const vector <sUser>& vUsers)
{
	for (const sUser& User : vUsers)
	{
		if (UserName == User.UserName)
			return true;
	}
	return false;
}
bool FindUserByUserName(const string& UserName, const vector <sUser>& vUsers, unsigned short& UserIndex)
{
	unsigned short NumberOfUsers = vUsers.size();

	for (unsigned short Index = 0; Index < NumberOfUsers; Index++)
	{
		if (vUsers[Index].UserName == UserName)
		{
			UserIndex = Index;
			return true;
		}
	}
	return false;
}

void ShowUserCard(const sUser& User)
{
	cout << "\n\n-> The Following Is The User Details:\n";
	cout << "------------------------------------------------------------------\n";
	cout << "-- UserName --------------: " << User.UserName << '\n';
	cout << "-- Password --------------: " << User.UserPassword << '\n';
	cout << "-- Permissions -----------: " << User.Permissions << '\n';
	cout << "------------------------------------------------------------------\n";
	return;
}

void ShowDeleteUsersScreen()
{
	system("cls");
	cout << "--------------------\n";
	cout << "--- Delete Users ---";
	cout << "\n--------------------\n\n";
	return;
}

void DeleteUserByUserName(const string& UserName, vector <sUser>& vUsers)
{
	unsigned short UserIndex;

	if (FindUserByUserName(UserName, vUsers, UserIndex))
	{
		ShowUserCard(vUsers[UserIndex]);

		if (Read_YesOrNo("\n\n-> Are you sure you want to delete this User?"))
		{
			vUsers[UserIndex].DeleteFlag = true; // Prepare User for delete

			SaveUsersDataToFile(UsersFileName, vUsers);

			// Update & Refresh vUsers vector after deletion
			vUsers = LoadUsersDataFromFile(UsersFileName);

			cout << "\n\n-> User Deleted Successfully.\n\n";
		}
	}
	else
	{
		cout << "\n-> Sorry, User With UserName {" << UserName << "} Not Found :-(";
	}
}

void DeleteUsers(vector <sUser>& vUsers)
{
	string UserName;

	do
	{
		ShowDeleteUsersScreen();

		cout << "-> Enter The UserName:  ";
		getline(cin >> ws, UserName);

		if (UserName == "MG" || UserName == CurrentUser.UserName)
			cout << "\n-> You Can't Delete This User :-(";
		else
			DeleteUserByUserName(UserName, vUsers);

	} while (Read_YesOrNo("\n\n-> Do you want to delete more users?"));
}
//-------------------------------------------------------------------------------


//-------------------------------Update User-------------------------------------
void ShowUpdateUsersScreen()
{
	system("cls");
	cout << "-------------------------\n";
	cout << "--- Update Users Data ---";
	cout << "\n-------------------------\n\n";
}

sUser UpdateUserRecord(string UserName)
{
	sUser User;

	// Update all record except 'UserName'
	User.UserName = UserName;

	cout << "\n-> Enter The New Password:  ";
	getline(cin >> ws, User.UserPassword);

	User.Permissions = ReadPermissions(User.UserName);

	return User;
}

void UpdateUserDataByUserName(const string& UserName, vector <sUser>& vUsers)
{
	unsigned short UserIndex = 0;

	if (FindUserByUserName(UserName, vUsers, UserIndex))
	{
		ShowUserCard(vUsers[UserIndex]);

		if (Read_YesOrNo("\n\n-> Are You Sure You Want To Update This User Data?"))
		{
			vUsers[UserIndex] = UpdateUserRecord(UserName);

			SaveUsersDataToFile(UsersFileName, vUsers);

			cout << "\n\n-> User Updated Successfully.\n\n";
		}
	}
	else
	{
		cout << "\n\n-> Sorry, User With UserName (" << UserName << ") Not Found :-(\n\n";
	}
}

void UpdateUserData(vector <sUser>& vUsers)
{
	string UserName;

	do
	{
		ShowUpdateUsersScreen();

		cout << "-> Enter The UserName:  ";
		getline(cin >> ws, UserName);

		if (UserName == "MG" || UserName == CurrentUser.UserName)
			cout << "\n-> You Can't Update This User :-(";
		else
			UpdateUserDataByUserName(UserName, vUsers);

	} while (Read_YesOrNo("\n\n-> Do you want to update more users?"));
}
//-------------------------------------------------------------------------------


//--------------------------------Find Users-------------------------------------
void ShowFindUsersScreen()
{
	system("cls");
	cout << "------------------------\n";
	cout << "--- Search For Users ---";
	cout << "\n------------------------\n\n";
}

void FindAndShowClientCard(const vector <sUser>& vUsers)
{
	unsigned short UserIndex;
	string UserName;

	do
	{
		ShowFindUsersScreen();

		UserName = ReadTxt("-> Please, Enter The UserName:  ");

		if (FindUserByUserName(UserName, vUsers, UserIndex))
			ShowUserCard(vUsers[UserIndex]);
		else
			cout << "\n\n-> Sorry, User With UserName (" << UserName << ") Not Found :-(";

	} while (Read_YesOrNo("\n\n-> Do you want to search again?"));
}
//-------------------------------------------------------------------------------

void UsersManagment()
{
	bool BackToMainMenu = false;
	vector <sUser> vUsers;

	do
	{
		UsersManagmentMenuScreen();
		vUsers = LoadUsersDataFromFile(UsersFileName);

		switch (ChooseFromUsersMenu())
		{
		case List_Users:
			ShowUsersList(vUsers);
			break;

		case Add_New_User:
			AddNewUsers(vUsers);
			break;

		case Delete_User:
			DeleteUsers(vUsers);
			break;

		case Update_User:
			UpdateUserData(vUsers);
			break;

		case Find_User:
			FindAndShowClientCard(vUsers);
			break;

		case MainMenu:
			BackToMainMenu = true;
			break;
		}

	} while (!BackToMainMenu);
}
//=================================================================================================
//=================================================================================================




enum enMainMenuOptions
{
	Show_Clients_List = 1,
	Add_New_Client = 2,
	Delete_Client = 3,
	Update_Client_Info = 4,
	Find_Client = 5,
	Transactions = 6,
	Lock_UnlockClientAccount = 7,
	Manage_Users = 8,
	Logout = 9
};


enMainMenuOptions ChooseFromMainMenu()
{
	return (enMainMenuOptions)ReadUserChoice(1, 9, "- Choose what do you want to do? [1 to 9]? ");
}

bool HasPermissionToAccess(enMainMenuOptions UserChoice)
{
	switch (UserChoice)
	{
	case Show_Clients_List:
		return (CurrentUser.Permissions & enMainMenuPermissions::canShowClientsList) != 0;

	case Add_New_Client:
		return (CurrentUser.Permissions & enMainMenuPermissions::canAddNewClient) != 0;

	case Delete_Client:
		return (CurrentUser.Permissions & enMainMenuPermissions::canDeleteClient) != 0;

	case Update_Client_Info:
		return (CurrentUser.Permissions & enMainMenuPermissions::canUpdateClient) != 0;

	case Find_Client:
		return (CurrentUser.Permissions & enMainMenuPermissions::canFindClient) != 0;

	case Transactions:
		return (CurrentUser.Permissions & enMainMenuPermissions::canMakeTransActions) != 0;

	case Lock_UnlockClientAccount:
		return (CurrentUser.Permissions & enMainMenuPermissions::canUnlockClientAccount) != 0;

	case Manage_Users:
		return (CurrentUser.Permissions & enMainMenuPermissions::canManageUsers) != 0;
	}
	return true; // logout case
}

void MainMenuScreen()
{
	system("cls");
	cout << "====================================================================\n";
	cout << "\t\t\tMain Menu \"" << CurrentUser.UserName << "\"";
	cout << "\n====================================================================\n";
	cout << "\t\t[1] Show Clients List.\n";
	cout << "\t\t[2] Add New Client.\n";
	cout << "\t\t[3] Delete Client.\n";
	cout << "\t\t[4] Update Client Info.\n";
	cout << "\t\t[5] Find Client.\n";
	cout << "\t\t[6] Transactions.\n";
	cout << "\t\t[7] Lock/Unlock Client Account.\n";
	cout << "\t\t[8] Manage Users.\n";
	cout << "\t\t[9] Logout.\n";
	cout << "====================================================================\n";
	return;
}

void BackToMainMenu()
{
	cout << "\n\n- Press any key to go back to main menu.....";
	system("pause>0"); // or you can use { cin.get() }
}

void AccessDeniedScreen()
{
	system("cls");
	cout << "-----------------------------------------------------\n";
	cout << "              Access Denied :-(\n";
	cout << "    You Don't Have The Permission To Do This\n";
	cout << "         Please, Contact Your Admin\n";
	cout << "-----------------------------------------------------";
	return;
}

void Login();

bool MainProcess(enMainMenuOptions UserChoice)
{
	// Load Data From Clients File
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

	if (HasPermissionToAccess(UserChoice))
	{
		switch (UserChoice)
		{
		case Show_Clients_List:
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

		case Transactions:
			MoneyTransactions(vClients);
			return false;

		case Lock_UnlockClientAccount:
			LockOrUnlockClientAccount(vClients);
			BackToMainMenu();
			return false;

		case Manage_Users:
			UsersManagment();
			return false;

		case Logout:
			Login(); // back to login screen
		}
	}
	else
	{
		AccessDeniedScreen();
		BackToMainMenu();
	}
	return false;
}

void Bank()
{
	bool logout = false;

	while (!logout)
	{
		MainMenuScreen();
		logout = MainProcess(ChooseFromMainMenu());
	}
	return;
}


// ************************************************ Login ************************************************
void ShowLoginScreen()
{
	system("cls");
	cout << "-------------------------------\n";
	cout << "-----------  Login  -----------";
	cout << "\n-------------------------------\n\n";
	return;
}

bool FindUserByUserNameAndPassword(const string& UserName, const string& Password, sUser& CurrentUser)
{
	vector <sUser> vUsers = LoadUsersDataFromFile(UsersFileName);

	for (const sUser& User : vUsers)
	{
		if (UserName == User.UserName && Password == User.UserPassword)
		{
			CurrentUser = User;
			return true;
		}
	}
	return false;
}

bool CheckUserInfo(const string& UserName, const string& Password)
{
	if (FindUserByUserNameAndPassword(UserName, Password, CurrentUser))
		return true;

	return false;
}

void Login()
{
	string UserName, Password;
	bool LoginFaild = false;

	do
	{
		ShowLoginScreen();

		if (LoginFaild)
			cout << "Invalid UserName/Password :-(\n\n";

		UserName = ReadTxt("Please, Enter UserName:  ");
		Password = ReadTxt("Please, Enter Password:  ");

		LoginFaild = !CheckUserInfo(UserName, Password);

	} while (LoginFaild);

	Bank(); // login successfully

	return;
}
// *******************************************************************************************************



int main(void)
{
	Login();

	return 0;
}