#pragma warning(disable : 4996) // Turn off the warning for a project in Visual Studio

#include <iostream>
#include <ctime>  // <ctime> header file that contain date & time functions

using namespace std;


int main()
{
    time_t* time_now = new time_t(time(NULL)); // to get the current time
    char* Date_Time = 0;
    tm* GMT_tm = 0;
    
    Date_Time = ctime(time_now);
    cout << "-> Time & Date in GMT+2 = " << Date_Time << endl;

    Date_Time = asctime(gmtime(time_now));
    cout << "-> Time & Date in GMT   = " << Date_Time << endl;

    delete time_now;
    time_now = NULL;

    return 0;
}