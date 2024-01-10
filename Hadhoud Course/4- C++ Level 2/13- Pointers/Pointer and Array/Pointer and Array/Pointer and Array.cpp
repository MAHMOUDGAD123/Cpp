
#include <iostream>

using namespace std;





int main()
{
    short Array[5] = {10,20,30,40,50};

    short* ptr = Array; // equal to ==> short* ptr = &Array[0]

    /*
        - You have to know that:
        -> (Array) is an unmodifiable Pointer to the first element of the Array { Array[0] }.
        -> (ptr) is a modifiable pointer to the first element of the Array { Array[0] }.

        so --> (ptr) & (Array) pointers are the same
    */

    cout << "Array     = " << Array << endl;
    cout << "&Array[0] = " << &Array[0] << endl;
    cout << "ptr       = " << ptr << endl;
    cout << endl;

    cout << "_____________________________________\n\n";

    cout << "Using (Array) Pointer:\n\n";

    // Print the addresses of the Array elements using (Array) pointer
    cout << "The address of element 0 = " << Array << endl;
    cout << "The address of element 1 = " << Array + 1 << endl;
    cout << "The address of element 2 = " << Array + 2 << endl;
    cout << "The address of element 3 = " << Array + 3 << endl;
    cout << "The address of element 4 = " << Array + 4 << endl;
    cout << endl << endl;

    // Print the values of the Array using (Array) pointer
    cout << "The value of element 0 = " << *(Array) << endl;
    cout << "The value of element 1 = " << *(Array + 1) << endl;
    cout << "The value of element 2 = " << *(Array + 2) << endl;
    cout << "The value of element 3 = " << *(Array + 3) << endl;
    cout << "The value of element 4 = " << *(Array + 4) << endl;
    cout << endl;


    cout << "_____________________________________\n\n";

    cout << "Using (ptr) Pointer:\n\n";

    // Print the addresses of the Array elements using (ptr) pointer
    cout << "The address of element 0 = " << ptr << endl;
    cout << "The address of element 1 = " << ptr + 1 << endl;
    cout << "The address of element 2 = " << ptr + 2 << endl;
    cout << "The address of element 3 = " << ptr + 3 << endl;
    cout << "The address of element 4 = " << ptr + 4 << endl;
    cout << endl << endl;

    // Print the values of the Array using (ptr) pointer
    cout << "The value of element 0 = " << *(ptr) << endl;
    cout << "The value of element 1 = " << *(ptr + 1) << endl;
    cout << "The value of element 2 = " << *(ptr + 2) << endl;
    cout << "The value of element 3 = " << *(ptr + 3) << endl;
    cout << "The value of element 4 = " << *(ptr + 4) << endl;
    cout << endl;

    cout << "_____________________________________\n\n";

    string FullName[7] = {"My", "Name", "Is:", "Mahmoud", "Abdelrahman", "Ismail", "Gad"};

    string* ptr1 = FullName;

    cout << "Printing \"FullName\" Array using pointer:\n{ ";
    for (short i = 0; i < sizeof(FullName) / sizeof(string); i++)
    {
        cout << *(ptr1 + i) << " "; // You can use -> ptr1[i] to print the elements
    }
    cout << "}" << endl << endl;



    return 0;
}
