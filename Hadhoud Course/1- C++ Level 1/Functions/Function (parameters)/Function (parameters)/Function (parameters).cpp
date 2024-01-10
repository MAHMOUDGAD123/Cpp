
#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <math.h>
#include <cmath>


using namespace std;

void SecToDays_Hrs_Mins(int TotalSec)
{ 
    int R = 0;
   
    int Days = floor( TotalSec / (24 * 60 * 60) );
    R = TotalSec % (24 * 60 * 60);

    int Hours = floor( R / (60 * 60) );
    R = R % ( 60 * 60 );

    int Minutes = floor( R / 60 );
    R = R % 60;

    int Seconds = R;

    cout << "The Result is : " << Days << " Days " << " & " << Hours << " Hours " << " & " << Minutes << " minutes " << " & " << Seconds << " Seconds. ";
}




int main()
{
    int TotalSec;

    cout << "Please enter the Total Seconds : ";
    cin >> TotalSec;
    cout << "\n";

  
    SecToDays_Hrs_Mins(TotalSec);
   
    
    return 0;
}
