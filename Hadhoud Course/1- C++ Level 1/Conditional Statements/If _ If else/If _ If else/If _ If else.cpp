

#include <iostream>
#include <string>

using namespace std;

int main()
{
    /*int age;
    bool haveDriverLicense;

    string Answer;
    cout << "Do you have a driver license? yes\\no\n ";
    cin >> Answer;
    if (Answer == "yes")
    {
        haveDriverLicense = true;
    }
    else 
    {
        haveDriverLicense = false;
    }
    cout << "\n";


    cout << "Please enter your age : ";
    cin >> age;
    cout << "\n";


    if (age >= 21 && haveDriverLicense == true)
    {
        cout << "Congratulations, You are Hired." << endl;
    }
    else
    {
        cout << "Sorry, you are rejected." << endl;
    }*/

    //**********************************************************************

    /*int mark;

    cout << "Please enter your mark : ";
    cin >> mark;
    cout << "\n";

    if (mark >= 50)
    {
        cout << "PASS" << endl;

    }
    else
    {
        cout << "FAIL" << endl;
    }*/

    //*************************************************************************

   /* int mark1, mark2, mark3;

    cout << "Please enter your 3 marks?\n";

    cout << "mark 1 : ";
    cin >> mark1;
    cout << "\n";


    cout << "mark 2 : ";
    cin >> mark2;
    cout << "\n";


    cout << "mark 3 : ";
    cin >> mark3;
    cout << "\n";

    int marksAverage = (mark1+mark2+mark3) / 3;


    if (marksAverage >= 50)
    {
        cout << "PASS" << endl;
    }
    else
    {
        cout << "FAIL" << endl;
    }*/

    //***********************************************************************

  /*  int age;
    cout << "Please enter your age : ";
    cin >> age;
    cout << "\n" << endl;

    if (age >= 18 && age <= 45)
    {
        cout << "Valid age." << endl;
    }
    else
    {
        cout << "Sorry, Invalid age." << endl;
    }*/


    //**********************************************************************

    
XXX:
    string PIN;
    cout << "Please enter your PIN : ";
    cin >> PIN;
    cout << "\n";
    
  
    if (PIN == "1234")
    {

        cout << "Your Balance is ( 1000000$ )" << endl << endl;

    }
    else
    {
        cout << "Wrong PIN, Please enter again" << endl << endl;
        goto XXX;
    }

    

    return 0;
}


