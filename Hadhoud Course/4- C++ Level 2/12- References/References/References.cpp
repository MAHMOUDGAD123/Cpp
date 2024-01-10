
#include <iostream>

using namespace std;

int main()
{
    // (ref) is a reference to (a)
    short a = 10;
    short& ref = a;

    // (a),(ref) have the same address
    cout << "Adderss Of (a) = " << &a << endl;
    cout << "Adderss Of (ref) = " << &ref << endl;

    // (a),(ref) have the same Value
    cout << "Value Of (a) = " << a << endl;
    cout << "Value Of (ref) = " << ref << endl;

    cout << endl << endl;

    // If we change (a) this mean that (ref) had changed too
    a = 20;

    cout << "After Cahnging (a):" << endl << endl;
    cout << "Value Of (a) = " << a << endl;
    cout << "Value Of (ref) = " << ref << endl;

    cout << endl << endl;

    // If we change (ref) this mean that (a) had changed too
    ref = 30;
    
    cout << "After Cahnging (ref):" << endl << endl;
    cout << "Value Of (a) = " << a << endl;
    cout << "Value Of (ref) = " << ref << endl;
    
    return 0;
}
