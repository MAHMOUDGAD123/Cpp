#include <string>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

using namespace this_thread;
using namespace chrono_literals;
using chrono::system_clock;



void PrintNumbersFrom_1toN(int& N)
{
	cout << "\n\n";
	cout << "*****************************************\n\n";
	cout << "Printing numbers from 1 to N.\n\n";
	cout << "Please enter N : ";
	cin >> N;
	cout << "\n";

	for (int i = 1; i <= N; i++)
	{
		cout << i << endl;
	}

}

void PrintNumbersFrom_Nto1(int& N)
{
	cout << "\n\n";
	cout << "************************************\n\n";
	cout << "Printing numbers from N to 1.\n\n";
	cout << "Please enter N : ";
	cin >> N;
	cout << "\n";

	for (int i = N; i >= 1; i--)
	{
		cout << i << endl;
	}

}

void PrintSumOddNumbersfrom_1toN(int& N)
{
	cout << "\n\n";
	cout << "************************************\n\n";
	cout << "Printing sum of odd numbers from 1 to N.\n\n";
	cout << "Please enter N : ";
	cin >> N;
	cout << "\n";

	int i;
	int sum = 0;

	for (i = 1; i <= N; i += 2)
	{
		sum += i;
	}

	cout << "Sum of odd numbers from 1 to " << N << " = " << sum << endl;

}

void PrintSumEvenNumbersfrom_1toN(int& N)
{
	cout << "\n\n";
	cout << "************************************\n\n";
	cout << "Printing sum of even numbers from 1 to N.\n\n";
	cout << "Please enter N : ";
	cin >> N;
	cout << "\n";

	int i;
	int sum = 0;

	for (i = 0; i <= N; i += 2)
	{
		sum += i;
	}

	cout << "Sum of even numbers from 1 to " << N << " = " << sum << endl;

}

int PrintFactorialOf_N(int& N) // 3! = 3 * 2 * 1
{
	cout << "\n\n";
	cout << "*******************************\n";
	cout << "\n";
	cout << "Th factorial of N.\n\n";
	
XXX:
	
	cout << "Please enter N : ";
	cin >> N;

	if (N < 0)
	{
		cout << "\n" << "Only positive numbers are allowed.\n\n";
		goto XXX;
	}
	
	int factorial = 1; // initialization factroial = 1 when (N=0) then (0!=1)  

	for (int i = N; i >= 1; i--)
	{
		factorial *= i;
	}

	return factorial;

}

double N_of_Power_P(int& N, int& P)
{
	cout << "\n\n";
	cout << "*******************************\n\n";
	cout << "The N of power P.\n\n";
	cout << "Please enter N : ";
	cin >> N;
	cout << "Please enter P : ";
	cin >> P;
	cout << "\n\n";


	double Result = 1;

	if (P < 0) // for negative M
	{

		for (int i = abs(P); i >= 1; i--)
		{
			Result *= N;
		}

		return 1 / Result;
	}

	else
	{
		for (int i = P; i >= 1; i--)
		{
			Result *= N;
		}

		return Result;
	}

}

void PrintLettersFrom_A_To_Z()
{
	cout << "\n\n";
	cout << "**********************************************************************************************************************\n\n";
	cout << "Printting all letters form A to Z.\n\n";

	for (int i = 65; i <= 90; i++)
	{
		cout << char(i) << "  ";
	}

	cout << "\n\n";
	cout << "**********************************************************************************************************************";

}


int main()
{


	


	for (;;)

	{

		int N = 0, P = 0;

		cout << "\n\n";
		cout << "***************************************\n\n";
		cout << "Welcome to our Program - Please choose from the next :\n\n";
		cout << "1- Print all numbers from 1 to N\n";
		cout << "2- Print all numbers from N to 1\n";
		cout << "3- sum of odd numbers from 1 to N\n";
		cout << "4- sum of even numbers from 1 to N\n";
		cout << "5- Factorial of N\n";
		cout << "6- N of Power M\n";
		cout << "7- Print all english letters\n";
		cout << "8- EXit\n\n\n";

	XXX:

		string choice;
		cout << "Your choice : ";
		cin >> choice;

		if (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6" && choice != "7" && choice != "8")
		{
			cout << "Wrong choise - Please choose again.\n" << endl;
			sleep_for(1.5s);
			goto XXX;
		}
		else
		{
			if (choice == "1")
			{
				PrintNumbersFrom_1toN(N);
				sleep_for(3s);
			}
			else if (choice == "2")
			{
				PrintNumbersFrom_Nto1(N);
				sleep_for(3s);
			}
			else if (choice == "3")
			{
				PrintSumOddNumbersfrom_1toN(N);
				sleep_for(3s);
			}
			else if (choice == "4")
			{
				PrintSumEvenNumbersfrom_1toN(N);
				sleep_for(3s);
			}
			else if (choice == "5")
			{
				cout << "\n" << "The Factorial of " << N << " = " << PrintFactorialOf_N(N) << endl;
				sleep_for(3s);
			}
			else if (choice == "6")
			{
				cout << "\n" << "N of power P = " << N_of_Power_P(N, P) << endl;
				sleep_for(3s);
			}
			else if (choice == "7")
			{
				PrintLettersFrom_A_To_Z();
				sleep_for(3s);
			}
			else if (choice == "8")
			{
				exit(0);
			}

		}

	}

	return 0;
}


