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

string ChooseARecordToDelete()
{
    size_t Answer = 0;

    vector <string> Records{ "Name", "Address", "Birth Date", "Gender", "National Id", "University Id" };

    cout << "\nWhat Record Do you Want To Delete?\n";
    cout << "(1)Name\n(2)Address\n(3)Birth Date\n(4)Gender\n(5)National Id\n(6)University Id\n\n";
    Answer = Read_NumberInRange("You Answer: ", 1, 6);

    return Records[Answer - 1];
}

void LoadDataFromFileToVector(const string FileName, vector <string>& vFileContent)
{
    string Line = "";

    fstream MGFile;
    MGFile.open(FileName, ios::in);

    if (MGFile.is_open())
    {
        while (getline(MGFile, Line))
        {
            vFileContent.push_back(Line);
        }
        MGFile.close();
    }
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

void DeleteFileRecords_v1(const string FileName)
{
    vector <string> vFileContent;
    string* Line = new string{ "" };
    string* RecordToDelete = new string{ "" };
    size_t* ErasePos = new size_t{ 0 };
    bool* DeleteMore = new bool{ false };

    fstream MGFile;

    do
    {
        MGFile.open(FileName, ios::in);

        if (MGFile.is_open())
        {
            *RecordToDelete = ChooseARecordToDelete();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            while (getline(MGFile, *Line))
            {
                *ErasePos = Line->find(*RecordToDelete);

                if (*ErasePos != string::npos)
                {
                    *ErasePos = Line->find(':');

                    Line->erase(*ErasePos + 2);
                }
                vFileContent.push_back(*Line);
            }
            MGFile.close();

            SaveVectorToFile(FileName, vFileContent);
            vFileContent.clear();
        }
        *DeleteMore = Read_Bool_Input("\nDo You Want To Delete More Records?");

    } while (*DeleteMore);

    delete Line, RecordToDelete, ErasePos, DeleteMore;
}

void DeleteFileRecords_v2(const string FileName)
{
    vector <string> vFileContent;
    string* RecordToDelete = new string{ "" };
    size_t* ErasePos = new size_t{ 0 };
    bool* DeleteMore = new bool{ false };


    do
    {
        LoadDataFromFileToVector(FileName, vFileContent);

        *RecordToDelete = ChooseARecordToDelete();

        for (string& Record : vFileContent)
        {
            *ErasePos = Record.find(*RecordToDelete);

            if (*ErasePos != string::npos)
            {
                *ErasePos = Record.find(':');
                Record.erase(*ErasePos + 2);
            }
        }

        SaveVectorToFile(FileName, vFileContent);
        vFileContent.clear();

        *DeleteMore = Read_Bool_Input("\nDo You Want To Delete More Records?");

    } while (*DeleteMore);

    delete RecordToDelete, DeleteMore, ErasePos;
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
    SizeOfVector = nullptr;
}


int main()
{
    MyInfo Info;
    vector <string> vFileContent;

    CreateATxtFile("MyInfo.txt", Info);

    cout << "Records Before Delete:";
    Diplay_FileContent("MyInfo.txt");

    DeleteFileRecords_v2("MyInfo.txt");

    cout << "\n\nRecords After Delete:";
    Diplay_FileContent("MyInfo.txt");



    return 0;
}