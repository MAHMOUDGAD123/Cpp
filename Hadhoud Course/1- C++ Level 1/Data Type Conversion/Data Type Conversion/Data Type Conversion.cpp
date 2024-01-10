

#include <iostream>
#include <string>

using namespace std;


int main()
{
    
    string st1 = "43.45";

    int sttoInt = stoi(st1);
    float sttoFloat = stof(st1);
    double sttoDouble = stod(st1);

    cout << "string to int = " << sttoInt << endl;
    cout << "string to float = " << sttoFloat << endl;
    cout << "string to double = " << sttoDouble << endl;


    cout << "**************************************************" << endl;
    cout << "**************************************************" << endl << endl;



    int N1 = 70;
    string N1toStr = to_string(N1);

    cout << "N1 to string = " << N1toStr << endl;



    cout << "**************************************************" << endl;
    cout << "**************************************************" << endl << endl;




    int num1;
    double N2 = 90.95645;
    string N2toStr = to_string(N2);
    num1 = N2;      // Implicit conversion (double to int)
    num1 = int(N2); // Explicit conversion using int() function 
    num1 = (int)N2; // Explicit conversion 

   
    cout << "N2 to string = " << N2toStr << endl;
    cout << "N2 to int = " << num1 << endl;



    cout << "**************************************************" << endl;
    cout << "**************************************************" << endl << endl;


     
    int num2;
    float N3 = 54.465;
    string N3toStr = to_string(N3);
    num2 = N3;      // Implicit conversion (double to int)
    num2 = int(N3); // Explicit conversion using int() function
    num2 = (int)N3; // Explicit conversion 


    cout << "N3 to string = " << N3toStr << endl;
    cout << "N3 to int = " << num2 << endl;



}


