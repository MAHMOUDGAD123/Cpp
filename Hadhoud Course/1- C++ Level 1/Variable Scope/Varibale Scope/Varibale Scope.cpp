#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <math.h>
#include <cmath>

using namespace std;

int X = 777; // Local Varible (دورة حياته بعمر البرنامج ككل بمعني : يتم خذفة من الميموري بعد انتهاء البرنامج)



void XProcedural() // Procedural
{
    int X = 77; // local varible

    cout << "This is the local value in the function : " << X << endl;

}

int XFunction() // function

{
    int X = 7; // local variable

    return X;

}




int main()
{

    int X = 3;

    XProcedural(); // print the value in the XProcedura
    cout << "\n" << endl;

    cout << "This is the value of X in the XFunction : " << XFunction() << endl << endl;   // print the value in the XFuunction

    cout << "This is the value of X in the main function : " << X << endl << endl; // print the value of X in the main function

    cout << "This is the Global value of X in the Program : " << ::X << endl << endl; // print the Global value of X in the Program

    ::X++; // increasing the Global value of X by 1 ( ::X used to call the global variable or modify it )

    cout << "This is the Global value of X after increasing by 1 : " << ::X << endl << endl; // print the Global value of X after increasing it

    return 0;
}
