
#include <string>
#include <iostream>
#include <chrono>
#include <thread>


using namespace std;
using namespace std::this_thread;
using namespace std::chrono_literals;
using std::chrono::system_clock;



enum en_ScreenColor { Blue = 1, Purple = 2, Red = 3 };
enum en_Countries {Egypt = 1, Jordan = 2, Iraq =3 };

void ChooseColor(string &choice)
{
    cout << "Which color you prefer for your Background? " << endl;
    cout << "***************************************" << endl;
    cout << "(1) Blue\n";
    cout << "(2) Purple\n";
    cout << "(3) Red\n";
    cout << "Just write (1 or 2 or 3)\n";

    cout << "Your choice : ";
    cin >> choice;
    cout << "\n" << endl;


}
void ChooseCountry(string& C)
{
    cout << "What is your country?" << endl;
    cout << "(1) Egyot\n";
    cout << "(2) Jordan\n";
    cout << "(3) Iraq\n";
    cout << "your choice : ";
    cin >> C;
    cout << "\n" << endl;
}

int main()
{
XXX:

    string choice;
    ChooseColor(choice);

    en_ScreenColor Color = (en_ScreenColor) stoi(choice);

    switch (Color)
    {
    case en_ScreenColor::Blue:
        system("color 1F");
        cout << "\n" << endl;
        break;

    case en_ScreenColor::Purple:
        system("color 5F");
        cout << "\n" << endl;
        break;

    case en_ScreenColor::Red:
        system("color 4F");
        cout << "\n" << endl;
        break;

    default:
        cout << "Sorry, this color is not available choose again." << endl << endl;
        sleep_for(1s);
        goto XXX;

    }

    cout << "****************************************************************************\n";
    cout << "****************************************************************************\n";
    cout << "****************************************************************************\n" << endl;;

YYY:


    string C;
    ChooseCountry(C);

    en_Countries YourCountry = (en_Countries) stoi(C);

    switch (YourCountry)
    {
    case en_Countries::Egypt:
        cout << "********************************************************\n";
        cout << "*********************   WELCOME   **********************\n";
        cout << "*********************   EGYPTION  **********************\n";
        cout << "********************************************************\n" << endl;
        break;

    case en_Countries::Jordan:
        cout << "********************************************************\n";
        cout << "*********************   WELCOME   **********************\n";
        cout << "*********************  JORDANIAN  **********************\n";
        cout << "********************************************************\n" << endl;
        break;

    case en_Countries::Iraq:
        cout << "********************************************************\n";
        cout << "*********************   WELCOME   **********************\n";
        cout << "*********************    IRAQI    **********************\n";
        cout << "********************************************************\n" << endl;
        break;

    default:
        cout << "Sorry, not available." << endl << endl;
        sleep_for(1s);
        goto YYY;
  
    }


    return 0;
}


