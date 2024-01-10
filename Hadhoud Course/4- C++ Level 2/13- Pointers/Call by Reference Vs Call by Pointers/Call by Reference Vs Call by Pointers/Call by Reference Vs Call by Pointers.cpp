
#include <iostream>

using namespace std;

// Take a value parameters
void Swap_byReference(short& N1, short& N2)
{
    short temp;
    temp = N1;
    N1 = N2;
    N2 = temp;
}

// Take an address parameters
void Swap_byPointers(short* N1, short* N2)
{
    short temp;
    temp = *N1;
    *N1 = *N2;
    *N2 = temp;
}

// (*&) -> Means Reference to a Pointer
// Take a pointer parameters
void Swap_byRefPointer(short*& N1, short*& N2)
{
    short temp;
    temp = *N1;
    *N1 = *N2;
    *N2 = temp;
}


int main()
{
    short a = 10, b = 20;

    cout << "- (a, b) Before Swapping:" << endl;
    cout << "-> a = " << a << endl;
    cout << "-> b = " << b << endl << endl;

    // Swap by Reference
    Swap_byReference(a, b);

    cout << "- (a, b) After Swapping By Reference:" << endl;
    cout << "-> a = " << a << endl;
    cout << "-> b = " << b << endl;

    cout << "\n_____________________________________\n\n";

    short x = 100, y = 200;

    cout << "- (x, y) Before Swapping:" << endl;
    cout << "-> x = " << a << endl;
    cout << "-> y = " << b << endl << endl;

    Swap_byPointers(&x, &y);

    cout << "- (x, y) After Swapping By Pointer:" << endl;
    cout << "-> x = " << a << endl;
    cout << "-> y = " << b << endl;

    cout << "\n_____________________________________\n\n";

    short w = 33, z = 77;

    short* wp = &w;
    short* zp = &z;

    cout << "- (w, z) Before Swapping:" << endl;
    cout << "-> w = " << w << endl;
    cout << "-> z = " << z << endl << endl;

    Swap_byRefPointer(wp, zp);

    cout << "- (w, z) After Swapping By Ref_Pointer:" << endl;
    cout << "-> w = " << w << endl;
    cout << "-> z = " << z << endl;

    cout << "\n_____________________________________\n\n";


    return 0;
}
