#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct MyInfo
{
    string Name = "Mahmoud Gad";
    string Address = "Mansoura - Egypt";
    string Birth_Date = "10 / 9 / 1997";
    string NId = "29709101204993";
    string UId = "1000152612";
};

void CreateATxtFile(string FileName, MyInfo& Info)
{
    fstream MGFile(FileName, ios::out);

    if (MGFile.is_open())
    {
        MGFile << "MG Informatin\n";
        MGFile << "-------------\n\n";
        MGFile << "-> Name         : " << Info.Name << endl;
        MGFile << "-> Address      : " << Info.Address << endl;
        MGFile << "-> Birth Date   : " << Info.Birth_Date << endl;
        MGFile << "-> National Id  : " << Info.NId << endl;
        MGFile << "-> University Id: " << Info.UId << endl;
    }
    MGFile.close();
}

void LoadDataFromFileToVector(string FileName, vector <string>& vFileContent)
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

void Print_Vector_Data(const vector <string>& vFileContent)
{
    short SizeOfVector = 0;

    for (const string& Info : vFileContent)
    {
        cout << Info << endl;
        SizeOfVector++;
    }

    cout << "\n-> Size Of the Vector = " << SizeOfVector << endl;
}


int main()
{
    MyInfo Info;
    vector <string> vFileContent;

    CreateATxtFile("MyInfo.txt", Info);

    LoadDataFromFileToVector("MyInfo.txt", vFileContent);

    Print_Vector_Data(vFileContent);

    return 0;
}