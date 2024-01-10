
#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int b = 20;

    

    cout << "- Address of a = " << &a << endl;
    cout << "- Address of b = " << &b << endl;
    cout << "- Value Of a   = " << a << endl;
    cout << "- Value Of b   = " << b << endl;
    cout << endl;

    // Pionter (p)
    // The data type of (p) must be form the same type of (a)
    // Pointer variables only takes addresses (References)
    // (p) has an address too

    int* p;
    p = &a;


    /*
        -> (p) : Give the address of the varible(a) that (p) is pointing to
        -> (&p): Give the address of the pointer (p)
        -> (*p): Give the value of the varible(a) that (p) is pointing to
    */


    cout << "- Value of p (Adderss of a)  = " << p << endl;
    cout << "- Value of &p (Adderss of p) = " << &p << endl;
    cout << "- Value of *p (Value of a)   = " << *p << endl;
    cout << endl;

    // We can change the Direction of (p) form (a) to (b)
    p = &b;

    cout << "-> After Change The Direction Of (p) From (a) to (b):" << endl << endl;

    cout << "- Value of p (Adderss of b)  = " << p << endl;
    cout << "- Value of &p (Adderss of p) = " << &p << endl;
    cout << "- Value of *p (Value of b)   = " << *p << endl;
    cout << endl;
    
    
    return 0;
}
