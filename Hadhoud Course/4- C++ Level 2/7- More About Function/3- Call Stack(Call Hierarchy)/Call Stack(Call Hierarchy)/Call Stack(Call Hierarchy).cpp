
#include <iostream>

using namespace std;

// Declarations
void Function1();
void FuckinFunction();


void FuckinFunction()
{
    cout << "Fuck You!" << endl;
}

void Function3()
{
    cout << "Call Function4" << endl;
    FuckinFunction();
}

void Function2()
{
    cout << "Call Function3" << endl;
    Function3();
}

void Function1()
{
    cout << "Call Function2" << endl;
    Function2();
    Function3();
}


int main()
{
    cout << "Call Function1" << endl;
    Function1();
    FuckinFunction();

    return 0;
}

