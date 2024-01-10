#include <string>
#include <string.h>
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

bool IsItNumber(char c)
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
		if (IsItNumber(N[i]) == false || N == "." || N == "-")
			return false;
	}
	for (short j = 1; j < N.length(); j++)
	{
		if (N[j] == '-')
			return false;
	}

	return true;
}

bool Check_Number_Int(string N)
{
	for (int i = 0; i < N.length(); i++)
	{
		if (Integer_Only(N[i]) == false || N == "-")
			return false;
	}
	for (short j = 1; j < N.length(); j++)
	{
		if (N[j] == '-')
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

unsigned int Read_Positive_Int_Number(string Message)
{
	string N;

	do
	{
		cout << Message << endl;
		cout << "your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!(Check_Positive_Number_Int(N)));

	return stoul(N);
}

unsigned int Read_Positive_Int_NumberOf_SpecificNumberOfDigits(short NumberOfDigits)
{
	string N;

	do
	{
		cout << "Please, Enter A (" << NumberOfDigits << ") Digits Number?" << endl;
		cout << "your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!(Check_Positive_Number_Int(N) && Check_TheNumberOfDigits(N, NumberOfDigits)));

	return stoul(N);
}

unsigned int Read_Positive_Int_NumberOf_SpecificNumberOfDigits_InRange(short NumberOfDigits, short from, short to)
{
	string N;

	do
	{
		cout << "Please, Enter A (" << NumberOfDigits << ") Digits Number From " << from << " To " << to << " ?" << endl;
		cout << "your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!(Check_Positive_Number_Int(N) && Check_TheNumberOfDigits(N, NumberOfDigits) && CheckNumber_InRange(N, from, to)));

	return stoul(N);
}

unsigned int Read_Positive_Int_NumberOf_SpecificNumberOfDigits_InRange_Message(string Message, short NumberOfDigits, short from, short to)
{
	string N;

	do
	{
		cout << Message << endl;
		cout << "Your Answer :";
		cin >> N;
		cout << endl;

	} while (!(Check_Positive_Number_Int(N) && Check_TheNumberOfDigits(N, NumberOfDigits) && CheckNumber_InRange(N, from, to)));

	return stoi(N);
}

unsigned int Read_Positive_Int_NumberInRange(int from, int to)
{
	string N;
	do
	{
		cout << "Range ( " << from << " -> " << to << " ) " << endl;
		cout << "Your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!(Check_Positive_Number_Int(N) && CheckNumber_InRange(N, from, to)));

	return stoul(N);
}

unsigned int Read_Positive_Int_NumberInRange_Message(string Message, int from, int to)
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

	return stoul(N);
}

double Read_Positive_Number(string Message)
{
	string N;

	do
	{
		cout << Message << endl;
		cout << "your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!(Check_Positive_Number(N)));

	return stod(N);
}

double Read_Number(string Message)
{
	string N;

	do
	{
		cout << Message << endl;
		cout << "your Answer : ";
		cin >> N;
		cout << "\n";

	} while (!Check_Number(N));

	return stod(N);
}

bool Read_Bool_InputFromUser_0or1()
{
	string N;

	do
	{
		cout << "Enter Only [0] or [1]?" << endl;
		cout << "Your Answer :";
		cin >> N;
		cout << endl;

	} while (!(Check_Positive_Number_Int(N) && Check_TheNumberOfDigits(N, 1) && CheckNumber_InRange(N, 0, 1)));

	return stoi(N);
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

bool IsOddOrEvenNumber(short Number)
{
	// Return True if Odd & Return false if Even
	return Number % 2 != 0;
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

	return rand() % (To - From + 1) + From;
}

enum en_CharType { SmallChar = 1, CapitalChar = 2, SpecialChar = 3, Digit = 4 };

char GenerateRandomCharacter(en_CharType CharType)
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
		Word += GenerateRandomCharacter(CharType);
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

void Read_IntArray(short Array[], short& Arr_Length)
{
	short N = Read_Positive_Int_Number("What is The Max Size Of The Array?");

	Arr_Length = Read_Positive_Int_NumberInRange_Message("Please, Enter The Array Length?", 1, N);

	cout << "Enter Array Elements /" << endl << endl;
	for (short i = 0; i < Arr_Length; i++)
	{
		cout << "- Element [" << i + 1 << "] : ";
		cin >> Array[i];
	}

	cout << endl << endl;
}

void Read_StringArray(string Array[], short& Arr_Length)
{
	short N = Read_Positive_Int_Number("What is The Max Size Of The Array?");

	Arr_Length = Read_Positive_Int_NumberInRange_Message("Please, Enter The Array Length?", 1, N);

	cout << "Enter Array Elements /" << endl << endl;
	for (short i = 0; i < Arr_Length; i++)
	{
		cout << "- Element [" << i + 1 << "] : ";
		cin >> Array[i];
	}

	cout << endl << endl;
}

void Print_Array(short Array[], short Arr_Length)
{
	for (short i = 0; i < Arr_Length; i++)
	{
		cout << Array[i] << "  ";
	}
}

void Print_StringArray(string Array[], short Arr_Length)
{
	for (short i = 0; i < Arr_Length; i++)
	{
		cout << "-> Array[" << i << "]: ";
		cout << Array[i] << endl << endl;
	}
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

void Fill_Array_With_Random_Numbers_From1toN_RefLength(short Array[], short& Arr_Length)
{
	short L = Read_Positive_Int_Number("What Is The Max Size Of The Array?");

	Arr_Length = Read_Positive_Int_NumberInRange_Message("Please, Enter The Array Length?", 1, L);

	short min = Read_Int_Number("Enter The Min Value Of The Array Element?");
	short max = Read_Int_Number("Enter The Max Value Of The Array Element?");

	for (short i = 0; i < Arr_Length; i++)
	{
		Array[i] = Generate_Random_Number_InRange(min, max);
	}

	cout << endl;
}

void Fill_Array_With_Random_Numbers_From1toN(short Array[], short Arr_Length)
{
	short min = Read_Int_Number("Enter The Min Value Of The Array Element?");
	short max = Read_Int_Number("Enter The Max Value Of The Array Element?");

	for (short i = 0; i < Arr_Length; i++)
	{
		Array[i] = Generate_Random_Number_InRange(min, max);
	}
}

void Fill_Array_With_Random_Numbers_From1toN_NoRepeating(short Array[], short Arr_Length)
{
	short X = 0; // just a container

	short min = Read_Int_Number("Enter The Min Value Of The Array Element?");
	short max = Read_Int_Number("Enter The Max Value Of The Array Element?");

	for (short i = 0; i < Arr_Length; i++)
	{
		do
		{
			X = Generate_Random_Number_InRange(min, max);

		} while (Get_Number_Frequency_InArray(Array, X, Arr_Length) > 0);

		Array[i] = X;
	}

}

int Get_Max_Number_Of_Array(short Array[], short Arr_Length)
{
	short Max = Array[0];

	for (short i = 1; i < Arr_Length; i++)
	{
		if (Array[i] > Max)
			Max = Array[i];
	}

	return Max;
}

int Get_Min_Number_Of_Array(short Array[], short Arr_Length)
{
	short Min = Array[0];

	for (short i = 1; i < Arr_Length; i++)
	{
		if (Array[i] < Min)
			Min = Array[i];
	}

	return Min;
}

int Get_Sum_Of_Array(short Array[], short Arr_Length)
{
	int sum = 0;

	for (short i = 0; i < Arr_Length; i++)
	{
		sum += Array[i];
	}

	return sum;
}

float Get_Average_Of_Array(short Array[], short Arr_Length)
{
	return (float)Get_Sum_Of_Array(Array, Arr_Length) / Arr_Length;
}

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

void Fill_Array_With_Sum_Of_2Arrays_Elements(short Array1[], short Array2[], short Arr12Sum[], short Arr_Length)
{
	for (short i = 0; i <= Arr_Length; i++)
	{
		Arr12Sum[i] = Array1[i] + Array2[i];
	}
}

void Swap2Numbers(short& N1, short& N2)
{
	short temp = 0;
	temp = N1;
	N1 = N2;
	N2 = temp;
}

void Fill_Array_With_Orderd_Numbers_From1toN(short Array[], short Arr_Length)
{
	// N = Arr_Length

	for (short i = 0; i < Arr_Length; i++)
	{
		Array[i] = i + 1;
	}

}

void Shuffle_Array_MG(short Array[], short Arr_Length)
{
	short N1 = 0, N2 = 0;

	for (short i = 0; i < Arr_Length; i++)
	{
		N1 = Generate_Random_Number_InRange(0, Arr_Length - 1);
		N2 = Generate_Random_Number_InRange(0, Arr_Length - 1);

		Swap2Numbers(Array[N1], Array[N2]);
	}
}

void Shuffle_Array_Hadhoud(short Array[], short Arr_Length)
{
	for (short i = 0; i < Arr_Length; i++)
	{
		Swap2Numbers(Array[Generate_Random_Number_InRange(0, Arr_Length - 1)], Array[Generate_Random_Number_InRange(0, Arr_Length - 1)]);
	}
}

void Array_ZeroFill(short Array[], short Arr_Length)
{
	for (short i = 0; i < Arr_Length; i++)
	{
		Array[i] = NULL;
	}
}

void Reverse_Array(short Array[], short Arr_Length)
{
	short C = Arr_Length - 1;

	for (short i = 0; i < ceil(Arr_Length / 2); i++)
	{
		Swap2Numbers(Array[i], Array[C]);
		C--;
	}
}

void CopyArray_InReverdedOrder_MG(short Array[], short Reversed_Copy[], short Arr_Length)
{
	short C = Arr_Length - 1;

	for (short i = 0; i < Arr_Length; i++)
	{
		Reversed_Copy[i] = Array[C];
		C--;
	}
}

void CopyArray_InReverdedOrder_Hadhoud(short Array[], short Reversed_Copy[], short Arr_Length)
{

	for (short i = 0; i < Arr_Length; i++)
	{
		Reversed_Copy[i] = Array[Arr_Length - 1 - i];

	}
}

short GetNumberIndex_InArray(short Array[], short Arr_Length, short NumberToCheck)
{
	// Only return the number index in the array if there is no repeating in the array

	for (short i = 0; i < Arr_Length; i++)
	{
		if (NumberToCheck == Array[i])
		{
			return i;
		}

	}

	return -1;
}

string Get_AllNumberIndexes_R(short Array[], short Arr_Length, short NumberToCheck)

{
	// return the number indexes in the array as string if repeating is allowed in the array

	string Indexes = "";

	for (short i = 0; i < Arr_Length; i++)
	{

		if (NumberToCheck == Array[i])
		{
			Indexes = Indexes + "{" + to_string(i) + "} ";
		}
	}
	Indexes += "\b";

	return Indexes;
}

bool IsNumber_InArray_Hadhoud(short Array[], short Arr_Length, short NumberToCheck)
{
	// Only Check if the number is exist in the array or not

	return GetNumberIndex_InArray(Array, Arr_Length, NumberToCheck) != -1;
}

bool IsNumber_InArray_MG(short Array[], short Arr_Length, short NumberToCheck)
{
	// Check if the number is exist in the array or not

	for (short i = 0; i < Arr_Length; i++)
	{
		if (NumberToCheck == Array[i])
			return true;
	}

	return false;
}

void Fill_Array_SimiDynamic_ByUserInput(short Array[], short& Arr_Length)
{
	bool AddMore;
	short C = 0;
	Arr_Length = 0;

	do
	{
		Arr_Length++;
		Array[C] = Read_Positive_Int_Number("Enter The Element Number " + to_string(C + 1) + "?");
		C++;

		cout << "Do You Want To Add More Numbers? [0]:No, [1]:Yes?" << endl;
		AddMore = Read_Bool_InputFromUser_0or1();

	} while (AddMore);
}

void Add_ElementToArray(short Number, short Array[], short& Arr_Length)
{
	// To Add An Element To An Array & Increase Length By 1

	Arr_Length++;
	Array[Arr_Length - 1] = Number;
}

void InputUsrtNumberInArray(short Array[], short& Arr_Length)
{
	bool AddMore;
	short C = 0, Number = 0;

	do
	{
		C++;
		Number = Read_Positive_Int_Number("Enter The Element Number " + to_string(C) + "?");
		Add_ElementToArray(Number, Array, Arr_Length);

		cout << "Do You Want To Add More Numbers? [0]:No, [1]:Yes?" << endl;
		AddMore = Read_Bool_InputFromUser_0or1();

	} while (AddMore);

}

void Take_Copy_Of_Array(short Source_Array[], short Copy_Array[], short Arr_Length)
{
	// You Should Declare The Copy_Array In The Main Function First & Then Racall This Function 

	for (short i = 0; i < Arr_Length; i++)
	{
		Copy_Array[i] = Source_Array[i];
	}
}

void CopyArrayBy_AddElementToArray(short Source_Array[], short Copy_Array[], short Source_Length, short& Copy_Length)
{
	// You Should Declare The Copy_Array In The Main Function First & Then Racall This Function 

	for (short i = 0; i < Source_Length; i++)
	{
		Add_ElementToArray(Source_Array[i], Copy_Array, Copy_Length);
	}
}

void CopyArray_OddNumbersBy_AddElementToArray(short Source_Array[], short CopyOdd_Array[], short Source_Length, short& CopyOdd_Length)
{
	for (short i = 0; i < Source_Length; i++)
	{
		if (Source_Array[i] % 2 != 0)
			Add_ElementToArray(Source_Array[i], CopyOdd_Array, CopyOdd_Length);
	}
}

void CopyArray_EvenNumbersBy_AddElementToArray(short Source_Array[], short CopyEven_Array[], short Source_Length, short& CopyEven_Length)
{
	for (short i = 0; i < Source_Length; i++)
	{
		if (Source_Array[i] % 2 == 0)
			Add_ElementToArray(Source_Array[i], CopyEven_Array, CopyEven_Length);
	}
}

void CopyArray_PrimeNumbersBy_AddElementToArray(short Source_Array[], short CopyPrime_Array[], short Source_Length, short& CopyPrime_Length)
{
	for (short i = 0; i < Source_Length; i++)
	{
		if (IsPrime_Number(Source_Array[i]))
			Add_ElementToArray(Source_Array[i], CopyPrime_Array, CopyPrime_Length);
	}
}

void FillArray_HardCoded(short Array[], short& Arr_Length)
{
	// Your Can Change The Length & The Elements


	Arr_Length = 10;

	Array[0] = 10;
	Array[1] = 10;
	Array[2] = 10;
	Array[3] = 20;
	Array[4] = 30;
	Array[5] = 40;
	Array[6] = 80;
	Array[7] = 90;
	Array[8] = 40;
	Array[9] = 60;
}

void CopyArray_DistinctNumbersBy_AddElementToArray(short Source_Array[], short CopyDistinct_Array[], short Source_Length, short& CopyDistinct_Length)
{
	// Only Copy Distinct Numbers (No Repeating)

	for (short i = 0; i < Source_Length; i++)
	{
		if (!IsNumber_InArray_MG(CopyDistinct_Array, CopyDistinct_Length, Source_Array[i]))
			Add_ElementToArray(Source_Array[i], CopyDistinct_Array, CopyDistinct_Length);
	}
}

bool IsArrayPalindrome_MG(short Array[], short Arr_Length)
{
	// (Just Compaire The Array Elements)
	// Return True If Array is Palindrome & Else Return False

	/*
		 We Can use{  i <= floor(Arr_Length / 2)   or   i < ceil(Arr_Length / 2)  }

		 to make the function stop in the middle of the array
	*/


	short C = Arr_Length - 1;

	for (short i = 0; i <= floor(Arr_Length / 2); i++)
	{
		if (Array[i] != Array[C])
		{
			return false;
		}
		C--;
	}

	return true;
}

bool IsArrayPalindrome_Hadhoud(short Array[], short Arr_Length)
{
	// (Just Compaire The Array Elements)
	// Return True If Array Palindrome & Return False If Not

	/*
		 We Can use{  i <= floor(Arr_Length / 2)   or   i < ceil(Arr_Length / 2)  }

		 to make the function stop in the middle of the array
	*/


	for (short i = 0; i < ceil(Arr_Length / 2); i++)
	{
		if (Array[i] != Array[Arr_Length - 1 - i])
		{
			return false;
		}
	}

	return true;
}

short CountOddNumbersInArray(short Array[], short Arr_Length)
{
	short Counter = 0;

	for (short i = 0; i < Arr_Length; i++)
	{
		if (Array[i] % 2 != 0)
		{
			Counter++;
		}
	}

	return Counter;
}

short CountEvenNumbersInArray(short Array[], short Arr_Length)
{
	short Counter = 0;

	for (short i = 0; i < Arr_Length; i++)
	{
		if (Array[i] % 2 == 0)
		{
			Counter++;
		}
	}

	return Counter;
}

short CountPositiveNumbersInArray(short Array[], short Arr_Length)
{
	short Counter = 0;

	for (short i = 0; i < Arr_Length; i++)
	{
		if (Array[i] > 0)
		{
			Counter++;
		}
	}

	return Counter;
}

short CountNegativeNumbersInArray(short Array[], short Arr_Length)
{
	short Counter = 0;

	for (short i = 0; i < Arr_Length; i++)
	{
		if (Array[i] < 0)
		{
			Counter++;
		}
	}

	return Counter;
}

double MyAbs(double Number)
{
	if (Number == 0 || Number == -0)
		return 0;
	else if (Number > 0)
		return Number;
	else
		return Number * -1;
}

short GetTheFirstFloatingDigit_InNumber(double Number)
{
	// To Get The First Digit On THe Right Of The (.) Of Floating-Point Number 

	string St_Number = to_string(Number);

	for (short i = 0; i < St_Number.length(); i++)
	{
		if (St_Number[i] == '.')
			return short(St_Number[i + 1] - '0'); // we can use -> {   short(St_Number[i + 1]) - 48   }
	}
}

long long MyRound_MG(double Number)
{
	short Digit = 0;
	string St_Number = to_string(Number);

	for (short i = 0; i < St_Number.length(); i++)
	{
		if (St_Number[i] == '.')
			Digit = short(St_Number[i + 1] - '0'); // we can use -> {   short(St_Number[i + 1]) - 48   }
	}


	if (Digit >= 5)
	{
		if (Number > 0)
			return long long(++Number);
		else
			return long long(--Number);
	}
	else
	{
		return long long(Number);
	}

}

long long GetIntegerPartOfNumber(double Number)
{
	return long long(Number);
}
double GetFractionPartOfNumber(double Number)
{
	return Number - long long(Number);
}

long long MyRound_Hadhoud(double Number)
{
	long long IntPart = long long(Number);
	double FractionPart = Number - IntPart;

	if (MyAbs(FractionPart) >= 0.5)
	{
		if (Number > 0)
			return ++IntPart;
		else
			return --IntPart;
	}
	else
	{
		return IntPart;
	}
}


//*******************************************************************************************************************************************************
//*******************************************************************************************************************************************************
//*******************************************************************************************************************************************************
//  My Floor Function

long long MyFloor(double Number)
{
	return Number;
}


//________________________________________________________________________________________________________________________________________

int main()
{
	double Number = 0;
	Number = Read_Number("Enter A Number?");

	cout << "*******************************************************" << endl << endl;
	cout << "My Floor Function Result (MG): { " << MyFloor(Number) << " }" << endl << endl;
	cout << "C++ Floor Function Result: { " << floor(Number) << " }" << endl << endl;
	cout << "*******************************************************" << endl << endl;


	return 0;

}

