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


//*********************************************************************************************************
//************************************ My Solution ********************************************************
//*********************************************************************************************************


void Multiplication_Table_From1To10()
{
	cout << "\n\t\t\tMultiplication Table From 1 To 10\n" << endl;

	cout << "  \t";
	for (int i = 1; i <= 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;

	for (int i = 1; i <= 84; i++)
	{
		cout << "_";
	}
	cout << endl;

	for (int i = 1; i <= 10; i++)
	{
		if (i == 10)
		{
			cout << " " << i << "  |  ";
		}
		else
		{
			cout << " " << i << "   |  ";
		}
		for (int j = 1; j <= 10; j++)
		{
			
			cout << i * j;
			cout << "\t";
		}
		
		cout << endl;
	}
	
}


//*********************************************************************************************************
//************************************ Abu-Hadhoud Solution ***********************************************
//*********************************************************************************************************


void Print_TableHeader()
{
	cout << "\n\t\t\tMultiplication Table From 1 To 10\n\n";
	cout << "\t";

	for (int i = 1; i <= 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;


	for (int i = 1; i <= 84; i++)
	{
		cout << "_";
	}
	cout << endl;
	
}

string Separator_Column(int i)
{
	if (i < 10)
	{
		return "   |";
	}
	else
	{
		return "  |";
	}
}

void Print_MultiplicationTable()
{
	Print_TableHeader();

	for (int i = 1; i <= 10; i++)
	{
		cout << " " << i << Separator_Column(i) << "\t";

		for (int j = 1; j <= 10; j++)
		{
			cout << i * j << "\t";
		}
		cout << endl;
	}
}


//********************************************************************************************************
//********************************************************************************************************


int main()
{

	Multiplication_Table_From1To10();

	cout << "\n__________________________________________________________________________________________________\n";
	cout << "\n__________________________________________________________________________________________________\n\n";

	Print_MultiplicationTable();

	
	

    return 0;
}

