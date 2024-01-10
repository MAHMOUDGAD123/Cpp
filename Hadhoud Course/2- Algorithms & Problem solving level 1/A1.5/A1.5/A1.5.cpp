#define _use_math_defines


#include <string>
#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;


//*************************** PROGRAM 1 *****************************
// Age validation in range


bool IsItDigitOrNot(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
		return true;
	else
		return false;
}

bool check_number(string N) // to make sure that the age is numberical
{
	for (int i = 0; i < N.length(); i++)
	{
		if (IsItDigitOrNot(N[i]) == false)
		{
			return false;
		}
	}

	return true;

}

int ReadAge()
{
	string age;

	cout << "* * * * * * * * * * * * *\n";
	cout << "*  Only numbers allowed *\n";
	cout << "* * * * * * * * * * * * *\n\n";

	do 
	{
		cout << "Please enter your age?\n";
		cout << "Age : ";
		cin >> age;
		cout << "\n\n";
	}
	while (check_number(age) == false);
	
	return stoi(age);
}

bool ValidateNumberInRange(int number, int from, int to)
{
	return (number >= from && number <= to);
}

void PrintResult1(int age)
{
	if (ValidateNumberInRange(age, 18, 45))
		cout << "Your age is valid\n\n\n";
	else
		cout << "Your age is invalid\n\n\n";
}


//*************************** PROGRAM 2 *****************************
// Read Until age in range (18 - 45)
// using the same functions from program 1 + the next functions


int ReadUntilAgeInRange(int from, int to)
{
	int age = 0;

	do 
	{
		age = ReadAge();

	} while (!ValidateNumberInRange(age, from, to));

	return age;

}

void PrintResult2(int age)
{
	cout << "Your are " << age << " years old\n\n\n";
}


//*******************************************************************


int main()
{
    //PROGRAM 1
	//PrintResult1(ReadAge());

	//PROGRAM 2
	PrintResult2(ReadUntilAgeInRange(18, 45));


	return 0;
}

