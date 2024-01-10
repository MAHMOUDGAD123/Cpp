#include <iostream>
#include <vector>

using namespace std;


// Exception Handling slow down the program 
// So, you must not use it except if it's inevitable

// https://www.geeksforgeeks.org/exception-handling-c/


// Here we specify the exceptions that this function throws.

void fun(int* ptr, int x) throw (int*, int) // Dynamic Exception specification
{
    if (ptr == NULL)
        throw ptr;
    if (x == 0)
        throw x;
}


int main()
{

    try {
        fun(NULL, 0);
    }
    catch (...) {
        cout << "\nCaught exception from fun()\n\n";
    }

    
    return 0;
}