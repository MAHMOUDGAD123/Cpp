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
	if (stoul(N) >= from && stoul(N) <= to)
		return true;
	else
		return false;
}

bool Check_PositiveOrNot(string N)
{
	if (stod(N) > 0)
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

bool Positive_Integer_Only(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
		return true;
	else
		return false;
}

bool Positive_Only(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '.')
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

bool Check_Positive_Number_Int(string N)
{
	for (int i = 0; i < N.length(); i++)
	{
		if (Positive_Integer_Only(N[i]) == false)
			return false;
	}

	return true;
}

bool Check_Positive_Number(string N)
{
	for (int i = 0; i < N.length(); i++)
	{
		if (Positive_Only(N[i]) == false)
			return false;
	}

	return true;
}

long long Read_Int_Number(string Message)
{
	string N;

	do
	{
		cout << Message << endl;
		cout << "your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!Check_Number_Int(N));

	return stoll(N);
}

unsigned long long Read_Positive_LLInt_Number(string Message)
{
	string N;

	do
	{
		cout << Message << endl;
		cout << "your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!(Check_Positive_Number_Int(N)));

	return stoll(N);
}

unsigned long long Read_Positive_LLInt_Number_With_SpecificNumberOfDigits(short NumberOfDigits)
{
	string N;

	do
	{
		cout << "Please, Enter A " << NumberOfDigits << " Digits Number?" << endl;
		cout << "your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!(Check_Positive_Number_Int(N) && Check_TheNumberOfDigits(N, NumberOfDigits)));

	return stoull(N);
}

unsigned long long Read_Positive_LLInt_NumberInRange(int from, int to)
{
	string N;
	do
	{
		//cout << "Enter a number between " << from << " & " << to << " : " << endl;
		cout << "Your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!(Check_Positive_Number_Int(N) && CheckNumber_InRange(N, from, to)));

	return stoull(N);
}

unsigned long long Read_Positive_LLInt_NumberInRange_Message(string Message, int from, int to)
{
	string N;
	do
	{
		//cout << "Enter a number between " << from << " & " << to << " : " << endl;
		cout << Message << endl;
		cout << "Your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!(Check_Positive_Number_Int(N) && CheckNumber_InRange(N, from, to)));

	return stoull(N);
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

	} while (!(Check_Positive_Number(N)));

	return stof(N);
}

float Read_Number(string Message)
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

int Sum_Of_Number_Digits(int Number)
{
	int Remainder = 0;
	int sum = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number /= 10;

		sum += Remainder;
	}

	return sum;

}

void Print_Number_Reversed(unsigned long long Number)
{
	short Remainder = 0, Reversed = 0;

	cout << "The Number In The Same Order is { ";
	while (Number > 0)
	{
		Remainder = Number % 10;
		Number /= 10;

		cout << "  " << Remainder << "  ";
	}

	cout << " }" << endl << endl;
}

void Print_Number_Digits_As_String(unsigned long long Number)
{
	string SN = to_string(Number);
	short Length = to_string(Number).length();

	for (int i = 0; i < Length; i++)
	{
		cout << SN.at(i) << endl;
	}
}

void Print_Number_Digits_Reversed(unsigned long long Number)
{
	short Remainder = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number /= 10;

		cout << to_string(Remainder) << endl;
	}
}

unsigned long long Reverse_Number(unsigned long long Number)
{
	short Remainder = 0;
	unsigned long long Reversed = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number /= 10;

		Reversed = Reversed * 10 + Remainder;
	}

	return Reversed;
}

string Reverse_String(string N)
{
	string Reversed = "";

	for (int i = N.length() - 1; i >= 0; i--)
	{
		Reversed += N[i];
	}

	return Reversed;
}

unsigned long long Read_Positive_LLInt_Number_Reversed(string Message)
{
	string N;

	do
	{
		cout << Message << endl;
		cout << "your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!(Check_Positive_Number_Int(N)));



	return stoull(Reverse_String(N));
}

string Read_String_Positive_Int_Number(string Message)
{
	string N;

	do
	{
		cout << Message << endl;
		cout << "your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!(Check_Positive_Number_Int(N)));

	return N;
}

bool Is_Palindrome_Number(unsigned long long Number)
{
	return Reverse_Number(Number) == Number;

	// we can use this condition too
	// Reverse_Number / Nubmer == 1
}

bool Is_Palindrome_String(string S)
{
	return Reverse_String(S) == S;
}


//****************************************************************************************************************
//****************************************************************************************************************
// Print Reversed Number Pattern

// Solution 1

void Print_Inverted_Pattern(short Number)
{
	for (int i = Number; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			cout << i << " ";
		}
		cout << endl;
	}
}





int main()
{
	// Solution 1
	Print_Inverted_Pattern(Read_Positive_LLInt_Number("Please, Enter a Positive Int Number?"));


	


	return 0;
}