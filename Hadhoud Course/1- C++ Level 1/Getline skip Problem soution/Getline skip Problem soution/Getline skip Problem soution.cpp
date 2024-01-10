
#include <string>
#include <iostream>

using namespace std;


int main()
{
    string PhoneNumber;
    string FName;
    string age;

 

    cout << "Please enter your Phone number : ";
    cin >> PhoneNumber;
    cout << "\n" << endl;


    cout << "Please enter yout name : ";
    cin.ignore(1,'\n');          //>>>>>>>>> {  cin.ignore(,)  } clear buffer before taking new line ( to get input from getline ). 
    getline(cin , FName);
    cout << "\n" << endl;


    cout << "Please enter your age : ";
    cin >> age;
    cout << "\n" << endl;



    cout << "your name is : " << FName << "\n" << "your age is : " << age << "\n" << "Phone number : " << PhoneNumber << endl;



    return 0;
}


