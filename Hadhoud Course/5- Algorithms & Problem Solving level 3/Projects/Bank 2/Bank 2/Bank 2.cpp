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
//***********************************************************************************************
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

	} while (Read_YesOrNo_FromUser("\n\n-> Do you want to search again?"));
}
//********************************************************************************
//********************************************************************************




//******************************Add Clients****************************
//*********************************************************************
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
	do
	{
		ShowAddNewClientsScreen();

		// Check Client by Account Number Before Adding
		AddNewClient();

		// update vClients after adding new clients
		vClients = LoadClientsDataFromFile(ClientsFileName);

	} while (Read_YesOrNo_FromUser("\n\n-> Client added successfully, Do you want to add more clients?"));
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
	string AccountNumber;

	do
	{
		ShowDeleteClientsScreen();

		cout << "-> Enter The Account Number:  ";
		getline(cin >> ws, AccountNumber);

		DeleteClientByAccountNumber(AccountNumber, vClients);

	} while (Read_YesOrNo_FromUser("\n\n-> Do you want to delete more clients?"));
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

	return Client;
}

void UpdateClientDataByAccountNumber(const string& AccountNumber, vector <sClient>& vClients)
{
	unsigned short ClientIndex = 0;

	if (FindClientByAccountNumber(AccountNumber, vClients, ClientIndex))
	{
		ShowClientCard(vClients[ClientIndex]);

		bool Update = Read_YesOrNo_FromUser("\n\n-> Are You Sure You Want To Update This Client Data?");

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

	} while (Read_YesOrNo_FromUser("\n\n-> Do you want to update more clients?"));
}
//********************************************************************************************
//********************************************************************************************



//_______________________________________________________________________________________________________________
//_______________________________________________________________________________________________________________
//_______________________________________________________________________________________________________________

enum TransactionMenuOptions
{
	Deposit = 1,
	Withdraw = 2,
	Money_Transfer = 3,
	Total_Balances = 4,
	Main_Menu = 5
};

enum MainMenuOptions
{
	Show_Client_List = 1,
	Add_New_Client = 2,
	Delete_Client = 3,
	Update_Client_Info = 4,
	Find_Client = 5,
	Transactions = 6,
	Exit = 7
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
	cout << "\t\t[6] Transactions.\n";
	cout << "\t\t[7] Exit.\n";
	cout << "====================================================================\n";
}

void TransactionsMenuScreen()
{
	system("cls");
	cout << "====================================================================\n";
	cout << "\t\tTransaction Menu Screen";
	cout << "\n====================================================================\n";
	cout << "\t\t[1] Deposit.\n";
	cout << "\t\t[2] Withdraw.\n";
	cout << "\t\t[3] Money Transfer (Client to Client).\n";
	cout << "\t\t[4] Total Balances.\n";
	cout << "\t\t[5] Main Menu.\n";
	cout << "====================================================================\n";
}

void BackToMainMenu()
{
	cout << "\n\n- Press any key to go back to main menu.....";
	system("pause>0"); // or you can use { cin.get() }
}

void ShowEndScreen()
{
	system("cls");

	cout << "----------------------------------------------------------------\n";
	cout << "-------------------- Program Ends See You :-) ------------------";
	cout << "\n----------------------------------------------------------------\n\n";
}




//***********************************Transactions*********************************************
//********************************************************************************************

TransactionMenuOptions ChooseATransaction()
{
	return (TransactionMenuOptions)Read_Positive_Number_InRange(1, 5, "- Choose what do you want to do? [1 to 5]? ");
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

	if (Read_YesOrNo_FromUser("\n\n-> Are You Sure You Want To Perform This Transaction?"))
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

	} while (Read_YesOrNo_FromUser("\n\n-> Do You Want To Deposit More Money?"));
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

	if (Read_YesOrNo_FromUser("\n\n-> Are You Sure You Want To Perform This Transaction?"))
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
			cout << "\n\n-> Sorry, Client With Account Number (" << AccountNumber << ") Not Found :-(";
			cout << "\n\n-> Please, Enter Another Account Number:  ";
			getline(cin >> ws, AccountNumber);
		}

		ShowClientCard(vClients[ClientIndex]);

		WithdrawMoney(vClients[ClientIndex].Account_Balance);

		SaveClientsDataToFile(ClientsFileName, vClients);

	} while (Read_YesOrNo_FromUser("\n\n-> Do You Want To Deposit More Money?"));
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

	if (Read_YesOrNo_FromUser("\n\n-> Are You Sure You Want To Perform This Transaction?"))
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
	bool PerformMore = true;

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
			PerformMore = false;
			break;
		}

	} while (PerformMore);
}
//********************************************************************************************
//********************************************************************************************

MainMenuOptions ChooseFromMainMenu()
{
	return (MainMenuOptions)Read_Positive_Number_InRange(1, 7, "- Choose what do you want to do? [1 to 7]? ");
}

bool MainProcess(MainMenuOptions UserChoice)
{
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName); // Load Data From File To vClients

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

	case Transactions:
		MoneyTransactions(vClients);
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