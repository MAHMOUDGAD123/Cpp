#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <math.h>
#include <cmath>

using namespace std;


/*
  SwapProcedural(int &n1, int &n2) >>>> {by reference} (this change the value of n1,n2 in the main function not just in the procedural)

  swapProcedural(int n1, int n2) >>>> {by value} (this will chinge the value of n1,n2 just within the procedutal)

*/


void SwapProcedural(int &n1, int &n2)
{
    int R = n1;
    n1 = n2;
    n2 = R;

    cout << "this is n1, n1 after swapping : " << "n1 = " << n1 << " & " << "n2 = " << n2 << endl << endl;

}

int main()
{
    int n1, n2;

    cout << "Please enter n1 : ";
    cin >> n1;

    cout << "please enter n2 : ";
    cin >> n2;
    cout << "\n";

    cout << "this is n1, n1 before swapping : " << "n1 = " << n1 << " "  << " & " << "n2 = " << n2 << endl << endl;


    SwapProcedural(n1, n2);

    cout << "this is the new n1 : " << n1 << endl;
    cout << "the address of the new n1 = " << &n1 << endl; // adress of n1

    cout << "this is the new n2 : " << n2 << endl;
    cout << "the address of the new n2 = " << &n2 << endl; // address of n2

    return 0;
}

