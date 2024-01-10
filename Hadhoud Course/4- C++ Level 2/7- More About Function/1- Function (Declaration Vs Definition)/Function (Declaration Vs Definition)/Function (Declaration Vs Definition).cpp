#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// You Have To Make A Function Declaration Above If The Difinition Of The Called Function Is Below Your Function


// Functions Declaration
void SwapByValue(short, short);
void SwapByPionter(short*, short*);
void SwapByReference(short&, short&);


int main()
{
    short a = 10, b = 20;

    cout << "Before Swapping:" << endl;
    cout << "a = " << a << " &  b = " << b << endl << endl;

    SwapByValue(a, b);
    cout << "After Swap By Value:" << endl;
    cout << "a = " << a << " &  b = " << b << endl << endl;

    SwapByPionter(&a, &b);
    cout << "After Swap By Pointer:" << endl;
    cout << "a = " << a << " &  b = " << b << endl << endl;

    short A = 10, B = 20;
    SwapByReference(A, B);
    cout << "After Swap By Reference:" << endl;
    cout << "A = " << A << " &  B = " << B << endl << endl;
	
	return 0;
}



// Calling By Value
void SwapByValue(short a, short b)
{
    short temp = 0;

    temp = a;
    a = b;
    b = temp;
}

// Calling By Pointer
void SwapByPionter(short* a, short* b)
{
    short temp = 0;

    temp = *a;
    *a = *b;
    *b = temp;
}


// Calling By Reference
void SwapByReference(short& a, short& b)
{
    short temp = 0;

    temp = a;
    a = b;
    b = temp;
}


