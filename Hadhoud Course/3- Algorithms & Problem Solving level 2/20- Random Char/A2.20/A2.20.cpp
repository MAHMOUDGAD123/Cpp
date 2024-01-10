#include <string>
#include <iostream>
#include <cstdlib>

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
		cout << "Please, Enter A (" << NumberOfDigits << ") Digits Number?" << endl;
		cout << "your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!(Check_Positive_Number_Int(N) && Check_TheNumberOfDigits(N, NumberOfDigits)));

	return stoull(N);
}

unsigned long long Read_Positive_LLInt_Number_With_SpecificNumberOfDigits_InRange(short NumberOfDigits, short from, short to)
{
	string N;

	do
	{
		cout << "Please, Enter A (" << NumberOfDigits << ") Digits Number From " << from << " To " << to << " ?" << endl;
		cout << "your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!(Check_Positive_Number_Int(N) && Check_TheNumberOfDigits(N, NumberOfDigits) && CheckNumber_InRange(N, from, to)));

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

bool Capital_Letters_Only(char C)
{
	for (short i = 65; i <= 90; i++)
	{
		if (C == char(i))
			return true;
	}
	return false;
}

bool All_Letters_Only(char C)
{
	if (C == ' ')
		return true;

	for (short i = 65; i <= 90; i++)
	{
		if (C == char(i))
			return true;
	}

	for (short i = 97; i <= 122; i++)
	{
		if (C == char(i))
			return true;
	}

	return false;
}

bool Check_Capital_Letters_Only(string S)
{

	for (short i = 0; i < S.length(); i++)
	{
		if (Capital_Letters_Only(S[i]) == false)
			return false;
	}

	return true;

}

bool Check_All_Letters_Only(string S)
{

	for (short i = 0; i < S.length(); i++)
	{
		if (All_Letters_Only(S[i]) == false)
			return false;
	}

	return true;

}

string Read_Word_Of_Specific_Number_Of_Capital_Letters(short NumberOfLetters)
{
	string S;

	do
	{
		cout << "Please, Enter A Word Of " << NumberOfLetters << " Letters?" << endl;
		cout << "your Answer : ";
		cin >> S;
		cout << "\n";

	} while (!(Check_Capital_Letters_Only(S) && Check_TheNumberOfDigits(S, NumberOfLetters)));

	return S;
}

string Read_String_Word_Of_Letters_Only(string Message)
{
	string S;

	do
	{
		cout << Message << endl;
		cout << "your Answer : ";
		//cin.ignore(1, '\n');
		getline(cin, S);
		cout << "\n";

	} while (!(Check_All_Letters_Only(S)));

	return S;
}

string Read_Text(string Message)
{
	string S;

	cout << Message << endl;
	cout << "your Answer : ";
	//cin.ignore(1, '\n');
	getline(cin, S);
	cout << "\n";

	return S;
}

int Generate_Random_Number(int From, int To)
{
	//Function To Generate A Random Number In Range Of (From -> To)

	int Random_Number = rand() % (To - From + 1) + From;

	return Random_Number;
}



//******************************************************************************************
//******************************************************************************************
// Function To Generate A Random ( Small char , Capital char , Special char , One Digit Number )

enum en_What_To_Print { Small_Char = 1, Capital_Char = 2, Special_Char = 3, Digit_Number = 4, Print_All = 5 };

// MG Solution
en_What_To_Print Choose()
{
	cout << "What Do You Want To Print?" << endl << endl;
	cout << "(1) Small Character" << endl;
	cout << "(2) Capital Character" << endl;
	cout << "(3) Special Character" << endl;
	cout << "(4) One Digit Number" << endl;
	cout << "(5) Print All Previous" << endl;
	cout << "____________________________" << endl << endl;

	short Choice = Read_Positive_LLInt_Number_With_SpecificNumberOfDigits_InRange(1, 1, 5);

	switch (Choice)
	{
	case 1:
		return en_What_To_Print::Small_Char;
	case 2:
		return en_What_To_Print::Capital_Char;
	case 3:
		return en_What_To_Print::Special_Char;
	case 4:
		return en_What_To_Print::Digit_Number;
	case 5:
		return en_What_To_Print::Print_All;
	}
}

void Print(en_What_To_Print Choice)
{
	switch (Choice)
	{
	case en_What_To_Print::Small_Char:
		cout << char(Generate_Random_Number(97, 122)) << endl;
		break;

	case en_What_To_Print::Capital_Char:
		cout << char(Generate_Random_Number(65, 90)) << endl;
		break;

	case en_What_To_Print::Special_Char:
		cout << char(Generate_Random_Number(33, 47)) << endl;
		break;

	case en_What_To_Print::Digit_Number:
		cout << Generate_Random_Number(1, 10) << endl;
		break;

	case en_What_To_Print::Print_All:
		cout << char(Generate_Random_Number(97, 122)) << endl;
		cout << char(Generate_Random_Number(65, 90)) << endl;
		cout << char(Generate_Random_Number(33, 47)) << endl;
		cout << Generate_Random_Number(48, 57) << endl;
		break;

	}
}



// Hadhoud Solution
enum en_CharType{ SmallChar = 1, CapitalChar = 2, SpecialChar = 3, Digit = 4 };

char GetRandomCharacter(en_CharType CharType)
{
	switch (CharType)
	{
	case SmallChar:
		return char(Generate_Random_Number(97, 122));
	case CapitalChar:
		return char(Generate_Random_Number(65, 90));
	case SpecialChar:
		return char(Generate_Random_Number(33, 47));
	case Digit:
		return char(Generate_Random_Number(48, 57));
	}
}



int main()
{
	srand((unsigned)time(NULL));

	// MG Solution
	//Print(Choose());


	// Hadhoud Solution
	cout << GetRandomCharacter(SpecialChar) << " ";
	cout << GetRandomCharacter(CapitalChar) << " ";
	cout << GetRandomCharacter(SpecialChar) << " ";
	cout << GetRandomCharacter(Digit) << endl;


	return 0;
}

