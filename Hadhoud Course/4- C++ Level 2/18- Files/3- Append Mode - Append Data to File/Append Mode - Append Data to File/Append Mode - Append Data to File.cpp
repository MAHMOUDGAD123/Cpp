#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string Name = "Mahmoud Abdelrahman Ismail Abdelrahman Ismail Gad";
    string Address = "Mansoura - Egypt";
    string Birth_Date = "10 / 9 / 1997";

    // Create the file & open it in 'write' mode
    fstream MGFile("MyFile.txt", ios::out);

    if (MGFile.is_open())
    {
        MGFile << "-> My Name Is: " << Name << endl;

        MGFile.close();
    }


    // Recall MGFile & open the file in 'appending' mode
    MGFile.open("MyFile.txt", ios::out | ios::app);       /* -> { ios::app } is appending mode <- */

    if (MGFile.is_open())
    {
        MGFile << "-> My Address is: " << Address << endl;

        MGFile.close();
    }

    // Add more data
    MGFile.open("MyFile.txt", ios::out | ios::app);

    if (MGFile.is_open())
    {
        MGFile << "-> My Birth Date Is: " << Birth_Date << endl;

        MGFile.close();
    }



    return 0;
}