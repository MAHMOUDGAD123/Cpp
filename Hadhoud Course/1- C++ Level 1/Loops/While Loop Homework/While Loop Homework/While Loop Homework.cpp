
#include <string>
#include <iostream>

using namespace std;


void PrintNumbersFrom_1To_N(int& N)
{
	
	cout << "Please enter a number : ";
	cin >> N;
	cout << "\n";

	int i = 1;
	while (i <= N)
	{
		cout << i << endl;
		i++;
	}


}

void PrintNumbersFrom_NTo_1(int& N)
{
	cout << "Please enter a number : ";
	cin >> N;
	cout << "\n";

	int i = N;
	while (i >= 1)
	{
		cout << i << endl;
		i--;

	}

}

int PrintSumOfOddNumbersFrom_1To_N(int& N)
{
	cout << "Please enter a number : ";
	cin >> N;
	cout << "\n";

	int i = 1;
	int sum = 0;
	while (i <= N)
	{
		sum += i;
		i += 2;
	}

	return sum;
}

int PrintSumOfEvenNumbersFrom_1To_N(int& N)
{
	cout << "Please enter a number : ";
	cin >> N;
	cout << "\n";

	int i = 0;
	int sum = 0;
	while (i <= N)
	{
		sum += i;
		i += 2;
	}

	return sum;
}

float FactorialOf_N(int& N)
{
	cout << "Please enter a number : ";
	cin >> N;
	cout << "\n";

	int factorial = 1;
	int i = N;

	while (i >= 1)
	{
		factorial *= i;
		i--;
	}

	return factorial;
}

float PowerOf_N(int& N, int& P)
{
	cout << "Please enter a number : ";
	cin >> N;
	cout << "Please enter the power : ";
	cin >> P;
	cout << "\n";


	if (P < 0)
	{
		int i = abs(P);
		int Result = 1;

		while (i >= abs(P))
		{
			Result *= N;
			i--;
		}

		return (float)1 / Result;

	}

	else
	{
		int i = 1;
		int Result = 1;

		while (i <= P)
		{
			Result *= N;
			i++;
		}

		return Result;

	}

	
}

float SumUserInputUntil_Negative99In(int& N)
{

	float sum = 0;

	cout << "Please enter a number : ";
	cin >> N;
	cout << "\n";

	
	while (N != -99)
	{
		sum += N;

		cout << "Please enter a number : ";
		cin >> N;
		cout << "\n";

	}

	return (float)sum;

}

void PrintLettersFromAtoZ()
{
	int i = 65;

	while (i <= 90)
	{
		cout << char(i) << endl;
		i++;
	}
}


void AtmPin()
{
	string PIN;
	cout << "Please enter the PIN number : ";
	cin >> PIN;
	cout << "\n";

	int i = 1;
	while (PIN != "1234")
	{
		cout << " Wrong PIN, Please enter the PIN again.\n\n";
		i++;
		cout << "Please enter the PIN number : ";
		cin >> PIN;
		cout << "\n";
		

		while (i == 3 && PIN != "1234")
		{
			cout << "Card is Locked." << endl;
			exit(0);
		
		}


	}


	cout << "your balance is : 1000000 $\n\n" << endl;

}


int main()
{
	int N, P;


	//PrintNumbersFrom_1To_N(N);
	//PrintNumbersFrom_NTo_1(N);

	//cout << "The sum of odd numbers between 1 to " << N << " = " << PrintSumOfOddNumbersFrom_1To_N(N) << endl;

	//cout << "The sum of even numbers between 1 to " << N << " = " << PrintSumOfEvenNumbersFrom_1To_N(N) << endl;

	//cout << "The factorial of your number = " << FactorialOf_N(N) << endl;

	//cout << "The Power " << P << " of " << N << " = " << PowerOf_N(N, P) << endl;

	//cout << "\nThe sum of all numbers = " << SumUserInputUntil_Negative99In(N) << endl;

	//PrintLettersFromAtoZ();

	AtmPin();


	return 0;
}
