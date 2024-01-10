
#include <iostream>
#include <string>

using namespace std;



int main()
{
    string FName, num1, num2;

    cout << "Please enter your full name : ";
    getline(cin, FName);
    cout << "\n" << endl;


    cout << "Please enter number 1 : ";
    cin >> num1;
    cout << "\n" << endl;

    cout << "Please enter number 2 : ";
    cin >> num2;
    cout << "\n" << endl;


    cout << "*******************************************" << endl << endl << endl;

    cout << "Your name is : " << FName << endl;
    cout << "The length of your name is : " << FName.length() << endl;

    cout << "The first lertter of your name is : " << FName[0] << endl;
    cout << "The last lertter of your name is : " << FName[FName.length() - 1] << endl;  // Last letter of the FName


    cout << "The concatenatin of num1 & num2 is = " << num1 + num2 << endl;

    cout << "The numerical sum of num1 & num2 is = " << stoi(num1) + stoi(num2) << endl;



    return 0;

}





