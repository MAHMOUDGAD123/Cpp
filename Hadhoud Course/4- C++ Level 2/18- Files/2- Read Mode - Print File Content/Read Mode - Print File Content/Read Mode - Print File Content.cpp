#include <iostream>
#include <fstream>
#include <string>

using namespace std;


struct MGInfo
{
	string Name = "";
	string Address = "";
	string Birth_Date = "";
};

MGInfo Read_Data()
{
	MGInfo MyInfo;

	cout << "Please Enter The Next Data?\n";

	cout << "Name: ";
	getline(cin, MyInfo.Name);

	cout << "Address: ";
	getline(cin, MyInfo.Address);

	cout << "Birth Date: ";
	getline(cin, MyInfo.Birth_Date);

	return MyInfo;
}

void Create_TxtFile(string FileName, MGInfo& MyInfo)
{
	fstream MGFile(FileName, ios::out);  // Write mode

	if (MGFile.is_open())
	{
		MGFile << "MG Information\n";
		MGFile << "--------------\n\n";
		MGFile << "-> Name      |: " << MyInfo.Name << endl;
		MGFile << "-> Address   |: " << MyInfo.Address << endl;
		MGFile << "-> Birth Date|: " << MyInfo.Birth_Date << endl;
	}
	MGFile.close();
}


void Read_TxtFile_Content(string FileName)
{
	string Line = "";

	fstream MGFile(FileName, ios::in);  // Read Mode

	if (MGFile.is_open())
	{
		while (getline(MGFile, Line))
		{
			cout << Line << endl;
		}

		MGFile.close();
	}
	else
	{
		cout << "Unable to Open The File!!" << endl; // When fail to open the file
	}
}


int main()
{
	MGInfo MyInfo = Read_Data();

	Create_TxtFile("MyFile.txt", MyInfo);

	Read_TxtFile_Content("MyFile.txt");


	return 0;
}