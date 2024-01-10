
#include <iostream>
#include <string>

using namespace std;


void mysumProcedural() // procedural is always void
{
   
    cout << "This is the sum of 2 numbers Procedural." << endl << endl;

    int num1, num2;

    cout << "Please enter number1 : ";
    cin >> num1;
    cout << "\n";


    cout << "Please enter number2 : ";
    cin >> num2;
    cout << "\n";

    int result = num1 + num2;

    cout << "The result = " << result << endl;


    cout << "\n" << endl;
    cout << "**********************************" << endl;
    cout << "**********************************" << endl;


}


int mysumFunction() // function
{
    cout << "\n" << endl;

    cout << "This is the sum of 2 numbers Function." << endl << endl;

    int num3, num4;

    cout << "Please enter number1 : ";
    cin >> num3;
    cout << "\n";


    cout << "Please enter number2 : ";
    cin >> num4;
    cout << "\n";

    int Result = num3 + num4;


    return Result;

    // after the (return) no thing will be executed

}


string myNameFunction()    // function
{


    cout << "\n" << endl;
    cout << "**********************************" << endl;
    cout << "**********************************" << endl;
    cout << "\n" << endl;
   
    string FullName;

    cout << "This is myname Function." << endl <<endl;

    cout << "please enter your Full name : ";
    cin.ignore(1, '\n');
    getline(cin, FullName);
    cout << "\n" << endl;

    return FullName;


}


int main()
{
    
    mysumProcedural(); // prcedural called without ( cout fun ) because it has no return value.

    cout << "The result = " << mysumFunction() << endl;  // Function called with ( cout fun ) because it has a return value.

    cout << "The result = " << mysumFunction() + 7 << endl;

    cout << "your Full name is : " << myNameFunction() + " " + "Takshomah" << endl;

    return 0;

}


