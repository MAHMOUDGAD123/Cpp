#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "MGLib.h"

using namespace std;
using namespace MGLib;

struct MyInfo
{
	string Name = "Mahmoud Abdelrahman Ismail Abdelrahman Gad";
	string Address = "Hy_Alzafaran - Mansoura - Dakahlia - Egypt";
	string Birth_Date = "10 / 9 / 1997";
	string Gender = "Male";
	string NId = "29709101204993";
	string UId = "1000152612";
};

void CreateATxtFile(const string FileName, MyInfo& Info)
{
	fstream MGFile;
	MGFile.open(FileName, ios::out);

	if (MGFile.is_open())
	{
		MGFile << "MG Information\n";
		MGFile << "-------------\n\n";
		MGFile << "-> Name         : " << Info.Name << endl;
		MGFile << "-> Address      : " << Info.Address << endl;
		MGFile << "-> Birth Date   : " << Info.Birth_Date << endl;
		MGFile << "-> Gender       : " << Info.Gender << endl;
		MGFile << "-> National Id  : " << Info.NId << endl;
		MGFile << "-> University Id: " << Info.UId << endl;
	}
	MGFile.close();
}

string ChooseARecordToUpdate()
{
	size_t* Answer = new size_t{ 0 };

	vector <string> Records{ "Name", "Address", "Birth Date", "Gender", "National Id", "University Id" };

	cout << "\nWhat Record Do you Want To Update?\n";
	cout << "(1)Name\n(2)Address\n(3)Birth Date\n(4)Gender\n(5)National Id\n(6)University Id\n\n";
	*Answer = Read_NumberInRange("You Answer: ", 1, 6);

	return Records[*Answer - 1];
}

void LoadDataFromFileToVector(const string FileName, vector <string>& vFileContent)
{
	string* Line = new string("");

	fstream MGFile;
	MGFile.open(FileName, ios::in);

	if (MGFile.is_open())
	{
		while (getline(MGFile, *Line))
		{
			vFileContent.push_back(*Line);
		}
		MGFile.close();
	}
	delete Line;
}

void SaveVectorToFile(const string FileName, vector <string>& vFileContent)
{
	fstream MGFile;
	MGFile.open(FileName, ios::out);

	if (MGFile.is_open())
	{
		for (const string& Info : vFileContent)
		{
			if (Info != "")
				MGFile << Info << endl;
		}
		MGFile.close();
	}
}

void UpdateFileRecords_v1(const string FileName)
{
	vector <string> vFileContent;

	string* Line = new string("");
	string* TempTxt = new string("");
	size_t* ReplacePos = new size_t{ 0 };
	string* RecordToUpdate = new string("");
	bool* UpdateMore = new bool(false);

	fstream MGFile;

	do
	{
		MGFile.open(FileName, ios::in);

		if (MGFile.is_open())
		{
			*RecordToUpdate = ChooseARecordToUpdate();

			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			while (getline(MGFile, *Line))
			{
				*ReplacePos = Line->find(*RecordToUpdate);

				if (*ReplacePos != string::npos)
				{
					*ReplacePos = Line->find(':');
					cout << "\nEnter The New " << *RecordToUpdate << ": ";
					getline(cin, *TempTxt);

					Line->replace(*ReplacePos + 2, Line->length() - *ReplacePos + 2, *TempTxt);
				}
				vFileContent.push_back(*Line);
			}
			MGFile.close();
		}
		SaveVectorToFile(FileName, vFileContent);
		vFileContent.clear();

		*UpdateMore = Read_Bool_Input("\nDo You Want To Update More?");

	} while (*UpdateMore);

	delete Line, TempTxt, ReplacePos, RecordToUpdate, UpdateMore;
}

void UpdateFileRecords_v2(const string FileName)
{
	vector <string> vFileContent;
	string* RecordToUpdate = new string("");
	string* NewRecord = new string("");
	size_t* ReplacePos = new size_t{ 0 };
	bool* UpdateMore = new bool(false);

	do
	{
		LoadDataFromFileToVector(FileName, vFileContent);

		*RecordToUpdate = ChooseARecordToUpdate();

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		for (string& Record : vFileContent)
		{
			*ReplacePos = Record.find(*RecordToUpdate);

			if (*ReplacePos != string::npos)
			{
				*ReplacePos = Record.find(':');
				cout << "\nEnter The New " << *RecordToUpdate << ": ";
				getline(cin, *NewRecord);

				Record.replace(*ReplacePos + 2, Record.length() - *ReplacePos + 2, *NewRecord);
			}
		}
		SaveVectorToFile(FileName, vFileContent);
		vFileContent.clear();

		*UpdateMore = Read_Bool_Input("\nDo You Want To Update More Records?");

	} while (*UpdateMore);

	delete RecordToUpdate, NewRecord, UpdateMore;
}

void Print_Vector_Data(vector <string>& vFileContent)
{
	short* SizeOfVector = new short{ 0 };

	cout << "\n_________________________________________________________\n\n";
	for (const string& Info : vFileContent)
	{
		cout << Info << endl;
		(*SizeOfVector)++;
	}

	cout << "\n-> Size Of the Vector = " << *SizeOfVector << endl;
	cout << "\n_________________________________________________________\n";
	delete SizeOfVector;
}

void Diplay_FileContent(const string FileName)
{
	string* Line = new string{ "" };

	fstream MGFile;
	MGFile.open(FileName, ios::in);

	if (MGFile.is_open())
	{
		cout << "\n_______________________________________________________________\n\n";
		while (getline(MGFile, *Line))
		{
			cout << *Line << endl;
		}
		cout << "\n_______________________________________________________________\n";
		MGFile.close();
	}
	delete Line;
}


int main()
{
	MyInfo Info;
	vector <string> vFileContent;

	CreateATxtFile("MyInfo.txt", Info);


	cout << "Records Before Update:";
	Diplay_FileContent("MyInfo.txt");

	UpdateFileRecords_v2("MyInfo.txt");

	cout << "\n\nRecords After Update:";
	Diplay_FileContent("MyInfo.txt");

	return 0;
}