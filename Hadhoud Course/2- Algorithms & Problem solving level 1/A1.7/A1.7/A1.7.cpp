#include <iostream>
#include <string>

using namespace std;

//*************************************** Global Functions *******************************************

bool IsItDigitOrNot(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
		return true;
	else
		return false;
}

bool Check_Number(string N)
{
	for (int i = 0; i < N.length(); i++)
	{
		if (IsItDigitOrNot(N[i]) == false)
			return false;
	}

	return true;
}

int ReadNumber()
{
	string N;

	do
	{
		cout << "Please, enter a number?\n";
		cin >> N;

	} while (Check_Number(N) == false);

	return stoi(N);
}

int ReadNumberInRange(int from, int to)
{
	int Number;
	do 
	{
		cout << "Please, enter a numbe between " << from << " & " << to << " ?" << endl;
		cout << "your Answer : ";
		cin >> Number;
		cout << "\n\n";

	} while (!(Number >= from && Number <= to));

	return Number;
}

//*********************************** PROGRAM 1 ************************************
// N of Powers P


int ReadPower()
{
	string P;

	do
	{
		cout << "Please, enter the power?\n";
		cin >> P;

	} while (Check_Number(P) == false);

	return stoi(P);
}

void N_Of_Power_P(int Number, int Power)
{
	int Result = 1;
	for (int i = 0; i < Power; i++)
	{
		Result *= Number;
	}


	cout << "\n\n" << Number << "^" << Power << " = " << Result << endl;

}



//*********************************** PROGRAM 2 ************************************
// Student Grade


char Sturdent_Grade(int N)
{
	if (N >= 90)
		return 'A';
	else if (N >= 80)
		return 'B';
	else if (N >= 70)
		return 'C';
	else if (N >= 60)
		return 'D';
	else if (N >= 50)
		return 'E';
	else
		return 'F';

}


//*********************************** PROGRAM 3 ************************************
// Commission Percentage of sales


int ReadTotalSales()
{
	string N;

	do
	{
		cout << "Please, enter your total sales?\n";
		cin >> N;

	} while (Check_Number(N) == false);

	return stoi(N);
}

float GetCommissionPercentageOfSales(int TotalSales)
{
	if (TotalSales > 1000000)
		return 0.01;
	else if (TotalSales > 500000)
		return 0.02;
	else if (TotalSales > 100000)
		return 0.03;
	else if (TotalSales > 100000)
		return 0.05;
	else
		return 0.0;
	
}

float CalculateCommission(int TotalSales)
{
	return GetCommissionPercentageOfSales(TotalSales) * TotalSales;
}


//*********************************** PROGRAM 4 ************************************
// Piggy bank Calculator

struct st_PiggyBankContent
{
	float Penny, Nickel, Dime, Quarter, Dollar;
};

st_PiggyBankContent ReadMoney()
{
	st_PiggyBankContent Money;

	cout << "Please enter how much do you have of the next ?\n";

	cout << "Pennies : ";
	cin >> Money.Penny;

	cout << "Nickeles : ";
	cin >> Money.Nickel;

	cout << "Dimes : ";
	cin >> Money.Dime;

	cout << "Quarters : ";
	cin >> Money.Quarter;

	cout << "Dollars : ";
	cin >> Money.Dollar;

	cout << "\n\n";

	return Money;

	

}

int CalculateTotalPinnies(st_PiggyBankContent Money)
{
	return Money.Penny + Money.Nickel * 5 + Money.Dime * 10 + Money.Quarter * 25 + Money.Dollar * 100;
}




int main()
{

	// PROGRAM 1
	//int Number = ReadNumber();
	//int Power = ReadPower();
	//N_Of_Power_P(Number, Power);
	//N_Of_Power_P(ReadNumber(), ReadPower());


	// PROGRAM 2
	//cout << "Your Result is : " << Sturdent_Grade(ReadNumberInRange(0,100)) << endl << endl;


	// PROGRAM 3
	//float TotalSales = ReadTotalSales();
	//cout << "- The commission Percentage = " << GetCommissionPercentageOfSales(TotalSales) << endl << endl;
	//cout << "- Your commission Percentage = " << CalculateCommission(TotalSales) << endl << endl;


	// PROGRAM 4
	/*int TotalNumberOfPinnies = CalculateTotalPinnies(ReadMoney());
	cout << "The Total number of Pinnes = " << TotalNumberOfPinnies << " Pinnies" << endl << endl;
	cout << "The Total number of Dollars = " << (float)TotalNumberOfPinnies / 100 << " Dollars" << endl << endl;*/

	// PROGRAM 4 ANOTHER SOLUTION
	st_PiggyBankContent Money = ReadMoney();
	cout << "The Total number of Pinnes = " << CalculateTotalPinnies(Money) << " Pinnies" << endl << endl;
	cout << "The Total number of Pinnes = " << (float) CalculateTotalPinnies(Money) / 100 << " Dollars" << endl << endl;


	return 0;
}