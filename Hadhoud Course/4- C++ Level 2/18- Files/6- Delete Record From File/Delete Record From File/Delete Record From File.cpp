#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "MGLib.h"

using namespace std;
using namespace MGLib;

void CreateATxtFile(const string FileName)
{
    vector <string> vNames{ "Mahmoud","Abdelrahman","Ismail","Abdelrahman","Ismail","Gad","Ali","Mohammed","Amal","Amira","Gamal" };

    fstream MGFile;
    MGFile.open(FileName, ios::out);

    if (MGFile.is_open())
    {
        for (const string& Name : vNames)
            MGFile << Name << endl;
    }
    MGFile.close();
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
        for (const string& Record : vFileContent)
        {
            if (Record != "")
                MGFile << Record << endl;
        }
        MGFile.close();
    }
}

void DeleteFileRecords(const string FileName, const string RecordToDelete)
{
    vector <string> vFileContent;

    LoadDataFromFileToVector(FileName, vFileContent);

    for (string& Record : vFileContent)
    {
        if (Record == RecordToDelete)
            Record = "";
    }

    SaveVectorToFile(FileName, vFileContent);
    vFileContent.clear();
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
        cout << "_______________________________________________________________\n";
        MGFile.close();
    }
    delete Line;
}

void Print_Vector_Data(vector <string>& vFileContent)
{
    short* SizeOfVector = new short{ 0 };

    cout << "\n________________________________________________________\n\n";
    for (const string& Record : vFileContent)
    {
        cout << Record << endl;
        (*SizeOfVector)++;
    }

    cout << "\n-> Size Of the Vector = " << *SizeOfVector << endl;
    cout << "\n________________________________________________________\n";
    delete SizeOfVector;
}


int main()
{

    CreateATxtFile("Names.txt");

    cout << "Records Before Delete:";
    Diplay_FileContent("Names.txt");

    DeleteFileRecords("Names.txt", "Ismail");

    cout << "\n\nRecords After Delete:\n\n";
    Diplay_FileContent("Names.txt");



    return 0;
}