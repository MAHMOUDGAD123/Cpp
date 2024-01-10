

#include <iostream>
#include <string>

using namespace std;


int main()
{
    cout << "Welcome to data type conversion " << endl << endl << endl;

    for (;;)
    {
        string UserInput;
        cout << "Please enter any number : ";
        cin >> UserInput;
        cout << "\n" << endl;

        string choice;
        cout << "Convert to :  " << "1- Integer  2- Float  3- double " << endl << endl;
        cout << "just enter ( 1 or 2 or 3 ) : ";
        cin >> choice;
        cout << "\n" << endl;

        if (choice == "1")
        {
            cout << "The result is = " << stoi(UserInput) << endl << endl << endl;
            continue;

        }

        else if (choice == "2")
        {
            cout << "The result is = " << stof(UserInput) << endl << endl << endl;
            continue;

        }

        else if (choice == "3")
        {
            cout << "The result is = " << stod(UserInput) << endl << endl << endl;
            continue;

        }

        else
        {

            cout << "Wrong choice" << endl << endl << endl;
            continue;


        }



    }



}


