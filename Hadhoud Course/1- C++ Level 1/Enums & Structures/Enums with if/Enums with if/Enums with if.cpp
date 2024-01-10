
#include <string> 
#include <iostream>
#include <chrono>
#include <thread>


using namespace std;
using namespace std::this_thread;
using namespace std::chrono_literals;
using std::chrono::system_clock;




enum en_ScreenColor {Blue=1, Puple=2, Red=3, Yellow=4};

void ColorsMenu(string &choice)
{
    cout << "which screen color you prefer? " << endl;
    cout << "******************" << endl;
    cout << "(1)Blue" << endl;
    cout << "(2)Puple" << endl;
    cout << "(3)Red" << endl;
    cout << "(4)Yellow" << endl;
    cout << "*****************" << endl;

    cout << "you choice : ";
    cin >> choice;
    cout << "\n" << endl;
}


//***********************************************************************************

enum en_Countries { Egypt = 1, Jordan = 2, Syria = 3, Iraq = 4, Others = 5 };

void CountriesMenu(string &C)
{
    cout << "Hello, What is your country?\n" << endl;

    cout << "*********************" << endl;
    cout << "(1)Egypt" << endl;
    cout << "(2)Jordan" << endl;
    cout << "(3)Syria" << endl;
    cout << "(4)Iraq" << endl;
    cout << "(5)Others" << endl;
    cout << "*********************" << endl;

    cout << "your choice : ";
    cin >> C;
    cout << "\n" << endl;


}

int main()
{

    string choice;

XXX:

    ColorsMenu(choice);

    en_ScreenColor Color;

    Color = (en_ScreenColor)stoi(choice);


    if (Color == en_ScreenColor::Blue)
    {
        system("color 1F");
    }
    else if (Color == en_ScreenColor::Puple)
    {
        system("color 5F");
    }
    else if (Color == en_ScreenColor::Red)
    {
        system("color 4F");
    }
    else if (Color == en_ScreenColor::Yellow)
    {
        system("color 6F");
    }
    else
    {
        cout << "Unavailable Color Choose again." << endl << endl;
        sleep_for(1.5s);
        goto XXX;
    }



    cout << "***********************************************************************" << endl;
    cout << "***********************************************************************" << endl;
    cout << "***********************************************************************" << endl << endl << endl;
    sleep_for(1.5s);


    string C;
    CountriesMenu(C);

    en_Countries yourCountry;
    yourCountry = (en_Countries)stoi(C);

    if (yourCountry == en_Countries::Egypt)
    {
        cout << "Your Country is : Egypt" << endl << endl;
    }
    else if (yourCountry == en_Countries::Jordan)
    {
        cout << "your country is : Jordan " << endl << endl;
    }

    else if (yourCountry == en_Countries::Jordan)
    {
        cout << "your country is : Jordan " << endl << endl;
    }
    else if (yourCountry == en_Countries::Syria)
    {
        cout << "your country is : Syria " << endl << endl;
    }
    else if (yourCountry == en_Countries::Iraq)
    {
        cout << "your country is : Iraq " << endl << endl;
    }
    else
    {
        cout << "Sorry, you are not from the list." << endl << endl;
    }




    return 0;
}

