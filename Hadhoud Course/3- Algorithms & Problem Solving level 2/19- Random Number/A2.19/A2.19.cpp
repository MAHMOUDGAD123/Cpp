#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

// int random = (rand() % range) + offset;
// offset -> The starting point for the range of random numbers
// range -> The number of values between first and the last possible number including the limits.
// range = ( end point - offset + 1 )
/*
	ex: 

	Retrieve a random number between 100 and 200
	Offset = 100
	Range = 101

	int RandomNumber = rand() % (200 - 100 + 1) + 100;


	--> Look here: https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/
*/ 

int Generate_Random_Number(int From, int To)
{ 
	//Function To Generate A Random Number In Range Of (From -> To)

	return rand() % (To - From + 1) + From;
}




int main() 
{ 
	//Seeds the random number generator in C++, called only once 
	srand((unsigned)time(0));

	cout << endl;

	for (short i = 0; i <= 10; i++)
		cout << Generate_Random_Number(1, 10) << "  ";

	cout << endl << endl;
	

	return 0;
} 






























