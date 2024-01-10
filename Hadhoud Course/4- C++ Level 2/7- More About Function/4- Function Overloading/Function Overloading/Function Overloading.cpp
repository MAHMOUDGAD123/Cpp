

#include <iostream>

using namespace std;

// In C++ Function Overloading
// Function Overloading Allow You To Define Different Functions With The Same Name
// But Not With The Same Number Of Parameters
// And The Compiler Will Choose Which Function To Use Due To Your Inputs

// Function Overloading: provides multiple definitions of the function by changing signature i.e
// changing number of parameters, change datatype of parameters, return type doesn’t play anyrole. 

double Sum(double a, double b)
{
    return a + b;
}

// Not Allowed
/*

double Sum(double x, double y)
{
    return x + y;
}

*/

// Allowed
int Sum(int a, int b)
{
    return a + b;
}

// Allowed
int Sum(int a, int b, int c)
{
    return a + b + c;
}


// Allowed
int Sum(int a, int b, int c, int d)
{
    return a + b + c + d;
}


int main()
{

    cout << "Sum = " << Sum(10.6541, 20.7647) << endl << endl;
    cout << "Sum = " << Sum(10, 20) << endl << endl;
    cout << "Sum = " << Sum(10, 20, 30) << endl << endl;
    cout << "Sum = " << Sum(10, 20, 30, 40) << endl << endl;


    return 0;
}