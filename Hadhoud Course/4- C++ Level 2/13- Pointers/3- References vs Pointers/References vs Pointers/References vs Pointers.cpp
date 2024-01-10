
#include <iostream>

using namespace std;


void Swap(string*& str1, string*& str2)
{
    string temp;
    temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}



int main()
{
    // Reference

    short a = 10;
    short& ref = a; // Reference to (a)

    cout << "- &a   = " << &a << endl;
    cout << "- &ref = " << &ref << endl;
    cout << "- a    = " << a << endl;
    cout << "- ref  = " << ref << endl;
    cout << endl;

    // You can't update the Reference after referencing it X(&ref = b)X
    // Only you can change the value but not the Reference(Address)
    short b = 20;
    ref = b;


    // The Reference(Address) of (ref) will keep the same as (a) and will not change ever
    cout << "- &a   = " << &a << endl;
    cout << "- &b   = " << &b << endl;
    cout << "- &ref = " << &ref << endl;
    cout << "- a    = " << a << endl;
    cout << "- b    = " << b << endl;
    cout << "- ref  = " << ref << endl;
    cout << endl;



    cout << "\n____________________________________________________\n\n";


    // Pointer

    short x = 100;

    short* ptr = &x;

    cout << "- &x  = " << &x << endl;
    cout << "- ptr  = " << ptr << endl;
    cout << "- x   = " << x << endl;
    cout << "- *ptr = " << *ptr << endl;
    cout << endl;

     // You can update the Reference of the (ptr)

    short z = 200;

    // update the Reference of (ptr)
    ptr = &z;

    cout << "Pointer (ptr) After Update:" << endl;
    cout << "- &z  = " << &z << endl;
    cout << "- ptr  = " << ptr << endl;
    cout << "- z   = " << z << endl;
    cout << "- *ptr = " << *ptr << endl;
    cout << endl;

    cout << "____________________________________________________\n\n";


    string FName = "Mahmoud";
    string LName = "Gad";

    string* fp = &FName;
    string* lp = &LName;


    cout << "- FName = " << FName << endl;
    cout << "- LName = " << LName << endl;
    cout << endl;


    Swap(fp,lp);


    cout << "- FName = " << FName << endl;
    cout << "- LName = " << LName << endl;
    cout << endl;

    cout << "____________________________________________________\n\n";


    return 0;
}
