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

sClient CurrentClient;

// Gobal variable
const char* ClientsFileName = "D:\\VS\\Hadhoud Course\\6- Algorithms & Problem Solving Level 4\\Projects\\1- Bank Exention 2\\Bank Extention 2\\Bank Extention 2\\Clients.txt";



//***************************************** Tools ***********************************************
//***********************************************************************************************
short ReadPIN(short NumberOfDigits, const char* Message = "")
{
	short PIN = 0;
	cout << Message;
	cin >> PIN;

	while (cin.fail() || PIN < 0 || !Check_HowManyDigits(PIN, NumberOfDigits))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << Message;
		cin >> PIN;
	}
	// to discard any non_numerics in the end of input
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return PIN;
}

short ReadClientChoice(short from, short to, const char* Message = "")
{
	short Choice = 0;
	cout << Message;
	cin >> Choice;

	while (cin.fail() || Choice < from || Choice > to)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << Message;
		cin >> Choice;
	}
	// to discard any non_numerics in the end of input
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return Choice;
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
	return;
}
//***********************************************************************************************
//***********************************************************************************************




enum enAtmMainMenuOptions
{
	QuickWithdraw = 1,
	NormalWithdraw = 2,
	Deposit = 3,
	CheckBalance = 4,
	UpdatePIN = 5,
	Logout = 6
};

enum enQuickWithdrawMenuOptions
{
	BackToMainMenu = 0,
	Twenty$ = 1,
	Fifty$ = 2,
	Hundred$ = 3,
	TwoHundred$ = 4,
	fourHundred$ = 5,
	SixHundred$ = 6,
	EightHundred$ = 7,
	Thousand$ = 8
};


void Login();
void ShowAtmMainMenuScreen();

void BackToMainMenuScreen()
{
	cout << "\n\nPress Any Key To Go Back To Main Menu.......";
	system("pause>0");
	ShowAtmMainMenuScreen();
	return;
}

//=============================================== Withdraw =============================================== 
//======================================================================================================== 
void WithdrawMoney(unsigned long& ClientBalance, unsigned long WithdrawAmount)
{
	if (WithdrawAmount > ClientBalance)
	{
		cout << "\n\n-> Amount Exceeds The Balance, You Can Withdraw Up To : " << ClientBalance << " $";
	}
	else
	{
		if (Read_YesOrNo("\n\n-> Are You Sure You Want To Perform This Transaction?"))
		{
			ClientBalance -= WithdrawAmount;
			cout << "\n\n-> Withdraw Transaction Done Successfully, New Balance = " << ClientBalance << " $";
		}
	}
	return;
}

void FindClientByAccountNumber(const vector <sClient>& vClients, unsigned long& ClientIndex)
{
	unsigned short NumberOfClients = vClients.size();

	for (unsigned short Index = 0; Index < NumberOfClients; Index++)
		if (vClients[Index].Account_Number == CurrentClient.Account_Number)
		{
			ClientIndex = Index;
			return;
		}
}

void WithdrawTransaction(unsigned long WithdrawAmount)
{
	unsigned long ClientIndex;
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

	// get the client index in vClients
	FindClientByAccountNumber(vClients, ClientIndex);

	WithdrawMoney(vClients[ClientIndex].Account_Balance, WithdrawAmount);

	// update CurrentUser balance after withdraw
	CurrentClient.Account_Balance = vClients[ClientIndex].Account_Balance;

	SaveClientsDataToFile(ClientsFileName, vClients);
	return;
}

//-------------------------------------------- Quick Withdraw --------------------------------------------
enQuickWithdrawMenuOptions ChooseFromQuickWithdrawMenu()
{
	return (enQuickWithdrawMenuOptions)ReadClientChoice(0, 8, "- Choose what to withdraw from {0 to 8}?  ");
}

void PerformQuickWithdrawMenuOptions(enQuickWithdrawMenuOptions ClientChoice)
{
	const unsigned short QuickWithdrawValues[8] = { 20,50,100,200,400,600,800,1000 };

	if (ClientChoice != 0) WithdrawTransaction(QuickWithdrawValues[ClientChoice - 1]);

	return BackToMainMenuScreen();
}

