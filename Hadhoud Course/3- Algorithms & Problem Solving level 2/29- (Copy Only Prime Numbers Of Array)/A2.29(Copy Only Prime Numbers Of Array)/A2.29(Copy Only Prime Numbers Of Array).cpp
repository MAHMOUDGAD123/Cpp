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

unsigned long long Read_Positive_LLInt_NumberInRange(string Message, int from, int to)
{
	string N;
	do
	{
		cout << Message << endl;
		cout << "Range ( " << from << " -> " << to << " ) " << endl;
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

bool IsPrime_Number(int N)
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

string Generate_Random_Word_With_Length(en_CharType CharType, short Length)
{
	string Word;

	for (short i = 1; i <= Length; i++)
	{
		Word += GetRandomCharacter(CharType);
	}

	return Word;
}

string Random_Password_Generator_With_Length(short Length)
{
	string Password;

	for (short i = 1; i <= Length; i++)
	{
		Password += Generate_Random_Number_InRange(33, 126);
	}

	return Password;
}

string Random_Password_Generator()
{
	short Length = Generate_Random_Number_InRange(21, 50);
	string Password;

	for (short i = 1; i <= Length; i++)
	{
		Password += Generate_Random_Number_InRange(33, 126);
	}

	return Password;


}

// 	srand((unsigned)time(NULL));

void Read_Array(short Array[100], short& Arr_Length)
{
	Arr_Length = Read_Positive_LLInt_NumberInRange("Please, Enter The Array Length?", 1, 100);

	cout << "Enter Array Elements /" << endl << endl;
	for (short i = 0; i < Arr_Length; i++)
	{
		cout << "- Element [" << i + 1 << "] : ";
		cin >> Array[i];
	}

	cout << endl << endl;
}

void Print_Array(short Array[100], short Arr_Length)
{

	for (short i = 0; i < Arr_Length; i++)
	{
		cout << Array[i] << " ";
	}
	cout << endl;
}

short Get_Number_Frequency_InArray(short Array[], short NumberToCheck, short Arr_Length)
{
	short Counter = 0;

	for (short i = 0; i < Arr_Length; i++)
	{
		if (NumberToCheck == Array[i])
			Counter++;
	}

	return Counter;
}

void Fill_Array_With_Random_Numbers(short Array[100], short& Arr_Length)
{
	Arr_Length = Read_Positive_LLInt_NumberInRange("Please, Enter The Array Length?", 1, 100);

	for (short i = 0; i < Arr_Length; i++)
	{
		Array[i] = Generate_Random_Number_InRange(1, 100);
	}

	cout << endl;
}

int Get_Max_Number_Of_Array(short Array[100], short Arr_Length)
{
	short Max = Array[0];

	for (short i = 1; i < Arr_Length; i++)
	{
		if (Array[i] > Max)
			Max = Array[i];
	}

	return Max;
}

int Get_Min_Number_Of_Array(short Array[100], short Arr_Length)
{
	short Min = Array[0];

	for (short i = 1; i < Arr_Length; i++)
	{
		if (Array[i] < Min)
			Min = Array[i];
	}

	return Min;
}

int Get_Sum_Of_Array(short Array[100], short Arr_Length)
{
	int sum = 0;

	for (short i = 0; i < Arr_Length; i++)
	{
		sum += Array[i];
	}

	return sum;
}

float Get_Average_Of_Array(short Array[100], short Arr_Length)
{
	return (float)Get_Sum_Of_Array(Array, Arr_Length) / Arr_Length;
}

void Take_Copy_Of_Array(short Source_Array[], short Copy_Array[], short Arr_Length)
{
	// You Should Declare The Copy_Array In The Main Function First & Then Racall This Function 

	for (short i = 0; i < Arr_Length; i++)
	{
		Copy_Array[i] = Source_Array[i];
	}
}

//*******************************************************************************************************************************************************
//*******************************************************************************************************************************************************
// Copy Only Prime Numbers Of Array


void _Fill_Array_With_Random_Numbers(short Array[], short& Arr_Length)
{
	Arr_Length = Read_Positive_LLInt_NumberInRange("Please, Enter The Array Length?", 1, 100);

	for (short i = 0; i < Arr_Length; i++)
	{
		Array[i] = Generate_Random_Number_InRange(1, 100);
	}

}

void _Print_Array(short Array[], short Arr_Length)
{
	for (short i = 0; i < Arr_Length; i++)
	{
		cout << Array[i] << " ";
	}
}



// MG Solution
short Copy_Only_Array_Prime_Numbers_MG(short Source_Array[], short Copy_Array[], short Arr_Length)
{
	short C = 0; // For The Copy Array

	for (short i = 0; i < Arr_Length; i++)
	{
		if (IsPrime_Number(Source_Array[i]))
		{
			Copy_Array[C] = Source_Array[i];
			C++;
		}
		
	}

	return C; // Put the return value of this function in the Copy_arr_Length in the main function
}

// Hadhoud Solution
void Copy_Only_Array_Prime_Numbers_Hadhoud(short Source_Array[], short Copy_Array[], short Arr_Length, short& Copy_Arr_Length)
{
	short C = 0; // For The Copy Array

	for (short i = 0; i < Arr_Length; i++)
	{
		if (IsPrime_Number(Source_Array[i]))
		{
			Copy_Array[C] = Source_Array[i];
			C++;
		}

	}

	Copy_Arr_Length = C; // by Reference
}



//________________________________________________________________________________________________________________________________________

int main()
{
	srand((unsigned)time(NULL));

	short Array[100], Copy_Array[100], Arr_Length, Copy_Arr_Length;

	_Fill_Array_With_Random_Numbers(Array, Arr_Length);




	// MG
	Copy_Arr_Length = Copy_Only_Array_Prime_Numbers_MG(Array, Copy_Array, Arr_Length);
	

	// Hadhoud
	//Copy_Only_Array_Prime_Numbers_Hadhoud(Array, Copy_Array, Arr_Length, Copy_Arr_Length);




	cout << "-> Source Array : { ";
	_Print_Array(Array, Arr_Length);
	cout << "}" << endl << endl;

	cout << "-> Copy Array Of Prime Numbers : { ";
	_Print_Array(Copy_Array, Copy_Arr_Length);
	cout << "}" << endl << endl;



	return 0;
}

