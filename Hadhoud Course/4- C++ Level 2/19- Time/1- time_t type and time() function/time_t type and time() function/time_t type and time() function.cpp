#pragma warning(disable : 4996) // Turn off the warning for a project in Visual Studio

#include <iostream>
#include <ctime>  // <ctime> header file that contain date & time functions

using namespace std;


/*
    - Look here:

    time_t -> https://cplusplus.com/reference/ctime/time_t/

    time_t time(time_t* t) function:

    ---> Returns the number of seconds has passed since 00:00:00 GMT, Jan 1, 1970

    -> https://cplusplus.com/reference/ctime/time/
    -> https://www.programiz.com/cpp-programming/library-function/ctime/time

*/

int main()
{
    time_t Time_Now = time(NULL); // to get the current time

    cout << "-> The Number Of Seconds Since 1970 = " << Time_Now << endl;


    // Or you can use time() as void function to store the time

    // time_t time(time_t* timer)  -----> 'timer' is a pointer of type 'time_t'
  
    // (t) is a pointer of type 'time_t'
    time_t t{ 0 }; // Create a variable of type 'time_t'

    time(&t); // Stores the time in -> t

    cout << "-> The Number Of Seconds Since 1970 = " << t << endl;

    return 0;
}