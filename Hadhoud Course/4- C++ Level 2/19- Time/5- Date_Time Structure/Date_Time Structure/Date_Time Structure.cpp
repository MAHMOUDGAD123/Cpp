#pragma warning(disable : 4996)

#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;


/* 

    int tm_sec; // seconds of minutes from (0 to 60)
    int tm_min; // minutes of hour from (0 to 59)
    int tm_hour; // hours of day from (0 to 24)
    int tm_mon; // month of year from (0 to 11)
    int tm_year; // year since 1900
    int tm_wday; // days since sunday from (0 -> 6)
    int tm_mday; // day of month from (1 to 31)
    int tm_yday; // days since January 1st from (0 -> 365)
    int tm_isdst; // hours of daylight savings time


    -> tm_sec is generally 0-59. The extra range is to accommodate for leap seconds in certain systems.
    
    -> The Daylight Saving Time flag (tm_isdst) is greater than zero if Daylight Saving Time is in effect,
       zero if Daylight Saving Time is not in effect, and less than zero if the information is not available.

*/

int main()
{
    time_t TimeNow = time(NULL); // Get the time now in seconds

    tm* LocalTime = localtime(&TimeNow);

    cout << "\n_______________________________________________________________\n\n";

    cout << "-> Seconds   = " << LocalTime->tm_sec << endl;
    cout << "-> Minutes   = " << LocalTime->tm_min << endl;
    cout << "-> Hours     = " << LocalTime->tm_hour << endl; // in 24 format
    cout << "-> Month     = " << LocalTime->tm_mon + 1 << endl; // +1 to make because it's from ( 1 -> 11 )
    cout << "-> Year      = " << LocalTime->tm_year + 1900 << endl; // +1900 ( Since 1900 )
    cout << "-> Weak Day  = " << LocalTime->tm_wday + 1 << endl; // Since sunday (0 -> 6)
    cout << "-> Month Day = " << LocalTime->tm_mday << endl;
    cout << "-> Year Day  = " << LocalTime->tm_yday + 1 << endl; // +1 Since january 1st ( 0 -> 365 )
    
    cout << "\n-> Daylight Saving Time Flag = " << LocalTime->tm_isdst << endl;

    cout << "____________________________ Test _____________________________\n\n";

    printf("-> Today's Date Is: { %2d / %2d / %4d }\n", LocalTime->tm_mday, LocalTime->tm_mon, LocalTime->tm_year + 1900);
    printf("\n-> Time Now Is: { %02d : %02d : %02d }\n", LocalTime->tm_hour, LocalTime->tm_min, LocalTime->tm_sec);


    cout << "_______________________________________________________________\n";





    return 0;
}