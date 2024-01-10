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
	cout << "\n\n";

	cout << "-- Account Number:---- {  " << Data.Account_Number << "  }" << "\n";
	cout << "-- PIN_code:---------- {  " << Data.PIN_Code << "  }" << "\n";
	cout << "-- Name:-------------- {  " << Data.Name << "  }" << "\n";
	cout << "-- Phone Number:------ {  " << Data.Phone_number << "  }" << "\n";
	cout << "-- Account_Balance:--- {  " << fixed << Data.Account_Balance << "  }" << "\n";
}


string ClientRecordsToLineData(sClient_Data Data, const char* Seperator = "#//#")
{
	string Record = "";

	Record += Data.Account_Number + Seperator;
	Record += to_string(Data.PIN_Code) + Seperator;
	Record += Data.Name + Seperator;
	Record += Data.Phone_number + Seperator;
	Record += to_string(Data.Account_Balance);

	return Record;
}



int main(void)
{
	cout << "-- Enter The Client Data:\n\n";

	sClient_Data Data = Read_Client_Data();

	Dispaly_Client_Data(Data);

	cout << "\n\n-> Client Record:\n\n";
	cout << "{  " << ClientRecordsToLineData(Data) << "  }\n\n";

	return 0;
}