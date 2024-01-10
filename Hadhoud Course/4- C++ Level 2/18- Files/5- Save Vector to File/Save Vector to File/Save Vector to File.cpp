#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


void SaveVectorToFile(const string FileName, vector <string>& vFileContent)
{
    fstream MGFile;
    MGFile.open(FileName, ios::out);
    
    if (MGFile.is_open())
    {
        for (const string& Info : vFileContent)
        {
            if(Info != "")
                MGFile << Info << endl;
        }
        MGFile.close();
    }
}

void Print_Vector_Data(const vector <string>& vFileContent)
{
    short* SizeOfVector = new short{ 0 };

    for (const string& Info : vFileContent)
    {
        cout << Info << endl;
        (*SizeOfVector)++;
    }

    cout << "\n-> Size Of the Vector = " << *SizeOfVector << endl;
    delete SizeOfVector;
}


int main()
{
    vector <string> vFileContent{"Mahmoud","Abdelrahman","Ismail","Gad"};

    SaveVectorToFile("MyInfo.txt", vFileContent);

    Print_Vector_Data(vFileContent);



    return 0;
}