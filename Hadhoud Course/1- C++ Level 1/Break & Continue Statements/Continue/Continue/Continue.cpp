
#include <string>
#include <iostream>
#include <ctype.h>

using namespace std;


bool isitdigit(char c)
{
    if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool check_number(string N)
{
    for (int i = 0; i < N.length(); i++)
    {
        if ( isitdigit(N[i]) == false )
        {
            return false;
        }
    }

    return true;
}



int main()
{
    string N;
    int sum = 0;

    cout << "Please enter 7 numbers to sum them.\n\n";

   
    for (int i = 1; i <= 7; i++)
    {


        cout << "-- Enter the " << i << " number : ";
        cin >> N;
        cout << "\n";


        while (check_number(N) == false)
        {
            cout << "Only numbers are allowed.\n";
            cout << "-- Enter the " << i << " number : ";
            cin >> N;
            cout << "\n";
        }




        if (stoi(N) > 50)
        {
            cout << "The " << N << " is skiped because it's > 50.\n\n";
            continue;
        }


        sum += stoi(N);
        cout << N << " is added\n\n";


    }
    

    cout << "**********************************************\n\n";
    cout << "The sum of all numbers (under 50) = " << sum << endl << endl;
    cout << "**********************************************\n\n";

    return 0;
}