void ShowQuickWithdrawScreen()
{
	system("cls");
	cout << "======================================================\n";
	cout << "                    Quick Withdraw";
	cout << "\n======================================================\n";
	cout << "              [1] 20             [2] 50\n";
	cout << "              [3] 100            [4] 200\n";
	cout << "              [5] 400            [6] 600\n";
	cout << "              [7] 800            [8] 1000\n";
	cout << "              [0] Back To Main Menu\n";
	cout << "======================================================\n";
	cout << "=> Your Balance = " << CurrentClient.Account_Balance;
	cout << "\n======================================================\n";
	return PerformQuickWithdrawMenuOptions(ChooseFromQuickWithdrawMenu());
}

//-------------------------------------------- Normal Withdraw -------------------------------------------
unsigned long ReadWithdrawAmount()
{
	unsigned long WithdrawAmount = 0;
	do
	{
		WithdrawAmount = ReadNumber("Please, enter an amount multiple of 5's:  ");

	} while (WithdrawAmount % 5 != 0);

	return WithdrawAmount;
}

void ShowNormalWithdrawScreen()
{
	system("cls");
	cout << "===================================================\n";
	cout << "                    Normal Withdraw";
	cout << "\n===================================================\n";
	cout << "=> Your Balance = " << CurrentClient.Account_Balance;
	cout << "\n===================================================\n\n";

	WithdrawTransaction(ReadWithdrawAmount());
	return BackToMainMenuScreen();
}
//========================================================================================================
//========================================================================================================


//------------------------------------------------ Deposit -----------------------------------------------
void DepositMoney(unsigned long& ClientBalance)
{
	unsigned long DepositAmount = ReadNumber("-> Please, enter the deposit amount:  ");

	if (Read_YesOrNo("\n\n-> Are You Sure You Want To Perform This Transaction?"))
	{
		ClientBalance += DepositAmount;
		cout << "\n\n-> Deposit Transaction Done Successfully, New Balance = " << ClientBalance << " $";
	}
	return;
}

void DepositTransaction()
{
	unsigned long ClientIndex;
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

	// get the client index in vClients
	FindClientByAccountNumber(vClients, ClientIndex);

	DepositMoney(vClients[ClientIndex].Account_Balance);

	// update CurrentUser balance after withdraw
	CurrentClient.Account_Balance = vClients[ClientIndex].Account_Balance;

	SaveClientsDataToFile(ClientsFileName, vClients);
	return;
}

void ShowDepositScreen()
{
	system("cls");
	cout << "===================================================\n";
	cout << "                    Normal Withdraw";
	cout << "\n===================================================\n\n";

	DepositTransaction();
	return BackToMainMenuScreen();
}
//--------------------------------------------------------------------------------------------------------


//----------------------------------------------- Update PIN ---------------------------------------------
short ReadAndConfirmPIN()
{
	short NewPIN, PINConfirmation;

	NewPIN = ReadPIN(4, "Please, Enter The New PIN:  ");
	PINConfirmation = ReadPIN(4, "To Confirm, Enter The PIN One More Time:  ");

	while (PINConfirmation != NewPIN)
	{
		cout << "\n- There's No Match :-(\n\n";
		NewPIN = ReadPIN(4, "Please, Enter The New PIN:  ");
		PINConfirmation = ReadPIN(4, "To Confirm, Enter The PIN One More Time:  ");
	}
	cout << "\n- PIN Updated Successfully :-)\n";

	return NewPIN;
}

void UpdateClientPIN()
{
	unsigned long ClientIndex;
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

	// get the client index in vClients
	FindClientByAccountNumber(vClients, ClientIndex);

	// update PIN
	vClients[ClientIndex].PIN_Code = CurrentClient.PIN_Code = ReadAndConfirmPIN();

	SaveClientsDataToFile(ClientsFileName, vClients);
	return;
}

