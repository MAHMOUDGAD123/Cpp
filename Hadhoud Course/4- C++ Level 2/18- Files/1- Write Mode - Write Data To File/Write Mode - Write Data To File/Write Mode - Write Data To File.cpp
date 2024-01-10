#include <iostream>
#include <fstream> // Needed

using namespace std;



int main()
{
    string MyName = "Mahmoud Abdelrahman Ismail Abdelrahman Ismail Gad";
    string Address = "Mansoura - Egypt";
    short Age = 25;

    /*                         Method(1) to open a file                        */

    fstream MGFile; // Create an object of 'fstream' name -> (MGFile)

    // Open file using 'open' function
    // filename.open (filename, mode);

    MGFile.open("MyName.txt", ios::out); // Open file in 'Write mode'

    // To write on the file we use the file name 'MGFile' like 'cout'
    MGFile << "-> Name: " << MyName << endl;

    // We have to close the file after we finish write
    // he stream object can be re-used to open another file,
    // and the file is available again to be opened by other processes.
    MGFile.close();





    /*                          Method(2) to open a file                             */

    fstream MGInfo("MyInfo.txt", ios::out); // by combine all in one statement

    // Check if the file is successfully opened ->  return true if success and otherwise return false
    if (MGInfo.is_open())
    {
        MGInfo << "-> Name   : " << MyName << endl;
        MGInfo << "-> Age    : " << Age << endl;
        MGInfo << "-> Address: " << Address << endl;

        MGInfo.close();     
    }
    else
    {
        cout << "Unalbe to Open a File" << endl;
    }



    return 0;
}