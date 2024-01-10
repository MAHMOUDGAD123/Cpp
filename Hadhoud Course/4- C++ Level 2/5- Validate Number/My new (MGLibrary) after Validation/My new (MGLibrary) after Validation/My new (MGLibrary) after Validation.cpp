
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <cstdlib>
#include <iomanip>

using namespace std;


namespace MGLib
{


	bool Check_HowManyDigits(long long N, short NumberOfDigits)
	{
		if (to_string(N).length() == NumberOfDigits)
			return true;
		else
			return false;
	}

	bool CheckNumber_InRange(double N, int from, int to)
	{
		if (N >= from && N <= to)
			return true;
		else
			return false;
	}

	bool IsPositiveNumber(double NumberToCheck)
	{
		bool Result = (NumberToCheck > 0) ? true : false;

		return Result;
	}

	double Read_Number(string Message)
	{

		double Number = 0;

		cout << Message;
		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Invalid Number, Enter a valid Number? --> ";
			cin >> Number;
		}

		return Number;
	}

	double Read_Positive_Number(string Message)
	{
		double Number = 0;

		cout << Message;
		cin >> Number;

		while (cin.fail() || !(Number >= 0))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Invalid Number, Enter A Positive Number? --> ";
			cin >> Number;
		}

		return Number;
	}

	unsigned Read_Positive_Int_Number_OfNDigits(string Message, short NumberOfDigits)
	{
		long long Number = 0;

		cout << Message << " (Max digits = " << NumberOfDigits << ") --> ";
		cin >> Number;

		while (cin.fail() || !((Number >= 0) && Check_HowManyDigits(Number, NumberOfDigits)))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Invalid Number, Enter A Positive Int " << NumberOfDigits << " Digits Number? --> ";
			cin >> Number;
		}

		return Number;
	}

	double Read_Positive_NumberInRange(string Message, int from, int to)
	{
		double Number = 0;

		cout << Message << " In Range (" << from << " -> " << to << ") --> ";
		cin >> Number;

		while (cin.fail() || !((Number >= 0) && CheckNumber_InRange(Number, from, to)))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Invalid Number, Enter A Positvie Int Number (" << from << " -> " << to << ") --> ";
			cin >> Number;
		}

		return Number;
	}

	double Read_NumberInRange(string Message, int from, int to)
	{
		double Number = 0;

		cout << Message << " In Range (" << from << " -> " << to << ") --> ";
		cin >> Number;

		while (cin.fail() || !CheckNumber_InRange(Number, from, to))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Invalid Number, Enter A Number (" << from << " -> " << to << ") --> ";
			cin >> Number;
		}

		return Number;
	}

	string Read_YesOrNo_FromUser(string Message)
	{
		string S;

		do
		{
			cout << Message;
			cout << "[Y/y]Yes [N/n]No --> ";
			cin >> S;

		} while (!(S == "Y" || S == "y" || S == "N" || S == "n"));

		return S;
	}

	void Fill_Int2DimentionalArray(int Array[50][50], short& NumberOfRows, short& NumberOfColumns)
	{
		NumberOfRows = Read_Positive_Number("Enter The Number Of Rows:--> ");
		cout << endl;
		NumberOfColumns = Read_Positive_Number("Enter The Number Of Colomns:--> ");
		cout << endl;

		cout << "Enter The Array Elements:\n\n";
		for (short i = 0; i < NumberOfRows; i++)
		{
			for (short j = 0; j < NumberOfColumns; j++)
			{
				printf("Array[%d][%d]: ", i, j);
				Array[i][j] = Read_Number("");
			}
		}

		cout << endl << endl;
	}

	string Read_Text(string Message)
	{
		string S;

		cout << Message;
		cin >> S;

		return S;
	}

	void Fill_String2DimentionalArray(string Array[50][50], short& NumberOfRows, short& NumberOfColumns)
	{
		NumberOfRows = Read_Positive_Number("Enter The Number Of Rows:--> ");
		cout << endl;
		NumberOfColumns = Read_Positive_Number("Enter The Number Of Colomns:--> ");
		cout << endl;

		cout << "Enter The Array Elements:\n\n";
		for (short i = 0; i < NumberOfRows; i++)
		{
			for (short j = 0; j < NumberOfColumns; j++)
			{
				printf("Array[%d][%d]: ", i, j);
				Array[i][j] = Read_Text("");
			}
		}

		cout << endl << endl;
	}

	void Print_2DArray(int Array[50][50], short NumberOfRows, short NumberOfColumns)
	{
		for (short i = 0; i < NumberOfRows; i++)
		{
			for (short j = 0; j < NumberOfColumns; j++)
			{
				cout << setw(10) << Array[i][j];
			}

			cout << endl << endl;
		}
	}

	bool Read_Bool_Input()
	{
		short B;

		cout << "Enter Only [0] or [1]? --> ";
		cin >> B;

		while (cin.fail() || !(B == 0 || B == 1))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Invalid Input, Enter a [0] or [1] --> ";
			cin >> B;
		}

		return (bool)B;
	}

	bool IsPrime_Number(int NumberToCheck)
	{
		int Half_N = ceil(NumberToCheck / 2);

		for (int i = 2; i <= Half_N; i++)
		{
			if (NumberToCheck % i == 0)
			{
				return false;
			}

		}

		return true;
	}

	bool IsOddNumber(short Number)
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
		short MaxSize = Read_Positive_Number("What is The Max Size Of The Array?");

		Arr_Length = Read_Positive_NumberInRange("Please, Enter The Array Length?", 1, MaxSize);

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
		short MaxSize = Read_Positive_Number("What is The Max Size Of The Array?");

		Arr_Length = Read_Positive_NumberInRange("Please, Enter The Array Length?", 1, MaxSize);

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
		short L = Read_Positive_Number("What Is The Max Size Of The Array?");

		Arr_Length = Read_Positive_NumberInRange("Please, Enter The Array Length?", 1, L);

		short min = Read_Number("Enter The Min Value Of The Array Element?");
		short max = Read_Number("Enter The Max Value Of The Array Element?");

		for (short i = 0; i < Arr_Length; i++)
		{
			Array[i] = Generate_Random_Number_InRange(min, max);
		}

		cout << endl;
	}

	void Fill_Array_With_Random_Numbers_From1toN(short Array[], short Arr_Length)
	{
		short min = Read_Number("Enter The Min Value Of The Array Element?");
		short max = Read_Number("Enter The Max Value Of The Array Element?");

		for (short i = 0; i < Arr_Length; i++)
		{
			Array[i] = Generate_Random_Number_InRange(min, max);
		}
	}

	void Fill_Array_With_Random_Numbers_From1toN_NoRepeating(short Array[], short Arr_Length)
	{
		short X = 0; // just a container

		short min = Read_Number("Enter The Min Value Of The Array Element?");
		short max = Read_Number("Enter The Max Value Of The Array Element?");

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

	short Copy_Only_Array_Prime_Numbers(short Source_Array[], short Copy_Array[], short Arr_Length)
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

	void Shuffle_Array(short Array[], short Arr_Length)
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

	void CopyArray_InReverdedOrder(short Array[], short Reversed_Copy[], short Arr_Length)
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

	bool IsNumber_InArray(short Array[], short Arr_Length, short NumberToCheck)
	{
		// Check if the number is exist in the array or not

		for (short i = 0; i < Arr_Length; i++)
		{
			if (NumberToCheck == Array[i])
				return true;
		}

		return false;
	}

	void Fill_Array_SimiDynamic_ByUserInput_While_Ref(short Array[], short& Arr_Length)
	{
		bool AddMore;
		short C = 0;
		Arr_Length = 0;

		do
		{
			Arr_Length++;
			Array[C] = Read_Positive_Number("Enter The Element Number " + to_string(C + 1) + "?");
			C++;

			cout << "Do You Want To Add More Numbers? [0]:No, [1]:Yes?" << endl;
			AddMore = Read_Bool_Input();

		} while (AddMore);
	}

	void Fill_Array_SimiDynamic_ByUserInput_For(short Array[], short Arr_Length)
	{
		for (short i = 0; i < Arr_Length; i++)
		{
			Array[i] = Read_Positive_Number("Enter The Element Number " + to_string(i + 1) + "?");
		}
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
			Number = Read_Positive_Number("Enter The Element Number " + to_string(C) + "?");
			Add_ElementToArray(Number, Array, Arr_Length);

			cout << "Do You Want To Add More Numbers? [0]:No, [1]:Yes?" << endl;
			AddMore = Read_Bool_Input();

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

	void CopyArray_DistinctNumbersBy_AddElementToArray(short Source_Array[], short CopyDistinct_Array[], short Source_Length, short& CopyDistinct_Length)
	{
		// Only Copy Distinct Numbers (No Repeating)

		for (short i = 0; i < Source_Length; i++)
		{
			if (!IsNumber_InArray(CopyDistinct_Array, CopyDistinct_Length, Source_Array[i]))
				Add_ElementToArray(Source_Array[i], CopyDistinct_Array, CopyDistinct_Length);
		}
	}

	bool IsArrayPalindrome(short Array[], short Arr_Length)
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

	long long GetIntegerPartOfNumber(double Number)
	{
		return long long(Number);
	}
	double GetFractionPartOfNumber(double Number)
	{
		return Number - long long(Number);
	}

	double MyAbs(double Number)
	{
		if (Number == 0)
			return 0;
		else if (Number > 0)
			return Number;
		else
			return Number * -1;
	}

	long long MyRound(double Number)
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

	long long MyFloor(double Number)
	{
		long long IntPart = long long(Number);
		double FractionPart = Number - IntPart;

		if (MyAbs(FractionPart) > 0)
		{
			if (Number > 0)
				return IntPart;
			else
				return --IntPart;
		}
		else
		{
			return Number;
		}
	}

	long long MyCeil(double Number)
	{
		long long IntPart = long long(Number);
		double FractionPart = Number - IntPart;

		if (MyAbs(FractionPart) > 0)
		{
			if (Number > 0)
				return ++IntPart;
			else
				return IntPart;
		}
		else
		{
			return Number;
		}
	}

	double MySqrt(double Number)
	{
		return pow(Number, 0.5);
	}

	void V_Spaces(short NumberOfSpaces)
	{
		for (short i = 1; i <= NumberOfSpaces; i++)
		{
			cout << " ";
		}
	}
	string S_Spaces(short NumberOfSpaces)
	{
		string Spaces = "";

		for (short i = 1; i <= NumberOfSpaces; i++)
		{
			Spaces += " ";
		}

		return Spaces;
	}

	void V_Tabs(short NumberOfTabs)
	{
		for (short i = 1; i <= NumberOfTabs; i++)
		{
			cout << "\t";
		}
	}
	string S_Tabs(short NumberOfTabs)
	{
		string Tabs = "";

		for (short i = 1; i <= NumberOfTabs; i++)
		{
			Tabs += "\t";
		}

		return Tabs;
	}

	void NewLines(short NumberOfLines)
	{
		for (short i = 1; i <= NumberOfLines; i++)
		{
			cout << "\n";
		}
	}

	void V_UnderScores(short NubmerOfUnderScores)
	{
		for (short i = 1; i <= NubmerOfUnderScores; i++)
		{
			cout << "_";
		}
	}
	string S_UnderScores(short NubmerOfUnderScores)
	{
		string UnderScores = "";

		for (short i = 1; i <= NubmerOfUnderScores; i++)
		{
			UnderScores += "_";
		}

		return UnderScores;
	}

	void V_Stars(short NumberOfStars)
	{
		for (short i = 1; i <= NumberOfStars; i++)
		{
			cout << "*";
		}
	}
	string S_Stars(short NumberOfStars)
	{
		string Stars = "";

		for (short i = 1; i <= NumberOfStars; i++)
		{
			Stars += "*";
		}

		return Stars;
	}

}