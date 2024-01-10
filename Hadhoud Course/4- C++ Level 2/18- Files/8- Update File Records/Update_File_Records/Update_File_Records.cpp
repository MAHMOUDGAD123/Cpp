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
        for (const string& Info : vFileContent)
        {
            if (Info != "")
                MGFile << Info << endl;
        }
        MGFile.close();
    }
}

void UpdateFileRecords(const string FileName, const string RecordToUpdate, const string NewRecord)
{
    vector <string> vFileContent;
  
    LoadDataFromFileToVector(FileName, vFileContent);

    for (string& Record : vFileContent)
    {
        if (Record == RecordToUpdate)
            Record = NewRecord;
    }
    SaveVectorToFile(FileName, vFileContent);
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
        cout << "_______________________________________________________________\n";
        MGFile.close();
    }
    delete Line;
}


int main()
{
    vector <string> vFileContent;

    CreateATxtFile("Names.txt");


    cout << "Records Before Update\\\\";
    Diplay_FileContent("Names.txt");

    UpdateFileRecords("Names.txt", "Ismail", "Reem");

    cout << "\n\nRecords After Update\\\\";
    Diplay_FileContent("Names.txt");

    return 0;
}