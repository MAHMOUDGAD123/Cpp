

#include <iostream>
#include <string>
#include <chrono>
#include <thread>


using namespace std;
using namespace this_thread;
using namespace chrono_literals;
using chrono::system_clock;

int main()
{
    /*
        string Grade;

    XXX:
        cout << "Please enter your Grade : ";
        cin >> Grade;
        cout << "\n";

        if (stoi(Grade) <= 100 && stoi(Grade) >= 1)
        {


            if (stoi(Grade) >= 90 && stoi(Grade) <= 100)
            {
                cout << "A" << endl;

            }


            else if (stoi(Grade) >= 80 && stoi(Grade) <= 89)
            {
                cout << "B" << endl;

            }

            else if (stoi(Grade) >= 70 && stoi(Grade) <= 79)
            {
                cout << "C" << endl;

            }

            else if (stoi(Grade) >= 60 && stoi(Grade) <= 69)
            {
                cout << "D" << endl;

            }

            else if (stoi(Grade) >= 50 && stoi(Grade) <= 59)
            {
                cout << "E" << endl;

            }

            else
            {
                cout << "F" << endl;

            }
        }
        else
        {
            goto XXX;
        }*/

        //*************************************************************************

   /* string TotalSales;

    cout << "Please enter the Total sales : ";
    cin >> TotalSales;
    cout << "\n";


    if (stoi(TotalSales) > 1000000)
    {
        cout << "Commition = " << stoi(TotalSales) * 0.01 << endl << endl;
    }

    else if(stoi(TotalSales) <= 1000000 && stoi(TotalSales) >= 500000)
    {
        cout << "Commition = " << stoi(TotalSales) * 0.02 << endl << endl;
    }

    else if (stoi(TotalSales) < 500000 && stoi(TotalSales) >= 100000)
    {
        cout << "Commition = " << stoi(TotalSales) * 0.03 << endl << endl;
    }

    else if (stoi(TotalSales) < 1000000 && stoi(TotalSales) >= 50000)
    {
        cout << "Commition = " << stoi(TotalSales) * 0.05 << endl << endl;
    }
    else
    {
        cout << "There is no commition." << endl << endl;
    }*/

    //******************************************************************************************
    //******************************************************************************************
    
//
//    string n1, n2;
//    char Op;
//
//XXX:
//
//    cout << "Please enter n1 (numerator) : ";
//    cin >> n1;
//    cout << "\n";
//
//    cout << "Please enter n2 (denominator) : ";
//    cin >> n2;
//    cout << "\n";
//
//YYY:
//
//    cout << "Please enter the Operation : " << endl;
//    cout << "(+) for addition\n(-) for subtraction\n(*) for multiplication\n(/) for Devition " << endl << endl;
//    cout << "your answer : ";
//    cin >> Op;
//    cout << "\n" << endl;
//
//    if (Op != '+' && Op != '-' && Op != '*' && Op != '/')
//    {
//        cout << "Wrong Operation.\n" << endl;
//        sleep_for(2s);
//        goto YYY;
//    }
//
//    if (Op == '/' && stof(n2) == 0)
//    {
//        cout << "Devision by zero n2 must be smaller than n1\n" << endl;
//        sleep_for(2s);
//        goto XXX;
//    }
//    else
//    {
//        if (Op == '+')
//        {
//            cout << "the Result = " << stof(n1) + stof(n2) << endl << endl;
//        }
//
//        else if (Op == '-')
//        {
//            cout << "the Result = " << stof(n1) - stof(n2) << endl << endl;
//        }
//
//        else if (Op == '*')
//        {
//            cout << "the Result = " << stof(n1) * stof(n2) << endl << endl;
//        }
//
//        else if (Op == '/')
//        {
//            cout << "the Result = " << stof(n1) / stof(n2) << endl << endl;
//        }
//
//
//    }

//******************************************************************************************************


    string day;


ZZZ:

    cout << "Please enter the day (from 1 to 7) : ";
    cin >> day;
    cout << "\n" << endl;

    if (stoi(day) == 1)
    {
        cout << "Saturday" << endl << endl;
    }

    else if (stoi(day) == 2)
    {
        cout << "Sunday" << endl << endl;
    }

    else if (stoi(day) == 3)
    {
        cout << "Monday" << endl << endl;
    }

    else if (stoi(day) == 4)
    {
        cout << "Tuesday" << endl << endl;
    }

    else if (stoi(day) == 5)
    {
        cout << "Wednesday" << endl << endl;
    }

    else if (stoi(day) == 6)
    {
        cout << "Thursday" << endl << endl;
    }

    else if (stoi(day) == 7)
    {
        cout << "Friday" << endl << endl;
    }

    else
    {
        cout << "Wrong day.\n" << endl;
        sleep_for(2s);
        goto ZZZ;
    }
    

   


    return 0;
}


