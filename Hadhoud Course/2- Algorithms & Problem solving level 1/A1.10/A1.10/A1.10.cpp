#include <iostream>
#include <string>

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
//*********************************************************************************************************

//******************************************* Program 1 ***************************************************
// Print All Letters from A to Z & from Z to A


int Choose_AToZ_ZToA()
{
	
	int Answer;

	do
	{
		cout << "Please, Choose From The List : \n";
		cout << "(1) Print All Letters From A to Z\n";
		cout << "(2) Print All Letters From Z to A\n";

		Answer = Read_Positive_Int_Number("\nJust Enter { 1 or 2 }\n");
		cout << "_____________________________________\n\n";

	} while (Answer != 1 && Answer != 2);

	return Answer;

}

void PrintLetters(int Answer)
{
	switch (Answer)
	{
	case 1:
		cout << "***********************************************************************************************************\n\n{ ";
		for (int i = 65; i <= 90; i++)
		{
			cout << " " << char(i) << " ";
		}
		cout << " }\n\n***********************************************************************************************************\n\n";
		break;
	
	case 2:
		cout << "***********************************************************************************************************\n\n{ ";
		for (int i = 90; i >= 65; i--)
		{
			cout << " " << char(i) << " ";
		}
		cout << " }\n\n***********************************************************************************************************\n\n";
		break;
	}
}



//******************************************* Program 2 ***************************************************
//Loan & the time to settle the Loan


float GetTotalMonths(float Loan_Amount, float Monthly_Payment)
{
	return round(Loan_Amount / Monthly_Payment);
}


//******************************************* Program 3 ***************************************************
// Monthly Loan Installmant

float GetMonthly_Installmant(float Loan_Amount, float HowManyMonths)
{

	return Loan_Amount / HowManyMonths;
}

float GetTotal_Monthly_Installment_After_Reba(float Monthly_Installment)
{
	// Reba = 10%

	return Monthly_Installment *= 1.1;
}

float GetTotal_Installment_After_Reba(float Loan_Amount)
{
	// Reba = 10%
	// Total Loan After Reba

	return Loan_Amount *= 1.1;
}


//******************************************* Program 4 ***************************************************
// ATM PIN

//   
//  

int ReadPIN(string Message)
{
	int PIN = Read_Positive_Int_Number_With_specificNumberOfDigits(Message, 4);
	cout << "______________________________\n\n";

	return PIN;
}

bool Check_PIN()
{
	int PIN = 0;
	int counter = 3;

	do
	{
		PIN = ReadPIN("Please, Enter The 4 Digit PIN Number?\n- Attempts = " + to_string(counter));
		counter--;

		if (PIN == 4283)
		{
			return true;
		}

	} while(counter >= 1 && PIN != 4283);

	return false;

}




//*********************************************************************************************************
//*********************************************************************************************************



int main()
{
   
	// Program 1
	//PrintLetters(Choose_AToZ_ZToA());

	//***********************************************************************************************************************************************************
	//***********************************************************************************************************************************************************


	// Program 2
	/*float Loan_Amount1 = Read_Positive_Number("Please, Enter The Loan Amount?");
	int Min_Monthly_Payment = Loan_Amount1 * 0.01;
	int Max_Monthly_Payment = Loan_Amount1 * 0.5;
	float Monthly_payment = Read_Positive_NumberInRange_Message("Please, Enter The Monthly Payment?{ min = " + to_string(Min_Monthly_Payment) + ", Max = " + to_string(Max_Monthly_Payment) + " }", Min_Monthly_Payment, Max_Monthly_Payment);
	
	cout << "The Total Months To Settle The Loan = " << GetTotalMonths(Loan_Amount1, Monthly_payment) << " Months.\n" << endl;
	cout << "_______________________________________________________\n\n\n\n";*/

	//***********************************************************************************************************************************************************
	//***********************************************************************************************************************************************************


	// Program 3
	

	//float Loan_Amount = Read_Positive_Number("Please, Enter The Loan Amount?");
	//int Minimum_Installment = Loan_Amount * 0.01;
	//int Max_NumberOfMonths = Loan_Amount / Minimum_Installment;
	//int Maximum_Installment = Loan_Amount * 0.5;
	//int Min_NumberOfMonths = Loan_Amount / Maximum_Installment;
	//float HowManyMonths = Read_Positive_NumberInRange_Message("Please, Enter How Many Months? { min = " + to_string(Min_NumberOfMonths) + ", Max = " + to_string(Max_NumberOfMonths) + " }", Min_NumberOfMonths, Max_NumberOfMonths);
	//float Monthly_Installmant = GetMonthly_Installmant(Loan_Amount, HowManyMonths);
	//float Monthly_Installment_After_Reba = GetTotal_Monthly_Installment_After_Reba(Monthly_Installmant);

	//cout << "\n*****************************************************\n\n";
	//cout << "The Monthly Installment = " << Monthly_Installmant << " $" << endl;
	//cout << "The Monthly Installment After Reba = " << Monthly_Installment_After_Reba << " $" << endl;
	//cout << "The Total Installment After Reba = " << GetTotal_Installment_After_Reba(Loan_Amount) << " $" << endl;
	//cout << "\n*****************************************************\n\n";
	//cout << "_______________________________________________________\n\n\n\n";

	//***********************************************************************************************************************************************************
	//***********************************************************************************************************************************************************


	// Program 4
	
	if (Check_PIN())
	{
		system("color 2F");
		cout << "Your Balance = 1000500 $" << endl;
		cout << "______________________________\n";
	}
	else
	{
		system("color 4F");
		cout << "______________________________________________\n\n";
		cout << "Your Account Is Locked call the bank for help" << endl;
		cout << "______________________________________________\n";
		exit(0);
	}



	//***********************************************************************************************************************************************************
	//***********************************************************************************************************************************************************



	return 0;
}
