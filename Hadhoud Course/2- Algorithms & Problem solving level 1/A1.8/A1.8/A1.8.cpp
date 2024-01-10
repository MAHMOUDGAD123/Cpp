#include <iostream>
#include <string>

using namespace std;

//***************************************************************************************************
//************************************ Global Functions *********************************************
//***************************************************************************************************

bool Check_PositiveOrNot(int N)
{
	if (N > 0)
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

	} while (!(Check_Number_Int(N) && Check_PositiveOrNot(stoi(N))));

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

	} while (!(Check_Number(N) && Check_PositiveOrNot(stoi(N))));

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

int ReadNumberInRange(int from, int to)
{
	int Number;
	do
	{
		cout << "Please, enter a numbe between " << from << " & " << to << " ?" << endl;
		cout << "your Answer : ";
		cin >> Number;
		cout << "\n";

	} while (!(Number >= from && Number <= to));

	return Number;
}


//*********************************************************************************************************
//*********************************************************************************************************
//******************************************* Program 1 ***************************************************
// Simple Calculator


enum en_OperationType { Add = '+', Sub = '-', Multi = '*', Div = '/' };

en_OperationType Choose_Operation()
{
	char Op;

	do
	{
		cout << "Choose the operation : \n";
		cout << "(1) for Addition type { + }\n";
		cout << "(2) for Subtraction type { - }\n";
		cout << "(3) for Multiplication type { * }\n";
		cout << "(4) for Division type { / }\n\n";

		cout << "Your choice : ";
		cin >> Op;
		cout << "\n\n";

	} while (Op != '+' && Op != '-' && Op != '*' && Op != '/');

	return (en_OperationType)Op;


}

float Calculations(float Number1, float Number2, en_OperationType OpType)
{
	switch (OpType)
	{


	case en_OperationType::Add:
		return Number1 + Number2;
		
	case en_OperationType::Sub:
		return Number1 - Number2;
		
	case en_OperationType::Multi:
		return Number1 * Number2;
		
	case en_OperationType::Div:
		
		while (Number2 == 0)
		{
			cout << "Division by zero ( number2 can't be 0 )\n\n";
			Number2 = ReadNumber("Please, enter the second number again?");
		}
		return Number1 / Number2;

		
	}

}



//******************************************* Program 2 ***************************************************
// Read numbers & sum them until user input = -99

float AddUntillInput_99()
{
	float N = 0, sum = 0;
	int i = 1;
	do
	{
		N = ReadNumber("Enter number " + to_string(i) + " ?");
		if (N == -99)
			break;

		sum += N;
		i++;

	} while (N != -99);

	return sum;
}


//******************************************* Program 3 ***************************************************
// Prime number or not


//My solution
string Check_PrimeOrNot(int Number)
{
	
	int H = ceil(Number / 2); // H is the half of Number

	
	for (int i = 2; i <= H; i++)
	{
		if (Number % i == 0)
			return "( " + to_string(Number) + " )" + " is not a prime number.";

	}

	return "{ " + to_string(Number) + " }" + " is a prime number.";

}

//Abu_Hadhoud Solution (using Enum)
enum en_PrimeOrNot { Prime = 1, NotPrime = 2 };

en_PrimeOrNot Check_Prime(int Number)
{
	int H = ceil(Number / 2);

	for(int i = 2; i <= H; i++)
	{
		if (Number % i == 0)
			return en_PrimeOrNot::NotPrime;
	}
	return en_PrimeOrNot::Prime;
}

void GetNumberType(int Number)
{
	switch (Check_Prime(Number))
	{
	case en_PrimeOrNot::Prime:
		cout << "{ " + to_string(Number) + " }" + " is a prime number.\n\n";
		break;
	case en_PrimeOrNot::NotPrime:
		cout << "{ " + to_string(Number) + " }" + " is not a prime number.\n\n";
		break;
	}
}


//******************************************* Program 4 ***************************************************
// Pay Remainder


float PayRemainder(float TotalBill, float CashPaid)
{
	float CashPaid_plus = 0;

	while (TotalBill > CashPaid)
	{
		cout << "Cash Paid = " << CashPaid << endl;
		cout << "The Total Bill = " << TotalBill << endl;
		cout << "\nThe Paid Money is not enough your have to pay more.\n\n";

		CashPaid_plus = Read_Positive_Number("Please, Pay more?");
		CashPaid += CashPaid_plus;
		cout << "***********************************\n";
	}

	return CashPaid - TotalBill;
}

void Get_CashBack()
{
	float TotalBill = Read_Positive_Number("Please, enter the Total Bill?");
	float CashPaid = Read_Positive_Number("Please, enter the Paid Cash?");

	cout << "***********************************\n";
	cout << "Cash Back = " << PayRemainder(TotalBill, CashPaid) << endl << endl;
}


//******************************************* Program 5 ***************************************************
// Service fee & Sales tax


float Total_Bill_AfterServiceFeeAndSalesTax(float TotalBill)
{
	TotalBill *= 1.1;
	TotalBill *= 1.16;

	return TotalBill;
}

void Print_Total_Bill()
{
	float TotalBill = Read_Positive_Number("Please, enter the Total Bill?");

	cout << "*********************************************************\n";
	cout << "- Total Bill = " << TotalBill << endl;
	cout << "- The Total Bill after service fee and sales tax = " << Total_Bill_AfterServiceFeeAndSalesTax(TotalBill) << endl;
	cout << "*********************************************************\n\n" << endl;

}


//*********************************************************************************************************
//*********************************************************************************************************


int main()
{

	// Program 1
	/*float Number1 = ReadNumber("Please, enter the first number?");
	float Number2 = ReadNumber("Please, enter the second number?");
	en_OperationType Op = Choose_Operation();
	cout << "The Result = " << Calculations(Number1, Number2, Op) << endl << endl;*/

	
	//*************************************************************************************************************************************************
	//*************************************************************************************************************************************************


	// Program 2
	//cout << endl << "The Result = " << AddUntillInput_99() << endl << endl;


	//*************************************************************************************************************************************************
	//*************************************************************************************************************************************************


	// Program 3
	//int Number = Read_Positive_Number("Please, enter a positive Number?");

	// my solution
	//cout << "\n***********************\n" << Check_PrimeOrNot(Number) << "\n***********************\n\n\n" << endl;

	//Abu-Hadhoud solution
	//GetNumberType(Number);


	//*************************************************************************************************************************************************
	//*************************************************************************************************************************************************

	//Program 4
	//Get_CashBack();


	//*************************************************************************************************************************************************
	//*************************************************************************************************************************************************


	//Program 5
	//Print_Total_Bill();


	//*************************************************************************************************************************************************


	// Problem 4 & 5 together
	float TotalBill = Read_Positive_Number("Please, enter the Total Bill?");

	cout << "*********************************************************\n";
	cout << "- Total Bill = " << TotalBill << endl;
	cout << "- The Total Bill after service fee and sales tax = " << Total_Bill_AfterServiceFeeAndSalesTax(TotalBill) << endl;
	cout << "\n\n*********************************************************\n" << endl;

	float CashPaid = Read_Positive_Number("Please, enter the Paid Cash?");

	cout << "*********************************************************\n";
	cout << "Cash Back = " << PayRemainder(Total_Bill_AfterServiceFeeAndSalesTax(TotalBill), CashPaid) << endl << endl;





	return 0;
}