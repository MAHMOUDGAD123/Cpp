#include <iostream>
#include <string>


// https://www.geeksforgeeks.org/stdstringresize-in-c/

using namespace std;

int main()
{
   // string::resize(unsigned n, char c)

    string S1{ "This C" };

    cout << endl << "___________________________________________________________________" << endl << endl;


    cout << "- S1 Before Resizing: \" " << S1 << " \"" << endl;
    cout << "- Size Of S1 Before Resizing = " << S1.size() << endl;

    S1.resize(S1.size() + 2, '+');
    cout << "- S1 After Resizing: \" " << S1 << " \"" << endl;
    cout << "- Size Of S1 After Resizing = " << S1.size() << endl;

    S1.resize(6);
    cout << "- S1 After Resizing: \" " << S1 << " \"" << endl;
    cout << "- Size Of S1 After Resizing = " << S1.size() << endl;

    // when resizing up with nothing resize() add a NULL values (add nothing)
    // but it only increase the size of the string
    S1.resize(20);
    cout << "- S1 After Resizing: \" " << S1 << " \"" << endl;
    cout << "- Size Of S1 After Resizing = " << S1.size() << endl;


    cout << endl << "___________________________________________________________________" << endl << endl;


  return 0;
}