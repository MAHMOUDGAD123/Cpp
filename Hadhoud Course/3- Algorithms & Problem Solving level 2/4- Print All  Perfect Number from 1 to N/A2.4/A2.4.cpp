#include <string>
#include <iostream>

using namespace std;



//***************************************************************************************************
//************************************ Global Functions *********************************************
//***************************************************************************************************

bool Check_TheNumberOfDigits(string N, int NumberOfDigits)
{
	if (N.length() == NumberOfDigits)
		return true;
	else
		return false;
}

bool CheckNumber_InRange(string N, int from, int to)
{
	if (stoi(N) >= from && stoi(N) <= to)
		return true;
	else
		return false;
}

bool Check_PositiveOrNot(string N)
{
	if (stoi(N) > 0)
		return true;
	else
		return false;
}

bool IsItDigitOrNot(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '.' || c == '-')
		return true;
	else
		return false;
}

bool Integer_Only(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '-')
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

bool Check_Number_Int(string N)
{
	for (int i = 0; i < N.length(); i++)
	{
		if (Integer_Only(N[i]) == false)
			return false;
	}

	return true;
}

int Read_Int_Number(string Message)
{
	string N;

	do
	{
		cout << Message << endl;
		cout << "your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!Check_Number_Int(N));

	return stoi(N);
}

int Read_Positive_Int_Number(string Message)
{
	string N;

	do
	{
		cout << Message << endl;
		cout << "your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!(Check_Number_Int(N) && Check_PositiveOrNot(N)));

	return stoi(N);
}

int Read_Positive_Int_Number_With_specificNumberOfDigits(string Message, int NumberOfDigits)
{
	string N;

	do
	{
		cout << Message << endl;
		cout << "your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!(Check_Number_Int(N) && Check_PositiveOrNot(N) && Check_TheNumberOfDigits(N, NumberOfDigits)));

	return stoi(N);
}

float Read_Positive_Number(string Message)
{
	string N;

	do
	{
		cout << Message << endl;
		cout << "your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!(Check_Number(N) && Check_PositiveOrNot(N)));

	return stof(N);
}

float ReadNumber(string Message)
{
	string N;

	do
	{
		cout << Message << endl;
		cout << "your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!Check_Number(N));

	return stof(N);
}

unsigned int Read_Positive_Int_NumberInRange_Message(string Message, int from, int to)
{
	string N;
	do
	{
		//cout << "Enter a number between " << from << " & " << to << " : " << endl;
		cout << Message << endl;
		cout << "Your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!(Check_Number_Int(N) && CheckNumber_InRange(N, from, to) && Check_PositiveOrNot(N)));

	return stoi(N);
}

unsigned int Read_Positive_Int_NumberInRange(int from, int to)
{
	string N;
	do
	{
		//cout << "Enter a number between " << from << " & " << to << " : " << endl;
		cout << "Your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!(Check_Number_Int(N) && CheckNumber_InRange(N, from, to) && Check_PositiveOrNot(N)));

	return stoi(N);
}

unsigned int Read_Positive_NumberInRange_Message(string Message, int from, int to)
{
	string N;
	do
	{
		//cout << "Enter A Number Between " << from << " & " << to << " : " << endl;
		cout << Message << endl;
		cout << "Your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!(Check_Number(N) && CheckNumber_InRange(N, from, to) && Check_PositiveOrNot(N)));

	return stoi(N);
}

int ReadNumberInRange_Message(string Message, int from, int to)
{
	string N;
	do
	{
		//cout << "Enter A Number Between " << from << " & " << to << " : " << endl;
		cout << Message << endl;
		cout << "Your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!(Check_Number(N) && CheckNumber_InRange(N, from, to)));

	return stoi(N);
}

bool Check_Prime(int N)
{
	int Half_N = ceil(N / 2);

	for (int i = 2; i <= Half_N; i++)
	{
		if (N % i == 0)
		{
			return false;
		}

	}

	return true;
}

bool IsPerfect_Number(unsigned int N)
{
	unsigned int Half_N = ceil(N / 2);
	unsigned int sum = 0;

	for (unsigned int i = 1; i <= Half_N; i++)
	{
		if (N % i == 0)
		{
			sum += i;
		}
	}

	return sum == N; // return (true) when equal & return (false) when not equal

	/*
	we can use :

	  =>  return sum == N;

	or we can use:

	  =>  if (sum == N)
			 return true;
		 else
			 return false;
	*/
}



//*********************************************************************************************************
//*********************************************************************************************************

void Print_AllPerfectNumbers_From1ToN(unsigned int N)
{
	cout << "All Perfect number form 1 to " << N << " are : ";

	for (unsigned int i = 1; i <= N; i++)
	{
		if (IsPerfect_Number(i))
		{
			cout << "( " << i << " )";
		}
	}
	cout << endl << endl;
}





int main()
{
	Print_AllPerfectNumbers_From1ToN(Read_Positive_Number("Please, enter a positive integer number?"));

	return 0;
}

