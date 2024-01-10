#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "MGLib.h"

using namespace std;
using namespace MGLib;


/*
    More about files in C++

    https://www.geeksforgeeks.org/file-handling-c-classes/

    https://cplusplus.com/doc/tutorial/files/

    -> Flags: https://cplusplus.com/reference/ios/ios/good/

    good() / fail() / bad() / eof()


*/


void CreateATxtFile(const string FileName)
{
    vector <string> vNames{ "Mahmoud","Abdelrahman","Ismail",
        "Abdelrahman","Sama","Ismail","Gad","Reem","Ali","Mohammed","Amal","Amira",
        "Gamal","Ali","Gad","Mahmoud","Mohammed","Reem","Sama","Amira","Amal" };

    fstream MGFile;
    MGFile.open(FileName, ios::out);

    if (MGFile.is_open())
    {
        for (const string& Name : vNames)
            MGFile << Name << endl;
    }
    MGFile.close();
}

bool IsRepeated(vector <string>& vFile, const string& WordToCheck)
{
    for (const string& Word : vFile)
    {
        if (Word == WordToCheck)
        {
            return true;
        }
    }
    return false;
}

void RemoveWordsRepetitionInFile(const char* FileName)
{
    vector <string> vFile;
    string* Line = new string{ "" };

    fstream File;
    File.open(FileName, ios::in);

    if (File.is_open())
    {
        while (getline(File, *Line))
        {
            if (!IsRepeated(vFile, *Line))
                vFile.push_back(*Line);
        }
        File.close();
    }
    SaveVectorToFile(FileName, vFile);
}


int main()
{
    CreateATxtFile("Names.txt");


    cout << "Records Before Remove Repetition:";
    Diplay_FileContent("Names.txt");

    RemoveWordsRepetitionInFile("Names.txt");

    cout << "\n\nRecords After Remove Repetition:";
    Diplay_FileContent("Names.txt");

    return 0;
}