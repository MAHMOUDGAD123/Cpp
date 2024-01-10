#pragma warning(disable : 4996)

#include <iostream>
#include <ctime>
#include <cstdio>

using namespace std;

/*

    look here --->https://www.programiz.com/cpp-programming/library-function/ctime

    &

    look here ---> https://cplusplus.com/reference/ctime/

*/
int main()
{
    time_t* Curr_Time = new time_t(time(NULL)); // (Curr_Time) is a pointer for the the value of { time(NuLL) }
    tm* tm_ptr = 0; // pointer for 'struct tm'
    char* Date_Time = 0; // pointer for 'string' 



    cout << "\n__________________________________ (1) ctime() function __________________________________\n\n\n";

    // char* ctime(const time_t* time_ptr);
    // Convert time_t value to string


    Date_Time = ctime(Curr_Time);

    cout << "-> Local Date & Time in GMT+2 Is:  " << Date_Time;

    cout << "\n__________________________________ (2) gmtime() function _________________________________\n\n\n";

    // struct tm * gmtime (const time_t * timer);
    // Convert time_t to tm as UTC time (GMT)

    tm_ptr = gmtime(Curr_Time);

    printf("The Current time Is: { %2d : %02d : %02d } GMT", tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec);

    cout << "\n\n__________________________________ (3) localtime() function ______________________________\n\n\n";

    // struct tm * localtime (const time_t * timer);
    // Convert time_t to tm as local time

    tm_ptr = localtime(Curr_Time);

    printf("The Current time Is: { %2d : %02d : %02d } GMT+2", tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec);

    cout << "\n\n__________________________________ (4) asctime() function ________________________________\n\n\n";

    // char* asctime (const struct tm * time_ptr)
    // Convert tm structure to string

    Date_Time = asctime(localtime(Curr_Time));

    cout << "-> Date & Time In GMT+2 Is :  " << Date_Time;

    Date_Time = asctime(gmtime(Curr_Time));

    cout << "\n-> Date & Time In GMT Is   :  " << Date_Time;

    cout << "\n__________________________________________________________________________________________\n\n";

    return 0;
}