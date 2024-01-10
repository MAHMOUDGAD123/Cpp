#pragma warning(disable : 4996)

#include <iostream>
#include <ctime>

using namespace std;

// look here -> https://www.programiz.com/cpp-programming/library-function/ctime/difftime

int main()
{
    time_t Start, Finish;

    int R = 0;

    time(&Start);

    for (int i = 0; i < 100000; i++)
    {
        for (int j = 0; j < 100000; j++)
            R = i * j;
    }
    
    time(&Finish);

    // double difftime(time_t end,time_t begin);

    cout << "The Required Time = " << difftime(Finish, Start) << " Seconds" << endl;


    return 0;
}