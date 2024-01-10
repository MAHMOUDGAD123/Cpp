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

int Generate_Random_Number_InRange(int From, int To)
{
	//Function To Generate A Random Number In Range Of (From -> To)

	int Random_Number = rand() % (To - From + 1) + From;

	return Random_Number;
}

enum en_CharType { SmallChar = 1, CapitalChar = 2, SpecialChar = 3, Digit = 4 };

char GetRandomCharacter(en_CharType CharType)
{
	switch (CharType)
	{
	case SmallChar:
		return char(Generate_Random_Number_InRange(97, 122));
		break;
	case CapitalChar:
		return char(Generate_Random_Number_InRange(65, 90));
		break;
	case SpecialChar:
		return char(Generate_Random_Number_InRange(33, 47));
		break;
	case Digit:
		return char(Generate_Random_Number_InRange(48, 57));
		break;;
	}
}


//*******************************************************************************************************************************************************
//*******************************************************************************************************************************************************
// Windows Key Generator

// MG Solutions

// Only Capital Characters Key Generator
string CapitalChars_Key_Generator()
{
	string Key = "";

	for (short i = 1; i <= 4; i++)
	{
		for (short j = 1; j <= 4; j++)
		{
			Key += GetRandomCharacter(CapitalChar);
		}

		if (i < 4)
			Key += "-";
	}
	return Key;
}

void Print_CapitalChars_Keys(short NumberOfKeys)
{
	for (short i = 1; i <= NumberOfKeys; i++)
	{
		cout << "-> Key[" << i << "]: " << CapitalChars_Key_Generator() << endl << endl;
	}
}


// ( Capital Characters + Digits ) Key Generator
bool Only_CapitalChars_And_Digits(char Char)
{
	for (short i = 48; i <= 57; i++)
	{
		if (Char == char(i))
			return true;
	}

	for (short i = 65; i <= 90; i++)
	{
		if (Char == char(i))
			return true;
	}

	return false;
}

string CapChars_And_Digits_Key_Generator()
{
	string Key = "";
	char Char;

	for (short i = 1; i <= 4; i++)
	{
		for (short j = 1; j <= 4; j++)
		{
			do 
			{
				Char = char(Generate_Random_Number_InRange(48, 90));

			} while (!Only_CapitalChars_And_Digits(Char));

			Key += Char;
			
		}

		if (i < 4)
			Key += "-";
	}
	return Key;
}

void Print_CapitalChars_And_Digits_Keys(short NumberOfKeys)
{
	for (short i = 1; i <= NumberOfKeys; i++)
	{
		cout << "-> Key[" << i << "]: " << CapChars_And_Digits_Key_Generator() << endl << endl;
	}
}


// ________________________________________________________________________________________



// Abu-Hadhoud Solution


// Only Generate Capital Characters Keys
string Generate_Random_Word_With_Length(en_CharType CharType, short Length)
{
	string Word;

	for (short i = 1; i <= Length; i++)
		Word += GetRandomCharacter(CharType);

	return Word;
}

string Key_Generator_Of_N_Words(short NumberOfWords)
{
	string Key;
	for (short i = 1; i <= NumberOfWords; i++)
	{
		Key += Generate_Random_Word_With_Length(CapitalChar, 4);

		if (i < NumberOfWords)
			Key += "-";
	}
	return Key;
}

void Keys_Generator(short NumberOfKeys)
{
	for (short i = 1; i <= NumberOfKeys; i++)
	{
		cout << "-> Key [" << i << "]: " << Key_Generator_Of_N_Words(5) << endl << endl;
	}
}


// Generate ( Capital Characters + Digits ) Keys
bool Only_CapitalChars_And_Digits_Allowed(char Char)
{
	for (short i = 48; i <= 57; i++)
	{
		if (Char == char(i))
			return true;
	}

	for (short i = 65; i <= 90; i++)
	{
		if (Char == char(i))
			return true;
	}

	return false;
}

string CapChars_Digits_Word_Generator_With_Length(short Length)
{
	string Word;
	char Char;

	for (short j = 1; j <= Length; j++)
	{
		do
		{
			Char = char(Generate_Random_Number_InRange(48, 90));

		} while (!Only_CapitalChars_And_Digits_Allowed(Char));

		Word += Char;

	}

	return Word;
}

string CapChars_Digits_Key_Generator_Of_N_Words(short NumberOfWords)
{
	string Key;

	for (short i = 1; i <= NumberOfWords; i++)
	{
		Key += CapChars_Digits_Word_Generator_With_Length(4);

		if (i < NumberOfWords)
			Key += "-";
	}


	return Key;
}

void  CapChars_Digits_Keys_Generator(short NumberOfKeys)
{
	for (short i = 1; i <= NumberOfKeys; i++)
	{
		cout << "-> Key [" << i << "]: " 
			<< CapChars_Digits_Key_Generator_Of_N_Words(5) << endl << endl;
	}
}


//________________________________________________________________________________________________________________________________________

int main()
{
	srand((unsigned)time(NULL));

	short NumberOfKeys = Read_Positive_LLInt_Number("How Many Keys Do You Want?");

	// MG

	//// Get Capital Characters Keys
	//cout << "________________________________" << endl;
	//cout << endl << "Only Capital Characters - Keys :" << endl;
	//cout << "________________________________" << endl <<endl;
	//Print_CapitalChars_Keys(NumberOfKeys);

	//
	//// Get ( Capital Characters + Digits ) Keys
	//cout << "____________________________________" << endl;
	//cout << endl << "Capital Characters & Digits - Keys :" << endl;
	//cout << "____________________________________" << endl << endl;
	//Print_CapitalChars_And_Digits_Keys(NumberOfKeys);


	//cout << endl << "*****************************************************************" << endl;
	//cout << "*****************************************************************" << endl << endl;


	// Abu-Hadhoud

	// Get Capital Characters Keys
	cout << "________________________________" << endl;
	cout << endl << "Only Capital Characters - Keys :" << endl;
	cout << "________________________________" << endl << endl;
	Keys_Generator(NumberOfKeys);

	cout << endl;

	// Get ( Capital Characters + Digits ) Keys
	cout << "____________________________________" << endl;
	cout << endl << "Capital Characters & Digits - Keys :" << endl;
	cout << "____________________________________" << endl << endl;
	CapChars_Digits_Keys_Generator(NumberOfKeys);
	
	return 0;
}

