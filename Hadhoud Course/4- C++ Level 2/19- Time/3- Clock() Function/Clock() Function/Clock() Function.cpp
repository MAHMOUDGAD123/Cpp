#include <iostream>
#include <cstdio> /* printf */
#include <ctime>  /* clock_t, clock, CLOCKS_PER_SEC */
#include <cmath>  /* sqrt */
#include <string>

using namespace std;


// look here -> https://www.programiz.com/cpp-programming/library-function/ctime/clock


// Divide by { CLOCKS_PER_SEC } to convert the Clicks into seconds


int main()
{
    clock_t* Time_Req = new clock_t(0);

    int N = 10000000;  // Number of iterations
    double* R = new double{ 0 };
    unsigned int* i = new unsigned int{ 0 };

    *Time_Req = clock(); // to start counting

    // Using C++ pow()
    for (*i; *i < N; (*i)++)
    {
        *R = pow(*i, 5);
    }

    *Time_Req = clock() - *Time_Req; // to get the required time
    printf("-> using pow It Needs %d Clicks (%f Seconds)\n", *Time_Req, (float)*Time_Req / CLOCKS_PER_SEC);
    
    *Time_Req = clock(); // to start counting

    // Without C++ pow()
    for (*i = 0; *i < N; (*i)++)
    {
        *R = *i * *i * *i * *i * *i;
    }

    *Time_Req = clock() - *Time_Req; // to get the required time
    printf("-> Without using pow It Needs %d Clicks (%f Seconds)\n", *Time_Req, (float)*Time_Req / CLOCKS_PER_SEC);



    return 0;
}
