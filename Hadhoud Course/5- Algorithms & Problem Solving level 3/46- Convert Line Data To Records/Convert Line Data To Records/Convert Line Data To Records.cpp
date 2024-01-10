#include <iostream>
#include <vector>
#include <iomanip>
#include "MGLib.h"

using namespace std;
using namespace MGLib;


struct sClient_Data
{
	string Account_Number = "";
	string Name = "";
	string Phone_number = "";
	unsigned short PIN_Code = 0;
	double Account_Balance = 0;
};


sClient_Data Read_Client_Data()
{
	sClient_Data Data;

	Data.Account_Number = Read_Text("-> Enter The Account Number: ");
	Data.Name = Read_Text("-> Enter The Name: ");
	Data.Phone_number = Read_Text("-> Enter The Phone Number: ");
	Data.PIN_Code = Read_Positive_Int_Number("-> Enter The PIN Code {4 Digits}: ", 4);
	Data.Account_Balance = Read_Positive_Number("-> Enter The Account Balance: ");

	return Data;
}

void Dispaly_Client_Data(sClient_Data Data)
{
	cout << "-- Account Number:---- {  " << Data.Account_Number << "  }" << "\n";
	cout << "-- Name:-------------- {  " << Data.Name << "  }" << "\n";
	cout << "-- Phone Number:------ {  " << Data.Phone_number << "  }" << "\n";
	cout << "-- PIN_code:---------- {  " << Data.PIN_Code << "  }" << "\n";
	cout << "-- Account_Balance:--- {  " << fixed << Data.Account_Balance << "  }" << "\n";
}

string ClientRecordsToLineData(sClient_Data Data, const char* Seperator = "#//#")
{
	string Record = "";

	Record += Data.Account_Number + Seperator;
	Record += Data.Name + Seperator;
	Record += Data.Phone_number + Seperator;
	Record += to_string(Data.PIN_Code) + Seperator;
	Record += to_string(Data.Account_Balance);

	return Record;
}

sClient_Data ClientLineDataToRecords(string LineData, const char* delim = "#//#")
{
	sClient_Data Data;

	vector <string> vRecords = Split_String(LineData, delim);;

	Data.Account_Number = vRecords.at(0);
	Data.Name = vRecords.at(1);
	Data.Phone_number = vRecords.at(2);
	Data.PIN_Code = stoi(vRecords.at(3));
	Data.Account_Balance = stod(vRecords.at(4));

	return Data;
}




// LD --> Line Data

int main(void)
{
	cout << "-- Enter The Client Data:\n\n";

	sClient_Data Data;

	Data = Read_Client_Data();

	string Client_LD = ClientRecordsToLineData(Data);

	cout << "\n\n-> Client LD:\n\n";
	cout << "{  " << Client_LD << "  }\n\n";

	// A1002#//#Mahmoud Gad#//#+201097890670#//#4283#//#1500000.000000

	Data = ClientLineDataToRecords(Client_LD);

	cout << "\n\n-> Client Records:\n\n";
	Dispaly_Client_Data(Data);


	return 0;
}