void ShowUpdatePINScreen()
{
	system("cls");
	cout << "===================================================\n";
	cout << "                    Update PIN";
	cout << "\n===================================================\n\n";

	UpdateClientPIN();
	return BackToMainMenuScreen();
}
//--------------------------------------------------------------------------------------------------------


void ShowCheckBalanceScreen()
{
	system("cls");
	cout << "===================================================\n";
	cout << "                    Check Balance";
	cout << "\n===================================================\n";
	cout << "-> Your Balance = " << CurrentClient.Account_Balance << " $";
	cout << "\n===================================================\n";
	return BackToMainMenuScreen();
}



enAtmMainMenuOptions ChooseFromAtmMainMenu()
{
	return (enAtmMainMenuOptions)ReadClientChoice(1, 6, "- Choose what do you want to do {1 to 6}?  ");
}

void PerformAtmMenuOptions(enAtmMainMenuOptions ClientChoice)
{
	switch (ClientChoice)
	{
	case QuickWithdraw:
		return ShowQuickWithdrawScreen();

	case NormalWithdraw:
		return ShowNormalWithdrawScreen();

	case Deposit:
		return ShowDepositScreen();

	case CheckBalance:
		return ShowCheckBalanceScreen();

	case UpdatePIN:
		return ShowUpdatePINScreen();

	case Logout:
		return Login();
	}
}

void ShowAtmMainMenuScreen()
{
	system("cls");
	cout << "=============================================================\n";
	cout << "\t\tATM Main Menu \"" << CurrentClient.Name << "\"";
	cout << "\n=============================================================\n";
	cout << "\t\t[1] Quick Withdraw.\n";
	cout << "\t\t[2] Normal Withdraw.\n";
	cout << "\t\t[3] Deposit.\n";
	cout << "\t\t[4] Check Balance.\n";
	cout << "\t\t[5] Update PIN.\n";
	cout << "\t\t[6] Logout.\n";
	cout << "=============================================================\n";
	return PerformAtmMenuOptions(ChooseFromAtmMainMenu());
}



// ************************************************ Login ************************************************
void ShowLockedAccountScreen()
{
	system("cls");
	cout << "===================================================\n";
	cout << "               )-: Locked Account :-(";
	cout << "\n===================================================\n";
	cout << "               Your Account Is Locked\n";
	cout << "                 Please, Contact Us";
	cout << "\n===================================================\n";
	cout << "\n\nPress Any Key To Go Back To Login Screen.......";
	system("pause>0");

	Login();
	return;
}

bool FindClientByAccountNumberAndPIN(const string& AccountNumber, const unsigned short& PIN)
{
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

	for (const sClient& Client : vClients)
	{
		if (AccountNumber == Client.Account_Number && PIN == Client.PIN_Code)
		{
			CurrentClient = Client;
			return true;
		}
	}
	return false;
}

bool CheckClientInfo(const string& AccountNumber, const unsigned short& PIN)
{
	if (FindClientByAccountNumberAndPIN(AccountNumber, PIN))
	{
		if (CurrentClient.AccountLockedFlag == true)
			ShowLockedAccountScreen(); // if account is locked

		return true;
	}
	return false;
}

void ShowLoginScreen()
{
	system("cls");
	cout << "===================================================\n";
	cout << "                      Login";
	cout << "\n===================================================\n\n";
	return;
}

void Login()
{
	string AccountNumber;
	unsigned short PIN;
	bool LoginFaild = false;

	do
	{
		ShowLoginScreen();

		if (LoginFaild)
			cout << "Invalid AccountNumber/PIN :-(\n\n";

		AccountNumber = ReadTxt("Please, Enter AccountNumber:  ");
		PIN = ReadPIN(4, "Please, Enter The 4 Digits PIN:  ");

		LoginFaild = !CheckClientInfo(AccountNumber, PIN);

	} while (LoginFaild);

	ShowAtmMainMenuScreen(); // login successfully

	return;
}
// *******************************************************************************************************



int main(void)
{
	Login();

	return 0;
}