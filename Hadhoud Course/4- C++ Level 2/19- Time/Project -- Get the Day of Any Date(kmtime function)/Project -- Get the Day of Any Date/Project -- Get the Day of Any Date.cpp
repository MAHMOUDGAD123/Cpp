#pragma warning(disable : 4996)

#include <iostream>
#include <string>
#include <ctime>
#include <cstdio>


using namespace std;


/*

    Using mktime() function

    -> https://www.programiz.com/cpp-programming/library-function/ctime/mktime
    -> https://cplusplus.com/reference/ctime/mktime/

*/


void Get_TheDayOfAnyDate()
{
    time_t* Timenow = new time_t{ 0 };
    tm* TimeInfo;

    int* year = new int{ 0 };
    int* month = new int{ 0 };
    int* day = new int{ 0 };

    const char* WeakDays[]{ "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };

    // Read data from user
    cout << "Enter The Year: ";
    cin >> *year;
    cout << "Enter The Month: ";
    cin >> *month;
    cout << "Enter The Day: ";
    cin >> *day;

    // Get the current & Modify the user data

    time(Timenow); // Get current time
    TimeInfo = localtime(Timenow);

    TimeInfo->tm_year = *year - 1900;
    TimeInfo->tm_mon = *month - 1;
    TimeInfo->tm_mday = *day;

    
    // call { mktime() } function --> to set the { TimeInfo->tm_wday }
    mktime(TimeInfo);

    printf("\n-> The Day Is: { %s }\n", WeakDays[TimeInfo->tm_wday]);

    delete Timenow, TimeInfo, year, month, day;
}


int main()
{

    Get_TheDayOfAnyDate();


    return 0;
}