
#include <iostream>

using namespace std;


// this function only takes a References(Addresses) parameters
void Swap2Numbers_ByPointer(short* p1, short* p2)
{
    short temp = 0;

    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}


int main()
{
    int a = 10;

    cout << "- Address of a = " << &a << endl;
    cout << "- Value Of a   = " << a << endl;
    cout << endl;

    // Referencing (p) to (a)
    int* p;
    p = &a;


    cout << "- Value Of p  (Adderss of a) = " << p << endl;
    cout << "- &p Give the (Adderss of p) = " << &p << endl;
    cout << "- *p Give the (Value of a)   = " << *p << endl;
    cout << endl;

    // You can change the value of (a, *p) by Dereferencing (*p) to another value
    *p = 20;

    cout << "->  a = " << a << endl;
    cout << "-> *p = " << *p << endl;
    cout << endl;

    // And you can change the value of (a, *p) by changing the value of (a)
    a = 30;

    cout << "->  a = " << a << endl;
    cout << "-> *p = " << *p << endl;
    cout << endl;


    cout << "\n_______________________________________________________________________\n\n\n";


    // Swap 2 Numbers:
    

    
    // 1- Swap function using References of 2 variables
    short x = 10, y = 20;

    cout << "- Values of x, y Before Swapping is: " << endl;
    cout << "-> x = " << x << endl;
    cout << "-> y = " << y << endl;
    cout << endl;

    Swap2Numbers_ByPointer(&x, &y);

    cout << "- Values of x, y After Swapping is: " << endl;
    cout << "-> x = " << x << endl;
    cout << "-> y = " << y << endl;
    cout << endl;

    cout << "\n_______________________________________________________________________\n\n\n";

    // 2- Swap function using Pointers of 2 variables
    short w = 100, z = 200;

    cout << "- Values of w, z Before Swapping is: " << endl;
    cout << "-> w = " << w << endl;
    cout << "-> z = " << z << endl;
    cout << endl;

    short* wp = &w; // Pointer of (w)
    short* zp = &z; // Pointer of (z)

    // Pointer Parameters
    Swap2Numbers_ByPointer(wp, zp);

    cout << "- Values of w, z After Swapping is: " << endl;
    cout << "-> w = " << w << endl;
    cout << "-> z = " << z << endl;
    cout << endl;

    cout << "\n_______________________________________________________________________\n\n\n";


    return 0;
}
