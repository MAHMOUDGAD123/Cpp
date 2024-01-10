
#include <iostream>

using namespace std;



int Sum(short a, short b, short c = 0, short d = 0) // (c , d) are Default Parameters
{
    return (a + b + c + d);
}

int Multiplier(short a, short b, short c = 1, short d = 1)
{
    return (a * b * c * d);
}


int main()
{
    cout << "Sum = " << Sum(10, 20) << endl;
    cout << "Sum = " << Sum(10, 20, 30) << endl;
    cout << "Sum = " << Sum(10, 20, 30, 40) << endl;
    cout << endl << endl;

    cout << "a * b = " << Multiplier(10, 20) << endl;
    cout << "a * b * c = " << Multiplier(10, 20, 30) << endl;
    cout << "a * b * c * d = " << Multiplier(10, 20, 30, 40) << endl;

    return 0;
}


