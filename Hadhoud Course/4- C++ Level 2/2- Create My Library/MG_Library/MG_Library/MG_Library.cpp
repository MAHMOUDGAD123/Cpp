#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <cstdlib>
#include "MGLib.h" // include your library

using namespace std;
using namespace MGLib; // Use the namespace of your library

int main()
{
    short arr[100], arr_length = 0;

    arr_length = Read_Positive_Int_Number("What is the array length?");


    Fill_Array_SimiDynamic_ByUserInput_For(arr, arr_length);
    cout << "Array = { ";
    for (short i = 0 ; i < arr_length; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "\b\b }" << endl << endl;

    V_UnderScores(50);
    cout << endl << endl;

    Array_ZeroFill(arr, arr_length);
    cout << "Array Zero Fill = { ";
    for (short i = 0; i < arr_length; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "\b\b }" << endl << endl;


    V_UnderScores(50);
    cout << endl << endl;


    Fill_Array_With_Random_Numbers_From1toN_NoRepeating(arr, arr_length);
    cout << "Array = { ";
    for (short i = 0; i < arr_length; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "\b\b }" << endl;

    return 0;
}


