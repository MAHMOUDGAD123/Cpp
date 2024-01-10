
#include <string>
#include <iostream>

using namespace std;


void FindIfYourNumberInArray(int Array[20], short arr_length)
{
    int Number = 0;
    cout << "What is the number you want to find?--> ";
    cin >> Number;
    cout << "\n\n";

    for (int i = 0; i < arr_length; i++)
    {
        if (Array[i] == Number) // if Number found 
        {
            cout << "\nWe find your number " << Array[i] << " at index " << i << endl << endl;
            break;
        }

        if ((i == arr_length - 1) && (Array[arr_length - 1] != Number)) // if Number not found
        {
            cout << "Sorry, your number is not at the list.\n\n";
        }
    }
   
}


int main()
{
    //int arr[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };

    // cout << end(arr) - begin(arr) << endl; // (end element {10} - begin element {0} = 10)

    // cout << sizeof(arr) / sizeof(int); // (40 / 4 = 10)

    //for (int i = 0; i <= 10; i++)
    //{
    //    if (arr[i] == 100)
    //    {
    //        cout << "We found number " << arr[i] << " at index " << i << " of the array.\n\n";
    //        break;
    //    }
    //}



    int Years[] = { 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010, 2011, 2012, 2013, 2014 };

    short arr_length = sizeof(Years) / sizeof(int);

    FindIfYourNumberInArray(Years, arr_length);
    

    

    return 0;
}


