
#include <iostream>


using namespace std;

// Calling By Value
void SwapByValue(short a, short b)
{
    short temp = 0;

    temp = a;
    a = b;
    b = temp;
}

// Calling By Pointer
void SwapByPionter(short *a, short *b)
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

    cout << "_______________________________________________\n\n";

    short A = 100, B = 200;

    cout << "Before Swapping:" << endl;
    cout << "A = " << A << " &  B = " << B << endl << endl;

    SwapByReference(A, B);
    cout << "After Swap By Reference:" << endl;
    cout << "A = " << A << " &  B = " << B << endl << endl;


    return 0;
}

