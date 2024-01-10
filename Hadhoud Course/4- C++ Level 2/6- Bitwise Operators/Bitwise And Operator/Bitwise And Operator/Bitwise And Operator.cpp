
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <cstdlib>
#include "MGLib.h"

using namespace std;


// C++ Operators:
// https://www.programiz.com/cpp-programming/operators#bitwise



int main()
{
    short N1 = 0, N2 = 0;

    N1 = Read_Positive_Number("Please, Enter The First Number");
    N2 = Read_Positive_Number("Please, Enter The Second Number");

    cout << "Original N1 = " << N1 << endl;
    cout << "Oroginal N2 = " << N2 << "\n\n";

    cout << "N1 AND N2 = " << (N1 & N2) << '\n';
    cout << "N1 OR N2 = " << (N1 | N2) << "\n";
    cout << "N1 XOR N2 = " << (N1 ^ N2) << "\n\n";

    N1 &= 3; // AND
    cout << "N1 AND 3 = " << N1 << endl;

    N1 |= 3; // OR
    cout << "N1 OR 3 = " << N1 << endl;

    N2 ^= 3; // XOR
    cout << "N2 XOR 3 = " << N2 << "\n\n";

    N1 <<= 2; // Shift Left
    cout << "N1 << 2 = " << N1 << endl;

    N2 >>= 2; //Shift Right
    cout << "N2 >> 2 = " << N2 << endl;




    return 0;
}